// Mon Jun 26 00:56:18 UTC 2017
// 4735-a0r-05-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_ALLOT
#include "allot.h"
/******************************************************************************/
/**                                                                          **/
/******************************************************************************/
// const char align_str[] = "align";
// ( -- )
// if the data-space pointer is not aligned, reserve enough space to align it.
// void _align(void) {
//   ALIGN_P(pHere);
// }

// const char aligned_str[] = "aligned";
// ( addr -- a-addr)
// a-addr is the first aligned address greater than or equal to addr.
// void _aligned(void) {
//   ucell_t addr = dStack_pop();
//   ALIGN(addr);
//   dStack_push(addr);
// }

const char allot_str[] = "allot";
// ( n -- )
// if n is greater than zero, reserve n address units of data space. if n is less
// than zero, release |n| address units of data space. If n is zero, leave the
// data-space pointer unchanged.
void _allot(void) {
  cell_t* pNewHere = pHere + dStack_pop();
// Check that the new pHere is not outside of the forth space
  if (pNewHere >= &forthSpace[0] &&
      pNewHere < &forthSpace[FORTH_SIZE]) {
        pHere = pNewHere;      // Save the valid address
  } else {                 // Throw an exception
    dStack_push(-9);
    _throw();
  }
}

#endif
