// Thu Aug  3 19:07:55 UTC 2017
// 4735-b0f-00-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"


#include "load.h"


const char echo_bang_str[] = "echo!"; // ( bool -- )
void _echo_bang(void) { // ( bool -- )
  uint8_t echo = TRUE ;
  // silentReading = dStack_pop();
  echo = dStack_pop();
  if (echo) { 
      silentReading = FALSE;
  } else {
      silentReading = TRUE;
  }
}

const char load_str[] = "load";
void _load(void) {

  spiFlashReading = TRUE ; // TRUE      // Adafruit SPI flash: reading

  // silentReading = TRUE ; // will eventually have a means to turn this on and off in Forth

  // if (spiFlashReading) { }
}

// #endif
