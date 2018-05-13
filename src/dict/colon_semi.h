// Wed Jun 21 20:55:05 UTC 2017
// 4735-a0p-03-

extern const char colon_str[]; // = ":";
extern const char semicolon_str[]; // = ";";

extern uint8_t state; // Holds the text interpreters compile/interpreter state

extern void _colon(void);
extern void _semicolon(void);

extern void openEntry(void);
extern void closeEntry(void);
extern void dStack_push(cell_t value);
extern cell_t dStack_pop(void);
extern void _throw(void);

