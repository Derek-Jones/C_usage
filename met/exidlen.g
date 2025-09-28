
__PRELUDE

.G1

# exidlen.gra, 14 Jul 02
# built on: __DATE

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 1,52 y 0.9,__MAXY log y

label bot "Identifier length"
label left "Identifiers" "" "" ""

ticks bot out at 1, 10, 20, 30, 40, 50
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

draw un solid times
next un at 37,__MAXY/1.07
next un at 40,__MAXY/1.07
"all identifiers" ljust at 41,__MAXY/1.07

draw un solid times
copy "exidlen.d" thru {
   next un at $1, $2
}

draw un solid bullet
next un at 37,__MAXY/3
next un at 40,__MAXY/3
"unique identifiers" ljust at 41,__MAXY/3

draw un solid bullet
copy "exidlenuniq.d" thru {
   next un at $1, $2
}

draw un dotted times
next un at 37,__MAXY/9
next un at 40,__MAXY/9
"all identifiers that are words" ljust at 41,__MAXY/8.9

draw un dotted times
copy "exidwordlen.d" thru {
   next un at $1, $2
}

draw un dotted bullet
next un at 37,__MAXY/23
next un at 40,__MAXY/23
"unique identifiers that are words" ljust at 41,__MAXY/23

draw un dotted bullet
copy "exidwordlenuniq.d" thru {
   next un at $1, $2
}

.G2

