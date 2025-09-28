
__PRELUDE

.G1

# indentdiff.g, 22 Mar 03
# built on: __DATE

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x -102,102 y 0.9,__MAXY log y

label bot "Indentation difference"
label left "Lines" "" "" ""

ticks bot out at -100, -75, -50, -25, 0, 25, 50, 75, 100
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "", 2046000 "2,046,000"
__LEFT_TICK_NUM

draw un solid
copy "indentdiff.d" thru {
   next un at $1-250, $2
}

.G2

