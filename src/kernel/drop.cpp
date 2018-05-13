// Sun Jun 11 23:00:12 UTC 2017
// 4735-a0g

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_DROP
#include "drop.h"
const char drop_str[] = "drop";
// ( x -- )
// Remove x from stack
void _drop(void) {
  dStack_pop();
}

#endif
