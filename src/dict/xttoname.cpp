// Wed Jun 21 20:55:05 UTC 2017
// 4735-a0p-03-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_XTTONAME
#include "xttoname.h"
/******************************************************************************/
/** Functions for decompiling words                                          **/
/**   Used by _see and _toName                                               **/
/******************************************************************************/
char* xtToName(cell_t xt) {
  pUserEntry = pLastUserEntry;
  // Second Search through the flash Dictionary
  if (xt < 256) {
    Serial.print(flashDict[xt-1].name);
  } else {
    while (pUserEntry) {
      if (pUserEntry->cfa == (cell_t*)xt) {
        Serial.print(pUserEntry->name);
        break;
      }
      pUserEntry = (userEntry_t*)pUserEntry->prevEntry;
    }
  }
  return 0;
}
#endif

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**  Version 0.7.0                                                           **/
/**                                                                          **/
/**  File: YAFFA.ino                                                         **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/**                                                                          **/
/**  This file is part of YAFFA.                                             **/
/**                                                                          **/
/******************************************************************************/
