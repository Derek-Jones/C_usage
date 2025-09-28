# updTABLE.awk, 10 Aug 03
#
# Add rows to between .TABLE/.E_TABLE

function gen_tab_data()
{
if (tab_data_generated == 0)
   system(CONV_PROG tab_file)
tab_data_generated=1
}


BEGIN {
	TAB_DIR="tab_data"
	CONV_PROG= "awk -f mkxml.awk < "
	tab_data_generated=1
	}

$1 == "<caption>" ||
$1 == ".E_TABLE" {
	gen_tab_data()
	in_table=0
	print $0
	next
	}

$1 == ".TABLE" {
	tab_file=TAB_DIR "/" $2
	if (($2 != "") && (system("if [ -e " tab_file " ]; then exit 1; else exit 0; fi") == 1)) {
	   in_table=1
	   in_hdr_lines=1
	   tab_data_generated=0
	   }
	#print tab_file ": system == "system("if [ -e " tab_file " ]; then exit 1; else exit 0; fi")
	print $0
	next
	}

	{
	if (in_table == 1) {
	   if (in_hdr_lines == 1) {
	      if ($1 == ":") {
	         print $0
	      } else {
	         print $0
		 in_hdr_lines=0
		 #print "++++"
		 gen_tab_data()
		 }
	   }
	   # else skip any lines before the <caption>
	} else {
	   print $0
	   }
	next
	}

END {
    }

