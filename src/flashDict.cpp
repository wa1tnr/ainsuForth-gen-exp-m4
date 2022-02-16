// Fri 22 Jun 18:03:52 UTC 2018
// 4737-a3b-005-

// previous timestamps:
// Thu 21 Jun 22:17:21 UTC 2018
// 4737-a3b-001-  +dict_comments_only.cpp file

// eflmkdir - external flashROM mod - create new directory 17 June 2018.
// NOTE: you must compile this 'eflmkdir' word.  The very
// act of compilation also executes it
// (both IMMEDIATE and COMP_ONLY flags are set for it).

// Go ahead and compile it into a word and execute that
// new word (held as bytecode in RAM) as many times as
// you like.  It'll just give an ok prompt, as this word
// checks to see if the directory '/forth' exists or not,
// and only tries to mkdir if it does not.

// So it is harmless to do it a second, third, fourth .. time.

// { eflmkdir_str,       _eflmkdir,        IMMEDIATE + COMP_ONLY },

// Like that.


// Sun 17 Jun 22:09:15 UTC 2018 // 4737-a3a-0e0-
// Wed 23 May 03:16:05 UTC 2018 // 4737-a3a-05p-

// source word uncommented.

// Mon 14 May 18:47:28 UTC 2018 // 4737-a3a-05a-
// Sun 13 May 06:53:54 UTC 2018 // 4737-a3a-03f-
// Mon Jan 15 18:14:33 UTC 2018 // 4737-a0d-05c-

// SPI flashROM stuff

// look for #ifdef HAS_SPI_FLASH_DEMO   10 Dec 2017

// the accept word

// Sat Dec 16 01:24:37 UTC 2017 // 4737-a0a-00a-
// Sun Dec 10 22:48:03 UTC 2017 // 4735-b0d-00b-   the -00x- is new Dec 10, 2017.
// Sat Nov 25 19:03:16 UTC 2017 // 4735-b0c-09d-   the -09x- is new Nov 24, 2017.
// Fri Nov 24 23:31:39 UTC 2017 // 4735-b0c-09b-   the -09x- is new Nov 24, 2017.
// Thu Aug  3 01:46:56 UTC 2017 // 4735-b0d-00-

#include <Arduino.h>
#include "yaffa.h"
#include "src/dict/new_dict_entries.h" // #include "src/dict/dict_entries.h" // 21 June 2018
#include "flashDict.h"
#include "Dictionary.h"
#include "Error_Codes.h"


/*********************************************************************************/
/**   'static void _foo(void)'  -- conflicts with 'extern void'                 **/
/*********************************************************************************/
const char comma_str[] = ",";
// ( x --  )
// Reserve one cell of data space and store x in the cell. If the data-space
// pointer is aligned when , begins execution, it will remain aligned when ,
// finishes execution. An ambiguous condition exists if the data-space pointer
// is not aligned prior to execution of ,.
static void _comma(void) {
  *pHere++ = dStack_pop();
}

const char two_drop_str[] = "2drop";
// ( x1 x2 -- )
static void _two_drop(void) {
  dStack_pop();
  dStack_pop();
}


/*********************************************************************************/
/**                         Dictionary Initialization                           **/
/*********************************************************************************/

const flashEntry_t DLflashDict[] = {
  { dl_ends_str,        _dl_ends,         NORMAL },  // IMMEDIATE
  { NULL,               NULL,             NORMAL }
};

/**                         Dictionary Initialization                           **/
const flashEntry_t flashDict[] = {
  /*****************************************************/
  /* The initial entries must stay in this order so    */
  /* they always have the same index. They get called  */
  /* referenced when compiling code                    */
  /*****************************************************/
  { exit_str,           _exit,            NORMAL },
  { literal_str,        _literal,         IMMEDIATE },
  { type_str,           _type,            NORMAL },
  { jump_str,           _jump,            SMUDGE },
  { zjump_str,          _zjump,           SMUDGE },
  { subroutine_str,     _subroutine,      SMUDGE },
  { throw_str,          _throw,           NORMAL },
  { do_sys_str,         _do_sys,          SMUDGE },
  { loop_sys_str,       _loop_sys,        SMUDGE },
  { leave_sys_str,      _leave_sys,       SMUDGE },
  { plus_loop_sys_str,  _plus_loop_sys,   SMUDGE },
  { evaluate_str,       _evaluate,        NORMAL },
  { s_quote_str,        _s_quote,         IMMEDIATE + COMP_ONLY },
  { dot_quote_str,      _dot_quote,       IMMEDIATE + COMP_ONLY },
  { variable_str,       _variable,        NORMAL },
  { over_str,           _over,            NORMAL }, // CAL
  { eq_str,             _eq,              NORMAL }, // CAL
  { drop_str,           _drop,            NORMAL }, // CAL

  /*****************************************************/
  /* Order does not matter after here                  */
  /* Core Words                                        */
  /*****************************************************/
#if defined(INCL_NOP_WORD) || defined(XDICT)
  { nop_str,            _nop,             NORMAL }, // 22 June 2018
#endif
  { warm_str,           _warm,            NORMAL },
  { dot_str,            _dot,             NORMAL },
  { minus_str,          _minus,           NORMAL },
  { plus_str,           _plus,            NORMAL },
  { star_str,           _star,            NORMAL },
  { zero_equal_str,     _zero_equal,      NORMAL },
//   { abort_str,          _abort,           NORMAL },
  { store_str,          _store,           NORMAL },
//   { number_sign_str,    _number_sign,     NORMAL },
//   { number_sign_gt_str, _number_sign_gt,  NORMAL },
//   { number_sign_s_str,  _number_sign_s,   NORMAL },
//   { tick_str,           _tick,            NORMAL },
//   { paren_str,          _paren,           IMMEDIATE },
//   { star_slash_str,     _star_slash,      NORMAL },
//   { star_slash_mod_str, _star_slash_mod,  NORMAL },
  { plus_store_str,     _plus_store,      NORMAL },
//   { plus_loop_str,      _plus_loop,       IMMEDIATE + COMP_ONLY },
  { comma_str,          _comma,           NORMAL },
  { slash_str,          _slash,           NORMAL },
//   { slash_mod_str,      _slash_mod,       NORMAL },
//   { zero_less_str,      _zero_less,       NORMAL },
//   { one_plus_str,       _one_plus,        NORMAL },
//   { one_minus_str,      _one_minus,       NORMAL },
  { two_store_str,      _two_store,       NORMAL },
//   { two_star_str,       _two_star,        NORMAL },
//   { two_slash_str,      _two_slash,       NORMAL },
  { two_fetch_str,      _two_fetch,       NORMAL },
  { two_drop_str,       _two_drop,        NORMAL },
//   { two_dup_str,        _two_dup,         NORMAL },
//   { two_over_str,       _two_over,        NORMAL },
//   { two_swap_str,       _two_swap,        NORMAL },
  { colon_str,          _colon,           NORMAL },
  { semicolon_str,      _semicolon,       IMMEDIATE },
//   { lt_str,             _lt,              NORMAL },
//   { lt_number_sign_str, _lt_number_sign,  NORMAL },
//   { eq_str,             _eq,              NORMAL },
//   { gt_str,             _gt,              NORMAL },
//   { to_body_str,        _to_body,         NORMAL },
//   { to_in_str,          _to_in,           NORMAL },
//   { to_number_str,      _to_number,       NORMAL },
  { to_r_str,           _to_r,            NORMAL },
//   { question_dup_str,   _question_dup,    NORMAL },
  { fetch_str,          _fetch,           NORMAL },
//   { abort_quote_str,    _abort_quote,     IMMEDIATE + COMP_ONLY },
  { abs_str,            _abs,             NORMAL },
#ifdef EXT_KERN_ACCEPT // lets get rid of this test - legacy cruft - 22 June 2018
  { accept_str,         _accept,          NORMAL },
#endif
//   { align_str,          _align,           NORMAL },
//   { aligned_str,        _aligned,         NORMAL },
  { allot_str,          _allot,           NORMAL },
  { and_str,            _and,             NORMAL },
//   { base_str,           _base,            NORMAL },
//   { begin_str,          _begin,           IMMEDIATE + COMP_ONLY },
//   { bl_str,             _bl,              NORMAL },
  { c_store_str,        _c_store,         NORMAL },
  { c_comma_str,        _c_comma,         NORMAL },
  { c_fetch_str,        _c_fetch,         NORMAL },
//   { cell_plus_str,      _cell_plus,       NORMAL },
//   { cells_str,          _cells,           NORMAL },
  { char_str,           _char,            NORMAL },
//   { char_plus_str,      _char_plus,       NORMAL },

//   { chars_str,          _chars,           NORMAL },
  { constant_str,       _constant,        NORMAL },
  { count_str,          _count,           NORMAL },
  { cr_str,             _cr,              NORMAL },
//   { create_str,         _create,          NORMAL },
  { decimal_str,        _decimal,         NORMAL },
//   { depth_str,          _depth,           NORMAL },
  { do_str,             _do,              IMMEDIATE + COMP_ONLY },
//   { does_str,           _does,            IMMEDIATE + COMP_ONLY },
//   { drop_str,           _drop,            NORMAL },
  { dupe_str,           _dupe,            NORMAL },
//   { else_str,           _else,            IMMEDIATE + COMP_ONLY },
  { emit_str,           _emit,            NORMAL },
//   { environment_str,    _environment,     NORMAL },
//   { execute_str,        _execute,         NORMAL },
  { fill_str,           _fill,            NORMAL },
//   { find_str,           _find,            NORMAL },
//   { fm_slash_mod_str,   _fm_slash_mod,    NORMAL },
  { here_str,           _here,            NORMAL },
//   { hold_str,           _hold,            NORMAL },
//   { i_str,              _i,               NORMAL },
//   { if_str,             _if,              IMMEDIATE + COMP_ONLY },
//   { immediate_str,      _immediate,       NORMAL },
//   { invert_str,         _invert,          NORMAL },
//   { j_str,              _j,               NORMAL },
//   { key_str,            _key,             NORMAL },
//   { leave_str,          _leave,           IMMEDIATE + COMP_ONLY },
  { loop_str,           _loop,            IMMEDIATE + COMP_ONLY },
//   { lshift_str,         _lshift,          NORMAL },
//   { m_star_str,         _m_star,          NORMAL },
  { max_str,            _max,             NORMAL },
  { min_str,            _min,             NORMAL },
//   { mod_str,            _mod,             NORMAL },
//   { move_str,           _move,            NORMAL },
  { negate_str,         _negate,          NORMAL },
  { or_str,             _or,              NORMAL },
//   { postpone_str,       _postpone,        IMMEDIATE + COMP_ONLY },
  { quit_str,           _quit,            NORMAL },
  { r_from_str,         _r_from,          NORMAL },
  { r_fetch_str,        _r_fetch,         NORMAL },
//   { recurse_str,        _recurse,         IMMEDIATE + COMP_ONLY },
//   { repeat_str,         _repeat,          IMMEDIATE + COMP_ONLY },
  { rot_str,            _rot,             NORMAL },
//   { rshift_str,         _rshift,          NORMAL },
//   { s_to_d_str,         _s_to_d,          NORMAL },
//   { sign_str,           _sign,            NORMAL },
//   { sm_slash_rem_str,   _sm_slash_rem,    NORMAL },
  { source_str,         _source,          NORMAL }, // uncommented 2018 23 May
  { space_str,          _space,           NORMAL },
  { spaces_str,         _spaces,          NORMAL },
//   { state_str,          _state,           NORMAL },
  { swap_str,           _swap,            NORMAL },
//   { then_str,           _then,            IMMEDIATE + COMP_ONLY },
  { u_dot_str,          _u_dot,           NORMAL },
//   { u_lt_str,           _u_lt,            NORMAL },
//   { um_star_str,        _um_star,         NORMAL },
//   { um_slash_mod_str,   _um_slash_mod,    NORMAL },
//   { unloop_str,         _unloop,          NORMAL + COMP_ONLY },
//   { until_str,          _until,           IMMEDIATE + COMP_ONLY },
//   { while_str,          _while,           IMMEDIATE + COMP_ONLY },
  { word_str,           _word,            NORMAL },
  { xor_str,            _xor,             NORMAL },
//   { left_bracket_str,   _left_bracket,    IMMEDIATE },
//   { bracket_tick_str,   _bracket_tick,    IMMEDIATE },
  { bracket_char_str,   _bracket_char,    IMMEDIATE },
//   { right_bracket_str,  _right_bracket,   NORMAL },

#ifdef CORE_EXT_SET
  { dot_paren_str,      _dot_paren,       IMMEDIATE },
//   { zero_not_equal_str, _zero_not_equal,  NORMAL },
//   { zero_greater_str,   _zero_greater,    NORMAL },
//   { two_to_r_str,       _two_to_r,        NORMAL },
//   { two_r_from_str,     _two_r_from,      NORMAL },
//   { two_r_fetch_str,    _two_r_fetch,     NORMAL },
//   { neq_str,            _neq,             NORMAL },
  { hex_str,            _hex,             NORMAL },
//   { case_str,           _case,            IMMEDIATE + COMP_ONLY },    // CAL
//   { of_str,             _of,              IMMEDIATE + COMP_ONLY },    // CAL
//   { endof_str,          _endof,           IMMEDIATE + COMP_ONLY },    // CAL
//   { endcase_str,        _endcase,         IMMEDIATE + COMP_ONLY },    // CAL
  { help_str,           _help,            NORMAL },
  { who_str,            _who,             NORMAL }, // who is this target? dump shows it.
#endif

#ifdef DOUBLE_SET
#endif

#ifdef EXCEPTION_SET
#endif

#ifdef FACILITY_SET
//   { key_question_str,   _key_question,    NORMAL },
#endif

#ifdef LOCALS_SET
#endif

#ifdef MEMORY_SET
#endif

#ifdef TOOLS_SET
  { dot_s_str,          _dot_s,           NORMAL },
  { dump_str,           _dump,            NORMAL },
  { see_str,            _see,             NORMAL },
  { words_str,          _words,           NORMAL },
#endif

#ifdef SEARCH_SET
#endif

#ifdef STRING_SET
#endif

#ifdef EN_ARDUINO_OPS
//   { freeMem_str,        _freeMem,         NORMAL },
  { delay_str,          _delay,           NORMAL },
  { pinWrite_str,       _pinWrite,        NORMAL },
  { pinMode_str,        _pinMode,         NORMAL },
  { pinRead_str,        _pinRead,         NORMAL },
//   { analogRead_str,     _analogRead,      NORMAL },  // ISTR this was defined
//   { analogWrite_str,    _analogWrite,     NORMAL },
//   { to_name_str,        _toName,          NORMAL },
#endif

#ifdef EN_EEPROM_OPS
//   { eeRead_str,         _eeprom_read,     NORMAL },
//   { eeWrite_str,        _eeprom_write,    NORMAL },
#endif


#ifdef NEO_PIXEL

  { npx_str,            _npx,             NORMAL }, // NORMAL  // set npx array index (e.g. 0-9 on CPX)  '4 npx' sets the 5th npx for future write ops incl. 'rgb'
  { npx_fetch_str,      _npx_fetch,       NORMAL }, // NORMAL  // fetch npx array index 'npx@ .' prints the current index without disturbing it
  { rgb_str,            _rgb,             NORMAL }, // NORMAL  // '0 0 1 rgb' sets blue.  '0 0 0 rgb' makes current npx go dark
  { pixel_str,          _pixel,           NORMAL }, // NORMAL  // 'pixel' runs a demo blinking pattern
  { cblink_str,         _cblink,          NORMAL }, // NORMAL  // 'cblink' blinks current npx once .. in cyan
                                                               // 3 npx 9 0 9 rgb -- this would select the 4th npx and color it in magenta

#endif // #ifdef NEO_PIXEL

#define SPI_FLASH_SRC
#ifdef SPI_FLASH_SRC

#ifdef HAS_SPI_FLASH_DEMO
    #warning THIS_THING_TRIPS

  { eflmkdir_str,       _eflmkdir,        IMMEDIATE + COMP_ONLY },
  { load_str,           _load,            NORMAL },
  { echo_bang_str,      _echo_bang,       NORMAL }, 
  { remove_str,         _remove,          NORMAL },
  { download_str,       _download,        NORMAL },
#endif // #ifdef HAS_SPI_FLASH_DEMO

#ifdef HAS_QSPI_FLASH_DEMO
    #warning THAT_THING_TRIPS
  { eflmkdir_str,       _eflmkdir,        IMMEDIATE + COMP_ONLY },
  { load_str,           _load,            NORMAL },
  { echo_bang_str,      _echo_bang,       NORMAL }, 
  { remove_str,         _remove,          NORMAL },
  { download_str,       _download,        NORMAL },
#endif // #ifdef HAS_QSPI_FLASH_DEMO

#endif // #ifdef SPI_FLASH_SRC

#ifdef QSPI_FLASHROM
#ifdef HAS_QSPI_FLASHROM_LIB

// { ffmt_str,           _ffmt,            NORMAL }, // flash format

#endif // HAS_QSPI_FLASHROM_LIB
#endif // QSPI_FLASHROM


  { NULL,           NULL,    NORMAL }
};


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/**                                                                          **/
/**  This file is part of YAFFA.                                             **/
/**                                                                          **/
/**  YAFFA is free software: you can redistribute it and/or modify           **/
/**  it under the terms of the GNU General Public License as published by    **/
/**  the Free Software Foundation, either version 2 of the License, or       **/
/**  (at your option) any later version.                                     **/
/**                                                                          **/
/**  YAFFA is distributed in the hope that it will be useful,                **/
/**  but WITHOUT ANY WARRANTY; without even the implied warranty of          **/
/**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **/
/**  GNU General Public License for more details.                            **/
/**                                                                          **/
/**  You should have received a copy of the GNU General Public License       **/
/**  along with YAFFA.  If not, see <http://www.gnu.org/licenses/>.          **/
/**                                                                          **/
/******************************************************************************/

