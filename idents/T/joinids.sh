#
# joinids.sh, 15 Mar 03

sort $1 > t.$1
sort $2 | join -1 1 t.$1 -
rm t.$1

