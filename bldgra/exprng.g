
__PRELUDE

.G1

# exprng.g, 10 Mar 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x -102,102 y 0.9,__MAXY log y

label bot "Exponent value"
# using left shift the graph underneath
label left "\fIfloating-constant\fRs"

#ticks bot out at -40, -30 "", -20, -10 "", 0, 10 "", 20, 30 "", 40
__LEFT_TICK_NUM

copy "exprng.d" thru {
   times size -1 at $1, $2
}
copy "exprng.dh" thru {
   bullet at $1, $2
}

times  at 70,__MAXY/2
".c files" ljust at 75,__MAXY/2
bullet  at 70,__MAXY/3
".h files" ljust at 75,__MAXY/3

.G2

