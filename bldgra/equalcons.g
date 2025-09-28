
__PRELUDE

.G1

# equalcons.g, 18 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,256 y 0.5,__MAXY log y

label bot "Numeric value"
label left "Occurrences" "" ""

ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 10000, 25000
__LEFT_TICK_NUM

"binary \fB==\fR" ljust at 125, __MAXY
times ljust at 125, __MAXY/3
"decimal notation" ljust at 142, __MAXY/3
bullet ljust at 125, __MAXY/7
"hexadecimal notation" ljust at 142, __MAXY/7

draw cd solid times size -1
draw ch dotted bullet size -1
copy "eqeqcons.d" thru {
   times size -2 at $1, $3
   bullet size -2 at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,256 y 0.5,__MAXY log y

label bot "Constant value"
#label left "number of occurrences" "" ""

ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1 "", 10 "", 100 "", 1000 "", 10000 "", 25000 ""
__LEFT_TICK

"binary \fB!=\fR" ljust at 125, __MAXY

draw cd solid times size -1
draw ch dotted bullet size -1
copy "neqcons.d" thru {
   times size -2 at $1, $3
   bullet size -2 at $1, $2
}

.G2

