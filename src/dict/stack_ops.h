// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

extern const char dupe_str[]; // = "dup";
extern void _dupe(void);

extern const char swap_str[]; // = "swap";
extern void _swap(void);

extern const char rot_str[]; // = "rot";
extern void _rot(void);

extern const char and_str[]; // = "and";
extern void _and(void);

extern const char or_str[]; // = "or";
extern void _or(void);

extern const char xor_str[]; // = "xor";
extern void _xor(void);

extern const char dot_str[];    // = ".";
extern void _dot(void);

extern const char u_dot_str[]; // = "u.";
extern void _u_dot(void);

extern const char dot_s_str[]; // = ".s";
extern void _dot_s(void);

extern const char emit_str[]; // = "emit";
extern void _emit(void);

extern const char dot_paren_str[]; // = ".(";
extern void _dot_paren(void);

extern const char cr_str[]; // = "cr"; // ( -- ) Carriage Return
extern void _cr(void);

extern const char space_str[]; // = "space";
extern void _space(void);

extern const char spaces_str[]; // = "spaces";
extern void _spaces(void);

extern const char hex_str[]; // = "hex";
extern void _hex(void); // { // value --

extern const char decimal_str[]; // = "decimal";
extern void _decimal(void);

extern const char words_str[]; // = "words";
extern void _words(void); // --

extern const char zero_equal_str[]; // = "0=";
extern void _zero_equal(void);

extern const char delay_str[]; // = "delay";
extern void _delay(void);


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
