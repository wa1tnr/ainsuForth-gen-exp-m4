// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_TYPE
#include "type.h"
const char type_str[] = "type";
// ( c-addr u -- )
// if u is greater than zero display character string specified by c-addr and u
void _type(void) {
  uint8_t length = (uint8_t)dStack_pop();
  char* addr = (char*)dStack_pop();
  for (char i = 0; i < length; i++)
    Serial.print(*addr++);
}

#endif
