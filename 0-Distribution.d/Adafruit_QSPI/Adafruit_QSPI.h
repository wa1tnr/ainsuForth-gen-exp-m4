/*!
 * @file Adafruit_QSPI.h
 *
 * This is part of Adafruit's QSPI Peripheral driver for the Arduino platform.  It is
 * designed specifically to work with the Adafruit M4 Express development boards.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Dean Miller for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef LIB_ZERO_QSPI_H
#define LIB_ZERO_QSPI_H

#include "SPI.h"
#include <Arduino.h>

/**************************************************************************/
/*! 
    @brief  The transfer mode
*/
/**************************************************************************/
typedef enum {
	QSPI_SPI_MODE = 0,
	QSPI_MEMORY_MODE,
} QSPIMode_t;


/**************************************************************************/
/*! 
    @brief  The transfer data width
*/
/**************************************************************************/
typedef enum {
	QSPI_DATAWIDTH_8_BITS = QSPI_CTRLB_DATALEN_8BITS_Val, 
	QSPI_DATAWIDTH_9_BITS,
	QSPI_DATAWIDTH_10_BITS,
	QSPI_DATAWIDTH_11_BITS,
	QSPI_DATAWIDTH_12_BITS,
	QSPI_DATAWIDTH_13_BITS,
	QSPI_DATAWIDTH_14_BITS,
	QSPI_DATAWIDTH_15_BITS,
	QSPI_DATAWIDTH_16_BITS,
} QSPIDataWidth_t;

/**************************************************************************/
/*! 
    @brief  The address length. Use QSPI_ADDRLEN_NONE if no address needed.
*/
/**************************************************************************/
typedef enum {
	QSPI_ADDRLEN_NONE = QSPI_INSTRFRAME_ADDRLEN_24BITS_Val,
	QSPI_ADDRLEN_24_BITS = QSPI_INSTRFRAME_ADDRLEN_24BITS_Val,
	QSPI_ADDRLEN_32_BITS,
} QSPIAddrLen_t;

/**************************************************************************/
/*! 
    @brief  The opcode length. Use QSPI_OPCODE_LEN_NONE if no opcode needed.
*/
/**************************************************************************/
typedef enum {
	QSPI_OPCODE_LEN_NONE = QSPI_INSTRFRAME_OPTCODELEN_1BIT_Val,
	QSPI_OPCODE_LEN_1_BITS = QSPI_INSTRFRAME_OPTCODELEN_1BIT_Val,
	QSPI_OPCODE_LEN_2_BITS,
	QSPI_OPCODE_LEN_4_BITS,
	QSPI_OPCODE_LEN_8_BITS,
} QSPIOpcodeLen_t;

/**************************************************************************/
/*! 
    @brief  the transfer format to use
*/
/**************************************************************************/
typedef enum {
	QSPI_IO_FORMAT_SINGLE = QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI_Val,
	QSPI_IO_FORMAT_SINGLE_DUAL_DATA,
	QSPI_IO_FORMAT_SINGLE_QUAD_DATA,
	QSPI_IO_FORMAT_SINGLE_INSTR_DUAL_ADDR_DUAL_DATA,
	QSPI_IO_FORMAT_SINGLE_INSTR_QUAD_ADDR_QUAD_DATA,
	QSPI_IO_FORMAT_DUAL,
	QSPI_IO_FORMAT_QUAD,
} QSPIIOFormat_t;

/**************************************************************************/
/*! 
    @brief  the type of transfer
*/
/**************************************************************************/
typedef enum {
	QSPI_READ = QSPI_INSTRFRAME_TFRTYPE_READ_Val,
	QSPI_READ_MEMORY,
	QSPI_WRITE,
	QSPI_WRITE_MEMORY,
} QSPITransferType_t;

#define QSPI_OPTION_NONE 0 ///< no option
#define QSPI_OPTION_INSTREN QSPI_INSTRFRAME_INSTREN ///< enable sending of instruction
#define QSPI_OPTION_ADDREN QSPI_INSTRFRAME_ADDREN ///< enable sending of address
#define QSPI_OPTION_OPCODEEN QSPI_INSTRFRAME_OPTCODEEN ///< enable sending of opcode
#define QSPI_OPTION_DATAEN QSPI_INSTRFRAME_DATAEN ///< enable sending of data

/**************************************************************************/
/*! 
    @brief  QSPI instruction struct
*/
/**************************************************************************/
typedef struct {
	uint8_t instruction; ///< the instruction byte
	bool continuousRead; ///< whether or not to use continuous read mode
	QSPIAddrLen_t addrLen; ///< the address length if an address is required
	QSPIOpcodeLen_t opcodeLen; ///< the opcode length if an opcode is required
	QSPIIOFormat_t ioFormat; ///< the data format to use
	uint8_t options; ///< additional option flags
	QSPITransferType_t type; ///< the transfer type
	uint8_t dummylen; ///< the number of dummy cycles that should preceed data transfer
} QSPIInstr;


/**************************************************************************/
/*! 
    @brief  Class for interfacing with QSPI hardware
*/
/**************************************************************************/
class Adafruit_QSPI
{
public:
	Adafruit_QSPI() {};
	~Adafruit_QSPI() {};

	byte transfer(uint16_t data);
	void transfer(void *buf, size_t count);

	// Transaction Functions
	/**************************************************************************/
	/*! 
		@brief Set the interrupt number to use
		@param interruptNumber the interrupt number to set
	*/
	/**************************************************************************/
	void usingInterrupt(int interruptNumber);
	/**************************************************************************/
	/*! 
		@brief begin an SPI transaction using the passed settings
		@param settings the settings to use 
	*/
	/**************************************************************************/
	void beginTransaction(SPISettings settings);
	void endTransaction(void); ///< end the SPI transaction

	// SPI Configuration methods
	void attachInterrupt(); ///< attach the SPI interrupt
	void detachInterrupt(); ///< detach the SPI interrupt

	void begin();
	void end(); ///< de-init the peripheral

	void runInstruction(const QSPIInstr *instr);
	void runInstruction(const QSPIInstr *instr, uint32_t addr, uint8_t *txData, uint8_t *rxData, uint32_t size);

	void setMemoryMode(QSPIMode_t mode);
	void setClockDivider(uint8_t uc_div);
	void setDataWidth(QSPIDataWidth_t width);

	private:
	/**************************************************************************/
	/*! 
		@brief configure using the passed settings
		@param settings the settings to use 
	*/
	/**************************************************************************/
	void config(SPISettings settings);
};

extern Adafruit_QSPI QSPI0; ///< default QSPI instance

#endif
