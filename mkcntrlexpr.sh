#
# mkcntrlexpr.sh, 15 Apr 03

zcat cntrl_expr.gz | grep $1 | awk -f cntrlexpr.awk - 

