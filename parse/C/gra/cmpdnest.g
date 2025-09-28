
__PRELUDE

.G1

# cmpdnest.gra, 22 Oct 07

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,33 y 0.9,__MAXY log y

ticks bot out at 0, 5, 10, 15 "", 20, 32
#ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15 "", 20, 32
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "Maximum nesting depth"
label left "Function definitions" "" ""

draw st solid times
next st at 18, __MAXY/2
next st at 20, __MAXY/2
"\fIcompound-statement\fRs" ljust at 21, __MAXY/2

draw st solid times

copy "cmpd_max_nesting.d" thru {
	next st at $1,$2
	}

draw sb solid bullet size -1
next sb at 18, __MAXY/6
next sb at 20, __MAXY/6
"blocks" ljust at 21, __MAXY/6

draw sb solid bullet size -2

copy "block_max_nesting.d" thru {
	next sb at $1,$2
	}

.G2

