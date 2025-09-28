#
# charsqinid.sh, 25 Sep 25

source ../config.files

zcat *$MET_SUFF | awk -f getfields.awk | awk -f charsqinid.awk
