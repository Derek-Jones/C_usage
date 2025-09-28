
__PRELUDE

.G1

# incnest.g, 27 Jul 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.8,14 y 0.8,__MAXY log y

label bot "Nesting depth"
label left "\fB#include\fRs" ""

ticks bot out at 1, 2 "", 3 "", 4 "", 5, 10, 15, 20
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw nl solid times

copy "incnest.d" thru {
   next nl at $1, $2
}

.G2

