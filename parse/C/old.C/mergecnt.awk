#
# mergecnt.awk,  9 Mar 05

BEGIN {
	seen_stars=0
	}

$0 == "***" {
	seen_stars=1
	next}

(seen_stars == 1) {
	print $0 " " production[$1-1]
	next
	}

	{
	line_num=$1
	$1=""
	gsub("\\|", "		", $0)
	production[line_num]=$0
	next
	}

