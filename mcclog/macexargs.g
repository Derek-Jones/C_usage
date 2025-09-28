
__PRELUDE

.G1

# macexargs.g,  1 Jan 05
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,15.5 y 0.9,__MAXY log y

label bot "Arguments"
label left "Function-macro expansions" "" "" ""

ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw st solid times
copy "macex_args.d" thru {
   next st at $1, $2
}

.G2

