// Tue Jul 25 07:27:48 UTC 2017
// 4735-b0a-09-

#ifndef NEO_PIXEL
#define NEO_PIXEL

extern void setup_neoPixel(void);
// extern void _rgbp(void);
extern void _cyan(void);
extern void _orange(void);
extern void _blue(void);
extern void _dullMagenta(void);
// extern void neoPixel(void);
extern const char rgb_str[]; // = "rgb"; // local idiom yainsu
extern void _rgb(void);

extern const char npx_str[]; // = "npx"; // local idiom ainsuForth - select which neopixel in a string of them
extern void _npx(void);

extern const char npx_fetch_str[]; // = "npx@"; // local idiom ainsuForth - fetch the npx number
extern void _npx_fetch(void); // ( -- npx_number )

extern void _darkNPX(void); // darken neo pixel
extern const char pixel_str[]; // = "pixel"; // local idiom ainsuForth
extern void _pixel(void);

extern void _rot(void);
extern void _swap(void);
extern cell_t dStack_pop(void);
extern void dStack_push(cell_t value);
#endif
