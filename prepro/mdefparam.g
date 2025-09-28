
__PRELUDE

.G1

# mdefparam.g, 26 Apr 03
# built on: __DATE

frame invis ht __HT wid __WID left solid bot solid

coord x 0,18 y 0.9,__MAXY log y

label left "\fB#define\fR function-like macros" "" ""
label bot "Parameters"

#ticks bot out at 0, 10, 20, 30, 40, 50, 60, 70
#ticks left out at 1, 10, 100, 1000, 2300 "2300"
__LEFT_TICK_NUM

draw md solid times
next md at 15,__MAXY/5
next md at 17,__MAXY/5
".c files" ljust at 18,__MAXY/5

draw md solid times size -1
copy "mdefparam.d" thru {
   next md at $1, $2
}

draw md dashed bullet
next md at 15,__MAXY/2
next md at 17,__MAXY/2
".h files" ljust at 18,__MAXY/2

draw md dashed bullet size -1
copy "mdefparam.dh" thru {
   next md at $1,$2
}

.G2

