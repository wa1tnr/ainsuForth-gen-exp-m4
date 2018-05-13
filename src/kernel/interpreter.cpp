// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_INTERPRETER
#include "interpreter.h"
/******************************************************************************/
/** Interpeter - Interprets a new string                                     **/
/**                                                                          **/
/** Parse the new line. For each parsed subString, try to execute it.  If it **/
/** can't be executed, try to interpret it as a number.  If that fails,      **/
/** signal an error.                                                         **/
/******************************************************************************/
void interpreter(void) {
  func function;
  while (getToken()) {
    if (state) {
      /*************************/
      /** Compile Mode        **/
      /*************************/
      if (isWord(cTokenBuffer)) {
        if (wordFlags & IMMEDIATE) {
          if (w > 255) {
            rStack_push(0);        // Push 0 as our return address
            ip = (cell_t *)w;    // set the ip to the XT (memory location)
            executeWord();
          } else {
            function = flashDict[w - 1].function;
            function();
            if (errorCode) return;
          }
          executeWord();  // Why is this here?
        } else {
          *pHere++ = w;
        } // ends stanza that began 'if (wordFlags & IMMEDIATE)'
      } // ends stanza that began 'if (isWord(cTokenBuffer))'
      else if (isNumber(cTokenBuffer)) {
        _literal();
      } else {
        dStack_push(-13);
        _throw();
      }
    } // ends stanza that began 'if (state)'

    else { // 'if (state) { foo } else ...
      /************************/
      /* Interpret Mode       */
      /************************/
      if (isWord(cTokenBuffer)) {
        if (wordFlags & COMP_ONLY) {
          dStack_push(-14);
          _throw();
          return;
        }
        if (w > 255) {
          rStack_push(0);           // Push 0 as our return address
          ip = (cell_t *)w;         // set the ip to the XT (memory location)
          executeWord();
          if (errorCode) return;
        } else {
          function = flashDict[w - 1].function;
          function();
          if (errorCode) return;
        }
      } // ends stanza that began 'if (isWord(cTokenBuffer))'
      else if (isNumber(cTokenBuffer)) {
        // Is something supposed to be here?
      } else {
        dStack_push(-13);
        _throw();
        return;
      }
    } // ends stanza that began 'if (state)'
  } // ends stanza that began 'while (getToken())'
  cpToIn = cpSource;
}
#endif
