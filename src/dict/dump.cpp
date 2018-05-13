// Sun Jul  2 20:55:24 UTC 2017
// 4735-b0a-07-

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../flashDict.h"  // required?
#include "../../Dictionary.h"
// #include "../../Error_Codes.h"

/*******************************************************************************/
/**                          Programming Tools Set                            **/
/*******************************************************************************/
#ifdef TOOLS_SET
const char zero_str[] = "0"; // was in: ainsuForthsketch.cpp
// const char sp_str[] = " ";
const char tab_str[] = "\t";

const char dump_str[] = "dump";
// ( addr u -- )
// Display the contents of u consecutive address starting at addr. The format of
// the display is implementation dependent.
// DUMP may be implemented using pictured numeric output words. Consequently,
// its use may corrupt the transient region identified by #>.
void _dump(void) {
  ucell_t len = (ucell_t)dStack_pop();
  cell_t* addr_start = (cell_t*)dStack_pop();
  cell_t* addr_end = addr_start;
  addr_end += len;
  addr_start = (cell_t*)(((size_t)addr_start >> 4) << 4);

  volatile uint8_t* addr = (uint8_t*)addr_start;

  while (addr < (uint8_t*)addr_end) {
    Serial.print("\r\n$");
    if (addr < (uint8_t*)0x10) Serial.print(zero_str);
    if (addr < (uint8_t*)0x100) Serial.print(zero_str);
    Serial.print((size_t)addr, HEX);
    Serial.print(sp_str);
    for (uint8_t i = 0; i < 16; i++) {
      if (*addr < 0x10) Serial.print(zero_str);
      Serial.print(*addr++, HEX);
      Serial.print(sp_str);
    }
    Serial.print(tab_str);
    addr -= 16;
    for (uint8_t i = 0; i < 16; i++) {
      if (*addr < 127 && *addr > 31) {
        Serial.print((char)*addr);
      } else {
        Serial.print(".");
      }
      addr++;
    }
  }
}

#endif


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
