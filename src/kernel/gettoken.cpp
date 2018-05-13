// Mon Jan 15 19:19:47 UTC 2018
// 4737-a0d-05d-

// Thu Aug  3 19:07:55 UTC 2017
// 4735-b0f-00-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_GETTOKEN
#include "gettoken.h"

/******************************************************************************/
/** GetToken                                                                 **/
/**   Find the next token in the buffer and stores it into the token buffer  **/
/**   with a NULL terminator. Returns length of the token or 0 if at end off **/
/**   the buffer.                                                            **/
/**   Could this become the word WORD?                                       **/
// ( char "<chars>ccc<chars>" -- c-addr )
// Skip leading delimiters. Parse characters ccc delimited by char. An ambiguous
// condition exists if the length of the parsed string is greater than the 
// implementation-defined length of a counted string.
//
// c-addr is the address of a transient region containing the parsed word as a
// counted string. If the parse area was empty or contained no characters other than
// the delimiter, the resulting string has a zero length. A space, not included in 
// the length, follows the string. A program may replace characters within the 
// string.
//
// NOTE: The requirement to follow the string with a space is obsolescent and is
// included as a concession to existing programs that use CONVERT. A program shall 
// not depend on the existence of the space.
/******************************************************************************/

/*

 65 char* cpSource;                 // Pointer to the string location that we will
 66                                 // evaluate. This could be the input buffer or
 67                                 // some other location in memory
 68 char* cpSourceEnd;              // Points to the end of the source string
 69 char* cpToIn;                   // Points to a position in the source string
 70                                 // that was the last character to be parsed
 71 char cDelimiter = ' ';          // The parsers delimiter
 72 char cInputBuffer[BUFFER_SIZE]; // Input Buffer that gets parsed
 73 char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

*/




uint8_t getToken(void) {
  String inString, endFileString;
  uint8_t tokenIdx = 0;
  while (cpToIn <= cpSourceEnd) {

      if (noInterpreter) {
          if (alreadyParsed) {
              int fakeAP = 0; // noop
          } else {
              // Serial.print(" <<DELIMITER_BEGIN ~");
              int fakeAPb = 0; // noop


// 24 const char dl_ends_str[] = "\\end.";  // type '\end.' to exit the download vocabulary.
// "download.cpp"

              // if ((char*) dl_ends_str[] == "\\end.") { Serial.print("Aha. Line 68 gettoken.cpp SEEN.\r\n"); }
              // if (*dl_ends_str[] == "\\end.") { Serial.print("Aha. Line 68 gettoken.cpp SEEN.\r\n"); }
              // cTokenBuffer[tokenIdx] = '\0';       // Terminate SubString
              // if (*cTokenBuffer[] == "\\end.") { Serial.print("Aha. Line 68 gettoken.cpp SEEN.\r\n"); }
              // if (*cpSource == "\\end.") { Serial.print("Aha. Line 72 gettoken.cpp SEEN.\r\n"); }
              // if (cpSource == "\end.") { Serial.print("Aha. Line 72 gettoken.cpp SEEN.\r\n"); }
              // compiles: // if ((char*) cTokenBuffer[tokenIdx] == "\\end.") { Serial.print("Aha. Line 68 gettoken.cpp SEEN.\r\n"); }

    //        if ((*cpToIn == cDelimiter) || (*cpToIn == 0)) {

              // String inString, endFileString;

// -----------------------------------------------------------------
              inString = String(cpSource); // GOOD do not change
// -----------------------------------------------------------------

              endFileString = ("\\end.");

              // if (inString == endFileString) { Serial.print("Aha. Line 68 gettoken.cpp SEEN.\r\n"); }

              // debug: // Serial.print("compare these:  ");
              // debug: // Serial.print(inString);
              // debug: // Serial.print("  and  ");
              // debug: // Serial.print(endFileString);
              // debug: // Serial.print("  for a match.  ");


              // debug: // if (inString == endFileString) { Serial.print("Aha. Line 68 gettoken.cpp SEEN.\r\n"); }

              // debug: // Serial.print("Now, write to the file: \r\n");



              if (inString == endFileString) { // DO NOT PRINT TO FILE - escape/exit token found.

                    // Serial.print("Aha. Line 68 gettoken.cpp SEEN.\r\n"); }
                    int fake_Stri = 0; // nop
                    
              } else {


#ifdef HAS_SPI_FLASH_DEMO // 15 Jan 2018

                  write_a_capture_file(); // this routine knows about cpSource

#endif // 15 Jan 2018
              }


// ----------------------------------------------------------------------
// -------------------------- primary echo .. maybe ---------------------
              // Serial.print(cpSource);
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

              // Serial.print("~ DELIMITER_END >> ");
              int fakeAPc = 0; // noop
              alreadyParsed = TRUE ; // reset
          }
      }




    if ((*cpToIn == cDelimiter) || (*cpToIn == 0)) {
      cTokenBuffer[tokenIdx] = '\0';       // Terminate SubString
      cpToIn++;
      if (tokenIdx) return tokenIdx;
    } else {
      if (tokenIdx < (WORD_SIZE - 1)) {
        cTokenBuffer[tokenIdx++] = *cpToIn++;
      }
    }
  }
// If we get to SourceEnd without a delimiter and the token buffer has
// something in it return that. Else return 0 to show we found nothing
  if (tokenIdx) return tokenIdx;
  else return 0;
}

#endif
