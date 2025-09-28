#
# cpar.sh,  2 Mar 05

find /usr1/expsrc -follow -name "*.c" -exec findexec.sh {} \; | a.out

