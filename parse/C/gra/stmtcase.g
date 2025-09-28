
__PRELUDE

.G1

# stmtcase.gra, 26 Aug 03

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.9,2000 y 0.9,__MAXY log log

#ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15, 20
__LEFT_TICK_NUM

label bot "Statements"
label left "\fBcase\fR/\fBdefault\fR labels" "" "" ""

copy "stmt_per_case.d" thru {
	bullet size -2 at $1,$2
	}

.G2

