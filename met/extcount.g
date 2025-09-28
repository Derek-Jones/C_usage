
__PRELUDE

.G1

# extcount.g,  4 Aug 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,26 y 0.9,__MAXY log y

label bot "\fIexternal-declaration\fRs"
label left "Translation units" ""

ticks bot out at 0, 5 "", 10 "500", 15 "", 20 "1,000", 25 ""
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

copy "externcount.d" thru {
   times at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e + (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,102 y 0.9,__MAXY log y

label bot "\fIfunction-definition\fRs"
#label left "occurrences" "" ""

#ticks bot out at 0, 10, 20
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK

copy "funcdefcount.d" thru {
   times size -1 at $1, $2
}

.G2

