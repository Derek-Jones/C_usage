
__PRELUDE

.G1

# macdefs.g,  3 Sep 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,41 y 0.9,__MAXY log y

label bot "Macro definitions"
label left "Translation units" "" ""

ticks bot out at 0, 5 "", 10 "100", 15 "", 20 "200", 25 "", 30 "300", 35 "", 40 "400"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw st solid times size -1
next st at 25,__MAXY/2
next st at 27,__MAXY/2
"all macro \fB#define\fR" ljust at 28,__MAXY/2

draw st solid times size -1

copy "all_macro_defines.d" thru {
   next st at $1, $2
}

draw sb solid bullet -1
next sb at 25,__MAXY/5
next sb at 27,__MAXY/5
"function-macro \fB#define\fR" ljust at 28,__MAXY/5

draw sb solid bullet -1

copy "func_macro_defines.d" thru {
   next sb at $1, $2
}

.G2

