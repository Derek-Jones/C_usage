#
# mkunused.sh,  8 May 11

cat *.params | awk -f unusedname.awk | sort > unused.names
cat *.params | awk -f multunused.awk > unused.number
