/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**  Version 0.7.0                                                           **/
/**                                                                          **/
/**  File: YAFFA.ino                                                         **/
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
/**                                                                          **/
/**  DESCRIPTION:                                                            **/
/**                                                                          **/
/**  YAFFA is an attempt to make a Forth environment for the Arduino that    **/
/**  is as close as possible to the ANSI Forth draft specification DPANS94.  **/
/**                                                                          **/
/**  The goal is to support at a minimum the ANS Forth C core word set and   **/
/**  to implement wrappers for the basic I/O functions found in the Arduino  **/
/**  library.                                                                **/
/**  YAFFA uses two dictionaries, one for built in words and is stored in    **/
/**  flash memory, and the other for user defined words, that is found in    **/
/**  RAM.                                                                    **/
/**                                                                          **/
/******************************************************************************/
/**                                                                          **/
/**  REVISION HISTORY:                                                       **/
/**                                                                          **/
/**    0.7.0                                                                **/
/**    - Fixed the how LEAVE is handled in LOOP and +LOOP.                   **/
/**    0.6.2                                                                 **/
/**    - Added words ">NUMBER", "KEY?", ".(", "0<>", "0>", "2>R", "2R>",     **/
/**      "2R@".                                                              **/
/**    - Removed static from the function headers to avoid compilation       **/
/**      errors with the new 1.6.6 Arduino IDE.                              **/
/**    - changed file names from yaffa.h to YAFFA.h and Yaffa.ino to         **/
/**      YAFFA.ino and the #includes to reflect the capatilized name. This   **/
/**      helps with cheking out the project from github without renaming     **/
/**      files.                                                              **/
/**    - Fixed comments for pinWrite and pinMode.                            **/
/**    - YAFFA.h reorganized for different architectures                     **/
/**    - Replaced Serial.print(PSTR()) with Serial.print(F())                **/
/**    0.6.1                                                                 **/
/**    - Documentation cleanup. thanks to Dr. Hugh Sasse, BSc(Hons), PhD     **/
/**    0.6                                                                   **/
/**    - Fixed PROGMEM compilation errors do to new compiler in Arduino 1.6  **/
/**    - Embedded the revision in to the compiled code.                      **/
/**    - Revision is now displayed in greeting at start up.                  **/
/**    - the interpreter not clears the word flags before it starts.         **/
/**    - Updated TICK, WORD, and FIND to make use of primitive calls for to  **/
/**      reduce code size.                                                   **/
/**    - Added word flag checks in dot_quote() and _s_quote().               **/
/**                                                                          **/
/**  NOTES:                                                                  **/
/**                                                                          **/
/**    - Compiler now gives "Low memory available, stability problems may    **/
/**      occur." warning. This is expected since most memory is reserved for **/
/**      the FORTH environment. Excessive recursive calls may overrun the C  **/
/**      stack.                                                              **/
/**                                                                          **/
/**  THINGS TO DO:                                                           **/
/**                                                                          **/
/**  CORE WORDS TO ADD:                                                      **/
/**      >NUMBER                                                             **/
/**                                                                          **/
/**  THINGS TO FIX:                                                          **/
/**                                                                          **/
/**    Fix the outer interpreter to use FIND instead of isWord               **/
/**    Fix Serial.Print(w, HEX) from displaying negative numbers as 32 bits  **/
/**    Fix ENVIRONMENT? Query to take a string reference from the stack.     **/
/**                                                                          **/
/******************************************************************************/

#include "YAFFA.h"
#include "Error_Codes.h"

/******************************************************************************/
/** Major and minor revision numbers                                         **/
/******************************************************************************/
#define YAFFA_MAJOR 0
#define YAFFA_MINOR 7
#define MAKESTR(a) #a
#define MAKEVER(a, b) MAKESTR(a*256+b)
asm(" .section .version\n"
    "yaffa_version: .word " MAKEVER(YAFFA_MAJOR, YAFFA_MINOR) "\n"
    " .section .text\n");

/******************************************************************************/
/** Common Strings & Terminal Constants                                      **/
/******************************************************************************/
const char prompt_str[] = ">> ";
const char compile_prompt_str[] = "|  ";
const char ok_str[] = " OK";
const char charset[] = "0123456789abcdef";
const char sp_str[] = " ";
const char tab_str[] = "\t";
const char hexidecimal_str[] = "$";
const char octal_str[] = "0";
const char binary_str[] = "%";
const char zero_str[] = "0";

/******************************************************************************/
/** Global Variables                                                         **/
/******************************************************************************/
//forthSpace_t fs;  // Creates the forth space structure

/******************************************************************************/
/**  Text Buffers and Associated Registers                                   **/
/******************************************************************************/
char* cpSource;                 // Pointer to the string location that we will
                                // evaluate. This could be the input buffer or
                                // some other location in memory
char* cpSourceEnd;              // Points to the end of the source string
char* cpToIn;                   // Points to a position in the source string
                                // that was the last character to be parsed
char cDelimiter = ' ';          // The parsers delimiter
char cInputBuffer[BUFFER_SIZE]; // Input Buffer that gets parsed
char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

/******************************************************************************/
/**  Stacks and Associated Registers                                         **/
/**                                                                          **/
/**  Control Flow Stack is virtual right now. But it may be but onto the     **/
/**  data stack. Error checking should be done to make sure the data stack   **/
/**  is not corrupted, i.e. the same number of items are on the stack as     **/
/**  at the end of the colon-sys as before it is started.                    **/
/******************************************************************************/
//int8_t tos = -1;                        // The data stack index
//int8_t rtos = -1;                       // The return stack index
//cell_t stack[STACK_SIZE];               // The data stack
//cell_t rStack[RSTACK_SIZE];             // The return stack
stack_t dStack;
stack_t rStack;
//Stack<cell_t> dStack = Stack<cell_t>(STACK_SIZE);
//Stack<cell_t> rStack = Stack<cell_t>(RSTACK_SIZE);
/******************************************************************************/
/**  Flash Dictionary Structure                                              **/
/******************************************************************************/
const flashEntry_t* pFlashEntry = flashDict;   // Pointer into the flash Dictionary

/******************************************************************************/
/**  User Dictionary is stored in name space.                                **/
/******************************************************************************/
userEntry_t* pLastUserEntry = NULL;
userEntry_t* pUserEntry = NULL;
userEntry_t* pNewUserEntry = NULL;

/******************************************************************************/
/**  Flags - Internal State and Word                                         **/
/******************************************************************************/
uint8_t flags;                 // Internal Flags
uint8_t wordFlags;             // Word flags

/******************************************************************************/
/** Error Handling                                                           **/
/******************************************************************************/
int8_t errorCode = 0;

/******************************************************************************/
/**  Forth Space (Name, Code and Data Space) and Associated Registers        **/
/******************************************************************************/
char* pPNO;                  // Pictured Numeric Output Pointer
cell_t forthSpace[FORTH_SIZE]; // Reserve a block on RAM for the forth environment
cell_t* pHere;               // HERE, points to the next free position in
                             // Forth Space
cell_t* pOldHere;            // Used by "colon-sys"
cell_t* pCodeStart;          // used by "colon-sys" and RECURSE
cell_t* pDoes;               // Used by CREATE and DOES>

/******************************************************************************/
/** Forth Global Variables                                                   **/
/******************************************************************************/
uint8_t state; // Holds the text interpreters compile/interpreter state
cell_t* ip;   // Instruction Pointer
cell_t w;     // Working Register
uint8_t base;  // stores the number conversion radix

/******************************************************************************/
/** Initialization                                                           **/
/******************************************************************************/
void setup(void) {                
  uint16_t mem;
  Serial.begin(19200);     // Open serial communications:

  flags = ECHO_ON;
  base = DECIMAL;

  pHere = &forthSpace[0];
  pOldHere = pHere;
  
  Serial.print("\n YAFFA - Yet Another Forth For Arduino, ");
  Serial.print("Version ");
  Serial.print(YAFFA_MAJOR,DEC);
  Serial.print(".");
  Serial.println(YAFFA_MINOR,DEC);
  Serial.print(" Copyright (C) 2012 Stuart Wood\r\n");
  Serial.print(" This program comes with ABSOLUTELY NO WARRANTY.\r\n");
  Serial.print(" This is free software, and you are welcome to\r\n");
  Serial.println(" redistribute it under certain conditions.\r\n");
  
  Serial.print(" Processor is a ");
  Serial.println(PROC_STR);
  Serial.print(" Terminal Echo is ");
  Serial.print(flags & ECHO_ON ? "On\r\n" : "Off\r\n");
  Serial.print(" Pre-Defined Words : ");
  pFlashEntry = flashDict;
  w = 0;
  while (pFlashEntry->name) { // Good for the Zero
    w++;
    pFlashEntry++;
  }
  Serial.println(w);

  Serial.println("\r\n Environment Parameters: ");
  Serial.print(" Counted String Length: \t");
  Serial.print(BUFFER_SIZE);
  Serial.println(" Bytes");
  Serial.print(" Pict. Num. Output Length: \t");
  Serial.print(HOLD_SIZE);
  Serial.println(" Bytes");
  Serial.print(" Scratch Pad size: \t\t");
  Serial.print(PAD_SIZE);
  Serial.println(" Bytes");
  Serial.print(" Address Size: \t\t\t");
  Serial.print(sizeof(void*) * 8);
  Serial.println(" Bits");
  Serial.print(" Core Word set: \t\t");
  Serial.println(CORE ? "TRUE" : "FALSE");
  Serial.print(" Ext. Core Word set: \t\t");
  Serial.println(CORE_EXT ? "TRUE" : "FALSE");
  Serial.print(" Floored Division: \t\t");
  Serial.println(FLOORED ? "TRUE" : "FALSE");
  Serial.print(" Max. Char Value: \t\t");
  Serial.print(MAX_CHAR);
  Serial.println(" Dec.");
#ifdef DOUBLE
  Serial.print(" Max. Signed Double: \t\t");
  Serial.print(MAX_OF(dcell_t));
  Serial.println(" Dec.");
#endif
  Serial.print(" Max. Singed Integer: \t\t");
  Serial.print(MAX_OF(cell_t));
  Serial.println(" Dec.");
  Serial.print(" Max. unsigned Integer: \t");
  Serial.print(MAX_OF(ucell_t));
  Serial.println(" Dec.");
  Serial.print(" Max. Return Stack Size: \t");
  Serial.print(RSTACK_SIZE);
  Serial.println(" Cells");
  Serial.print(" Max. Data Stack Size: \t\t");
  Serial.print(STACK_SIZE);
  Serial.println(" Cells");

  Serial.print("\r\n Input Buffer: Size ");
  Serial.print(BUFFER_SIZE);
  Serial.print(" Bytes, Starts at $");
  Serial.print((size_t)cInputBuffer[0], HEX);
  Serial.print(", Ends at $");
  Serial.println((size_t)cInputBuffer[BUFFER_SIZE] - 1, HEX);

  Serial.print(" Token Buffer: Size ");
  Serial.print(WORD_SIZE);
  Serial.print(" Bytes, Starts at $");
  Serial.print((size_t)&cTokenBuffer[0], HEX);
  Serial.print(", Ends at $");
  Serial.println((size_t)&cTokenBuffer[WORD_SIZE] - 1, HEX);

  Serial.print(" Forth Space: Size ");
  Serial.print(FORTH_SIZE);
  Serial.print(" Cells, Starts at $");
  Serial.print((size_t)&forthSpace[0], HEX);
  Serial.print(", Ends at $");
  Serial.println((size_t)&forthSpace[FORTH_SIZE] - 1, HEX);

  Serial.print(prompt_str);
}

/******************************************************************************/
/** Outer interpreter                                                        **/
/******************************************************************************/
void loop(void) {
  cpSource = cpToIn = cInputBuffer;
  cpSourceEnd = cpSource + getLine(cpSource, BUFFER_SIZE);
  if (cpSourceEnd > cpSource) {
    interpreter();
    if (errorCode) {
        errorCode = 0;
    } else {
      if (!state) {
        Serial.print(ok_str);
        // This shows a DOT for each item on the data stack
        char i = dStack_size();
        while(i--) {
            Serial.print(".");
        }
        Serial.println();
      }
    }
  }
  if (state) {
	Serial.print(compile_prompt_str);
  } else {
	Serial.print(prompt_str);
  }
}

/******************************************************************************/
/** getKey                                                                   **/
/**   waits for the next valid key to be entered and return its value        **/
/**   Valid characters are:  Backspace, Carriage Return, Escape, Tab, and    **/
/**   standard printable characters                                          **/
/******************************************************************************/
char getKey(void) {
  char inChar;

  while (1) {
    if (Serial.available()) {
      inChar = Serial.read();
      if (inChar == ASCII_BS || inChar == ASCII_TAB || inChar == ASCII_CR || 
          inChar == ASCII_ESC || isprint(inChar)) {
        return inChar; 
      }
    }
  }
}

/******************************************************************************/
/** getLine                                                                  **/
/**   read in a line of text ended by a Carriage Return (ASCII 13)           **/
/**   Valid characters are:  Backspace, Carriage Return, Escape, Tab, and    **/
/**   standard printable characters. Passed the address to store the string, **/
/**   and Returns the length of the string stored                            **/
/******************************************************************************/
uint8_t getLine(char* ptr, uint8_t buffSize) {
  char inChar;
  uint8_t count = 0;
  do {
    inChar = getKey();
    if (inChar == ASCII_BS) {
      if (count) {
        *--ptr = 0;
        if (flags & ECHO_ON) Serial.print("\b \b");
      }
    } else if (inChar == ASCII_TAB || inChar == ASCII_ESC) {
      if (flags & ECHO_ON) Serial.print("\a"); // Beep
    } else if (inChar == ASCII_CR) {
      if (flags & ECHO_ON) Serial.println();
      break;
    } else {
      if (flags & ECHO_ON) Serial.print(inChar);
      *ptr++ = inChar;
      *ptr = 0;
      count++;
    }
  } while (count < buffSize);
  return (count);
}

/******************************************************************************/
/** GetToken                                                                 **/
/**   Find the next token in the buffer and stores it into the token buffer  **/
/**   with a NULL terminator. Returns length of the token or 0 if at end off **/
/**   the buffer.                                                            **/
/**   Could this become the word WORD?                                       **/
// ( char "<chars>ccc<chars>" -- c-addr )
// Skip leading delimiters. Parse characters ccc delimited by char. An ambiguous
// condition exists if the length of the parsed string is greater than the 
// implementation-defined length of a counted string.
//
// c-addr is the address of a transient region containing the parsed word as a
// counted string. If the parse area was empty or contained no characters other than
// the delimiter, the resulting string has a zero length. A space, not included in 
// the length, follows the string. A program may replace characters within the 
// string.
//
// NOTE: The requirement to follow the string with a space is obsolescent and is
// included as a concession to existing programs that use CONVERT. A program shall 
// not depend on the existence of the space.
/******************************************************************************/
uint8_t getToken(void) {
  uint8_t tokenIdx = 0;
  while (cpToIn <= cpSourceEnd) {
    if ((*cpToIn == cDelimiter) || (*cpToIn == 0)) {
      cTokenBuffer[tokenIdx] = '\0';       // Terminate SubString
      cpToIn++;
      if (tokenIdx) return tokenIdx;
    } else {
      if (tokenIdx < (WORD_SIZE - 1)) {
        cTokenBuffer[tokenIdx++] = *cpToIn++;
      }
    }
  }
  // If we get to SourceEnd without a delimiter and the token buffer has
  // something in it return that. Else return 0 to show we found nothing
  if (tokenIdx) return tokenIdx;
  else return 0;
}

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
            rStack_push(0);            // Push 0 as our return address
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
        }
      } else if (isNumber(cTokenBuffer)) {
        _literal();
      } else {
        dStack_push(-13);
        _throw();
      }
    } else {

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
          rStack_push(0);                  // Push 0 as our return address
          ip = (cell_t *)w;          // set the ip to the XT (memory location)
          executeWord();
          if (errorCode) return;
        } else {
          function = flashDict[w - 1].function;
          function();
          if (errorCode) return;
        }
      } else if (isNumber(cTokenBuffer)) {
// Is something supposed to be here?        
      } else {
        dStack_push(-13);
        _throw();
        return;
      }
    }
  }
  cpToIn = cpSource;
}

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

/******************************************************************************/
/** freeMem returns the amount of free forth space left.                     **/
/******************************************************************************/
static unsigned int freeMem(void) {
  return (pHere - forthSpace);
}

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

/******************************************************************************/
/** Stack Functions                                                          **/
/**   Data Stack "stack" - A stack that may be used for passing parameters   **/
/**   between definitions. When there is no possibility of confusion, the    **/
/**   data stack is referred to as “the stack”. Contrast with return stack.  **/
/**                                                                          **/
/**   Return Stack "rStack" - A stack that may be used for program execution **/
/**   nesting, do-loop execution, temporary storage, and other purposes.     **/
/******************************************************************************/
/*********************************************/
/** Push (place) a cell onto the stack      **/
/*********************************************/
void dStack_push(cell_t value) {
  if (dStack.top < dStack.size) {
    dStack.d[++dStack.top] = value;
  } else {
    dStack.d[dStack.top] = -3;
    _throw();
  }
}

void rStack_push(cell_t value) {
  if (rStack.top < rStack.size) {
    rStack.d[++rStack.top] = value;
  } else {
    dStack_push(-5);
    _throw();
  }
}

/*********************************************/
/** Pop (remove) a cell from the stack      **/
/*********************************************/
cell_t dStack_pop(void) {
  if (dStack.top > 0) {
    return (dStack.d[dStack.top--]);
  } else {
    dStack_push(-4);
    _throw();
  }
  return 0;
}

cell_t rStack_pop(void) {
  if (rStack.top > 0) {
    return (rStack.d[rStack.top--]);
  } else {
    dStack_push(-6);
    _throw();
  }
  return 0;
}

/*********************************************/
/** Peek - copy the cell value from the Nth **/
/** position down from the top of the data  **/
/** stack. N = 0 is the top of the stack.   **/
/*********************************************/
cell_t dStack_peek(int n) {
  // Error Check: Make sure the depth doesn't
  // exceed the number of elements
  if (n < dStack.top) {
    return dStack.d[dStack.top - (n)];
  } else {
    Serial.println("Error: Depth too large!");
  }
  return 0;
}

cell_t rStack_peek(int n) {
  // Error Check: Make sure the depth doesn't
  // exceed the number of elements
  if (n < rStack.top) {
    return rStack.d[rStack.top - (n)];
  } else {
    Serial.println("Error: Depth too large!");
  }
  return 0;
}

/*********************************************/
/** isFull - return the true if the stack   **/
/** is full.                                **/
/*********************************************/ 
bool dStack_isFull(void) {
  if (dStack.top == dStack.size) {
    return true;
  } else {
    return false;
  }
}

bool rStack_isFull(void) {
  if (rStack.top == rStack.size) {
    return true;
  } else {
    return false;
  }
}

/*********************************************/
/** isEmpty - return the true if the stack  **/
/** is empty.                               **/
/*********************************************/ 
bool dStack_isEmpty(void) {
  if (dStack.top == 0) {
    return true;
  } else {
    return false;
  }
}

bool rStack_isEmpty(void) {
  if (rStack.top == 0) {
    return true;
  } else {
    return false;
  }
}

/*********************************************/
/** size - return the number items on the   **/
/** stack.                                  **/
/*********************************************/ 
uint8_t dStack_size(void) {
  return dStack.top;
}

uint8_t rStack_size(void) {
  return dStack.top;
}

/*********************************************/
/** clear - removes everything fromt the    **/
/** stack.                                  **/
/*********************************************/ 
void dStack_clear(void) {
  dStack.top = 0;
  dStack.d[0] = 0;
}

void rStack_clear(void) {
  dStack.top = 0;
  dStack.d[0] = 0;
}

/******************************************************************************/
/** String and Serial Functions                                              **/
/******************************************************************************/
void displayValue(void) {
  switch (base) {
    case DECIMAL: 
      Serial.print(w, DEC);
      break;
    case HEXIDECIMAL:
      Serial.print(hexidecimal_str); 
      Serial.print(w, HEX);
      break;
    case OCTAL:
      Serial.print(octal_str); 
      Serial.print(w, OCT);
      break;
    case BINARY:  
      Serial.print(binary_str); 
      Serial.print(w, BIN);
      break;
  }
  Serial.print(sp_str);
}

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


