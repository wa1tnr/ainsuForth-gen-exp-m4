// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

// prototypes - this word
extern const char throw_str[]; // = "throw";
extern void _throw(void);

// prototypes - variables
extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on
extern int8_t errorCode; // = 0;
extern uint8_t state; // Holds the text interpreters compile/interpreter state

// prototypes - external functions
extern cell_t dStack_pop(void);
extern void dStack_clear(void);
extern void _cr(void);
extern void _quit(void);

