#
# ppar.sh,  2 Mar 05

find ../programs/linux-2.4.20-8/drivers/char -follow -name "*.c" -exec findexec.sh {} \; | a.out

