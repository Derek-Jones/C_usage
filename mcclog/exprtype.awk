# exprtype.awk, 29 Aug 03
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
while (index(subtype[1], "array") == 1) {
   simp_type=subtype[3]
   for (i=4; i <= num_fields; i++)
      simp_type=simp_type " " subtype[i]
   num_fields=split(simp_type, subtype, " ")
   }
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
}

BEGIN {
   start_file()
num_2_tok[5]= "CHAR"
num_2_tok[6]= "FLOAT"
num_2_tok[7]= "DOUBLE"
num_2_tok[8]= "INT"
num_2_tok[9]= "SHORT"
num_2_tok[10]= "LONG"
num_2_tok[11]= "UNSIGNED"
num_2_tok[12]= "SIGNED"
num_2_tok[13]= "VOID"
num_2_tok[14]= "CONST"
num_2_tok[15]= "VOLATILE"
num_2_tok[16]= "STRUCT"
num_2_tok[17]= "UNION"
num_2_tok[18]= "ENUM"
num_2_tok[19]= "IF"
num_2_tok[20]= "ELSE"
num_2_tok[21]= "WHILE"
num_2_tok[22]= "FOR"
num_2_tok[23]= "DO"
num_2_tok[24]= "SWITCH"
num_2_tok[25]= "CASE"
num_2_tok[26]= "DEFAULT"
num_2_tok[27]= "BREAK"
num_2_tok[28]= "CONTINUE"
num_2_tok[29]= "RETURN"
num_2_tok[30]= "GOTO"
num_2_tok[31]= "sizeof"
num_2_tok[32]= "("
num_2_tok[33]= "<<"
num_2_tok[34]= ">>"
num_2_tok[35]= "+v"
num_2_tok[36]= "+"
num_2_tok[37]= "-v"
num_2_tok[38]= "-"
num_2_tok[39]= "STAR"
num_2_tok[40]= "*"
num_2_tok[41]= "%"
num_2_tok[42]= "/"
num_2_tok[43]= "^"
num_2_tok[44]= "AND"
num_2_tok[45]= "&"
num_2_tok[46]= "|"
num_2_tok[47]= "~"
num_2_tok[48]= "!"
num_2_tok[49]= "<"
num_2_tok[50]= "<="
num_2_tok[51]= ">="
num_2_tok[52]= ">"
num_2_tok[53]= "=="
num_2_tok[54]= "!="
num_2_tok[55]= "&&"
num_2_tok[56]= "||"
num_2_tok[57]= "?"
num_2_tok[58]= "?:"
num_2_tok[59]= ")"
num_2_tok[60]= "."
num_2_tok[61]= "->"
num_2_tok[62]= "++"
num_2_tok[63]= "--"
num_2_tok[64]= ","
num_2_tok[65]= "SEMICOLON"
num_2_tok[66]= "ELLIPSIS"
num_2_tok[67]= "OPEN_CURL"
num_2_tok[68]= "CL_CURL"
num_2_tok[69]= "OPEN_SQUARE"
num_2_tok[70]= "CL_SQUARE"
num_2_tok[71]= "="
num_2_tok[72]= "+="
num_2_tok[73]= "-="
num_2_tok[74]= "*="
num_2_tok[75]= "<<="
num_2_tok[76]= ">>="
num_2_tok[77]= "&="
num_2_tok[78]= "/="
num_2_tok[79]= "%="
num_2_tok[80]= "|="
num_2_tok[81]= "^="
num_2_tok[(99 + 29)]= "FNC_CALL"
num_2_tok[(99 + 30)]= "v++"
num_2_tok[(99 + 31)]= "v--"
num_2_tok[(99 + 32)]= "++v"
num_2_tok[(99 + 33)]= "--v"
num_2_tok[(99 + 34)]= "&v"
num_2_tok[(99 + 35)]= "*v"
num_2_tok[(99 + 36)]= "["
num_2_tok[(99 + 37)]= "PTR_MINUS"
num_2_tok[(99 + 38)]= "cast"
num_2_tok[(99 + 39)]= "UN_COMMA"
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

$1 == "expr_op_type_type" {
   if ($4 == 139)
      l_lit="_"
   else if ($4 == 140)
      l_lit="_"
   else if ($4 == 141)
      l_lit="_"
   else
      l_lit=""
   $4=""
   for (i=6; i <= NF; i++)
      if ($i == "|") {
	 if ($(i+1) == 139)
	    r_lit="_"
	 else if ($(i+1) == 140)
	    r_lit="_"
	 else if ($(i+1) == 141)
	    r_lit="_"
	 else
	    r_lit=""
         $(i+1)=""
	 }
   split($0, types, "|")
   op_type[num_2_tok[$2] " # " l_lit types[2] " # " r_lit types[3]]++
   simplify_type(types[2])
   types[2]=l_lit simp_type
   simplify_type(types[3])
   types[3]=r_lit simp_type
   op_sim_type[num_2_tok[$2] " # " types[2] " # " types[3]]++
   num_op[num_2_tok[$2]]++
   next
   }

   {
   next
   }

END {
	print "File: counts"
	for (i in num_op)
	   print i " " num_op[i]
	print "End File"
	TEMP_FILE="et" systime()
	printf("") > TEMP_FILE
	for (i in op_sim_type)
	   print i " # " op_sim_type[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: op_sim_type"
	system("sort < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in op_type)
	   print i " # " op_type[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: op_type"
	system("sort < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

