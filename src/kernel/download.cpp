// Thu Aug  3 18:43:18 UTC 2017
// 4735-b0e-05-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#include "download.h"


const char download_str[] = "download"; // part of the main forth vocabulary, only
void _download(void) {
    noInterpreter = TRUE; // download mode -- no standard interpreter -- use dl_interpreter
    Serial.print("     NOTE: the \'\\end.\' word will exit the download-interpreter vocabulary.");
    // debug: // Serial.println("\r\n debug: download.cpp - the download word.\r\n");
}

// 53   { dl_ends_str,        _dl_ends,         NORMAL },  // IMMEDIATE

const char dl_ends_str[] = "\\end.";  // type '\end.' to exit the download vocabulary.
void _dl_ends(void) {
    noInterpreter = FALSE; 
    Serial.println("\r\n DOWNLOAD ENDS. Please see: src/kernel/download.cpp");

    // August 3, 2017:
    // There was no file captured (at all).  This is just
    // a hook for an unimplemented SPI Flash file download
    // routine.

    // What really happened was a single-word vocabulary
    // was active during the 'download'.

    // The one word in that vocabulary is '\end.' (including
    // the leading backslash and the trailing dot/period
    // symbol).

    // The usual 'throw' was suppressed, so every word sent to
    // the interpreter that is not in the download vocabulary
    // is simply ignored.

    // At the moment, numbers could still be preserved on the
    // stack, even when entered during a 'download'.

    // That behavior has been suppressed -- numbers are detected
    // during a 'download' -- but are simply echo'd.

}


// end.

