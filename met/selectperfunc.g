
__PRELUDE

.G1

# selectperfunc.g, 24 Aug 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,102 y 0.9,__MAXY log y

label bot "\fIselection-statement\fRs"
label left "Function definitions" "" ""

#ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw cd solid times
next cd at 70,__MAXY/2
next cd at 74,__MAXY/2
"\fBif\fR" ljust at 76,__MAXY/2
draw cd solid bullet
next cd at 70,__MAXY/5
next cd at 74,__MAXY/5
"\fBelse\fR" ljust at 76,__MAXY/5
draw cd solid square
next cd at 70,__MAXY/13
next cd at 74,__MAXY/13
"\fBswitch\fR" ljust at 76,__MAXY/13

draw cd solid times size -1

copy "if_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid bullet size -1

copy "else_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid square size -2

copy "switch_per_func.d" thru {
   next cd at $1, $2
}

.G2

