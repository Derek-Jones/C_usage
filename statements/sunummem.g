
__PRELUDE

.G1

# sunummem.gra, 26 Aug 03

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0.5,102 y 0.9,__MAXY log y

ticks bot out at 1, 10, 20, 30, 40, 50, 75, 100
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "\fBstruct\fR/\fBunion\fR members"
label left "Definitions" "" ""

times at 69,__MAXY/2
".c files" ljust at 71,__MAXY/2

draw sb solid 
next sb at 65,__MAXY/13
next sb at 69,__MAXY/13
"\fBstruct\fR" ljust at 71,__MAXY/13
draw sb dashed 
next sb at 65,__MAXY/30
next sb at 69,__MAXY/30
"\fBunion\fR" ljust at 71,__MAXY/30

draw st solid times
draw dt dashed times

s=0
u=1

copy "su_num_members.d" thru {
	if $2 == s then {
	   next st at $1,$3
	} else {
	   next dt at $1,$3
	   }
	}

bullet at 69,__MAXY/5
".h files" ljust at 71,__MAXY/5

draw sb solid bullet size -1
draw db dashed bullet size -1

copy "su_num_members.dh" thru {
	if $2 == s then {
	   next sb at $1,$3
	} else {
	   next db at $1,$3
	   }
	}

.G2

