
__PRELUDE

.G1

# indobjuse.g, 25 Nov 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*0.9 left solid bot solid

coord x 0,101 y 0.9,__MAXY log y

label bot "References to same object (no linkage)"
label left "Function definitions" "" ""

#ticks bot out at 1, 10, 100
__LEFT_TICK_NUM

copy "ind_loc_obj_access.d" thru {
   times size -2 at $1, $2
}

copy "ind_loc_obj_modify.d" thru {
   bullet size -2 at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e - (0.2, 0)

frame invis ht __HT wid __WID*0.72 left solid bot solid

coord x 0,81 y 0.9,__MAXY log y

label bot "References to same object (external linkage)   "
#label left "Functions" "" ""

#ticks bot out at 1, 10, 100
__LEFT_TICK

times size -1 at 20,__MAXY/5
"read of object" ljust at 23,__MAXY/5
bullet size -1 at 20,__MAXY/15
"modification of object" ljust at 23,__MAXY/15

copy "ind_ext_obj_access.d" thru {
   times size -2 at $1, $2
}

copy "ind_ext_obj_modify.d" thru {
   bullet size -2 at $1, $2
}

graph Q_3 with .Frame.w at Q_2.e - (0.2, 0)

frame invis ht __HT wid __WID*0.54 left solid bot solid

coord x 0,61 y 0.9,__MAXY log y

label bot "  Same object (internal linkage)"
#label left "functions" "" ""

#ticks bot out at 1, 10, 100
__LEFT_TICK

copy "ind_int_obj_access.d" thru {
   times size -2 at $1, $2
}

copy "ind_int_obj_modify.d" thru {
   bullet size -2 at $1, $2
}

.G2

