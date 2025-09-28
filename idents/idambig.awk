# idambig.awk,  9 Jul 03
#
# strip out the idambig information

BEGIN {
	max_id_len=0
	in_idents=0
	print "dummy.d"
	}

$1 ~ /^Id$/ {
	print "End File"
	print "File: idambig." $3 ".d"
	next
	}

$1 ~ /^center$/ {
	print $3 " " $8
	next
	}

END {
	print "End File"
    }

