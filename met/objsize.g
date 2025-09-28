
__PRELUDE

.G1

# objsize.g, 27 Jul 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0.8,2500000 y 0.8,__MAXY log log

label bot "Size (bytes)"
label left "Objects" "" "" ""

ticks bot out at 1, 10, 100, 1000 "1,000", 10000 "10,000", 100000 "100,000", 1000000 "1,000,000"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "objsize.d" thru {
   times size -2 at $1, $2
}

.G2

