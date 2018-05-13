// Tue Jun 27 21:19:58 UTC 2017
// 4735-a0s-00-

extern const char do_str[]; // = "do";
extern void _do(void);

extern const char loop_str[]; // = "loop";
extern void _loop(void);

extern cell_t* pHere;               // HERE, points to the next free position in
                                    // Forth Space
extern void dStack_push(cell_t value);
extern cell_t dStack_pop(void);
extern void _throw(void);

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
