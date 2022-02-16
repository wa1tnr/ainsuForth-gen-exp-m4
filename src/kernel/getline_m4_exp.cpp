// Sun Nov 11 20:45:12 UTC 2018
// 4737-a3c-00g- // ainsuForth-gen-exp-m4
// On branch testing-hh-ii-

#ifdef HAS_EXP_MFOUR_QSPI_FLASH
#define CURRENT_FILESYSTEM fatfs


















// Fri Nov 24 23:31:39 UTC 2017
// 4735-b0c-09b-   the -09x- is new Nov 24, 2017.

// implemented a cpp macro to name the file read or written to SPI flashROM. 24 NOV 2017

// To ignore previous files stored in SPI flashROM, change the macro below
// to name a new file, then recompile the program and upload it
// to the target, using standard Arduino toolchain.  This is a kludge
// to allow a fresh program download from the forth interpreter into
// spi flashROM.

// previous timestamps:
// Fri Nov 24 05:23:48 UTC 2017
// 4735-b0c-09a-   the -09x- is new Nov 24, 2017.
// Thu Aug  3 19:07:55 UTC 2017
// 4735-b0f-00-

// macro to name the file read or written to SPI flashROM.
// #ifdef HAS_SPI_FLASH_DEMO // 15 Jan 2018
    #define SPI_FlashROM_FILENAME "/forth/ascii_xfer_a001.txt"
    #define SPI_FlashROM_TOPDIR   "/forth"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// 16 January 2018 00:24z:
// 
// The SPI flashROM *must* be pre-initialized by some other
// program.  The root directory *must* have a subdirectory
// named '/forth' (unless you change the hard-coded path,
// named above, and carry out any needed adjustments).
// The directory '/forth' does *not* have to have the named
// file present ('ascii_xfer_a001.txt') as it will be created
// the first time the 'download' word is used.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    #include <Arduino.h> // LINE 59
    #include "../yaffa.h" // LINE 60

    #ifdef EXT_KERN_GETLINE
        #include "getline.h" // this is the flag wanted: HAS_QSPI_FLASHROM_LIB
        #ifdef HAS_QSPI_FLASHROM_LIB // 11 Nov 2018 // NEW LINE 64
            #warning HAS_QSPI_FLASHROM_LIB includes extra code on line 65 __getline_m4_exp.cpp__
            #define FLASH_DEVICE_GD25Q
            #ifdef FLASH_DEVICE_GD25Q

// flash_ops.cpp  wa1tnr
// Wed Aug 21 02:15:00 UTC 2019 0.1.8 good-compiler-aa-bb  shred: abn-515

                #include <SPI.h>
                // #include "SdFat.h"
                #include <SdFat.h>
                // #include "Adafruit_SPIFlash.h"
                #include <Adafruit_SPIFlash.h> // NEW LINE 68
// RESCIND //   #include <Adafruit_SPIFlash_FatFs.h> // NEW LINE 69
// RESCIND //   #include "Adafruit_QSPI_GD25Q.h"
// RESCIND //   #define FLASH_TYPE     SPIFLASHTYPE_W25Q16BV  // Flash chip type. // NEW LINE 71
 
// RESCIND //   Adafruit_QSPI_GD25Q flash;
// RESCIND //   Adafruit_M0_Express_CircuitPython CURRENT_FILESYSTEM(flash);


// LINE 77

#if defined(__SAMD51__) || defined(NRF52840_XXAA)
  Adafruit_FlashTransport_QSPI flashTransport(PIN_QSPI_SCK, PIN_QSPI_CS, PIN_QSPI_IO0, PIN_QSPI_IO1, PIN_QSPI_IO2, PIN_QSPI_IO3);
#else
  #if (SPI_INTERFACES_COUNT == 1)
    Adafruit_FlashTransport_SPI flashTransport(SS, &SPI);
  #else
    Adafruit_FlashTransport_SPI flashTransport(SS1, &SPI1);
  #endif
#endif

Adafruit_SPIFlash flash(&flashTransport);

// file system object from SdFat
FatFileSystem fatfs;

File myFile;

#define WORKING_DIR "/forth"
























// LINE 100







// LINE 108
// ------------------------ this was SPI   not    SPI1   ------ when did this change?
// LINE 110



// Adafruit_SPIFlash flash(FLASH_SS, &FLASH_SPI_PORT); // Adafruit_QSPI_GD25Q flash;

// Adafruit_W25Q16BV_FatFs fatfs(flash); // Adafruit_M0_Express_CircuitPython CURRENT_FILESYSTEM(flash);

#endif // 15 Jan 2018
/* these two levels cpp still open 11 Nov 21:53 UTC:
#ifdef HAS_EXP_MFOUR_QSPI_FLASH
    #ifdef EXT_KERN_GETLINE
        #directive
*/
/******************************************************************************/
/** getDLKey                                                                 **/
/**   waits for the next valid key to be entered in download mode (DL)       **/
/**   and return its value                                                   **/
/**   Watches for code-escape key '\' (backslash) to detect the '\end.' word **/
/**   Valid characters are:  Backspace, Carriage Return (0x0d), Escape,      **/
/**   Tab, Newline (0x0a) and standard (printable) characters                **/
/******************************************************************************/

// 28 august 22:13z after a long hunt, this seems to not be wanted:
//      #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018

void setup_qspiFlashROM(void) { // void setup_spi_flash(void) {
    Serial.print("Hello from setup_qspi m4 getline stuff.   ");

    if (!flash.begin()) { // if (!flash.begin(FLASH_TYPE)) {
        Serial.println("E: could not find flash on QSPI bus.");
        while(1);
    }
    // Serial.print("Flash chip JEDEC ID: 0x"); Serial.println(flash.GetJEDECID(), HEX);
    Serial.println("Found QSPI Flash.");
    // Serial.print("Flash chip JEDEC ID: 0x");
    // Serial.println(flash.GetJEDECID(), HEX);
    // Serial.println(" want to see a message that says: Flash chip JEDEC ID: 0x1401501\r\n");

    // CURRENT_FILESYSTEM fatfs
    // RESCIND // flash.setFlashType(FLASH_TYPE); // new November 9 2018

    // if (!CURRENT_FILESYSTEM.begin()) {
    //        if    (!fatfs.begin(&flash)) {

    if (!CURRENT_FILESYSTEM.begin(&flash)) {
        Serial.println("Failed to mount filesystem!");
        Serial.println("Was CircuitPython loaded on the board first to create the filesystem?");
        // Serial.println(SPI_FlashROM_FILENAME);
        while(1);
    }
    Serial.println("NOV 2018: Mounted filesystem!");
}
//     removed #EnDiF


/******************************************************************************/
/** getLine                                                                  **/
/**   read in a line of text ended by a Carriage Return (ASCII 13)           **/
/**   Valid characters are:  Backspace, Carriage Return, Escape, Tab, and    **/
/**   standard printable characters. Passed the address to store the string, **/
/**   and Returns the length of the string stored                            **/
/******************************************************************************/

        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
File thisFile;
        #endif // 15 Jan 2018
        // #directive

uint8_t getLine(char* ptr, uint8_t buffSize) {
  char inChar;
  uint8_t count = 0;

  // if (fileClosed) { Serial.println("Indeed, fileClosed is TRUE"); }

        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
  if (spiFlashReading) {
      // cheap_test: if (fatfs.exists("/forth/job.fs")) {



      // if (CURRENT_FILESYSTEM.exists("data.txt")) { // if (fatfs.exists(SPI_FlashROM_FILENAME)) {
      if (CURRENT_FILESYSTEM.exists(SPI_FlashROM_FILENAME)) {

          if (fileClosed) {

        //  File bootPy = CURRENT_FILESYSTEM.open("data.txt", FILE_READ);
            File bootPy = CURRENT_FILESYSTEM.open(SPI_FlashROM_FILENAME, FILE_READ);

        //  File forthSrcFile = fatfs.open(SPI_FlashROM_FILENAME, FILE_READ);

        //  thisFile = (File) forthSrcFile;
            thisFile = (File) bootPy;
            fileClosed = FALSE ; // it is open, now.
          }
      }
  }
        #endif // 15 Jan 2018


// another getLine() stanza:
  do {
        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
    if (spiFlashReading) {
        if (thisFile) {
            if (thisFile.available()) {
             // this is where every character of job.fs is read from SPI flash:
                inChar = thisFile.read();

                spiFlashWaiting = FALSE;
                if (thisFile.available()) {
                    spiFlashWaiting = TRUE;
                } else {
                    fileClosed = TRUE; // want to close the file - set a flag
                    spiFlashReading = FALSE; // shutdown the reading mechanism
                }
            }
        }

    } else {
        #endif // 15 Jan 2018

        if (noInterpreter) {
            inChar = getKey();
            if (inChar == '\\') {
                // Serial.print("ESC \\ SEEN in getLine().\r\n");
            }
        } else {
            inChar = getKey(); 
        }
        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
    }
        #endif // 15 Jan 2018

    // inChar is now populated; either by keypress or by byte stored in SPI flash.

    if (inChar == ASCII_BS || inChar == ASCII_DEL) {  // new: was only ASCII_BS
       if (count) {
         *--ptr = 0;
         count--; // ainsuForth improvement -- backspace behavior


if (silentReading) { } else {
    if (flags & ECHO_ON) Serial.print("\b \b");
}



      }
    }
    else if (inChar == ASCII_TAB || inChar == ASCII_ESC) {


if (silentReading) { } else {
      if (flags & ECHO_ON) Serial.print("\a");
}




    }
    else if (inChar == ASCII_CR || inChar == ASCII_NL) { // ainsuForth improvement

                          // iirc, this was for use during colon definition upload,
                          // using copy and paste into the serial terminal.

                          // Basis: lack of newline sensitivity; added some.

                          // Test: revert, attempt a multi-line code paste.  If
                          // it fails or behaves poorly, reenable this code.
                          // Compare the two behaviors.

                          // iirc, interactive typing to the interpreter masks
                          // this behavior, whereas a paste-in unmasks it.

// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------

      // if (silentReading && spiFlashReading) { // the 'load' word
      if (silentReading) { // the 'load' word
      } else {
              if (flags & ECHO_ON) Serial.print(" "); // seems to want a space after 'dot' for example.
      }
// -----------------------------------------------------
// -----------------------------------------------------
// TRY TO REMEMBER:
// 
// The mechanism to end a file upload to the SPI Flash
// is a parsed word '\end.'

// Whereas .. the mechanism to end a 'load' (compile
// into VM code, stored in RAM -- from a disk file forth
// source program that's stored on SPI FlashROM)
// 
// That mechanism is simply to detect if flash is waiting
// (if we have reached EOF or not while reading a file
// from the SPI FlashROM chip).
// -----------------------------------------------------

      // debug // Serial.println("EVERYONE");
      // Serial.println("debug: is flash waiting or not?");
      if (spiFlashWaiting) {
          // Serial.println("a good spot to turn off silentReading perhaps.");
          // Serial.println("Flash is WAITING .. more to read.");
      } else { 
          silentReading = FALSE; // we are interactive once more, when spiFlashWaiting changes state
      }

      break;

    } else {



// always suppress echo when the load word is executed.
      if (silentReading && spiFlashReading) { // the 'load' word
          int fakeSPxT = 0;
      } else {
          if (flags & ECHO_ON) {
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
if (silentReading) {
} else {
              // main forth interpreter typing echo is right here:
              Serial.print(inChar); // do NOT suppress this ordinarily, if ever.
}
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
          }
      }

      *ptr++ = inChar;
      *ptr = 0;
      count++;
    }
  } while (count < buffSize);
  return (count);
}

        #endif
    #endif // #ifdef EXT_KERN_GETLINE


#ifdef EXT_KERN_GETKEY

/******************************************************************************/
/** getKey                                                                   **/
/**   waits for the next valid key to be entered and return its value        **/
/**   Valid characters are:  Backspace, Carriage Return (0x0d), Escape,      **/
/**   Tab, Newline (0x0a) and standard (printable) characters                **/
/******************************************************************************/
char getKey(void) {
    char inChar;
    // the load word provides this boolean:
    if (spiFlashReading) {
        if (inChar == ASCII_BS  ||
            inChar == ASCII_TAB ||
            inChar == ASCII_CR  ||  
            inChar == ASCII_NL  ||   // new
            inChar == ASCII_DEL ||   // new
            inChar == ASCII_ESC ||
            isprint(inChar)) {
            return inChar;
        }
    } else {
        while (1) {
            if (Serial.available()) {
                inChar = Serial.read();
                if (inChar == ASCII_BS  ||
                    inChar == ASCII_TAB ||
                    inChar == ASCII_CR  ||  
                    inChar == ASCII_NL  ||   // new
                    inChar == ASCII_DEL ||   // new
                    inChar == ASCII_ESC ||
                    isprint(inChar)) {
                    return inChar;
                }
            }
        }
    }
}

#endif







//  ---------------------------    ascii  transfer   --------------------------


//                      03 August 2017  15:49z begin.


// Wed Aug  2 01:22:51 UTC 2017
// 4735-b0c-03-

// #include <Arduino.h>
// #include "../../yaffa.h"
// #include "fatfs_writefile.h"

// Adafruit SPI Flash FatFs Full Usage Example
// Author: Tony DiCola

// locally modified July 2017 - wa1tnr

// modified to look at python in the fatfs - code.py and the /lib.

// This is an example of all the functions in the SPI Flash
// FatFs library.  Note that you MUST have a flash chip that's
// formatted with a flash filesystem before running.  See the
// fatfs_format example to perform this formatting.
//
// In general the API for this library closely follows the API
// for the Arduino SD card library.  However instead of interacting
// with a global SD object you create an instance of a fatfs class
// and use its open, exists, etc. functions.  See the SD library
// reference for more inspiration and examples to adapt:
//   https://www.arduino.cc/en/reference/SD
//
// Usage:
// - Modify the pins and type of fatfs object in the config
//   section below if necessary (usually not necessary).
// - Upload this sketch to your M0 express board.
// - Open the serial monitor at 115200 baud.  You should see the
//   example start to run and messages printed to the monitor.
//   If you don't see anything close the serial monitor, press
//   the board reset buttton, wait a few seconds, then open the
//   serial monitor again.
// #include <SPI.h>
// #include <Adafruit_SPIFlash.h>
// #include <Adafruit_SPIFlash_FatFs.h>


// Configuration of the flash chip pins and flash fatfs object.
// You don't normally need to change these if using a Feather/Metro
// M0 express board.
// #define FLASH_TYPE     SPIFLASHTYPE_W25Q16BV  // Flash chip type.
                                              // If you change this be
                                              // sure to change the fatfs
                                              // object type below to match.
// #define FLASH_SS       SS                    // Flash chip SS pin.
// #define FLASH_SPI_PORT SPI                   // What SPI port is Flash on?

// SHOULD NOT BE NEEDED 06 Aug:  Adafruit_SPIFlash ascii_xfer_flash(FLASH_SS, &FLASH_SPI_PORT);     // Use hardware SPI 

// Alternatively you can define and use non-SPI pins!
// Adafruit_SPIFlash flash(FLASH_SCK, FLASH_MISO, FLASH_MOSI, FLASH_SS);

// Adafruit_W25Q16BV_FatFs ascii_xfer_fatfs(ascii_xfer_flash);


const char eflmkdir_str[] = "eflmkdir"; // forth vocabulary external flash mkdir
// void create_test_directory(void) {
void _eflmkdir(void) {
  // Check if a directory called 'test' exists and create it if not there.
  // Note you should _not_ add a trailing slash (like '/test/') to directory names!
  // You can use the same exists function to check for the existance of a file too.

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
// #ifdef HAS_STANDARD_BUILD_HERE

// #define SPI_FlashROM_TOPDIR   "/forth"
// if (!fatfs.exists("/test")) {
  // if (!fatfs.exists(SPI_FlashROM_TOPDIR)) {
  if (!CURRENT_FILESYSTEM.exists(SPI_FlashROM_TOPDIR)) {
    Serial.println("/forth directory not found, creating...");
    // Use mkdir to create directory (note you should _not_ have a trailing slash).
  // if (!fatfs.mkdir("/test")) {
    // if (!fatfs.mkdir(SPI_FlashROM_TOPDIR)) {
    if (!CURRENT_FILESYSTEM.mkdir(SPI_FlashROM_TOPDIR)) {
      Serial.println("Error, failed to create test directory!");
      while(1);
    }
    Serial.println("Created /forth directory!");
  }
#endif




#ifdef NEVER_DEFINED_TEN_THREE // nonsense tag to prevent compile
#ifndef HAS_STANDARD_BUILD_HERE

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
// #define SPI_FlashROM_TOPDIR   "/forth"
// if (!fatfs.exists("/test")) { Serial.println("BAD ROBOT - fatfs.exists fails on line 97.");
  // if (!fatfs.exists(SPI_FlashROM_TOPDIR)) {
  if (!CURRENT_FILESYSTEM.exists(SPI_FlashROM_TOPDIR)) {
    Serial.println("BAD ROBOT - fatfs.exists fails on line 473 June 17, 2018.");
  } else {
    Serial.println("local: assuming /forth directory already exists.");
  }
#endif // 15 Jan 2018

#endif
#endif
}


#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void remove_a_file(void) {
  Serial.print("file: Deleting ");
  Serial.print(SPI_FlashROM_FILENAME);
  Serial.println("...");

  // if (!fatfs.remove(SPI_FlashROM_FILENAME)) {
  if (!CURRENT_FILESYSTEM.remove(SPI_FlashROM_FILENAME)) {
      Serial.print("Error, file ");
      Serial.print(SPI_FlashROM_FILENAME);
      Serial.println(" was not removed!");
      while(1);
  }
  Serial.println("Deleted file!");
  // kludge: disallow this filename to be missing from the directory - create a blank new file:
  // File writeFile = fatfs.open(SPI_FlashROM_FILENAME, FILE_WRITE);
  File writeFile = CURRENT_FILESYSTEM.open(SPI_FlashROM_FILENAME, FILE_WRITE);
  // if (!CURRENT_FILESYSTEM.remove(SPI_FlashROM_FILENAME)) {

  if (!writeFile) {
      Serial.print("Error, failed to open ");
      Serial.print(SPI_FlashROM_FILENAME);
      Serial.println(" for writing!");
      while(1); // what does this do .. hold the program in a forever loop upon failure?
      Serial.println("Exiting forever loop of getline.cpp -- probably means a serious error occurred. LINE 408.");
  } else {
  Serial.println("An empty new file was created in its place.");
  Serial.println("This kludge will go away when multi-filename usage is more fully integrated.");
  writeFile.println(" ");
  // writeFile.println(".( WRITE FILE is done.\) cr");
  writeFile.close(); // housekeeping.
  }
}
#endif // 15 Jan 2018

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void write_a_capture_file(void) {
  // Create a file in the test directory and write data to it.
  // Note the FILE_WRITE parameter which tells the library you intend to
  // write to the file.  This will create the file if it doesn't exist,
  // otherwise it will open the file and start appending new data to the
  // end of it.  More advanced users can specify different file modes by
  // using the FatFs f_open modes directly (which can be specified instead
  // of FILE_WRITE), see documentation at:
  //   http://elm-chan.org/fsw/ff/en/open.html

  // 03 Aug 15:52z -- try to use existing fatfs 'handle' / whatever it is
  // result: does compile just fine.

  // File writeFile = ascii_xfer_fatfs.open("/test/ascii_xfer_test.txt", FILE_WRITE);
    // CURRENT_FILESYSTEM fatfs
  // File writeFile =               fatfs.open(SPI_FlashROM_FILENAME, FILE_WRITE);
  File writeFile =               CURRENT_FILESYSTEM.open(SPI_FlashROM_FILENAME, FILE_WRITE);
  if (!writeFile) {
    Serial.print("Error, failed to open ");
    Serial.print(SPI_FlashROM_FILENAME);
    Serial.println(" for writing!");
    while(1);
  }
  // debug: // Serial.println("Opened file /forth/ascii_xfer_test.txt for writing/appending...");

  // Once open for writing you can print to the file as if you're printing
  // to the serial terminal, the same functions are available.

// payload -- download mode.

// model: Serial.print(cpSource);
  writeFile.println(cpSource);

  // Close the file when finished writing.
  writeFile.close();
  // debug: // Serial.println("Wrote -- appended -- to file /forth/ascii_xfer_test.txt!");
}
#endif // 15 Jan 2018


#ifndef HAS_STANDARD_BUILD_HERE

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void read_a_test_file(void) {
  // Now open the same file but for reading.
  // cheap_test: File readFile = fatfs.open("/forth/job.fs",             FILE_READ);
    // CURRENT_FILESYSTEM fatfs
  // File readFile = fatfs.open(SPI_FlashROM_FILENAME, FILE_READ);
  File readFile = CURRENT_FILESYSTEM.open(SPI_FlashROM_FILENAME, FILE_READ);
  if (!readFile) {
    // cheap_test: Serial.println("Error, failed to open job.fs for reading!");
    // Serial.println("Error, failed to open /forth/ascii_xfer_test.txt for reading!");
    Serial.print("Error, failed to open ");
    Serial.print(SPI_FlashROM_FILENAME);
    Serial.println(" for reading!");
    while(1);
  }
  // Read data using the same read, find, readString, etc. functions as when using
  // the serial class.  See SD library File class for more documentation:
  //   https://www.arduino.cc/en/reference/SD
  // Read a line of data:
  String line = readFile.readStringUntil('\n');
  // cheap_test: Serial.print("First line of job.fs: "); Serial.println(line);
  Serial.print("First line of ");
  Serial.print(SPI_FlashROM_FILENAME);
  Serial.println(line);
  // You can get the current position, remaining data, and total size of the file:
  Serial.print("Ignore job.fs and say ");
  Serial.print(SPI_FlashROM_FILENAME);
  Serial.print(" here - several lines.");
  Serial.print("Total size of job.fs (bytes): "); Serial.println(readFile.size(), DEC);
  Serial.print("Current position in job.fs: "); Serial.println(readFile.position(), DEC);
  Serial.print("Available data to read in job.fs: "); Serial.println(readFile.available(), DEC);

  // And a few other interesting attributes of a file:
  Serial.print("File name: "); Serial.println(readFile.name());
  Serial.print("Is file a directory? "); Serial.println(readFile.isDirectory() ? "Yes" : "No");

  // You can seek around inside the file relative to the start of the file.
  // For example to skip back to the start (position 0):
  if (!readFile.seek(0)) {
    Serial.println("Error, failed to seek back to start of file!");
    while(1);
  }

  // And finally to read all the data and print it out a character at a time
  // (stopping when end of file is reached):
  Serial.println("Entire contents of job.fs:");
  while (readFile.available()) {
    char c = readFile.read();
    Serial.print(c);
  }

  // Close the file when finished reading.
  readFile.close();
}
#endif // 15 Jan 2018
#endif

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018


#ifndef HAS_STANDARD_BUILD_HERE
void read_from_code_py_file(void) {
    // CURRENT_FILESYSTEM fatfs
  // File readCodeFile = fatfs.open("/main.py", FILE_READ);
  File readCodeFile = CURRENT_FILESYSTEM.open("/main.py", FILE_READ);
  if (!readCodeFile) {
    Serial.println("Error, failed to open code.py for reading!");
    while(1);
  }

  // Read a line of data:
  String line = readCodeFile.readStringUntil('\n');
  Serial.print("First line of code.py: "); Serial.println(line);

  // You can get the current position, remaining data, and total size of the file:
  Serial.print("Total size of code.py (bytes): "); Serial.println(readCodeFile.size(), DEC);
  Serial.print("Current position in code.py: "); Serial.println(readCodeFile.position(), DEC);
  Serial.print("Available data to read in code.py: "); Serial.println(readCodeFile.available(), DEC);

  // And a few other interesting attributes of a file:
  Serial.print("File name: "); Serial.println(readCodeFile.name());
  Serial.print("Is file a directory? "); Serial.println(readCodeFile.isDirectory() ? "Yes" : "No");

  // You can seek around inside the file relative to the start of the file.
  // For example to skip back to the start (position 0):
  if (!readCodeFile.seek(0)) {
    Serial.println("Error, failed to seek back to start of file!");
    while(1);
  }

  // And finally to read all the data and print it out a character at a time
  // (stopping when end of file is reached):
  Serial.println("Entire contents of code.py:");
  while (readCodeFile.available()) {
    char c = readCodeFile.read();
    Serial.print(c);
  }

  // Close the file when finished reading.
  readCodeFile.close();
}
#endif // 15 Jan 2018
#endif























// #EnDiF removed // 15 Jan 2018


#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void tail_code_bb(void) {
  // You can open a directory to list all the children (files and directories).
  // Just like the SD library the File type represents either a file or directory.
#ifndef HAS_STANDARD_BUILD_HERE
    // CURRENT_FILESYSTEM fatfs
  // File testDirRoot = fatfs.open("/");
  File testDirRoot = CURRENT_FILESYSTEM.open("/");
  if (!testDirRoot) {
    Serial.println("Error, failed to open root directory!");
    while(1);
  } else {
    Serial.println("Made it past the opening of the root directory.");
  }
#endif

#ifdef HAS_STANDARD_BUILD_HERE
    // CURRENT_FILESYSTEM fatfs
  File testDir = CURRENT_FILESYSTEM.open("/lib");
  if (!testDir) {
    Serial.println("Error, failed to open test directory!");
    while(1);
  } else {
    Serial.println("Made it past the opening of the /lib directory.");
  }
#endif

#ifndef HAS_STANDARD_BUILD_HERE
  if (!testDirRoot.isDirectory()) {
    Serial.println("Error, expected root to be a directory!");
    while(1);
  } else {
    Serial.println("Good - root is a directory - not a file.  Continue.");
  }
#endif

#ifdef HAS_STANDARD_BUILD_HERE
  if (!testDir.isDirectory()) {
    Serial.println("Error, expected /lib to be a directory!");
    while(1);
  } else {
    Serial.println("Good - /lib is a directory - not a file.  Continue.");
  }
#endif

#ifndef HAS_STANDARD_BUILD_HERE
  Serial.println("Listing children of root directory:");
  File child = testDirRoot.openNextFile();
  while (child) {
    // Print the file name and mention if it's a directory.
    Serial.print("- "); Serial.print(child.name());
    if (child.isDirectory()) {
      Serial.print(" (directory)");
    }
    Serial.println();
    // Keep calling openNextFile to get a new file.
    // When you're done enumerating files an unopened one will
    // be returned (i.e. testing it for true/false like at the
    // top of this while loop will fail).
    child = testDirRoot.openNextFile();
  }

  // If you want to list the files in the directory again call
  // rewindDirectory().  Then openNextFile will start from the
  // top again.
  testDirRoot.rewindDirectory();
#endif


// hold: while(1); Serial.println("WILL ROBINSON.");
         while(1); Serial.println("WILL ROBINSON.");



#ifdef HAS_STANDARD_BUILD_HERE
  Serial.println("Listing children of directory /lib:");
  File child = testDir.openNextFile();
  while (child) {
    // Print the file name and mention if it's a directory.
    Serial.print("- "); Serial.print(child.name());
    if (child.isDirectory()) {
      Serial.print(" (directory)");
    }
    Serial.println();
    // Keep calling openNextFile to get a new file.
    // When you're done enumerating files an unopened one will
    // be returned (i.e. testing it for true/false like at the
    // top of this while loop will fail).
    child = testDir.openNextFile();
  }


  // If you want to list the files in the directory again call
  // rewindDirectory().  Then openNextFile will start from the
  // top again.
  testDir.rewindDirectory();
#endif



#ifdef HAS_EXTRA_STANDARD_BUILD_HERE

  // Delete a file with the remove command.  For example create a test2.txt file
  // inside /test/foo and then delete it.
    // CURRENT_FILESYSTEM fatfs
  // File test2File = fatfs.open("/forth/foo/test2.txt", FILE_WRITE);
  File test2File = CURRENT_FILESYSTEM.open("/forth/foo/test2.txt", FILE_WRITE);
  test2File.close();
  Serial.println("Deleting /forth/foo/test2.txt...");
    // CURRENT_FILESYSTEM fatfs
  if (!CURRENT_FILESYSTEM.remove("/forth/foo/test2.txt")) {
    Serial.println("Error, couldn't delete test.txt file!");
    while(1);
  }
  Serial.println("Deleted file!");

  // Delete a directory with the rmdir command.  Be careful as
  // this will delete EVERYTHING in the directory at all levels!
  // I.e. this is like running a recursive delete, rm -rf, in
  // unix filesystems!
  Serial.println("Deleting /test directory and everything inside it...");
    // CURRENT_FILESYSTEM fatfs
  // if (!fatfs.rmdir("/test")) {
  if (!CURRENT_FILESYSTEM.rmdir("/test")) {
    Serial.println("Error, couldn't delete test directory!");
    while(1);
  }
  // Check that test is really deleted.
    // CURRENT_FILESYSTEM fatfs
  // if (fatfs.exists("/test")) {
  if (CURRENT_FILESYSTEM.exists("/test")) {
    Serial.println("Error, test directory was not deleted!");
    while(1);
  }
  Serial.println("Test directory was deleted!");
  
  Serial.println("Finished!");
#endif

#ifndef HAS_STANDARD_BUILD_HERE
#endif

}
#endif // 15 Jan 2018


































































void ascii_xfer_spi_flash_main(void) {
  // SHOULD NOT BE NEEDED 06 AUG: ascii_xfer_setup_spi_flash();
  // _eflmkdir(); // OLD NAME WAS: create_test_directory();
  // write_a_test_file();
  // read_a_test_file();
  read_from_code_py_file(); 
  tail_code_bb();

}

// void loop_flash_main(void) {
  // Nothing to be done in the main loop.
  // delay(100);
// }

#endif // #ifdef HAS_EXP_MFOUR_QSPI_FLASH - entire file omitted when this flag is set

// END.
