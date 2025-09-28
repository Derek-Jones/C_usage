
__PRELUDE

.G1

# totobjuse.g, 25 Nov 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.0 left solid bot solid

coord x 0,101 y 0.9,__MAXY log y

label bot "References to objects with no linkage"
label left "Function definitions" "" ""

#ticks bot out at 1, 10, 100, 1000 "1,000", 10000 "10,000", 100000 "100,000", 1000000 "1,000,000"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "loc_obj_access.d" thru {
   times size -2 at $1, $2
}

copy "loc_obj_modify.d" thru {
   bullet size -2 at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e - (0.2, 0)

frame invis ht __HT wid __WID*0.8 left solid bot solid

coord x 0,81 y 0.9,__MAXY log y

label bot "References to objects with external linkage"
#label left "functions" "" ""

#ticks bot out at 1, 10, 100, 1000 "1,000", 10000 "10,000", 100000 "100,000", 1000000 "1,000,000"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK

times size -1 at 20,__MAXY/5
"read of object" ljust at 23,__MAXY/5
bullet size -1 at 20,__MAXY/15
"modification of object" ljust at 23,__MAXY/15

copy "ext_obj_access.d" thru {
   times size -2 at $1, $2
}

copy "ext_obj_modify.d" thru {
   bullet size -2 at $1, $2
}

graph Q_3 with .Frame.w at Q_2.e - (0.2, 0)

frame invis ht __HT wid __WID*0.6 left solid bot solid

coord x 0,61 y 0.9,__MAXY log y

label bot "Objects with internal linkage"
#label left "functions" "" ""

#ticks bot out at 1, 10, 100, 1000 "1,000", 10000 "10,000", 100000 "100,000", 1000000 "1,000,000"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK

copy "int_obj_access.d" thru {
   times size -2 at $1, $2
}

copy "int_obj_modify.d" thru {
   bullet size -2 at $1, $2
}

.G2

