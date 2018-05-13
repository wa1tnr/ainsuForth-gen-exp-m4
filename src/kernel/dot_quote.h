// Sun Jun 11 23:00:12 UTC 2017
// 4735-a0g

extern const char dot_quote_str[]; // = ".\x22";
extern void _dot_quote(void);

/**  see File: YAFFA-ARM.ino                                                 **/
extern char cDelimiter; // = ' ';          // The parsers delimiter

extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

extern uint8_t flags;   // Internal Flags   //  see: ../../ainsuForthsketch.cpp
extern cell_t* pHere;   // HERE, points to the next free position in
                        // Forth Space
extern uint8_t state; // Holds the text interpreters compile/interpreter state
extern cell_t* ip;   // Instruction Pointer
extern uint8_t getToken(void);
extern void dStack_push(cell_t value);
extern void _throw(void);

// #endif
