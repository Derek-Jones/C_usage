
__PRELUDE

.G1

# cmpdfunc.g, 24 Aug 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,105 y 0.9,__MAXY log y

label bot "\fIcompound-statement\fRs"
label left "Function definitions" "" ""

#ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "cmpd_per_func.d" thru {
   bullet size -1 at $1, $2
}

.G2

