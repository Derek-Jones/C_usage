
__PRELUDE

.G1

# totobjref.g, 25 Nov 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0,101 y 0.9,__MAXY log y

label bot "References to any object"
label left "Function definitions" "" ""

#ticks bot out at 1, 10, 100, 1000 "1,000", 10000 "10,000", 100000 "100,000", 1000000 "1,000,000"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "obj_access.d" thru {
   times size -2 at $1, $2
}

copy "obj_modify.d" thru {
   square size -3 at $1, $2
}

copy "obj_ref.d" thru {
   bullet size -2 at $1, $2
}

.G2

