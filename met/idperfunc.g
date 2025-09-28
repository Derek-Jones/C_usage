
__PRELUDE

.G1

# idperfunc.g,  1 Sep 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID*1.2 left solid bot solid

coord x 0,153 y 0.9,__MAXY log y

label bot "Identifier references"
label left "Function definitions" "" ""

ticks bot out at 0, 10 "", 20 "", 30 "", 40 "", 50, 100, 150
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

times size -2 at 83,__MAXY/2
"all identifiers" size -1 ljust at 85,__MAXY/2

copy "ident_per_func.d" thru {
   times size -3 at $1, $2
}

bullet at 83,__MAXY/5
"unique identifiers" size -1 ljust at 85,__MAXY/5

copy "uident_per_func.d" thru {
   bullet size -1 at $1, $2
}

.G2

