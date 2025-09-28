
__PRELUDE

.G1

# macexpand.g,  3 Sep 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,40 y 0.9,__MAXY log y

label bot "Macro names expanded"
label left "Translation units" "" ""

ticks bot out at 4 "", 8 "100", 16 "200", 24 "", 32 "400"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw st solid times size -1
next st at 25,__MAXY/2
next st at 27,__MAXY/2
"all macro expansions" ljust at 28,__MAXY/2

draw st solid times size -1

copy "all_m_expands.d" thru {
   next st at $1, $2
}

draw sb solid bullet -1
next sb at 25,__MAXY/5
next sb at 27,__MAXY/5
"function-macro expansions" ljust at 28,__MAXY/5

draw sb solid bullet -1

copy "func_m_expands.d" thru {
   next sb at $1, $2
}

.G2

