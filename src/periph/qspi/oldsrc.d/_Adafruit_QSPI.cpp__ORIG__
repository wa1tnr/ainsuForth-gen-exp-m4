/*!
 * @file Adafruit_QSPI.cpp
 *
 * @mainpage Adafruit QSPI library
 *
 * @section intro_sec Introduction
 *
 * This is documentation for Adafruit's library for interfacing with the QSPI
 * peripheral on specific microcontrollers. Currently only the SAMD51 is supported.
 * This is intened to be used with the Adafruit Metro M4 Express, Adafruit Feather M4 Express,
 * and other M4 Express development boards.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * @section author Author
 *
 * Written by Dean Miller for Adafruit Industries.
 *
 * @section license License
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "Adafruit_QSPI.h"
#include "wiring_private.h"

/**************************************************************************/
/*! 
    @brief  Enable necessary clocks and configure QSPI peripheral.
*/
/**************************************************************************/
void Adafruit_QSPI::begin() {
	MCLK->AHBMASK.reg |= MCLK_AHBMASK_QSPI;
	MCLK->AHBMASK.reg |= MCLK_AHBMASK_QSPI_2X;
	MCLK->APBCMASK.reg |= MCLK_APBCMASK_QSPI;

	//set all pins to QSPI periph
	pinPeripheral(PIN_QSPI_SCK, PIO_COM);
	pinPeripheral(PIN_QSPI_CS, PIO_COM);
	pinPeripheral(PIN_QSPI_IO0, PIO_COM);
	pinPeripheral(PIN_QSPI_IO1, PIO_COM);
	pinPeripheral(PIN_QSPI_IO2, PIO_COM);
	pinPeripheral(PIN_QSPI_IO3, PIO_COM);

	QSPI->CTRLA.bit.SWRST = 1;

	delay(1); //no syncbusy reg.. do we need this? Probably not

	QSPI->CTRLB.reg = QSPI_CTRLB_MODE_MEMORY | QSPI_CTRLB_CSMODE_NORELOAD | QSPI_CTRLB_DATALEN_8BITS | QSPI_CTRLB_CSMODE_LASTXFER;

	QSPI->BAUD.reg = QSPI_BAUD_BAUD(VARIANT_MCK/VARIANT_QSPI_BAUD_DEFAULT);

	QSPI->CTRLA.bit.ENABLE = 1;
}

/**************************************************************************/
/*! 
    @brief  Run a single QSPI instruction.
    @param instr pointer to the struct containing instruction settings
    @param addr the address to read or write from. If the instruction doesn't require an address, this parameter is meaningless.
    @param txData pointer to the data to be written.
    @param rxData pointer to where read data should be stored.
    @param size the number of bytes to read.
*/
/**************************************************************************/
void Adafruit_QSPI::runInstruction(const QSPIInstr *instr, uint32_t addr, uint8_t *txData, uint8_t *rxData, uint32_t size)
{
	uint8_t *qspi_mem = (uint8_t *)QSPI_AHB;
	if(addr)
		qspi_mem += addr;

	QSPI->INSTRCTRL.bit.INSTR = instr->instruction;
	QSPI->INSTRADDR.reg = addr;

	//read to synchronize
	uint32_t iframe = QSPI->INSTRFRAME.reg;

	iframe = QSPI_INSTRFRAME_WIDTH(instr->ioFormat) | instr->options |
			QSPI_INSTRFRAME_OPTCODELEN(instr->opcodeLen) | (instr->addrLen << QSPI_INSTRFRAME_ADDRLEN_Pos) |
			( instr->continuousRead << QSPI_INSTRFRAME_CRMODE_Pos) | QSPI_INSTRFRAME_TFRTYPE(instr->type) | QSPI_INSTRFRAME_DUMMYLEN(instr->dummylen);

	QSPI->INSTRFRAME.reg = iframe;

	if(rxData != NULL){
		while(size){
			*rxData++ = *qspi_mem++;
			size--;
		}
	}
	else if(txData != NULL){
		while(size){
			*qspi_mem++ = *txData++;
			size--;
		}
	}

	__asm__ volatile ("dsb");
	__asm__ volatile ("isb");

	QSPI->CTRLA.reg = QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER;

	while( !QSPI->INTFLAG.bit.INSTREND );

	QSPI->INTFLAG.bit.INSTREND = 1;
}

/**************************************************************************/
/*! 
    @brief  Run a single QSPI instruction. This should only be used for single byte instructions that do not read or write data or require an address.
    @param instr pointer to the struct containing instruction settings
*/
/**************************************************************************/
void Adafruit_QSPI::runInstruction(const QSPIInstr *instr){
	runInstruction(instr, 0, NULL, NULL, 0);
}

/**************************************************************************/
/*! 
    @brief transfer data via QSPI
    @param data the data to be sent
    @returns the data that was read
*/
/**************************************************************************/
byte Adafruit_QSPI::transfer(uint16_t data)
{
	QSPI->TXDATA.reg = data;
	while( !QSPI->INTFLAG.bit.TXC );

	return QSPI->RXDATA.reg;
}

/**************************************************************************/
/*! 
    @brief  transfer multiple bytes via QSPI
    @param buf the bufer to read from and write to. This buffer will be modified by the function.
    @param count the number of bytes to transfer.
*/
/**************************************************************************/
void Adafruit_QSPI::transfer(void *buf, size_t count)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(buf);
	for (size_t i=0; i<count; i++) {
		*buffer = transfer(*buffer);
		buffer++;
	}
}

/**************************************************************************/
/*! 
    @brief  set the memory mode of the QSPI peripheral
    @param mode the mode to set to
*/
/**************************************************************************/
void Adafruit_QSPI::setMemoryMode(QSPIMode_t mode)
{
	QSPI->CTRLB.bit.MODE = mode;
}

/**************************************************************************/
/*! 
    @brief  set the clock divider
    @param uc_div the divider to set. Must be a value between 0 and 255. Note that QSPI uses GCLK0.
*/
/**************************************************************************/
void Adafruit_QSPI::setClockDivider(uint8_t uc_div)
{
	QSPI->BAUD.bit.BAUD = uc_div;
}

/**************************************************************************/
/*! 
    @brief set the data width
    @param width the data width to set.
*/
/**************************************************************************/
void Adafruit_QSPI::setDataWidth(QSPIDataWidth_t width)
{
	QSPI->CTRLB.bit.DATALEN = QSPI_CTRLB_DATALEN(width);
}

Adafruit_QSPI QSPI0;
