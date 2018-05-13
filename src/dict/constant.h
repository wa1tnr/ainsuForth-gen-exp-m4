// Sun Jun 25 03:24:01 UTC 2017
// 4735-a0r-04-

// external const
extern const char constant_str[]; // = "constant";

// prototypes - this word
extern void _constant(void);

// prototypes - variables
extern cell_t* pHere;               // HERE, points to the next free position in
                                    // Forth Space

// prototypes - external functions
extern void openEntry(void);
extern void closeEntry(void);
extern cell_t dStack_pop(void);

