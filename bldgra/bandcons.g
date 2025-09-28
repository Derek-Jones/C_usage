
__PRELUDE

.G1

# bandcons.g, 18 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,285 y 0.5,__MAXY log y

label bot "Numeric value"
label left "Occurrences" "" ""

ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 3500
__LEFT_TICK_NUM

"binary  \s+1\fB&\fR\s-1" ljust at 265, __MAXY
times ljust at 265, __MAXY/2.2
"decimal notation" ljust at 282, __MAXY/2.2
bullet ljust at 265, __MAXY/5
"hexadecimal notation" ljust at 282, __MAXY/5

draw cd solid times size -1
draw ch dotted bullet size -1
copy "bandcons.d" thru {
   times size -1 at $1, $3
   bullet size -1 at $1, $2
}

.G2

