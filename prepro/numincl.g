
__PRELUDE

.G1

# numincl.gra, 26 Apr 03
# built on: __DATE

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,61 y 0.8,__MAXY log y

label bot "\fB#include\fRs"
label left "Source files" "" ""

ticks bot out at 0, 10, 20, 30, 40, 50, 60, 70
#ticks left out at 1, 10, 100, 1000, 2300 "2300"
__LEFT_TICK_NUM

"<header>" ljust at 24,100

draw un solid
copy "hinclcnt.d" thru {
   next un at $1, $2
}

draw un dashed
copy "hincluniq.d" thru {
   next un at $1, $2
}

"\"header\"" rjust at 15,10

draw un solid
copy "qinclcnt.d" thru {
   next un at $1, $2
}

draw un dashed
copy "qincluniq.d" thru {
   next un at $1, $2
}

.G2

