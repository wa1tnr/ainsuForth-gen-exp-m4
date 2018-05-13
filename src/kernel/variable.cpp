// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_VARIABLE
#include "variable.h"
const char variable_str[] = "variable";
// ( "<spaces>name" -- )
// Parse name delimited by a space. Create a definition for name with the
// execution semantics defined below. Reserve one cell of data space at an
// aligned address.
// name Execution: ( -- a-addr )
// a-addr is the address of the reserved cell. A program is responsible for
// initializing the contents of a reserved cell.
void _variable(void) {
  if (flags & EXECUTE) {
    dStack_push((size_t)ip++);
  } else {
    openEntry();
    *pHere++ = VARIABLE_IDX;
    *pHere++ = 0;
    closeEntry();
  }
}

// cr variable helka .s cr helka .s cr drop .s cr 4377 helka ! .s cr helka @ .s cr cr
// <0>
// <1> 536871708
// <0>
// <0>
// <1> 4377
// 
//  ok..

#endif
