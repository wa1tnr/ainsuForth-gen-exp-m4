// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_EXIT
#include "exit.h"
const char exit_str[] = "exit";
// Interpretation: undefined
// Execution: ( -- ) (R: nest-sys -- )
// Return control to the calling definition specified by nest-sys. Before
// executing EXIT within a do-loop, a program shall discard the loop-control
// parameters by executing UNLOOP.
void _exit(void) {
  ip = (cell_t*)rStack_pop();
}

#endif
