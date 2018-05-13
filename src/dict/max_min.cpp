// Sun Jul  2 03:11:48 UTC 2017
// 4735-b0a-05-

#include <Arduino.h>
#include "../../yaffa.h"
#include "max_min.h"
// #include "../../Error_Codes.h"

const char max_str[] = "max";
// ( n1 n2 -- n3 )
// n3 is the greater of of n1 or n2.
void _max(void) {
  cell_t n2 = dStack_pop();
  cell_t n1 = dStack_pop();
  if (n1 > n2) dStack_push(n1);
  else dStack_push(n2);
}

const char min_str[] = "min";
// ( n1 n2 -- n3 )
// n3 is the lesser of of n1 or n2.
void _min(void) {
  cell_t n2 = dStack_pop();
  cell_t n1 = dStack_pop();
  if (n1 > n2) dStack_push(n2);
  else dStack_push(n1);
}


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
