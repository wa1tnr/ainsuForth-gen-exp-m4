// Sun Jun 18 16:24:18 UTC 2017
// 4735-a0m-01

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_EXEC_WORD
#include "execute_word.h"
/******************************************************************************/
/** Virtual Machine that executes Code Space                                 **/
/******************************************************************************/
void executeWord(void) {
   func function;
   flags |= EXECUTE;
   while (ip != NULL) {
     w = *ip++;
     if (w > 255) {
      // ip is an address in code space
       rStack_push((size_t)ip); // push the address to return to
       ip = (cell_t*)w;          // set the ip to the new address
     }
     else {
       function = flashDict[w - 1].function;
       function();
       if (errorCode) return;
     }
   }
   flags &= ~EXECUTE;
}

#endif
