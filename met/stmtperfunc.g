
__PRELUDE

.G1

# stmtperfunc.g, 28 Nov 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0,81 y 0.9,__MAXY log y

label bot "Statements"
label left "Function definitions" "" ""

#ticks bot out at 0, 16, 32, 64, 100, 128, 150, 200, 255
__LEFT_TICK_NUM

draw cd solid delta size -1
next cd at 50,__MAXY/2
next cd at 53,__MAXY/2
"\fIexpression-statement\fR" ljust at 55,__MAXY/2
draw cd solid bullet
next cd at 50,__MAXY/5
next cd at 53,__MAXY/5
"\fIselection-statement\fR" ljust at 55,__MAXY/5
draw cd solid dot
next cd at 50,__MAXY/13
next cd at 53,__MAXY/13
"\fIcompound-statement\fR" ljust at 55,__MAXY/13
draw cd solid square size -2
next cd at 50,__MAXY/30
next cd at 53,__MAXY/30
"\fIjump-statement\fR" ljust at 55,__MAXY/30
draw cd solid times size -1
next cd at 50,__MAXY/73
next cd at 53,__MAXY/73
"\fIiteration-statement\fR" ljust at 55,__MAXY/73

draw cd solid times size -1

copy "iter_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid bullet size -1

copy "select_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid square size -2

copy "jump_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid dot size -2

copy "cmpd_per_func.d" thru {
   next cd at $1, $2
}

draw cd solid delta size -2

copy "expr_per_func.d" thru {
   next cd at $1, $2
}

.G2

