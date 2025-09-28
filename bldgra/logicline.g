
__PRELUDE

.G1

# logicline.g,  9 Mar 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,320 y 0.9,__MAXY log y

label bot "Characters"
# using left shift the graph underneath
label left "Lines" "" "" ""
__LEFT_TICK_NUM

ticks bot out at 0, 50 "", 100, 150 "", 200, 250 "", 300

copy "physlinelen.d" thru {
   times size -2 at $1, $2
}
copy "physlinelen.dh" thru {
   bullet size -2 at $1, $2
}

times  at 240,__MAXY/2
".c files" ljust at 250,__MAXY/2
bullet  at 240,__MAXY/6
".h files" ljust at 250,__MAXY/6

.G2

