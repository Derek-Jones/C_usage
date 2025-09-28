
__PRELUDE

.G1

# sameiddecl.g,  3 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.8,21 y 0.9,__MAXY log y

label bot "Number using the same spelling"
label left "Identifier declarations" "" ""

ticks bot out at 1, 5, 10, 15, 20
__LEFT_TICK_NUM

bullet at 15, __MAXY/2
"members" ljust at 16, __MAXY/2
square size -1 at 15, __MAXY/5
"parameters" ljust at 16, __MAXY/5
times at 15, __MAXY/16
"local objects" ljust at 16, __MAXY/16

copy "same_member_id.d" thru {
   bullet size -1 at $1, $2
}

copy "same_param_id.d" thru {
   square size -2 at $1, $2
}

copy "same_locobj_id.d" thru {
   times size -1 at $1, $2
}

.G2

