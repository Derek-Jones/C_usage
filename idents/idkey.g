
__PRELUDE

.G1

# idkey.gra,  6 Aug 03
# built on: __DATE

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 1,452 y 0.9,__MAXY log log

label bot "Keyboard distance"
label left "Identifier pairs" "" "" "" ""

#ticks bot out at 1, 10, 20, 30, 40, 50
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

times at 240,__MAXY/2
"posgresql" ljust at 241,__MAXY/2

copy "postkeyd.d" thru {
   times at $1, $2
}

.G2

