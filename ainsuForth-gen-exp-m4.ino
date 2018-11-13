// Mon Nov 12 23:54:26 UTC 2018
// 4737-a3c-00i- // ainsuForth-gen-exp-m4

// On branch _with_file_io_aa-

// Metro M4 Express now has working file i/o.
// Trellis M4 Express, ItsyBitsy M4 Express,
// and Feather M4 Express supported for QSPI
// flashROM file i/o, as well.

// ATSAMD51J19A, ATSAMD51G19A

// limited to a single, hard-coded filename - this file is
// stored in the /forth directory of the FAT filesystem on
// the 2MB QSPI flashROM at this time (12 NOV 2018, 01:47 UTC).

//   edits as of: Mon Nov 12 23:54:26 UTC 2018

// fitudele     neftogr      kerferdi     pliptog      mezveraki
// stefafo      pibmarute    kelnarg      tifkarsi     sifto
// tuzzah       tornaque     pivakia      kivandidu    mittaxl

// Sun Nov 11 20:45:12 UTC 2018
// 4737-a3c-00g- // ainsuForth-gen-exp-m4
// On branch testing-hh-ii-

// Fri Nov  9 03:44:59 UTC 2018
// 4737-a3c-00f- // ainsuForth-gen-exp-m4
// On branch testing-hh-

// August 28 2018 (or earlier) notes, follow.

// itsybitsy m4 basic checkout seems fine.

// title sequence for itsym4 is

//     three colors in sequence
//     followed by a monopong on D13
//     until someone connects.

// this is to exercise the dotstar a little.  older code for gemma m0 and trinket m0
// should have a similar idea going.

// the others are probably sequenced with just a magenta NeoPixel quick blink
// ping-ponged against the red LED until connection.

// all the above from (human) memory - details may be off.

// previous:

// Sun Nov  4 02:32:24 UTC 2018
// 4737-a3c-00e- // ainsuForth-gen-exp-m4
// On branch testing-gg-

// Sun Nov  4 01:50:28 UTC 2018
// 4737-a3c-00d- // ainsuForth-gen-exp-m4
// On branch testing-gg-

// Tue Aug 28 18:10:58 UTC 2018
// 4737-a3c-00c- // ainsuForth-gen-exp-m4
// On branch master

// Tue Aug 28 17:11:45 UTC 2018
// 4737-a3c-00b- // ainsuForth-gen-exp-m4
// On branch testing-ee

// Wed Aug 22 03:12:41 UTC 2018
// 4737-a3c-00a- // ainsuForth-gen-exp-m4

// Compiles and operational Metro M4 Express (samd51)



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//                  s t r u c t u r e

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// August, 2018:

// This file, ainsuForth-gen-exp-m4.ino, serves as
// a Changelog pretty much.

// There is NO CODE at all in this file.  It is a placeholder
// to satisfy the requirement of a correctly named *.ino file
// to head the project, in the Arduino IDE.

// See various internet references as to how this works,
// exactly.  Everything but this file is a .cpp file, and
// that's permitted.

// ainsuForthsketch.cpp  is the expected top level file, and
// serves the same purpose as the primary (the .ino) file does.

// It has setup() and loop() defined, for example.

// Each (and every) .cpp needs to include Arduino.h, to
// bring in the basics (such as typedef statements) that are
//  not in the compiler itself:

// #include <Arduino.h>

// like that.

// the ./src directory is the only allowed directory name for
// the first-level source tree, found to function correctly.

// Other directory names at the same level (as ./src) appear to
// be ignored by the Arduino IDE (and so are a great place to
// hide good information the compiler should not try to parse).


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// more previous:
// Wed Aug 22 02:31:57 UTC 2018
// Thu 12 Jul 14:20:50 UTC 2018
// 4737-a3b-01b- // ainsuForth-gen-exp-m4

// Thu 12 Jul 06:31:01 UTC 2018 // 4737-a3b-019-

// Fri  6 Jul 06:50:19 UTC 2018 // 4737-a3b-017-
// Sat 23 Jun 02:43:45 UTC 2018 // 4737-a3b-00b-
// Fri 22 Jun 21:37:41 UTC 2018 // 4737-a3b-009-
// Fri 22 Jun 17:36:48 UTC 2018 // 4737-a3b-003-
// Thu 21 Jun 22:17:21 UTC 2018 // 4737-a3b-001-  +dict_comments_only.cpp file
// Thu 21 Jun 17:57:32 UTC 2018 // 4737-a3a-0fe-
// Wed 20 Jun 22:29:00 UTC 2018 // 4737-a3a-0fb-
// Wed 20 Jun 21:18:37 UTC 2018 // 4737-a3a-0f9-
// Wed 20 Jun 18:54:05 UTC 2018 // 4737-a3a-0f7-
// Mon 18 Jun 21:39:23 UTC 2018 // 4737-a3a-0f5-

// Mon 18 Jun 23:44:16 UTC 2018
// +crickit_cpx_as_itsy_m0

// crickit CPX supported when compiled as ItsyBitsy M0.
//    Has working NeoPixel (D39) and internal LED (on D37)

//    Tested good:

//    * cpx
//    * itsy m4
//    * gemma m0
//    * trinket m0
//    * crickit cpx
//    * metro m0 expr
//    * metro m4 expr
//    * feather m0 expr

//    Note - the 'pixel' word is more interesting on the CPX target board.

/*

1 13 pinMode
: pon 1 13 pinWrite ;
: poff 0 13 pinWrite ;
pon
poff
: blinks 0 do
pon 300 delay
poff 400 delay
loop ;
3 blinks
5 blinks
17 blinks

*/

// Mon 18 Jun 06:10:28 UTC 2018
// 4737-a3a-0f2-

// good clean sweep - all tested good on RGB and available filesystem support.
// this is the best of ainsuForth as of 18 June 2018 - in any branch or repository.

// Mon 18 Jun 05:32:01 UTC 2018
// 4737-a3a-0e7-

// Mon 18 Jun 03:50:24 UTC 2018
// 4737-a3a-0e5-

// second attempt to modify testing-aa after a good merge.

// CPX is now okay with NeoPixels.  The pix40 business was bad for CPX - enough to hang it.

// TODO: verify ItsyM4, Feather M0 Express, Metro M0 Express and Metro M4 Express each at least functions (with or without onboard RGB led support).

// Metro M0 Express is now okay with NeoPixel.
// ItsyBitsy M4 is now okay with its dotstar (3-color strobe, once, prior to USB serial connection, only).
// Feather M0 Express is now okay with its singleton onboard NeoPixel.

// Metro M4 needed an adjustment  -- may warrant a recheck of the other boards.
// Trinket M0 also needed an adjustment - it is dotstar.
// Gemma M0 as well needed adjustment.  compatibility.h got a workout today.

// Finally - dotstar.cpp had a big leak that is now plugged (hopefully).
// Unlike neo_pixel.cpp it never had a conditional to bring in all the code in the file.
// Now, it does.  CPX seemed to need it (something escaped the logic net and the CPX build unmasked this.  No idea just what that was.

// Sun 17 Jun 22:09:15 UTC 2018
// 4737-a3a-0e0-

// +eflmkdir word - external flash mkdir '/forth' (the path, '/forth' is hard-coded).

// caspitana   asa   selkitte 

// On branch 'testing-aa'
// Current Target: Feather M0 Express 17 June 2018 22:09z


// Towards Feather M0 Express JEDEC newfile instantiation (and its containing directory).


// New Word in Forth Dictionary:

//     see ag, the silver searcher entry, below - good example of all requirements to add a new word to the forth dictionary, from scratch.

//      it's near line 68.




// - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TESTBED: Adafruit Feather M0 Express only.  17 June 2018 22:09 UTC
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - -

// Sun 17 Jun 21:28:37 UTC 2018
// 4737-a3a-0cf-

// Prep for 'git branch testing-aa'
// commit in new branch.

// This message only in branch testing-aa at this time (21:53z 17 June 2018).

// this is master branch again.

// this comment only in branch 'master' as of 21:54z on 17 June, 2018.

// Sun 17 Jun 05:21:05 UTC 2018
// 4737-a3a-0ce-

// Sun 17 Jun 04:01:59 UTC 2018
// 4737-a3a-0cc-

// celepatter  utantun   swanton  telgar fisuva

// 17 June 2018:
//   Second Test Run:
//   * Metro M0 Express tested against.  JEDEC good and the load and download words work fine, as does the remove word.
//   * as expected NeoPixel support wasn't there.  Easy fix, just put in the effort.

//   First Test Run:
//   * tested against Feather M0 Express.  Working NeoPixel.
//   * JEDEC good; did not instantiate file to test load and download words.
//   *  in forth, type:
//      1 13 pinMode 1 13 pinWrite (human delay) 0 13 pinWrite  // test D13 LED
//   * modded to more automatically operate with NeoPixel on D8 - not working.
//   * tested (late, just before commit) against ItsyBitsy M4 and seems fine (dotstar prelude is operational)






// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - -
// - - - -
// - - - -                ag, the silver searcher -- eflmkdir 
// - - - -
// - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// 17 June 2018, 23:23z - ag output (brief, edited):

//  rvim ard $ ag eflmkdir
// Dictionary.h
// 4:// eflmkdir word needs getline.h included

// flashDict.cpp
// 4:// eflmkdir - external flashROM mod - create new directory 17 June 2018.
// 5:// NOTE: you must compile this 'eflmkdir' word.  The very
// 17:// { eflmkdir_str,       _eflmkdir,        IMMEDIATE + COMP_ONLY },
// 348:  { eflmkdir_str,       _eflmkdir,        IMMEDIATE + COMP_ONLY },

// src/kernel/getline.h
// 49:extern const char eflmkdir_str[]; // = "eflmkdir"; // forth vocabulary external flash mkdir
// 50:extern void _eflmkdir(void); // OLD NAME WAS: extern void create_test_directory(void);

// src/kernel/getline.cpp
// 448:const char eflmkdir_str[] = "eflmkdir"; // forth vocabulary external flash mkdir
// 450:void _eflmkdir(void) {
// 893:  // _eflmkdir(); // OLD NAME WAS: create_test_directory();

// ainsuForth-gen-exp-m4.ino
// 4:// +eflmkdir word - external flash mkdir '/forth' (the path, '/forth' is hard-coded).
//  rvim ard $ 

// Tue 12 Jun 23:47:23 UTC 2018
// 4737-a3a-09b-

// dotstar for ItsyM4

// Tue 12 Jun 20:55:50 UTC 2018
// 4737-a3a-09a-  // see the crkt (SAMD21) variant of this code for history of this shred

// calcifoss

// attempt to include ItsyBitsyM4 in this general/generic M4 version of the code base.


// previous timestamps:
// Sat 26 May 03:36:19 UTC 2018
// 4737-a3a-05t-

// mipafelmp  kevtiga  fibebbl

// kronstan  telvugulo


// Wed 23 May 19:37:12 UTC 2018
// 4737-a3a-05s-

// pebliak  nevado  tesfu
// keevado nfelgik

// working on an M4 implementation/port.

// Wed 23 May 03:16:05 UTC 2018
// 4737-a3a-05p-

// Tue 22 May 23:16:53 UTC 2018
// 4737-a3a-05k-

// Tue 15 May 01:57:23 UTC 2018
// 4737-a3a-05f-

// Mon 14 May 22:46:36 UTC 2018
// 4737-a3a-05e-

// Mon 14 May 20:26:35 UTC 2018
// 4737-a3a-05c-

// Mon 14 May 18:47:28 UTC 2018
// 4737-a3a-05a-

// Sun 13 May 06:53:54 UTC 2018
// 4737-a3a-03f-

// Wed Jan 31 00:27:18 UTC 2018
// 4737-a0e-01a-

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
// ---   Tue 15 May 01:57:23 UTC 2018   -------------
// ---                                  -------------
// --------------------------------------------------
// --------------------------------------------------
// SUCCESS.  Did something with QSPI on Metro M4 Express Beta.  Seems to auto-configure for Metro M0 Express - no intervention. -15 May 2018
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


// monopong   wa1tnr  28 August 2018

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

