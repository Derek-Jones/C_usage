# scope.awk, 28 Nov 03

BEGIN {
	seen_func=0
	num_func=0
	}

$1 == ".SCOPE" {
	if ($2 == "start") {
	   scope_start_line=$4
	} else {
	   lines_in_scope[1+$4-scope_start_line]++
	   for (l=scope_start_line; l < scope_end_line; l++)
	      scope_depth[l]=scope_depth[l]+$3-2
	   }
	next
	}

$1 == ".FUNC" {
	seen_func=1
	num_func++
	func_line_num=$2
	next
	}

$1 == ".END" {
	seen_func=0
	next
	}

	{
	next
	}

END {
	print "File: func_scope_level.d"
	for (l=1; l < 200; l++)
	   printf("%d %2.1f\n", l, 1000*(scope_depth[l]/num_func))
	print "End File"

	print "File: lines_in_scope.d"
	for (l=1; l < 200; l++)
	   printf("%d %7d\n", l, lines_in_scope[l])
	print "End File"

	}

