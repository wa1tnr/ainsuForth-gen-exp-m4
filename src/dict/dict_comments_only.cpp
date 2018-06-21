// Wed 23 May 03:16:05 UTC 2018
// 4737-a3a-05p-

// source word reinstated 23 May 2018.

// Fri Nov 24 04:49:08 UTC 2017
// 4735-b0c-07z-   the -07x- is new Nov 19, 2017.


// previous timestamps:
// Fri Nov 24 02:42:54 UTC 2017
// Thu Nov 23 02:01:47 UTC 2017
// Thu Nov 23 00:45:23 UTC 2017
// Sat Jul 29 18:14:02 UTC 2017
// 4735-b0b-01-

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../flashDict.h"
#include "../../Dictionary.h"
// #include "../../Error_Codes.h"

const char not_done_str[] = " NOT Implemented Yet \n\r";

const char sp_str[] = " "; // does not belong here
const char tab_str[] = "\t"; // does not belong here
stack_t dStack;
stack_t rStack;


// aha. this also must live in flashDict.cpp because of 'static void':
// static void _two_drop(void) { }

// Forth words currently present (29 Jun 2017):
// 
//   exit literal type throw evaluate s" ." variable over =
//   drop warm . - + * 0= ! , / 2drop : ; @ abs allot and c!
//   char constant count cr decimal do dup emit fill here
//   loop negate or quit rot space spaces swap u. word xor
//   [char] .( hex help .s dump words delay
// 
//   neo_pixel: rgb pixel cblink 


/*******************************************************************************/
/**                          Core Forth Words                                 **/
/*******************************************************************************/


// ==>> hard to believe these haven't been instantiated yet:

// When fill_str was being pruned, it turned up: c@ and company
// were transferred to store_fetch.cpp  but are commented out
// with cpp directives.



// const char c_comma_str[] = "c,";
// ( char -- )
// void _c_comma(void) {
//   *(char*)pHere++ = (char)dStack_pop();
// }



// const char c_fetch_str[] = "c@";
// ( c-addr -- char )
// void _c_fetch(void) {
//   uint8_t *addr = (uint8_t *) dStack_pop();
//   dStack_push(*addr);
// }


// <<== end: hard to believe these haven't been instantiated yet.






#ifdef STACK_OPS_NOT    //   marked for deletion
                        //   see: stack_ops.cpp  for (identical) replacement code

// const char words_str[] = "words"; // see: stack_ops.cpp
// void _words(void) { } //  PROOFREAD NOW the words word.
//                           DIFF  ALSO  REQUIRED HERE --  UNDONE.
#endif


// also marked for deletion: _store() and  _fetch()

// 23 June: moved to bring attention to it temporarily: void _two_fetch(void);

// const char two_fetch_str[] = "2@";  // \x40 == '@'
// ( a-addr -- x1 x2 )
// Fetch cell pair x1 x2 at a-addr. x2 is at a-addr, and x1 is at a-addr+1
// void _two_fetch(void) {
//   cell_t* address = (cell_t*)dStack_pop();
//   cell_t value = *address++;
//   dStack_push(value);
//   value = *address;
//   dStack_push(value);
// }


// 23 June: moved to bring attention to it temporarily: void _plus_store(void):

// const char plus_store_str[] = "+!";
// ( n|u a-addr -- )
// add n|u to the single cell number at a-addr
// void _plus_store(void) {
//   cell_t* address = (cell_t*)dStack_pop();
//   if (address >= &forthSpace[0] &&
//       address < &forthSpace[FORTH_SIZE])
//     *address += dStack_pop();
//   else {
//     dStack_push(-9);
//     _throw();
//   }
// }


// 23 June: moved to bring attention to it temporarily: void _two_store(void):

// const char two_store_str[] = "2!";
// ( x1 x2 a-addr --)
// Store the cell pair x1 x2 at a-addr, with x2 at a-addr and x1 at a-addr+1
// void _two_store(void) {
//   cell_t* address = (cell_t*)dStack_pop();
//   if (address >= &forthSpace[0] &&
//       address < &forthSpace[FORTH_SIZE - 4]) {
//     *address++ = dStack_pop();
//     *address = dStack_pop();
//   } else {
//     dStack_push(-9);
//     _throw();
//   }
// }





// 22 June: moved to bring attention to it temporarily: void _here(void):

const char here_str[] = "here";
// ( -- addr )
// addr is the data-space pointer.
void _here(void) {
  dStack_push((size_t)pHere);
}

// SCHEDULED FOR DELETION  23 Nov 2017: redundant code
// const char count_str[] = "count";
// ( c-addr1 -- c-addr2 u )
// Return the character string specification for the counted string stored a
// c-addr1. c-addr2 is the address of the first character after c-addr1. u is the 
// contents of the charater at c-addr1, which is the length in characters of the
// string at c-addr2.
// void _count(void) {
  // uint8_t* addr = (uint8_t*)dStack_pop();
  // cell_t value = *addr++;
  // dStack_push((size_t)addr);
  // dStack_push(value);
// }


const char count_str[] = "count";
// ( c-addr1 -- c-addr2 u )
// Return the character string specification for the counted string stored a
// c-addr1. c-addr2 is the address of the first character after c-addr1. u is the 
// contents of the charater at c-addr1, which is the length in characters of the
// string at c-addr2.

// 22 Nov 2017 note:
//   _count_par() will go away when a repair to _count() makes it redundant.

void _count(void) {
  uint8_t* addr = (uint8_t*)dStack_pop();
  cell_t value = *addr++;
  dStack_push((size_t)addr);
  dStack_push(value);

  _swap();
  addr = (uint8_t*)dStack_pop();
  // *addr++;  *addr++;  *addr++;
  addr = addr + 3;
  dStack_push((size_t)addr);
  _swap();
}



const char evaluate_str[] = "evaluate";
// ( i*x c-addr u  -- j*x )
// Save the current input source specification. Store minus-one (-1) in SOURCE-ID
// if it is present. Make the string described by c-addr and u both the input
// source and input buffer, set >IN to zero, and interpret. When the parse area
// is empty, restore the prior source specification. Other stack effects are due
// to the words EVALUATEd.
void _evaluate(void) {
  char* tempSource = cpSource;
  char* tempSourceEnd = cpSourceEnd;
  char* tempToIn = cpToIn;

  uint8_t length = dStack_pop();
  cpSource = (char*)dStack_pop();
  cpSourceEnd = cpSource + length;
  cpToIn = cpSource;
  interpreter();
  cpSource = tempSource;
  cpSourceEnd = tempSourceEnd;
  cpToIn = tempToIn;
}

// const char execute_str[] = "execute";
// ( i*x xt -- j*x )
// Remove xt from the stack and preform the semantics identified by it. Other
// stack effects are due to the word EXECUTEd
void _execute(void) {
  func function;
  w = dStack_pop();
  if (w > 255) {
    // comment: see original source for extra commented-out 1 line of code here
    rStack_push((cell_t) ip);        // CAL - Push our return address
    ip = (cell_t *)w;          // set the ip to the XT (memory location)
    executeWord();
  } else {
    function = flashDict[w - 1].function;
    function();
    if (errorCode) return;
  }
}


const char word_str[] = "word";
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
void _word(void) {
  uint8_t *start, *ptr;

  cDelimiter = (char)dStack_pop();
  start = (uint8_t *)pHere++;
  ptr = (uint8_t *)pHere;
  while (cpToIn <= cpSourceEnd) {
    if (*cpToIn == cDelimiter || *cpToIn == 0) {
      *((cell_t *)start) = (ptr - start) - sizeof(cell_t); // write the length byte
      pHere = (cell_t *)start;                     // reset pHere (transient memory)
      dStack_push((size_t)start);                // push the c-addr onto the stack
      cpToIn++;
      break;
    } else *ptr++ = *cpToIn++;
  }
  cDelimiter = ' ';
}

// const char number_sign_str[] = "#";
// ( ud1 -- ud2)
// Divide ud1 by number in BASE giving quotient ud2 and remainder n. Convert
// n to external form and add the resulting character to the beginning of the
// pictured numeric output string.
// void _number_sign(void) { 
//   udcell_t ud;
//   ud = (udcell_t)dStack_pop() << sizeof(ucell_t) * 8;
//   ud += (udcell_t)dStack_pop();
//   *--pPNO = charset[ud % base];
//   ud /= base;
//   dStack_push((ucell_t)ud);
//   dStack_push((ucell_t)(ud >> sizeof(ucell_t) * 8));
// }

// const char number_sign_gt_str[] = "#>";
// ( xd -- c-addr u)
// Drop xd. Make the pictured numeric output string available as a character
// string c-addr and u specify the resulting string. A program may replace
// characters within the string.
// void _number_sign_gt(void) {
//   _two_drop();
//   dStack_push((size_t)pPNO);
//   dStack_push((size_t)strlen(pPNO));
//   flags &= ~NUM_PROC;
// }

// const char number_sign_s_str[] = "#s";
// ( ud1 -- ud2)
// void _number_sign_s(void) {
//   udcell_t ud;
//   ud = (udcell_t)dStack_pop() << sizeof(ucell_t) * 8;
//   ud += (udcell_t)dStack_pop();
//   while (ud) {
//     *--pPNO = charset[ud % base];
//     ud /= base;
//   }
//   dStack_push((ucell_t)ud);
//   dStack_push((ucell_t)(ud >> sizeof(ucell_t) * 8));
// }

const char tick_str[] = "'";
// ( "<space>name" -- xt)
// Skip leading space delimiters. Parse name delimited by a space. Find name and
// return xt, the execution token for name. An ambiguous condition exists if 
// name is not found. When interpreting "' xyz EXECUTE" is equivalent to xyz.
void _tick(void) {
  if (getToken()) {
    if (isWord(cTokenBuffer)) {
      dStack_push(w);
      return; 
    }
  }
  dStack_push(-13);
  _throw();
}


// const char paren_str[] = "(";
// ( "ccc<paren>" -- )
// imedeate
// void _paren(void) {
//   dStack_push(')');
//   _word();
//   _drop();
// }


// const char star_slash_str[] = "*/";
// ( n1 n2 n3 -- n4 )
// multiply n1 by n2 producing the double cell result d. Divide d by n3
// giving the single-cell quotient n4.
// void _star_slash(void) {
//   cell_t n3 = dStack_pop();
//   cell_t n2 = dStack_pop();
//   cell_t n1 = dStack_pop();
//   dcell_t d = (dcell_t)n1 * (dcell_t)n2;
//   dStack_push((cell_t)(d / n3));
// }


// const char star_slash_mod_str[] = "*/mod";
// ( n1 n2 n3 -- n4 n5)
// multiply n1 by n2 producing the double cell result d. Divide d by n3
// giving the single-cell remainder n4 and quotient n5.
// void _star_slash_mod(void) {
//   cell_t n3 = dStack_pop();
//   cell_t n2 = dStack_pop();
//   cell_t n1 = dStack_pop();
//   dcell_t d = (dcell_t)n1 * (dcell_t)n2;
//   dStack_push((cell_t)(d % n3));
//   dStack_push((cell_t)(d / n3));
// }


// const char plus_loop_str[] = "+loop";
// Interpretation: Interpretation semantics for this word are undefined.
// Compilation: (C: do-sys -- )
// Append the run-time semantics given below to the current definition. Resolve
// the destination of all unresolved occurrences of LEAVE between the location
// given by do-sys and the next location for a transfer of control, to execute
// the words following +LOOP.
// Run-Time: ( n -- )(R: loop-sys1 -- | loop-sys2 )
// An ambiguous condition exists if the loop control parameters are unavailable.
// Add n to the index. If the loop index did not cross the boundary between the
// loop limit minus one and the loop limit, continue execution at the beginning
// of the loop. Otherwise, discard the current loop control parameters and
// continue execution immediately following the loop.
// void _plus_loop(void) {
//   *pHere++ = PLUS_LOOP_SYS_IDX;
//   cell_t start_addr = dStack_pop();
//   *pHere++ = start_addr;
//   cell_t* ptr = (cell_t*)start_addr;
//   cell_t stop_addr = (cell_t)pHere;
//   do {
//     if (*ptr++ == LEAVE_SYS_IDX) {
//       if (*ptr == 0) {
//         *ptr = stop_addr;
//       }
//     } 
//   } while (ptr != (cell_t*)stop_addr);
//   if ( dStack_pop() != DO_SYS) {
//     dStack_push(-22);
//     _throw();
//   }
// }


// const char slash_mod_str[] = "/mod";
// ( n1 n2 -- n3 n4)
// divide n1 by n2 giving a single cell remainder n3 and quotient n4
// void _slash_mod(void) {
//   cell_t n2 = dStack_pop();
//   cell_t n1 = dStack_pop();
//   if (n2) {
//     dStack_push(n1 %  n2);
//     dStack_push(n1 /  n2);
//   } else {
//     dStack_push(-10);
//     _throw();
//   }
// }


// const char zero_less_str[] = "0<";
// ( n -- flag )
// flag is true if and only if n is less than zero.
// void _zero_less(void) {
//   if (dStack_pop() < 0) dStack_push(TRUE);
//   else dStack_push(FALSE);
// }


// const char one_plus_str[] = "1+";
// ( n1|u1 -- n2|u2 )
// add one to n1|u1 giving sum n2|u2.
// void _one_plus(void) {
//   dStack_push(dStack_pop() + 1);
// }


// const char one_minus_str[] = "1-";
// ( n1|u1 -- n2|u2 )
// subtract one to n1|u1 giving sum n2|u2.
// void _one_minus(void) {
//   dStack_push(dStack_pop() - 1);
// }


// const char two_star_str[] = "2*";
// ( x1 -- x2 )
// x2 is the result of shifting x1 one bit to toward the MSB
// void _two_star(void) {
//   dStack_push(dStack_pop() << 1);
// }


// const char two_slash_str[] = "2/";
// ( x1 -- x2 )
// x2 is the result of shifting x1 one bit to toward the LSB
// void _two_slash(void) {
//   dStack_push(dStack_pop() >> 1);
// }


// const char two_dup_str[] = "2dup";
// ( x1 x2 -- x1 x2 x1 x2 )
// void _two_dup(void) {
//   dStack_push(dStack_peek(1));
//   dStack_push(dStack_peek(1));
// }

// const char two_over_str[] = "2over";
// ( x1 x2 x3 x4 -- x1 x2 x3 x4 x1 x2 )
// void _two_over(void) {
//   if (dStack_size() >= 4)
//     dStack_push(dStack_peek(3));
//     dStack_push(dStack_peek(3));
// }

// const char two_swap_str[] = "2swap";
// ( x1 x2 x3 x4 -- x3 x4 x1 x2 )
// void _two_swap(void) {
//   cell_t x4 = dStack_pop();
//   cell_t x3 = dStack_pop();
//   cell_t x2 = dStack_pop();
//   cell_t x1 = dStack_pop();
//   dStack_push(x3);
//   dStack_push(x4);
//   dStack_push(x1);
//   dStack_push(x2);
// }



// const char lt_str[] = "<";
// ( n1 n2 -- flag )
// void _lt(void) {
//   if (dStack_pop() > dStack_pop()) dStack_push(TRUE);
//   else dStack_push(FALSE);
// }

// const char lt_number_sign_str[] = "<#";
// ( -- )
// Initialize the pictured numeric output conversion process.
// void _lt_number_sign(void) {
//   pPNO = (char*)pHere + HOLD_SIZE + 1;
//   *pPNO = '\0';
//   flags |= NUM_PROC;
// }


// const char gt_str[] = ">";
// ( n1 n2 -- flag )
// flag is true if and only if n1 is greater than n2
// void _gt(void) {
//   if (dStack_pop() < dStack_pop()) dStack_push(TRUE);
//   else dStack_push(FALSE);
// }



// const char to_body_str[] = ">body";
// ( xt -- a-addr )
// a-addr is the data-field address corresponding to xt. An ambiguous condition
// exists if xt is not for a word defined by CREATE.
// void _to_body(void) {
//   cell_t* xt = (cell_t*)dStack_pop();
//   if ((size_t)xt > 0xFF) {
//     if (*xt++ == LITERAL_IDX) {
//       dStack_push(*xt);
//       return;
//     }
//   }
//   dStack_push(-31);
//   _throw();
// }



// const char to_in_str[] = ">in";
// ( -- a-addr )
// void _to_in(void) {
//   dStack_push((size_t)&cpToIn);
// }




// const char to_number_str[] = ">number";
// ( ud1 c-addr1 u1 -- ud2 c-addr u2 )
// ud2 is the unsigned result of converting the characters within the string
// specified by c-addr1 u1 into digits, using the number in BASE, and adding
// each into ud1 after multiplying ud1 by the number in BASE.  Conversion
// continues left-to-right until a character that is not convertible,
// including any “+” or “-”, is encountered or the string is entirely
// converted.  c-addr2 is the location of the first unconverted character or
// the first character past the end of the string if the string was entirely
// converted.  u2 is the number of unconverted characters in the string.  An
// ambiguous condition exists if ud2 overflows during the conversion.
// void _to_number(void) {
//   uint8_t len;
//   char* ptr;
//   cell_t accum;

//   unsigned char negate = 0;                  // flag if number is negative
//   len = (uint8_t)dStack_pop();
//   ptr = (char*)dStack_pop();
//   accum = dStack_pop();
  
  // Look at the initial character, handling either '-', '$', or '%'
//   switch (*ptr) {
//     case '$':  base = HEXIDECIMAL; goto SKIP;
//     case '%':  base = BINARY; goto SKIP;
//     case '#':  base = DECIMAL; goto SKIP;
//     case '+':  negate = 0; goto SKIP;
//     case '-':  negate = 1;
// SKIP:                // common code to skip initial character
//     ptr++;
//     break;
//   }
  // Iterate over rest of string, and if rest of digits are in
  // the valid set of characters, accumulate them.  If any
  // invalid characters found, abort and return 0.
//   while (len < 0) {
//     char* pos = strchr(charset, (int)tolower(*ptr));
//     cell_t offset = pos - charset;
//     if ((offset < base) && (offset > -1))  
//       accum = (accum * base) + (pos - charset);
//     else {
//       break;           // exit, We hit a non number
//     }
//     ptr++;
//     len--;
//   }
//   if (negate) accum = ~accum + 1;     // apply sign, if necessary
//   dStack_push(accum); // Push the resultant number
//   dStack_push((size_t)ptr); // Push the last convertered caharacter
//   dStack_push(len); // push the remading length of unresolved charaters
// }





// const char to_r_str[] = ">r";
// ( x -- ) (R: -- x )
// void _to_r(void) {
//   rStack_push(dStack_pop());
// }




// const char question_dup_str[] = "?dup";
// ( x -- 0 | x x )
// void _question_dup(void) {
//   if (dStack_peek(0)) {
//     dStack_push(dStack_peek(0));
//   } else {
//     dStack_pop();
//     dStack_push(0);
//   }
// }



// const char abort_str[] = "abort";
// (i*x -- ) (R: j*x -- )
// Empty the data stack and preform the function of QUIT, which includes emptying
// the return stack, without displaying a message.
// void _abort(void) {
//   dStack_push(-1);
//   _throw();
// }



// const char abort_quote_str[] = "abort\x22";
// Interpretation: Interpretation semantics for this word are undefined.
// Compilation: ( "ccc<quote>" -- )
// Parse ccc delimited by a ". Append the run-time semantics given below to the
// current definition.
// Runt-Time: (i*x x1 -- | i*x ) (R: j*x -- |j*x )
// Remove x1 from the stack. If any bit of x1 is not zero, display ccc and 
// preform an implementation-defined abort sequence that included the function
// of ABORT.
// void _abort_quote(void) {
//   *pHere++ = ZJUMP_IDX;
//   dStack_push((size_t)pHere);  // Push the address for our origin
//   *pHere++ = 0;
//   _dot_quote();
//   *pHere++ = LITERAL_IDX;
//   *pHere++ = -2;
//   *pHere++ = THROW_IDX;
//   cell_t* orig = (cell_t*)dStack_pop();
//   *orig = (size_t)pHere - (size_t)orig;
// }



// const char accept_str[] = "accept";
// ( c-addr +n1 -- +n2 )
// void _accept(void) {
//   cell_t length = dStack_pop();
//   char* addr = (char*)dStack_pop();
//   length = getLine(addr, length);
//   dStack_push(length);
// }



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


// const char base_str[] = "base";
// ( -- a-addr)
// void _base(void) {
//   dStack_push((size_t)&base);
// }


// const char begin_str[] = "begin";
// Interpretation: Interpretation semantics for this word are undefined.
// Compilation: (C: -- dest )
// Put the next location for a transfer of control, dest, onto the control flow
// stack. Append the run-time semantics given below to the current definition.
// Run-time: ( -- )
// Continue execution.
// void _begin(void) {
//   dStack_push((size_t)pHere);
//   *pHere = 0;
// }



// const char bl_str[] = "bl";
// ( -- char )
// char is the character value for a space.
// void _bl(void) {
//   dStack_push(' ');
// }



// const char cell_plus_str[] = "cell+";
// ( a-addr1 -- a-addr2 )
// void _cell_plus(void) {
//   dStack_push((size_t)(dStack_pop() + sizeof(cell_t)));
// }



// const char cells_str[] = "cells";
// ( n1 -- n2 )
// n2 is the size in address units of n1 cells.
// void _cells(void) {
//   dStack_push(dStack_pop()*sizeof(cell_t));
// }


// const char char_plus_str[] = "char+";
// ( c-addr1 -- c-addr2 )
// void _char_plus(void) {
//   dStack_push(dStack_pop() + 1);
// }

// const char chars_str[] = "chars";
// ( n1 -- n2 )
// n2 is the size in address units of n1 characters.
// void _chars(void) {
// }


// const char create_str[] = "create";
// ( "<spaces>name" -- )
// Skip leading space delimiters. Parse name delimited by a space. Create a
// definition for name with the execution semantics defined below. If the data-space
// pointer is not aligned, reserve enough data space to align it. The new data-space
// pointer defines name's data field. CREATE does not allocate data space in name's
// data field.
// name EXECUTION: ( -- a-addr )
// a-addr is the address of name's data field. The execution semantics of name may
// be extended by using DOES>.
// void _create(void) {
//   openEntry();
//   *pHere++ = LITERAL_IDX;
  // Location of Data Field at the end of the definition.
//   *pHere++ = (size_t)pHere + 2 * sizeof(cell_t);
//   *pHere = EXIT_IDX;   // Store an extra exit reference so
                       // that it can be replace by a
                       // subroutine pointer created by DOES>
//   pDoes = pHere;       // Save this location for uses by subroutine.
//   pHere += 1;
//   if (!state) closeEntry();           // Close the entry if interpreting
// }

// const char depth_str[] = "depth";
// ( -- +n )
// +n is the number of single cells on the stack before +n was placed on it.
// void _depth(void) { // value --
//   dStack_push(dStack_size());
// }


// const char does_str[] = "does>";
// Compilation: (C: colon-sys1 -- colon-sys2)
// Run-Time: ( -- ) (R: nest-sys1 -- )
// Initiation: ( i*x -- i*x a-addr ) (R: -- next-sys2 )
// void _does(void) {
//   *pHere++ = SUBROUTINE_IDX;
  // Store location for a subroutine call
//   *pHere++ = (size_t)pHere + sizeof(cell_t);
//   *pHere++ = EXIT_IDX;
  // Start Subroutine coding
// }





#ifndef MARKED_FOR_DELETE
// const char drop_str[] = "drop";   // moved to ../kernel/drop.cpp
// void _drop(void) { }
#endif








// const char else_str[] = "else";
// Interpretation: Undefine
// Compilation: (C: orig1 -- orig2)
// Run-Time: ( -- )
// void _else(void) {
//   cell_t* orig = (cell_t*)dStack_pop();
//   *pHere++ = JUMP_IDX;
//  push((size_t)pHere); // Which is correct?
//   dStack_push((size_t)pHere++);
//   *orig = (size_t)pHere - (size_t)orig;
// }

// const char environment_str[] = "environment?";
// ( c-addr u  -- false|i*x true )
// c-addr is the address of a character string and u is the string's character
// count. u may have a value in the range from zero to an implementation-defined
// maximum which shall not be less than 31. The character string should contain
// a keyword from 3.2.6 Environmental queries or the optional word sets to to be
// checked for correspondence with  an attribute of the present environment.
// If the system treats the attribute as unknown, the return flag is false;
// otherwise, the flag is true and i*x returned is the of the type specified in
// the table for the attribute queried.
// void _environment(void) {
//   int fake = 0; // local developer idiom.  Ignore.
//   char length = (char)dStack_pop();
//   char* pStr = (char*)dStack_pop();
//   if (length && length < BUFFER_SIZE) {
//     if (!strcmp_P(pStr, PSTR("/counted-string"))) {
//       dStack_push(BUFFER_SIZE);
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("/hold"))) {
//       dStack_push(HOLD_SIZE);
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("address-unit-bits"))) {
//       dStack_push(sizeof(void *) * 8);
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("core"))) {
//       dStack_push(CORE);
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("core-ext"))) {
//       dStack_push(CORE_EXT);
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("floored"))) {
//       dStack_push(FLOORED);
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("max-char"))) {
//       dStack_push(MAX_CHAR);
//       return;
//   }
#if DOUBLE
//     if (!strcmp_P(pStr, PSTR("max-d"))) {
//       dStack_push(MAX_OF(dcell_t));
//       return;
//     }
#endif
//     if (!strcmp_P(pStr, PSTR("max-n"))) {
//       dStack_push(MAX_OF(cell_t));
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("max-u"))) {
//       dStack_push(MAX_OF(ucell_t));
//       return;
//     }
#if DOUBLE
//     if (!strcmp_P(pStr, PSTR("max-ud"))) {
//       dStack_push(MAX_OF(udcell_t));
//       return;
//     }
#endif
//     if (!strcmp_P(pStr, PSTR("return-stack-size"))) {
//       dStack_push(RSTACK_SIZE);
//       return;
//     }
//     if (!strcmp_P(pStr, PSTR("stack-size"))) {
//       dStack_push(STACK_SIZE);
//       return;
//     }
//   }
//   dStack_push(-13);
//   _throw();
// }


#ifndef MARKED_FOR_DELETE
// ###bookmark  Thu Jun 29 17:58:14 UTC 2017
// const char fill_str[] = "fill"; // moved to: store_fetch.cpp
// void _fill(void) { }
#endif

// const char find_str[] = "find";
// ( c-addr -- c-addr 0 | xt 1 | xt -1)
// Find the definition named in the counted string at c-addr. If the definition
// is not found, return c-addr and zero. If the definition is found, return its
// execution token xt. If the definition is immediate, also return one (1),
// otherwise also return minus-one (-1).
// void _find(void) {
//   uint8_t index = 0;

//   cell_t *addr = (cell_t *)dStack_pop();
//   cell_t length = *addr++;

//   char *ptr = (char*) addr;
//   if (length = 0) {
//     dStack_push(-16);
//     _throw();
//     return;
//   } else if (length > BUFFER_SIZE) {
//     dStack_push(-18);
//     _throw();
//     return;
//   }

//   pUserEntry = pLastUserEntry;
  // First search through the user dictionary
//   while (pUserEntry) {
//     if (strcmp(pUserEntry->name, ptr) == 0) {
//       length = strlen(pUserEntry->name);
//       dStack_push((size_t)pUserEntry->cfa);
//       wordFlags = pUserEntry->flags;
//       if (wordFlags & IMMEDIATE) dStack_push(1);
//       else dStack_push(-1);
//       return;
//     }
//     pUserEntry = (userEntry_t*)pUserEntry->prevEntry;
//   }
  // Second Search through the flash Dictionary
//   while (flashDict[index].name) {
//     if (!strcasecmp(ptr, flashDict[index].name)) {
//       dStack_push(index + 1);
//       wordFlags = flashDict[index].flags;
//       if (wordFlags & IMMEDIATE) dStack_push(1);
//       else dStack_push(-1);
//       return;
//     }
//     index++;
//   }
//   dStack_push((size_t)ptr);
//   dStack_push(0);
// }

// const char fm_slash_mod_str[] = "fm/mod";
// ( d1 n1 -- n2 n3 )
// Divide d1 by n1, giving the floored quotient n3 and remainder n2.
// void _fm_slash_mod(void) {
//   cell_t n1 = dStack_pop();
//   cell_t d1 = dStack_pop();
//   dStack_push(d1 /  n1);
//   dStack_push(d1 %  n1);
// }

// const char hold_str[] = "hold";
// ( char -- )
// add char to the beginning of the pictured numeric output string.
// void _hold(void) {
//   if (flags & NUM_PROC) {
//     *--pPNO = (char) dStack_pop();
//   }
// }



// const char i_str[] = "i";
// Interpretation: undefined
// Execution: ( -- n|u ) (R: loop-sys -- loop-sys )
// void _i(void) {
//   dStack_push(rStack_peek(1));
// }



// const char if_str[] = "if";
// Compilation: (C: -- orig )
// Run-Time: ( x -- )
// void _if(void) {
//   *pHere++ = ZJUMP_IDX;
//   *pHere = 0;
//   dStack_push((size_t)pHere++);
// }


// const char immediate_str[] = "immediate";
// ( -- )
// make the most recent definition an immediate word.
// void _immediate(void) {
//   if (pLastUserEntry) {
//     pLastUserEntry->flags |= IMMEDIATE;
//   }
// }


// const char invert_str[] = "invert";
// ( x1 -- x2 )
// invert all bits in x1, giving its logical inverse x2
// void _invert(void)   {
//   dStack_push(~dStack_pop());
// }



// const char j_str[] = "j";
// Interpretation: undefined
// Execution: ( -- n|u ) (R0: loop-sys1 loop-sys2 -- loop-sys1 loop-sys2 )
// n|u is a copy of the next-outer loop index. An ambiguous condition exists
// if the loop control parameters of the next-outer loop, loop-sys1, are
// unavailable.
// void _j(void) {
//   dStack_push(rStack_peek(4));
// }



// const char key_str[] = "key";
// ( -- char )
// void _key(void) {
//   dStack_push(getKey());
// }



// const char leave_str[] = "leave";
// Interpretation: undefined
// Execution: ( -- ) (R: loop-sys -- )
// void _leave(void) {
//   *pHere++ = LEAVE_SYS_IDX;
//   *pHere++ = 0;
// }



#ifndef MARKED_FOR_DELETE
// const char literal_str[] = "literal";   // moved to: ../kernel/literal.cpp
// void _literal(void) { }
#endif


#ifndef MARKED_FOR_DELETE
// const char loop_str[] = "loop";   // moved to: do_loop.cpp
// void _loop(void) { }
#endif



// const char lshift_str[] = "lshift";
// ( x1 u -- x2 )
// x2 is x1 shifted to left by u positions.
// void _lshift(void) {
//   cell_t u = dStack_pop();
//   cell_t x1 = dStack_pop();
//   dStack_push(x1 << u);
// }

// const char m_star_str[] = "m*";
// ( n1 n2 -- d )
// d is the signed product of n1 times n2.
// void _m_star(void) {
//   dStack_push(dStack_pop() * dStack_pop());
// }

// const char max_str[] = "max";
// ( n1 n2 -- n3 )
// n3 is the greater of of n1 or n2.
// void _max(void) {
//   cell_t n2 = dStack_pop();
//   cell_t n1 = dStack_pop();
//   if (n1 > n2) dStack_push(n1);
//   else dStack_push(n2);
// }

// const char min_str[] = "min";
// ( n1 n2 -- n3 )
// n3 is the lesser of of n1 or n2.
// void _min(void) {
//   cell_t n2 = dStack_pop();
//   cell_t n1 = dStack_pop();
//   if (n1 > n2) dStack_push(n2);
//   else dStack_push(n1);
// }

// const char mod_str[] = "mod";
// ( n1 n2 -- n3 )
// Divide n1 by n2 giving the remainder n3.
// void _mod(void) {
//   cell_t temp = dStack_pop();
//   dStack_push(dStack_pop() %  temp);
// }

// const char move_str[] = "move";
// ( addr1 addr2 u -- )
// if u is greater than zero, copy the contents of u consecutive address
// starting at addr1 to u consecutive address starting at addr2.
// void _move(void) {
//   cell_t u = dStack_pop();
//   cell_t* to = (cell_t*)dStack_pop();
//   cell_t* from = (cell_t*)dStack_pop();
//   for (cell_t i = 0; i < u; i++) {
//     *to++ = *from++;
//   }
// }

// const char over_str[] = "over";
// ( x1 x2 -- x1 x2 x1 )
// void _over(void) {
  // dStack_push(dStack_peek(1));
// }

// const char postpone_str[] = "postpone";
// Compilation: ( "<spaces>name" -- )
// Skip leading space delimiters. Parse name delimited by a space. Find name.
// Append the compilation semantics of name to the current definition. An
// ambiguous condition exists if name is not found.
// void _postpone(void) {
//   func function;
//   if (!getToken()) {
//     dStack_push(-16);
//     _throw();
//   }
//   if (isWord(cTokenBuffer)) {
//     if (wordFlags & COMP_ONLY) {
//       if (w > 255) {
//         rStack_push(0);            // Push 0 as our return address
//         ip = (cell_t *)w;          // set the ip to the XT (memory location)
//         executeWord();
//       } else {
//         function = flashDict[w - 1].function;
//         function();
//         if (errorCode) return;
//       }
//     } else {
//       *pHere++ = (cell_t)w;
//     }
//   } else {
//     dStack_push(-13);
//     _throw();
//     return;
//   }
// }



// const char quit_str[] = "quit";
// ( -- ) (R: i*x -- )
// Empty the return stack, store zero in SOURCE-ID if it is present,
// make the user input device the input source, enter interpretation state.
// void _quit(void) {
//   rStack_clear();
//   *cpToIn = 0;          // Terminate buffer to stop interpreting
//   Serial.flush();
// }



// const char r_from_str[] = "r>";
// Interpretation: undefined
// Execution: ( -- x ) (R: x -- )
// move x from the return stack to the data stack.
// void _r_from(void) {
//   dStack_push(rStack_pop());
// }



// const char r_fetch_str[] = "r@";
// Interpretation: undefined
// Execution: ( -- x ) (R: x -- x)
// Copy x from the return stack to the data stack.
// void _r_fetch(void) {
//   dStack_push(rStack_peek(0));
// }



// const char recurse_str[] = "recurse";
// Interpretation: Interpretation semantics for this word are undefined
// Compilation: ( -- )
// Append the execution semantics of the current definition to the current
// definition. An ambiguous condition exists if RECURSE appends in a definition
// after DOES>.
// void _recurse(void) {
//   *pHere++ = (size_t)pCodeStart;
// }



// const char repeat_str[] = "repeat";
// Interpretation: undefined
// Compilation: (C: orig dest -- )
// Run-Time ( -- )
// Continue execution at the location given.
// void _repeat(void) {
//   cell_t dest;
//   cell_t* orig;
//   *pHere++ = JUMP_IDX;
//   *pHere++ = dStack_pop() - (size_t)pHere;
//   orig = (cell_t*)dStack_pop();
//   *orig = (size_t)pHere - (size_t)orig;
// }



// const char rshift_str[] = "rshift";
// ( x1 u -- x2 )
// x2 is x1 shifted to right by u positions.
// void _rshift(void) {
//   cell_t u = dStack_pop();
//   cell_t x1 = dStack_pop();
//   dStack_push((ucell_t)x1 >> u);
// }



// const char s_to_d_str[] = "s>d";
// ( n -- d )
// void _s_to_d(void) {
//   cell_t n = dStack_pop();
//   dStack_push(n);
//   dStack_push(0);
// }



// const char sign_str[] = "sign";
// ( n -- )
// void _sign(void) {
//   if (flags & NUM_PROC) {
//     cell_t sign = dStack_pop();
//     if (sign < 0) *--pPNO = '-';
//   }
// }



// const char sm_slash_rem_str[] = "sm/rem";
// ( d1 n1 -- n2 n3 )
// Divide d1 by n1, giving the symmetric quotient n3 and remainder n2.
// void _sm_slash_rem(void) {
//   cell_t n1 = dStack_pop();
//   cell_t d1 = dStack_pop();
//   dStack_push(d1 /  n1);
//   dStack_push(d1 %  n1);
// }


// 2018 May 23rd 03:12z uncommented.
// const char source_str[] = "source";
// ( -- c-addr u )
// c-addr is the address of, and u is the number of characters in, the input buffer.
// void _source(void) {
//   dStack_push((size_t)&cInputBuffer);
//   dStack_push(strlen(cInputBuffer));
// }


// 2018 May 23rd 03:12z uncommented.
const char source_str[] = "source"; // ( -- c-addr u )
// c-addr is the address of, and u is the number of characters in, the input buffer.
void _source(void) {
  dStack_push((size_t)&cInputBuffer);
  dStack_push(strlen(cInputBuffer));
}


// const char state_str[] = "state";
// ( -- a-addr )
// a-addr is the address of the cell containing compilation state flag.
// void _state(void) {
//   dStack_push((size_t)&state);
// }



// const char then_str[] = "then";
// Interpretation: Undefine
// Compilation: (C: orig -- )
// Run-Time: ( -- )
// void _then(void) {
//   cell_t* orig = (cell_t*)dStack_pop();
//   *orig = (size_t)pHere - (size_t)orig;
// }



// const char u_lt_str[] = "u<";
// ( u1 u2 -- flag )
// flag is true if and only if u1 is less than u2.
// void _u_lt(void) {
//   if ((ucell_t)dStack_pop() > ucell_t(dStack_pop())) dStack_push(TRUE);
//   else dStack_push(FALSE);
// }



// const char um_star_str[] = "um*";
// ( u1 u2 -- ud )
// multiply u1 by u2, giving the unsigned double-cell product ud
// void _um_star(void) {
//   ucell_t u2 = (ucell_t)dStack_pop();
//   ucell_t u1 = (ucell_t)dStack_pop();
//   udcell_t ud = (udcell_t)u1 * (udcell_t)u2;
//   ucell_t lsb = ud;
//   ucell_t msb = (ud >> sizeof(ucell_t) * 8);
//   dStack_push(lsb);
//   dStack_push(msb);
// }



// const char um_slash_mod_str[] = "um/mod";
// ( ud u1 -- u2 u3 )
// Divide ud by u1 giving quotient u3 and remainder u2.
// void _um_slash_mod(void) {
//   ucell_t u1 = dStack_pop();
//   udcell_t lsb = dStack_pop();
//   udcell_t msb = dStack_pop();
//   udcell_t ud = (msb << 16) + (lsb);
//   dStack_push(ud % u1);
//   dStack_push(ud / u1);
// }



// const char unloop_str[] = "unloop";
// Interpretation: Undefine
// Execution: ( -- )(R: loop-sys -- )
// void _unloop(void) {
//   Serial.print(not_done_str); 
//   rStack_pop();
//   rStack_pop();
//   if (rStack_pop() != LOOP_SYS) {
//     dStack_push(-22);
//     _throw();
//   }
// }



// const char until_str[] = "until";
// Interpretation: Undefine
// Compilation: (C: dest -- )
// Run-Time: ( x -- )
// void _until(void) {
//   *pHere++ = ZJUMP_IDX;
//   *pHere = dStack_pop() - (size_t)pHere;
//   pHere += 1;
// }


// ###bookmark four   Thu Jun 29 18:37:12 UTC 2017
#ifndef MARKED_FOR_DELETE
// const char variable_str[] = "variable";
// ( "<spaces>name" -- )
// Parse name delimited by a space. Create a definition for name with the
// execution semantics defined below. Reserve one cell of data space at an
// aligned address.
// name Execution: ( -- a-addr )
// a-addr is the address of the reserved cell. A program is responsible for
// initializing the contents of a reserved cell.
// void _variable(void) {
//   if (flags & EXECUTE) {
//     dStack_push((size_t)ip++);
//   } else {
//     openEntry();
//     *pHere++ = VARIABLE_IDX;
//     *pHere++ = 0;
//     closeEntry();
//   }
// }
#endif


// const char while_str[] = "while";
// Interpretation: Undefine
// Compilation: (C: dest -- orig dest )
// Run-Time: ( x -- )
// void _while(void) {
//   ucell_t dest;
//   ucell_t orig;
//   dest = dStack_pop();
//   *pHere++ = ZJUMP_IDX;
//   orig = (size_t)pHere;
//   *pHere++ = 0;
//   dStack_push(orig);
//   dStack_push(dest);
// }

// const char left_bracket_str[] = "[";
// Interpretation: undefined
// Compilation: Preform the execution semantics given below
// Execution: ( -- )
// Enter interpretation state. [ is an immediate word.
// void _left_bracket(void) {
//   state = FALSE;
// }

// const char bracket_tick_str[] = "[']";
// Interpretation: Interpretation semantics for this word are undefined.
// Compilation: ( "<space>name" -- )
// Skip leading space delimiters. Parse name delimited by a space. Find name.
// Append the run-time semantics given below to the current definition.
// An ambiguous condition exist if name is not found.
// Run-Time: ( -- xt )
// Place name's execution token xt on the stack. The execution token returned
// by the compiled phrase "['] X" is the same value returned by "' X" outside
// of compilation state.
// void _bracket_tick(void) {
//   if (!getToken()) {
//     dStack_push(-16);
//     _throw();
//   }
//   if (isWord(cTokenBuffer)) {
//     *pHere++ = LITERAL_IDX;
//     *pHere++ = w;
//   } else {
//     dStack_push(-13);
//     _throw();
//     return;
//   }
// }


#ifndef MARKED_FOR_DELETE
// const char bracket_char_str[] = "[char]";
// Interpretation: Interpretation semantics for this word are undefined.
// Compilation: ( "<space>name" -- )
// Skip leading spaces delimiters. Parse name delimited by a space. Append
// the run-time semantics given below to the current definition.
// Run-Time: ( -- char )
// Place char, the value of the first character of name, on the stack.
// void _bracket_char(void) {
//   if (getToken()) {
//     *pHere++ = LITERAL_IDX;
//     *pHere++ = cTokenBuffer[0];
//   } else {
//     dStack_push(-16);
//     _throw();
//   }
// }
#endif


// const char right_bracket_str[] = "]";
// ( -- )
// Enter compilation state.
// void _right_bracket(void) {
//   state = TRUE;
// }






/*******************************************************************************/
/**                          Core Extension Set                               **/
/*******************************************************************************/
#ifdef CORE_EXT_SET




// const char zero_not_equal_str[] = "0<>";
// ( x -- flag)
// flag is true if and only if x is not equal to zero. 
// void _zero_not_equal(void) { 
//   w = dStack_pop();
//   if (w == 0) dStack_push(FALSE);
//   else dStack_push(TRUE);
// }

// const char zero_greater_str[] = "0>";
// (n -- flag)
// flag is true if and only if n is greater than zero.
// void _zero_greater(void) {
//   w = dStack_pop();
//   if (w > 0) dStack_push(TRUE);
//   else dStack_push(FALSE);
// }

// const char two_to_r_str[] = "2>r";
// Interpretation: Interpretation semantics for this word are undefined. 
// Execution: ( x1 x2 -- ) ( R:  -- x1 x2 )
// Transfer cell pair x1 x2 to the return stack.  Semantically equivalent
// to SWAP >R >R.
// void _two_to_r(void) {
//   _swap();
//   _to_r();
//   _to_r();
// }

// const char two_r_from_str[] = "2r>";
// Interpretation: Interpretation semantics for this word are undefined. 
// Execution: ( -- x1 x2 )  ( R:  x1 x2 -- ) 
// Transfer cell pair x1 x2 from the return stack.  Semantically equivalent to
// R> R> SWAP. 
// void _two_r_from(void) {
//   _r_from();
//   _r_from();
//   _swap();
// }

// const char two_r_fetch_str[] = "2r@";
// Interpretation: Interpretation semantics for this word are undefined. 
// Execution: ( -- x1 x2 )  ( R:  x1 x2 -- x1 x2 ) 
// Copy cell pair x1 x2 from the return stack.  Semantically equivalent to
// R> R> 2DUP >R >R SWAP. 
// void _two_r_fetch(void) {
//   _r_from();
//   _r_from();
//   _two_dup();
//   _to_r();
//   _to_r();
//   _swap();
// }

// const char colon_noname_str[] = ":noname";
// ( C:  -- colon-sys )  ( S:  -- xt )
// Create an execution token xt, enter compilation state and start the current
// definition, producing colon-sys.  Append the initiation semantics given 
// below to the current definition. 
// The execution semantics of xt will be determined by the words compiled into
// the body of the definition.  This definition can be executed later by using
// xt EXECUTE.
// If the control-flow stack is implemented using the data stack, colon-sys 
// shall be the topmost item on the data stack.  See 3.2.3.2 Control-flow stack.
//
// Initiation: ( i*x -- i*x )  ( R:  -- nest-sys )
// Save implementation-dependent information nest-sys about the calling 
// definition.  The stack effects i*x represent arguments to xt. 
//
// xt Execution: ( i*x -- j*x )
// Execute the definition specified by xt.  The stack effects i*x and j*x 
// represent arguments to and results from xt, respectively.  
//void _colon_noname(void) {
//  state = TRUE;
//  push(COLON_SYS);
//  openEntry();
//}

// const char neq_str[] = "<>";
// (x1 x2 -- flag)
// flag is true if and only if x1 is not bit-for-bit the same as x2.
// void _neq(void) {
//   cell_t x2 = dStack_pop();
//   cell_t x1 = dStack_pop();
//   if (x1 != x2) dStack_push(TRUE);
//   else dStack_push(FALSE); 
// }


// const char case_str[] = "case";
// Contributed by Craig Lindley
// Interpretation semantics for this word are undefined.
// Compilation: ( C: -- case-sys )
// Mark the start of the CASE ... OF ... ENDOF ... ENDCASE structure. Append the run-time
// semantics given below to the current definition.
// Run-time: ( -- )
// Continue execution.
// static void _case(void) {
//   dStack_push(CASE_SYS);
//   dStack_push(0); // Count of of clauses
// }

// const char of_str[] = "of";
// Contributed by Craig Lindley
// Interpretation semantics for this word are undefined.
// Compilation: ( C: -- of-sys )
// Put of-sys onto the control flow stack. Append the run-time semantics given below to
// the current definition. The semantics are incomplete until resolved by a consumer of
// of-sys such as ENDOF.
// Run-time: ( x1 x2 -- | x1 )
// If the two values on the stack are not equal, discard the top value and continue execution
// at the location specified by the consumer of of-sys, e.g., following the next ENDOF.
// Otherwise, discard both values and continue execution in line.
// static void _of(void) {
//   dStack_push(dStack_pop() + 1);      // Increment count of of clauses
//   rStack_push(dStack_pop());         // Move to return stack

//   dStack_push(OF_SYS);
//   *pHere++ = OVER_IDX;  // Postpone over
//   *pHere++ = EQUAL_IDX; // Postpone =
//   *pHere++ = ZJUMP_IDX; // If
//   *pHere = 0;           // Filled in by endof
//   dStack_push((size_t) pHere++);// Push address of jump address onto control stack
//   dStack_push(rStack_pop());         // Bring of count back
// }

// const char endof_str[] = "endof";
// Contributed by Craig Lindley
// Interpretation semantics for this word are undefined.
// Compilation: ( C: case-sys1 of-sys -- case-sys2 )
// Mark the end of the OF ... ENDOF part of the CASE structure. The next location for a
// transfer of control resolves the reference given by of-sys. Append the run-time semantics
// given below to the current definition. Replace case-sys1 with case-sys2 on the
// control-flow stack, to be resolved by ENDCASE.
// Run-time: ( -- )
// Continue execution at the location specified by the consumer of case-sys2.
// static void _endof(void) {
//   cell_t *back, *forward;

//   rStack_push(dStack_pop());         // Move of count to return stack

  // Prepare jump to endcase
//   *pHere++ = JUMP_IDX;
//   *pHere = 0;
//   forward = pHere++;

//   back = (cell_t*) dStack_pop(); // Resolve If from of
//   *back = (size_t) pHere - (size_t) back;

//   if (dStack_pop() != OF_SYS) { // Make sure control structure is consistent
//     dStack_push(-22);
//     _throw();
//     return;
//   }
  // Place forward jump address onto control stack
//   dStack_push((cell_t) forward);
//   dStack_push(rStack_pop());          // Bring of count back
// }

// const char endcase_str[] = "endcase";
// Contributed by Craig Lindley
// Interpretation semantics for this word are undefined.
// Compilation: ( C: case-sys -- )
// Mark the end of the CASE ... OF ... ENDOF ... ENDCASE structure. Use case-sys to resolve
// the entire structure. Append the run-time semantics given below to the current definition.
// Run-time: ( x -- )
// Discard the case selector x and continue execution.
// static void _endcase(void) {
//   cell_t *orig;

  // Resolve all of the jumps from of statements to here
//   int count = dStack_pop();
//   for (int i = 0; i < count; i++) {
//     orig = (cell_t *) dStack_pop();
//     *orig = (size_t) pHere - (size_t) orig;
//   }

//   *pHere++ = DROP_IDX;      // Postpone drop of case selector

//   if (dStack_pop() != CASE_SYS) {  // Make sure control structure is consistent
//     dStack_push(-22);
//     _throw();
//   }
// }

#endif

/*******************************************************************************/
/**                            Double Cell Set                                **/
/*******************************************************************************/
#ifdef DOUBLE_SET
#endif


/*******************************************************************************/
/**  File: Dictionary.ino                                                     **/
/*******************************************************************************/
/**                             Exception Set                                 **/
/**                         ainsuForth: this stays.                           **/
/*******************************************************************************/
#ifdef EXCEPTION_SET
#endif

/*******************************************************************************/
/**                             Facility Set                                  **/
/*******************************************************************************/
#ifdef FACILITY_SET
/*
 * Contributed by Andrew Holt
 */
const char key_question_str[] = "key?";
void _key_question(void) {
    
//     if( Serial.available() > 0) {
//         dStack_push(TRUE);
//     } else {
//         dStack_push(FALSE);
//     }
}
#endif

/*******************************************************************************/
/**                              Local Set                                    **/
/*******************************************************************************/
#ifdef LOCAL_SET
#endif

/*******************************************************************************/
/**                              Memory Set                                   **/
/*******************************************************************************/
#ifdef MEMORY_SET
#endif

/*******************************************************************************/
/**                          Programming Tools Set                            **/
/*******************************************************************************/
#ifdef TOOLS_SET


// const char dump_str[] = "dump"; // see: dump.cpp // marked for deletion: _dump();
// void _dump(void) { }

const char see_str[] = "see";
// ("<spaces>name" -- )
// Display a human-readable representation of the named word's definition. The
// source of the representation (object-code decompilation, source block, etc.)
// and the particular form of the display in implementation defined.
void _see(void) {
  bool isLiteral, done;

  _tick();
  if (errorCode) return;
  char flags = wordFlags;
  if (flags && IMMEDIATE)
    Serial.print("Immediate ");
  cell_t xt = dStack_pop();
  if (xt < 255) {
    Serial.print("Primitive Word");
  } else {
    cell_t* addr = (cell_t*)xt;
    Serial.print("\r\nCode Field Address: ");
    Serial.print((size_t)addr, HEX);
    Serial.print("\r\nAddr\tXT\tName");
    do {
      isLiteral = done = false;
      Serial.print("\r\n$");
      Serial.print((size_t)addr, HEX);
      Serial.print(tab_str);
      Serial.print(*addr, HEX);
      Serial.print(tab_str);
      xtToName(*addr);
      switch (*addr) {
        case 2:
          isLiteral = true;
        case 4:
        case 5:
          Serial.print("(");
          Serial.print(*++addr);
          Serial.print(")");
          break;
        case 13:
        case 14:
          Serial.print(sp_str);
          char *ptr = (char*)++addr;
          do {
            Serial.print(*ptr++);
          } while (*ptr != 0);
          Serial.print("\x22");
          addr = (cell_t *)ptr;
          ALIGN_P(addr);
          break;
      }
      // We're done if exit code but not a literal with value of one
      done = ((*addr++ == 1) && (! isLiteral));
    } while (! done);
  }
  Serial.println();
}

#endif

/*******************************************************************************/
/**                               Search Set                                  **/
/*******************************************************************************/
#ifdef SEARCH_SET
#endif

/*******************************************************************************/
/**                               String Set                                  **/
/*******************************************************************************/
#ifdef STRING_SET
#endif

/********************************************************************************/
/**                         EEPROM Operations                                  **/
/********************************************************************************/
#ifdef EN_EEPROM_OPS
// const char eeRead_str[] = "eeRead";
// void _eeprom_read(void) {             // address -- value
//   dStack_push(EEPROM.read(dStack_pop()));
// }

// const char eeWrite_str[] = "eeWrite";
// void _eeprom_write(void) {             // value address --
//   char address;
//   char value;
//   address = (char) dStack_pop();
//   value = (char) dStack_pop();
//   EEPROM.write(address, value);
// }
#endif

/********************************************************************************/
/**                      Arduino Library Operations                            **/
/********************************************************************************/
#ifdef EN_ARDUINO_OPS
const char freeMem_str[] = "freeMem";
void _freeMem(void) { 
//   dStack_push(freeMem());
}
#endif

#define EN_PIN_WRITE_MODE_READ
#ifdef  EN_PIN_WRITE_MODE_READ
const char pinWrite_str[] = "pinWrite";
// ( u1 u2 -- )
// Write a high (1) or low (0) value to a digital pin
// u1 is the pin and u2 is the value ( 1 or 0 ). To turn on the LED
// attached to D13, first change its pinMode to OUTPUT.  Then,
// type "1 13 pinWrite".  "0 13 pinWrite" will (correspondingly) turn off
// the LED on D13.

// Note: if you typed "hex" you must enter everything in hexadecimal
// (there is no notation, just type the digits with no symbols to
// mark the number base).

// Thus,

//     hex 1 d pinMode 1 d pinWrite 7d0 delay 0 d pinWrite

// will set the PinMode to OUTPUT, and pulse the LED on for 2 seconds
// (0x7d0 milliseconds).

// Afterwards, try

//    777 dup 10 dump

// just to demonstrate that data entry is currently in hexadecimal.

void _pinWrite(void) {
  digitalWrite(dStack_pop(), dStack_pop());
  // digitalWrite(13, HIGH);
}

const char pinMode_str[] = "pinMode";
// ( u1 u2 -- )
// Set the specified pin behavior to either an input (0) or output (1)
// u1 is the pin and u2 is the mode ( 1 or 0 ).
// The LED is attached to the GPIO pin assigned to D13, on most Arduino devices.
// To set this port pin to an OUTPUT, type "1 13 pinMode".
void _pinMode(void) {
  pinMode(dStack_pop(), dStack_pop());
  // pinMode(13, OUTPUT);
}

const char pinRead_str[] = "pinRead";
void _pinRead(void) {
  dStack_push(digitalRead(dStack_pop()));
}
#endif


#ifdef EN_ARDUINO_OPS
const char analogRead_str[] = "analogRead";
void _analogRead(void) {
//   dStack_push(analogRead(dStack_pop()));
}

const char analogWrite_str[] = "analogWrite";
void _analogWrite(void) {
//   analogWrite(dStack_pop(), dStack_pop());
}

const char to_name_str[] = ">name";
void _toName(void) {
//   xtToName(dStack_pop());
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

