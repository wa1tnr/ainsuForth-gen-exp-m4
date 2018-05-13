// Thu Aug  3 01:46:56 UTC 2017
// 4735-b0d-00-

const char dl_charset[] = "0123456789abcdef";

// prototypes - these words
extern uint8_t isDLWord(char* addr);
extern uint8_t isDLNumber(char* subString);

// prototypes - variables
extern userEntry_t* pLastUserEntry; // = NULL;
extern userEntry_t* pUserEntry; // = NULL;
extern uint8_t wordFlags;             // Word flags
extern cell_t w;     // Working Register
extern uint8_t base;  // stores the number conversion radix

// prototypes - external functions
extern void dStack_push(cell_t value);

