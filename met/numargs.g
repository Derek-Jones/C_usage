
__PRELUDE

.G1

# numargs.g, 31 Aug 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,21 y 0.9,__MAXY log y

label bot "Arguments"
label left "Function calls" "" ""

#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw ts solid times size -1

copy "arg_count.d" thru {
   next ts at $1, $2
}

.G2

