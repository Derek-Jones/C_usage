# cleanprogs.sh, 26 Nov 03

PROGS="/home/cbook/usage/programs"		; export PROGS

cd $PROGS
cd gcc*/gcc
make clean

cd $PROGS
cd linux*
make clean

cd $PROGS
cd netscape
make clean

cd $PROGS
cd openafs*
make clean

cd $PROGS
cd openMotif*
make clean

cd $PROGS
cd postgresql*
cd src
make clean

# no make clean for idsoftware

