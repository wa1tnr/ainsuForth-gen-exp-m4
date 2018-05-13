// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

// external const
extern const char literal_str[]; // = "literal";

// prototypes - this word
extern void interpreter(void);

// prototypes - structs
extern const flashEntry_t flashDict[];

// prototypes - variables
extern char* cpSource;      // Pointer to the string location that we will
                            // evaluate. This could be the input buffer or
                            // some other location in memory

extern char* cpToIn;        // Points to a position in the source string
                            // that was the last character to be parsed

extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

extern uint8_t wordFlags;             // Word flags

extern int8_t errorCode; // = 0;

extern cell_t* pHere;               // HERE, points to the next free position in

extern uint8_t state; // Holds the text interpreters compile/interpreter state

extern cell_t* ip;   // Instruction Pointer

extern cell_t w;     // Working Register

// prototypes - external functions
extern uint8_t getToken(void);
extern void executeWord(void);
extern void dStack_push(cell_t value);
extern void rStack_push(cell_t value);
extern cell_t dStack_pop(void);
extern uint8_t isWord(char* addr);
extern uint8_t isNumber(char* subString);
extern void _literal(void);
extern void _throw(void);

