/*
 * Adafruit_GD25Q.h
 *
 *  Created on: Jan 2, 2018
 *      Author: deanm
 */

#ifndef ADAFRUIT_QSPI_GD25Q_H_
#define ADAFRUIT_QSPI_GD25Q_H_

#include "Adafruit_QSPI_Generic.h"

/**************************************************************************/
/*! 
    @brief  a class for interfacing with a GD25Q QSPI flash device. http://www.elm-tech.com/en/products/spi-flash-memory/gd25q16/gd25q16.pdf
*/
/**************************************************************************/
class Adafruit_QSPI_GD25Q : public Adafruit_QSPI_Generic {

public:
	Adafruit_QSPI_GD25Q() : Adafruit_QSPI_Generic() {}
	~Adafruit_QSPI_GD25Q() {}

	bool begin();

private:
	void writeStatus();

	typedef union {
		struct {
			uint8_t WIP:1;
			uint8_t WEL:1;
			uint8_t BP:5;
			uint8_t SRP0:1;
			uint8_t SRP1:1;
			uint8_t QE:1;
			uint8_t LB:1;
			uint8_t :2;
			uint8_t HPF:1;
			uint8_t CMP:1;
			uint8_t SUS:1;
		} bit;
		uint16_t reg;
	} statusRegister;
	statusRegister _status;
};



#endif /* ADAFRUIT_QSPI_GD25Q_H_ */
