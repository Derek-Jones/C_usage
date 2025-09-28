# lognotcont.awk, 10 Dec 04
#
# Count contexts in which logical not operator occurs
#

function lognot_cnt(expr)
{
return gsub(" ! ", "", expr)
}


BEGIN {
	FS=" ; "
	split(COUNTS, tok_counts, " ")
	total_log_not=tok_counts[4]
	}

$0 ~ /^SWITCH \( / {
	num_op=lognot_cnt($0)
	if (num_op > 0)
	   num_switch_with_op++
	switch_cntrl_not+=num_op
	num_switch++
	next
	}

$0 ~ /^FOR \( / {
	num_op=lognot_cnt($2)
	if (num_op > 0)
	   num_for_with_op++
	for_cntrl_not+=num_op
	num_for++
	next
	}

$0 ~ /^WHILE \( / {
	num_op=lognot_cnt($0)
	if (num_op > 0)
	   num_while_with_op++
	while_cntrl_not+=num_op
	num_while++
	next
	}

$0 ~ /^IF \( / {
	num_op=lognot_cnt($0)
	if (num_op > 0)
	   num_if_with_op++
	if_cntrl_not+=num_op
	num_if++
	next
	}

END {
        printf(" IF control-expression ,, %2.1f ,, %2.1f\n", 100*(if_cntrl_not/total_log_not), 100*(num_if_with_op/num_if))
	printf(" FOR control-expression ,, %2.1f ,, %2.1f\n", 100*(for_cntrl_not/total_log_not), 100*(num_for_with_op/num_for))
	printf(" WHILE control-expression ,, %2.1f ,, %2.1f\n", 100*(while_cntrl_not/total_log_not), 100*(num_while_with_op/num_while))
	printf(" SWITCH control-expression ,, %2.1f ,, %2.1f\n", 100*(switch_cntrl_not/total_log_not), 100*(num_switch_with_op/num_switch))
	printf(" other contexts ,, %2.1f ,, &emdash;\n", 100*((total_log_not-for_cntrl_not-while_cntrl_not-if_cntrl_not-switch_cntrl_not)/total_log_not))
	}

