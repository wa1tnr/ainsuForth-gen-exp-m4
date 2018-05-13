\  Thu Aug  3 19:07:55 UTC 2017
\  4735-b0f-00-

\ Note that the backslash is not escaped in ainsuForth during source code upload.
\ It's only used to begin the '\end.' utterance.  It's on the TODO list to allow it,
\ to escape commentary in forth.fs style forth source files.


\ Things to Try
warm \ warm boots the machine.  Do this before some of the following snippets, to clear (especially prior to a 'load').

: false 0 ; : true -1 ; false echo! load  \ load without an echo to the console
: false 0 ; false echo!       \ console does not echo until ENTER is pressed again.

\ progress meter during the load:
: false 0 ; 99 false echo! load  \ any stack item echoes a dot during a load. more is more:

\ larger magnitude progress meter during the load:
: false 0 ; 99 22 11 false echo! load  \ These are the same dots as usual but they're echoed contiguously here, since nothing else is to interleave with them.

\ another demo of how a stack element causes a (cheap) progress meter:
: false 0 ;  : true -1 ; : sload 44 false echo! load cr cr .s ; sload

\ not sure if this '\end.' is parsed during a download or not:

\end.
