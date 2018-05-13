// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_LOOP_SYS
#include "loop_sys.h"
const char loop_sys_str[] = "loop-sys";
void _loop_sys(void) {
  cell_t limit = rStack_pop();    // fetch limit
  cell_t index = rStack_pop();    // fetch index
  index++;
  if (limit - index) {
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
