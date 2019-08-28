#ifdef HAS_EXP_MFOUR_QSPI_FLASH

    #define SPI_FlashROM_FILENAME "/forth/ascii_xfer_a001.txt"
    #define SPI_FlashROM_TOPDIR   "/forth"

    #include <Arduino.h> // LINE 59
    #include "../../yaffa.h" // LINE 60

    #ifdef EXT_KERN_GETLINE
        #include "getline.h" // this is the flag wanted: HAS_QSPI_FLASHROM_LIB
        #ifdef HAS_QSPI_FLASHROM_LIB // 11 Nov 2018 // NEW LINE 64
            #warning HAS_QSPI_FLASHROM_LIB includes extra code on line 65 __getline_m4_exp.cpp__ // 11 Nov 2018 - NEW LINE 66
            #define FLASH_DEVICE_GD25Q
            #ifdef FLASH_DEVICE_GD25Q

// flash_ops.cpp  wa1tnr
// Wed Aug 21 02:15:00 UTC 2019 0.1.8 good-compiler-aa-bb  shred: abn-515

                #include <SPI.h>
                // #include "SdFat.h"
                #include <SdFat.h>
                // #include "Adafruit_SPIFlash.h"
                #include <Adafruit_SPIFlash.h> // NEW LINE 68

                // done below but could go here as well // File thisFile;
                // #include "../common.h"

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


 // RESCIND //  #include <Adafruit_SPIFlash_FatFs.h> // NEW LINE 69
 // RESCIND //  #include "Adafruit_QSPI_GD25Q.h"
 // RESCIND //  #define FLASH_TYPE     SPIFLASHTYPE_W25Q16BV  // Flash chip type. // NEW LINE 71
 
 // RESCIND //  Adafruit_QSPI_GD25Q flash;
 // RESCIND //  Adafruit_M0_Express_CircuitPython pythonfs(flash);


// LINE 77
// LINE 100
// LINE 108
// ------------------------ this was SPI   not    SPI1   ------ when did this change?
// LINE 110

#endif // 15 Jan 2018

/******************************************************************************/
/** getDLKey                                                                 **/
/**   waits for the next valid key to be entered in download mode (DL)       **/
/**   and return its value                                                   **/
/**   Watches for code-escape key '\' (backslash) to detect the '\end.' word **/
/**   Valid characters are:  Backspace, Carriage Return (0x0d), Escape,      **/
/**   Tab, Newline (0x0a) and standard (printable) characters                **/
/******************************************************************************/







void setup_qspiFlashROM(void) { // void setup_spi_flash(void) {
    Serial.print("Hello from setup_qspi m4 getline stuff.   ");

/*

 68   flash.begin();
 69 
 70   // Init file system on the flash
 71   fatfs.begin(&flash);

*/
    if (!flash.begin()) { // if (!flash.begin(FLASH_TYPE)) {
        Serial.println("E: could not find flash on QSPI bus.");
        while(1);
    }
    Serial.println("Found QSPI Flash using new libs in August 2019");
    // RESCIND? // flash.setFlashType(FLASH_TYPE); // new November 9 2018
    // if (!fatfs.begin()) { //  if (!fatfs.begin()) {
    if    (!fatfs.begin(&flash)) {
        Serial.println("Failed to mount filesystem!");
        Serial.println("Was CircuitPython loaded on the board first to create the filesystem?");
        while(1);
    }
    Serial.println("AUG 2019: Mounted filesystem!");
}




/******************************************************************************/
/** getLine                                                                  **/
/**   read in a line of text ended by a Carriage Return (ASCII 13)           **/
/**   Valid characters are:  Backspace, Carriage Return, Escape, Tab, and    **/
/**   standard printable characters. Passed the address to store the string, **/
/**   and Returns the length of the string stored                            **/
/******************************************************************************/

// was protected by the '#ifdef HAS_QSPI_FLASH_DEMO'
        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
File thisFile;
        #endif // 15 Jan 2018
        // #directive

uint8_t getLine(char* ptr, uint8_t buffSize) {
  char inChar;
  uint8_t count = 0;



        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
  if (spiFlashReading) {


// UNIVERSAL USE ###bookmark
//  34   if (!fatfs.exists(WORKING_DIR)) {

      if (fatfs.exists(SPI_FlashROM_FILENAME)) {
          if (fileClosed) {
            File bootPy = fatfs.open(SPI_FlashROM_FILENAME, FILE_READ);
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

// -----------------------------------------------------
// -----------------------------------------------------

      if (silentReading) { // the 'load' word
      } else {
              if (flags & ECHO_ON) Serial.print(" "); // seems to want a space after 'dot' for example.
      }
// -----------------------------------------------------

      if (spiFlashWaiting) {
      } else { 
          silentReading = FALSE; // we are interactive once more, when spiFlashWaiting changes state
      }

      break;

    } else {

      if (silentReading && spiFlashReading) { // the 'load' word
          int fakeSPxT = 0;
      } else {
          if (flags & ECHO_ON) {
// -----------------------------------------------------
if (silentReading) {
} else {
              // main forth interpreter typing echo is right here:
              Serial.print(inChar); // do NOT suppress this ordinarily, if ever.
}
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

const char eflmkdir_str[] = "eflmkdir"; // forth vocabulary external flash mkdir
// void create_test_directory(void) {
void _eflmkdir(void) {

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018

  if (!fatfs.exists(SPI_FlashROM_TOPDIR)) {
    Serial.println("/forth directory not found, creating...");
    if (!fatfs.mkdir(SPI_FlashROM_TOPDIR)) {
      Serial.println("Error, failed to create test directory!");
      while(1);
    }
    Serial.println("Created /forth directory!");
  }
#endif




#ifdef NEVER_DEFINED_TEN_THREE // nonsense tag to prevent compile
#ifndef HAS_STANDARD_BUILD_HERE

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
  if (!fatfs.exists(SPI_FlashROM_TOPDIR)) {
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

  if (!fatfs.remove(SPI_FlashROM_FILENAME)) {
      Serial.print("Error, file ");
      Serial.print(SPI_FlashROM_FILENAME);
      Serial.println(" was not removed!");
      while(1);
  }
  Serial.println("Deleted file!");
  File writeFile = fatfs.open(SPI_FlashROM_FILENAME, FILE_WRITE);

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
  writeFile.close(); // housekeeping.
  }
}
#endif // 15 Jan 2018

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void write_a_capture_file(void) {
  File writeFile =               fatfs.open(SPI_FlashROM_FILENAME, FILE_WRITE);
  if (!writeFile) {
    Serial.print("Error, failed to open ");
    Serial.print(SPI_FlashROM_FILENAME);
    Serial.println(" for writing!");
    while(1);
  }
  writeFile.println(cpSource);

  // Close the file when finished writing.
  writeFile.close();
}
#endif // 15 Jan 2018


#ifndef HAS_STANDARD_BUILD_HERE

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void read_a_test_file(void) {
  File readFile = fatfs.open(SPI_FlashROM_FILENAME, FILE_READ);
  if (!readFile) {
    Serial.print("Error, failed to open ");
    Serial.print(SPI_FlashROM_FILENAME);
    Serial.println(" for reading!");
    while(1);
  }
  String line = readFile.readStringUntil('\n');
  Serial.print("First line of ");
  Serial.print(SPI_FlashROM_FILENAME);
  Serial.println(line);
  Serial.print("Ignore job.fs and say ");
  Serial.print(SPI_FlashROM_FILENAME);
  Serial.print(" here - several lines.");
  Serial.print("Total size of job.fs (bytes): "); Serial.println(readFile.size(), DEC);
  Serial.print("Current position in job.fs: "); Serial.println(readFile.position(), DEC);
  Serial.print("Available data to read in job.fs: "); Serial.println(readFile.available(), DEC);

  Serial.print("File name: "); Serial.println(readFile.name());
  Serial.print("Is file a directory? "); Serial.println(readFile.isDirectory() ? "Yes" : "No");

  if (!readFile.seek(0)) {
    Serial.println("Error, failed to seek back to start of file!");
    while(1);
  }

  Serial.println("Entire contents of job.fs:");
  while (readFile.available()) {
    char c = readFile.read();
    Serial.print(c);
  }

  readFile.close();
}
#endif // 15 Jan 2018
#endif

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018


#ifndef HAS_STANDARD_BUILD_HERE
void read_from_code_py_file(void) {
  File readCodeFile = fatfs.open("/main.py", FILE_READ);
  if (!readCodeFile) {
    Serial.println("Error, failed to open code.py for reading!");
    while(1);
  }

  String line = readCodeFile.readStringUntil('\n');
  Serial.print("First line of code.py: "); Serial.println(line);

  Serial.print("Total size of code.py (bytes): "); Serial.println(readCodeFile.size(), DEC);
  Serial.print("Current position in code.py: "); Serial.println(readCodeFile.position(), DEC);
  Serial.print("Available data to read in code.py: "); Serial.println(readCodeFile.available(), DEC);

  Serial.print("File name: "); Serial.println(readCodeFile.name());
  Serial.print("Is file a directory? "); Serial.println(readCodeFile.isDirectory() ? "Yes" : "No");

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























// #endif // 15 Jan 2018


#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void tail_code_bb(void) {
  // You can open a directory to list all the children (files and directories).
  // Just like the SD library the File type represents either a file or directory.
#ifndef HAS_STANDARD_BUILD_HERE
    // pythonfs fatfs
  // File testDirRoot = fatfs.open("/");
  File testDirRoot = fatfs.open("/");
  if (!testDirRoot) {
    Serial.println("Error, failed to open root directory!");
    while(1);
  } else {
    Serial.println("Made it past the opening of the root directory.");
  }
#endif

#ifdef HAS_STANDARD_BUILD_HERE
    // pythonfs fatfs
  File testDir = fatfs.open("/lib");
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
    // pythonfs fatfs
  // File test2File = fatfs.open("/forth/foo/test2.txt", FILE_WRITE);
  File test2File = fatfs.open("/forth/foo/test2.txt", FILE_WRITE);
  test2File.close();
  Serial.println("Deleting /forth/foo/test2.txt...");
    // pythonfs fatfs
  if (!fatfs.remove("/forth/foo/test2.txt")) {
    Serial.println("Error, couldn't delete test.txt file!");
    while(1);
  }
  Serial.println("Deleted file!");

  // Delete a directory with the rmdir command.  Be careful as
  // this will delete EVERYTHING in the directory at all levels!
  // I.e. this is like running a recursive delete, rm -rf, in
  // unix filesystems!
  Serial.println("Deleting /test directory and everything inside it...");
    // pythonfs fatfs
  // if (!fatfs.rmdir("/test")) {
  if (!fatfs.rmdir("/test")) {
    Serial.println("Error, couldn't delete test directory!");
    while(1);
  }
  // Check that test is really deleted.
    // pythonfs fatfs
  // if (fatfs.exists("/test")) {
  if (fatfs.exists("/test")) {
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
