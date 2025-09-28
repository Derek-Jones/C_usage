#
# h_use.sh, 25 Sep 25

find programs -follow -iname "*.h" -exec ./findexec.sh {} \; | ./ngram

