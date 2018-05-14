// Mon 14 May 22:46:36 UTC 2018
// 4737-a3a-05e-

// Mon 14 May 20:26:35 UTC 2018
// 4737-a3a-05c-

// Mon 14 May 18:47:28 UTC 2018
// 4737-a3a-05a-

// previous timestamps:
// Sun 13 May 06:53:54 UTC 2018
// 4737-a3a-03f-

// Tue Jan 16 02:30:09 UTC 2018
// 4737-a0d-05j-

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

// METRO M4 (Metro M4 Express Beta)
// + QSPI flash 2MB - incompatible with SPI flashROM routines for the M0 series
// __SAMD51J19A__ __SAMD51__ __FPU_PRESENT ARM_MATH_CM4
// ARDUINO_METRO_M4 -DARDUINO_ARCH_SAMD  -D__SAMD51J19A__

#undef QSPI_FLASHROM_PRESENT // re-enable only for some SAMD51 target boards


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
// __SAMD51J19A__


// #ifdef _SAMD51J19A_
// #ifdef __SAMD51J19A__
// #ifdef ARDUINO_METRO_M4
#ifdef ARDUINO_METRO_M4
  #undef HAS_SPI_FLASH_DEMO
  #define QSPI_FLASHROM_PRESENT // assume Metro M4 Express Beta - for now (May 2018)
#endif // #ifdef ARDUINO_METRO_M4
// #endif // #ifdef _SAMD51J19A_
// #endif // #ifdef __SAMD51J19A__

// global override - debug
// #define HAS_SPI_FLASH_DEMO
// #undef HAS_SPI_FLASH_DEMO // kludge.  QSPI flash may be a game-changer.  wait.
// load echo! remove download are relevant only to presence of SPI flashROM.

