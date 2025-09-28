# makemcc.sh, 25 Sep 25

cd $PROG_DIR
cd linux*
make -k bzImage > /usr2/linux.mcc

