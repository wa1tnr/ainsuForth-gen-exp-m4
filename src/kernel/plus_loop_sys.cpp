// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_PLUS_LOOP_SYS
#include "plus_loop_sys.h"
const char plus_loop_sys_str[] = "plus_loop-sys";
void _plus_loop_sys(void) {
  cell_t limit = rStack_pop();    // fetch limit
  cell_t index = rStack_pop();    // fetch index
  index += dStack_pop();
  if (limit != index) {
    rStack_push(index);
    rStack_push(limit);
    ip = (cell_t*)*ip;
  } else {
    ip++;
    if (rStack_pop() != LOOP_SYS) {
      dStack_push(-22);
      _throw();
      return;
    }
  }
}

#endif
