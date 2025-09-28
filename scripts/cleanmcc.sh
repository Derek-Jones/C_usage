# cleanmcc.sh, 26 Nov 03

PROGS="/home/cbook/usage/programs"		; export PROGS

cd $PROGS
find . -follow -name "*.met" -exec rm {} \;
find . -follow -name "*.kic" -exec rm {} \;
find . -follow -name "*.klc" -exec rm {} \;
find . -follow -name mcc.log -exec rm {} \;

