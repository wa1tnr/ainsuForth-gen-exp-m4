// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

// prototypes - these words
extern void dStack_clear(void);
extern void rStack_clear(void);
extern void dStack_push(cell_t value);
extern void rStack_push(cell_t value);
extern cell_t dStack_pop(void);
extern cell_t rStack_pop(void);
extern cell_t dStack_peek(int n);
extern cell_t rStack_peek(int n);
extern bool dStack_isFull(void);
extern bool rStack_isFull(void);
extern bool dStack_isEmpty(void);
extern bool rStack_isEmpty(void);
extern uint8_t dStack_size(void);
extern uint8_t rStack_size(void);

// prototypes - variables
extern stack_t dStack;
extern stack_t rStack;

// prototypes - external functions
extern void _throw(void);

