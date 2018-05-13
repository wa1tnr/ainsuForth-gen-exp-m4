// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// version bump

// previous timestamp:
// Fri Nov 24 04:49:08 UTC 2017
// 4735-b0c-07z-   the -07x- is new Nov 19, 2017.
// Fri Nov 24 02:42:54 UTC 2017
// Thu Nov 23 02:01:47 UTC 2017
// Thu Nov 23 00:45:23 UTC 2017
// Wed Nov 22 21:43:39 UTC 2017
// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../flashDict.h"
#include "../../Dictionary.h"
// #include "../../Error_Codes.h"

extern const char sp_str[]; // = " "; // does not belong here

/*******************************************************************************/
/**                          Core Forth Words                                 **/
/*******************************************************************************/

#ifndef STACK_OPS
#define STACK_OPS
#endif

#ifdef STACK_OPS
const char dupe_str[] = "dup";
// ( x -- x x )
// Duplicate x
void _dupe(void) {
  dStack_push(dStack_peek(0));
}


const char swap_str[] = "swap";
void _swap(void) { // x y -- y x
  cell_t x, y;

  y = dStack_pop();
  x = dStack_pop();
  dStack_push(y);
  dStack_push(x);
}


const char rot_str[] = "rot";
// ( x1 x2 x3 -- x2 x3 x1)
void _rot(void) {
  cell_t x3 = dStack_pop();
  cell_t x2 = dStack_pop();
  cell_t x1 = dStack_pop();
  dStack_push(x2);
  dStack_push(x3);
  dStack_push(x1);
}


const char and_str[] = "and";
// ( x1 x2 -- x3 )
// x3 is the bit by bit logical and of x1 with x2
void _and(void) {
  dStack_push(dStack_pop() & dStack_pop());
}


const char or_str[] = "or";
// ( x1 x2 -- x3 )
// x3 is the bit by bit logical or of x1 with x2
void _or(void) {
  dStack_push(dStack_pop() |  dStack_pop());
}


const char xor_str[] = "xor";
// ( x1 x2 -- x3 )
// x3 is the bit by bit exclusive or of x1 with x2
void _xor(void) {
  dStack_push(dStack_pop() ^  dStack_pop());
}


const char dot_str[] = ".";
// ( n -- )
// display n in free field format
void _dot(void) {
  w = dStack_pop();
  displayValue();
}


const char u_dot_str[] = "u.";
// ( u -- )
// Displau u in free field format
// tested and fixed by Alex Moskovskij
void _u_dot(void) {
  Serial.print((ucell_t) dStack_pop());
  Serial.print(F(" "));
}


/**                          Programming Tools Set                            **/
// #ifdef TOOLS_SET  // YAFFA-ARM organization: TOOLS_SET

const char dot_s_str[] = ".s";
void _dot_s(void) {
  char i = 0;
  char j = 0;
  char depth = dStack_size();
  j = depth;
  Serial.print("<"); // gforthism 
  Serial.print(j+0); // comment was here
  Serial.print("> ");
  if (depth > 0) {
    for (i = depth; i > 0; i--) { // walk backwards
      j = i - 1; // normalize
      w = dStack_peek(j);
      displayValue();
    }
  }
}


const char emit_str[] = "emit";
// ( x -- )
// display x as a character
void _emit(void) {
  Serial.print((char) dStack_pop());
}

// repair (or kludge) of the dot_paren word on 22 Nov 2017.

// In a four-byte field, the first character of a counted string
// appears to be right-aligned in that field.  To compensate,
// the address is now incremented by three, so that it now points
// to the first character in the counted string.

const char dot_paren_str[] = ".(";
// ( "ccc<paren>" -- )
// Parse and display ccc delimitied by ) (right parenthesis). .( is an immediate word.
void _dot_paren(void) { 
  dStack_push(')');
  _word();
  _count(); // has the fixes (below) appended
  // _swap();
  // uint8_t* addr = (uint8_t*)dStack_pop();
  // *addr++;  *addr++;  *addr++;
  // dStack_push((size_t)addr);
  // _swap();
  _type();
}

const char cr_str[] = "cr"; // ( -- ) Carriage Return
void _cr(void) {
  Serial.println();
}


const char space_str[] = "space";
// ( -- )
// Display one space
void _space(void) {
  Serial.print(sp_str);
}


const char spaces_str[] = "spaces";
// ( n -- )
// if n is greater than zero, display n space
void _spaces(void) {
  char n = (char) dStack_pop();
  while (n > 0) {
    Serial.print(sp_str);
    n--;
  }
}


const char hex_str[] = "hex";
// ( -- )
// Set BASE to 16
void _hex(void) { // value --
  base = HEX;
}


const char decimal_str[] = "decimal";
// ( -- )
// Set BASE to 10
void _decimal(void) { // value --
  base = DECIMAL;
}


const char words_str[] = "words";
void _words(void) { // --
  uint8_t count = 0;
  uint8_t index = 0;
  uint8_t length = 0;
  char* pChar;

   while (flashDict[index].name) {
     if (count > 70) {
      Serial.println();
      count = 0;
     }
     if (!(flashDict[index].flags & SMUDGE)) {
      count += Serial.print(flashDict[index].name);
      count += Serial.print(sp_str);
     }
    index++;
   }

  pUserEntry = pLastUserEntry;
   while (pUserEntry) {
     if (count > 70) {
      Serial.println();
      count = 0;
     }
     if (!(pUserEntry->flags & SMUDGE)) {
      count += Serial.print(pUserEntry->name);
      count += Serial.print(sp_str);
     }
    pUserEntry = (userEntry_t*)pUserEntry->prevEntry;
   }
  Serial.println();
}


const char zero_equal_str[] = "0=";
// ( n -- flag )
// flag is true if and only if n is equal to zero.
void _zero_equal(void) {
  if (dStack_pop() == 0) dStack_push(TRUE);
  else dStack_push(FALSE);
}


const char delay_str[] = "delay";
void _delay(void) {
  delay(dStack_pop());
}
#endif


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
