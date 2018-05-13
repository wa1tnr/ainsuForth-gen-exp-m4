// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_QUIT
#include "quit.h"
const char quit_str[] = "quit";
void _quit(void) {
  rStack_clear();
  *cpToIn = 0;          // Terminate buffer to stop interpreting
  Serial.flush();
}

#endif
