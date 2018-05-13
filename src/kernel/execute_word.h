// Sun Jun 18 16:24:18 UTC 2017
// 4735-a0m-01

// prototypes - this word
extern void executeWord(void);

// prototypes - variables
extern uint8_t flags;                 // Internal Flags
extern int8_t errorCode; // = 0;
extern cell_t* ip;   // Instruction Pointer
extern cell_t w;     // Working Register

// prototypes - external functions
extern void rStack_push(cell_t value);

