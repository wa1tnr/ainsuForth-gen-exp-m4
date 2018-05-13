// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

#ifdef EXT_KERN_IS_WORD_NUMBER // may need this guard
const char charset[] = "0123456789abcdef";
#endif

// prototypes - these words
extern uint8_t isWord(char* addr);
extern uint8_t isNumber(char* subString);

// prototypes - variables
extern userEntry_t* pLastUserEntry; // = NULL;
extern userEntry_t* pUserEntry; // = NULL;
extern uint8_t wordFlags;             // Word flags
extern cell_t w;     // Working Register
extern uint8_t base;  // stores the number conversion radix

// prototypes - external functions
extern void dStack_push(cell_t value);

