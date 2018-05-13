// Wed Jan 31 00:27:18 UTC 2018
// 4737-a0e-01a-

// kandra helgar tronde


// .arduino15/packages/adafruit/hardware/samd/1.0.21/variants/feather_m0_express/variant.h
// that's the location for feather M0 Express that gave D29 and D30 correctly.  15 Feb 2018d


// feather M0 Expresss:
//    SCK is on D30  -- ainsuForth can use pinMode and pinWrite on '30'.
//    MOSI is on D29


// confirmed: ST7565 can run on MOSI and SCK when referred to as 29 and 30 in the regular
//                   adafruit  arduino  ST7565 driver.  15 Feb 2018 15:48 UTC
//  using Feather M0 express



// MALAMUTE   CHACHARRE   PELGRUUT   KUSKIP

// SEE ALSO:
//   m0_interpreter_uart -- this gained the next shred in series
//   on 31 Jan 2018.  When incrementing ainsuForth-gen-exp shred
//   in (immediate) future, please take this into account.



// GOOD ON Metro M0 Express.  Most likely fine on Trinket M0,
// Feather M0 Express as well as CPX.  Needs additional tests
// to confirm all that.

// Only Gemma M0 is unconfigured and untested, now, of the five platforms.


// previous timestamps:

// Tue Jan 16 02:30:09 UTC 2018
// 4737-a0d-05j-

// Tue Jan 16 02:20:48 UTC 2018
// 4737-a0d-05g-

// GOOD ON CPX.  Seems fine on Trinket M0 and Feather M0 Express. Tue 16 Jan 02:20z


// PREVIOUS VERSION:
//     GOOD ON TRINKET M0 - FEATHER M0 EXPRESS only.
//     Porting to the other M0 boards comes later. -15 Jan 2018


// Mon Jan 15 19:19:47 UTC 2018
// 4737-a0d-05d-

// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// Sat Dec 16 03:49:57 UTC 2017
// 4737-a0a-00b-

// Sat Dec 16 01:24:37 UTC 2017   // 4737-a0a-00a-

// An expected error can occur:

//     E: fatfs.begin() fault.

// It is related to uninitialized SPI flashROM.

// ---------------------------------------------------------
// If you have a problem look below in this file, first, as
// it has some information of immediate use, with regard to
// routine errors that may occur when the SPI flashROM chip
// has not been initialized to the extent ainsuForth expects.
//  
// The (possibly) missing file is declared in getline.cpp:
// 
// 19 #define SPI_FlashROM_FILENAME "/forth/ascii_xfer_a001.txt"
// 
// When such a file is not found, it can cause ainsuForth
// to misoperate.
// 
// Edit compatibility.h to avoid this issue entirely, by
// disabling SPI flashROM use by ainsuForth.
// 
// In compatibility.h, this line decides if SPI flashROM support
// is compiled in or not:

// #define HAS_SPI_FLASH_DEMO

// Currently, this is disabled by default, though during
// active development it may have been forgotten (and
// enabled).
// ---------------------------------------------------------


// HELCUBIK  CANDALOX  TELURIXIANO  ELIAS NEKTUVIA

// NOTE: Cannot go very far with the new SPI flashROM support for
// ainsuForth, without learning something about this:

//    libraries/Adafruit_SPIFlash/examples/fatfs_full_usage/fatfs_full_usage.ino

// If you're uninterested, avoid the download, load and remove words.  Maybe others.

// Those words deal with the onboard SPI flashROM found on
// Adafruit M0 target boards, such as the Circuit Playground
// Express ('Express' in the name usually implies presence of
// SPI flashROM on that target board).



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - -      SPI  flashROM    - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// This commit provides for lack of any initialized filesystem
// on the target SPI flashROM chip, by disabling the routines
// that interact with the SPI flashROM.

// To re-enable, make a filesystem on the target's SPI flashROM,
// and add a '/forth' directory, as well as an initial file.

// Circuit Python is the suggested tool for this.

// It can be done in the Arduino system as well.

// Also, edit compatibility.h near the bottom of that file:

//   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    31  // reverse these two lines to enable SPI flashROM support:
//    32  #undef HAS_SPI_FLASH_DEMO
//    33  #define HAS_SPI_FLASH_DEMO
//    34  // load echo! remove download are relevant only to presence of SPI flashROM.
//   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Use a cpp (C preprocessor) macro to name the file that is
// read from, or written to, the SPI flashROM.

// from src/kernel/getline.cpp:

// 18 // macro to name the file read or written to SPI flashROM.
// 19 #define SPI_FlashROM_FILENAME "/forth/ascii_xfer_a001.txt"

// That's the expected path to the sample filename (cannot be
// changed elsewhere, only in getline.cpp, in this revision of
// the code).

// If the advice given is overlooked (this happens on an uninitialized
// target SPI flashROM, after an erasure, for example) then the system
// won't start properly:

// $ microcom -s 115200 -p /dev/ttyACM0 
// connected to /dev/ttyACM0
// 
// f_mount failed with error code: 13
// E: fatfs.begin() fault.

// That error seems specific to an uninitialized SPI flashROM chip
// (one that has been recently erased, removing the filesystem,
// or one that was never initialized).

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// more previous timestamps:
// Sun Dec 10 22:48:03 UTC 2017
// 4735-b0d-00b-   the -00x- is new Dec 10, 2017.

// Sat Nov 25 19:03:16 UTC 2017
// 4735-b0c-09d-   the -09x- is new Nov 24, 2017.
// Sat Nov 25 02:01:09 UTC 2017
// Fri Nov 24 05:23:48 UTC 2017
// 4735-b0c-09a-   the -09x- is new Nov 24, 2017.
// Fri Nov 24 04:49:08 UTC 2017
// 4735-b0c-07z-   the -07x- is new Nov 19, 2017.

// Fri Nov 24 02:42:54 UTC 2017
// Thu Aug  3 19:07:55 UTC 2017
// 4735-b0f-00-

// MULAMOTTE   HELEGRIDAK   03 Aug 2017  19:07z  -  the echo! word controls some silences

// KELDRIN  NOKURVID

// next: suppress echo during a file download.  Hmm.  It's suppressed when 'load' is run.

// NOTE: it is a 'load' because one is logged into the SAMD21 board,
// via USB and a terminal, and issues the command to 'load' from
// the SPI flashROM (a peripheral device) to the internal RAM of the SAMD21 chip
// (and stored there in RAM, compiled such that the virtual machine can
// execute this newly-stored program).
// 
// In that sense, 'compile' could also be a reasonable name for this same word.

// 'download' is for when the forth Interpreter is leveraged to acquire
// new source code to be stored onto SPI flashROM.

// GNAGA


// --------------------------------------------------
// --------------------------------------------------
// ---                                  -------------
// ---   Thu Aug  3 21:42:35 UTC 2017   -------------
// ---                                  -------------
// --------------------------------------------------
// --------------------------------------------------
// SUCCESS.  Wrote a download file, then read it in, using the 'download' and then the 'load' words.  w00t.
// --------------------------------------------------
// --------------------------------------------------
// --------------------------------------------------

// BUG:  captures the '\end.' word to SPI flash file.  Omit in future revision.



// MIPIXIC  CESSOME  RALDOXI  15:43z Thu 03 Aug 2017

// parser looks (provisionally) functional for whole-line echo to capture file.




// KELKANNE  GRIAMO  FISPARD 

// file echo complete.  Needs: parsing (or 'de-parsing' -- for whole-line repeat).

// partial: input line is echoed, and only once, in preparation for file capture to SPI flash as a file.fs or file.txt &c.


// the 'see' word was reinstated.  Appears to function well.  2 July 22:44z

// several words are now untested. 2 July 22:45z

// ++store_fetch.cpp
// ++dict_entries.cpp
// major housekeeping: dict_entries.h





// quite a bit of juggling.  Mistakes made?

// ------------------------------------------------------------------------
//   reserved.  messages go here.
// ------------------------------------------------------------------------

// TODO: test c! and 2drop as well as allot and variable

// Meanwhile:

// +max_min.cpp   max  min
// +char.cpp  char  [char]
// +do_loop.cpp
// +src/periph/neo_pixel.cpp
// +cblink.cpp

// , 2drop c! - three words added to dictionary.

// PRIMITIVE FORTH - working 18 June  -  HABILLEAUX   CHOGUFE   STELDONE   PARKEFF

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**  Version 0.7.0                                                           **/
/**                                                                          **/
/**  File: YAFFA.ino                                                         **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/**                                                                          **/
/**  This file is part of YAFFA.                                             **/
/**                                                                          **/
/**  YAFFA is free software: you can redistribute it and/or modify           **/
/**  it under the terms of the GNU General Public License as published by    **/
/**  the Free Software Foundation, either version 2 of the License, or       **/
/**  (at your option) any later version.                                     **/
/**                                                                          **/
/**  YAFFA is distributed in the hope that it will be useful,                **/
/**  but WITHOUT ANY WARRANTY; without even the implied warranty of          **/
/**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **/
/**  GNU General Public License for more details.                            **/
/**                                                                          **/
/**  You should have received a copy of the GNU General Public License       **/
/**  along with YAFFA.  If not, see <http://www.gnu.org/licenses/>.          **/
/**                                                                          **/
/******************************************************************************/
/**                                                                          **/
/**  DESCRIPTION:                                                            **/
/**                                                                          **/
/**  YAFFA is an attempt to make a Forth environment for the Arduino that    **/
/**  is as close as possible to the ANSI Forth draft specification DPANS94.  **/
/**                                                                          **/
/**  The goal is to support at a minimum the ANS Forth C core word set and   **/
/**  to implement wrappers for the basic I/O functions found in the Arduino  **/
/**  library.                                                                **/
/**  YAFFA uses two dictionaries, one for built in words and is stored in    **/
/**  flash memory, and the other for user defined words, that is found in    **/
/**  RAM.                                                                    **/
/**                                                                          **/
/******************************************************************************/
/**                                                                          **/
/**  REVISION HISTORY:                                                       **/
/**                                                                          **/
/**    0.7.0                                                                 **/
/**    - Fixed the how LEAVE is handled in LOOP and +LOOP.                   **/
/**    0.6.2                                                                 **/
/**    - Added words ">NUMBER", "KEY?", ".(", "0<>", "0>", "2>R", "2R>",     **/
/**      "2R@".                                                              **/
/**    - Removed static from the function headers to avoid compilation       **/
/**      errors with the new 1.6.6 Arduino IDE.                              **/
/**                                                                          **/
/**                                                                          **/
/** 2017: changed to yaffa.h -- reverting possibly what is mentioned         **/
/**       on the lines, below this one.                                      **/
/**                                                                          **/
/**                                                                          **/
/**    - changed file names from yaffa.h to YAFFA.h and Yaffa.ino to         **/
/**      YAFFA.ino and the #includes to reflect the capatilized name. This   **/
/**      helps with cheking out the project from github without renaming     **/
/**      files.                                                              **/
/**                                                                          **/
/**                                                                          **/
/**    - Fixed comments for pinWrite and pinMode.                            **/
/**    - yaffa.h reorganized for different architectures                     **/
/**    - Replaced Serial.print(PSTR()) with Serial.print(F())                **/
/**    0.6.1                                                                 **/
/**    - Documentation cleanup. thanks to Dr. Hugh Sasse, BSc(Hons), PhD     **/
/**    0.6                                                                   **/
/**    - Fixed PROGMEM compilation errors do to new compiler in Arduino 1.6  **/
/**    - Embedded the revision in to the compiled code.                      **/
/**    - Revision is now displayed in greeting at start up.                  **/
/**    - the interpreter not clears the word flags before it starts.         **/
/**    - Updated TICK, WORD, and FIND to make use of primitive calls for to  **/
/**      reduce code size.                                                   **/
/**    - Added word flag checks in dot_quote() and _s_quote().               **/
/**                                                                          **/
/**  NOTES:                                                                  **/
/**                                                                          **/
/**    - Compiler now gives "Low memory available, stability problems may    **/
/**      occur." warning. This is expected since most memory is reserved for **/
/**      the FORTH environment. Excessive recursive calls may overrun the C  **/
/**      stack.                                                              **/
/**                                                                          **/
/**  THINGS TO DO:                                                           **/
/**                                                                          **/
/**  CORE WORDS TO ADD:                                                      **/
/**      >NUMBER                                                             **/
/**                                                                          **/
/**  THINGS TO FIX:                                                          **/
/**                                                                          **/
/**    Fix the outer interpreter to use FIND instead of isWord               **/
/**    Fix Serial.Print(w, HEX) from displaying negative numbers as 32 bits  **/
/**    Fix ENVIRONMENT? Query to take a string reference from the stack.     **/
/**                                                                          **/
/******************************************************************************/


