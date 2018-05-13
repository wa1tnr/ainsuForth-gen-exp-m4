// Mon Jun 26 00:56:18 UTC 2017
// 4735-a0r-05-

extern const char allot_str[]; // = "allot";
extern void _allot(void);

extern cell_t forthSpace[FORTH_SIZE]; // Reserve a block on RAM for the forth environment
extern cell_t* pHere;               // HERE, points to the next free position in
                                    // Forth Space

extern void dStack_push(cell_t value);
extern cell_t dStack_pop(void);

extern const char throw_str[]; // = "throw";
extern void _throw(void);

