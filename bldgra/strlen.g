
__PRELUDE

.G1

# strlen.g,  8 Jun 02
# built on: __DATE

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,255 y 0.8,__MAXY log y

label bot "Characters"
label left "String literals" "" ""

ticks bot at 0, 50, 100, 150, 200, 250
#ticks left at 0.1 "0", 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "strlen.d" thru {
   times size -2  at $1, $2
}

.G2

