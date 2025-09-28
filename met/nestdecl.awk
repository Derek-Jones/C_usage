# nestdecl.awk,  5 Oct 08

function decl_nest(obj_type)
{
num_decl_mod=gsub("array", "", obj_type)
num_decl_mod+=gsub("struct", "", obj_type)
num_decl_mod+=gsub("union", "", obj_type)
num_decl_mod+=gsub("ptr_to", "", obj_type)
num_decl_mod+=gsub("func", "", obj_type)
decl_mod_cnt[num_decl_mod]++
if (num_decl_mod > max_decl_mod)
   max_decl_mod=num_decl_mod
}

BEGIN {
	seen_file_before=0
	start_depth=0
	start_name="###"
	}

$1 == ".START" {
	# We only count the contents of any file once.
	# This means we undercount if different files have the same name
	sfb_stack[start_depth]=seen_file_before
	start_stack[start_depth]=start_name
	start_depth++
	seen_file_before=0
	start_name=$2
        gsub(/\.\.\//, "", start_name)
        if (files_seen[start_name] == 1)
           seen_file_before=1
        else
           files_seen[start_name]=1
	next
	}

$1 == ".END" {
	in_global=0
        end_name=$2
        gsub(/\.\.\//, "", end_name)
        if (end_name == start_name)
	   {
	   start_depth--
	   start_name=start_stack[start_depth]
	   seen_file_before=sfb_stack[start_depth]
	   }
	next
	}

seen_file_before == 1 {
	next
	}

$1 == ".GLOBAL" {
	in_global=(seen_file_before == 0)
	next
	}

$1 == ".ARG" {
	decl_nest($NF)
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT")
	   decl_nest($NF)
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if ((in_global == 1) && ($(NF-1) == "IDENT"))
	   decl_nest($NF)
	next
	}

END {
	print "File: nestdecl.d"
	for (i=0; i <= max_decl_mod; i++)
	   print i " " decl_mod_cnt[i]
	print "End File"
	}

