// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_OVER
#include "over.h"
const char over_str[] = "over";
// ( x1 x2 -- x1 x2 x1 )
void _over(void) {
  dStack_push(dStack_peek(1));
}

#endif
