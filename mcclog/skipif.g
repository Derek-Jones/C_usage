
__PRELUDE

.G1

# skipif.g,  5 Sep 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.8,153 y 0.8,__MAXY log y

label bot "Physical lines skipped"
label left "Top level files" ""

#ticks bot out at 0, 1, 2, 8, 16, 24, 32
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

times at 100, __MAXY/2
"\fB#if\fR part" ljust at 105, __MAXY/2
bullet at 100, __MAXY/5
"\fB#else\fR part" ljust at 105, __MAXY/5

copy "skipped_if.d" thru {
   times size -1 at $1, $2
}

copy "skipped_else.d" thru {
   bullet size -1 at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e + (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0.8,153 y 0.8,__MAXY log y

label bot "Physical lines skipped"
label left "Translation units" right 0.1

#ticks bot out at 0, 1, 2, 8, 16, 24, 32
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK

copy "tu_if_total.d" thru {
   times size -1 at $1, $2
}

copy "tu_else_total.d" thru {
   bullet size -1 at $1, $2
}

.G2

