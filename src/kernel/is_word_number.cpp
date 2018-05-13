// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_IS_WORD_NUMBER
#include "is_word_number.h"
/******************************************************************************/
/** Find the word in the Dictionaries                                        **/
/** Return execution token value in the w register.                          **/
/** Returns 1 if the word is found                                           **/
/**                                                                          **/
/** Also set wordFlags, from the definition of the word.                     **/
/**                                                                          **/
/** Could this become the word FIND or ' (tick)?                             **/
/******************************************************************************/
uint8_t isWord(char* addr) {
  uint8_t index = 0;
  pUserEntry = pLastUserEntry;
  // First search through the user dictionary
  while (pUserEntry) {
    if (strcmp(pUserEntry->name, addr) == 0) {
      wordFlags = pUserEntry->flags;
      w = (size_t)pUserEntry->cfa;
      return 1;
    }
    pUserEntry = (userEntry_t*)pUserEntry->prevEntry;
  }
  // Second Search through the flash Dictionary
  while (flashDict[index].name) {
    if (!strcasecmp(addr, flashDict[index].name)) {
      w = index + 1;
      wordFlags = flashDict[index].flags;
      if (wordFlags & SMUDGE) {
        return 0;
      } else {
        return 1;
      }
    }
    index++;
  }
  w = 0;
  return 0;
}

/******************************************************************************/
/** Attempt to interpret token as a number.  If it looks like a number, push **/
/** it on the stack and return 1.  Otherwise, push nothing and return 0.     **/
/**                                                                          **/
/** Numbers without a prefix are assumed to be decimal.  Decimal numbers may **/
/** have a negative sign in front which does a 2's complement conversion at  **/
/** the end.  Prefixes are # for decimal, $ for hexadecimal, and % for       **/
/** binary.                                                                  **/
/******************************************************************************/
uint8_t isNumber(char* subString) {
  unsigned char negate = 0;                  // flag if number is negative
  cell_t tempBase = base;
  cell_t number = 0;
  wordFlags = 0;
  // Look at the initial character, handling either '-', '$', or '%'
  switch (*subString) {
    case '$':  base = HEXIDECIMAL;  goto SKIP;
    case '%':  base = BINARY;   goto SKIP;
    case '#':  base = DECIMAL;  goto SKIP;
    case '-':  negate = 1;
SKIP:                // common code to skip initial character
    subString++;
    break;
  }
  // Iterate over rest of token, and if rest of digits are in
  // the valid set of characters, accumulate them.  If any
  // invalid characters found, abort and return 0.
  while (*subString) {
    char* pos = strchr(charset, (int)tolower(*subString));
    cell_t offset = pos - charset;
    if ((offset < base) && (offset > -1))
      number = (number * base) + (pos - charset);
    else {
      base = tempBase;
      return 0;           // exit, signalling subString isn't a number
    }
    subString++;
  }
  if (negate) number = ~number + 1;     // apply sign, if necessary
  dStack_push(number);
  base = tempBase;
  return 1;
}

#endif
