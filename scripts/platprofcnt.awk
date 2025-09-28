# platprofcnt.awk, 26 Aug 03
#

BEGIN {
	}

$4 == "macro" {
	num_macro++
	next
	}

$4 == "external" {
	num_external++
	next
	}

$4 == "file" {
	if ($6 == "tag")
	   num_tag++
	else
	   num_typedef++
	next
	}

$4 == "identifier" {
	num_int_linkage++
	next
	}

	{
	print $0
	next
	}

END {
    print "macro " num_macro
    print "external " num_external
    print "tag " num_tag
    print "typedef " num_typedef
    print "internal linkage " num_int_linkage
    }

