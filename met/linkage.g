
__PRELUDE

.G1

# linkage.g, 27 Jul 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0,105 y 0.9,__MAXY log y

label bot "Declarations"
label left "Translation units" "" ""

ticks bot out at 25 "250", 50 "500", 75 "750", 100 "1,000"
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

times at 70,__MAXY/2
"function - external linkage" size -1 ljust at 72, __MAXY/2
copy "extfunc.d" thru {
   times size -1 at $1, $2
}

square size -1 at 70,__MAXY/5
"function - internal linkage" size -1 ljust at 72, __MAXY/5
copy "intfunc.d" thru {
   square size -2 at $1, $2
}

bullet at 70, __MAXY/12
"object - external linkage" size -1 ljust at 72, __MAXY/12
copy "extobj.d" thru {
   bullet size -1 at $1, $2
}

delta at 70, __MAXY/30
"object - internal linkage" size -1 ljust at 72, __MAXY/30
copy "intobj.d" thru {
   delta size -2 at $1, $2
}

.G2

