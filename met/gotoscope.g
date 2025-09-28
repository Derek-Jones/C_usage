
__PRELUDE

.G1

# gotoscope.g,  3 Dec 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.8, 16 y 0.9,__MAXY log y

label bot "Scope nesting level"
label left "Occurrences" "" ""

ticks bot out at 1, 2 "", 3 "", 4 "", 5, 10, 15
__LEFT_TICK_NUM

draw st solid times size -1
next st at 8,__MAXY/2
next st at 9.5,__MAXY/2
"\fBgoto\fR statements" ljust at 10.2,__MAXY/2
draw sb solid bullet size -1
next sb at 8,__MAXY/5
next sb at 9.5,__MAXY/5
"labeled statements" ljust at 10.2,__MAXY/5

draw st solid times size -1

copy "goto_scope.d" thru {
   next st at $1, $2
}

draw sb solid bullet size -1

copy "label_scope.d" thru {
   next sb at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x -12,4 y 0.9,__MAXY log y

label bot "Scope nesting difference"
#label left "Occurrences" "" ""

ticks bot out at -15, -10, -5, -4 "", -3 "", -2 "", -1 "", 0, 1 "", 2 ""
__LEFT_TICK

draw st solid times size -1

copy "goto_scope_diff.d" thru {
   next st at $1, $2
}

.G2

