// Sat 26 May 03:36:19 UTC 2018
// 4737-a3a-05t-

// Wed 23 May 19:37:12 UTC 2018
// 4737-a3a-05s-

// Tue 15 May 01:57:23 UTC 2018
// 4737-a3a-05f-

// Mon 14 May 22:46:36 UTC 2018
// 4737-a3a-05e-

// Mon 14 May 20:26:35 UTC 2018
// 4737-a3a-05c-

// Mon 14 May 18:47:28 UTC 2018
// 4737-a3a-05a-

#include <Arduino.h>
#include "../../../yaffa.h"

#ifdef HAS_QSPI_FLASHROM_LIB
    #include "flashrom.h"
    // close this at very end of this file.

    #define FLASH_DEVICE_GD25Q
    #ifdef FLASH_DEVICE_GD25Q
        /*
         26 #include <SPI.h>
         27 #include <Adafruit_SPIFlash.h>
        */
        #include <Adafruit_SPIFlash_FatFs.h>
        /*
         29 #include "Adafruit_QSPI_GD25Q.h"
        */
        #include "Adafruit_QSPI_GD25Q.h"

Adafruit_QSPI_GD25Q flash;

    #else
        #error "Flash Device not supported."
    #endif

    #define PROGSIZE 512

uint8_t progData[PROGSIZE];
uint8_t readData[PROGSIZE];

void data_fill_qflash(void) { // data fill
    Serial.print("Hello from data_fill_qflash.   ");
    for (int i=0; i<PROGSIZE; i++) {
        progData[i] = i;
    }
}

void write2qflash(void) { // write out memory image to QSPI flashROM
    Serial.print("Writing... using write2qflash... ");
    // in one statement, 512 bytes are written:
    flash.writeMemory(0, progData, sizeof(progData));
    Serial.println("done!"); 
}


void readqflash(void) { // read the memory image stored in QSPI flashROM
    Serial.print("Reading...");

    flash.readMemory(0, readData, sizeof(readData));

    // the buffer readData should now hold, in RAM,
    // the memory image retrieved from flashROM

    Serial.print("done!");
}

void compare_flash2src_bufr(void) {
    for (int i=0; i<PROGSIZE; i++) {
        if(readData[i] != progData[i]) {
            Serial.print("ERROR: mismatch found at index ");
            Serial.println(i);
            while(1); // wait forever - trapped.  Use a throw here.
        }
    }
}

void erase_qflash(void) { // erase
    Serial.print("Erasing... using erase_qflash()... ");
    flash.chipErase();
    Serial.println("done!"); 
}



void setup_qspiFlashROM(void) {
    Serial.print("Hello from setup_qspi stuff.   ");
    if (!flash.begin()) {
        Serial.println("Could not find flash on QSPI bus!");
        while(1);
    }
    Serial.println("Found QSPI Flash."); 

    data_fill_qflash();

    // erase_qflash();

    // write2qflash();

    Serial.print("note: erase and write are skipped.   ");

    readqflash(); // read the memory image stored in QSPI flashROM 

    compare_flash2src_bufr();

    // DEBUG // Serial.println("Flash was populated, read back into RAM, then compared.");
    // DEBUG // Serial.println("SUCCESS.  Basic QSPI flashROM use is confirmed.");

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
