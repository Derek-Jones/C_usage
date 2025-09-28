
__PRELUDE

.G1

# brkcon.gra, 22 Oct 07

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,20.5 y 0.8,__MAXY log y

ticks bot out at 0, 5, 10, 15, 20
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "\fBbreak\fRs or \fBcontinue\fRs"
label left "\fIiteration-statement\fRs" "" "" ""

draw em solid times
next em at 12,__MAXY/2
next em at 14,__MAXY/2
"\fBbreak\fR" ljust at 15,__MAXY/2

draw em solid times

copy "break_p_loop.d" thru {
	next em at $1,$2
	}

draw em solid bullet
next em at 12,__MAXY/5
next em at 14,__MAXY/5
"\fBcontinue\fR" ljust at 15,__MAXY/5

draw em solid bullet

copy "contin_p_loop.d" thru {
	next em at $1,$2
	}

.G2

