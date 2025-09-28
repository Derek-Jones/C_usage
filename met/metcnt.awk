BEGIN {
   total_files=0
   total_funcs=0
   NO_SECTION=0
   METRICS=1
   PPTOKS=2
   TOKS=3
   in_section=NO_SECTION
   }

$1 ~ /^\.FILE/ {
   if (start_depth != 0) {
      print "start depth=" start_depth " " $0
      }
   start_depth=0
   in_func=0
   in_global=0
   num_funcs=0
   num_included=0
   in_section=NO_SECTION
   total_files++
   next
   }

$1 ~ /^\.START/ {
   start_depth++
   incl_nest[start_depth]++
   next
   }

$1 ~ /^\.END/ {
   in_section=NO_SECTION
   if (in_func == 1) {
      in_func=0
      local_obj_distrib[num_local_objs]++
      local_tot_size_distrib[total_local_size]++
      local_typedef_distrib[num_local_typedefs]++
      param_distrib[num_params]++
      local_econst_distrib[num_local_econst]++
   } else {
      start_depth--;
      }
   next
   }

$1 ~ /^\.FUNC/ {
   in_func=1
   in_global=0
   num_funcs++
   num_local_objs=0
   num_local_typdefs=0
   total_local_size=0
   num_local_econst=0
   num_params=0
   total_funcs++
   next
   }

$1 ~ /^\.ARG/ {
   num_params++
   next
   }

$1 ~ /^\.LOCAL/ {
   if ($11 == "IDENT") {
      if ($12 == "econst") {
         num_local_econst++
      } else {
         num_local_objs++
         total_local_size+=$10
         local_scope_distrib[$4-1]++
         local_used_distrib[$6]++
         local_set_distrib[$8]++
         local_size_distrib[$10]++
	 local_obj_type[$12]++
      }
   } else if ($11 == "TYPEDEF") {
      num_local_typedef++  
   }
   next
   }

$1 ~ /^\.GLOBAL/ {
   in_global=1
   next
   }

$1 ~ /^\.METRICS/ {
   in_section=METRICS
   next
   }

$1 ~ /^\.PPTOKS/ {
   in_section=PPTOKS
   next
   }

$1 ~ /^\.TOKS/ {
   in_section=TOKS
   next
   }

$1 ~ /^\.ERR/ {
   next
   }

$1 ~ /^\.ACC/ {
   next
   }

$1 ~ /^\.MOD/ {
   next
   }

$1 ~ /^\.CALL/ {
   next
   }

$1 ~ /^\.INCLUDED/ {
   in_section=NO_SECTION
   num_included++
   next
   }

   {
   if (start_depth != 1) {
      next
   }

   if (in_section == NO_SECTION) {
      if (in_global == 1) {
         if ($2 == "EXTERNAL") {
	    id_ext_file++
         } else if ($2 == "INTERNAL") {
	    id_int_file++
         }
      }
   } else if (in_section == METRICS) {
   } else if (in_section == PPTOKS) {
   } else if (in_section == TOKS) {
      for (rec=1; rec < NF; rec+=2) {
         if (in_global == 1) {
	    glob_toks[$rec]+=$(rec+1)
	 } else {
	    loc_toks[$rec]+=$(rec+1)
         }
      }
   }
   next
   }

END {
   print "Total files=" total_files ", total functions=" total_funcs
   print "total id/ext/file=" id_ext_file ", total id/int/file=" id_int_file
   print "incnest.d include nesting"
   for (ind in incl_nest) {
      print ind " " incl_nest[ind]
      }
   print "locobjdec.d locals"
   for (ind in local_obj_distrib) {
      print ind " " local_obj_distrib[ind]
      }
   print "totlocsize.d local summed sizes"
   for (ind in local_tot_size_distrib) {
      print ind " " local_tot_size_distrib[ind]
      }
   print "locsize.d local object sizes"
   for (ind in local_size_distrib) {
      print ind " " local_size_distrib[ind]
      }
   print "locsize.d local object types"
   for (ind in local_obj_type) {
      print ind " " local_obj_type[ind]
      }
   print "scope.d nesting of local definitions"
   for (ind in local_scope_distrib) {
      print ind " " local_scope_distrib[ind]
      }
   print "locals used"
   for (ind in local_used_distrib) {
      print ind " " local_used_distrib[ind]
      }
   print "locals set"
   for (ind in local_set_distrib) {
      print ind " " local_set_distrib[ind]
      }
   print "local typedefs"
   for (ind in local_typedef_distrib) {
      print ind " " local_typedef_distrib[ind]
      }
   print "params.d param count"
   for (ind in param_distrib) {
      print ind " " param_distrib[ind]
      }
   print "leconst.d local enum constants count"
   for (ind in local_econst_distrib) {
      print ind " " local_econst_distrib[ind]
      }
   print "loctok.d local token count"
   for (ind in loc_toks) {
      print ind " " loc_toks[ind]
      }
   print "globtok.d global token count"
   for (ind in glob_toks) {
      print ind " " glob_toks[ind]
      }
   }

