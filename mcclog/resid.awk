# resid.awk, 24 Aug 03
#

BEGIN {
   }

$1 == "1300" {
	if ($2 ~ /^__/)
	   r["1300 __"]=r["1300 __"]+$3
	else
	   r["1300 _[A-Z]"]=r["1300 _[A-Z]"]+$3
	next
	}

$1 == "1301" {
	r["1301 #"]=r["1301 #"]+$3
	next
	}

$1 == "1303" {
	r["1303 #"]=r["1303 #"]+$3
	next
	}

$1 == "1305" {
	if ($2 ~ /^E[0-9]/)
	   r["1305 E[0-9]"]=r["1305 E[0-9]"]+$3
	else
	if ($2 ~ /^E[A-Z]/)
	   r["1305 E[A-Z]"]=r["1305 E[A-Z]"]+$3
	else
	if ($2 ~ /^LC_/)
	   r["1305 LC_[A-Z]"]=r["1305 LC_[A-Z]"]+$3
	else
	if ($2 ~ /^SIG_/)
	   r["1305 SIG_[A-Z]"]=r["1305 SIG_[A-Z]"]+$3
	else
	if ($2 ~ /^SIG/)
	   r["1305 SIG[A-Z]"]=r["1305 SIG[A-Z]"]+$3
	next
	}

$1 == "1306" {
	if ($2 ~ /^is/)
	   r["1306 is[a-z]"]=r["1306 is[a-z]"]+$3
	else
	if ($2 ~ /^to/)
	   r["1306 to[a-z]"]=r["1306 to[a-z]"]+$3
	else
	if ($2 ~ /^str/)
	   r["1306 str[a-z]"]=r["1306 str[a-z]"]+$3
	else
	if ($2 ~ /^mem/)
	   r["1306 mem[a-z]"]=r["1306 mem[a-z]"]+$3
	else
	   r["1300 wcs[a-z]"]=r["1300 wcs[a-z]"]+$3
	next
	}

$1 == "1307" {
	r["1307 #"]=r["1307 #"]+$3
	next
	}

$1 == "1308" {
	if ($2 ~ /^is/)
	   r["1308 is[a-z]"]=r["1308 is[a-z]"]+$3
	else
	if ($2 ~ /^to/)
	   r["1308 to[a-z]"]=r["1308 to[a-z]"]+$3
	else
	if ($2 ~ /^str/)
	   r["1308 str[a-z]"]=r["1308 str[a-z]"]+$3
	else
	if ($2 ~ /^mem/)
	   r["1308 mem[a-z]"]=r["1308 mem[a-z]"]+$3
	else
	if ($2 ~ /^wcs/)
	   r["1308 wcs[a-z]"]=r["1308 wcs[a-z]"]+$3
	next
	}

   {
   r[$1 " " $2]=$3
   next
   }

END {
	TEMP_FILE=systime() ".rn"
	printf("") > TEMP_FILE
	for (i in r)
	   print i " " r[i] >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	
	system("rm " TEMP_FILE)
	}

