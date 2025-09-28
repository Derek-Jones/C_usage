# getidtype.awk,  5 Oct 08
#

function zero_totals()
{
num_tcs=0
total_derived=0
total_qualified=0
loc_total=0
param_total=0
glob_total=0
typedef_total=0
member_total=0
}

function rm_qualifiers(obj_type)
{
if (index(obj_type, "volatile") == 1)
   obj_type=substr(obj_type, 9)
if (index(obj_type, "const") == 1)
   obj_type=substr(obj_type, 6)
unqual_type=obj_type
}

function num_type_occurrences(obj_type)
{
num_tcs+=loc_type[obj_type] + param_type[obj_type] + glob_type[obj_type] + typedef_type[obj_type] + member_type[obj_type]
loc_total+=loc_type[obj_type]
param_total+=param_type[obj_type]
glob_total+=glob_type[obj_type]
typedef_total+=typedef_type[obj_type]
member_total+=member_type[obj_type]
}

function type_occurrences(obj_type)
{
printf(" %s ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f", obj_type , 100*(loc_type[obj_type]/num_tcs) , 100*(param_type[obj_type]/num_tcs) , 100*(glob_type[obj_type]/num_tcs) , 100*(typedef_type[obj_type]/num_tcs) , 100*(member_type[obj_type]/num_tcs))
printf(" ,, %2.1f\n", 100*((loc_type[obj_type] + param_type[obj_type] + glob_type[obj_type] + typedef_type[obj_type] + member_type[obj_type])/num_tcs))
}

function dtype_occurrences(derived_type, context)
{
num_derived=0
for (t in context)
   if (index(t, derived_type) == 1)
      num_derived+=context[t]
}

function num_derived_type_occurrences(derived_type)
{
cur_total_derived=0
dtype_occurrences(derived_type, loc_type)
cur_total_derived+=num_derived
loc_total+=num_derived
dtype_occurrences(derived_type, param_type)
cur_total_derived+=num_derived
param_total+=num_derived
dtype_occurrences(derived_type, glob_type)
cur_total_derived+=num_derived
glob_total+=num_derived
dtype_occurrences(derived_type, typedef_type)
cur_total_derived+=num_derived
typedef_total+=num_derived
dtype_occurrences(derived_type, member_type)
cur_total_derived+=num_derived
member_total+=num_derived
total_derived+=cur_total_derived
}

function derived_type_occurrences(derived_type)
{
cur_total=0
printf(" %s", derived_type)
dtype_occurrences(derived_type, loc_type)
cur_total+=num_derived
printf(" ,, %2.1f", 100*(num_derived/total_derived))
dtype_occurrences(derived_type, param_type)
cur_total+=num_derived
printf(" ,, %2.1f", 100*(num_derived/total_derived))
dtype_occurrences(derived_type, glob_type)
cur_total+=num_derived
printf(" ,, %2.1f", 100*(num_derived/total_derived))
dtype_occurrences(derived_type, typedef_type)
cur_total+=num_derived
printf(" ,, %2.1f", 100*(num_derived/total_derived))
dtype_occurrences(derived_type, member_type)
cur_total+=num_derived
printf(" ,, %2.1f", 100*(num_derived/total_derived))
printf(" ,, %2.1f", 100*(cur_total/total_derived))
printf("\n")
}

function qtype_occurrences(type_qual, context)
{
num_qualified=0
for (t in context)
   if (index(t, type_qual) == 1)
      num_qualified+=context[t]
}

function num_type_qual_occurrences(type_qual)
{
qtype_occurrences(type_qual, loc_qtype)
total_qualified+=num_qualified
qtype_occurrences(type_qual, param_qtype)
total_qualified+=num_qualified
qtype_occurrences(type_qual, glob_qtype)
total_qualified+=num_qualified
qtype_occurrences(type_qual, typedef_qtype)
total_qualified+=num_qualified
qtype_occurrences(type_qual, member_qtype)
total_qualified+=num_qualified
}

function type_qual_occurrences(type_qual)
{
total_type_qual=0
printf(" %s", type_qual)
qtype_occurrences(type_qual, loc_qtype)
total_type_qual+=num_qualified
loc_total+=num_qualified
printf(" ,, %2.1f", 100*(num_qualified/total_qualified))
qtype_occurrences(type_qual, param_qtype)
total_type_qual+=num_qualified
param_total+=num_qualified
printf(" ,, %2.1f", 100*(num_qualified/total_qualified))
qtype_occurrences(type_qual, glob_qtype)
total_type_qual+=num_qualified
glob_total+=num_qualified
printf(" ,, %2.1f", 100*(num_qualified/total_qualified))
qtype_occurrences(type_qual, typedef_qtype)
total_type_qual+=num_qualified
typedef_total+=num_qualified
printf(" ,, %2.1f", 100*(num_qualified/total_qualified))
qtype_occurrences(type_qual, member_qtype)
total_type_qual+=num_qualified
member_total+=num_qualified
printf(" ,, %2.1f", 100*(num_qualified/total_qualified))
printf(" ,, %2.1f", 100*(total_type_qual/total_qualified))
printf("\n")
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
	param_qtype[$12]++
	rm_qualifiers($12)
	param_type[unqual_type]++
	num_params++
	next
	}

$1 == ".MEMBER" {
	member_qtype[$3]++
	rm_qualifiers($3)
	member_type[unqual_type]++
	num_members++
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT") {
	   loc_qtype[$12]++
	   rm_qualifiers($12)
	   loc_type[unqual_type]++
	   if ($12 == "econst")
	      {
	      num_econsts++
	      }
	   else {
	      num_loc_objs++
	      }
	   }
	else if ($9 == "TAG")
	      {
	      num_tags++
	      }
	else if ($11 == "TYPEDEF")
	      {
	      typedef_qtype[$12]++
	      rm_qualifiers($12)
	      typedef_type[unqual_type]++
	      num_typedefs++
	      }
	next
	}

$1 == ".FUNC" {
	num_func_defs++
	next
	}

$1 == ".LABEL" &&
$2 == "define" {
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
	   } else if ($(NF-1) == "IDENT") {
	      glob_qtype[$NF]++
	      rm_qualifiers($NF)
	      glob_type[unqual_type]++
	      if ($NF == "econst")
	         {
	         num_econsts++
	         }
	      else {
	         num_glob_objs++
	         }
	   } else if ($(NF-1) == "TYPEDEF") {
	      typedef_qtype[$NF]++
	      rm_qualifiers($NF)
	      typedef_type[unqual_type]++
	      num_typedefs++
	   } else if ($NF == "TAG") {
	      num_tags++
	      }
	   }
	next
	}

END {
	print "File: floating_type.t"
	zero_totals()
	num_type_occurrences("float")
	num_type_occurrences("double")
	num_type_occurrences("long_double")
	type_occurrences("float")
	type_occurrences("double")
	type_occurrences("long_double")
	printf(" Total ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f\n", 100*(loc_total/num_tcs) , 100*(param_total/num_tcs) , 100*(glob_total/num_tcs) , 100*(typedef_total/num_tcs) , 100*(member_total/num_tcs))
	print "End File"

	print "File: character_type.t"
	zero_totals()
	num_type_occurrences("char")
	num_type_occurrences("signedchar")
	num_type_occurrences("unsignedchar")
	type_occurrences("char")
	type_occurrences("signedchar")
	type_occurrences("unsignedchar")
	printf(" Total ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f\n", 100*(loc_total/num_tcs) , 100*(param_total/num_tcs) , 100*(glob_total/num_tcs) , 100*(typedef_total/num_tcs) , 100*(member_total/num_tcs))
	print "End File"

	print "File: integer_type.t"
	zero_totals()
	num_type_occurrences("char")
	num_type_occurrences("signedchar")
	num_type_occurrences("unsignedchar")
	num_type_occurrences("short")
	num_type_occurrences("unsignedshort")
	num_type_occurrences("int")
	num_type_occurrences("unsignedint")
	num_type_occurrences("long")
	num_type_occurrences("unsignedlong")
	num_type_occurrences("enum")
	type_occurrences("char")
	type_occurrences("signedchar")
	type_occurrences("unsignedchar")
	type_occurrences("short")
	type_occurrences("unsignedshort")
	type_occurrences("int")
	type_occurrences("unsignedint")
	type_occurrences("long")
	type_occurrences("unsignedlong")
	type_occurrences("enum")
	printf(" Total ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f\n", 100*(loc_total/num_tcs) , 100*(param_total/num_tcs) , 100*(glob_total/num_tcs) , 100*(typedef_total/num_tcs) , 100*(member_total/num_tcs))
	print "End File"

	print "File: derived_type.t"
	zero_totals()
	num_derived_type_occurrences("ptr_to")
	num_derived_type_occurrences("array")
	num_derived_type_occurrences("struct")
	num_derived_type_occurrences("union")
	derived_type_occurrences("ptr_to")
	derived_type_occurrences("array")
	derived_type_occurrences("struct")
	derived_type_occurrences("union")
	printf(" Total ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f\n", 100*(loc_total/total_derived) , 100*(param_total/total_derived) , 100*(glob_total/total_derived) , 100*(typedef_total/total_derived) , 100*(member_total/total_derived))
	print "End File"

	print "File: type_qual.t"
	zero_totals()
	num_type_qual_occurrences("const")
	num_type_qual_occurrences("volatile")
	num_type_qual_occurrences("volatileconst")
	type_qual_occurrences("const")
	type_qual_occurrences("volatile")
	type_qual_occurrences("volatileconst")
	printf(" Total ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f\n", 100*(loc_total/total_qualified) , 100*(param_total/total_qualified) , 100*(glob_total/total_qualified) , 100*(typedef_total/total_qualified) , 100*(member_total/total_qualified))
	print "End File"

	print "File: all_type.t"
	zero_totals()
	num_type_occurrences("char")
	num_type_occurrences("signedchar")
	num_type_occurrences("unsignedchar")
	num_type_occurrences("short")
	num_type_occurrences("unsignedshort")
	num_type_occurrences("int")
	num_type_occurrences("unsignedint")
	num_type_occurrences("long")
	num_type_occurrences("unsignedlong")
	num_type_occurrences("enum")
	num_int=num_tcs
	zero_totals()
	num_type_occurrences("float")
	num_type_occurrences("double")
	num_type_occurrences("long_double")
	num_float=num_tcs
	zero_totals()
	num_derived_type_occurrences("ptr_to")
	num_ptr=cur_total_derived
	num_derived_type_occurrences("array")
	num_array=cur_total_derived
	num_derived_type_occurrences("struct")
	num_su=cur_total_derived
	num_derived_type_occurrences("union")
	num_su+=cur_total_derived
	num_types=num_int+num_float+num_ptr+num_array+num_su
	printf(" %2.1f ,, %2.1f ,, %2.1f ,, %2.1f ,, %2.1f\n", 100*(num_int/num_types) , 100*(num_float/num_types) , 100*(num_ptr/num_types) , 100*(num_array/num_types) , 100*(num_su/num_types))
	printf(" %5.1f ,, %5.1f ,, %5.1f ,, %5.1f ,, %5.1f\n", num_int , num_float, num_ptr, num_array , num_su)
	print "End File"

	}

