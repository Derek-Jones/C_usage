#
# awkall.sh,  6 Apr 02

for f in cjpeg djpeg epic unepic g721_encode g721_decode gsm_toast gsm_untoast mpeg2encode mpeg2decode rawcaudio rawdaudio
   do
   sort +3 -n -r $f | awk -f wr.awk > ${f}w.d
   done


