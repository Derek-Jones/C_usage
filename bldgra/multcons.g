
__PRELUDE

.G1

# multcons.g, 17 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,256 y 0.5,__MAXY log y

label bot "Numeric value"
label left "Occurrences" "" ""

ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 2500
__LEFT_TICK_NUM

"binary \s+1\fB*\fR\s-1" ljust at 125, __MAXY
times ljust at 125, __MAXY/2.2
"decimal notation" ljust at 142, __MAXY/2.2
bullet ljust at 125, __MAXY/5.0
"hexadecimal notation" ljust at 142, __MAXY/5.0

draw cd solid times size -1
draw ch dotted bullet size -1
copy "multcons.d" thru {
   times size -1 at $1, $3
   bullet at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,256 y 0.5,__MAXY log y

label bot "Numeric value"
#label left "number of occurrences" "" ""

ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1 "", 10 "", 100 "", 1000 "", 2500 ""
__LEFT_TICK

"binary \s+1\fB/\fR\s-1" ljust at 125, __MAXY

draw cd solid times size -1
draw ch dotted bullet size -1
copy "divcons.d" thru {
   times size -1 at $1, $3
   bullet at $1, $2
}

.G2

