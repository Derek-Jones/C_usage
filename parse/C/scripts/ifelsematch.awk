# ifelsematch.awk,  6 Mar 08
#
# Match ELSEs to their corresponding IFs
#

function print_cmpd_stack()
{
print line_num
for (c=cmpd_hdr_nest; c > 0; c--)
   print c " : " loop_hdr[c]
}

function zero_count()
{
stmt_cnt=0
num_if=0
num_open_cmpd=0
}

function push_stmt()
{
stmt_cnt++
stmt_list[stmt_cnt]=$0
}

function end_func()
{
for (s=1; s <= stmt_cnt; s++)
   print stmt_list[s]
zero_count()
}

function push_if()
{
push_stmt()
num_if++
if_position[num_if]=stmt_cnt
}

function match_else()
{
push_stmt()
if (num_if > 0)
   {
   stmt_list[if_position[num_if]]="IE"
   num_if--
   }
}

function push_cmpd()
{
push_stmt()
num_open_cmpd++
OC_position[num_open_cmpd]=num_if
}

function pop_cmpd()
{
push_stmt()
if (num_open_cmpd > 0)
   {
   num_if=OC_position[num_open_cmpd]
   num_open_cmpd--
   }
}

BEGIN {
	zero_count()
	}

	{
	line_num++
	}

$1 == "IF" {
	push_if()
	next
	}

$1 == "EL" {
	match_else()
	next
	}


$1 == "{_" {
	push_cmpd()
	next
	}

$1 == "}_" {
	pop_cmpd()
	next
	}

	{
	push_stmt()
	next
	}

$1 == "FD" {
	end_func()
	next
	}

$1 == "__E__O__F__" {
	end_func()
	next
	}

END {
	end_func()
	}

