1 13 pinMode
: pon 1 13 pinWrite ;
: poff 0 13 pinWrite ;
pon
poff
: blinks 0 do
pon 300 delay
poff 400 delay
loop ;
3 blinks
5 blinks
17 blinks
