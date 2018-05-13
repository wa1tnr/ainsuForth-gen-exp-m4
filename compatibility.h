// Sun 13 May 03:29:16 UTC 2018
// 4737-a3a-03c-

// Sun 13 May 01:18:47 UTC 2018
// 4737-a3a-01a-

// previous timestamps:
// Tue Jan 16 02:30:09 UTC 2018
// 4737-a0d-05j-

// Tue Jan 16 01:14:29 UTC 2018
// 4737-a0d-05f-

// Mon Jan 15 19:19:47 UTC 2018
// 4737-a0d-05d-

// Sat Dec 16 01:24:37 UTC 2017
// 4737-a0a-00a-

// Sun Dec 10 22:48:03 UTC 2017
// 4735-b0d-00b-   the -00x- is new Dec 10, 2017.

// Wed Aug  2 18:04:12 UTC 2017
// 4735-b0c-05-

// packages/adafruit/hardware/samd/1.0.18/boards.txt:173:adafruit_gemma_m0.build.extra_flags=-DCRYSTALLESS -DADAFRUIT_GEMMA_M0 -D__SAMD21E18A__ {build.usb_flags}

// In July 2017, all boards were SAMD21G18A except Gemma M0, which is SAMD21E18A (similar inside, fewer pins brought out?)

// GEMMA M0
// + dotstar x1
// CRYSTALLESS   ADAFRUIT_GEMMA_M0   __SAMD21E18A__

// FEATHER M0
// ARDUINO_SAMD_ZERO __SAMD21G18A__

// FEATHER M0 EXPRESS
// + npx x1  + SPI flash 2MB
// ARDUINO_SAMD_ZERO ARDUINO_SAMD_FEATHER_M0 ADAFRUIT_FEATHER_M0_EXPRESS __SAMD21G18A__ 

// RADIO M0 (Feather ..)
// __SAMR21G18A__ 

// METRO M0 (Metro M0 Express)
// + npx x1  + SPI flash 2MB
// __SAMD21G18A__  ARDUINO_SAMD_ZERO ADAFRUIT_METRO_M0_EXPRESS 


// CPX - Circuit Playground M0 (Circuit Playground Express)
// + npx x10  + SPI flash 2MB
// CRYSTALLESS ARDUINO_SAMD_ZERO __SAMD21G18A__ ADAFRUIT_CIRCUITPLAYGROUND_M0

// reverse these two lines to enable SPI flashROM support:
#define HAS_SPI_FLASH_DEMO
#undef HAS_SPI_FLASH_DEMO

#ifdef ADAFRUIT_FEATHER_M0_EXPRESS
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef ADAFRUIT_FEATHER_M0_EXPRESS

#ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0

#ifdef ADAFRUIT_METRO_M0_EXPRESS
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef ADAFRUIT_METRO_M0_EXPRESS

// M4 target offers an impoverished test - redefine later, tracking upstream refinements.
#ifdef __SAMD51J19A__
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef __SAMD51J19A__

// global override - debug
#define HAS_SPI_FLASH_DEMO
#undef HAS_SPI_FLASH_DEMO // kludge.  QSPI flash may be a game-changer.  wait.
// load echo! remove download are relevant only to presence of SPI flashROM.

