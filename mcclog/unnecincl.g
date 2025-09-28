
__PRELUDE

.G1

# unnecincl.g, 27 Aug 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,20.5 y 0.8,__MAXY log y

label bot "Unnecessary headers \fB#include\fR'd"
label left "Translation units" ""

ticks bot out at 0, 5, 10, 15, 20
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw cd solid times size -1
copy "unnecincl.d" thru {
   next cd at $1, $2
}

.G2

