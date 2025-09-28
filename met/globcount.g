
__PRELUDE

.G1

# globcount.g, 29 Nov 03
# built on: __DATE

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0,30 y 0,__MAXY/1.7

label bot "Identifiers declared"
label left "Translation units"

ticks bot out at 0, 5 "", 10 "100", 15 "", 20 "200", 25 "", 30 "300"
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_LIN_NUM

copy "globcount.d" thru {
   times at $1, $2
}

.G2

