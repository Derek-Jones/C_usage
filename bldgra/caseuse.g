
__PRELUDE

.G1

# caseuse.g,  3 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,55 y 0.9,__MAXY log y

label bot "\fBcase\fR labels"
label left "\fBswitch\fR statements" "" ""

ticks bot out at 0, 10, 20, 30, 40, 50, 60
#ticks left out at 1, 10, 100, 1000, 3700
__LEFT_TICK_NUM

copy "caseswitch.d" thru {
   times at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e + (0.3, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,55 y 0.9,__MAXY log y

label bot "\fBcase\fR labels"
label left "Statements" "" ""

ticks bot out at 0, 10, 20, 30, 40, 50, 60
#ticks left out at 1, 10, 100, 1000, 3700
__LEFT_TICK_NUM

copy "casestmt.d" thru {
   times at $1, $2
}

.G2

