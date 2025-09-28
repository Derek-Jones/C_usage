# commentinfo.awk, 14 Jul 03
#
# comment usage

function end_func()
{
total_comments=comment+cpp_comment
printf("/* comment */ ,, %2.1f\n", 100*comment/total_comments)
printf("// comment ,, %2.1f\n", 100*cpp_comment/total_comments)
printf("/* on one line */ ,, %2.1f\n", 100*single_line_comment/comment)
printf("new-lines in /* comments ,, %2.1f\n", 100*comment_nl/(new_line+comment_nl))
exit
}


BEGIN {
	}

$2 ~ /tokcnt.d/ {
	in_data_freq=1
	next
	}

$0 ~ /^Total_tokens/ {
	single_line_comment=$6
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1) end_func()
	next
	}

	{
	if (in_data_freq == 1) {
	   if ($1 == "COMMENT")
	      comment=$3
	   if ($1 == "COMMENT_NL")
	      comment_nl=$3
	   if ($1 == "CPP_COMMENT")
	      cpp_comment=$3
	   if ($1 == "NEW_LINE")
	      new_line=$3
	   }
	next
	}

END {
    }

