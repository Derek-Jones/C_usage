
__PRELUDE

.G1

# idlev.gra,  5 Feb 08
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 1,52 y 0.9,__MAXY log y

label bot "Levenstein distance"
label left "Identifier pairs" "" "" "" "" ""

ticks bot out at 1, 10, 20, 30, 40, 50
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

#draw un solid times
#next un at 30,__MAXY/1.07
#next un at 35,__MAXY/1.07
#"all identifiers" ljust at 36,__MAXY/1.07

bullet at 45,__MAXY/2
"linux" ljust at 46,__MAXY/2

copy "linuxlev.d" thru {
   bullet size -1 at $1, $2
}

times at 45,__MAXY/9
"gcc" ljust at 46,__MAXY/9

copy "gcclev.d" thru {
   times size -1 at $1, $2
}

square size -1 at 45,__MAXY/40
"idsoftware" ljust at 46,__MAXY/40

copy "idsoftlev.d" thru {
   square size -2 at $1, $2
}

star at 45,__MAXY/180
"postgresql" ljust at 46,__MAXY/180

copy "postlev.d" thru {
   star size -1 at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e + (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 1,52 y 0.9,__MAXY log y

label bot "Keyboard-Levenstein distance"
#label left "Identifier pairs" "" "" "" "" ""

ticks bot out at 1, 10, 20, 30, 40, 50
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK

#draw un solid times
#next un at 30,__MAXY/1.07
#next un at 35,__MAXY/1.07
#"all identifiers" ljust at 36,__MAXY/1.07

#bullet at 45,__MAXY/2
#"linux" ljust at 46,__MAXY/2
#
#copy "linuxlev.d" thru {
#   bullet size -1 at $1, $2
#}

times at 45,__MAXY/9
"gcc" ljust at 46,__MAXY/9

copy "gccklev.d" thru {
   times size -1 at $1, $2/2
}

square size -1 at 45,__MAXY/40
"idsoftware" ljust at 46,__MAXY/40

copy "idsoftklev.d" thru {
   square size -2 at $1, $2/2
}

star at 45,__MAXY/180
"openafs" ljust at 46,__MAXY/180

copy "openafsklev.d" thru {
   star size -1 at $1, $2/2
}

.G2

