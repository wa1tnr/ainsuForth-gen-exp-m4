// Fri Nov 24 23:31:39 UTC 2017
// 4735-b0c-09b-   the -09x- is new Nov 24, 2017.


// previous timestamp:
// none.

#include <Arduino.h>
#include "../../yaffa.h"

#include "remove.h"
#include "getline.h"


const char remove_str[] = "remove";
void _remove(void) {
    remove_a_file();
    Serial.print(" the remove word was called.  see remove.cpp in the kernel directory.");
}

// end.

