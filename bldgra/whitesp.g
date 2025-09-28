
__PRELUDE

.G1

# whitesp.g,  9 Mar 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.9,110 y 0.9,__MAXY log log

label bot "Whitespace characters between preprocessing tokens"
# using left shift the graph underneath
label left "Preprocessing token pairs" "" "" "" ""
__LEFT_TICK_NUM

copy "whitespace.d" thru {
   times size -1 at $1, $2
}
copy "whitespace.dh" thru {
   bullet size -1 at $1, $2
}

times  at 30,__MAXY/2
".c files" ljust at 35,__MAXY/2
bullet  at 30,__MAXY/7
".h files" ljust at 35,__MAXY/7

.G2

