# opcontext.awk, 17 Dec 07
#
# Count contexts in which the OP operator occur
#

function op_cnt(expr)
{
num_ops=0
split(expr, tok_str, " ")
for (t in tok_str)
   if (tok_str[t] == OP)
      num_ops++
return num_ops
}


BEGIN {
	FS=" ; "
	split(COUNTS, tok_counts, " ")
	total_op=tok_counts[4]
	}

$0 ~ /^SWITCH \( / {
	num_op=op_cnt($0)
	if (num_op > 0)
	   num_switch_with_op++
	switch_cntrl_op+=num_op
	num_switch++
	next
	}

$0 ~ /^FOR \( / {
	num_op=op_cnt($0)
	if (num_op > 0)
	   num_for_with_op++
	for_cntrl_op+=num_op
	num_for++
	next
	}

$0 ~ /^WHILE \( / {
	num_op=op_cnt($0)
	if (num_op > 0)
	   num_while_with_op++
	while_cntrl_op+=num_op
	num_while++
	next
	}

$0 ~ /^IF \( / {
	num_op=op_cnt($0)
	if (num_op > 0)
	   num_if_with_op++
	if_cntrl_op+=num_op
	num_if++
	next
	}

END {
	printf(" IF control-expression ,, %2.1f&nbsp;(%2.1f)\n", 100*(if_cntrl_op/total_op), 100*(num_if_with_op/num_if))
	printf(" FOR control-expression ,, %2.1f&nbsp;(%2.1f)\n", 100*(for_cntrl_op/total_op), 100*(num_for_with_op/num_for))
	printf(" WHILE control-expression ,, %2.1f&nbsp;(%2.1f)\n", 100*(while_cntrl_op/total_op), 100*(num_while_with_op/num_while))
	printf(" SWITCH control-expression ,, %2.1f&nbsp;(%2.1f)\n", 100*(switch_cntrl_op/total_op), 100*(num_switch_with_op/num_switch))
	printf(" other contexts ,, %2.1f&nbsp;(&emdash;)\n", 100*((total_op-for_cntrl_op-while_cntrl_op-if_cntrl_op-switch_cntrl_op)/total_op))
	}

