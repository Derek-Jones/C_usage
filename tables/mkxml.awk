# mkxml.awk, 18 Dec 07
#
# Convert tokens to book xml form

BEGIN {
	LOGICAL_OPS=" && || "
	SHIFT_OPS=" >> << "
	BITWISE_OPS=" & | ^ "
	BIT_OPS=" ~ ! ^= <<= >>= &= |= "
	MULT_OPS=" * / % "
	ADD_OPS=" - + "
	ASSIGN_OPS=" = += -= *= /= %= |= &= ^= <<= >>= "
	ARITH_OPS=" += -= *= /= %= "
	REL_OPS=" < <= > >= "
	EQUAL_OPS=" == != "
	POSTFIX_OPS=" . -> v++ v-- "
	PREFIX_OPS=" ++v --v "
	UNARY_OPS=" sizeof &v *v +v -v ~ ! "
	TERNARY_OPS=" ? ?: "
	PUNCT_TOK=" [ ] { } ( ) : ; \# \#\# , . ... :c *p "
	UNARY_OPS=" sizeof &v *v +v -v ~ ! "
	punct_str=LOGICAL_OPS SHIFT_OPS BITWISE_OPS MULT_OPS ADD_OPS ASSIGN_OPS REL_OPS EQUAL_OPS POSTFIX_OPS PREFIX_OPS UNARY_OPS TERNARY_OPS PUNCT_TOK
	STORE_CLASS=" typedef extern static register auto "
	TYPE_SPEC="  void char short int long float double signed unsigned struct union enum typedef-name "
	COMPOSITE_TYPE=" enum struct union "
	TYPE_QUAL=" const volatile restrict "
	LANG_KEYWORD=" if else while do for switch case default break continue goto return "
	OPERATOR_TOK=" sizeof "
	PPDIR_TOK=" #if #ifdef #ifndef #elif #else #endif #define #include #undef #error #line #pragma "
	PP_OP=" DEFINED "
	keyword= COMPOSITE_TYPE STORE_CLASS TYPE_QUAL TYPE_SPEC OPERATOR_TOK LANG_KEYWORD PPDIR_TOK PP_OP
	SYNTAX=" integer-constant floating-constant character-constant string-literal "
	}

	{
	gsub("DEFINED", "defined", $0)
	gsub("prog_all", "Total", $0)
	gsub("signedchar", "signed char", $0)
	gsub("unsignedchar", "unsigned char", $0)
	gsub("unsignedshort", "unsigned short", $0)
	gsub("unsignedint", "unsigned int", $0)
	gsub("unsignedlong", "unsigned long", $0)
	gsub("long_double", "long double", $0)
	gsub("ptr_to", "*", $0)
	#gsub("array", "array of", $0)
	gsub("volatileconst", "volatile const", $0)
	gsub("INT_CONST", "<c_syntax>integer-constant</c_syntax>", $0)
	gsub("FLOAT_CONST", "<c_syntax>floating-constant</c_syntax>", $0)
	gsub("CHAR_CONST", "<c_syntax>character-constant</c_syntax>", $0)
	gsub("STRING", "<c_syntax>string-literal</c_syntax>", $0)
	gsub("IDENT", "identifier", $0)
	gsub("OBJECT", "object", $0)

	gsub("hexadecimal-constant", "<c_syntax>hexaQecimal-constant</c_syntax>", $0)
	gsub("decimal-constant", "<c_syntax>decimal-constant</c_syntax>", $0)
# The Q is to prevent the match against decimal-constant
	gsub("hexaQecimal-constant", "hexadecimal-constant", $0)
	gsub("octal-constant", "<c_syntax>octal-constant</c_syntax>", $0)

	gsub("OBJ_MAC", "object-macro", $0)
	gsub("FUNC_MAC", "function-macro", $0)
	gsub("#UND-DEF", "#undef-#define", $0)
	gsub(/#IF\(N\)DEF/, "#if(n)def", $0)
	
	gsub("CONST_EXPR", "<c_syntax>constant-expression</c_syntax>", $0)
	gsub("EXPR", "expression", $0)
	gsub("ASSIGN", "assignment", $0)
	gsub("FUNC", "function-call", $0)
	gsub("CPP_COMMENT", "\\\\", $0)
	gsub("COMMENT_NL", "\\* new-line *\\", $0)
	gsub("COMMENT", "\\* ... *\\", $0)
	gsub("HEADER", "header-name", $0)
	gsub(" , ", " \\&comma; ", $0)
	for (i=1; i <= NF; i++)
	   if (index(punct_str, " " $i " ") != 0)
	      $i="<keyword>" $i "</keyword>"
	#
	# we don't always want to convert to lower case
	# also tolower(" ,,") -> ",," for some reason
	#
	for (i=1; i <= NF; i++) {
	   if (index(keyword, " " tolower($i) " ") != 0)
	      $i="<keyword>" tolower($i) "</keyword>"
	   if (index($i, "_") == 1) 
	      {
	      lit_type=tolower(substr($i, 2))
	      if (index(TYPE_SPEC, " " lit_type " ") != 0)
	         $i="_<keyword>" lit_type "</keyword>"
	      }
	   }
	for (i=1; i <= NF; i++) {
	   if (index(SYNTAX, " " $i " ") != 0)
	      $i="<c_syntax>" $i "</c_syntax>"
	   }
	$0=gensub(/ ([0-9]+) /, " \\&zs;\\1\\&ze; ", "g")
	$0=gensub(/ ([0-9]+)$/, " \\&zs;\\1\\&ze;", "g")
	$0=gensub(/\(([0-9]+)\)/, "(\\&zs;\\1\\&ze;)", "g")
	$0=gensub(/ ([0-9]+\.[0-9][0-9][0-9]) /, " \\&z3p;\\1\\&ze; ", "g")
	$0=gensub(/ ([0-9]+\.[0-9][0-9][0-9])$/, " \\&z3p;\\1\\&ze;", "g")
	$0=gensub(/ ([0-9]+\.[0-9][0-9]) /, " \\&z2p;\\1\\&ze; ", "g")
	$0=gensub(/ ([0-9]+\.[0-9][0-9])$/, " \\&z2p;\\1\\&ze;", "g")
	$0=gensub(/ ([0-9]+\.[0-9]) /, " \\&zp;\\1\\&ze; ", "g")
	$0=gensub(/ ([0-9]+\.[0-9])$/, " \\&zp;\\1\\&ze;", "g")
	$0=gensub(/\(([0-9]+\.[0-9])\)/, "(\\&zp;\\1\\&ze;)", "g")
	gsub("@@", "<b>", $0)
	gsub("`@", "</b>", $0)
	gsub(" nan ", " &emdash; ", $0)
	gsub("^,, ", " ,, ", $0)
	gsub(" ,,", ", ", $0)
	gsub(",  ", ", ", $0)
	print $0
	next
	}

END {
    }

