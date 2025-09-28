#
# klev.sh, 16 Feb 05

for f in *.c.uniq
   do
   echo $f
   time src/calclev < $f | awk -f uniqcnt.awk > `basename $f .uniq`.lev
   time src/calcklev < $f | awk -f uniqcnt.awk > `basename $f .uniq`.kl
   done

