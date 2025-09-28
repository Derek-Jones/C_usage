
__PRELUDE

.G1

# duplines.g, 18 Dec 07
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.8, 21 y 0.9,__MAXY log y

label bot "Source files"
label left "Number of duplicates" "" ""

ticks bot out at 1, 5, 10, 15, 20
__LEFT_TICK_NUM

draw st solid times size -1
next st at 13,__MAXY/2
next st at 14,__MAXY/2
"4 or more lines duplicated" ljust at 14.5,__MAXY/2
draw sb solid bullet size -1
next sb at 13,__MAXY/5
next sb at 14,__MAXY/5
"8 or more lines duplicated" ljust at 14.5,__MAXY/5

draw st solid times size -1

copy "dup_file_cnt.d" thru {
   next st at $1, $2
}

draw sb solid bullet size -1

copy "big_dup_file_cnt.d" thru {
   next sb at $1, $2
}

#graph Q_2 with .Frame.w at Q_1.e - (0.1, 0)

.G2

