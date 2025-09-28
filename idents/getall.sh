#
# getall.sh, 25 Sep 25

GEN_LEV="0"

./getids.sh
./mkuniqid.sh

if test $GEN_LEV == "1"
then
   ./klev.sh
else
   echo "Not generating identifier Levenstein measurements"
fi
