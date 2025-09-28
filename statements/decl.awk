# decl.awk, 26 Aug 03
#

function print_cmpd_stack()
{
print line_num
for (c=su_nest_depth; c > 0; c--)
   print c " : " loop_hdr[c]
}

function start_file()
{
su_nest_depth=0
last_was_struct=0
last_was_union=0
last_was_su_push=0
last_was_init_push=0
last_was_curl=0
last_was_equal=0
init_nest_depth=0
}

function start_init()
{
if (init_nest_depth == 0) {
   init_nest_depth=1
   num_inits=1
   last_was_init_push=1
   }
}

function push_init()
{
init_nest_depth++
init_stack[init_nest_depth]=num_inits
num_inits=1
last_was_init_push=1
}


function pop_init()
{
if (last_was_init_push == 1)
   init_nesting[init_nest_depth]++
last_was_init_push=0
init_list_len[num_inits]++
num_inits=init_stack[init_nest_depth]
init_nest_depth--
}

function push_su(su_str)
{
last_was_su_push=1
su_nest_depth++
decl_hdr[su_nest_depth]=su_str
decl_members[su_nest_depth]=member_cnt
member_cnt=1
}

function pop_su()
{
if (su_nest_depth > 0) {
   su_num_members[member_cnt " " decl_hdr[su_nest_depth]]++
   member_cnt=decl_members[su_nest_depth]
   if (last_was_su_push == 1)
      su_nesting[su_nest_depth]++
   last_was_su_push=0
   su_nest_depth--
   }
}

BEGIN {
	start_file()
	line_num=0
	total_struct=0
	total_union=0
	member_cnt=0
	num_inits=0
	}

	{
	line_num++
	}

$1 == "STRUCT" {
	last_was_struct=1
	total_struct++
	next
	}

$1 == "UNION" {
	last_was_union=1
	total_union++
	next
	}

$1 == "(" ||
$1 == ")" {
	last_was_struct=0
	last_was_union=0
	#
	# for ( ; ; = ) {
	last_was_equal=0
	next
	}

$1 == ";" {
	last_was_struct=0
	last_was_union=0
	last_was_curl=0
	last_was_equal=0
	member_cnt++
	if (init_nest_depth != 0)
	   {
	   print "line " line_num " init_nest_depth " init_nest_depth
	   #print_cmpd_stack()
	   }
	init_nest_depth=0
	next
	}

$1 == "=" {
	last_was_equal=1
	next
	}

$1 == "{" {
	if (last_was_struct)
	   push_su("s")
	if (last_was_union)
	   push_su("u")
	if (init_nest_depth > 0)
	   push_init()
	if (last_was_equal)
	   start_init()
	last_was_curl=1
	next
	}

$1 == "}" {
	if (su_nest_depth > 0)
	   pop_su()
	if (init_nest_depth > 0)
	   pop_init()
	next
	}

$1 == "," {
	num_inits++
	next
	}

$1 == "__E__O__F__" {
	if (su_nest_depth != 0)
	   {
	   print "su_nest_depth " su_nest_depth
	   print_cmpd_stack()
	   }
	start_file()
	next
	}

	{
	next
	}

END {
	su_check=0
	for (i in su_nesting)
	   su_check=su_check+i*su_nesting[i]
	print "nested su count " su_check
	print "total struct " total_struct
	print "total union " total_union
	TEMP_FILE="su" systime()
        printf("") > TEMP_FILE
	for (i in su_nesting)
	   print i " " su_nesting[i] >> TEMP_FILE
	print "File: su_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in su_num_members)
	   print i " " su_num_members[i] >> TEMP_FILE
	print "File: su_num_members.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in init_nesting)
	   print i " " init_nesting[i] >> TEMP_FILE
	print "File: init_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in init_list_len)
	   print i " " init_list_len[i] >> TEMP_FILE
	print "File: init_list_len.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        
	system("rm " TEMP_FILE)
	}

