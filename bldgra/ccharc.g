
__PRELUDE

.G1

# ccharc.g,  2 Jan 05
# built on: __DATE

frame invis ht __HT wid __WID*2.0 left solid bot solid

coord x 0,130 y 0,1.0

label bot "ASCII value"
label left "Relative occurrence" ""

ticks bot out at 0, 10, 25, 30 "", 35 "", 40 "", 45 "", 50, 55 "", 60 "", 65 "", 70 "", 75, 80 "", 85 "", 90 "", 95 "", 100, 105 "", 110 "", 115 "", 120 "", 125
ticks left out at 0.25 "0.25", 0.5 "0.50", 0.75 "0.75", 1.0 "1.0"

draw li solid dot
copy "ccharc.d" thru {
   next li at $2, $3/__MAXy
}

"\\0" at 1,1.00
"\\t" at 9,2100/__MAXy
"\\n" at 10,2470/__MAXy
"sp" at 32,3010/__MAXy
"0" at 48,2980/__MAXy
":" at 58,1400/__MAXy
"A" at 65,1420/__MAXy
"L" at 76,810/__MAXy
"S" at 83,810/__MAXy
" \\ " at 92,1170/__MAXy
"a" at 97,1460/__MAXy
"e" at 101,1050/__MAXy
"i" at 105,1140/__MAXy
"n" at 110, 910/__MAXy
"t" at 116,1020/__MAXy
"z" at 122,560/__MAXy

.G2

