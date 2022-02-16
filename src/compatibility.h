// Thu 12 Jul 06:31:01 UTC 2018
// 4737-a3b-019- // ainsuForth-gen-exp-m4

#include "config_dict.h"  // dictionary configuration

// previous timestamps:
// Fri 22 Jun 17:36:48 UTC 2018
// 4737-a3b-003-

// Mon 18 Jun 21:39:23 UTC 2018
// 4737-a3a-0f5-

// Sun 17 Jun 04:01:59 UTC 2018
// 4737-a3a-0cc-

// Tue 12 Jun 23:47:23 UTC 2018
// 4737-a3a-09b-

// Wed 30 May 17:49:01 UTC 2018
// 4737-a3a-07a-

// Mon 14 May 22:46:36 UTC 2018
// 4737-a3a-05e-

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


// __SAMD51G19A__ ADAFRUIT_TRELLIS_M4_EXPRESS __SAMD51__ __FPU_PRESENT ARM_MATH_CM4 CRYSTALLESS



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

#ifdef ADAFRUIT_ITSYBITSY_M0
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef ADAFRUIT_METRO_M0_EXPRESS

// M4 target offers an impoverished test - redefine later, tracking upstream refinements.
// __SAMD51J19A__

// commented out 20 June 2018 18:43z -- redundant:

// #ifdef ADAFRUIT_METRO_M4_EXPRESS
  // #undef HAS_SPI_FLASH_DEMO
  // #define QSPI_FLASHROM_PRESENT // assume Metro M4 Express Beta - for now (May 2018)
// #endif // ADAFRUIT_METRO_M4_EXPRESS

// global override - debug
// #define HAS_SPI_FLASH_DEMO
// #undef HAS_SPI_FLASH_DEMO // kludge.  QSPI flash may be a game-changer.  wait.
// load echo! remove download are relevant only to presence of SPI flashROM.


#ifdef ADAFRUIT_METRO_M4_EXPRESS
  #undef HAS_SPI_FLASH_DEMO
  #define HAS_QSPI_FLASH_DEMO   // note the 'Q' .. takes SPI and makes it QSPI in this flag
  #undef QSPI_FLASHROM_PRESENT
  #define QSPI_FLASHROM_PRESENT // problem flag: assumption was: Metro M4 Express Beta - for now (May 2018)
  #define COMMUTED_PIN_NPX 40 // unused - future dev or delme

  // NEO_PIXEL - Metro M4 Express - ENABLED 20 June 2018 18:49z
  // -------  use this to switch between them   ---------
  #undef NEO_PIXEL_LIB_ENABLED  // swap these two
  #define NEO_PIXEL_LIB_ENABLED // swap these two
  // -------  use this to switch between them   ---------
  #ifdef NEO_PIXEL_LIB_ENABLED
    #ifndef HAS_NEO_PIXEL_LIB
      #define HAS_NEO_PIXEL_LIB
    #endif // #ifndef HAS_NEO_PIXEL_LIB
  #endif // #ifdef NEO_PIXEL_LIB_ENABLED

  #ifndef NEO_PIXEL_LIB_ENABLED
    #ifdef HAS_NEO_PIXEL_LIB
      #undef HAS_NEO_PIXEL_LIB
    #endif
  #endif // #ifndef NEO_PIXEL_LIB_ENABLED
#endif // #ifdef ADAFRUIT_METRO_M4_EXPRESS

// 20 June 2018 18:48z:
// above stanza carefully indented for
//   human parsing of its structure.


/* shipping:
 * Adafruit CircuitPython 3.0.0-rc.0 on 2018-06-18; Adafruit Feather M4 Express with samd51j19
 * >>>
 */

#ifdef ADAFRUIT_FEATHER_M4_EXPRESS // __SAMD51J19A__
  #undef HAS_SPI_FLASH_DEMO
  #define HAS_QSPI_FLASH_DEMO
  #undef QSPI_FLASHROM_PRESENT
  #define QSPI_FLASHROM_PRESENT // problem flag: assumption was: Metro M4 Express Beta - for now (May 2018)
  #define COMMUTED_PIN_NPX 8

  // NEO_PIXEL - Feather M4 Express - ENABLED 12 July 2018 06:25z
  // -------  use this to switch between them   ---------
  #undef NEO_PIXEL_LIB_ENABLED  // swap these two
  #define NEO_PIXEL_LIB_ENABLED // swap these two
  // -------  use this to switch between them   ---------
  #ifdef NEO_PIXEL_LIB_ENABLED
    #ifndef HAS_NEO_PIXEL_LIB
      #define HAS_NEO_PIXEL_LIB
    #endif // #ifndef HAS_NEO_PIXEL_LIB
  #endif // #ifdef NEO_PIXEL_LIB_ENABLED




  #ifndef NEO_PIXEL_LIB_ENABLED
    #ifdef HAS_NEO_PIXEL_LIB
      #undef HAS_NEO_PIXEL_LIB
    #endif
  #endif // #ifndef NEO_PIXEL_LIB_ENABLED
#endif // #ifdef ADAFRUIT_FEATHER_M4_EXPRESS // __SAMD51J19A__



#ifdef ADAFRUIT_TRELLIS_M4_EXPRESS
  #undef HAS_SPI_FLASH_DEMO
  #define HAS_QSPI_FLASH_DEMO
  #undef QSPI_FLASHROM_PRESENT
  #define QSPI_FLASHROM_PRESENT


  #define COMMUTED_PIN_NPX 10 // unused - future dev or delme

  // NEO_PIXEL - Trellis M4 Express
  // -------  use this to switch between them   ---------
  #undef NEO_PIXEL_LIB_ENABLED  // swap these two
  #define NEO_PIXEL_LIB_ENABLED // swap these two
  // -------  use this to switch between them   ---------
  #ifdef NEO_PIXEL_LIB_ENABLED
    #ifndef HAS_NEO_PIXEL_LIB
      #define HAS_NEO_PIXEL_LIB
    #endif // #ifndef HAS_NEO_PIXEL_LIB
  #endif // #ifdef NEO_PIXEL_LIB_ENABLED

  #ifndef NEO_PIXEL_LIB_ENABLED
    #ifdef HAS_NEO_PIXEL_LIB
      #undef HAS_NEO_PIXEL_LIB
    #endif
  #endif // #ifndef NEO_PIXEL_LIB_ENABLED


  // DOTSTAR
  // -------  use this to switch between them   ---------

  #undef DOTSTAR_LIB_ENABLED  // swap these two
  #define DOTSTAR_LIB_ENABLED // swap these two

  // -------  use this to switch between them   ---------


  #ifdef DOTSTAR_LIB_ENABLED
    #ifndef HAS_DOTSTAR_LIB
      #define HAS_DOTSTAR_LIB
    #endif
  #endif

  #ifndef DOTSTAR_LIB_ENABLED
    #ifdef HAS_DOTSTAR_LIB
      #undef HAS_DOTSTAR_LIB
    #endif
  #endif

  // force define:
  #define HAS_DOTSTAR_LIB
#endif // #ifdef ADAFRUIT_TRELLIS_M4_EXPRESS



// adafruit_itsybitsy_m4.build.extra_flags=-D__SAMD51G19A__ -DADAFRUIT_ITSYBITSY_M4_EXPRESS -D__SAMD51__ {build.usb_flags} -D__FPU_PRESENT -DARM_MATH_CM4 -DCRYSTALLESS -mfloat-abi=hard -mfpu=fpv4-sp-d16
#ifdef ADAFRUIT_ITSYBITSY_M4_EXPRESS
  #undef HAS_SPI_FLASH_DEMO
  #define HAS_QSPI_FLASH_DEMO
  #undef QSPI_FLASHROM_PRESENT
  #define QSPI_FLASHROM_PRESENT // problem flag: assumption was: Metro M4 Express Beta - for now (May 2018)


// DOTSTAR
// -------  use this to switch between them   ---------

#undef DOTSTAR_LIB_ENABLED  // swap these two
#define DOTSTAR_LIB_ENABLED // swap these two

// -------  use this to switch between them   ---------


#ifdef DOTSTAR_LIB_ENABLED
  #ifndef HAS_DOTSTAR_LIB
    #define HAS_DOTSTAR_LIB
  #endif
#endif

#ifndef DOTSTAR_LIB_ENABLED
  #ifdef HAS_DOTSTAR_LIB
    #undef HAS_DOTSTAR_LIB
  #endif
#endif

#endif // #ifdef ADAFRUIT_ITSYBITSY_M4_EXPRESS










#ifdef ADAFRUIT_FEATHER_M0_EXPRESS


#define COMMUTED_PIN_NPX 8 // unused - future dev or delme

// NEO_PIXEL
// -------  use this to switch between them   ---------

#undef NEO_PIXEL_LIB_ENABLED  // swap these two
#define NEO_PIXEL_LIB_ENABLED // swap these two

// -------  use this to switch between them   ---------


#ifdef NEO_PIXEL_LIB_ENABLED
  #ifndef HAS_NEO_PIXEL_LIB
    #define HAS_NEO_PIXEL_LIB
  #endif
#endif

#ifndef NEO_PIXEL_LIB_ENABLED
  #ifdef HAS_NEO_PIXEL_LIB
    #undef HAS_NEO_PIXEL_LIB
  #endif
#endif
#endif // #ifdef ADAFRUIT_FEATHER_M0_EXPRESS


#ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0


#define COMMUTED_PIN_NPX 8 // unused - future dev or delme

// NEO_PIXEL
// -------  use this to switch between them   ---------

#undef NEO_PIXEL_LIB_ENABLED  // swap these two
#define NEO_PIXEL_LIB_ENABLED // swap these two

// -------  use this to switch between them   ---------


#ifdef NEO_PIXEL_LIB_ENABLED
  #ifndef HAS_NEO_PIXEL_LIB
    #define HAS_NEO_PIXEL_LIB
  #endif
#endif

#ifndef NEO_PIXEL_LIB_ENABLED
  #ifdef HAS_NEO_PIXEL_LIB
    #undef HAS_NEO_PIXEL_LIB
  #endif
#endif
#endif // #ifdef ADAFRUIT_FEATHER_M0_EXPRESS








#ifdef ADAFRUIT_METRO_M0_EXPRESS 

#define COMMUTED_PIN_NPX 40 // unused - future dev or delme

// NEO_PIXEL
// -------  use this to switch between them   ---------

#undef NEO_PIXEL_LIB_ENABLED  // swap these two
#define NEO_PIXEL_LIB_ENABLED // swap these two

// -------  use this to switch between them   ---------


#ifdef NEO_PIXEL_LIB_ENABLED
  #ifndef HAS_NEO_PIXEL_LIB
    #define HAS_NEO_PIXEL_LIB
  #endif
#endif

#ifndef NEO_PIXEL_LIB_ENABLED
  #ifdef HAS_NEO_PIXEL_LIB
    #undef HAS_NEO_PIXEL_LIB
  #endif
#endif
#endif // #ifdef ADAFRUIT_METRO_M0_EXPRESS 



#ifdef ADAFRUIT_TRINKET_M0

// DOTSTAR
// -------  use this to switch between them   ---------

#undef DOTSTAR_LIB_ENABLED  // swap these two
#define DOTSTAR_LIB_ENABLED // swap these two

// -------  use this to switch between them   ---------


#ifdef DOTSTAR_LIB_ENABLED
  #ifndef HAS_DOTSTAR_LIB
    #define HAS_DOTSTAR_LIB
  #endif
#endif

#ifndef DOTSTAR_LIB_ENABLED
  #ifdef HAS_DOTSTAR_LIB
    #undef HAS_DOTSTAR_LIB
  #endif
#endif



#endif // #ifdef ADAFRUIT_TRINKET_M0







#ifdef ADAFRUIT_GEMMA_M0

// DOTSTAR
// -------  use this to switch between them   ---------

#undef DOTSTAR_LIB_ENABLED  // swap these two
#define DOTSTAR_LIB_ENABLED // swap these two

// -------  use this to switch between them   ---------

#ifdef DOTSTAR_LIB_ENABLED
  #ifndef HAS_DOTSTAR_LIB
    #define HAS_DOTSTAR_LIB
  #endif
#endif

#ifndef DOTSTAR_LIB_ENABLED
  #ifdef HAS_DOTSTAR_LIB
    #undef HAS_DOTSTAR_LIB
  #endif
#endif
#endif // #ifdef ADAFRUIT_GEMMA_M0



#ifdef ADAFRUIT_ITSYBITSY_M0 // kludge! This is for crickit CPX as work-around

#define LEDX 37

#define COMMUTED_PIN_NPX 39 // guess is PA27 here - aka SPI SS
// tried: A2.  Based on '37' working for internal LED it seems it
// is possible the schematic pin number (physical) may possibly be
// a correct reference.  Weird.  WORKED!  So that is odd, or perhaps
// it's not at all odd.

// NEO_PIXEL
// -------  use this to switch between them   ---------

#undef NEO_PIXEL_LIB_ENABLED  // swap these two
#define NEO_PIXEL_LIB_ENABLED // swap these two

// -------  use this to switch between them   ---------


#ifdef NEO_PIXEL_LIB_ENABLED
  #ifndef HAS_NEO_PIXEL_LIB
    #define HAS_NEO_PIXEL_LIB
  #endif
#endif

#ifndef NEO_PIXEL_LIB_ENABLED
  #ifdef HAS_NEO_PIXEL_LIB
    #undef HAS_NEO_PIXEL_LIB
  #endif
#endif
#endif // #ifdef ADAFRUIT_ITSYBITSY_M0 // kludge!


// END.
