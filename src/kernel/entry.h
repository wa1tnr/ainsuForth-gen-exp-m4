// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

// prototypes - these words
extern void openEntry(void);
extern void closeEntry(void);

// prototypes - variables
extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on
extern userEntry_t* pLastUserEntry; // = NULL;
extern userEntry_t* pNewUserEntry; // = NULL;
extern int8_t errorCode; // = 0;
extern cell_t* pHere;               // HERE, points to the next free position in
                                    // Forth Space
extern cell_t* pOldHere;            // Used by "colon-sys"
extern cell_t* pCodeStart;          // used by "colon-sys" and RECURSE

// prototypes - external functions
extern uint8_t getToken(void);
extern void dStack_push(cell_t value);
extern void _throw(void);

