#
# bldall.sh, 16 Feb 05

cd src

gcc calclev.c -DLEV_DIST=1 -lm -o calclev
gcc calclev.c -DKEY_DIST=1 -lm -o calckey
gcc calclev.c -DLEVKEY_DIST=1 -lm -o calcklev

gcc lettercnt.c -o lettercnt
gcc wordambig.c -o wordambig
mv wordambig ../.

