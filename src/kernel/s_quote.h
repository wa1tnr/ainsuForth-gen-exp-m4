// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

// prototypes - this word
extern const char s_quote_str[]; // = "s\x22"; 
extern void _s_quote(void);

// prototypes - variables
extern char cDelimiter; // = ' ';          // The parsers delimiter
extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on
extern uint8_t flags;                 // Internal Flags
extern cell_t* pHere;               // HERE, points to the next free position in
extern uint8_t state; // Holds the text interpreters compile/interpreter state
extern cell_t* ip;   // Instruction Pointer

// prototypes - external functions
extern uint8_t getToken(void);
extern void dStack_push(cell_t value);
extern void _throw(void);

