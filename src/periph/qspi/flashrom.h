// Mon 14 May 22:46:36 UTC 2018
// 4737-a3a-05e-

// Mon 14 May 20:26:35 UTC 2018
// 4737-a3a-05c-

// Mon 14 May 18:47:28 UTC 2018
// 4737-a3a-05a-

#ifndef QSPI_FLASHROM
#define QSPI_FLASHROM

extern void setup_qspiFlashROM(void);
extern void _abcdX44(void); // ( n3 n2 n1 -- n1 n2 n3 )
// extern const char ffmt_str[]; // = "ffmt"; // local idiom ainsuForth - TODO: describe this
extern void _ffmt(void); // ( TOS_requirement_if_any -- )
extern void fomFom(void);
extern void _rot(void);
extern void _swap(void);
extern cell_t dStack_pop(void);
extern void dStack_push(cell_t value);
#endif
