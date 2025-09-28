# ifnest.awk, 29 Oct 07
#
# Count #if/#ifdef/#ifndef nesting levels
#

BEGIN {
	nesting=0
	going_up=0
	max_nesting=0
	total_max_nesting=0
	}

function at_eof()
{
TU_max_nesting[max_nesting]++
if (max_nesting > total_max_nesting)
   total_max_nesting=max_nesting
max_nesting=0
nesting=0
going_up=0
}


$1 == "#IF" ||
$1 == "#IFDEF" ||
$1 == "#IFNDEF" {
	going_up=1
	nesting++
	if (nesting > max_nesting)
	   max_nesting=nesting
	next
	}

$1 == "#ELIF" ||
$1 == "#ELSE" {
	next
	}

$1 == "#ENDIF" {
	if (going_up == 1)
	   max_level[nesting]++
	nesting--
	going_up=0
	next
	}

$1 == "__E__O__F__"  {
	at_eof()
	next
	}

	{
	next
	}

END {
    at_eof()
    print "File: pptunest.d"
    for (i=1; i <= total_max_nesting; i++)
       print i " " 0+TU_max_nesting[i]
    print "End File"
    print "File: ppidnest.d"
    for (i=1; i <= total_max_nesting; i++)
       print i " " 0+max_level[i]
    print "End File"
    }

