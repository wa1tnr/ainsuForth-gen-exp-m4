// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_EQ
#include "eq.h"
const char eq_str[] = "=";
// ( x1 x2 -- flag )
// flag is true if and only if x1 is bit for bit the same as x2
void _eq(void) {
  if (dStack_pop() == dStack_pop()) dStack_push(TRUE);
  else dStack_push(FALSE);
}

#endif
