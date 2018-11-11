// see:

// http://forum.arduino.cc/index.php?topic=134226.0
#define WANT_FLAG_REPORTS
#include "target_sensed.cpp"

#if defined (ADAFRUIT_FEATHER_M0_EXPRESS) | (ADAFRUIT_METRO_M0_EXPRESS) | (ADAFRUIT_CIRCUITPLAYGROUND_M0) | (ADAFRUIT_ITSYBITSY_M0)
    #define ANY_M0_EXPRESS_TARGET
#endif

#if defined ANY_M0_EXPRESS_TARGET
    #ifndef HAS_EXP_MZERO_SPI_FLASH
        #define HAS_EXP_MZERO_SPI_FLASH
            #warning INCLUDING_GETLINE_MZERO_EXP_CPP here
            #include "getline_m0_exp.cpp"
    #endif
#endif // #if defined (ADAFRUIT_FEATHER_M0_EXPRESS) | (ADAFRUIT_METRO_M0_EXPRESS) | (ADAFRUIT_CIRCUITPLAYGROUND_M0) | (ADAFRUIT_ITSYBITSY_M0)

#if defined (ADAFRUIT_METRO_M4_EXPRESS) | (ADAFRUIT_TRELLIS_M4_EXPRESS) | (ADAFRUIT_ITSYBITSY_M4_EXPRESS) | (ADAFRUIT_FEATHER_M4_EXPRESS)
    #define ANY_M4_EXPRESS_TARGET
#endif

#if defined ANY_M4_EXPRESS_TARGET
    #ifndef HAS_EXP_MFOUR_QSPI_FLASH
        #define HAS_EXP_MFOUR_QSPI_FLASH
            #warning INCLUDING_GETLINE_MFOUR_EXP_CPP here
            #include "getline_m4_exp.cpp"
    #endif
#endif // #if defined (ADAFRUIT_METRO_M4_EXPRESS) | (ADAFRUIT_TRELLIS_M4_EXPRESS) | (ADAFRUIT_ITSYBITSY_M4_EXPRESS) | (ADAFRUIT_FEATHER_M4_EXPRESS)

#ifdef DEBUG_GETLINE_TESTS
    #undef __TESTING_SEVEN
    #define __TESTING_SEVEN

    #ifdef __TESTING_SEVEN
        #warning __TESTING_SEVEN defined in test.cpp
    #else
        #warning __TESTING_SEVEN UNdefined in test.cpp
    #endif
#endif // #ifdef DEBUG_GETLINE_TESTS
