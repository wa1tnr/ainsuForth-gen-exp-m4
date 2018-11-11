#ifndef HAS_TARGET_SENSED_INCLUSION
    #define HAS_TARGET_SENSED_INCLUSION
    #ifdef WANT_FLAG_REPORTS
        #warning SOURCE_target_sensed.cpp BEGINS

        #ifdef QSPI_FLASHROM_PRESENT
            #warning WFLAG: QSPI_FLASHROM_PRESENT  is defined
        #endif

        #ifndef QSPI_FLASHROM_PRESENT
            #warning WFLAG: QSPI_FLASHROM_PRESENT  is UNDEFINED
        #endif

        #ifdef HAS_QSPI_FLASH_DEMO
            #warning HAS_QSPI_FLASH_DEMO is defined
        #endif

        #ifndef HAS_QSPI_FLASH_DEMO
            #warning HAS_QSPI_FLASH_DEMO is UNDEFINED
        #endif

        #ifdef HAS_SPI_FLASH_DEMO
            #warning WFLAG: HAS_SPI_FLASH_DEMO is defined
        #endif

        #ifndef HAS_SPI_FLASH_DEMO
            #warning WFLAG: HAS_SPI_FLASH_DEMO is UNDEFINED
        #endif

        #ifdef COMMUTED_PIN_NPX
            #warning WFLAG: COMMUTED_PIN_NPX is defined
        #endif

        #ifndef COMMUTED_PIN_NPX
            #warning WFLAG: COMMUTED_PIN_NPX is UNDEFINED
        #endif

        #ifdef LEDX
            #warning WFLAG: LEDX is defined
        #endif

        #ifndef LEDX
            #warning WFLAG: LEDX is UNDEFINED
        #endif

        #ifdef NEO_PIXEL_LIB_ENABLED
            #warning WFLAG: NEO_PIXEL_LIB_ENABLED is defined
        #endif

        #ifndef NEO_PIXEL_LIB_ENABLED
            #warning WFLAG: NEO_PIXEL_LIB_ENABLED is UNDEFINED
        #endif

        #ifdef HAS_NEO_PIXEL_LIB
            #warning WFLAG: HAS_NEO_PIXEL_LIB is defined
        #endif

        #ifndef HAS_NEO_PIXEL_LIB
            #warning WFLAG: HAS_NEO_PIXEL_LIB is UNDEFINED
        #endif

        #ifdef ADAFRUIT_FEATHER_M0_EXPRESS
            #warning WFLAG: ADAFRUIT_FEATHER_M0_EXPRESS
        #endif

        #ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0
            #warning WFLAG: ADAFRUIT_CIRCUITPLAYGROUND_M0
        #endif

        #ifdef ADAFRUIT_METRO_M0_EXPRESS
            #warning WFLAG: ADAFRUIT_METRO_M0_EXPRESS
        #endif

        #ifdef ADAFRUIT_ITSYBITSY_M0
            #warning WFLAG: ADAFRUIT_ITSYBITSY_M0
        #endif

        #ifdef ADAFRUIT_GEMMA_M0
            #warning WFLAG: ADAFRUIT_GEMMA_M0
        #endif

        #ifdef ADAFRUIT_TRINKET_M0
            #warning WFLAG: ADAFRUIT_TRINKET_M0
        #endif

        #ifdef ADAFRUIT_METRO_M4_EXPRESS
            #warning WFLAG: ADAFRUIT_METRO_M4_EXPRESS
        #endif

        #ifdef ADAFRUIT_FEATHER_M4_EXPRESS
            #warning WFLAG: ADAFRUIT_FEATHER_M4_EXPRESS
        #endif

        #ifdef ADAFRUIT_TRELLIS_M4_EXPRESS
            #warning WFLAG: ADAFRUIT_TRELLIS_M4_EXPRESS
        #endif

        #ifdef ADAFRUIT_ITSYBITSY_M4_EXPRESS
            #warning WFLAG: ADAFRUIT_ITSYBITSY_M4_EXPRESS
        #endif

        #ifdef DOTSTAR_LIB_ENABLED
            #warning WFLAG: DOTSTAR_LIB_ENABLED is defined
        #endif

        #ifndef DOTSTAR_LIB_ENABLED
            #warning WFLAG: DOTSTAR_LIB_ENABLED is UNDEFINED
        #endif

        #ifdef HAS_DOTSTAR_LIB
            #warning WFLAG: HAS_DOTSTAR_LIB is defined
        #endif

        #ifndef HAS_DOTSTAR_LIB
            #warning WFLAG: HAS_DOTSTAR_LIB is UNDEFINED
        #endif
    #endif // #ifdef WANT_FLAG_REPORTS
#endif // #define HAS_TARGET_SENSED_INCLUSION
// END.
