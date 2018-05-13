// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_ZJUMP
#include "zjump.h"
const char zjump_str[] = "zjump";
void _zjump(void) {
  if (!dStack_pop()) ip = (cell_t*)((size_t)ip + *ip);
  else ip++;
}

#endif
