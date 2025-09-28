
__PRELUDE

.G1

# parennest.g, 22 Jan 08
# built on: __DATE

frame invis ht __HT wid __WID left solid bot solid

coord x 0.9,13 y 0.9,__MAXY log y

label bot "Nesting depth"
label left "Parentheses" "" ""

ticks bot at 1, 2 "", 3 "", 4 "", 5, 10, 15
#ticks left at 0.1 "0", 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw st solid times size -1
next st at 9,__MAXY/2
next st at 10,__MAXY/2
".c files" ljust at 10.6,__MAXY/2

draw st solid times size -1
copy "parennest.d" thru {
   next st at $1, $2
}

draw db dashed bullet size -1
next db at 9,__MAXY/7
next db at 10,__MAXY/7
".h files" ljust at 10.6,__MAXY/7

draw db dashed bullet size -1
copy "parennest.dh" thru {
   next db at $1, $2
}

.G2

