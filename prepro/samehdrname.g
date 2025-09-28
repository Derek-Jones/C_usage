
__PRELUDE

.G1

# samehdrname.g,  9 Oct 07
# built on: __DATE

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0.9,3000 y 0.9,__MAXY log log

label left "Occurrences of header name" ""
label bot "Rank"

#ticks bot out at 0, 10, 20, 30, 40, 50, 60, 70
#ticks left out at 1, 10, 100, 1000, 2300 "2300"
__LEFT_TICK_NUM

times at 800,__MAXY/2
"<header>" ljust at 1000,__MAXY/2

x=0
copy "hdrhstr.d" thru {
   x=x+1
   times size -2 at x,$2
}

bullet at 800,__MAXY/5
"\"header\"" ljust at 1000,__MAXY/5

x=0
copy "hdrqstr.d" thru {
   x=x+1
   bullet size -1 at x,$2
}

.G2

