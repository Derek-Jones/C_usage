# esutag.awk,  3 Jan 04
#
# tag usage information
#

BEGIN {
	num_anon=0
	num_tag_defs=0
	esu_syntax["ENUM id ;"]=0
	esu_syntax["ENUM id {"]=0
	esu_syntax["ENUM {"]=0
	esu_syntax["ENUM id id"]=0
	esu_syntax["STRUCT id ;"]=0
	esu_syntax["STRUCT id {"]=0
	esu_syntax["STRUCT {"]=0
	esu_syntax["STRUCT id id"]=0
	esu_syntax["UNION id ;"]=0
	esu_syntax["UNION id {"]=0
	esu_syntax["UNION {"]=0
	esu_syntax["UNION id id"]=0
	}

$1 == "STRUCT" ||
$1 == "UNION" ||
$1 == "ENUM"  {
	gsub("NEW_LINE", "", $0)
	tag_name=""
	tag_field=1
	for (i=2; i <= NF; i++)
	   if ($i == "{")
	      break
	   else if ($i != "") {
	      tag_name=$i
	      tag_field=i
	      break
	      }
	#
	# struct tag ;
	# struct tag {...
	# struct { ...
	# struct tag obj = { ...
	is_def=0
	is_obj_decl=0
	for (i=tag_field+1; i <= NF; i++)
	   if ($i == "{") {
	      is_def=1
	      break
	   } else if (($i == "=") || ($i == ";"))
	      break
	   else if ($i != "")
	      {
	      is_obj_decl=1
	      break
	      }
	if (is_def == 1)
	   {
	   if (tag_name == "")
	      esu_syntax[$1 " {"]++
	   else
	      esu_syntax[$1 " id {"]++
	   }
	else if (is_obj_decl == 1)
	      esu_syntax[$1 " id id"]++
	   else
	      esu_syntax[$1 " id ;"]++
	if (tag_name == "")
	   num_anon++
	else if (is_def == 0) {
	   if (def_tag[tag_name] == 0)
	      def_tag[tag_name]=1
	   else
              {
	      nv_tag[tag_name]++
	      def_tag[tag_name]=2
              }
	   if ($1 == "STRUCT")
	      st_refs[tag_name]++
	   else if ($1 == "ENUM")
	      et_refs[tag_name]++
	   else if ($1 == "UNION")
	      ut_refs[tag_name]++
           }
	else
	   num_tag_defs++
	next
	}

$1 == "__E__O__F__" {
	for (i in st_refs)
	   stag_refs[st_refs[i]]++
	delete st_refs
	for (i in ut_refs)
	   utag_refs[ut_refs[i]]++
	delete ut_refs
	for (i in et_refs)
	   etag_refs[et_refs[i]]++
	delete et_refs
	for (i in nv_tag)
	   nonvis_tag[nv_tag[i]]++
	delete nv_tag
	delete def_tag
	anon_tags[num_anon]++
	num_anon=0
	tag_defs[num_tag_defs]++
	num_tag_defs=0
	next
	}

	{
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in stag_refs)
	   print i " " stag_refs[i] >> TEMP_FILE
	print "File: stag_refs.d"
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in utag_refs)
	   print i " " utag_refs[i] >> TEMP_FILE
	print "File: utag_refs.d"
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in etag_refs)
	   print i " " etag_refs[i] >> TEMP_FILE
	print "File: etag_refs.d"
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in tag_defs)
	   print i " " tag_defs[i] >> TEMP_FILE
	print "File: tag_defs.d"
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in nonvis_tag)
	   print i " " nonvis_tag[i] >> TEMP_FILE
	print "File: nonvis_tag.d"
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in anon_tags)
	   print i " " anon_tags[i] >> TEMP_FILE
	print "File: anon_tags.d"
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in esu_syntax)
	   print " " i " ,, " esu_syntax[i] >> TEMP_FILE
	print "File: esu_syntax.t"
	close(TEMP_FILE)
	system("sort < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

