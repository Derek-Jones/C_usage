
__PRELUDE

.G1

# benfordflt.g, 31 May 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 1,9 y 0.009,1.0 log y

label bot "First non-zero digit"
label left "Probability of appearing" ""

tick bot at 1, 2, 3, 4, 5, 6, 7, 8, 9
tick left at 0.01 "1", 0.1 "10", 1.0 "100"

draw do dashed
for ben=1 to 9 by 1 do {
   next do at ben, log(1+1/ben)
   }

total=0
copy "benfordflt.d" thru {
   total=total+$2
}

draw do solid
copy "benfordflt.d" thru {
   next do at $1, $2/total
}

.G2

