// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// version bump

// Sat Nov 25 19:03:16 UTC 2017
// 4735-b0c-09d-   the -09x- is new Nov 24, 2017.

// RATIONALE - the accept word goes in the dictionary, not the
// kernel, as the system can be used quite ably without it.
// It is, however, valuable enough to belong in the permanent
// dictionary (and can be compiled-out easily enough).

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../flashDict.h"
// #include "../../Dictionary.h"
// #include "../../Error_Codes.h"
#ifdef EXT_KERN_ACCEPT
#include "accept.h"

// const char not_done_str[] = " NOT Implemented Yet \n\r";

// const char sp_str[] = " "; // does not belong here
// const char tab_str[] = "\t"; // does not belong here
// stack_t dStack;
// stack_t rStack;


/*******************************************************************************/
/**                          Core Forth Words                                 **/
/*******************************************************************************/

const char accept_str[] = "accept"; // ( c-addr +n1 -- +n2 )
void _accept(void) {
  cell_t length = dStack_pop();
  char* addr = (char*)dStack_pop();
  length = getLine(addr, length);
  dStack_push(length);
}


#endif

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/**                                                                          **/
/**  This file is part of YAFFA.                                             **/
/**                                                                          **/
/**  YAFFA is free software: you can redistribute it and/or modify           **/
/**  it under the terms of the GNU General Public License as published by    **/
/**  the Free Software Foundation, either version 2 of the License, or       **/
/**  (at your option) any later version.                                     **/
/**                                                                          **/
/**  YAFFA is distributed in the hope that it will be useful,                **/
/**  but WITHOUT ANY WARRANTY; without even the implied warranty of          **/
/**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **/
/**  GNU General Public License for more details.                            **/
/**                                                                          **/
/**  You should have received a copy of the GNU General Public License       **/
/**  along with YAFFA.  If not, see <http://www.gnu.org/licenses/>.          **/
/**                                                                          **/
/******************************************************************************/

