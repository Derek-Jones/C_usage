# getmet.sh, 24 Nov 03

if test -d "$1"
   then
   find $1 -name "*.met" -follow -exec cat {} \;
   fi

if test -d "$2"
   then
   find $2 -name "*.met" -follow -exec cat {} \;
   fi

