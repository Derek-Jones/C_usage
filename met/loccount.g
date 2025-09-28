
__PRELUDE

.G1

# loccount.gra, 14 Jul 02
# built on: __DATE

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,51 y 0.9,__MAXY log y

label bot "Objects defined"
label left "Function definitions" "" ""

ticks bot out at 0, 10, 20, 30, 40, 50
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

draw st solid times size -1

copy "locobjcnt.d" thru {
   next st at $1, $2
}

.G2

