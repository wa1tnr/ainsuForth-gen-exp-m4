: farmer 989 ;
: purp 1 0 9 rgb ;
: orng 9 2 0 rgb ;

: pulstp
  s" delay  pin_no" drop drop
  over over
  1 swap pinwrite delay
  0 swap pinwrite delay ;

: red 5 0 0 rgb ;

.( that is a nice pale red )

: cyan 0 2 2 rgb ;

.( good pale cyan can go 0 1 1 rgb also )

: sda 21 ;

: scl 22 ;

: wiggle .( pulse SDA ten times)
  10 0 do
  111 sda pulstp
  loop ;

: inia 1 sda pinmode .( init gpio pin sda PUSH_PULL )
;

: emits 0 do emit loop ;

