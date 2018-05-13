// Sun Jul  2 20:55:24 UTC 2017
// 4735-b0a-07-

extern const char fill_str[]; // = "fill";
extern void _fill(void);

extern const char store_str[]; // = "!";
extern void _store(void);

extern const char fetch_str[]; // = "@";
extern void _fetch(void);

extern const char c_store_str[]; // = "c!";
extern void _c_store(void);

extern const char c_comma_str[]; // = "c,";
extern void _c_comma(void);

extern const char plus_store_str[]; // = "+!";
extern void _plus_store(void);

extern const char two_store_str[]; // = "2!";
extern void _two_store(void);

extern const char two_fetch_str[]; // = "2@";  // \x40 == '@'
extern void _two_fetch(void);

extern const char c_fetch_str[]; // = "c@";
extern void _c_fetch(void);

extern const char to_r_str[]; // = ">r";
extern void _to_r(void);

extern const char r_from_str[]; // = "r>";
extern void _r_from(void);

extern const char r_fetch_str[]; // = "r@";
extern void _r_fetch(void);


extern cell_t rStack_peek(int n);

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
