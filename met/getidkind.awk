# getidkind.awk,  5 Oct 08
#

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
	param_name[$2]++
	num_params++
	next
	}

$1 == ".MEMBER" {
	member_name[$2]++
	num_members++
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT") {
	   if ($12 == "econst")
	      {
	      econst_name[$2]++
	      num_econsts++
	      }
	   else {
	      loc_obj_name[$2]++
	      num_loc_objs++
	      }
	   }
	else if ($9 == "TAG")
	      {
	      tag_name[$2]++
	      num_tags++
	      }
	else if ($11 == "TYPEDEF")
	      {
	      typedef_name[$2]++
	      num_typedefs++
	      }
	next
	}

$1 == ".FUNC" {
	num_func_defs++
	func_def_name[$2]++
	next
	}

$1 == ".LABEL" &&
$2 == "define" {
	label_name[$3]++
	num_labels++
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if (in_global == 1) {
	   if ($NF == "FUNC") {
	      num_func_decls++
	      func_decl_name[$1]++
	   } else if ($(NF-1) == "IDENT") {
	      if ($NF == "econst")
	         {
	         econst_name[$1]++
	         num_econsts++
	         }
	      else {
	         glob_obj_name[$1]++
	         num_glob_objs++
	         }
	   } else if ($(NF-1) == "TYPEDEF") {
	      typedef_name[$1]++
	      num_typedefs++
	   } else if ($NF == "TAG") {
	      num_tags++
	      tag_name[$1]++
	      }
	   }
	next
	}

END {
	print "File: global_objects " num_glob_objs
	for (n in glob_obj_name)
	   print n " " glob_obj_name[n]
	print "END global_objects"
	
	print "File: local_objects " num_loc_objs
	for (n in loc_obj_name)
	   print n " " loc_obj_name[n]
	print "END local_objects"
	
	print "File: func_params " num_params
	for (n in param_name)
	   print n " " param_name[n]
	print "END func_params"
	
	print "File: func_defs " num_func_defs
	for (n in func_def_name)
	   print n " " func_def_name[n]
	print "END func_defs"
	
	print "File: members " num_members
	for (n in member_name)
	   print n " " member_name[n]
	print "END members"
	
	print "File: func_decls " num_func_decls
	for (n in func_decl_name)
	   print n " " func_decl_name[n]
	print "END func_decls"
	
	print "File: tags " num_tags
	for (n in tag_name)
	   print n " " tag_name[n]
	print "END tags"
	
	print "File: typedefs " num_typedefs
	for (n in typedef_name)
	   print n " " typedef_name[n]
	print "END typedefs"
	
	print "File: enum_consts " num_econsts
	for (n in econst_name)
	   print n " " econst_name[n]
	print "END enum_consts"
	
	print "File: labels " num_labels
	for (n in label_name)
	   print n " " label_name[n]
	print "END labels"

	}

