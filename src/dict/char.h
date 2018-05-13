// Sun Jul  2 20:55:24 UTC 2017
// 4735-b0a-07-

extern const char bracket_char_str[]; // = "[char]";
extern void _bracket_char(void);

extern const char char_str[]; // = "char";
extern void _char(void);

extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on
extern cell_t* pHere;                 // HERE, points to the next free position in
                                      // Forth Space
extern uint8_t getToken(void);
extern void dStack_push(cell_t value);
extern void _throw(void);

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
