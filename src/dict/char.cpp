// Wed Jun 28 17:53:29 UTC 2017
// 4735-a0s-01-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

// #ifdef EXT_DICT_CHAR
#include "char.h"
/******************************************************************************/
/** char                                                                     **/
/******************************************************************************/
const char char_str[] = "char";
// ( "<spaces>name" -- char )
// Skip leading space delimiters. Parse name delimited by a space. Put the value
// of its first character onto the stack.
void _char(void) {
  if(getToken()) {
    dStack_push(cTokenBuffer[0]);
  } else {
    dStack_push(-16);
    _throw();
  }
}


const char bracket_char_str[] = "[char]";
// Interpretation: Interpretation semantics for this word are undefined.
// Compilation: ( "<space>name" -- )
// Skip leading spaces delimiters. Parse name delimited by a space. Append
// the run-time semantics given below to the current definition.
// Run-Time: ( -- char )
// Place char, the value of the first character of name, on the stack.
void _bracket_char(void) {
  if (getToken()) {
    *pHere++ = LITERAL_IDX;
    *pHere++ = cTokenBuffer[0];
  } else {
    dStack_push(-16);
    _throw();
  }
}

// #endif

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
