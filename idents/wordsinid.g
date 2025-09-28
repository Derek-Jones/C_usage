
__PRELUDE

.G1

# wordsinid.gra,  4 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,15.2 y 0.9,__MAXY log y

label bot "Number of components"
label left "Identifiers" "" "" "" ""

ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

draw un dashed bullet
next un at 7,__MAXY/7
next un at 8,__MAXY/7
"components that are words" ljust at 9,__MAXY/7

draw un dashed bullet
copy "idwords.d" thru {
   next un at $1, $2
}

draw un solid times
next un at 7,__MAXY/2
next un at 8,__MAXY/2
"underscore delimited" ljust at 9,__MAXY/2

draw un solid times
copy "idunders.d" thru {
   next un at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e + (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,15.2 y 0.9,__MAXY log y

label bot "Number of components"
#label left "Identifiers" "" "" "" ""

ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK

draw un dashed bullet
next un at 7,__MAXY/7
next un at 8,__MAXY/7
"components that are words" ljust at 9,__MAXY/7

draw un dashed bullet
copy "idcamelwords.d" thru {
   next un at $1, $2
}

draw un solid times
next un at 7,__MAXY/2
next un at 8,__MAXY/2
"camelcase delimited" ljust at 9,__MAXY/2

draw un solid times
copy "idcamel.d" thru {
   next un at $1, $2
}

.G2

