#
# c_use.sh, 25 Sep 25

find programs -follow -iname "*.c" -exec ./findexec.sh {} \; | ./ngram $1

