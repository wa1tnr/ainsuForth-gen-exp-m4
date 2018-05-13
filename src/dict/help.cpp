// Sun 13 May 06:53:54 UTC 2018
// 4737-a3a-03f-

// Sat Jul 29 18:14:02 UTC 2017
// 4735-b0b-01-

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../Dictionary.h"
// #include "../../Error_Codes.h"

/*******************************************************************************/
/*******************************************************************************/
const char help_str[] = "help";
void _help(void) {
  Serial.println();
  Serial.print("    type 'words' instead of 'help'.\r\n");
}

const char who_str[] = "who";
void _who(void) {
  // hex 1d10 dup 48 dump
  // _hex();
  dStack_push(0x2070); // nothing sacred, experiment!  YMMV.
  _dupe();
  dStack_push(0x50);
  _dump();
}
