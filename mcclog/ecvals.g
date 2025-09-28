
__PRELUDE

.G1

# ecvals.g, 28 Aug 03
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.9,150 y 0.9,__MAXY log log

label bot "Enumeration constants"
label left "Enumeration types" ""

ticks bot out at 1, 2, 5, 10, 20, 50, 100
#ticks left out at 1, 10, 100, 1000, 10000
__LEFT_TICK_NUM

times at 100, __MAXY/2
"enumeration constants in definition" size -1 ljust at 120,__MAXY/2
bullet at 100, __MAXY/4
"uninitialized enumeration constants in definition" size -1 ljust at 120,__MAXY/4
square size -1 at 100, __MAXY/8
"initialized enumeration constants in definition" size -1 ljust at 120,__MAXY/8

copy "ec_total.d" thru {
   times size -1 at $1, $2
}

copy "ec_uninit.d" thru {
   bullet size -1 at $1, $2
}

copy "ec_init.d" thru {
   square size -2 at $1, $2
}

.G2

