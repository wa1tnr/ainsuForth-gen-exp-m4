// Mon Jan 15 19:19:47 UTC 2018
// 4737-a0d-05d-

// previous timestamp:
// Wed Aug  2 01:22:51 UTC 2017
// 4735-b0c-03-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_SIGN_ON
#include "signon.h"
/******************************************************************************/
/** signOn - say Hello to the user interface via USB serial port             **/
/******************************************************************************/
void signOn(void) {
  // Serial.begin(19200);     // Open serial communications:

  // Serial.print("\n warm boot message - early bird."); // instant confirmation

  // delay(9 * 100);

  // colours - entirely optional
  Serial.print("\033\133"); // ESC [
  Serial.print("\063\063"); // 33 - yellow fg
  Serial.print("m");        // for the stanza

  Serial.print("\033\133"); // ESC [
  Serial.print("\064\064"); // 44 - blue bg
  Serial.print("m");        // for the stanza

// 203   Serial.print("\033\133"); // ESC [
// 204 
// 205   Serial.print("\063\063"); // 33 - yellow fg
// 206   Serial.print("m");        // for the stanza
// 207 
// 208   Serial.print("\033\133"); // ESC [
// 209 
// 210   Serial.print("\064\064"); // 44 - blue bg
// 211   Serial.print("m");        // for the stanza

  // Serial.print("\n YAFFA - Yet Another Forth For Arduino, ");

//  Serial.print("Version ");
//  Serial.print(YAFFA_MAJOR,DEC);
//  Serial.print(".");
//  Serial.println(YAFFA_MINOR,DEC);

    Serial.print("\033\133"); // ESC [
    Serial.print("\064\060"); // 40 - black bg
    Serial.print("m");        // for the stanza

    Serial.print("\r\n\r\n   ");  // leading black space on the wa1tnr line

    Serial.print("\033\133"); // ESC [
    Serial.print("\064\064"); // 44 - blue bg
    Serial.print("m");        // for the stanza

    Serial.print("  ainsuForth - 2018 - wa1tnr  ");

    Serial.print("\033\133"); // ESC [
    Serial.print("\064\060"); // 40 - black bg
    Serial.print("m");        // for the stanza
    Serial.print("  words: ");
    pFlashEntry = flashDict;
    w = 0;
    while (pFlashEntry->name) { // Good for the Zero
      w++;
      pFlashEntry++;
    }
    Serial.print(w);


    Serial.print("  \r\n         YAFFA - Yet Another Forth For Arduino, \r\n");

    Serial.print("         Copyright (C) 2012 Stuart Wood\r\n");

//  Serial.print(" This program comes with ABSOLUTELY NO WARRANTY.\r\n");
//  Serial.print(" This is free software, and you are welcome to\r\n");
//  Serial.println(" redistribute it under certain conditions.\r\n");
  
//  Serial.print(" Processor is a ");
//  Serial.println(PROC_STR);
//  Serial.print(" Terminal Echo is ");
//  Serial.print(flags & ECHO_ON ? "On\r\n" : "Off\r\n");
//  Serial.print(" Pre-Defined Words : ");


//  Serial.println("\r\n Environment Parameters: ");
//  Serial.print(" Counted String Length: \t");
//  Serial.print(BUFFER_SIZE);
//  Serial.println(" Bytes");
//  Serial.print(" Pict. Num. Output Length: \t");
//  Serial.print(HOLD_SIZE);
//  Serial.println(" Bytes");
//  Serial.print(" Scratch Pad size: \t\t");
//  Serial.print(PAD_SIZE);
//  Serial.println(" Bytes");
//  Serial.print(" Address Size: \t\t\t");
//  Serial.print(sizeof(void*) * 8);
//  Serial.println(" Bits");
//  Serial.print(" Core Word set: \t\t");
//  Serial.println(CORE ? "TRUE" : "FALSE");
//  Serial.print(" Ext. Core Word set: \t\t");
//  Serial.println(CORE_EXT ? "TRUE" : "FALSE");
//  Serial.print(" Floored Division: \t\t");
//  Serial.println(FLOORED ? "TRUE" : "FALSE");
//  Serial.print(" Max. Char Value: \t\t");
//  Serial.print(MAX_CHAR);
//  Serial.println(" Dec.");
#ifdef DOUBLE
//  Serial.print(" Max. Signed Double: \t\t");
//  Serial.print(MAX_OF(dcell_t));
//  Serial.println(" Dec.");
#endif
//  Serial.print(" Max. Singed Integer: \t\t");
//  Serial.print(MAX_OF(cell_t));
//  Serial.println(" Dec.");
//  Serial.print(" Max. unsigned Integer: \t");
//  Serial.print(MAX_OF(ucell_t));
//  Serial.println(" Dec.");
//  Serial.print(" Max. Return Stack Size: \t");
//  Serial.print(RSTACK_SIZE);
//  Serial.println(" Cells");
//  Serial.print(" Max. Data Stack Size: \t\t");
//  Serial.print(STACK_SIZE);
//  Serial.println(" Cells");

//  Serial.print("\r\n Input Buffer: Size ");
//  Serial.print(BUFFER_SIZE);
//  Serial.print(" Bytes, Starts at $");
//  Serial.print((size_t)cInputBuffer[0], HEX);
//  Serial.print(", Ends at $");
//  Serial.println((size_t)cInputBuffer[BUFFER_SIZE] - 1, HEX);

//  Serial.print(" Token Buffer: Size ");
//  Serial.print(WORD_SIZE);
//  Serial.print(" Bytes, Starts at $");
//  Serial.print((size_t)&cTokenBuffer[0], HEX);
//  Serial.print(", Ends at $");
//  Serial.println((size_t)&cTokenBuffer[WORD_SIZE] - 1, HEX);

//  Serial.print(" Forth Space: Size ");
//  Serial.print(FORTH_SIZE);
//  Serial.print(" Cells, Starts at $");
//  Serial.print((size_t)&forthSpace[0], HEX);
//  Serial.print(", Ends at $");
//  Serial.println((size_t)&forthSpace[FORTH_SIZE] - 1, HEX);

// Serial.print(prompt_str);
}

#endif
