
__PRELUDE

.G1

# hashindent.g, 22 Apr 03
# built on: __DATE

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0,50 y 0.9,__MAXY log y

label bot "Indentation of \fB#\fR"
label left "Visible lines" "" ""

ticks bot out at 0, 2 "", 4, 6 "", 8, 12, 16, 20 "", 24, 32, 40, 48
#ticks left out at 1, 10, 100, 1000, 10000, 100000 "", 264000 "264,000"
__LEFT_TICK_NUM

draw un solid times
next un at 40,__MAXY/3
next un at 43,__MAXY/3
".c files" ljust at 44,__MAXY/3

draw un solid times
copy "hashinden.d" thru {
   next un at $1, $2
}

draw un dashed bullet
next un at 40,__MAXY/10
next un at 43,__MAXY/10
".h files" ljust at 44,__MAXY/10

draw un dashed bullet
copy "hashinden.dh" thru {
   next un at $1, $2
}

.G2

