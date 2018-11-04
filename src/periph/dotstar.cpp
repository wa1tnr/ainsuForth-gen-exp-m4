// Mon 18 Jun 05:32:01 UTC 2018
// 4737-a3a-0e7-

// Tue 12 Jun 23:47:23 UTC 2018
// 4737-a3a-09b-

// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// version bump

// Sat Jul 29 18:14:02 UTC 2017
// 4735-b0b-01-


// very experimental - 18 June:
#include <Arduino.h>
#include "../../yaffa.h"

#ifdef HAS_DOTSTAR_LIB
#include "dotstar.h"
// #include "../../Error_Codes.h"

#include <Adafruit_DotStar.h>

#define NUMPIXELS 1 // Number of LEDs in strip



#ifdef ADAFRUIT_GEMMA_M0

  #undef DATAPIN
  #undef CLOCKPIN

  #define DATAPIN    3
  #define CLOCKPIN   4

#endif // #ifdef ADAFRUIT_GEMMA_M0



#ifdef ADAFRUIT_TRINKET_M0

  #undef DATAPIN
  #undef CLOCKPIN

  #define DATAPIN  7
  #define CLOCKPIN 8

#endif // #ifdef ADAFRUIT_TRINKET_M0


#ifdef ADAFRUIT_METRO_M4_EXPRESS // ignore -- we are NeoPixel on Metro M4 Express

  // #undef DATAPIN
  // #undef CLOCKPIN

  // #define DATAPIN    8
  // #define CLOCKPIN   6

#endif // #ifdef ADAFRUIT_METRO_M4_EXPRESS


// ItsyBitsyM4: clock D6 data D8 per variant.cpp
#ifdef ADAFRUIT_ITSYBITSY_M4_EXPRESS

  #undef DATAPIN
  #undef CLOCKPIN

  #define DATAPIN    8
  #define CLOCKPIN   6

#endif // big kludge 13 June 2018 - compatibility.h should signal for this toggle

// Trellis M4: clock D11 data D12 per variant.cpp .. sort of
#ifdef ADAFRUIT_TRELLIS_M4_EXPRESS

  #undef DATAPIN
  #undef CLOCKPIN

/* works on 04 November on a Trellis M4 shipped on 01 Nov 2018 */
  #define CLOCKPIN   37
  #define DATAPIN    38

/*
  #define CLOCKPIN   11
  #define DATAPIN    12

PB02 is D37 and is the dotstar clock   PB03 is its data

 91   // 36 - SWDIO
 92   { PORTA, 31, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT
 93
 94   // Unused
 95   { PORTB,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2
 96   { PORTB,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3
*/


#endif


Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

void setup_dotstar() {
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

int      head  = 0, tail = -3;  // Index of first 'on' and 'off' pixels

// DEBUG 13 June 2018: make the color a bit stronger
// uint32_t color = 0x010000;      // 'On' color (starts red)
   uint32_t color = 0x500000;      // 'On' color (starts red)

void loop_dotstar() {

  // DEBUG: new stanza
  strip.setPixelColor(0, 0x000000); // turn it off
  strip.show();                     // Refresh strip
  delay(200);
  // end debug stanza

  strip.setPixelColor(head, color); // 'On' pixel at head
  strip.setPixelColor(tail, 0);     // 'Off' pixel at tail

  strip.show();                     // Refresh strip
  delay(20);                        // Pause 20 milliseconds (~50 FPS)

// DEBUG 13 June 2018: we are M4 and are much faster!  Must extend our timeout:
  delay(900);                        // Pause 20 milliseconds (~50 FPS)

// DEBUG 04 Nov  2018: Trellis M4 (still no help - pin assignments probably wrong)
// delay(900);                        // Pause 20 milliseconds (~50 FPS)

  if(++head >= NUMPIXELS) {         // Increment head index.  Off end of strip?
    head = 0;                       //  Yes, reset head index to start
    if((color >>= 8) == 0)          //  Next color (R->G->B) ... past blue now?
      color = 0x010000;             //   Yes, reset to red
  }
  if(++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index

Serial.println("\r\nWent off tail.  Bye from dotstar.");

}

#endif

// END
