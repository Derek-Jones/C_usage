
__PRELUDE

.G1

# splice.g,  9 Mar 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.9,300 y 0.9,__MAXY log log

label bot "Splices"
# using left shift the graph underneath
label left "Lines" "" ""
__LEFT_TICK_NUM

copy "splice.d" thru {
   times size -1 at $1, $2
}
copy "splice.dh" thru {
   bullet size -2 at $1, $2
}

times  at 55,__MAXY/3
".c files" ljust at 65,__MAXY/3
bullet  at 55,__MAXY/10
".h files" ljust at 65,__MAXY/10

graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0.9,3200 y 0.9,__MAXY log log

label bot "Spliced line length"
#label left "occurrences" "" "" "" ""
__LEFT_TICK

copy "splicellen.d" thru {
   times size -2 at $1, $2
}
copy "splicellen.dh" thru {
   bullet size -2 at $1, $2
}

times  at 500,__MAXY/3
".c files" ljust at 650,__MAXY/3
bullet  at 500,__MAXY/10
".h files" ljust at 650,__MAXY/10

.G2

