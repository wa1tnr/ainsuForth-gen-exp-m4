// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// version bump

// previous timestamp:
// Sat Nov 25 19:03:16 UTC 2017
// 4735-b0c-09d-   the -09x- is new Nov 24, 2017.

// accept.h included

// Fri Nov 24 23:31:39 UTC 2017
// Wed Aug  2 18:04:12 UTC 2017
// 4735-b0c-05-

#include "src/kernel/remove.h"
#include "src/kernel/download.h"
#include "src/kernel/load.h"

// #include "src/kernel/getkey.h"
// #include "src/kernel/getline.h"
// #include "src/kernel/stacks.h"

// #include "src/dict/commas.cpp"
#include "src/dict/accept.h"
#include "src/dict/dump.h"

#include "src/dict/cblink.h"

#ifdef HAS_NEO_PIXEL_LIB
#include "src/periph/neo_pixel.h"
#endif

#include "src/dict/help.h"


#include "src/dict/max_min.h"

#include "src/dict/char.h"
#include "src/dict/do_loop.h"

#include "src/dict/allot.h"
#include "src/dict/constant.h"
#include "src/dict/store_fetch.h"
#include "src/dict/xttoname.h"
// #include "src/dict/colon_semi.h"
#include "src/dict/stack_ops.h"
#include "src/dict/iasmd.h"
#include "src/dict/dict_entries.h"

// #include "src/kernel/dl_interpreter.h"
#include "src/kernel/interpreter.h"
#include "src/kernel/do_sys.h"
#include "src/kernel/dot_quote.h"
#include "src/kernel/drop.h"
#include "src/kernel/eq.h"
#include "src/kernel/exit.h"
// #include "src/kernel/fake_header.h" // fake header
#include "src/kernel/jump.h"
#include "src/kernel/leave_sys.h"
#include "src/kernel/literal.h"
#include "src/kernel/loop_sys.h"
#include "src/kernel/over.h"
#include "src/kernel/plus_loop_sys.h"
#include "src/kernel/quit.h"
#include "src/kernel/s_quote.h"
#include "src/kernel/subroutine.h"
#include "src/kernel/throw.h"
#include "src/kernel/type.h"
#include "src/kernel/variable.h"
#include "src/kernel/warm.h"
#include "src/kernel/zjump.h"

extern char* cpSource;                // Pointer to the string location that we will
                                      // evaluate. This could be the input buffer or
                                      // some other location in memory
extern char* cpSourceEnd;             // Points to the end of the source string
extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on
extern userEntry_t* pLastUserEntry; // = NULL;
extern userEntry_t* pUserEntry; // = NULL;
extern int8_t errorCode ; // = 0;
extern cell_t* pHere;     // HERE, points to the next free position in
                          // Forth Space
extern uint8_t state;     // Holds the text interpreters compile/interpreter state
extern cell_t dStack_pop(void);
extern uint8_t dStack_size(void);
extern void dStack_clear(void);
extern void displayValue(void);

extern uint8_t base;  // stores the number conversion radix

