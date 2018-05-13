// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../Error_Codes.h"

#ifdef EXT_KERN_THROW
#include "throw.h"

#ifndef EXCEPTION_SET
#define EXCEPTION_SET
#endif // #ifndef EXCEPTION_SET

#ifdef EXCEPTION_SET
const char throw_str[] = "throw";
// ( k*x n -- k*x | i*x n)
// if any bit of n are non-zero, pop the topmost exception frame from the
// exception stack, along with everything on the return stack above that frame.
// ...
void _throw(void) {
  errorCode = dStack_pop();
  uint8_t index = 0;
  int tableCode;
  //_cr();
  Serial.print(cTokenBuffer);
  Serial.print(F(" EXCEPTION("));
  do {
    tableCode = pgm_read_dword(&(exception[index].code));
    if (errorCode == tableCode) {
      Serial.print((int)errorCode);
      Serial.print("): ");
      Serial.print(exception[index].name);
      _cr();
    }
    index++;
  } while (tableCode);
//  dStack.tos = -1;                       // Clear the stack.
  dStack_clear();                        // Clear the stack.
  _quit();
  state = FALSE;
}  
#endif
#endif
