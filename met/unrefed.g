
__PRELUDE

.G1

# unrefed.g, 16 Feb 04
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,9 y 0.9,__MAXY log y

label bot "Objects not referenced"
label left "Function definitions" "" ""

#ticks bot out at 1, 10, 100, 1000 "1,000", 10000 "10,000", 100000 "100,000", 1000000 "1,000,000"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw ts solid times size -1
next ts at 5,__MAXY/2
next ts at 6,__MAXY/2
"Local objects" ljust at 6.2,__MAXY/2
draw ts solid times size -1

copy "obj_unrefed.d" thru {
   next ts at $1, $2
}

draw bs solid bullet size -1
next bs at 5,__MAXY/5
next bs at 6,__MAXY/5
"Parameters" ljust at 6.2,__MAXY/5
draw bs solid bullet size -1

copy "arg_unrefed.d" thru {
   next bs at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e + (0.0, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,15.3 y 0.9,__MAXY log y

label bot "Objects with excessive scope"
#label left "Function definitions" "" ""

#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK

draw ts solid times size -1

copy "obj_nestedref.d" thru {
   next ts at $1, $2
}

.G2

