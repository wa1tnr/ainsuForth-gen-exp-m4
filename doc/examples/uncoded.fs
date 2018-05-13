\ Wed Jan 31 00:27:18 UTC 2018
\ 4737-a0e-01a-

\  uncoded.fs
0 [if]   uncoded.fs
    forth words not yet coded anywhere seen by ainsuForth.

Copyright (C) 1991-2004 by AM Research, Inc.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

For LGPL information:   http://www.gnu.org/copyleft/lesser.txt
For application information:   http://www.amresearch.com

[then]

0 [if]

This Forth (amrFORTH) was developed by :
    Albert Lee Mitchell and
    Charles Shattuck
[then]

: within  ( n lo hi  - flag)
    push over pop <  push < not  pop and ;

\ within is a standard forth word that is not used often enough to be
\ included in a small forth kernel.  It returns a true or false flag
\ if the number "n" is greater or equal to "lo" and also less than "hi".

\ from:  appnote005 - amrFORTH v6

