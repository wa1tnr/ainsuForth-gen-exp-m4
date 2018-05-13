// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

// prototypes - this word
extern const char variable_str[]; // = "variable";
extern void _variable(void);

// prototypes - variables
extern cell_t* ip;   // Instruction Pointer
extern cell_t* pHere;   // HERE, points to the next free position in
extern uint8_t flags;                 // Internal Flags

// prototypes - external functions
extern void dStack_push(cell_t value);
extern void openEntry(void);
extern void closeEntry(void);
