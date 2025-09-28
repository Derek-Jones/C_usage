# getdeclinfo.awk, 16 Jul 03
#
# enum declarations
# not used at the moment

BEGIN {
	}

$0 ~ /^ENUM {/ ||
$0 ~ /^ENUM NEWLINE {/ ||
$0 ~ /^ENUM NEWLINE IDENT {/ ||
$0 ~ /^ENUM IDENT NEWLINE {/ ||
$0 ~ /^ENUM IDENT {/ {
	print $0
	next
	}

        {
	next
	}

END {
    }

