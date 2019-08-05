# ainsuForth-gen-exp-m4
ainsuForth - generalized - all targets including SAMD51 M4 - experimental

+Metro M4 Express     - SAMD51J19A
+ItsyBitsy M4 Express - SAMD51G19A
+Feather M4 Express   - SAMD51J19A

(previously ainsuForth-gen-exp)

gen-exp means generalized and experimental; generalized
to all the available target boards (trying to move as
much of that into compatibility.h as a single-source
place to look for porting issues, across targets).

This forth is compiled regularly (as targets are reused
to test other code).  It is usually operational. ;)

# New 05 Aug 2019:

On branch develop / testing-gg- / master

The code should be ready for a release, against the older
QSPI flashROM lib (October 2018 timeframe).

Code is broken for latest (2019) Adafruit libs (wrt the
QSPI flashROM support) and will be addressed some other
time.

Roll back your libs to an earlier version, to compile. ;)

    Adafruit_QSPI
    Adafruit_SPIFlash

Both may be affected.  Have not documented just what to
do with this, though a good test compile was done in
early August, 2019, by rolling back one or both of these
(and possibly others; this is off-the-cuff reportage ;)

The program (as-is, and against Oct 2018 Adafruit libs)
will accept code in the forth interpreter, and write it to
the flashROM (to a single named file).

It will also 'play back' the same code, as if a human had
typed it to the regular forth interpreter.

In this way, code may be developed on the device itself,
and stored for future use. ;)

The user interface is identical to the one used when
developed for SAMD21.  The (recent) change is about
supporting similar functionality for the M4 (SAMD51)
chip series (Feather M4 Express, ItsyBitsyM4, Trellis M4).

Grand Central was not looked into, at the time of this
writing (August 2019).

Hopefully the release actually works; it's untested but
believed to have been previously tested (so this is mostly
a human memory problem, more than an actual, executable
code problem .. that's the working assumption!)

Mon Aug  5 01:05:34 UTC 2019

# New 12 Nov 2018:

On branch _with_file_io_aa-

QSPI flashROM support (basic file i/o) for Metro M4 Express.


Older commentary on flashROM support follows:

# SPI flashROM

flashROM support is limited to the JEDEC stuff for samd21
(SPI rather than QSPI).  It occurs in the form of an ability
to capture text to disk and replay that text to program
the forth compiler/interpreter.

It works well enough to be useful on a dumb serial terminal
(with USB interface).  Tested during a power outage when
the usual resources weren't available.  Still primitive,
but a useful asset.

No effort was made at file management, so it's just the
one file on SPI flashROM at present (which can be reset
to zero length, from inside the forth interpreter).

22 August 2018:

Development for a bare-metal Forth in

   https://github.com/wa1tnr/ainsuMtxd21.git (samd21)

The most recent branch incorporating what is achieved is found

   On branch KM_converser_aa-

of that repository.

Earlier work was done on samd51 (clocks look good;
bidirectional USART looks good):

   https://github.com/wa1tnr/samd51_USART_basic.git  (samd51)

The most recent (non-clock) work was carried over (back to)
samd51 in the ainsuMtxd21 repo, currently branch KM_converser_aa-
(just menttioned).


There is also a UART-based version of ainsuForth-gen-exp-m4,
(written in Arduino IDE c++ code) though it hasn't been published.

All that was required was a global search and replace for
'Serial.' with 'Serial1.' to get that to work quite well
(using CP2104 USART-USB bridge chip; reference implementation
was for Adafruit PiUART - a nice way to leverage this,
quickly, with just two wires (plus ground, for three
wires, total).

12 June 2018: Nothing said below this line is reliable, as it is
a copy-over from an earlier project and hasn't been looked at,
recently.  Ignore (or interpret from past events).

August 2018 update:  Haven't removed what's below, nor reviewed it.

It's so much easier to just be diligent with 'git diff' and
to use 'gitk' to step through the changes (though that is the
developer's point of view; for the end-user, hard to say).

 - - - - - - - -

Suggest: diff against ainsuForth-gen-exp -- which was the best
         SAMD21 M0 effort, to date.


Older notes follow.  No effort is made to update them, or remove
where no longer applicable.

August 2nd:

More experimental -- looking at adding SPI flash write support,
file capture from ASCII upload (the 'download' word) and perhaps
splitting out file i/o to its own proper source files.


EXPERIMENTAL -- the below, plus a limited use of the SPI flash
to author forth source code on the device.  Currently, this
amounts to reading a full program (a multi-line forth source
program) from /forth/job.fs on the SPI flash volume.


Platform: Circuit Playground Express (an M0 board w/SPI 2MB flashROM) - 02 Aug 2017

A Forth for SAMD21G18A based on YAFFA-ARM Forth - 2012 by Stuart Wood.



See compatibility.h for (some) configuration options across
target board devices (subset of boards.txt found under

  .arduino15/packages/adafruit/hardware/samd/1.0.18/boards.txt )


----------------------------------------------------------------

Current platform is the

    Adafruit Metro M4 Express Beta -- 13 May 2018.

was:

    Adafruit Feather M0 Express -- 15 January 2018.

All other platform declarations are incorrect, where they differ
from this one.

----------------------------------------------------------------

OLD:
Current platform is the
    Adafruit CPX (Circuit Playground Express) - PRODUCT ID: 3333
which is ATSAMD21 Cortex M0+ based.
----------------------------------------------------------------

Platform will change frequently -- seven different targets are
tested on a (somewhat) rotating basis:

  * Adafruit Metro M4 Express Beta (SAMD51)
  * Arduino M0 Pro (SAMD21)
  * Adafruit Feather M0 Express
  * Adafruit Metro M0 Express
  * Adafruit Circuit Playground Express
  * Adafruit Gemma M0
  * Adafruit Trinket M0

Sun 13 May 00:34:29 UTC 2018

28f54e6bc7

old:

# YAFFA-ARM
YAFFA for Arduino ARM Processors 

See:
 [ https://github.com/sdwood68/YAFFA-ARM ]

