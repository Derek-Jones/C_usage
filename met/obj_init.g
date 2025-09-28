
__PRELUDE

.G1

# obj_init.g,  7 Dec 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.1 left solid bot solid

coord x 0,100 y 0.9,__MAXY log y

label bot "Initialized objects with no linkage"
label left "Function definitions" "" ""

#ticks bot out at 1, 10, 100
__LEFT_TICK_NUM

copy "loc_init.d" thru {
   times size -2 at $1, $2+0.1
}

graph Q_2 with .Frame.w at Q_1.e + (0.2, 0)

frame invis ht __HT wid __WID*1.1 left solid bot solid

coord x 0,100 y 0.9,__MAXY log y

label bot "Initialized objects with internal linkage"
label left "Translation units"

#ticks bot out at 1, 10, 100
__LEFT_TICK

copy "tu_int_init.d" thru {
   times size -2 at $1, $2+0.1
}

.G2

