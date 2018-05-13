// Wed Jun 28 17:53:29 UTC 2017
// 4735-a0s-01-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#include "cblink.h"
#include "../periph/neo_pixel.h"
/*******************************************************************************/
/**                                                                          **/
/*******************************************************************************/
const char cblink_str[] = "cblink";
// ( -- )
// Blink the NeoPixel.
void _cblink(void) {
#ifdef HAS_NEO_PIXEL_LIB
  _cyan();
  delay(300);
  _darkNPX();
#endif
}


// Blink the NeoPixel.
void _mblink(void) {
#ifdef HAS_NEO_PIXEL_LIB
  // _cyan();
  // _dullMagenta();
  _dullMagenta();
  delay(100);
  _darkNPX();
#endif
}


/******************************************************************************/
/**                                                                          **/
/******************************************************************************/
