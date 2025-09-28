
__PRELUDE

.G1

# selectnest.gra, 22 Oct 07

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.7,15.4 y 0.9,__MAXY log y

ticks bot out at 1, 5, 10, 15, 20
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "Nesting depth"
label left "\fIselection-statement\fRs" "" ""

draw em solid times
next em at 10.5,__MAXY/2
next em at 11.5,__MAXY/2
".c files" ljust at 12,__MAXY/2

draw em solid times

copy "select_max_nesting.d" thru {
	next em at $1,$2
	}

draw em solid bullet
next em at 10.5,__MAXY/5
next em at 11.5,__MAXY/5
"Embedded" ljust at 12,__MAXY/5

draw em solid bullet

# the value for depth 5 is interpolated
copy thru {
	next em at $1,$2
	} until "XXX"
1 __MAXY*0.495
2 __MAXY*0.196
3 __MAXY*0.095
4 __MAXY*0.067
5 __MAXY*0.065
6 __MAXY*0.063
7 __MAXY*0.019
8 __MAXY*0.014
9 __MAXY*0.007
10 __MAXY*0.008
XXX

.G2

