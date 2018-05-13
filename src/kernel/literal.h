// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

// prototypes - this word
extern const char literal_str[]; // = "literal";
extern void _literal(void);

// prototypes - variables
extern cell_t* pHere;               // HERE, points to the next free position in
                                    // Forth Space
extern uint8_t state; // Holds the text interpreters compile/interpreter state
extern cell_t* ip;   // Instruction Pointer

// prototypes - external functions
extern void dStack_push(cell_t value);
extern cell_t dStack_pop(void);

