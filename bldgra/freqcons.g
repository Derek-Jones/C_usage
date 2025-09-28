
__PRELUDE

.G1

# freqcons.gra, 30 May 02
# built on: __DATE

graph Q_1

frame invis ht __HT wid __WID left solid bot solid

coord x 0.5,1030 y 0.1,__MAXY log log

label bot "\fIdecimal-constant\fR value"
label left "Occurrences" "" ""

tick bot at 0.5 "0", 1 "", 2, 4 "", 8, 16 "", 32, 64 "", 128, 256 "", 512, 1024 ""
#tick left at 0.1 "0", 1, 10, 100, 1000, 10000, 100000, 1000000 "1000000"
__LEFT_TICK_NUM

#draw do solid

copy "intlitvals.d" thru {
   if $1 == 0 then {
      x=0.5
   } else {
      x=$1
   }
   if $1 > 16 then {
      dot at x, $2
   } else {
      dot size +2 at x, $2
   }
}

graph Q_2 with .Frame.w at Q_1.e - (0.2, 0)

frame invis ht __HT wid __WID left solid bot solid

coord x 0.5,1030 y 0.1,__MAXY log log

label bot "\fIhexadecimal-constant\fR value"

tick bot at 0.5 "0", 1 "", 2, 4 "", 8, 16 "", 32, 64 "", 128, 256 "", 512, 1024 ""
#tick left at 0.1 "", 1 "", 10 "", 100 "", 1000 "", 10000 "", 100000 "", 1000000 ""
__LEFT_TICK

#draw do solid

copy "hexlitvals.d" thru {
   if $1 == 0 then {
      x=0.5
   } else {
      x=$1
   }
   if $1 > 16 then {
      dot at x, $2
   } else {
      dot size +2 at x, $2
   }
}

.G2

