.( trellis m4 stuff)

.( to setup neopixel color tuples)
.( and to use sda and scl as gpio)

: purp 1 0 9 rgb ;
: orng 9 2 0 rgb ;

: pulstp .( pulse gpio pin with delay )
.( delay  pin_no)
over over
1 swap pinwrite delay
0 swap pinwrite delay ;

.( You can also:

: fulstp .( comment
s" comment here" drop drop
.( those two drops remove the
.( results of addr-d length
1 drop ;

: red 5 0 0 rgb ;
.( that is a nice pale red)

: cyan 0 2 2 rgb ;
.( good pale cyan X also try 0 1 1 rgb)

: sda 21 ;
: scl 22 ;

: wiggle .( pulse SDA ten times)
10 0 do
111 sda pulstp
loop ;
: inia 1 sda pinmode .( init gpio pin sda as PUSH_PULL)
;
