// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_LITERAL
#include "literal.h"
const char literal_str[] = "literal";
// Interpretation: undefined
// Compilation: ( x -- )
// Run-Time: ( -- x )
// Place x on the stack
void _literal(void) {
  if (state) {
       *pHere++ = LITERAL_IDX;
    *pHere++ = dStack_pop();
  } else {
    dStack_push(*ip++);
  }
}

#endif
