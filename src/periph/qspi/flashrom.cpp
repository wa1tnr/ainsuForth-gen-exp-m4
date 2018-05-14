// Mon 14 May 18:47:28 UTC 2018
// 4737-a3a-05a-

#include <Arduino.h>
#include "../../../yaffa.h"

#ifdef HAS_QSPI_FLASHROM_LIB
#include "flashrom.h"
// close this at very end of this file.

#define FLASH_DEVICE_GD25Q
#ifdef FLASH_DEVICE_GD25Q

#include "Adafruit_QSPI_GD25Q.h"
Adafruit_QSPI_GD25Q flash;

#else
#error "Flash Device not supported."
#endif

// #define PROGSIZE 512

int abc = 1;

void setup_qspiFlashROM(void) {
  int i = 0;
  // foo.begin(); // This initializes the n library.
}


void _abcdX44(void) { // ( n3 n2 n1 -- n1 n2 n3 )
    _rot();
    _rot();
    _swap();
}

const char ffmt_str[] = "ffmt"; // local idiom ainsuForth - TODO: describe this
void _ffmt(void) { // ( TOS_requirement_if_any -- )
    int myVariable941 = 0;
    int i = 0; // generic integer
    myVariable941 = dStack_pop();
    Serial.println("dropped TOS - no other effects.");
}


void fomFom(void) { // nonsense - stub - testing
  int myVar942 = 0 ; // nonsense - stub
  for(int i=0;i<25;i++){
      myVar942 = 77 ; // nonsense - stub
  }
}

#endif // #ifdef HAS_QSPI_FLASHROM_LIB
