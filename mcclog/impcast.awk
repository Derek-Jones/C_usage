# impcast.awk,  3 Sep 03
#

function start_file()
{
inc_depth=0
in_sys_hdr=0
hdr_seen_before=0
}

function simplify_type(op_type)
{
simp_type=op_type
num_fields=split(op_type, subtype, " ")
if (index(subtype[1], "array") == 1)
   simp_type="array"
if (index(subtype[num_fields], ")") != 0)
   simp_type="func-literal"
if (subtype[1] == "enum")
   simp_type="enum"
if (subtype[1] == "fnptr-to")
   simp_type="fnptr-to"
if (subtype[1] == "ptr-to")
   simp_type="ptr-to"
if (subtype[1] == "struct")
   simp_type="struct"
if (subtype[1] == "union")
   simp_type="union"
if (subtype[1] == "function")
   simp_type="function"
gsub(/^ +/, "", simp_type)
gsub(/ +$/, "", simp_type)
}

BEGIN {
   num_imp_cast=0
   start_file()
   }

$1 == "include_open" {
   inc_depth++
   sys_hdr_stack[inc_depth]=in_sys_hdr
   in_sys_hdr= ($2 == "h_hdr")
   hdr_seen_stack[inc_depth]=hdr_seen_before
   hdr_seen_before= (hdrs_seen[$3] != 0)
   hdrs_seen[$3]=1
   next
   }

$1 == "include_close" {
   in_sys_hdr=sys_hdr_stack[inc_depth]
   hdr_seen_before=hdr_seen_stack[inc_depth]
   inc_depth--
   next
   }

$0 ~ /Copyright \(c\) 1990-.* Knowledge Software Ltd/ {
	if (inc_depth != 0)
	   print "inc_depth " inc_depth
	start_file()
	next
	}

in_sys_hdr == 1 {
	next
	}

hdr_seen_before == 1 {
	next
	}

$1 == "int_promote" {
   $1=""
   if (index($0, "ptr-to") == 0) {
      if (index($0, "short") != 0)
         int_promote[$0]++
      if (index($0, "char") != 0)
         int_promote[$0]++
      }
   num_int_promote++
   next
   }

$1 == "imp_cast" {
   if ($3 == 139)
      lit="_"
   else if ($3 == 140)
      lit="_"
   else if ($3 == 141)
      lit="_"
   else
      lit=""
   $3=""
   split($0, types, "|")
   imp_to_from[types[3] " # " types[2]]++
   simplify_type(types[2])
   simp_type=lit simp_type
   types[2]=simp_type
   simplify_type(types[3])
   types[3]=simp_type
   simp_to_from["( " types[3] " ) ,, " types[2]]++
   num_imp_cast++
   next
   }

   {
   next
   }

END {
	print num_int_promote
	print "File: int_promote"
	others=100
	for (i in int_promote)
	   {
	   percent=100*(int_promote[i]/num_int_promote)
	   if (percent >= 0.1)
	      {
	      others=others-percent
	      printf("%s ,, %2.1f\n", i, percent)
	      }
	   }
	#printf("other operand types ,, %2.1f\n", others)
	print "End File"
	print num_imp_cast
	print "File: simp_to_from"
	others=0
	for (i in simp_to_from)
	   {
	   percent=100*(simp_to_from[i]/num_imp_cast)
	   if (percent < 1.0)
	      others=others+percent
	   else
	      printf("%s ,, %2.1f\n", i, percent)
	   }
	printf("( other-types ) ,, other-types ,, %2.1f\n", others)
	print "End File"
	print "File: imp_to_from"
	for (i in imp_to_from)
	   print i " # " imp_to_from[i]
	print "End File"

	}

