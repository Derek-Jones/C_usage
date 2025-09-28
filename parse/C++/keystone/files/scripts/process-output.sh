#!/bin/sh

if [ $# -ne 2 ]; then
  echo "Usage: $0 OPTION TESTDIR"
  echo 
  echo "  clean       remove all .out files"
  echo "  failures    capture all parse failures to failures.key"
  echo
  exit
fi

if [ $1 == "clean" ]; then
  find $2 -name \*.out | xargs rm -f
  exit
elif [ $1 == "failures" ]; then
  PWD=`pwd`
  ## we only want to see the syntax errors produced by keystone - not successes or cpp warnings
  find $2 -name \*.out | xargs cat | grep -v "Parse Succeeded" | grep -v "left but not entered" | sed 's%'"$PWD"'%%' > failures.key
  exit
else
  echo "Invalid Option"
  exit
fi

