
__PRELUDE

.G1

# idsignif.g, 24 Jul 03
# built on: __DATE

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 5.5,52 y 0.001,100 log y

label bot "Significant characters"
label left "% identical matches" "" ""

ticks bot out at 6, 10, 20, 30, 40, 50
#ticks left out at 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
#__LEFT_TICK_NUM

draw un solid times
next un at 40,100
next un at 43,100
"\s-1gcc\s+1" ljust at 44,100
draw un solid times
copy "gcc.sig.d" thru {
   next un at $1, $2
}

draw un solid dot
next un at 40,30
next un at 43,30
"\s-1idsoftware\s+1" ljust at 44,30
draw un solid dot
copy "idsoftware.sig.d" thru {
   next un at $1, $2
}

draw un solid delta
next un at 40,10
next un at 43,10
"\s-1linux\s+1" ljust at 44,10
draw un solid delta size -1
copy "linux.sig.d" thru {
   next un at $1, $2
}

draw un solid bullet
next un at 40,3
next un at 43,3
"\s-1mozilla\s+1" ljust at 44,3
draw un solid bullet
copy "netscape.sig.d" thru {
   next un at $1, $2
}

.G2

