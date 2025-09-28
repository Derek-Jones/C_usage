
__PRELUDE

.G1

# scopelines.g,  3 Jan 05
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.9,200 y 0.9,__MAXY log log

label bot "Physical lines"
label left "\fIcompound-statement\fRs" "" ""

#ticks bot out at 1, 10, 100
__LEFT_TICK_NUM

copy "lines_in_scope.d" thru {
   times size -1 at $1, $2+0.1
}

.G2

