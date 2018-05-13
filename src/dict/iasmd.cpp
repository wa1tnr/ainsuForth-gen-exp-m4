// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

// iasmd.cpp -- add, subtract, multiply and divide integers

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../flashDict.h"
#include "../../Dictionary.h" // provides: #include "iasmd.h"
// #include "../../Error_Codes.h"

/*******************************************************************************/
/**                          Core Forth Words                                 **/
/*******************************************************************************/
const char plus_str[] = "+";
// ( n1|u1 n2|u2 -- n3|u3 )
// add n2|u2 to n1|u1, giving the sum n3|u3
void _plus(void) {
  cell_t x = dStack_pop();
  cell_t y = dStack_pop();
  dStack_push(x +  y);
}


const char minus_str[] = "-";
// ( n1|u1 n2|u2 -- n3|u3 )
void _minus(void) {
  cell_t temp = dStack_pop();
  dStack_push(dStack_pop() -  temp);
}


const char star_str[] = "*";
// ( n1|u1 n2|u2 -- n3|u3 )
// multiply n1|u1 by n2|u2 giving the product n3|u3
void _star(void) {
  dStack_push(dStack_pop() * dStack_pop());
}


const char slash_str[] = "/";
// ( n1 n2 -- n3 )
// divide n1 by n2 giving a single cell quotient n3
void _slash(void) {
  cell_t temp = dStack_pop();
  if (temp)
    dStack_push(dStack_pop() /  temp);
  else {
    dStack_push(-10);
    _throw();
  }
}


const char negate_str[] = "negate";
// ( n1 -- n2 )
// Negate n1, giving its arithmetic inverse n2.
void _negate(void) {
  dStack_push(-dStack_pop());
}


const char abs_str[] = "abs";
// ( n -- u)
// u is the absolute value of n 
void _abs(void) {
  cell_t n = dStack_pop();
  dStack_push(n < 0 ? 0 - n : n);
}


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
