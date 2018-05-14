/*
 * Flash_Generic.h
 *
 *  Created on: Jan 2, 2018
 *      Author: deanm
 */

#ifndef ADAFRUIT_QSPI_GENERIC_H_
#define ADAFRUIT_QSPI_GENERIC_H_


#include "Adafruit_QSPI.h"

/**************************************************************************/
/*! 
    @brief  a class for interfacing with a generic QSPI flash device.
*/
/**************************************************************************/
class Adafruit_QSPI_Generic {

public:
	Adafruit_QSPI_Generic() {}
	~Adafruit_QSPI_Generic() {}

	bool begin();

	byte readDeviceID();
	byte readManufacturerID();
	byte readStatus();
	void chipErase();
	void eraseBlock(uint32_t blocknum);

	byte read8(uint32_t addr);

	bool readMemory(uint32_t addr, uint8_t *data, uint32_t size);
	bool writeMemory(uint32_t addr, uint8_t *data, uint32_t size);
};

enum {
	ADAFRUIT_QSPI_GENERIC_CMD_DEVID = 0,
	ADAFRUIT_QSPI_GENERIC_CMD_MFGID,
	ADAFRUIT_QSPI_GENERIC_READ_STATUS,
	ADAFRUIT_QSPI_GENERIC_CMD_WRITE_STATUS,
	ADAFRUIT_QSPI_GENERIC_CMD_WRITE_ENABLE,
	ADAFRUIT_QSPI_GENERIC_CMD_WRITE_DISABLE,
	ADAFRUIT_QSPI_GENERIC_CMD_CHIP_ERASE,
	ADAFRUIT_QSPI_GENERIC_CMD_BLOCK64K_ERASE,
	ADAFRUIT_QSPI_GENERIC_CMD_PAGE_PROGRAM,
	ADAFRUIT_QSPI_GENERIC_CMD_QUAD_READ,
};

extern const QSPIInstr cmdSetGeneric[];


#endif /* ADAFRUIT_QSPI_GENERIC_H_ */
