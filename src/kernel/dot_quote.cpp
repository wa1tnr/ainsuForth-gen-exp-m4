// Sun Jun 11 23:00:12 UTC 2017
// 4735-a0g

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_DOT_QUOTE
#include "dot_quote.h"
/**  File: Dictionary.ino                                                    **/
const char dot_quote_str[] = ".\x22";
// Compilation ("ccc<quote>" -- )
// Parse ccc delimited by ". Append the run time semantics given below to
// the current definition.
// Run-Time ( -- )
// Display ccc.
void _dot_quote(void) {
  uint8_t i;
  char length;
  if (flags & EXECUTE) {
    Serial.print((char*)ip); // Print the string at the istuction pointer (ip)
    cell_t len = strlen((char*)ip) + 1;  // include null terminator
    ip = (cell_t*)((size_t)ip + len); // Move the ip to the end of the string 
    ALIGN_P(ip); // and align it.
  }
  else if (state) {
    cDelimiter = '"';
    if (!getToken()) {
      dStack_push(-16);
      _throw();
    }
    length = strlen(cTokenBuffer);
    *pHere++ = DOT_QUOTE_IDX;
    char *ptr = (char *) pHere;
    for (uint8_t i = 0; i < length; i++) {
      *ptr++ = cTokenBuffer[i];
    }
    *ptr++ = '\0';    // Terminate String
    pHere = (cell_t *)ptr;
    ALIGN_P(pHere);  // re- align the pHere for any new code
    cDelimiter = ' ';
  }
}

#endif
