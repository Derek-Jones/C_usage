
__PRELUDE

.G1

# calluse.g, 18 Dec 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,102 y 0.9,__MAXY log y

label bot "Function definitions"
label left "Translation units" "" ""

#ticks bot out at 1, 10, 100
__LEFT_TICK_NUM

copy "func_defs.d" thru {
   times size -1 at $1, $2+0.1
}

graph Q_2 with .Frame.w at Q_1.e + (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,100 y 0.9,__MAXY log y

label bot "Percentage called"
#label left "Translation units"

#ticks bot out at 1, 10, 100
__LEFT_TICK

copy "func_defs_called.d" thru {
   bullet size -2 at $1, $2+0.1
}

.G2

