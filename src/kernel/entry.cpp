// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_ENTRY
#include "entry.h"
/******************************************************************************/
/** Start a New Entry in the Dictionary                                      **/
/******************************************************************************/
void openEntry(void) {
  uint8_t index = 0;
  pOldHere = pHere;            // Save the old location of HERE so we can
                               // abort out of the new definition
  pNewUserEntry = (userEntry_t*)pHere;
  if (pLastUserEntry == NULL)
    pNewUserEntry->prevEntry = 0;              // Initialize User Dictionary
  else pNewUserEntry->prevEntry = pLastUserEntry;
  if (!getToken()) {
   dStack_push(-16);
   _throw();
  }
  char* ptr = pNewUserEntry->name;
  do {
    *ptr++ = cTokenBuffer[index++];
  } while (cTokenBuffer[index] != '\0');
  *ptr++ = '\0';
  pHere = (cell_t *)ptr;
  ALIGN_P(pHere);

  pNewUserEntry->cfa = pHere;
  pCodeStart = pHere;
}

/******************************************************************************/
/** Finish an new Entry in the Dictionary                                    **/
/******************************************************************************/
void closeEntry(void) {
  if (errorCode == 0) {
    *pHere++ = EXIT_IDX;
    pNewUserEntry->flags = 0; // clear the word's flags
    pLastUserEntry = pNewUserEntry;
  } else pHere = pOldHere;   // Revert pHere to what it was before the start
                             // of the new word definition
}

#endif
