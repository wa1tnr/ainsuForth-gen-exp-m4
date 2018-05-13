// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

// many other files in src/kernel also would get the above timestamp,
// but it is tedious to modify them by hand, to make that happen.

// So, the first file listed alphabetically generally carries the
// latest timestamp, regardless of its true age.

// prototypes - this word
extern const char do_sys_str[]; // = "do-sys";
extern void _do_sys(void);

// prototypes - external functions
extern void rStack_push(cell_t value);
extern cell_t dStack_pop(void);

