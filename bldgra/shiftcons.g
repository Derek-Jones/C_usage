
__PRELUDE

.G1

# shiftcons.g, 17 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,65 y 0.5,__MAXY log y

label bot "Numeric value"
label left "Occurrences" "" ""

ticks bot out at 0, 2, 4, 8, 16, 24, 32, 48, 64
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

"binary  \fB<<\fR" ljust at 32, __MAXY
times ljust at 32, __MAXY/2
"decimal notation" ljust at 36, __MAXY/2
bullet ljust at 32, __MAXY/4.0
"hexadecimal notation" ljust at 36, __MAXY/4.0

draw cd solid times size -1
draw ch dotted bullet size -1
copy "lshiftcons.d" thru {
   times at $1, $3
   bullet at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,65 y 0.5,__MAXY log y

label bot "Numeric value"
#label left "number of occurrences" "" ""

ticks bot out at 0, 2, 4, 8, 16, 24, 32, 48, 64
#ticks left out at 1 "", 10 "", 100 "", 1000 "", 10000 ""
__LEFT_TICK

"binary  \fB>>\fR" ljust at 32, __MAXY

draw cd solid times size -1
draw ch dotted bullet size -1
copy "rshiftcons.d" thru {
   times at $1, $3
   bullet at $1, $2
}

.G2

