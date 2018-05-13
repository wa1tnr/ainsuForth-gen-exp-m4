// Tue Jun 27 21:19:58 UTC 2017
// 4735-a0s-00-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

// #ifdef EXT_DO_LOOP
#include "do_loop.h"
/******************************************************************************/
/** do ... loop                                                              **/
/******************************************************************************/
const char do_str[] = "do";
// Compilation: (C: -- do-sys)
// Run-Time: ( n1|u1 n2|u2 -- ) (R: -- loop-sys )
void _do(void) {
  dStack_push(DO_SYS);
  *pHere++ = DO_SYS_IDX;
  dStack_push((size_t)pHere); // store the origin address of the do loop
}

const char loop_str[] = "loop";
// Interpretation: undefined
// Compilation: (C: do-sys -- )
// Run-Time: ( -- ) (R: loop-sys1 -- loop-sys2 )
void _loop(void) {
  *pHere++ = LOOP_SYS_IDX;
  cell_t start_addr = dStack_pop();
  *pHere++ = start_addr;
  cell_t stop_addr = (cell_t)pHere;
  cell_t* ptr = (cell_t*)start_addr;
  do {
    if (*ptr++ == LEAVE_SYS_IDX) {
      if (*ptr == 0) {
        *ptr = stop_addr;
      }
    }
  } while (ptr != (cell_t*)stop_addr);
  if ( dStack_pop() != DO_SYS) {
    dStack_push(-22);
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
