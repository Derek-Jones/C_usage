
__PRELUDE

.G1

# idzipf.g, 19 Feb 09
# built on: __DATE

frame invis ht __HT wid __WID*2.0 left solid bot solid

coord x 0.9,400000 y 0.9,__MAXY log log

label bot "Identifier rank"
label left "Occurrences" "" ""

ticks bot out at 1, 10, 100, 1000 "1,000", 10000 "10,000", 100000 "100,000"
__LEFT_TICK_NUM

#copy "idzipf.d" thru {
#   dot at $1, $2
#}

# netscape (mozilla)
rank=0
copy "idzipnet.d" thru {
   rank=rank+1
   if (rank < 1000) || ((rank - 20*int(rank / 20)) == 0) then {
      dot at rank, $1
      }
}
# linux
rank=0
copy "idziplin.d" thru {
   rank=rank+1
   if (rank < 1000) || ((rank - 20*int(rank / 20)) == 0) then {
      dot at rank, $1
      }
}
# gcc
rank=0
copy "idzipope.d" thru {
   rank=rank+1
   if (rank < 1000) || ((rank - 20*int(rank / 20)) == 0) then {
      dot at rank, $1
      }
}

"a" at 600,100
"b" at 1300,100
"c" at 5200,100

.G2

