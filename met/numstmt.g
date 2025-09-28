
__PRELUDE

.G1

# numstmt.g, 27 Aug 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0,405 y 0.9,__MAXY log y

label bot "Statements"
label left "Function definitions" "" ""

#ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

copy "stmts_per_func.d" thru {
   bullet size -2 at $1, $2
}

graph Q_2 with .Frame.w at Q_1.e + (0.1, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0,405 y 0.9,__MAXY log y

label bot "Visible lines"
#label left "Function definitions" "" ""

#ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK

copy "lines_per_func.d" thru {
   bullet size -2 at $1, $2
}

.G2

