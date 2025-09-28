
__PRELUDE

.G1

# loopnest.g, 22 Oct 07

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.0,7.2 y 0.8,__MAXY log y

ticks bot out at 0, 1, 2, 3, 4, 5, 6 "", 7 "", 8 "", 9 "", 10 ""
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "Maximum nesting depth"
label left "Function definitions" "" ""

draw em solid times
next em at 4.5,__MAXY/2
next em at 5.5,__MAXY/2
".c files" ljust at 6,__MAXY/2

draw em solid times

copy "loop_max_nesting.d" thru {
	next em at $1,$2
	}

draw em solid bullet
next em at 4.5,__MAXY/7
next em at 5.5,__MAXY/7
"Embedded" ljust at 6,__MAXY/7

draw em solid bullet

copy thru {
	next em at $1,$2
	} until "XXX"
1 __MAXY*0.906
2 __MAXY*0.079
3 __MAXY*0.011
4 __MAXY*0.001
5 __MAXY*0.000
XXX

.G2

