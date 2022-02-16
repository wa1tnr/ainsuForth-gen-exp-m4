#ifdef HAS_EXP_MFOUR_QSPI_FLASH
    #define CURRENT_FILESYSTEM fatfs
    #define SPI_FlashROM_FILENAME "/forth/ascii_xfer_a001.txt"
    #define SPI_FlashROM_TOPDIR   "/forth"
    #include <Arduino.h>
    #include "../yaffa.h"
    #ifdef EXT_KERN_GETLINE
        #include "getline.h"
        #ifdef HAS_QSPI_FLASHROM_LIB
            #warning HAS_QSPI_FLASHROM_LIB includes extra code on line 10 __getline_m4_exp.cpp__
            #define FLASH_DEVICE_GD25Q
            #ifdef FLASH_DEVICE_GD25Q
                #include <SPI.h>
                #include <SdFat.h>
                #include <Adafruit_SPIFlash.h>
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
                FatFileSystem fatfs;
                File myFile;
                #define WORKING_DIR "/forth"
            #endif
        #endif
    #endif
#endif

#ifdef HAS_EXP_MFOUR_QSPI_FLASH
    #ifdef EXT_KERN_GETLINE
        #ifdef HAS_QSPI_FLASHROM_LIB

/******************************************************************************/
/** getDLKey                                                                 **/
/******************************************************************************/
















void setup_qspiFlashROM(void) { // void setup_spi_flash(void) {
    Serial.print("Hello from setup_qspi m4 getline stuff.   ");
    if (!flash.begin()) { // if (!flash.begin(FLASH_TYPE)) {
        Serial.println("E: could not find flash on QSPI bus.");
        while(1);
    }
    Serial.println("Found QSPI Flash.");
    if (!CURRENT_FILESYSTEM.begin(&flash)) {
        Serial.println("Failed to mount filesystem!");
        Serial.println("Was CircuitPython loaded on the board first to create the filesystem?");
        while(1);
    }
    Serial.println("FEB 2022: Mounted filesystem!");
}











            #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
                File thisFile;
            #endif // 15 Jan 2018

/******************************************************************************/
/** getLine                                                                  **/
/******************************************************************************/









uint8_t getLine(char* ptr, uint8_t buffSize) {
    char inChar;
    uint8_t count = 0;
            #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
    if (spiFlashReading) {
        if (CURRENT_FILESYSTEM.exists(SPI_FlashROM_FILENAME)) {
            if (fileClosed) {
                File bootPy = CURRENT_FILESYSTEM.open(SPI_FlashROM_FILENAME, FILE_READ);
                thisFile = (File) bootPy;
                fileClosed = FALSE ; // it is open, now.
            }
        }
    }
            #endif // 15 Jan 2018
    do {
            #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
        if (spiFlashReading) {
            if (thisFile) {
                if (thisFile.available()) {
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
                if (inChar == '\\') { }
            } else {
                inChar = getKey(); 
            }
            #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
        }
            #endif // 15 Jan 2018
        if (inChar == ASCII_BS || inChar == ASCII_DEL) {  // new: was only ASCII_BS
            if (count) {
                *--ptr = 0;
                count--; // ainsuForth improvement -- backspace behavior
                if (silentReading) { } else {
                    if (flags & ECHO_ON) Serial.print("\b \b");
                }
            }
        } else if (inChar == ASCII_TAB || inChar == ASCII_ESC) {
            if (silentReading) { } else {
                if (flags & ECHO_ON) Serial.print("\a");
            }
        } else if (inChar == ASCII_CR || inChar == ASCII_NL) { // ainsuForth improvement
            if (silentReading) { // the 'load' word
            } else {
                if (flags & ECHO_ON) Serial.print(" "); // seems to want a space after 'dot' for example.
            }
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
                    if (silentReading) {
                    } else {
                        // main forth interpreter typing echo is right here:
                        Serial.print(inChar); // do NOT suppress this ordinarily, if ever.
                    }
                }
            }
            *ptr++ = inChar;
            *ptr = 0;
            count++;
        }
    } while (count < buffSize);
    return (count);
}













        #endif // #ifdef HAS_QSPI_FLASHROM_LIB
    #endif // #ifdef EXT_KERN_GETLINE



    #ifdef EXT_KERN_GETKEY

/******************************************************************************/
/** getKey                                                                   **/
/******************************************************************************/

















char getKey(void) {
    char inChar;
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

const char eflmkdir_str[] = "eflmkdir"; // forth vocabulary external flash mkdir













void _eflmkdir(void) {
    #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
    if (!CURRENT_FILESYSTEM.exists(SPI_FlashROM_TOPDIR)) {
        Serial.println("/forth directory not found, creating...");
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
    if (!CURRENT_FILESYSTEM.remove(SPI_FlashROM_FILENAME)) {
        Serial.print("Error, file ");
        Serial.print(SPI_FlashROM_FILENAME);
        Serial.println(" was not removed!");
        while(1);
    }
    Serial.println("Deleted file!");
    File writeFile = CURRENT_FILESYSTEM.open(SPI_FlashROM_FILENAME, FILE_WRITE);
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
    File writeFile = CURRENT_FILESYSTEM.open(SPI_FlashROM_FILENAME, FILE_WRITE);
    if (!writeFile) {
        Serial.print("Error, failed to open ");
        Serial.print(SPI_FlashROM_FILENAME);
        Serial.println(" for writing!");
        while(1);
    }
    writeFile.println(cpSource);
    writeFile.close();
}

    #endif // 15 Jan 2018
#endif // #ifdef HAS_EXP_MFOUR_QSPI_FLASH - entire file omitted when this flag is set
// END.
