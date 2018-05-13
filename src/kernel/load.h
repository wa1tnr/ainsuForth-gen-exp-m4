// Thu Aug  3 19:07:55 UTC 2017
// 4735-b0f-00-

// prototypes - this word
extern const char load_str[]; // = "load";
extern void _load(void);

extern uint8_t spiFlashReading;       // Adafruit SPI flash: reading
extern uint8_t silentReading; // = FALSE ;   // the load word is silent, if this flag is set


extern const char echo_bang_str[]; // = "echo!"; // ( bool -- )
extern void _echo_bang(void);  // ( bool -- )

extern cell_t dStack_pop(void);

