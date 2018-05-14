/* Test QSPI read and write functionality. Erase chip, write sequential bytes, verify.
 */

//Uncomment one of the following lines based on the flash device used

//#define FLASH_DEVICE_S25FL1
#define FLASH_DEVICE_GD25Q
//#define FLASH_DEVICE_GENERIC

#ifdef FLASH_DEVICE_GD25Q

#include "Adafruit_QSPI_GD25Q.h"
Adafruit_QSPI_GD25Q flash;
#elif defined(FLASH_DEVICE_S25FL1)
#include "Adafruit_QSPI_S25FL1.h"
Adafruit_QSPI_S25FL1 flash;
#elif defined(FLASH_DEVICE_S25FL1)
#include "Adafruit_QSPI_Generic.h"
Adafruit_QSPI_Generic flash;
#else
#error "Flash Device not supported."
#endif

#define PROGSIZE 512

uint8_t progData[PROGSIZE];
uint8_t readData[PROGSIZE];

void setup(){
  Serial.begin(115200);
  while(!Serial) {
    delay(10);
  }

  Serial.println("Adafruit QSPI test!");
  
  if (!flash.begin()){
    Serial.println("Could not find flash on QSPI bus!");
    while(1);
  }
  Serial.println("Found QSPI Flash");

  for (int i=0; i<PROGSIZE; i++){
    progData[i] = i;
  }

  Serial.print("Erasing...");
  flash.chipErase();
  Serial.println("done!");

  Serial.print("Writing...");
  flash.writeMemory(0, progData, sizeof(progData));
  Serial.println("done!");

  Serial.print("Reading...");
  flash.readMemory(0, readData, sizeof(readData));
  Serial.println("done!");

  for (int i=0; i<PROGSIZE; i++){
    if(readData[i] != progData[i]){
      Serial.print("ERROR: mismatch found at index ");
      Serial.println(i);
      while(1);
    }
  }

  Serial.println("Verify successful!");
}

void loop(){
  //don't even do anything
}

