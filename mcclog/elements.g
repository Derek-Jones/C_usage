
__PRELUDE

.G1

# elements.g,  3 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0.9,100000 y 0.9,__MAXY log log

label bot "Number of elements"
label left "Array declarations" ""

ticks bot out at 1, 2, 4, 10, 64, 256, 1024 "1,024", 8192 "8,192", 65536 "65,536"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "num_elems.d" thru {
   times size -2 at $1, $2
}

.G2

