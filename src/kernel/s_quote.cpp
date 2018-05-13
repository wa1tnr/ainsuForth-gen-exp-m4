// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_S_QUOTE
#include "s_quote.h"
const char s_quote_str[] = "s\x22"; 
// Interpretation: Interpretation semantics for this word are undefined.
// Compilation: ("ccc<quote>" -- )
// Parse ccc delimited by ". Append the run-time semantics given below to the
// current definition.
// Run-Time: ( -- c-addr u )
// Return c-addr and u describing a string consisting of the characters ccc. A program
// shall not alter the returned string.
void _s_quote(void) {
  uint8_t i;
  char length;
  if (flags & EXECUTE) {
    dStack_push((size_t)ip);
    cell_t len = strlen((char*)ip);
    dStack_push(len++);    // increment for the null terminator
    ALIGN(len);
    ip = (cell_t*)((size_t)ip + len);
  }
  else if (state) {
    cDelimiter = '"';
    if (!getToken()) {
      dStack_push(-16);
      _throw();
    }
    length = strlen(cTokenBuffer);
    *pHere++ = S_QUOTE_IDX;
    char *ptr = (char*)pHere;
    for (uint8_t i = 0; i < length; i++) {
      *ptr++ = cTokenBuffer[i];
    }
    *ptr++ = '\0';    // Terminate String
    pHere = (cell_t *)ptr;
    ALIGN_P(pHere);  // re- align pHere for any new code
    cDelimiter = ' ';
  }
}

#endif
