
__PRELUDE

.G1

# initlist.g, 26 Aug 03

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.8,10 y 0.9,__MAXY log y

ticks bot out at 1, 2, 3, 4, 5, 6 "", 7 "", 8 "", 9 "", 10, 15, 20
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK_NUM

label bot "\fIinitializer-list\fR nesting depth"
label left "Initializers" "" ""

draw em solid times

copy "init_nesting.d" thru {
	next em at $1,$2
	}

graph Q_2 with .Frame.w at Q_1.e + (0.3, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0.8,100 y 0.9,__MAXY log y

ticks bot out at 1, 25, 50, 75, 100
#ticks left out at  10, 100, 1000, 10000, 34000
__LEFT_TICK

label bot "Members in an \fIinitializer-list\fR"
#label left "initializers" "" ""

copy "init_list_len.d" thru {
	bullet size -1 at $1,$2
	}

.G2

