# qualifier.awk,  5 Oct 08

function decl_nest(obj_type)
{
#
# Stop enumerated constants being counted as a type qualifier
gsub("econst", "", obj_type)
if (match(obj_type, /ptr_to/)) {
   num_qual_type["_*_"]++
   }
if (match(obj_type, /const[^_]*ptr_to/)) {
   num_qual_type["c_*"]++
   }
if (match(obj_type, /volatile[^_]*ptr_to/)) {
   num_qual_type["v_*"]++
   }
if (match(obj_type, /ptr_to[^_]*const/)) {
   num_qual_type["*_c"]++
   }
if (match(obj_type, /ptr_to[^_]*volatile/)) {
   num_qual_type["*_v"]++
   }
if (match(obj_type, /array/)) {
   num_qual_type["_a_"]++
   }
if (match(obj_type, /array[^_]*const/)) {
   num_qual_type["a_c"]++
   }
if (match(obj_type, /array[^_]*volatile/)) {
   num_qual_type["a_v"]++
   }
if (match(obj_type, /struct/)) {
   num_qual_type["_s_"]++
   }
if (match(obj_type, /const[^_]*struct/)) {
   num_qual_type["c_s"]++
   }
if (match(obj_type, /volatile[^_]*struct/)) {
   num_qual_type["v_s"]++
   }
if (match(obj_type, /union/)) {
   num_qual_type["_u_"]++
   }
if (match(obj_type, /const[^_]*union/)) {
   num_qual_type["c_u"]++
   }
if (match(obj_type, /volatile[^_]*union/)) {
   num_qual_type["v_u"]++
   }
if (match(obj_type, /(char|short|int|long)/)) {
   num_qual_type["_i_"]++
   }
if (match(obj_type, /const[^_]*(char|short|int|long)/)) {
   num_qual_type["c_i"]++
   }
if (match(obj_type, /volatile[^_]*(char|short|int|long)/)) {
   num_qual_type["v_i"]++
   }
if (match(obj_type, /(float|double)/)) {
   num_qual_type["_r_"]++
   }
if (match(obj_type, /const[^_]*(float|double)/)) {
   num_qual_type["c_r"]++
   }
if (match(obj_type, /volatile[^_]*(float|double)/)) {
   num_qual_type["v_r"]++
   }
if (match(obj_type, /volatileconst/)) {
   num_qual_type["cv"]++
   }
if (match(obj_type, /constvolatile/)) {
   num_qual_type["cv"]++
   }
if (obj_type == "const") {
   num_qual_type["_c_"]++
   }
if (match(obj_type, /const/)) {
   num_qual_type["c"]++
   }
if (match(obj_type, /volatile/)) {
   num_qual_type["v"]++
   }
}

function print_nonzero(format, value)
{
if (value >= 0.01)
   printf(format, value)
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
	#other_types=0
	#for (i in num_qual_type)
	#   print i " " num_qual_type[i]
	#print "End File"
	print_nonzero("const * ,, %2.1f\n", 100*(num_qual_type["c_*"]/ num_qual_type["_*_"]))
	print_nonzero("volatile* ,, %2.1f\n", 100*(num_qual_type["v_*"]/ num_qual_type["_*_"]))
	print_nonzero("* const ,, %2.1f\n", 100*(num_qual_type["*_c"]/ num_qual_type["_*_"]))
	print_nonzero("* volatile ,, %2.1f\n", 100*(num_qual_type["*_v"]/ num_qual_type["_*_"]))
	print_nonzero("array of const ,, %2.1f\n", 100*(num_qual_type["a_c"]/ num_qual_type["_a_"]))
	print_nonzero("array of volatile ,, %2.1f\n", 100*(num_qual_type["a_v"]/ num_qual_type["_a_"]))
	print_nonzero("const struct ,, %2.1f\n", 100*(num_qual_type["c_s"]/ num_qual_type["_s_"]))
	print_nonzero("volatile struct ,, %2.1f\n", 100*(num_qual_type["v_s"]/ num_qual_type["_s_"]))
	print_nonzero("const union ,, %2.1f\n", 100*(num_qual_type["c_u"]/ num_qual_type["_u_"]))
	print_nonzero("volatile union ,, %2.1f\n", 100*(num_qual_type["v_u"]/ num_qual_type["_u_"]))
	print_nonzero("const integer-type ,, %2.1f\n", 100*(num_qual_type["c_i"]/ num_qual_type["_i_"]))
	print_nonzero("volatile integer-type ,, %2.1f\n", 100*(num_qual_type["v_i"]/ num_qual_type["_i_"]))
	print_nonzero("const real-type ,, %2.1f\n", 100*(num_qual_type["c_r"]/ num_qual_type["_r_"]))
	print_nonzero("volatile real-type ,, %2.1f\n", 100*(num_qual_type["v_r"]/ num_qual_type["_r_"]))
	#printf("c %2.1f\n", 100*(num_qual_type["cv"]/ num_qual_type["c"]))
	#printf("v %2.1f\n", 100*(num_qual_type["cv"]/ num_qual_type["v"]))
	}

