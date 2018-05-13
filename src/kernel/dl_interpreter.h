// Thu Aug  3 01:46:56 UTC 2017
// 4735-b0d-00-

extern void dl_interpreter(void);

extern char* cpSource;      // Pointer to the string location that we will

extern char* cpToIn;        // Points to a position in the source string

extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

extern uint8_t wordFlags;             // Word flags

extern int8_t errorCode; // = 0;

extern cell_t* pHere;               // HERE, points to the next free position in

extern uint8_t state; // Holds the text interpreters compile/interpreter state

extern cell_t* ip;   // Instruction Pointer

extern cell_t w;     // Working Register

extern uint8_t getToken(void);
extern void executeWord(void);
extern void dStack_push(cell_t value);
extern void rStack_push(cell_t value);
// extern cell_t dStack_pop(void);
extern uint8_t isDLWord(char* addr);
extern uint8_t isDLNumber(char* subString);
extern void _literal(void);
extern void _throw(void);

extern uint8_t noInterpreter; // = FALSE ;

