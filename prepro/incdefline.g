
__PRELUDE

.G1

# incdefline.g, 11 Apr 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,100 y 0.9,__MAXY log y

#ticks bot out at 1, 10, 100, 1000 "", 2000
#ticks left out at  1, 10, 100, 1000, 3000
__LEFT_TICK_NUM

label bot "Percentage line count into .c source file"
label left "Occurrences" ""

bullet at 70,__MAXY/3
"\fB#define\fR" ljust at 75,__MAXY/3
times at 70,__MAXY/8
"\fB#include\fR" ljust at 75,__MAXY/8

copy "rellineinclude.d" thru {
	times size -2 at $1,$2
	}

copy "rellinedefine.d" thru {
	bullet size -2  at $1,$2
	}

graph Q_2  with .Frame.w at Q_1.e - (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,100 y 0.9,__MAXY log y

#ticks bot out at 1, 10, 100, 1000 "", 2000
#ticks left out at  1 "", 10 "", 100 "", 1000 "", 3000
__LEFT_TICK

label bot "Percentage line count into .h source file"
#label left "occurrences" "" ""

#times at 70,__MAXY/3
#"\fB#include\fR" ljust at 75,__MAXY/3
#bullet at 70,__MAXY/8
#"\fB#define\fR" ljust at 75,__MAXY/8

copy "rellineinclude.dh" thru {
	times size -2 at $1,$2
	}

copy "rellinedefine.dh" thru {
	bullet size -2  at $1,$2
	}

.G2

