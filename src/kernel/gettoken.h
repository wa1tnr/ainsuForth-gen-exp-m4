// Thu Aug  3 18:43:18 UTC 2017
// 4735-b0e-05-

// prototypes - this word
extern uint8_t getToken(void);

// prototypes - variables
extern char* cpSourceEnd;              // Points to the end of the source string
extern char* cpToIn;                   // Points to a position in the source string
                                       // that was the last character to be parsed
extern char cDelimiter; // = ' ';          // The parsers delimiter
extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

extern uint8_t noInterpreter; // = FALSE ;
extern uint8_t alreadyParsed; // = FALSE ;


extern char* cpSource;                 // Pointer to the string location that we will
extern void write_a_capture_file(void);

/*

 65 char* cpSource;                 // Pointer to the string location that we will
 66                                 // evaluate. This could be the input buffer or
 67                                 // some other location in memory
 68 char* cpSourceEnd;              // Points to the end of the source string
 69 char* cpToIn;                   // Points to a position in the source string
 70                                 // that was the last character to be parsed
 71 char cDelimiter = ' ';          // The parsers delimiter
 72 char cInputBuffer[BUFFER_SIZE]; // Input Buffer that gets parsed
 73 char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on



*/

