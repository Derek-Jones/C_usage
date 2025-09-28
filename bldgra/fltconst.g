
__PRELUDE

.G1

# fltconst.g, 03 Dec 15
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x -25,25 y 0.9,__MAXY log y

label bot "characters before dp      characters after dp "
label left "\fIfloating-constant\fRs" ""

tick bot at -25 "", -20 "20", -15 "", -10 "10", -5 "", 0 "dp", 5 "", 10, 15 "", 20, 25 ""
__LEFT_TICK_NUM

copy "fltconst.d" thru {
   times at -$1, $6
   times at $1, $7
}
copy "fltconst.dh" thru {
   bullet at -$1, $6
   bullet at $1, $7
}

times  at 14,__MAXY/3
".c files" ljust at 16,__MAXY/3
bullet  at 14,__MAXY/8
".h files" ljust at 16,__MAXY/8

graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,26 y 0.9,__MAXY log y

label bot "Digits in \fIfloating-constant\fR"
#label left "occurrences" ""

__LEFT_TICK

# subtract 1 for the decimal point

copy "fltconst.d" thru {
   times at $1, $5-1
}
copy "fltconst.dh" thru {
   bullet at $1, $5-1
}

times  at 19,__MAXY/3
".c files" ljust at 21,__MAXY/3
bullet  at 19,__MAXY/8
".h files" ljust at 21,__MAXY/8

.G2

