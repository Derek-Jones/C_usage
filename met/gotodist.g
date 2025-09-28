
__PRELUDE

.G1

# gotodist.g, 27 Aug 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x -303,303 y 0.9,__MAXY log y

label bot "Line difference"
label left "\fBgoto\fR statements" "" ""

ticks bot out at -300, -200, -100, 0, 100, 200, 300
__LEFT_TICK_NUM

copy "goto_distance.d" thru {
   bullet size -2 at $1, $2
}

.G2

