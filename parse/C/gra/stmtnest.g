
.G1

# stmtnest.gra, 13 Mar 08

graph Q_1

frame invis ht 2.5 wid 3.5 left solid bot solid

coord x 0,15 y 0,50

ticks bot out at 0, 5, 10
#ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15 "", 20, 32
#ticks left out at  10, 100, 1000, 10000, 34000
#__LEFT_TICK_NUM

label bot "Nesting depth"
label left "Percentage occurrences" "" ""

#draw st solid times
#next st at 18, __MAXY/2
#next st at 20, __MAXY/2
#"\fIcompound-statement\fRs" ljust at 21, __MAXY/2

draw s_es solid times
draw s_if solid bullet size -1
draw s_oc solid delta size -2
draw s_el solid square size -2
draw s_ifs dashed times

last_nest_level=-1
copy "totalstmt.d" thru {
	if $2 != last_nest_level then {
	   seen_all=0
	   all_ifs=0
	   last_nest_level=$2
	}
	if $1 == 99 then {
	   seen_all=seen_all+1
	   all_ifs=all_ifs+$4
	}
	if $1 == 100 then {
	   next s_es at $2,$4
	}
	if $1 == 101 then {
	   next s_if at $2,$4
	   seen_all=seen_all+1
	   all_ifs=all_ifs+$4
	}
	if $1 == 102 then {
	   next s_oc at $2,$4
	}
	if $1 == 105 then {
	   next s_el at $2,$4
	}
	if seen_all == 2 then {
	   next s_ifs at $2,all_ifs
	}
	}

graph Q_2 with .Frame.n at Q_1.s - (0.0, 0.2)

frame invis ht 2.5 wid 3.5 left solid bot solid

coord x 0,15 y 0,8

ticks bot out at 0, 5, 10
#ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15 "", 20, 32
#ticks left out at  10, 100, 1000, 10000, 34000
#__LEFT_TICK_NUM

label bot "Nesting depth"
label left "Percentage occurrence" "" ""

#draw st solid times
#next st at 18, __MAXY/2
#next st at 20, __MAXY/2
#"\fIcompound-statement\fRs" ljust at 21, __MAXY/2

draw s_go solid times
draw s_re solid bullet size -1
draw s_fo solid delta size -2
draw s_br solid square size -2

copy "totalstmt.d" thru {
	if $1 == 106 then {
	   next s_go at $2,$4
	}
	if $1 == 107 then {
	   next s_re at $2,$4
	}
	if $1 == 108 then {
	   next s_fo at $2,$4
	}
	if $1 == 109 then {
	   next s_br at $2,$4
	}
	}

graph Q_2 with .Frame.n at Q_2.s - (0.0, 0.2)

frame invis ht 2.5 wid 3.5 left solid bot solid

coord x 0,15 y 0,4

ticks bot out at 0, 5, 10
#ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15 "", 20, 32
#ticks left out at  10, 100, 1000, 10000, 34000
#__LEFT_TICK_NUM

label bot "Nesting depth"
label left "Percentage occurrence" "" ""

#draw st solid times
#next st at 18, __MAXY/2
#next st at 20, __MAXY/2
#"\fIcompound-statement\fRs" ljust at 21, __MAXY/2

draw s_dc solid times
draw s_wh solid bullet size -1
draw s_sw solid delta size -2
draw s_co solid square size -2

copy "totalstmt.d" thru {
	if $1 == 110 then {
	   next s_dc at $2,$4
	}
	if $1 == 111 then {
	   next s_wh at $2,$4
	}
	if $1 == 112 then {
	   next s_sw at $2,$4
	}
	if $1 == 113 then {
	   next s_co at $2,$4
	}
	}

.G2

