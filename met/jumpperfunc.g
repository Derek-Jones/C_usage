
__PRELUDE

.G1

# jumpperfunc.g, 28 Nov 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,26 y 0.9,__MAXY log y

label bot "\fIjump-statement\fRs"
label left "Function definitions" "" ""

#ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

draw cd solid times
next cd at 16,__MAXY/2
next cd at 18,__MAXY/2
"\fBreturn\fR" ljust at 19,__MAXY/2
draw cd solid bullet
next cd at 16,__MAXY/5
next cd at 18,__MAXY/5
"\fBbreak\fR" ljust at 19,__MAXY/5
draw cd solid square size -2
next cd at 16,__MAXY/13
next cd at 18,__MAXY/13
"\fBcontinue\fR" ljust at 19,__MAXY/13
draw cd solid delta size -1
next cd at 16,__MAXY/30
next cd at 18,__MAXY/30
"\fBgoto\fR" ljust at 19,__MAXY/33

draw cd solid square size -2

copy "continue_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid bullet size -1

copy "break_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid times size -1

copy "return_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid delta size -2

copy "goto_per_func.d" thru {
   next cd at $1, $2
}

.G2

