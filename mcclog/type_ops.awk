# type_ops.awk, 30 Nov 03
#

function simplify_type(op_type)
{
simp_type=op_type
num_fields=split(op_type, subtype, " ")
if (index(subtype[1], "array") == 1)
   simp_type="array-index"
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
}

function get_base_type(op_type)
{
cur_op_ptr=0
base_type=op_type
num_fields=split(base_type, subtype, " ")
#while (index(subtype[1], "array") == 1) {
#   simp_type=subtype[3]
#   for (i=4; i <= num_fields; i++)
#      simp_type=simp_type " " subtype[i]
#   num_fields=split(simp_type, subtype, " ")
#   }
if (index(subtype[num_fields], ")") != 0)
   {
   cur_op_ptr=1
   op_is_ptr++
   base_type="func-literal"
   }
if (subtype[1] == "fnptr-to")
   {
   cur_op_ptr=1
   op_is_ptr++
   sub("fnptr-to", "", base_type)
   }
if (subtype[1] == "ptr-to")
   {
   cur_op_ptr=1
   op_is_ptr++
   sub("ptr-to", "", base_type)
   }
simplify_type(base_type)
if (cur_op_ptr == 1)
   {
   gsub(/^ */, "", simp_type)
   gsub(/ *$/, "", simp_type)
   simp_type=simp_type " *"
   }
}

