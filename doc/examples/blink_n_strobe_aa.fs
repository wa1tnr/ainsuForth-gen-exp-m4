\  Fri 22 Jun 21:37:41 UTC 2018
\  4737-a3b-009-

\ blink_n_strobe_aa.fs

warm  \ reboot
1 13 pinmode
: pon 1 13 pinwrite ;
: poff 0 13 pinwrite ;
: sdel 333 delay ;
: blinka pon sdel poff sdel ;
blinka blinka blinka blinka blinka
: ndel 55 delay ;
: blinkb pon ndel poff ndel ;
blinkb blinkb blinkb blinkb blinkb blinkb blinkb
: strobe 14 0 do blinkb loop ;
strobe
strobe strobe strobe strobe strobe
: lstrobe 5 0 do strobe loop ;
lstrobe
: astrobe 3 0 do blinkb loop 3 0 do cblink ndel loop ;
astrobe
astrobe astrobe astrobe
: xstrobe 14 0 do astrobe loop cr .s ;
xstrobe
\ end.
