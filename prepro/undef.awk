# undef.awk, 18 Apr 03
#
# Count the preprocessor directive properties
# of identifiers that are #undef'ed
#

BEGIN {
	}

$1 == "#UNDEF" {
	num_undef++
	undef[$2]++
	if (undef_seq[$2] != "") {
	   undef_seq[$2]=undef_seq[$2] " " $1
	} else {
	   num_first_undefs++
	   undef_seq[$2]="u "
	   }
	if (ident[$2] == 1) {
	   num_undef_undef++
	} else {
	   ident[$2]=1
	   }
	next
	}

# count the number of #undef's that occur before the
# first #include in a file.
#
$1 ~ /"/ {
	if (seen_include == 0) {
	   for (u in ident) {
	      if (ident[u] == 1) {
	         num_undef_qincl++
		 }
	      }
	   }
	seen_include=1
	next
	}

$1 ~ /</ {
	if (seen_include == 0) {
	   for (u in ident) {
	      if (ident[u] == 1) {
	         num_undef_hincl++
		 }
	      }
	   }
	seen_include=1
	next
	}

$1 == "#DEFINE" {
	num_define++
	define[$2]++
	if (undef_seq[$2] != "") {
	   undef_seq[$2]=undef_seq[$2] " " $1
	   }
	if (ident[$2] == 1) {
	   ident[$2]=4
	   num_undef_define++
	} else {
	   }
	next
	}

$1 == "#IFDEF" {
	num_ifdef++
	if (undef_seq[$2] != "") {
	   undef_seq[$2]=undef_seq[$2] " " $1
	   }
	if (ident[$2] == 1) {
	   ident[$2]=5
	   num_undef_ifdef++
	} else {
	   }
	next
	}

$1 == "#IFNDEF" {
	num_ifdef++
	if (undef_seq[$2] != "") {
	   undef_seq[$2]=undef_seq[$2] " " $1
	   }
	if (ident[$2] == 1) {
	   ident[$2]=6
	   num_undef_ifndef++
	} else {
	   }
	next
	}

$1 == "__E__O__F__"  {
    for (u in undef_seq) {
       if (undef_seq[u] != "") {
	  num_undef_seq++
	  #
	  # Reduce multiple sequencies of a directive to a single instance
	  do {
	     submade=gsub(/\#DEFINE \#DEFINE/, "\#DEFINE", undef_seq[u])
	     submade+=gsub(/\#IFDEF \#IFDEF/, "\#IFDEF", undef_seq[u])
	     submade+=gsub(/\#IFNDEF \#IFNDEF/, "\#IFNDEF", undef_seq[u])
	     submade+=gsub(/\#UNDEF \#UNDEF/, "\#UNDEF", undef_seq[u])
	     } while (submade != 0)
	  do {
	     submade=gsub(/\#UNDEF \#DEFINE/, "\#UND-DEF", undef_seq[u])
	     submade+=gsub(/\#UND-DEF \#UND-DEF/, "\#UND-DEF", undef_seq[u])
	     submade+=gsub(/\#IFDEF \#IFNDEF/, "\#IF\(N\)DEF", undef_seq[u])
	     submade+=gsub(/\#IFDEF \#IF\(N\)DEF/, "\#IF\(N\)DEF", undef_seq[u])
	     submade+=gsub(/\#IF\(N\)DEF \#IFDEF/, "\#IF\(N\)DEF", undef_seq[u])
	     submade+=gsub(/\#IFNDEF \#IFDEF/, "\#IF\(N\)DEF", undef_seq[u])
	     submade+=gsub(/\#IFNDEF \#IF\(N\)DEF/, "\#IF\(N\)DEF", undef_seq[u])
	     submade+=gsub(/\#IF\(N\)DEF \#IFNDEF/, "\#IF\(N\)DEF", undef_seq[u])
	     submade+=gsub(/\#IF\(N\)DEF \#IF\(N\)DEF/, "\#IF\(N\)DEF", undef_seq[u])
	     } while (submade != 0)
          cnt_undef_seq[undef_seq[u]]++
	  }
       }

	seen_include=0
	delete ident
	delete undef_seq
	next
	}

END {
    print "num undef " num_undef
    print "num first undef " num_first_undefs
    print "num define " num_define
    print "num ifdef " num_ifdef
    print "num undef-q-include " num_undef_qincl
    print "num undef-h-include " num_undef_hincl
    print "num undef-undef " num_undef_undef
    print "num undef-define " num_undef_define
    print "num undef-ifdef " num_undef_ifdef
    print "num undef-ifndef " num_undef_ifndef
    print "num undef-define-ifdef " num_undef_define_ifdef
    
    TEMP_FILE="uf" systime()
    printf("") > TEMP_FILE
    print "number of #undefs " num_undef
    for (u in undef) {
       print undef[u] " " u >> TEMP_FILE
    }
    close(TEMP_FILE)
    system("sort -gr < " TEMP_FILE)

    print "" > TEMP_FILE
    print "number of #defines " num_define
    for (u in define) {
       print define[u] " " u >> TEMP_FILE
    }
    close(TEMP_FILE)
    system("sort -gr < " TEMP_FILE)

    print "" > TEMP_FILE
    print "number abstract undef sequence " num_undef_seq
    for (u in cnt_undef_seq) {
       print cnt_undef_seq[u] " " u >> TEMP_FILE
    }
    close(TEMP_FILE)
    system("sort -gr < " TEMP_FILE)
    
    system("rm " TEMP_FILE)
    }

