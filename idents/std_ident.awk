# std_ident.awk,  4 Jan 04
#
# Calculate the number of uses of identifiers
# reserved by the C Standard
#
BEGIN {
	max_std_id=0
	in_idents=0
	}

$1 == "EnD_StD_IdEnT" {
	in_idents=1
	next
	}

	{
	if (in_idents) {
	   if (std_id[$1] != 0) {
	      std_id[$1]++
	   }
	} else {
	   max_std_id++
	   std_id[$1]=1
	}
	next
	}

END {
    print "File: stdid.d"
    for (ind in std_id) {
       if (std_id[ind] != 0)
          print ind " " std_id[ind]-1
    }
    print "End File"

    print "File: lim_std_id.t"
    print "CHAR_BIT " std_id["CHAR_BIT"]-1
    print "SCHAR_MIN " std_id["SCHAR_MIN"]-1
    print "SCHAR_MAX " std_id["SCHAR_MAX"]-1
    print "UCHAR_MAX " std_id["UCHAR_MAX"]-1
    print "CHAR_MIN " std_id["CHAR_MIN"]-1
    print "CHAR_MAX " std_id["CHAR_MAX"]-1
    print "MB_LEN_MAX " std_id["MB_LEN_MAX"]-1
    print "SHRT_MIN " std_id["SHRT_MIN"]-1
    print "SHRT_MAX " std_id["SHRT_MAX"]-1
    print "USHRT_MAX " std_id["USHRT_MAX"]-1
    print "INT_MIN " std_id["INT_MIN"]-1
    print "INT_MAX " std_id["INT_MAX"]-1
    print "UINT_MAX " std_id["UINT_MAX"]-1
    print "LONG_MIN " std_id["LONG_MIN"]-1
    print "LONG_MAX " std_id["LONG_MAX"]-1
    print "ULONG_MAX " std_id["ULONG_MAX"]-1
    print "LLONG_MIN " std_id["LLONG_MIN"]-1
    print "LLONG_MAX " std_id["LLONG_MAX"]-1
    print "ULLONG_MAX " std_id["ULLONG_MAX"]-1
    print "End File"

    print "File: flt_std_id.t"
    print "FLT_ROUNDS " std_id["FLT_ROUNDS"]-1
    print "FLT_EVAL_METHOD " std_id["FLT_EVAL_METHOD"]-1
    print "FLT_RADIX " std_id["FLT_RADIX"]-1
    print "FLT_MANT_DIG " std_id["FLT_MANT_DIG"]-1
    print "DBL_MANT_DIG " std_id["DBL_MANT_DIG"]-1
    print "LDBL_MANT_DIG " std_id["LDBL_MANT_DIG"]-1
    print "DECIMAL_DIG " std_id["DECIMAL_DIG"]-1
    print "FLT_DIG " std_id["FLT_DIG"]-1
    print "DBL_DIG " std_id["DBL_DIG"]-1
    print "LDBL_DIG " std_id["LDBL_DIG"]-1
    print "FLT_MIN_EXP " std_id["FLT_MIN_EXP"]-1
    print "DBL_MIN_EXP " std_id["DBL_MIN_EXP"]-1
    print "LDBL_MIN_EXP " std_id["LDBL_MIN_EXP"]-1
    print "FLT_MIN_10_EXP " std_id["FLT_MIN_10_EXP"]-1
    print "DBL_MIN_10_EXP " std_id["DBL_MIN_10_EXP"]-1
    print "LDBL_MIN_10_EXP " std_id["LDBL_MIN_10_EXP"]-1
    print "FLT_MAX_EXP " std_id["FLT_MAX_EXP"]-1
    print "DBL_MAX_EXP " std_id["DBL_MAX_EXP"]-1
    print "LDBL_MAX_EXP " std_id["LDBL_MAX_EXP"]-1
    print "FLT_MAX_10_EXP " std_id["FLT_MAX_10_EXP"]-1
    print "DBL_MAX_10_EXP " std_id["DBL_MAX_10_EXP"]-1
    print "LDBL_MAX_10_EXP " std_id["LDBL_MAX_10_EXP"]-1
    print "FLT_EPSILON " std_id["FLT_EPSILON"]-1
    print "DBL_EPSILON " std_id["DBL_EPSILON"]-1
    print "LDBL_EPSILON " std_id["LDBL_EPSILON"]-1
    print "FLT_MIN " std_id["FLT_MIN"]-1
    print "DBL_MIN " std_id["DBL_MIN"]-1
    print "LDBL_MIN " std_id["LDBL_MIN"]-1
    print "FLT_MAX " std_id["FLT_MAX"]-1
    print "DBL_MAX " std_id["DBL_MAX"]-1
    print "LDBL_MAX " std_id["LDBL_MAX"]-1
    print "End File"

    total_predefined=std_id["__LINE__"]-1+                \
				std_id["__FILE__"]-1+     \
				std_id["__TIME__"]-1+     \
				std_id["__DATE__"]-1+     \
				std_id["__STDC__"]-1+     \
				std_id["__STDC_HOSTED__"]-1+    \
				std_id["__STDC_VERSION__"]-1+   \
				std_id["__STDC_IEC_559__"]-1+   \
				std_id["__STDC_IEC_559_COMPLEX__"]-1+              \
				std_id["__STDC_ISO_10646__"]-1
    print "Total predefined " total_predefined
    print "File: predef_macro.t"
    printf("__LINE__ %2.2f\n", 100*((std_id["__LINE__"]-1)/total_predefined))
    printf("__FILE__ %2.2f\n", 100*((std_id["__FILE__"]-1)/total_predefined))
    printf("__TIME__ %2.2f\n", 100*((std_id["__TIME__"]-1)/total_predefined))
    printf("__DATE__ %2.2f\n", 100*((std_id["__DATE__"]-1)/total_predefined))
    printf("__STDC__ %2.2f\n", 100*((std_id["__STDC__"]-1)/total_predefined))
    printf("__STDC_HOSTED__ %2.2f\n", 100*((std_id["__STDC_HOSTED__"]-1)/total_predefined))
    printf("__STDC_VERSION__ %2.2f\n", 100*((std_id["__STDC_VERSION__"]-1)/total_predefined))
    printf("__STDC_IEC_559__ %2.2f\n", 100*((std_id["__STDC_IEC_559__"]-1)/total_predefined))
    printf("__STDC_IEC_559_COMPLEX__ %2.2f\n", 100*((std_id["__STDC_IEC_559_COMPLEX__"]-1)/total_predefined))
    printf("__STDC_ISO_10646__ %2.2f\n", 100*((std_id["__STDC_ISO_10646__"]-1)/total_predefined))
    print "End File"
    }

