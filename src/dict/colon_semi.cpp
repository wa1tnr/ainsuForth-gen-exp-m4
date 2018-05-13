// Wed Jun 21 20:55:05 UTC 2017
// 4735-a0p-03-

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../flashDict.h"
#include "../../Dictionary.h"
// #include "../../Error_Codes.h"

// const char not_done_str[] = " NOT Implemented Yet \n\r";

// const char sp_str[] = " "; // does not belong here
// stack_t dStack;
// stack_t rStack;

/*******************************************************************************/
/**                          Core Forth Words                                 **/
/*******************************************************************************/
const char colon_str[] = ":";
// (C: "<space>name" -- colon-sys )
// Skip leading space delimiters. Parse name delimited by a space. Create a
// definition for name, called a "colon definition" Enter compilation state
// and start the current definition, producing a colon-sys. Append the
// initiation semantics given below to the current definition....
void _colon(void) {
  state = TRUE;
  dStack_push(COLON_SYS);
  openEntry();
}

const char semicolon_str[] = ";";
// IMMEDIATE
// Interpretation: undefined
// Compilation: (C: colon-sys -- )
// Run-time: ( -- ) (R: nest-sys -- )
void _semicolon(void) {
  if (dStack_pop() != COLON_SYS) {
    dStack_push(-22);
    _throw();
    return;
  }
  closeEntry();
  state = FALSE;
}


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/**                                                                          **/
/**  This file is part of YAFFA.                                             **/
/**                                                                          **/
/******************************************************************************/

