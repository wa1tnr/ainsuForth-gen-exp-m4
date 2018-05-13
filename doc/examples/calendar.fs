decimal

: xcell ." xxx  " ;
: cellrow 
  xcell xcell xcell xcell xcell xcell xcell
  xcell xcell xcell xcell xcell xcell ;
: rowac ." 1    2    3" ; : rowad ." 4    5    6    7" ;
: rowba ." 2    3    4" ; : rowbb ." 5    6    7" ;
: rowbc ." 8    9   10 " ; : rowbd ." 11   12   13   14" ;
: rowca ." 9   10   11" ; : rowcb ." 12   13   14" ;
: rowcc ." 15   16   17" ; : rowcd ." 18   19   20   21" ;
: rowda ." 16   17   18" ; : rowdb ." 19   20   21" ;
: rowdc ." 22   23   24" ; : rowdd ." 25   26   27   28" ;
: rowea ." 23   24   25" ; : roweb ." 26   27   28" ;
: rowec ." 29   30   31" ; : rowfa ." 30   31" ;
: row1 32 spaces rowac 4 spaces rowad cr ;
: row2 2 spaces rowba 4 spaces rowbb 4 spaces rowbc 2 spaces rowbd cr ;
: row3 2 spaces rowca 3 spaces rowcb 3 spaces rowcc 3 spaces rowcd cr ;
: row4 space rowda 3 spaces rowdb 3 spaces rowdc 3 spaces rowdd cr ;
: row5 space rowea 3 spaces roweb 3 spaces rowec 3 spaces cr ;
: row6 space rowfa ;
: samp cr 42 spaces xcell cr cellrow cr ;
: go samp row1 row2 row3 row4 row5 row6 ;

