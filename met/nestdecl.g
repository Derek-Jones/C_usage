
__PRELUDE

.G1

# nestdecl.g, 27 Aug 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,6.5 y 0.9,__MAXY log y

label bot "Declarator nesting"
label left "Declarations" "" ""

ticks bot out at 0, 1, 2, 3, 4, 5, 6 "", 7 "", 8 "", 9 "", 10
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw cd solid times

copy "nestdecl.d" thru {
   next cd at $1, $2
}

.G2

