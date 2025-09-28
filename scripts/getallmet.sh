# getallmet.sh, 25 Sep 25


cd $USE_HOME/programs

for f in linux gcc idsoft linux netscape openafs openMotif postgres
   do
   $USE_HOME/scripts/getmet.sh $USE_HOME/programs/${f}* | gzip -c > $f.MET.gz
   done

