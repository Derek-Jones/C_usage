
__PRELUDE

.G1

# tokenonline.g,  3 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,320 y 1,__MAXY log y

label bot "Characters"
# using left shift the graph underneath
label left "Physical lines" "" ""
__LEFT_TICK_NUM

copy "numnonwhitesp.d" thru {
   times size -2 at $1, $2
}
copy "numnonwhitesp.dh" thru {
   bullet size -2 at $1, $2
}

times  at 240,__MAXY/10
".c files" ljust at 250,__MAXY/10
bullet  at 240,__MAXY/50
".h files" ljust at 250,__MAXY/50


graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,82 y 1,__MAXY log y

label bot "Tokens"
# using left shift the graph underneath
#label left "occurrences" "" ""
__LEFT_TICK

copy "tokonline.d" thru {
   times size -2 at $1, $2
}
copy "tokonline.dh" thru {
   bullet size -2 at $1, $2
}

times  at 60,__MAXY/10
".c files" ljust at 62.5,__MAXY/10
bullet  at 60,__MAXY/50
".h files" ljust at 62.5,__MAXY/50

.G2

