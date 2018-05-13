// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

// many other files in src/kernel also would get the above timestamp,
// but it is tedious to modify them by hand, to make that happen.

// So, the first file listed alphabetically generally carries the
// latest timestamp, regardless of its true age.

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_DO_SYS
#include "do_sys.h"
const char do_sys_str[] = "do-sys";
// ( n1|u1 n2|u2 -- ) (R: -- loop_sys )
// Set up loop control parameters with index n2|u2 and limit n1|u1. An ambiguous
// condition exists if n1|u1 and n2|u2 are not the same type. Anything already
// on the return stack becomes unavailable until the loop-control parameters
// are discarded.
void _do_sys(void) {
  rStack_push(LOOP_SYS);
  rStack_push(dStack_pop());   // push index on to return stack
  rStack_push(dStack_pop());   // push limit on to return stack
}

#endif
