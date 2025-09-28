
__PRELUDE

.G1

# idonline.gra,  2 Aug 03
# built on: __DATE

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,31 y 0.9,__MAXY log y

label bot "Identifiers"
label left "Physical lines" "" "" ""

ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15 "", 20, 25 "", 30
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

draw un solid times
copy "idonline.d" thru {
   next un at $1, $2
}

.G2

