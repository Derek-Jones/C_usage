# makemcc.sh, 25 Sep 25

cd $PROG_DIR
cd gcc*/gcc
make -k > gcc.mcc

cd $PROG_DIR
cd linux*
make -k bzImage > linux.mcc

cd $PROG_DIR
cd netscape
make -k > netscape.mcc

cd $PROG_DIR
cd openafs*
make -k > openafs.mcc

cd $PROG_DIR
cd openMot*
make -k > openMotif.mcc

cd $PROG_DIR
cd postg*
cd src
make -k > postgresql.mcc

cd $PROG_DIR
cd idsoftware
walk_dir.sh > idsoft.mcc

