// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

extern const char loop_sys_str[]; // = "loop-sys";
extern void _loop_sys(void);
extern void dStack_push(cell_t value);
extern void rStack_push(cell_t value);
extern cell_t rStack_pop(void);
extern cell_t* ip;
extern void _throw(void);

