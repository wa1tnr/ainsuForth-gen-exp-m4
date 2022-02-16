// Fri 22 Jun 18:03:52 UTC 2018
// 4737-a3b-005-

// This file, config_dict.h is included only by compatibility.h

// Fri 22 Jun 17:36:48 UTC 2018
// 4737-a3b-003-


// XDICT  -  global xdict (extra dictionary) inclusion flag
// -------  use this to switch between them   ---------

#define XDICT // swap these two
#undef  XDICT // swap these two

// -------  use this to switch between them   ---------





// NOP  -  the nop word - no operation (empty code - not optimized away)
// -------  use this to switch between them   ---------

#define INCL_NOP_WORD // swap these two
#undef  INCL_NOP_WORD // swap these two

// -------  use this to switch between them   ---------



//      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//      - - - - - - - -   d o c u m e n t a t i o n   - - - - - - - -
//      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


/* model - target code (in the dictionary files, elsewhere in the source tree):

#if defined(INCL_THIS_WORD) || defined(XDICT)
    .
    .
    code
    .
    .
#endif

*/

/* local model code
189 // NEO_PIXEL
190 // -------  use this to switch between them   ---------
191 
192 #undef NEO_PIXEL_LIB_ENABLED  // swap these two
193 #define NEO_PIXEL_LIB_ENABLED // swap these two
194 
195 // -------  use this to switch between them   ---------
*/

// END.
