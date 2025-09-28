#
# cpar.sh,  3 Nov 06

#find programs -follow -name "*.c" -exec findexec.sh {} \; | ecnt results

find programs -follow -name "*.c" -exec findexec.sh {} \; | ecnt dispexpr | awk -f binoperands.awk | sort

