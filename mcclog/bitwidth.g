
__PRELUDE

.G1

# bitwidth.g,  3 Jan 05
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,33 y 0.9,__MAXY log y

label bot "Bits"
label left "Bit-field declarations" ""

ticks bot out at 0, 1, 4 "", 8, 16, 24, 32
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "bitf_width.d" thru {
   times size -1 at $1, $2
}

.G2

