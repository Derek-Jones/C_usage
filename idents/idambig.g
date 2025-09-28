
__PRELUDE

.G1

# idambig.g, 27 May 02
# built on: __DATE

frame invis ht __HT wid __WID*2.0 left solid bot solid

label left "Ambiguity" ""
label bot "Fixation location relative to word center"
coord x -4,4 y 1.0,3

tick bot out at -4, -3, -2, -1, 0, 1, 2, 3, 4
tick left out at 1.0, 1.25 "", 1.5, 1.75 "", 2.0, 2.25 "", 2.5, 2.75 "", 3.0

draw sd solid bullet

"\s-211 letters\s+2" at -3.5,1.7
copy "idambig.11.d" thru {
   next sd at $1, $2
   }

draw sd solid bullet

"\s-210 letters\s+2" at -3.0,1.57
copy "idambig.10.d" thru {
   next sd at $1, $2
   }

draw sd solid bullet

"\s-29 letters\s+2" at -2.3,1.7
copy "idambig.9.d" thru {
   next sd at $1, $2
   }

draw sd solid bullet

"\s-28 letters\s+2" at -1.7,1.57
copy "idambig.8.d" thru {
   next sd at $1, $2
   }

draw sd solid bullet

"\s-27 letters\s+2" at -1.0,1.47
copy "idambig.7.d" thru {
   next sd at $1, $2
   }

draw sd solid bullet

"\s-26 letters\s+2" at -0.9,1.12
copy "idambig.6.d" thru {
   next sd at $1, $2
   }

draw sd solid bullet

"\s-25 letters\s+2" at 0.9,1.1
copy "idambig.5.d" thru {
   next sd at $1, $2
   }

.G2

