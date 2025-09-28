
__PRELUDE

.G1

# sunest.gra,  1 Jan 05

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.8,11 y 0.9,__MAXY log y

ticks bot out at 1, 2, 3, 4, 5, 10
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "Nesting depth"
label left "\fBstruct\fR/\fBunion\fR definitions" "" ""

draw st solid times
next st at 6.5,__MAXY/2
next st at 7.5,__MAXY/2
".c files" ljust at 8,__MAXY/2

draw st solid times

copy "su_nesting.d" thru {
	next st at $1,$2
	}

draw sb solid bullet
next sb at 6.5,__MAXY/5
next sb at 7.5,__MAXY/5
".h files" ljust at 8,__MAXY/5

draw sb solid bullet

copy "su_nesting.dh" thru {
	next sb at $1,$2
	}

.G2

