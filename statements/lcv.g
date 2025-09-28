
__PRELUDE

.G1

# lcv.gra, 28 Mar 03

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0,18 y 0.8,__MAXY log y

ticks bot out at 0, 1, 2 "", 3, 4 "", 5, 10, 15, 20
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "Possible loop control variables"
label left "\fBfor\fR loop headers" "" ""

draw em solid square
next em at 13,__MAXy/3.4
next em at 14,__MAXy/3.4
"\fIexpression-2\fR" ljust at 15,__MAXy/3.4

draw em solid square size -2

copy "lcvcntrl.d" thru {
	next em at $1,$2
	}

draw em solid times
next em at 13,__MAXy/8.2
next em at 14,__MAXy/8.2
"\fIexpression-3\fR" ljust at 15,__MAXy/8.2

draw em solid times

copy "lcvinc.d" thru {
	next em at $1,$2
	}

draw em solid bullet
next em at 13,__MAXy/20.0
next em at 14,__MAXy/20.0
"\fIclause-1\fR" ljust at 15,__MAXy/20.0

draw em solid bullet

copy "lcvinit.d" thru {
	next em at $1,$2
	}

.G2

