
__PRELUDE

.G1

# ppifnest.g, 29 Oct 07
# built on: __DATE

frame invis ht __HT wid __WID left solid bot solid

coord x 0.5,10.5 y 0.8,__MAXY log y

label bot "Maximum nesting depth"
label left "Translation units" "" ""

ticks bot out at 1 "", 2, 3 "", 4, 5 "", 6, 7 "", 8, 9 "", 10, 11 ""
#ticks left out at 1, 10, 100, 1000, 10000, 100000 "", 264000 "264,000"
__LEFT_TICK_NUM

draw un solid times
next un at 8,__MAXY/2
next un at 9,__MAXY/2
".c files" ljust at 9.6,__MAXY/2

draw un solid times
copy "pptunest.d" thru {
   next un at $1, $2
}

draw un dashed bullet
next un at 8,__MAXY/5
next un at 9,__MAXY/5
".h files" ljust at 9.6,__MAXY/5

draw un dashed bullet
copy "pptunest.dh" thru {
   next un at $1, $2
}

.G2

