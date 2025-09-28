
__PRELUDE

.G1

# sameinc.g, 11 Jan 08
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.8,11 y 0.8,__MAXY log y

label bot "Times \fB#include\fRd"
label left "Number of \fB#include\fRs" "" ""

ticks bot out at 1, 2 "", 3 "", 4 "", 5, 10
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw na dashed times
next na at 6,__MAXY/2
next na at 7,__MAXY/2
"All \fB#include\fRs" size -1 ljust at 7.4,__MAXY/2
draw nu solid delta
next nu at 6,__MAXY/7
next nu at 7,__MAXY/7
"User \fB#include\fRs" size -1 ljust at 7.4,__MAXY/7
draw nu3 dashed bullet
next nu3 at 6,__MAXY/25
next nu3 at 7,__MAXY/25
"Nested user \fB#include\fRs" size -1 ljust at 7.4,__MAXY/25

draw na dashed times
draw nu solid delta
#draw nu1 solid square
draw nu3 dashed bullet

copy "sameinc.d" thru {
   next nu at $1, $2
   next nu3 at $1, $4
   next na at $1, $5
}

.G2

