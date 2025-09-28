
__PRELUDE

.G1

# blkdeclnest.gra, 23 Nov 03
# built on: __DATE

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.7,14 y 0.9,__MAXY log y

label bot "Block nesting"
label left "Object definitions" "" ""

ticks bot out at 1, 2 "", 3 "", 4 "", 5, 10, 15
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

draw st solid times

copy "locscope.d" thru {
   next st at $1, $2
}

.G2

