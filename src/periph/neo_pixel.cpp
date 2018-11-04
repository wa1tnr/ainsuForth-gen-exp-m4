// Fri  6 Jul 06:50:19 UTC 2018
// 4737-a3b-017-

// Update for ADAFRUIT_FEATHER_M4_EXPRESS

// Mon 18 Jun 21:39:23 UTC 2018
// 4737-a3a-0f5-

// Mon 18 Jun 05:32:01 UTC 2018
// 4737-a3a-0e7-

// Sun 17 Jun 04:01:59 UTC 2018
// 4737-a3a-0cc-

// removal or mod of PIN 12 for MM4X
// removal of assumption of 8x strip
// this one commit represents Feather M0 Express with working NPX but no external array of NPX.

// Tue 22 May 23:16:53 UTC 2018
// 4737-a3a-05k-

// This version modified to allow onboard NPX on Pin 40 as
// well as a strip of 8x NeoPixels on Pin 12. --22 May 2018

// Sun 13 May 01:18:47 UTC 2018
// 4737-a3a-01a-

// Tue Jan 16 02:30:09 UTC 2018
// 4737-a0d-05j-

// Mon Jan 15 19:19:47 UTC 2018
// 4737-a0d-05d-

// Tue Jul 25 07:27:48 UTC 2017
// 4735-b0a-09-

// Adafruit original header, but this sketch operates only
// the one neopixel on the Feather M0 Express board:

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library


// define a series of words ?rgb such as:
// : rrgb npx 1 1 7 rgb ;  ok
// ... that point to different colors (replace 1 1 7 with another rgb triple)
// ex.
// : srgb npx 7 1 1 rgb ;  ok
// : drgb npx 0 0 0 rgb ;  ok // drgb means dark rgb

// nice blank word:
// : bl npx 0 0 0 rgb ;  ok
// ex.
// 3 bl 4 bl 5 bl ok   blanks neoPixels #3, 4 and 5.

#include <Arduino.h>
#include "../../yaffa.h"

#ifdef HAS_NEO_PIXEL_LIB
#include "neo_pixel.h"
// #include "../../Error_Codes.h"

#include <Adafruit_NeoPixel.h> // REQUIRED: https://github.com/adafruit/Adafruit_NeoPixel


// Which pin on the Arduino is connected to the NeoPixels?
// #define PIN              40 // peculiar to Metro M4 Express.
// #define PIN              40 // peculiar to Metro M0 Express.  Feather M0 Express: PIN 8
// #define PIN               8 // peculiar to Feather M0 Express.  Metro M0 Express: PIN 40
// #define PIN               8 // circuit playground Express


// #ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0

#undef PIN

#ifdef ADAFRUIT_METRO_M4_EXPRESS // #ifdef __SAMD51J19A__
  #define PIN               40 // peculiar to Metro M4 Express.
#endif

#ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0
  #define PIN                8 // peculiar to Circuit Playground Express and Feather M0 Express
#endif

#ifdef ADAFRUIT_FEATHER_M0_EXPRESS
  #define PIN                8 // peculiar to Feather M0 Express
#endif // 15 Jan 2018

#ifdef ADAFRUIT_FEATHER_M4_EXPRESS
  #define PIN                8 // peculiar to Feather M4 Express
#endif // 06 July 2018

#ifdef ADAFRUIT_TRINKET_M0
  #define PIN                1 // arbitrary assignment? Trinket M0
#endif

#ifndef PIN // sieve fall-through clause
  #define PIN              2 // arbitrary assignment to non-specific board
#endif

// #undef PIN     // override 22 May 2018
// #define PIN 12 // override 22 May 2018 - M4X arbitrarily assigned.

#undef PIN     // override 22 May 2018
#define PIN COMMUTED_PIN_NPX // how about them apples

// How many NeoPixels are attached to the Arduino?
// #define NUMPIXELS        10 // circuit playground Express

#undef NUMPIXELS

#ifdef ADAFRUIT_TRELLIS_M4_EXPRESS
  #define NUMPIXELS         32
#endif

#ifdef ADAFRUIT_METRO_M4_EXPRESS
  #define NUMPIXELS          1
#endif

// #ifdef __SAMD51J19A__
//  #define NUMPIXELS          1 // Metro M4 Express
// #endif

#ifdef ADAFRUIT_ITSYBITSY_M0
  #define NUMPIXELS          1 // Crickit CPX - pretend itsybitsym0
#endif

#ifdef ADAFRUIT_METRO_M0_EXPRESS
  #define NUMPIXELS          1 // Metro M0 Express
#endif

#ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0
  #define NUMPIXELS         10 // Circuit Playground Express
#endif

#ifdef ADAFRUIT_FEATHER_M0_EXPRESS
#define NUMPIXELS            1 // Not zero - some other define can remove this code entirely
#endif // 15 Jan 2018

// local condition: NeoPixel 8 strip connected to Trinket M0:
#ifdef ADAFRUIT_TRINKET_M0
  #define NUMPIXELS          8 // NeoPixel strip 8x
#endif


#ifndef NUMPIXELS          // sieve fall-through clause
  #define NUMPIXELS     1 // other Adafruit SAMD21 boards
#endif                     // Not zero - some other define can remove this code entirely

// #undef NUMPIXELS    // 22 may override
// #define NUMPIXELS 8 // 22 may override

// When we setup the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.

// #undef PIN
// #undef NUMPIXELS

// #define PIN 8 // desperate override Mon 18 June 04:06z
// #define NUMPIXELS     1 // other Adafruit SAMD21 boards

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// might be a memory hog; this is for the legacy onboard NeoPixel, only:
// Adafruit_NeoPixel pix40 =  Adafruit_NeoPixel(1, 40, NEO_GRB + NEO_KHZ800);

int delayval = 300;
int delaySval = 110;

int neoPixelNumber = 0; // zero is a legal value and names the first pixel in the string

// void setup_neoPix40(void) { // for the legacy onboard NeoPixel only
  // pix40.begin();
  // the whole purpose of providing for the onboard NPX  is to recolor it:
  // pix40.setPixelColor(0, 0, 1, 1); pix40.show();
// }

void setup_neoPixel(void) {
  // DEBUG 04:08z 18 June - comment out two lines:
  pixels.begin(); // This initializes the NeoPixel library.
  // setup_neoPix40();
}


/* test

: magentaDull  14 0 14 rgb ;
: cyanDull 0 14 14 rgb ;
: greenBright 0 100 0 rgb ;

: ldelay 3000 delay ;
: red 75 0 0 rgb ;
: magenta  35 0 35 rgb ;
: cyan 0 19 19 rgb ;
: green 0 44 0 rgb ;
: blue 0 0 254 rgb ;
: orange 155 11 0 rgb ;
: yellow 75 35 0 rgb ;
: colours red ldelay green ldelay blue ldelay orange ldelay cyan ldelay magenta ldelay ;

: strobeonce pixel 2000 delay ;
: strobe strobeonce strobeonce strobeonce strobeonce ;

 */

// a typical stack effect diagram: ( TOS-2  TOS-1  TOS -- )

void _rgbp(void) { // ( n3 n2 n1 -- n1 n2 n3 )
    _rot();
    _rot();
    _swap();
}

const char npx_str[] = "npx"; // local idiom ainsuForth - select which neopixel in a string of them
void _npx(void) { // ( pixel_number_in_string -- )
  neoPixelNumber = dStack_pop(); // set a global to TOS, destructively
}

const char npx_fetch_str[] = "npx@"; // local idiom ainsuForth - fetch the npx number
void _npx_fetch(void) { // ( -- npx_number )
  dStack_push(neoPixelNumber);
}


const char rgb_str[] = "rgb"; // local idiom ainsuForth

void _rgb(void) { // ( red green blue -- )
    int i = 0; // this may be the neoPixel 'number' on a string of neoPixels
    _rgbp();

    // debug: suppy stack values

    //   dStack_push(0); // blue
    //   dStack_push(150); // green
    //   dStack_push(0); // red

    _npx_fetch();

    // 22 may // pixels.setPixelColor(dStack_pop(), pixels.Color(dStack_pop(), dStack_pop(), dStack_pop()));
    pixels.setPixelColor(dStack_pop(), pixels.Color(dStack_pop(), dStack_pop(), dStack_pop()));
    // 22 may // int ji = dStack_pop(); pixels.setPixelColor(3, pixels.Color(dStack_pop(), dStack_pop(), dStack_pop()));
    pixels.show();
}


void _darkNPX(void) { // darken the neoPixel
  dStack_push(0);
  dStack_push(0);
  dStack_push(0);
  _rgb();
}


void _cyan(void) {
    dStack_push(0);   // red
    dStack_push(1);  // green
    dStack_push(1);  // blue
    _rgb();
}

void _orange(void) {
    dStack_push(155); // red
    dStack_push(11);  // green
    dStack_push(0);   // blue
    _rgb();
}


void _blue(void) {
    dStack_push(0);   // red
    dStack_push(0);   // green
    dStack_push(254); // blue
    _rgb();
}

void _dullMagenta(void) {
    dStack_push(1);   // red
    dStack_push(0);   // green
    dStack_push(1);   // blue
    _rgb();
}

void neoPixel(void) { // ainsuForth: invoke using the 'pixel' word
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){ // i=0 originally

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(1,0,0)); // Red
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).

    pixels.setPixelColor(i, pixels.Color(0,1,0)); // Green
    pixels.show();
    delay(delayval);

    pixels.setPixelColor(i, pixels.Color(0,0,1)); // Blue
    pixels.show();
    delay(delayval);



    _orange();
    delay(delaySval);

    _blue();
    delay(delaySval);

    _orange();
    delay(delaySval);

    _blue();
    delay(delaySval);
    _cyan();

  }
}

const char pixel_str[] = "pixel"; // local idiom ainsuForth
void _pixel(void) {
    neoPixel();
    // _darkNPX();
}

#endif
