/*	$Header$

	CGRAM		LastMod	 3 Jun 00  DJ
			Created	   Jul 86  DJ

##############################################################################

	'C' Compiler grammar

	(c) 1986-2000 Knowledge Software Ltd, all rights reserved

##############################################################################
         
	 3 Jun 00  DJ   Added @eeprom etc support
	 8 Jun 99  DJ   Added variable value tracking calls
	31 Jul 98  DJ   Added GCC ... in old_param_decl_list
	16 Feb 97  DJ   Added GCC unary && support
	 7 Feb 97  DJ   Added GCC alignof support
	15 Jan 97  DJ   Added checks for Java compatibility :-O
	13 Jun 96  DJ   Added limited GCC statement expression support,
					taken from version 2.7.2
	 2 Mar 96  DJ   Added GCC typeof support, taken from version 2.7.2
	 8 Feb 96  DJ   Added GCC attribute support, taken from version 2.7.2
	11 Oct 95  DJ   Added GCC asm support
	 9 Aug 94  DJ   Added SQL token + some rules
	11 Feb 94  DJ   Fixed misparse (bug) of *(*f(void)){}
	 5 Sep 93  DJ   Improved error recovery on C++ constructs
	23 Jul 93  DJ   Added lint like checks
	 8 Mar 93  DJ   Fixed void *y; void ** const x problem
	20 Jun 92  DJ   Fixed typedef int l; l: ... goto l;
	23 Aug 90  SAC  Fixed enum range check for 4-byte int
	15 Aug 90  SAC  Fixed bug in empty declarator trapping
	14 Aug 90  SAC  Trapped unmatched '#if's at end of source
	18 Jul 90  SAC  Removed 'extension to C' message from pascal/fortran
			Fixed trailing comma on enumerator_list
	25 Jun 90  SAC  Fixed bug in typedef acceptance in casts
	21 Jun 90  SAC  Fixed bug in typedef acceptance within decl lists
	20 Jun 90  SAC  Told Mk_Sizeof about lvalue-ness
	 5 Jun 90  SAC  Changed calls to Get_Cmpd
	 3 Jan 90  SAC  Changed fn param structure
	22 Nov 89  SAC  Fixed prototype scope handling
	17 Nov 89  SAC  Fixed bug with initialized arrays of unknown size
	15 Nov 89  SAC  Fixed bug with mixed labels inside switch
	25 Aug 89  SAC  Fixed undeclared variable not spotted
	13 Jul 89  SAC  Fixed enum consts with casts
	28 Jun 89  SAC  Added full wide char/string support
	16 Jun 89  SAC  Fixed labels for relative jumps
	 7 Jun 89  SAC  Initializer handling changed not to build tree
	24 Apr 89  SAC  Fixed some bugs in expression syntax
	30 Jan 89  SAC  Fixed bug with enum tag & typedefname
	27 Jan 89  SAC  Fixed another typedef bug with struct tags
	 3 Nov 88  SAC  Fixed typedef bug with struct tags
	 9 Sep 88  SAC  Changed function param list handling
	20 Aug 88  SAC	Fixed undeclared ident msg appearing twice
	 4 Aug 88  SAC	Fixed undeclared ident not spotted in sizeof
	 3 Aug 88  SAC	Fixed undeclared ident not spotted in params
	 2 Aug 88  SAC	Fixed typedef in parameter list bug
	 7 Aug 87   DJ	Brought upto date with latest proposed ANSI C standard
	30 Jul 87  SAC	Removed Memory Manager for C compiler version
			Rearranged + augmented %token section
	17 Nov 86  SAC	Modded for Memory Manager
	   Jul 86   DJ	Created
*/

%token
AUTO STATIC EXTERN REGISTER TYPEDEF
CHAR FLOAT DOUBLE INT SHORT LONG UNSIGNED SIGNED VOID
CONST VOLATILE
STRUCT UNION ENUM
IF ELSE
WHILE FOR DO
SWITCH CASE DEFAULT
BREAK CONTINUE
RETURN
GOTO
SIZEOF
OPEN_RND
LEFTSHIFT RIGHTSHIFT
PLUS ADD
NEGATE MINUS
STAR TIMES REMAINDER
DIVIDE XOR
AND BITAND
OR BITNEGATE NOT
LT LE GE GT EQUAL NOTEQUAL ANDTEST ORTEST
QUESTION COLON
CLOSE_RND
DOT DEREF PLUSPLUS MINUSMINUS
COMMA SEMICOLON
ELLIPSIS
OPEN_CURL CLOSE_CURL
OPEN_SQUARE CLOSE_SQUARE
ASSIGN PLUSASSIGN MINUSASSIGN TIMESASSIGN LSASSIGN RSASSIGN ANDASSIGN
DIVASSIGN REMASSIGN ORASSIGN NOTASSIGN
LITERAL
IDENTIFIER TYPEDEFNAME
PASCAL FORTRAN
ASM ATTRIBUTE TYPEOF ALIGNOF
INLINE RESTRICT _BOOL _COMPLEX _IMAGINARY
AT_ADDR
EMBED_SQL_HERMAPH EMBED_SQL_DECL EMBED_SQL_STMT
UNDEFINED
%%

program : translation_unit
	  {
	  if (num_externals == 0)	
/*STD2103*/
	     LANG_ERROR(E_NO_EXTE_DECL);
	  if (cond_pending != NULL)	
/*STD2169*/
	     LANG_ERROR(E_MISSING_ENDIF);
	  do_postlude();
	  }	  ;


translation_unit :			
	  {
/*STD0146*/
	  scope_entry();
	  file_scope = cur_scope;
	  seen_usr_external_dcls = FALSE;
#ifdef GENERATE_CODE
	  out_prog_header();
#endif
	  magic_names();
	  }				|

	  translation_unit external_declaration
	  {
/*STD2103*/
	  seen_usr_external_dcls |= (hdr_nesting == 0);
	  just_seen_comment=FALSE;
	  fls_list();
	  free_nodes();		/* free up any leftover trees */
	  }				;


err_fn_body :			  
	  {
/*STD0150*/
          scope_entry();
	  ctl_function();
          had_statement = FALSE;
          not_labelled = FALSE;	
/*STD2129*/
/*STD2124*/
          cerror(E_FUNC_HEAD_MISS_SEMI_AFTE_FUNC);
	  /* frig function header for better parsing... */
          cur_fn_var = new_var((STR_PTR)NULL, nest_scope_depth); /* dummy function */
          cur_fn_var->vtype = mk_func((C_TYPE_PTR)NULL, OLD_FUNC_DECL,
	  				(PARAM_LIST_PTR)NULL);
	  }			   |

	  err_fn_body decl_or_stmt
	  {
          fls_list();
          free_nodes();		/* free up tree storage */
	  }		       ;

func_body : OPEN_CURL err_fn_body CLOSE_CURL
	    {
/*STD0162*/
            scope_exit(TRUE);
	    ctl_exit_fn();
            this_is_jump = FALSE;
            last_was_jump = FALSE;
	    }			     ;


/*STD2107*/
external_declaration : top_level_data_declaration |
                       function_definition        |
		       func_body		  |
		       asm_decl			  |
		       EMBED_SQL_DECL             |
	               EMBED_SQL_HERMAPH          ;


/*STD1337b*/
top_level_data_declaration : opt_decl_specifier SEMICOLON 
			     {
                             current_tok_p = $2.this_token;	
/*IMP ??? ??-?? */
			     if (cc_extensions[CPP_Extension])
			        cpp_struct(TRUE, cur_decl_spec,
						$1.u_ptr_c_type.ptr_c_type);
                             pop_decl_spec();
/*IMP ??? ??-?? */
                             if (tag_pending)
                                {				
/*STD1646*/
	                        if (decl_is_empty)  /* perform declaration of tag */
	                           decl_pending_tag();
	                        tag_pending = FALSE;
                                }
                             else if (decl_is_empty)	
/*STD1342*/
	                        LANG_ERROR(E_EMPT_DECL);
                             cur_decl_spec = (C_TYPE_PTR)NULL;
	    		     just_defined_type=FALSE;
                             decl_is_empty = TRUE;
                             tdef_valid = TRUE;
			     }				  |

			     opt_decl_specifier error SEMICOLON
			     {
                             pop_decl_spec();		
/*IMP ??? ??-?? */
                             cerror(E_SYNT_RECOV_DECL);
                             ats_errok();
                             cur_decl_spec = (C_TYPE_PTR)NULL;
	                     tag_pending = FALSE;
	    		     just_defined_type=FALSE;
                             decl_is_empty = TRUE;
                             tdef_valid = TRUE;
			     }					|

/*STD1337b*/
			     opt_decl_specifier list_init_dcltr SEMICOLON
			     {
/*IMP ??? ??-?? */
			     if (cc_extensions[CPP_Extension] &&
                                 (!tag_pending))
                                cpp_tag_usage(cur_decl_spec);
                             pop_decl_spec();
                             current_tok_p = $2.this_token;
#ifdef SQL_CHK
/*IMP ??? ??-?? */
                             if (in_sql_decl_section)
	                        sql_chk_decl($2.u_ptr_c_type.ptr_c_vlist);
#endif
                             cur_decl_spec = (C_TYPE_PTR)NULL;
	                     tag_pending = FALSE;
	    		     just_defined_type=FALSE;
                             decl_is_empty = TRUE;
                             tdef_valid = TRUE;
			     }						  |

			     CLOSE_RND			
			     {
                             current_tok_p = $1.this_token;	
/*IMP ??? ??-?? */
                             cerror(E_RIGHT_PAREN);	/* syntax error */
                             cur_decl_spec = (C_TYPE_PTR)NULL;
	    		     just_defined_type=FALSE;
                             tdef_valid = TRUE;
			     }					;


/* List Of Var */
old_param_decl_list :				    
	   {
           $$.this_token = (TOKEN_LIST)NULL;
           $$.u_ptr_c_type.ptr_c_vlist = (VLIST_PTR)NULL;
           decl_is_empty = TRUE;	/* ready for param decls */
           tdef_valid = TRUE;
	   }					     |

	   old_param_decl_list EMBED_SQL_DECL        |

	   old_param_decl_list ELLIPSIS		    
	   {
/*STD0001a*/
           if (!cc_extensions[GCC_Extension])
	      LANG_ERROR(E_GCC_ELLIPSIS);
	   }					     |
	   
	   old_param_decl_list parameter_declaration
	   {
           $$.this_token = $2.this_token;
           $$.u_ptr_c_type.ptr_c_vlist = app_var_list($2.u_ptr_c_type.ptr_c_vlist,
                                                      $1.u_ptr_c_type.ptr_c_vlist);
	   }					     ;


/* Variable */
function_header : opt_decl_specifier p3_fn_dcltr old_param_decl_list
		  {
      $$ = $2;	
/*IMP ??? ??-?? */
      if (get_base($$.u_ptr_c_type.ptr_c_var->vtype) == CFUNC)
         {
	 $$.u_ptr_c_type.ptr_c_var->vtype
                                   build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                                cur_decl_spec);
	 $$.u_ptr_c_type.ptr_c_var->v_scope = S_FNDEF;
	 current_tok_p = $3.this_token;
	/*
	 * The prototype scope opened by the p3_fn_dcltr is
	 * now (miraculously) considered to be block scope.
	 */
	 override_formals($$.u_ptr_c_type.ptr_c_var,
                                 $3.u_ptr_c_type.ptr_c_vlist);	
/*STD0251*/
	 func_scope_entry($$.u_ptr_c_type.ptr_c_var);
	 decl_formals(cur_fn_var);
#ifdef GENERATE_CODE
/*IMP ??? ??-?? */
	 if (generating_code)
	    {
	    fls_func_related_tables(FALSE, (DATA_OFF_TYPE)0,
                                          idx_ref(cur_fn_var));
   	    code_is_init = FALSE;
	    func_start(cur_fn_var);
   	    out_func_def(cur_fn_var);
   	    cur_fn_var->unreffed = FALSE;
	    }
#endif
	 $$.u_ptr_c_type.ptr_c_var = cur_fn_var;
         }
      else
	 {
	 LANG_ERROR(E_IDENT_NOT_FUNC_TYPE);
	 cur_fn_var = new_var((STR_PTR)NULL, nest_scope_depth);	/* dummy function */
         cur_fn_var->vtype = mk_func((C_TYPE_PTR)NULL, OLD_FUNC_DECL,
	 				(PARAM_LIST_PTR)NULL);
	 scope_entry();
	 }
      func_entry(cur_fn_var);
      ctl_function();
      pop_decl_spec();
      fls_list();
      just_defined_type=FALSE;
      not_labelled = FALSE;	/* first stmt is always reachable */
		  }				   ;


function_def_start :	function_header OPEN_CURL
                        {
/*IMP ??? ??-?? */
                        if (code_standard[CSTAN_LAYOUT])
                           indent_start_func($2.this_token);
#ifdef	HAS_METRICS
/*IMP ??? ??-?? */
                        if (do_metfile)
			   met_startfunc();
#endif
                        /*
			 * This stops the first statement
			 * being dead code!
			 */
			last_was_jump = FALSE;
                        }                         ;

function_definition :	function_def_start cmpd_body CLOSE_CURL
			{
/*STD2124*/
                        leave_func(cur_fn_var);
                        fin_labels();
#ifdef GENERATE_CODE
/*IMP ??? ??-?? */
                        if ((cur_fn_var != NULL) &&
			    generating_code)
	                   {
	                   fls_func_related_tables(TRUE,
		                 cur_scope->maxoffset, /*+cur fn data size */
		                 idx_ref(cur_fn_var));
	                   code_is_init = TRUE;
	                   }
#endif
                        scope_exit(TRUE);
                        ctl_exit_fn();
/*IMP ??? ??-?? */
                        if (code_standard[CSTAN_LAYOUT])
                           indent_end_func($3.this_token);
                        this_is_jump = FALSE;
                        last_was_jump = FALSE;
#ifdef	HAS_METRICS
/*IMP ??? ??-?? */
                        if (do_metfile)
			   met_endfunc();
#endif
			}				;


/*STD1337b*/
local_data_declaration : decl_specifier SEMICOLON		 
			 {
                         current_tok_p = $2.this_token;	
/*IMP ??? ??-?? */
			 if (cc_extensions[CPP_Extension])
			    cpp_struct(FALSE, cur_decl_spec,
			   		$1.u_ptr_c_type.ptr_c_type);
                         pop_decl_spec();
/*IMP ??? ??-?? */
                         if (tag_pending)
                            {				
/*STD1646*/
	                    if (decl_is_empty)	/* perform declaration of tag */
	                       decl_pending_tag();
	                    tag_pending = FALSE;
                            }
                         else if (decl_is_empty)	
/*STD1342*/
	                    LANG_ERROR(E_EMPT_DECL);
                         cur_decl_spec = (C_TYPE_PTR)NULL;
	    		 just_defined_type=FALSE;
                         decl_is_empty = TRUE;
                         tdef_valid = TRUE;
			 }					  |

/*STD1337b*/
			 decl_specifier list_init_dcltr SEMICOLON
			 {
/*IMP ??? ??-?? */
			 if (cc_extensions[CPP_Extension] &&
                             (!tag_pending))
                            cpp_tag_usage(cur_decl_spec);
                         pop_decl_spec();
                         current_tok_p = $2.this_token;
#ifdef SQL_CHK
/*IMP ??? ??-?? */
                         if (in_sql_decl_section)
	                    sql_chk_decl($2.u_ptr_c_type.ptr_c_vlist);
#endif
                         cur_decl_spec = (C_TYPE_PTR)NULL;
	                 tag_pending = FALSE;
	    		 just_defined_type=FALSE;
                         decl_is_empty = TRUE;
                         tdef_valid = TRUE;
			 }					  |
			 
			 EMBED_SQL_DECL                           ;


/* List of variables */
/*STD1337b*/
parameter_declaration : decl_specifier SEMICOLON	   
			{
      			pop_decl_spec();
      			current_tok_p = $2.this_token;
      			if (decl_is_empty)	
/*STD2138a*/
/*STD1342*/
	 		   LANG_ERROR(E_EMPT_DECL);
      			decl_is_empty = TRUE;
      			tdef_valid = TRUE;
      			$$.u_ptr_c_type.ptr_c_vlist = (VLIST_PTR)NULL;
			}				    |

/*STD1337b*/
			decl_specifier list_dcltr SEMICOLON
			{
/*STD2140a*/
      			pop_decl_spec();
      			current_tok_p = $2.this_token;
      			$$ = $2;
      			decl_is_empty = TRUE;
      			tdef_valid = TRUE;
  
			}				    |

			error SEMICOLON			   
			{
      			cerror(E_SYNT_RECOV_PARAM);
      			ats_errok();
      			$$.u_ptr_c_type.ptr_c_vlist = (VLIST_PTR)NULL;
      			decl_is_empty = TRUE;
      			tdef_valid = TRUE;
			}				    ;

/* Type */
typename_declaration : decl_specifier abs_dcltr
		       {
/*IMP ??? ??-?? */
	   	       if (cc_opts[OPT_LINT].u_bool.bool_val &&
		           just_defined_type)
	      	          LINT_60;
/*STD1798*/
      		       pop_decl_spec();
      		       current_tok_p = $2.this_token;
      		       $$.u_ptr_c_type.ptr_c_type = build_type($2.u_ptr_c_type.ptr_c_type,
                                                  $1.u_ptr_c_type.ptr_c_type);
		       }			;

/* List of fields */
NT_0003 :			    
	  {
	  $$.u_ptr_c_type.ptr_fld_list = (FIELD_PTR)NULL;
	  }			     |

	  NT_0003 struct_declaration
	  {
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_fld_list = append_fields($1.u_ptr_c_type.ptr_fld_list,
      	                                          $2.u_ptr_c_type.ptr_fld_list);
	  }			     |

	  NT_0003 error SEMICOLON   
	  {
/*IMP ??? ??-?? */
          cerror(E_SYNT_RECOV_STRUCT);
          ats_errok();
          tdef_valid = TRUE;
          $$.u_ptr_c_type.ptr_fld_list = $1.u_ptr_c_type.ptr_fld_list;
	  }				;


/* List of fields */
list_struct_declaration : NT_0003
		{
      		if ($$.u_ptr_c_type.ptr_fld_list == NULL)	
/*STD1517*/
	 	   LANG_ERROR(E_STRU_UNIO_FIEL_LIST_EMPT);
      		else
         	   {
	 	   temp_long=su_member_count($$.u_ptr_c_type.ptr_fld_list);
	 	   if (temp_long > MAX_FIELDS_LIMIT)
/*STD0071*/
	 	      LANG_ERROR(E_NUM_FIELDS_EXCEEDS_CSTAN);
	 	   if (temp_long > max_struct_members)
	 	      LANG_ERROR(E_NUM_FIELDS_EXCEEDS_LIMIT);
	 	   }
		}		;

ptr_star : STAR
	   {
	   tdef_valid = FALSE;
	   }	|

	   AND
	   {
	   /* Better error recover by supporting C++ ref
	    * operator in the grammar.
	    */
	   tdef_valid = FALSE;
/*STD0001a*/
	   LANG_ERROR(E_CPP_REF_OPERATOR);
	   }    ;

/* Type */
star_type : ptr_star		    
	    {
            $$.u_ptr_c_type.ptr_c_type = mk_ptr((C_TYPE_PTR)NULL);
	    }			     |

	    ptr_star type_specifier_list
	    {
      $$.u_ptr_c_type.ptr_c_type = build_type($2.u_ptr_c_type.ptr_c_type,
                                              mk_ptr((C_TYPE_PTR)NULL));
	    }			     ;


/* Type */
pointer : star_type          |

          pointer star_type 
          {
         $$.u_ptr_c_type.ptr_c_type = build_type(
                                   $2.u_ptr_c_type.ptr_c_type,
                                   $1.u_ptr_c_type.ptr_c_type);
          }                  ;


/* List Of Var */
/*STD1709*/
parameter_type_list : parameter_list		    |
/*STD1709*/
		      parameter_list COMMA ELLIPSIS
		      {
      $$.u_ptr_c_type.ptr_c_plist = mk_plist($1.u_ptr_c_type.ptr_c_plist,
                                                anon_ellip_var);
		      }				    |

		      ELLIPSIS
		      {
      LANG_ERROR(E_ELLIPSIS_IS_CPP);
      $$.u_ptr_c_type.ptr_c_plist = (PARAM_LIST_PTR)NULL;
		      }				    ;


/* List Of Var */
/*STD1709a*/
parameter_list	: formal_declaration			 
		  {
      $$.u_ptr_c_type.ptr_c_plist = mk_plist((PARAM_LIST_PTR)NULL,
      					     $1.u_ptr_c_type.ptr_c_var);
		  }					  |

/*STD1709a*/
		  parameter_list COMMA formal_declaration
		  {
      $$.u_ptr_c_type.ptr_c_plist = mk_plist($1.u_ptr_c_type.ptr_c_plist,
                                             $3.u_ptr_c_type.ptr_c_var);
		  }					  ;


/* List Of Var */
formals_declaration : parameter_type_list
		{
		chk_void_params($$.u_ptr_c_type.ptr_c_plist);
		}			;

/* Variable */
/*STD1710*/
formal_declaration : decl_specifier p3_dcltr 
		     {
         current_tok_p = $2.this_token;
/*IMP ??? ??-?? */
	 if (just_defined_type)
	    {
	    just_defined_type=FALSE;
/*STD0071*/
	    if (cc_extensions[CPP_Extension])
	       LANG_ERROR(E_CPP_DEF_TYPE_PARAM);
/*IMP ??? ??-?? */
	    if (cc_opts[OPT_LINT].u_bool.bool_val)
	       LANG_ERROR(E_DEF_TYPE_PARAM);
	    }
	 if (is_open_proto_scope($2.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
	    scope_exit(FALSE);	/* close this prototype scope */
	 $2.u_ptr_c_type.ptr_c_var->vtype
	 		build_type($2.u_ptr_c_type.ptr_c_var->vtype,
                                    rebuild_type(cur_decl_spec));
         chk_formal($2.u_ptr_c_type.ptr_c_var);
         pop_decl_spec();
         $$ = $2;
         tdef_valid = TRUE;
		     }			      |

/*STD1710*/
		     decl_specifier abs_dcltr
		     {
         current_tok_p = $2.this_token;
/*IMP ??? ??-?? */
	 if (just_defined_type)
	    {
	    just_defined_type=FALSE;
/*STD0071*/
	    if (cc_extensions[CPP_Extension])
	       LANG_ERROR(E_CPP_DEF_TYPE_PARAM);
/*IMP ??? ??-?? */
	    if (cc_opts[OPT_LINT].u_bool.bool_val)
	       LANG_ERROR(E_DEF_TYPE_PARAM);
	    }
         pop_decl_spec();
         $$.u_ptr_c_type.ptr_c_var = new_var((STR_PTR)NULL,
					      nest_scope_depth);
         $$.u_ptr_c_type.ptr_c_var->vtype = $2.u_ptr_c_type.ptr_c_type;
         chk_formal($$.u_ptr_c_type.ptr_c_var);
         tdef_valid = TRUE;
		     }			      ;


/* Type */
opt_decl_specifier :		   
		     {
		     $$.u_ptr_c_type.ptr_c_type = (C_TYPE_PTR)NULL;
		     push_decl_spec((C_TYPE_PTR)NULL);
		     }		    |

		     decl_specifier ;


/* Type */
decl_specifier : NT_0005
		 {
                 mk_empty_set(types_seen);
                 push_decl_spec($1.u_ptr_c_type.ptr_c_type);
		 }	 ;


/* Type */
/*STD1337c*/
NT_0005 : tc_specifier	      
	  {
          mk_empty_set(types_seen);
          if ($1.optok != TOK_AT_LOCATION)
	     combine_std_types(types_seen, $1.optok);
	  }		       |

/*STD1337c*/
	  NT_0005 tc_specifier
	  {
          current_tok_p = $2.this_token;
          if ($2.optok != TOK_AT_LOCATION)
             {
	     combine_std_types(types_seen, $2.optok);
             $$.u_ptr_c_type.ptr_c_type = mk_tc_spec($1.u_ptr_c_type.ptr_c_type,
                                                   $2.u_ptr_c_type.ptr_c_type);
             }
	  }		       ;


/* Type */
/*STD1337c*/
/*STD1438a*/
tc_specifier : std_class      |
	       type_specifier ;


/* Type */
std_class : AUTO    
	    {
/*STD1377*/
            $$.u_ptr_c_type.ptr_c_type = mk_class(CAUTO,
					      (C_TYPE_PTR)NULL);
/*IMP ??? ??-?? */
            if (cc_extensions[JAVA_Extension])
	       LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	    }	     |

	    STATIC  
	    {
/*STD1373*/
            $$.u_ptr_c_type.ptr_c_type = mk_class(CSTATIC,
					      (C_TYPE_PTR)NULL);
	    }	     |

	    EXTERN  
	    {
/*STD1369*/
            $$.u_ptr_c_type.ptr_c_type = mk_class(EXT,
					      (C_TYPE_PTR)NULL);
/*IMP ??? ??-?? */
            if (cc_extensions[JAVA_Extension])
	       LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	    }	     |

	    REGISTER
	    {
/*STD1381*/
            $$.u_ptr_c_type.ptr_c_type = mk_class(REG,
					      (C_TYPE_PTR)NULL);
/*IMP ??? ??-?? */
            if (cc_extensions[JAVA_Extension])
	       LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	    }	     |

	    TYPEDEF 
	    {
/*STD1365*/
            $$.u_ptr_c_type.ptr_c_type = mk_class(CTYPEDEF,
					      (C_TYPE_PTR)NULL);
/*IMP ??? ??-?? */
            if (cc_extensions[JAVA_Extension])
	       LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	    }	     |

	    INLINE  
	    {
/*IMP????*/
            $$.u_ptr_c_type.ptr_c_type = mk_class(CINLINE,
					      (C_TYPE_PTR)NULL);
	    }	     ;


/* Type */
/*STD1708*/
type_specifier_list : std_type			  
		      {
			/*
			 * The only types allowed are const
			 * and volatile
			 */
      current_tok_p = $1.this_token;
      mk_empty_set(types_seen);	
      if ($1.optok != TOK_AT_LOCATION)
/*STD1659*/
/*STD1667*/
         if (($1.optok != TOK_CONST) && ($1.optok != TOK_VOLATILE))
	    LANG_ERROR(E_ONLY_CONS_OR_VOLA_ARE_LEGA_IN);
         else
	    combine_std_types(types_seen, $1.optok);
		      }				   |

/*STD1708*/
		      type_specifier_list std_type
		      {
	 current_tok_p = $2.this_token;	
         if ($2.optok != TOK_AT_LOCATION)
/*STD1659*/
/*STD1667*/
	    if (($2.optok != TOK_CONST) && ($2.optok != TOK_VOLATILE))
	       LANG_ERROR(E_ONLY_CONS_OR_VOLA_ARE_LEGA_IN);
	    else
	       {
	       combine_std_types(types_seen, $2.optok);
	       $$.u_ptr_c_type.ptr_c_type = mk_tc_spec($1.u_ptr_c_type.ptr_c_type,
   	                                            $2.u_ptr_c_type.ptr_c_type);
	       }
		      }				   ;
		      

/* Type */
type_specifier : TYPEDEFNAME	                 
		 {
/*STD1432*/
                 tdef_valid = FALSE;
		 }		                  |

		 TYPEOF OPEN_RND exp CLOSE_RND   
		 {
/*STD0001a*/
                 if (!cc_extensions[GCC_Extension])
	            LANG_ERROR(E_GCC_TYPEOF);
#ifdef API_CHK
	         lit_dcl_expr($3.u_ptr_c_type.ptr_tree);
#endif
		 $$.u_ptr_c_type.ptr_c_type = $3.u_ptr_c_type.ptr_tree->exptype;
		 }                                |

	         TYPEOF OPEN_RND typename_declaration CLOSE_RND
		 {
/*STD0001a*/
                 if (!cc_extensions[GCC_Extension])
	            LANG_ERROR(E_GCC_TYPEOF);
	         $$.u_ptr_c_type.ptr_c_type = $3.u_ptr_c_type.ptr_c_type;
		 }                                |

		 std_type	                  |
		 struct_enum_spec maybe_attribute ;

struct_enum_spec : struct_specifier
		   {
/*STD1424*/
                   tdef_valid = FALSE;
		   }		    |

		   enum_specifier  
		   {
/*STD1428*/
                   tdef_valid = FALSE;
		   }		    ;


/* Type */
std_type : CHAR	   
	   {
/*STD1392*/
           $$.u_ptr_c_type.ptr_c_type = ct_char;
           tdef_valid = FALSE;
	   }	    |

	   FLOAT   
	   {
/*STD1408*/
           $$.u_ptr_c_type.ptr_c_type = ct_float;
           tdef_valid = FALSE;
	   }	    |

	   DOUBLE  
	   {
/*STD1412*/
           $$.u_ptr_c_type.ptr_c_type = ct_double;
           tdef_valid = FALSE;
	   }	    |

	   INT	   
	   {
/*STD1400*/
           $$.u_ptr_c_type.ptr_c_type = ct_int;
           tdef_valid = FALSE;
	   }	    |

	   SHORT   
	   {
/*STD1396*/
           $$.u_ptr_c_type.ptr_c_type = ct_short;
           tdef_valid = FALSE;
	   }	    |

	   LONG	   
	   {
/*STD1404*/
           $$.u_ptr_c_type.ptr_c_type = ct_long;
           tdef_valid = FALSE;
	   }	    |

	   UNSIGNED
	   {
/*STD1420*/
           $$.u_ptr_c_type.ptr_c_type = ct_uint;
           tdef_valid = FALSE;
/*IMP ??? ??-?? */
           if (cc_extensions[JAVA_Extension])
	      LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	   }	    |

	   SIGNED  
	   {
           KandR_Warn($$.this_token->tok.name, KR_SIGNED);
/*STD1416*/
           $$.u_ptr_c_type.ptr_c_type = ct_sint;
           tdef_valid = FALSE;
/*IMP ??? ??-?? */
           if (cc_extensions[JAVA_Extension])
	      LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	   }	    |

	   VOID	   
	   {
/*STD1388*/
           $$.u_ptr_c_type.ptr_c_type = ct_void;
           tdef_valid = FALSE;
	   }	    |

	   PASCAL  
	   {
           $$.u_ptr_c_type.ptr_c_type = mk_class(CPASCAL,
					       (C_TYPE_PTR)NULL);
	   }	    |

	   FORTRAN 
	   {
           $$.u_ptr_c_type.ptr_c_type = mk_class(CFORTRAN,
					       (C_TYPE_PTR)NULL);
	   }	    |

	   type_qual ;


type_qual : CONST   
	    {
            KandR_Warn($$.this_token->tok.name, KR_CONST);
/*STD1659*/
            $$.u_ptr_c_type.ptr_c_type = add_qualifier(CCONSTANT, (C_TYPE_PTR)NULL);
/*IMP ??? ??-?? */
            if (cc_extensions[JAVA_Extension] &&
               /*
                * If there is a parent macro assume it is used
		* to select between const & final.
                */
               ($1.this_token->tok.parent_macro == No_Parent_Macro))
	       LANG_ERROR(E_CONST_IS_FINAL);
	    }	    |

	    VOLATILE
	    {
            KandR_Warn($$.this_token->tok.name, KR_VOLATILE);
/*STD1667*/
            $$.u_ptr_c_type.ptr_c_type = add_qualifier(CVOLATILE, (C_TYPE_PTR)NULL);
	    }	    |

            AT_ADDR IDENTIFIER
	    {
	    $$.u_ptr_c_type.ptr_c_type = add_qualifier(CEXTENSION, (C_TYPE_PTR)NULL);
	    LANG_ERROR(E_AT_IDENTIFIER);
	    }       ;


struct_or_union : STRUCT
	{
/*STD1509*/
        tdef_valid = FALSE;
	}			|

	UNION		
	{
/*STD1513*/
        tdef_valid = FALSE;
/*IMP ??? ??-?? */
        if (cc_extensions[JAVA_Extension])
           LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	}			;


/* Var */
/*STD1635a*/
struct_tag : struct_or_union IDENTIFIER
	     {
/*STD1505*/
      if ($1.optok == TOK_STRUCT)
	 $$.u_ptr_c_type.ptr_c_var = tagged_type($2.u_ptr_c_type.ptr_ident,
                                                                      CSTRUCT);
      else
	 $$.u_ptr_c_type.ptr_c_var = tagged_type($2.u_ptr_c_type.ptr_ident,
                                                                      CUNION);
	     }		       ;


/* Var */
/*STD1635a*/
struct_def : struct_tag OPEN_CURL
	     {
      tdef_valid = TRUE;
      decl_is_empty = FALSE;	
/*STD1643*/
      if ($$.u_ptr_c_type.ptr_c_var->v_scope_level != nest_scope_depth)	
/*STD0319*/
/*STD0239*/
	 $$.u_ptr_c_type.ptr_c_var = decl_tag($$.u_ptr_c_type.ptr_c_var->cvname,
                                        $$.u_ptr_c_type.ptr_c_var->vtype->base,
					struct_nesting);
/*STD0081*/
      if (struct_nesting == MAX_SU_NEST)
         LANG_ERROR(E_STRUCT_NEST_CSTAN);
      if (struct_nesting == max_nest_struct)
         LANG_ERROR(E_STRUCT_NEST_LIMIT);
      struct_nesting++;
	     }			  ;


/*STD1654a*/
/*STD1654b*/
struct_curl : struct_or_union OPEN_CURL
	{
/*STD0081*/
        if (struct_nesting == MAX_SU_NEST)
           LANG_ERROR(E_STRUCT_NEST_CSTAN);
        if (struct_nesting == max_nest_struct)
           LANG_ERROR(E_STRUCT_NEST_LIMIT);
	struct_nesting++;
	tdef_valid = TRUE;
	}				;


/* Type */
/*STD1639*/
struct_specifier : struct_tag					 
		   {
         $$.u_ptr_c_type.ptr_c_type = $$.u_ptr_c_type.ptr_c_var->vtype;
		   }						  |

/*STD1654a*/
/*STD1654b*/
		   struct_curl list_struct_declaration CLOSE_CURL
		   {
      just_defined_type=TRUE;
      struct_nesting--;
      current_tok_p = $2.this_token;	
/*STD1501*/
/*STD1564*/
/*STD1568a*/
/*STD1654c*/
      if ($1.optok == TOK_STRUCT)
	 $$.u_ptr_c_type.ptr_c_type = mk_new_su((STR_PTR)NULL, CSTRUCT,
                                                  $2.u_ptr_c_type.ptr_fld_list,
						  struct_nesting);
      else
	 $$.u_ptr_c_type.ptr_c_type = mk_new_su((STR_PTR)NULL, CUNION,
                                                  $2.u_ptr_c_type.ptr_fld_list,
						  struct_nesting);
		   }						  |

/*STD1635a*/
		   struct_def list_struct_declaration CLOSE_CURL 
		   {
      just_defined_type=TRUE;
      struct_nesting--;
      current_tok_p = $2.this_token;
/*STD1568a*/
      $$.u_ptr_c_type.ptr_c_type = fin_su_tagged_decl($1.u_ptr_c_type.ptr_c_var,
      		                                  $2.u_ptr_c_type.ptr_fld_list);
      decl_is_empty = FALSE;
		   }						  ;


/* List of fields */
struct_declaration : decl_specifier list_struct_dcltr SEMICOLON
		     {
		     current_tok_p = $2.this_token;
/*IMP ??? ??-?? */
		     if (cc_extensions[CPP_Extension] &&
                         (!tag_pending))
                         cpp_tag_usage(cur_decl_spec);
/*STD1521*/
		     pop_decl_spec();
		     $$ = $2;
		     just_defined_type=FALSE;
	             tag_pending = FALSE;
		     tdef_valid = TRUE;
		     }						;


/*STD1569a*/
bitfield_dcltr : p3_dcltr COLON
		 {
		  if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
		     scope_exit(FALSE);	/* close this prototype scope */
		 }		;

/* Field */
/*STD1569*/
struct_dcltr : p3_dcltr	      
	       {
/*STD1530*/
         current_tok_p = $$.this_token;
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_fld_list = mk_field($$.u_ptr_c_type.ptr_c_var->cvname,
                                    build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                                  rebuild_type(cur_decl_spec)));
	       }	       |

/*STD1569a*/
	       COLON exp      
	       {
/*STD1534*/
	 current_tok_p = $2.this_token;	
/*STD1547*/
	 if (is_integral_const($2.u_ptr_c_type.ptr_tree))
	    {
#ifdef API_CHK
	    lit_dcl_expr($2.u_ptr_c_type.ptr_tree);
	    chk_always_const($2.u_ptr_c_type.ptr_tree);
#endif
/*STD1305b*/
	    temp_long = get_val($2.u_ptr_c_type.ptr_tree, (INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_BITS_INT_CONST);
	    temp_long = 0;
	    }
/*STD1575b*/
	 $$.u_ptr_c_type.ptr_fld_list = mk_field((STR_PTR)NULL,
                                            mk_bits(rebuild_type(cur_decl_spec),
                                                               temp_long, FALSE));
         KandR_BitFld();
	       } 	          |

	       bitfield_dcltr exp
	       {
/*STD1534*/
	 current_tok_p = $2.this_token;	
/*STD1547*/
	 if (is_integral_const($2.u_ptr_c_type.ptr_tree))
	    {
#ifdef API_CHK
	    lit_dcl_expr($2.u_ptr_c_type.ptr_tree);
	    chk_always_const($2.u_ptr_c_type.ptr_tree);
#endif
/*STD1305b*/
	    temp_long = get_val($2.u_ptr_c_type.ptr_tree,
                                       bits_in_type[INT_ALIGN]);
	    }
	 else
	 {
	    LANG_ERROR(E_BITS_INT_CONST);
	    temp_long = bits_in_type[INT_ALIGN];
	 }
      KandR_BitFld();
      if (temp_long == 0)	
/*STD1556*/
      {
	 LANG_ERROR(E_NAME_BIT_FIEL_MAY_NOT_HAVE_ZE);
	 temp_long = bits_in_type[INT_ALIGN];
      }
      $$.u_ptr_c_type.ptr_fld_list = mk_field($1.u_ptr_c_type.ptr_c_var->cvname,
                            mk_bits(build_type($1.u_ptr_c_type.ptr_c_var->vtype,
                                      rebuild_type(cur_decl_spec)),
							temp_long, TRUE));
	       }	       ;


/* List of variables */
NT_0006 : enumerator		
	  {
          $$.u_ptr_c_type.ptr_c_vlist = mk_vlist((VLIST_PTR)NULL,
	  					 $1.u_ptr_c_type.ptr_c_var);
	  }				|

	  NT_0006 enumerator	
	  {
      /* This is an error case aimed at aiding syntax recovery */
      current_tok_p = $2.this_token;	
/*STD1596*/
      LANG_ERROR(E_MISS_COMMA);
      $$.u_ptr_c_type.ptr_c_vlist = mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                     $2.u_ptr_c_type.ptr_c_var);
	  }				|

	  NT_0006 COMMA enumerator
	  {
      $$.u_ptr_c_type.ptr_c_vlist = mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                     $3.u_ptr_c_type.ptr_c_var);
	  }				;


/* List of variables */
enumerator_list : NT_0007	
	  {
/*STD1626*/
          set_num(-1, ct_int, &cur_enum_val);
          if (enum_member_count($$.u_ptr_c_type.ptr_c_vlist) > MAX_NUM_ENUMS)
/*STD0076*/
	     LANG_ERROR(E_NUM_ENUM_CONSTS_EXCEEDS_CSTAN);
          if (enum_member_count($$.u_ptr_c_type.ptr_c_vlist) > max_enum_const)
	     LANG_ERROR(E_NUM_ENUM_CONSTS_EXCEEDS_LIMIT);
	  }			;


NT_0007 : NT_0006		|
	  NT_0006 COMMA	
	  {
/*STD1596*/
	  LANG_ERROR(E_ENUM_TRAIL_COMMA);
	  }			;


an_enum : ENUM
	{
        KandR_Warn($$.this_token->tok.name, KR_ENUM);
        $$.u_ptr_c_type.ptr_c_type = (C_TYPE_PTR)NULL;
        tdef_valid = FALSE;
/*IMP ??? ??-?? */
        if (cc_extensions[JAVA_Extension])
	   LANG_ERROR(E_NOT_KEYWORD_IN_JAVA);
	}	;


/*STD1635b*/
enum_tag : an_enum IDENTIFIER
	{
/*STD1592*/
      $$.u_ptr_c_type.ptr_c_var = tagged_type($2.u_ptr_c_type.ptr_ident, CENUM);
	}			;


/*STD1635b*/
enum_def : enum_tag OPEN_CURL
	{
      decl_is_empty = FALSE;	
/*STD2453*/
      if ($$.u_ptr_c_type.ptr_c_var->v_scope_level != nest_scope_depth)
	 $$.u_ptr_c_type.ptr_c_var = decl_tag($$.u_ptr_c_type.ptr_c_var->cvname,
                                              CENUM,
					      struct_nesting);
	}			;

	
/* Type */
enum_specifier : enum_tag
		{
      $$.u_ptr_c_type.ptr_c_type = $$.u_ptr_c_type.ptr_c_var->vtype;
		}		|

/*STD1654a*/
/*STD1654b*/
		 an_enum OPEN_CURL enumerator_list CLOSE_CURL
		 {
/*STD1584*/
      		 mk_enum(&($$.u_ptr_c_type.ptr_c_type), $3.u_ptr_c_type.ptr_c_vlist);
      		 just_defined_type=TRUE;
      		 decl_is_empty = FALSE;
		 }						|

/*STD1635b*/
		 enum_def enumerator_list CLOSE_CURL           
		 {
/*STD1584*/
	 	 current_tok_p = $3.this_token;
	 	 mk_enum(&($$.u_ptr_c_type.ptr_c_var->vtype),
                                                   $2.u_ptr_c_type.ptr_c_vlist);
#ifdef GENERATE_CODE
	 	 out_var_sym_tab($$.u_ptr_c_type.ptr_c_var);
#endif
	 	 $$.u_ptr_c_type.ptr_c_type = $$.u_ptr_c_type.ptr_c_var->vtype;
         	 just_defined_type=TRUE;
         	 decl_is_empty = FALSE;
		 }						;


enum_set_val : IDENTIFIER ASSIGN
	       {
	       tdef_valid = TRUE;	/* to allow casts in ensuing exp */
	       }		 ;


/* Variable */
enumerator : IDENTIFIER		  
	     {
/*STD1604*/
             current_tok_p = $1.this_token;	
/*STD1616*/
             if (signed_compare(&cur_enum_val,
				&int_info->val[IS_SIGNED].max_val) == COMP_EQ)
	        LANG_ERROR(E_ENUM_CONS_TOO_LARG);
             else
                {
/*STD1631*/
                if (signed_compare(&cur_enum_val,
			   &int_info->val[IS_SIGNED].max_port_val) != COMP_LT)
	           LANG_ERROR(E_ENUM_VALU_EXCEED_MIN_VAL);
                inc_number(&cur_enum_val, IS_SIGNED);	
                }
/*STD0243*/
             $$.u_ptr_c_type.ptr_c_var = mk_efield($1.u_ptr_c_type.ptr_ident,
                                                   &cur_enum_val);
	     }			   |

	     enum_set_val exp
	     {
/*STD1608*/
	 current_tok_p = $2.this_token;	
/*STD1612*/
	 if (is_integral_const($2.u_ptr_c_type.ptr_tree))
/*STD1622*/
/*STD1305b*/
	    {
#ifdef API_CHK
	    lit_dcl_expr($2.u_ptr_c_type.ptr_tree);
	    chk_always_const($2.u_ptr_c_type.ptr_tree);
#endif
	    get_folded_num(&cur_enum_val, $2.u_ptr_c_type.ptr_tree);
/*IMP ??? ??-?? */
	    if ((cc_opts[OPT_LINT].u_bool.bool_val) &&
		$2.u_ptr_c_type.ptr_tree->is_suffixed_lit)
	       LINT_ERROR(E_ENUM_SUFF_CONST);
	    }
	 else
	    LANG_ERROR(E_ENUM_INT_CONST);
/*STD0243*/
      $$.u_ptr_c_type.ptr_c_var = mk_efield($1.u_ptr_c_type.ptr_ident,
                                                  &cur_enum_val);
	     }			   ;


/* List Of Var */
identifier_list : IDENTIFIER			  
		  {
                  $$.u_ptr_c_type.ptr_c_plist = mk_plist((PARAM_LIST_PTR)NULL,
                                             new_var($1.u_ptr_c_type.ptr_ident,
                                                    nest_scope_depth));
		  }				   |

		  identifier_list COMMA IDENTIFIER
		  {
/*STD1711*/
             $$.u_ptr_c_type.ptr_c_plist = mk_plist($1.u_ptr_c_type.ptr_c_plist,
                                      new_var($3.u_ptr_c_type.ptr_ident,
                                               nest_scope_depth));
		  }				   ;

/* Variable */
/*STD1362*/
p1_dcltr : IDENTIFIER		   
	   {
           $$.u_ptr_c_type.ptr_c_var = new_var($1.u_ptr_c_type.ptr_ident,
                                               nest_scope_depth);
           decl_is_empty = FALSE;
           if (code_standard[CSTAN_LAYOUT])
	      indent_ident_decl(nest_scope_depth);
	   }			    ;


/* Variable */
p2_fndcl : p2_dcltr OPEN_RND
	   {
           current_tok_p = $1.this_token;
/*IMP ??? ??-?? */
	   if (cc_extensions[CPP_Extension] &&
	       just_defined_type)
	      {
	      just_defined_type=FALSE;
	      LANG_ERROR(E_CPP_DEF_TYPE_RET);
	      }
/*STD1766*/
           tdef_valid = TRUE;
           nested_params++;		
/*STD0170*/
           scope_entry();	/* open prototype scope */
	   }		     ;

p2_fn_dcltr : p2_fndcl CLOSE_RND		     
	   {
/*STD1699*/
      current_tok_p = $2.this_token;
/*IMP ??? ??-?? */
      if (cc_extensions[CPP_Extension])
	 LANG_ERROR(E_OBSOL_EMPTY_PAREN);
      if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
         scope_exit(FALSE);	/* close this prototype scope */
      $$.u_ptr_c_type.ptr_c_var->vtype
                                 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                            mk_func((C_TYPE_PTR)NULL,
					            OLD_FUNC_DECL,
						    (PARAM_LIST_PTR)NULL));
      tdef_valid = TRUE;
      nested_params--;
	   }					      |

	   OPEN_RND p3_dcltr CLOSE_RND               
	   {
/*STD1683*/
/*STD1719*/
	   $$ = $2;
	   }			                      |

	   p2_fndcl identifier_list CLOSE_RND	     
	   {
/*STD1699*/
	 current_tok_p = $2.this_token;
/*IMP ??? ??-?? */
         if (cc_extensions[CPP_Extension])
	    LANG_ERROR(E_OBSOL_OLD_ARGS);
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_c_var->vtype
				 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                             mk_func((C_TYPE_PTR)NULL,
					     	     OLD_FUNC_DECL,
                                               	     $2.u_ptr_c_type.ptr_c_plist));
         tdef_valid = TRUE;
         nested_params--;
	   }					      |

	   p2_fndcl formals_declaration CLOSE_RND    
	   {
/*STD1695*/
	 current_tok_p = $2.this_token;
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_c_var->vtype
				build_type($$.u_ptr_c_type.ptr_c_var->vtype,
/*STD2142*/
                                              mk_func((C_TYPE_PTR)NULL,
					      	      PROTOTYPE_FUNC,
                                               	      $2.u_ptr_c_type.ptr_c_plist));
         tdef_valid = TRUE;
         nested_params--;
	   }					      ;

/* Variable */
p2_dcltr : p1_dcltr				      |
	   p2_fn_dcltr				      |

	   p2_dcltr OPEN_SQUARE CLOSE_SQUARE	     
	   {
/*STD1687*/
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_c_var->vtype
				 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                          mk_array((C_TYPE_PTR)NULL,
					  	   (TYPE_SIZE_TYPE)0));
	   }					      |

/*STD1305a*/
	   p2_dcltr OPEN_SQUARE cond_exp CLOSE_SQUARE
	   {
/*STD1687*/
	 current_tok_p = $3.this_token;	
/*STD1724*/
	 if (is_integral_const($3.u_ptr_c_type.ptr_tree))
/*STD1305b*/
	    {
#ifdef API_CHK
	    lit_dcl_expr($3.u_ptr_c_type.ptr_tree);
	    chk_always_const($3.u_ptr_c_type.ptr_tree);
#endif
	    temp_long = get_val($3.u_ptr_c_type.ptr_tree,
						(INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long = 0;
	    }
         if (temp_long <= 0)	
/*STD1736*/
            {
	    LANG_ERROR(E_ILLE_ARRA_SIZE);
	    temp_long = 1;
            }
         $$.u_ptr_c_type.ptr_c_var->vtype
				 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                                  mk_array((C_TYPE_PTR)NULL,
						  	    temp_long));
	   }		    ;


/* Variable */
p3_dcltr : p2_dcltr	    maybe_asm maybe_attribute |

	   pointer p2_dcltr maybe_asm maybe_attribute
	   {
/*STD1679*/
         $2.u_ptr_c_type.ptr_c_var->vtype
				build_type($2.u_ptr_c_type.ptr_c_var->vtype,
                                                 $1.u_ptr_c_type.ptr_c_type);
         $$ = $2;
	   }		    ;

p3_fn_dcltr : p2_dcltr         |

	      pointer p2_dcltr
		{
      $2.u_ptr_c_type.ptr_c_var->vtype
				 build_type($2.u_ptr_c_type.ptr_c_var->vtype,
                                                 $1.u_ptr_c_type.ptr_c_type);
      $$ = $2;
		}			;

dcltr : p3_dcltr
	{
      if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
         {
	 scope_exit(FALSE);	/* close prototype scope */
	 /* and transform fn params
          * add in the current decl specifier
	  */
	 strip_idents_from_formals($$.u_ptr_c_type.ptr_c_var->vtype);
         }
      
/*STD0251*/
      no_init_declare(&($1.u_ptr_c_type.ptr_c_var));
#ifdef GENERATE_CODE
      out_var_sym_tab($1.u_ptr_c_type.ptr_c_var);
#endif
	}	 ;


i_dcltr : p3_dcltr ASSIGN
	  {
/*STD1338*/
      tdef_valid = TRUE;	/* allow casts in ensuing initializer */
      if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
         {
	 scope_exit(FALSE);	/* close prototype scope */
	 /*
	  * and transform fn params
	  */
	 strip_idents_from_formals($$.u_ptr_c_type.ptr_c_var->vtype);
         }
      current_tok_p = $1.this_token;	
/*STD0251*/
      init_declare(&($$.u_ptr_c_type.ptr_c_var));
      cur_scope->has_init = TRUE;	
/*STD1948*/
      start_initializer($$.u_ptr_c_type.ptr_c_var);
#ifdef API_CHK
      api_init_check($$.u_ptr_c_type.ptr_c_var);
#endif
/*IMP ??? ??-?? */
      if (code_standard[CSTAN_FLOW] && !has_qualifier(CSTATIC, cur_decl_spec))
         LINT_17(E_UNRE_INITIALIZER);
	  }		  ;

at_location : AT_ADDR cond_exp
	      {
	      current_tok_p = $1.this_token;	
	      LANG_ERROR(E_AT_LOCATION);
	      }		       ;

/* Variable */
init_dcltr : init_1_dcltr             |
	     init_1_dcltr at_location ;

init_1_dcltr : dcltr             |

	     i_dcltr init_exp 
	     {
/*STD1853*/
      	     finish_initializer($$.u_ptr_c_type.ptr_c_var);
/*IMP ??? ??-?? */
	     if (cc_opts[OPT_LINT].u_bool.bool_val)
      	        vv_init_expr($1.u_ptr_c_type.ptr_c_var,
			     $2.u_ptr_c_type.ptr_tree);
#ifdef GENERATE_CODE
      	     out_var_sym_tab($$.u_ptr_c_type.ptr_c_var);
#endif
	     }		       ;


NT_0009 : init_exp		 |

	  NT_0009 COMMA init_exp
	  {
/*STD1861*/
	  }			;


start_init : OPEN_CURL
	     {
	     open_curly();
	     }		;


end_init : NT_0010 CLOSE_CURL
	   {
	   cl_curly(TRUE);
	   }			;


init_exp : exp			
	   {
           chk_lvalue_conversions($$.u_ptr_c_type.ptr_tree, TRUE);
           process_init($$.u_ptr_c_type.ptr_tree, TRUE);
	   }				|

	   start_init end_init	
	   {
	   $$=$2;
	   }				;

NT_0010 :  NT_0009		|

	   NT_0009 COMMA
	   {
/*IMP ??? ??-?? */
	   if (cc_opts[OPT_LINT].u_bool.bool_val)
	      LINT_15;
	   }			;


/* Type */
p1_abs_dcltr : OPEN_RND p3_abs_dcltr CLOSE_RND
	       {
/*STD1810*/
	       $$ = $2;
	       }			       ;


/* Type */
p2_abs_fndcl : p2_abs_dcltr OPEN_RND
	       {
               current_tok_p = $1.this_token;
/*IMP ??? ??-?? */
	       if (cc_extensions[CPP_Extension] &&
	           just_defined_type)
	          {
		  just_defined_type=FALSE;
		  LANG_ERROR(E_CPP_DEF_TYPE_RET);
		  }
/*STD1766*/
               tdef_valid = TRUE;
               nested_params++;		
/*STD0170*/
               scope_entry();	/* open prototype scope */
	       }			;


e_open_rnd : OPEN_RND
	     {
             tdef_valid = TRUE;
             nested_params++;		
/*STD0170*/
             scope_entry();	/* open prototype scope */
	     }		;


/* Type */
p2_abs_dcltr : p1_abs_dcltr				      |

	       p2_abs_fndcl CLOSE_RND			     
	       {
      current_tok_p = $2.this_token;
/*IMP ??? ??-?? */
      if (cc_extensions[CPP_Extension])
         LANG_ERROR(E_OBSOL_EMPTY_PAREN);
/*STD1830*/
/*STD0183*/
      scope_exit(TRUE);		/* close prototype scope */
      $$.u_ptr_c_type.ptr_c_type = build_type($1.u_ptr_c_type.ptr_c_type,
                                              mk_func((C_TYPE_PTR)NULL,
					      	      OLD_FUNC_DECL,
						      (PARAM_LIST_PTR)NULL));
      tdef_valid = TRUE;
      nested_params--;
	       }					      |

	       p2_abs_fndcl parameter_type_list CLOSE_RND    
	       {
/*STD1830*/
/*STD0183*/
      scope_exit(TRUE);		/* close prototype scope */
      current_tok_p = $1.this_token;	/* we do not want a
					 * variable list here! */
      $$.u_ptr_c_type.ptr_c_type = mk_func((C_TYPE_PTR)NULL, PROTOTYPE_FUNC,
                                            $2.u_ptr_c_type.ptr_c_plist);
      strip_idents_from_formals($$.u_ptr_c_type.ptr_c_type);
      $$.u_ptr_c_type.ptr_c_type = build_type($1.u_ptr_c_type.ptr_c_type,
                                                 $$.u_ptr_c_type.ptr_c_type);
      tdef_valid = TRUE;
      nested_params--;
	       }					      |

	       e_open_rnd parameter_type_list CLOSE_RND    
	       {
/*STD1830*/
/*STD0183*/
      scope_exit(TRUE);		/* close prototype scope */
      current_tok_p = $1.this_token;	/* we do not want a
					 * variable list here! */
      $$.u_ptr_c_type.ptr_c_type = mk_func((C_TYPE_PTR)NULL, PROTOTYPE_FUNC,
                                               $2.u_ptr_c_type.ptr_c_plist);
      strip_idents_from_formals($$.u_ptr_c_type.ptr_c_type);
      tdef_valid = TRUE;
      nested_params--;
	       }					      |

	       e_open_rnd CLOSE_RND			     
	       {
      current_tok_p = $2.this_token;
/*IMP ??? ??-?? */
      if (cc_extensions[CPP_Extension])
         LANG_ERROR(E_OBSOL_EMPTY_PAREN);
/*STD1830*/
/*STD0183*/
      scope_exit(TRUE);		/* close prototype scope */
      $$.u_ptr_c_type.ptr_c_type = mk_func((C_TYPE_PTR)NULL, OLD_FUNC_DECL,
      						(PARAM_LIST_PTR)NULL);
      tdef_valid = TRUE;
      nested_params--;
	       }					      |

	       p2_abs_dcltr OPEN_SQUARE CLOSE_SQUARE	     
	       {
/*STD1814*/
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_c_type = build_type($1.u_ptr_c_type.ptr_c_type,
                                              mk_array((C_TYPE_PTR)NULL,
					      	       (TYPE_SIZE_TYPE)0));
	       }					      |

/*STD1305a*/
	       p2_abs_dcltr OPEN_SQUARE cond_exp CLOSE_SQUARE
	       {
/*STD1814*/
	 current_tok_p = $3.this_token;	
/*STD1724*/
	 if (is_integral_const($3.u_ptr_c_type.ptr_tree))
/*STD1305b*/
	    {
#ifdef API_CHK
	    lit_dcl_expr($3.u_ptr_c_type.ptr_tree);
	    chk_always_const($3.u_ptr_c_type.ptr_tree);
#endif
	    temp_long = get_val($3.u_ptr_c_type.ptr_tree, (INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long = 0;
	    }
         if (temp_long <= 0)	
/*STD1736*/
            {
	    LANG_ERROR(E_ILLE_ARRA_SIZE);
	    temp_long = 1;
            }
         $$.u_ptr_c_type.ptr_c_type = build_type($1.u_ptr_c_type.ptr_c_type,
                                                 mk_array((C_TYPE_PTR)NULL,
						 	  temp_long));
	       }					      |

	       e_abs_dcltr OPEN_SQUARE CLOSE_SQUARE	     
	       {
/*STD1814*/
            $$.u_ptr_c_type.ptr_c_type = mk_array((C_TYPE_PTR)NULL, (TYPE_SIZE_TYPE)0);
	       }					      |

/*STD1305a*/
	       e_abs_dcltr OPEN_SQUARE cond_exp CLOSE_SQUARE 
	       {
/*STD1814*/
	 current_tok_p = $3.this_token;	
/*STD1724*/
	 if (is_integral_const($3.u_ptr_c_type.ptr_tree))
/*STD1305b*/
	    {
#ifdef API_CHK
	    lit_dcl_expr($3.u_ptr_c_type.ptr_tree);
	    chk_always_const($3.u_ptr_c_type.ptr_tree);
#endif
	    temp_long = get_val($3.u_ptr_c_type.ptr_tree,
						(INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long = 0;
	    }
         if (temp_long <= 0)	
/*STD1736*/
            {
	    LANG_ERROR(E_ILLE_ARRA_SIZE);
	    temp_long = 1;
            }
         $$.u_ptr_c_type.ptr_c_type = mk_array((C_TYPE_PTR)NULL,
						      temp_long);
	       }					      ;


/* Type */
p3_abs_dcltr : p2_abs_dcltr	    |

	       pointer p2_abs_dcltr
	       {
/*STD1806*/
      $$.u_ptr_c_type.ptr_c_type = build_type($2.u_ptr_c_type.ptr_c_type,
                                                $1.u_ptr_c_type.ptr_c_type);
	       }		    |
	       pointer e_abs_dcltr 
	       {
/*STD1802*/
      $$.u_ptr_c_type.ptr_c_type = $1.u_ptr_c_type.ptr_c_type ;
	       }		    ;


e_abs_dcltr : ;


/* Type */
abs_dcltr : p3_abs_dcltr
	    {
      $$.u_ptr_c_type.ptr_c_type = build_type($$.u_ptr_c_type.ptr_c_type,
                                                rebuild_type(cur_decl_spec));
	    }		 |

	    e_abs_dcltr	
	    {
      $$.u_ptr_c_type.ptr_c_type = rebuild_type(cur_decl_spec);
	    }		 ;


/* List of variables */
/*STD1337d*/
/*STD1361a*/
list_init_dcltr : init_dcltr			  
		  {
      $$.u_ptr_c_type.ptr_c_vlist = mk_vlist((VLIST_PTR)NULL,
      					     $1.u_ptr_c_type.ptr_c_var);
      tdef_valid = FALSE;
		  }				   |

/*STD1337d*/
/*STD1361a*/
		  list_init_dcltr COMMA init_dcltr
		  {
			/* NOTE: we build var list back to front!!!! */
      $$.u_ptr_c_type.ptr_c_vlist = mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                   $3.u_ptr_c_type.ptr_c_var);
      tdef_valid = FALSE;
		  }				   ;


/* List of fields */
list_struct_dcltr : struct_dcltr                	
		    {
		    tdef_valid = FALSE;
		    }					|

		    list_struct_dcltr COMMA struct_dcltr
		    {
/*STD1526*/
      current_tok_p = $3.this_token;
      $$.u_ptr_c_type.ptr_fld_list = append_fields($1.u_ptr_c_type.ptr_fld_list,
                                                 $3.u_ptr_c_type.ptr_fld_list);
      tdef_valid = FALSE;
		    }					 ;


/* List of variables */
list_dcltr : p3_dcltr		      
	     {
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_c_var->vtype = build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                                  rebuild_type(cur_decl_spec));
	 $$.u_ptr_c_type.ptr_c_vlist = mk_vlist((VLIST_PTR)NULL,
	 					$$.u_ptr_c_type.ptr_c_var);
         tdef_valid = FALSE;
	     }			       |

	     list_dcltr COMMA p3_dcltr
	     {
	 if (is_open_proto_scope($3.u_ptr_c_type.ptr_c_var->vtype))	
/*STD0183*/
	    scope_exit(FALSE);	/* close this prototype scope */
	 $3.u_ptr_c_type.ptr_c_var->vtype = build_type($3.u_ptr_c_type.ptr_c_var->vtype,
                                              rebuild_type(cur_decl_spec));
	 $$.u_ptr_c_type.ptr_c_vlist = mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                    $3.u_ptr_c_type.ptr_c_var);
         tdef_valid = FALSE;
	     }			       ;


cmpd_start : OPEN_CURL
	     {
/*STD0150*/
             scope_entry();		/* open block scope */
             entercompound(CMPD_BLOCK, (TPTR_TYPE)NULL);
/*IMP ??? ??-?? */
             if (code_standard[CSTAN_LAYOUT])
	        start_cmpd_blk($1.this_token);
	     }		;


cmpd_body :		        
	  {
	  had_statement = FALSE;
	  }		         |

	  cmpd_body decl_or_stmt
	  {
/*STD1940*/
/*STD1936*/
          fls_list();
          free_nodes();		/* free up tree storage */
	  }		         ;


compound_stmt : cmpd_start cmpd_body CLOSE_CURL
		{
/*STD1944*/
/*STD0162*/
                scope_exit(TRUE);
                leavecompound((TPTR_TYPE)NULL);
		/*
		 * Before reducing to cmpd_body we reduce through
		 * stmt This will assign this_is_jump to
		 * last_was_jump and set this_is_jump to FALSE.
		 * compound_stmt will eventually reduce through
		 * stmt so we need to reset values so that the
		 * actions on this reduction don't give spurious
		 * warnings.
		 */
		this_is_jump=last_was_jump;
		last_was_jump = FALSE;
/*IMP ??? ??-?? */
                if (code_standard[CSTAN_LAYOUT])
                   end_cmpd_blk($3.this_token);
		}			     ;


decl_or_stmt : local_data_declaration
	       {
               current_tok_p = $1.this_token;
               if (had_statement)	
/*STD1932*/
	          LANG_ERROR(E_DECL_APPE_AFTE_STAT);
               set_start_col=TRUE;
	       }		      |

	       stmt		     
	       {
	       /*
	        * Part of this statement may have already been
		* printed, so we trust Current_Tok_P to be
		* somewhere suitable...
	        */
               vv_stmt_num++;
	       had_statement |= ($1.this_token->tok.token !=
					TOK_EMBED_SQL_HERMAPH);
/*IMP ??? ??-?? */
               if (code_standard[CSTAN_FLOW])
                  LINT_17(E_UNRE_CODE);
#if HAS_METRICS
               MET_STMT_1;
#endif
	       last_was_jump = this_is_jump;
               this_is_jump = FALSE;
               not_labelled = TRUE;
/*STD1922a*/
               stmt_end();
	       }		      ;


/*
 * The * rules are dummies to accept the Apollo extended syntax
 * so that the header files compile.
 */
maybe_attribute:            |
                 attributes
	         {
/*STD0001a*/
                 if (!cc_extensions[GCC_Extension])
	            LANG_ERROR(E_GCC_ATTRIBUTE);
                 }          ;

attributes: attribute            |
	    attributes attribute ;

attribute: ATTRIBUTE OPEN_RND OPEN_RND attribute_list CLOSE_RND CLOSE_RND ;

attribute_list: attrib                      |
	        attribute_list COMMA attrib ;
 
attrib:                                                  |
        any_word                                         |
        /*
         * The gcc grammar contains:
         *
         *   any_word OPEN_RND IDENTIFIER CLOSE_RND
         *   any_word OPEN_RND IDENTIFIER COMMA exp CLOSE_RND
         *
         * which is syntactically equivalent to:
         *
         *   anyword OPEN_RRND comma_exp CLOSE_RND
         *
         * We simply use the later (it prevents a shift/reduce
         * conflict from heppening).
         */
        any_word OPEN_RND           CLOSE_RND             |
        any_word OPEN_RND comma_exp CLOSE_RND             ;

/* This still leaves out most reserved keywords,
 * shouldn't we include them? 
 */

any_word: IDENTIFIER   |
	  tc_specifier ;

/*
 * SVR4, GCC and other vendors support the following in various
 * forms.  We parse the general case and don't worry about
 * vendor dialects.
 *
 * In SVR4 exp must be a string literal.
 */
asm_decl : ASM OPEN_RND exp CLOSE_RND SEMICOLON
	   {
/*STD0001a*/
           if (!cc_extensions[ASM_Extension])
	      LANG_ERROR(E_EMBED_ASM);
	   }                                    ;

maybe_asm :                                |
            ASM OPEN_RND LITERAL CLOSE_RND
	    {
/*IMP ??? ??-?? */
            if (!cc_extensions[ASM_Extension])
	       LANG_ERROR(E_EMBED_ASM);
	    }                              ;

asm_stmt : asm_gnu_stmt
	   {
/*IMP ??? ??-?? */
           if (!cc_extensions[ASM_Extension])
	      LANG_ERROR(E_EMBED_ASM);
	   }            ;

/*
 * asm ( string_list ) ; is also supported by SVR4
 */
asm_gnu_stmt : asm_hdr exp CLOSE_RND SEMICOLON                                   |
               asm_hdr exp COLON asm_operands CLOSE_RND SEMICOLON                |
               asm_hdr exp COLON asm_operands COLON asm_operands CLOSE_RND
                                                                       SEMICOLON |
               asm_hdr exp COLON asm_operands COLON asm_operands COLON
                                                asm_clobbers CLOSE_RND SEMICOLON ;

asm_hdr : ASM           OPEN_RND |
          ASM type_qual OPEN_RND ;

asm_operands :                      |
               nonnull_asm_operands ;

nonnull_asm_operands : asm_operand                            |
                       nonnull_asm_operands COMMA asm_operand ;

/*
 * GCC says that LITERAL must be a string.
 */
/*STD0001a*/
asm_operand : LITERAL OPEN_RND exp CLOSE_RND ;

/*
 * GCC says that LITERAL must be a string.
 */
/*STD0001a*/
asm_clobbers : LITERAL                    |
               asm_clobbers COMMA LITERAL ;

stmt : bal_stmt		   |
       unbal_stmt	   ;


label_list  : label	
	      {
	      not_labelled=FALSE;
	      }		        |

	      label_list label	;


/*STD1921c*/
basic_stmt : e_stmt		       |
/*STD1921b*/
	     compound_stmt	       |
/*STD1921e*/
	     do_stmt		       |

/*STD1921f*/
	     BREAK SEMICOLON	      
	     {
/*STD2047*/
      current_tok_p = $1.this_token;
      ptr_to_cmpd_stmt_info = get_cmpd(TOK_BREAK);
      ctl_break();
      this_is_jump = TRUE;	
#ifdef	GENERATE_CODE
/*STD2059*/
      if (ptr_to_cmpd_stmt_info != NULL)	
/*IMP ??? ??-?? */
	 if (ptr_to_cmpd_stmt_info->cmpd_is == CMPD_SWITCH)
	    ujump(&(ptr_to_cmpd_stmt_info->u_default_lab.u_default_lab.sbreak_lab));
	 else
	    ujump(&(ptr_to_cmpd_stmt_info->u_default_lab.u_cont_lab.lbreak_lab));
#endif
	     }			       |

/*STD1921f*/
	     CONTINUE SEMICOLON	      
	     {
/*STD2043*/
             current_tok_p = $1.this_token;
             ptr_to_cmpd_stmt_info = get_cmpd(TOK_CONTINUE);
	     ctl_continue();
             this_is_jump = TRUE;	
#ifdef	GENERATE_CODE
/*STD2077a*/
/*STD2059*/
             if (ptr_to_cmpd_stmt_info != NULL)
	        ujump(&(ptr_to_cmpd_stmt_info->u_default_lab.u_cont_lab.cont_lab));
#endif
	       }			 |

/*STD1921f*/
	     GOTO TYPEDEFNAME SEMICOLON
	     {
             tdef_valid = TRUE;
             current_tok_p = $2.this_token;
	     /*
		restore fact that we are dealing with an identifier
	     */
	     $2.this_token->tok.token = TOK_IDENTIFIER;
	     $2.optok = TOK_IDENTIFIER;
	     $2.u_ptr_c_type.ptr_ident = current_tok_p->tok.name;
	     goto_label($2.u_ptr_c_type.ptr_ident);
/*IMP ??? ??-?? */
             if (code_standard[CSTAN_FLOW])
	        {
/*IMP ??? ??-?? */
		if ($1.this_token->tok.parent_macro == No_Parent_Macro)
	           LINT_ERROR(E_USE_GOTO);
		else
	           LINT_ERROR(E_USE_MACRO_GOTO);
		}
	     }                         |
	     
	     GOTO IDENTIFIER SEMICOLON
	     {
             current_tok_p = $2.this_token;
	     goto_label($2.u_ptr_c_type.ptr_ident);
/*IMP ??? ??-?? */
             if (code_standard[CSTAN_FLOW])
	        {
/*IMP ??? ??-?? */
		if ($1.this_token->tok.parent_macro == No_Parent_Macro)
	           LINT_ERROR(E_USE_GOTO);
		else
	           LINT_ERROR(E_USE_MACRO_GOTO);
		}
	     }			       |

/*STD1921f*/
	     return_stmt	       |
	     null_stmt		       |
	     asm_stmt                 
	     {
#ifdef API_CHK
/*IMP ??? ??-?? */
             if (cc_opts[OPT_LINT].u_bool.bool_val)
                chk_status_codes((TPTR_TYPE)NULL);
#endif
	     }                         |

	     EMBED_SQL_STMT           
	     {
#ifdef SQL_CHK
             ctl_sql_stmt();
#endif
	     }                         |

	     EMBED_SQL_HERMAPH        
	     {
#ifdef SQL_CHK
             ctl_sql_stmt();
#endif
	     }                         ;


bal_stmt : bal_statement		|
/*STD1921a*/
/*STD1931a*/
/*STD1931b*/
	   label_list bal_statement	;


bal_statement : basic_stmt	|
/*STD1921e*/
		bal_while_stmt	|
/*STD1921e*/
		bal_for_stmt	|
/*STD1921d*/
		bal_ifelse_stmt |
/*STD1921d*/
		bal_switch_stmt ;


unbal_stmt : unbal_statement		|
/*STD1921a*/
/*STD1931a*/
/*STD1931b*/
	     label_list unbal_statement ;



/*STD1921e*/
unbal_statement : unbal_while_stmt  |
/*STD1921e*/
		  unbal_for_stmt    |
/*STD1921d*/
		  unbal_if_stmt	    |
/*STD1921d*/
		  unbal_ifelse_stmt |
/*STD1921d*/
		  unbal_switch_stmt ;
		  

if_tok  : IF
	  {
/*IMP ??? ??-?? */
          if (code_standard[CSTAN_LAYOUT])
             push_cmpd_header($1.this_token);
/*IMP ??? ??-?? */
          if (code_standard[CSTAN_FLOW])
             LINT_17(E_UNRE_CODE);
	  }  ;


if_header  : if_tok OPEN_RND list_exp CLOSE_RND
	     {
/*STD1964*/
             current_tok_p = $3.this_token;
             entercompound(CMPD_COND, $3.u_ptr_c_type.ptr_tree);
/*IMP ??? ??-?? */
             if (code_standard[CSTAN_LAYOUT])
                lay_if();
#ifdef API_CHK
/*IMP ??? ??-?? */
             if (cc_opts[OPT_LINT].u_bool.bool_val)
                chk_status_codes($3.u_ptr_c_type.ptr_tree);
#endif
             ctl_if($3.u_ptr_c_type.ptr_tree);
             fls_list();
             stmt_end();
	     }		  ;


if_else	   : if_header bal_stmt ELSE
	     {
/*STD1978a*/
/*STD1968*/
#ifdef	GENERATE_CODE
             gen_else(&(cur_cmpd->u_default_lab.u_cond));
#endif
/*IMP ??? ??-?? */
             if (code_standard[CSTAN_LAYOUT])
                lay_else();
             cmpd_else();
             ctl_else($3.this_token);
             this_is_jump = FALSE;
	     }			     ;


bal_ifelse_stmt : if_else bal_stmt
		  {
		  leavecompound((TPTR_TYPE)NULL);
/*IMP ??? ??-?? */
                  if (code_standard[CSTAN_LAYOUT])
                     lay_endif(FALSE);
		  this_is_jump = ctl_endif();
		  }		   ;


unbal_ifelse_stmt : if_else unbal_stmt
		    {
		    leavecompound((TPTR_TYPE)NULL);
/*IMP ??? ??-?? */
                    if (code_standard[CSTAN_LAYOUT])
                       lay_endif(FALSE);
		    this_is_jump = ctl_endif();
		    }		       ;


unbal_if_stmt : if_header stmt
		{
		leavecompound((TPTR_TYPE)NULL);
                current_tok_p = $1.this_token;
/*IMP ??? ??-?? */
                if (code_standard[CSTAN_LAYOUT])
                   lay_endif(TRUE);
		(VOID)ctl_endif();
		this_is_jump = FALSE; /* condition might not be taken */
		}	       ;


e_stmt : list_exp SEMICOLON
	 {
/*STD1952*/
         current_tok_p = $1.this_token;
/*STD_L0294*/
         chk_lvalue_conversions($1.u_ptr_c_type.ptr_tree, TRUE);
#if HAS_METRICS
         MET_EXPR_1($1.u_ptr_c_type.ptr_tree);
#endif
/*STD1922c*/
         full_expression($1.u_ptr_c_type.ptr_tree, IS_VOID_EXPR, SETJMP_OK);
#ifdef	GENERATE_CODE
/*STD1956*/
         stmt_gen($1.u_ptr_c_type.ptr_tree);
/*STD1922a*/
#endif
#ifdef API_CHK
         lit_stmt_expr($1.u_ptr_c_type.ptr_tree);
#endif
	 ctl_stmt();
/*IMP ??? ??-?? */
         if (cc_opts[OPT_LINT].u_bool.bool_val)
            {
            vv_sideeffects($1.u_ptr_c_type.ptr_tree);
            LINT_33($1.u_ptr_c_type.ptr_tree);
	    }
	 }		    ;


while_tok : WHILE
	    {
/*IMP ??? ??-?? */
            if (code_standard[CSTAN_LAYOUT])
               push_cmpd_header($1.this_token);
/*IMP ??? ??-?? */
            if (code_standard[CSTAN_FLOW])
               LINT_17(E_UNRE_CODE);
	    }     ;


while_header  : while_tok OPEN_RND list_exp CLOSE_RND
		{
/*STD1993*/
                current_tok_p = $3.this_token;
                entercompound(CMPD_LOOP, $3.u_ptr_c_type.ptr_tree);
#ifdef API_CHK
/*IMP ??? ??-?? */
                if (cc_opts[OPT_LINT].u_bool.bool_val)
		   chk_status_codes($3.u_ptr_c_type.ptr_tree);
#endif
	        ctl_while($3.u_ptr_c_type.ptr_tree);
                fls_list();
                stmt_end();
		}		;


bal_while_stmt : while_header bal_stmt
		 {
		 leavecompound((TPTR_TYPE)NULL);
		 ctl_xwhile();
		 this_is_jump = FALSE;
		 }		       ;


unbal_while_stmt : while_header unbal_stmt
		   {
		   leavecompound((TPTR_TYPE)NULL);
		   ctl_xwhile();
		   this_is_jump = FALSE;
		   }			     ;


do_header : DO
	    {
            entercompound(CMPD_LOOP, (TPTR_TYPE)NULL);
	    ctl_do($1.this_token);
            decl_label(&(cur_cmpd->u_default_lab.u_cont_lab.head_lab));
            fls_list();
            stmt_end();
	    }  ;


do_stmt : do_header stmt WHILE OPEN_RND list_exp CLOSE_RND SEMICOLON
	  {
/*STD1997*/
          current_tok_p = $5.this_token;
	  ctl_xdo($5.u_ptr_c_type.ptr_tree);
          leavecompound($5.u_ptr_c_type.ptr_tree);
	  ctl_break_xdo();
	  }					   ;


NT_0014 : SEMICOLON CLOSE_RND	      
	  {
/*STD2027*/
	  $$.u_ptr_c_type.ptr_tree = (TPTR_TYPE)NULL;
	  }			       |

	  SEMICOLON list_exp CLOSE_RND
	  {
	  $$.u_ptr_c_type.ptr_tree = $2.u_ptr_c_type.ptr_tree;
	  }			       ;


for_tok : FOR
	  {
/*IMP ??? ??-?? */
          if (code_standard[CSTAN_LAYOUT])
             push_cmpd_header($1.this_token);
/*IMP ??? ??-?? */
          if (code_standard[CSTAN_FLOW])
             LINT_17(E_UNRE_CODE);
#ifdef API_CHK
/*IMP ??? ??-?? */
          if (cc_opts[OPT_LINT].u_bool.bool_val)
             chk_status_codes((TPTR_TYPE)NULL);
#endif
	  }   ;


for_header     : for_tok OPEN_RND SEMICOLON NT_0014		     
		 {
/*STD2001*/
/*STD2023*/
		 enterfor((TPTR_TYPE)NULL, (TPTR_TYPE)NULL, $4.u_ptr_c_type.ptr_tree);
		 ctl_for((TPTR_TYPE)NULL);
		 fls_list();
		 stmt_end();
		 }						      |

		 for_tok OPEN_RND SEMICOLON list_exp NT_0014	     
		 {
/*STD2001*/
/*STD2023*/
	         current_tok_p = $4.this_token;
	         enterfor((TPTR_TYPE)NULL, $4.u_ptr_c_type.ptr_tree,
						 $5.u_ptr_c_type.ptr_tree);
		 ctl_for($4.u_ptr_c_type.ptr_tree);
                 fls_list();
                 stmt_end();
		 }						      |

		 for_tok OPEN_RND list_exp SEMICOLON NT_0014	     
		 {
/*STD2001*/
                 current_tok_p = $3.this_token;
                 enterfor($3.u_ptr_c_type.ptr_tree, (TPTR_TYPE)NULL,
						 $5.u_ptr_c_type.ptr_tree);
		 ctl_for((TPTR_TYPE)NULL);
                 fls_list();
                 stmt_end();
		 }					 	      |

		 for_tok OPEN_RND list_exp SEMICOLON list_exp NT_0014
		 {
/*STD2001*/
	         current_tok_p = $5.this_token;
	         enterfor($3.u_ptr_c_type.ptr_tree, $5.u_ptr_c_type.ptr_tree,
                                                  $6.u_ptr_c_type.ptr_tree);
	         ctl_for($5.u_ptr_c_type.ptr_tree);
                 fls_list();
                 stmt_end();
		 }						      ;


bal_for_stmt : for_header bal_stmt
	       {
	       leavecompound((TPTR_TYPE)NULL);
	       ctl_xfor();
	       this_is_jump = FALSE;
	       scope_exit(TRUE);
	       }		   ;


unbal_for_stmt :for_header unbal_stmt
	       {
	       leavecompound((TPTR_TYPE)NULL);
	       ctl_xfor();
	       this_is_jump = FALSE;
	       scope_exit(TRUE);
	       }		      ;

switch_tok : SWITCH
	     {
/*IMP ??? ??-?? */
             if (code_standard[CSTAN_LAYOUT])
                push_cmpd_header($1.this_token);
/*IMP ??? ??-?? */
             if (code_standard[CSTAN_FLOW])
               LINT_17(E_UNRE_CODE);
	     }      ;


switch_header	: switch_tok OPEN_RND list_exp CLOSE_RND
		  {
/*STD1972*/
	          current_tok_p = $3.this_token;
	          last_was_jump = TRUE;	/* frig for start of switch body */
	          enterswitch($3.u_ptr_c_type.ptr_tree);
	          ctl_switch($3.u_ptr_c_type.ptr_tree);
#ifdef API_CHK
/*IMP ??? ??-?? */
                  if (cc_opts[OPT_LINT].u_bool.bool_val)
                     chk_status_codes($3.u_ptr_c_type.ptr_tree);
#endif
                  fls_list();
                  stmt_end();
		  }		;


bal_switch_stmt : switch_header bal_stmt
		  {
		  leavecompound((TPTR_TYPE)NULL);
		  this_is_jump=ctl_xswitch();
		  }			 ;


unbal_switch_stmt : switch_header unbal_stmt
		    {
		    leavecompound((TPTR_TYPE)NULL);
		    this_is_jump=ctl_xswitch();
		    }			     ;


return_stmt : RETURN SEMICOLON	
	      {
/*STD2051*/
              current_tok_p = $1.this_token;
              do_return((TPTR_TYPE)NULL, TRUE);
	      ctl_return();
	      }				|

	      RETURN list_exp SEMICOLON
	      {
/*STD2051*/
	      current_tok_p = $2.this_token;
	      do_return($2.u_ptr_c_type.ptr_tree, TRUE);
	      ctl_return();
#ifdef API_CHK
              lit_stmt_expr($2.u_ptr_c_type.ptr_tree);
#endif
	      }			  ;


null_stmt : SEMICOLON
	    {
	    current_tok_p = $$.this_token;
/*IMP ??? ??-?? */
            if (cc_opts[OPT_LINT].u_bool.bool_val)
               LINT_37;
	    /*
	     * Flag a null statement as dead code, but hang onto
	     * the last 'real' statement jump status
	     */
	    last_was_jump = this_is_jump;
	    ctl_stmt();
/*STD1960*/
	    }	      ;


label : TYPEDEFNAME COLON
	{
        tdef_valid = TRUE;
/*STD1923*/
        current_tok_p = $1.this_token;
        /*
	 * Restore fact that we are dealing with an identifier
	 */
	$1.this_token->tok.token = TOK_IDENTIFIER;
	$1.optok = TOK_IDENTIFIER;
	$1.u_ptr_c_type.ptr_ident = current_tok_p->tok.name;
        label_decl($1.u_ptr_c_type.ptr_ident);
	vv_jumped_to();
#if HAS_METRICS
	MET_STMT_2;
#endif
	}		 |

        IDENTIFIER COLON
	{
/*STD1923*/
        current_tok_p = $1.this_token;
        label_decl($1.u_ptr_c_type.ptr_ident);
	vv_jumped_to();
#if HAS_METRICS
	MET_STMT_2;
#endif
	}		 |

	CASE exp COLON	
	{
/*STD1927*/
	current_tok_p = $2.this_token;	
/*STD1980*/
	if (is_integral_const($2.u_ptr_c_type.ptr_tree))
/*STD1305b*/
	   {
#ifdef API_CHK
	   chk_always_const($2.u_ptr_c_type.ptr_tree);
#endif
/*IMP ??? ??-?? */
	   if (cc_opts[OPT_LINT].u_bool.bool_val)
	      LINT_1($2.u_ptr_c_type.ptr_tree);
	   /*
	    * Measure the unfolded expression
	    */
#if HAS_METRICS
	   MET_EXPR_1($2.u_ptr_c_type.ptr_tree);
#endif
	   $$.u_ptr_c_type.ptr_tree = fold_tree($2.u_ptr_c_type.ptr_tree);
	   }
	else
	   {
	   LANG_ERROR(E_CASE_INT_CONST);
	   $$.u_ptr_c_type.ptr_tree = mk_i_const((C_LONG)0, (STR_PTR)NULL);
	   }
        ptr_to_cmpd_stmt_info = get_cmpd(TOK_CASE);	
/*IMP ??? ??-?? */
        if (ptr_to_cmpd_stmt_info != NULL)
	   add_case($2.u_ptr_c_type.ptr_tree, ptr_to_cmpd_stmt_info);
	ctl_case($1.this_token, $2.u_ptr_c_type.ptr_tree);
/*IMP ??? ??-?? */
        if ((!last_was_jump) && code_standard[CSTAN_FLOW])
	   {
	   last_was_jump=TRUE;
	   LINT_ERROR(E_FALLTHROUGH);
	   }
	}		 |

	CASE error	
	{
/*IMP ??? ??-?? */
        cerror(E_SYNT_RECOV_CASE);
        ats_errok();
	}		 |

	DEFAULT COLON	
	{
/*IMP ??? ??-?? */
        if ((!last_was_jump) && code_standard[CSTAN_FLOW])
	   {
	   last_was_jump=TRUE;
	   LINT_ERROR(E_FALLTHROUGH);
	   }
	ptr_to_cmpd_stmt_info = get_cmpd(TOK_DEFAULT);
/*IMP ??? ??-?? */
	if (ptr_to_cmpd_stmt_info != NULL)
	  add_default(ptr_to_cmpd_stmt_info);
	ctl_default($1.this_token);
	}		;


paren_exp : OPEN_RND list_exp CLOSE_RND
	    {
/*STD0746*/
      $$.u_ptr_c_type.ptr_tree = mk_tree($2.u_ptr_c_type.ptr_tree, (TPTR_TYPE)NULL,
                                         TOK_OPEN_RND,
					 $1.this_token->tok.parent_macro);
	    }				;


primary_exp : IDENTIFIER				
	      {
/*STD0746*/
              current_tok_p = $1.this_token;	
	      id_name=$1.u_ptr_c_type.ptr_ident;
/*STD0762*/
              $1.u_ptr_c_type.ptr_c_var = lookup_var(id_name,
					       $1.this_token->tok.parent_macro);
              $$.u_ptr_c_type.ptr_tree = mk_leaf(&($1), TOK_IDENTIFIER);
	      }						|

	      LITERAL				
	      {
/*STD0747*/
/*STD0746*/
      current_tok_p = $1.this_token;
      switch (lit_tag)
      {				
/*STD0766*/
      case LITDECINT:
      case LITHEXINT:
      case LITOCTINT:
      case LITBININT:
      case LITWIDECHAR:
      case LITCHAR:
/*STD0345a*/
/*STD0345c*/
	 $$.u_ptr_c_type.ptr_tree
		str2num($1.u_ptr_c_type.ptr_ident, lit_tag,
				current_tok_p->tok.parent_macro);
/*STD0766*/
	 break;

      case LITFLOATPOINT:
	 $$.u_ptr_c_type.ptr_tree = mk_leaf(&($1), TOK_FLOATVAL);
/*STD0774*/
	 break;

      case LITWIDESTRING:
	 $$.u_ptr_c_type.ptr_tree = mk_leaf(&($1), TOK_WIDESTR);
/*STD0774*/
	 break;

      case LITSTRING:
	 $$.u_ptr_c_type.ptr_tree = mk_leaf(&($1), TOK_STRCONST);
	 break;
      }
		 }						|

		 paren_exp					|

		 OPEN_RND compound_stmt CLOSE_RND              
		 {
	         $$.u_ptr_c_type.ptr_tree = mk_c_size_t(1, (STR_PTR)NULL);
/*STD0001a*/
                 if (!cc_extensions[GCC_Extension])
	            LANG_ERROR(E_GCC_STMT_EXPR);
		 }                                              ;


postfix_exp : primary_exp					   |

	      postfix_exp OPEN_SQUARE list_exp CLOSE_SQUARE       
	      {
              array_bnd_chk($1.u_ptr_c_type.ptr_tree, $3.u_ptr_c_type.ptr_tree);
              current_tok_p = $2.this_token;
              $$.u_ptr_c_type.ptr_tree
		        mk_tree($1.u_ptr_c_type.ptr_tree,
                                $3.u_ptr_c_type.ptr_tree,
				TOK_ARRAY_REF,
		                $2.this_token->tok.parent_macro);
	      }						   |

	      postfix_exp OPEN_RND CLOSE_RND		  
	      {
/*STD0820*/
/*STD0787*/
              current_tok_p = $1.this_token;
              $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
					    (TPTR_TYPE)NULL,
                                            TOK_FNC_CALL,
				            current_tok_p->tok.parent_macro);
	       }					   |

/*STD0804*/
/*STD0820*/
		 postfix_exp OPEN_RND comma_exp CLOSE_RND	   
		 {
/*STD0787*/
      current_tok_p = $3.this_token;
      temp_tree_ptr = tilt_args($3.u_ptr_c_type.ptr_tree);
      current_tok_p = $1.this_token;
      $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         temp_tree_ptr,
					 TOK_FNC_CALL,
				         $2.this_token->tok.parent_macro);
		 }						   |

		 postfix_exp DOT IDENTIFIER			  
		 {
/*STD0795*/
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         (TPTR_TYPE)$3.u_ptr_c_type.ptr_ident,
                                         TOK_DIR_SELECT,
				         $2.this_token->tok.parent_macro);
	/* note type punning of Ptr_Ident with Ptr_Tree */
		 }						     |

		 postfix_exp DEREF IDENTIFIER		  
		 {
/*STD0799*/
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         (TPTR_TYPE)$3.u_ptr_c_type.ptr_ident,
                                         TOK_INDIR_SELECT,
				         $2.this_token->tok.parent_macro);
		 }						     |

	         postfix_exp postfix_op			  
	         {
/*STD0803*/
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
					 (TPTR_TYPE)NULL,
                                         $2.optok,
				         $2.this_token->tok.parent_macro);
	         }						     |

		 postfix_exp DOT LITERAL		  
		 {
      /*
       * S. 9 is tokenised as IDENTIFIER DOT LITERAL
       */
      current_tok_p = $2.this_token;
      $$=$1;
      LANG_ERROR(E_EXT_BIT_SELECT);
		 }						     |

		 postfix_exp     LITERAL		  
		 {
      /*
       * S.9 is tokenised as IDENTIFIER LITERAL, not
       * IDENTIFIER DOT LITERAL
       * where the literal will be a floating point value
       */
      current_tok_p = $2.this_token;
      $$=$1;
/*IMP ??? ??-?? */
      if (lit_tag == LITFLOATPOINT)
         LANG_ERROR(E_EXT_BIT_SELECT);
      else
         LANG_ERROR(E_SYNT_ERRO);
		 }						     ;


postfix_op : PLUSPLUS
	     {
	     $$.optok=TOK_POST_PLUS;
	     }		|

	     MINUSMINUS
	     {
	     $$.optok=TOK_POST_MINUS;
	     }		;

unary_exp : postfix_exp	|

	    SIZEOF OPEN_RND typename_declaration CLOSE_RND
	    {
/*STD0883*/
/*STD0941*/
	    current_tok_p = $3.this_token;
	    $$.u_ptr_c_type.ptr_tree = mk_sizeof($3.u_ptr_c_type.ptr_c_type,
                                                  FALSE,
				                  $3.this_token->tok.parent_macro);
            tdef_valid = TRUE;
	    }						  |

	    SIZEOF unary_exp
	    {
/*STD0879*/
/*STD0936*/
	    current_tok_p = $2.this_token;
	    if ($2.u_ptr_c_type.ptr_tree->op == TOK_IDENTIFIER)
/*STD0124*/
	       if ($2.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->defaulted)
	          {
	          LANG_ERRMSG(E_UNDE_IDEN_ASSU_EXTE_INT,
                                 $2.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->cvname);
	          $2.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->defaulted = FALSE;
	          }
/*IMP ??? ??-?? */
	    if (cc_opts[OPT_LINT].u_bool.bool_val)
	       LINT_7($2.u_ptr_c_type.ptr_tree);
/*STD0945*/
	    $$.u_ptr_c_type.ptr_tree = mk_sizeof($2.u_ptr_c_type.ptr_tree->exptype,
                                              $2.u_ptr_c_type.ptr_tree->is_l_value,
				              $2.this_token->tok.parent_macro);
	     }			|

	     ALIGNOF OPEN_RND typename_declaration CLOSE_RND
	     {
/*STD0001a*/
	     if (cc_extensions[GCC_Extension])
	        $$.u_ptr_c_type.ptr_tree = mk_alignof($3.u_ptr_c_type.ptr_c_type,
                                                     FALSE,
				                     $3.this_token->tok.parent_macro);
	     else
	        LANG_ERROR(E_GCC_ALIGNOF);
	     }						     |

	     ALIGNOF unary_exp	 
	     {
/*STD0001a*/
             if (cc_extensions[GCC_Extension])
	        $$.u_ptr_c_type.ptr_tree = mk_alignof($2.u_ptr_c_type.ptr_tree->exptype,
                                                 $2.u_ptr_c_type.ptr_tree->is_l_value,
				                 $2.this_token->tok.parent_macro);
	     else
	        LANG_ERROR(E_GCC_ALIGNOF);
	     }			  |

	     prefix_op unary_exp
	     {
/*STD0863*/
             current_tok_p = $2.this_token;
             $$.u_ptr_c_type.ptr_tree = mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                                $1.optok,
				                $1.this_token->tok.parent_macro);
	     }			|

	     STAR cast_exp
	     {
/*STD0866*/
/*STD0887*/
             current_tok_p = $2.this_token;
             $$.u_ptr_c_type.ptr_tree = mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	TOK_CONT_OF,
				         	$1.this_token->tok.parent_macro);
	     }			|

	     AND cast_exp
	     {
/*STD0866*/
/*STD0887*/
             current_tok_p = $2.this_token;
             $$.u_ptr_c_type.ptr_tree = mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	TOK_ADDR_OF,
				         	$1.this_token->tok.parent_macro);
	     }			|

	     negate_op cast_exp
	     {
/*STD0866*/
/*STD0887*/
             current_tok_p = $2.this_token;
             $$.u_ptr_c_type.ptr_tree = mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	$1.optok,
				         	$1.this_token->tok.parent_macro);
	     }			|


	     ANDTEST IDENTIFIER
	     {
/*STD0001a*/
             if (!cc_extensions[GCC_Extension])
	        LANG_ERROR(E_GCC_ADDR_LABEL);
             (VOID)lookup_label($2.u_ptr_c_type.ptr_ident, FALSE);
             /*
	      * The NULL pointer constant, a 'safe' value
	      */
	     $$.u_ptr_c_type.ptr_tree = mk_l_const(0,
				                   $1.this_token->tok.parent_macro);
	     }		        ;

prefix_op : PLUSPLUS  
	    {
	    $$.optok=TOK_PRE_PLUS;
	    }	       |

	    MINUSMINUS
	    {
	    $$.optok=TOK_PRE_MINUS;
	    }	       ;


negate_op : PLUS     
	    {
      	    KandR_UnPlus($$.this_token->tok.name);
	    }	      |

	    NEGATE    |
	    NOT	      |
	    BITNEGATE ;


type_cast : OPEN_RND typename_declaration CLOSE_RND
	    {
	    tdef_valid = TRUE;
	    $$ = $2;
	    }					    ;

cast_exp : unary_exp		|

	   type_cast cast_exp
	   {
/*STD0964*/
           current_tok_p = $$.this_token;
           $$.u_ptr_c_type.ptr_tree = mk_cast($2.u_ptr_c_type.ptr_tree,
                                                $$.u_ptr_c_type.ptr_c_type,
				         	$1.this_token->tok.parent_macro);
	   }			;



mult_oper_exp : cast_exp			     |
		
		mult_oper_exp mult_op cast_exp
		{
/*STD0999*/
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree, $2.optok,
				         $2.this_token->tok.parent_macro);
		}				     ;


mult_op : STAR	   
	  {
	  $$.optok = TOK_TIMES;
	  }	    |
	  DIVIDE    |
	  REMAINDER ;


add_oper_exp : mult_oper_exp			 |

	       add_oper_exp add_op mult_oper_exp
	       {
/*STD1018*/
      current_tok_p = $2.this_token;
      $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                        $3.u_ptr_c_type.ptr_tree, $2.optok,
				        $2.this_token->tok.parent_macro);
	       }				 ;


add_op : PLUS
	 {
	 $$.optok = TOK_ADD;
	 }	|
	 
	 NEGATE
	 {
	 $$.optok = TOK_MINUS;
	 }     ;


shift_oper_exp : add_oper_exp			      |

		 shift_oper_exp shift_op add_oper_exp
		 {
/*STD1075*/
                 current_tok_p = $2.this_token;
                 $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree, $2.optok,
				         $2.this_token->tok.parent_macro);
		 }				      ;


shift_op : LEFTSHIFT  |
	   RIGHTSHIFT ;


rel_oper_exp : shift_oper_exp			  |

	       rel_oper_exp rel_op shift_oper_exp
	       {
/*STD1096*/
               current_tok_p = $2.this_token;
               $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         $2.optok,
				         $2.this_token->tok.parent_macro);
	       }				  ;

rel_op : LT  |
	 LE  |
	 GE  |
	 GT  ;


equ_oper_exp : rel_oper_exp			|

	       equ_oper_exp equ_op rel_oper_exp
	       {
/*STD1116*/
               current_tok_p = $2.this_token;
               $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         $2.optok,
				         $2.this_token->tok.parent_macro);
	       }				;


equ_op : EQUAL	  |
	 NOTEQUAL ;


bitand_oper_exp : equ_oper_exp			   |

		  bitand_oper_exp AND equ_oper_exp
		  {
/*STD1140*/
                  current_tok_p = $2.this_token;
                  $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_BIT_AND,
				         $2.this_token->tok.parent_macro);
		  }				   ;


bitxor_oper_exp : bitand_oper_exp		      |

		  bitxor_oper_exp XOR bitand_oper_exp
		  {
/*STD1152*/
                  current_tok_p = $2.this_token;
                  $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_BIT_XOR,
				         $2.this_token->tok.parent_macro);
		  }				      ;


bitor_oper_exp : bitxor_oper_exp		   |

		 bitor_oper_exp OR bitxor_oper_exp
		 {
/*STD1164*/
                 current_tok_p = $2.this_token;
                 $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_BIT_OR,
				         $2.this_token->tok.parent_macro);
		 }				   ;


and_oper_exp : bitor_oper_exp			   |

	       and_oper_exp ANDTEST bitor_oper_exp
	       {
/*STD1176*/
               current_tok_p = $2.this_token;
               $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_LOG_AND,
				         $2.this_token->tok.parent_macro);
	       }				   ;


or_oper_exp : and_oper_exp		      |

	      or_oper_exp ORTEST and_oper_exp
	      {
/*STD1187*/
              current_tok_p = $2.this_token;
              $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_LOG_OR,
				         $2.this_token->tok.parent_macro);
	      }						   ;


cond_exp : or_oper_exp					|

	   or_oper_exp QUESTION list_exp COLON cond_exp
	   {
/*STD1198*/
           current_tok_p = $2.this_token;
           $$.u_ptr_c_type.ptr_tree
			mk_tree($1.u_ptr_c_type.ptr_tree,
				mk_tree($3.u_ptr_c_type.ptr_tree,
                                        $5.u_ptr_c_type.ptr_tree,
                                        TOK_COLON,
				        $4.this_token->tok.parent_macro),
				TOK_QUESTION,
				$2.this_token->tok.parent_macro);
	   }						;


assign_exp : cond_exp		  |

	     /*
	      * Standard C says unary_exp asgn_op assign_exp here
	      * Allowing a cast on the lhs is a common extention
	      * and error recovery is awful unless we support it
	      * in the grammar.
	      */
	     cast_exp asgn_op assign_exp
	     {
             if ($1.u_ptr_c_type.ptr_tree->op == TOK_CAST)
	        {
                current_tok_p = $1.this_token;
	        LANG_ERROR(E_CAST_ON_LHS_ASSIGN);
                while ($1.u_ptr_c_type.ptr_tree->op == TOK_CAST)
                   $1.u_ptr_c_type.ptr_tree=RHS_EXPR($1.u_ptr_c_type.ptr_tree);
		}
/*STD1232*/
             current_tok_p = $2.this_token;
             $$.u_ptr_c_type.ptr_tree = mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         $2.optok,
				         $2.this_token->tok.parent_macro);
	     }			  ;


asgn_op : ASSIGN      |
	  PLUSASSIGN  |
	  MINUSASSIGN |
	  TIMESASSIGN |
	  DIVASSIGN   |
	  REMASSIGN   |
	  RSASSIGN    |
	  LSASSIGN    |
	  ANDASSIGN   |
	  ORASSIGN    |
	  NOTASSIGN   ;


exp : assign_exp ;

comma_exp : exp		
	    {
/*STD1294*/
            if ($$.u_ptr_c_type.ptr_tree->op == TOK_IDENTIFIER)	
/*STD0124*/
	       if ($$.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->defaulted)
	          {
	          LANG_ERRMSG(E_UNDE_IDEN_ASSU_EXTE_INT,
                              $$.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->cvname);
	          $$.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->defaulted = FALSE;
	          }
	    }			|

	    error	
	    {
/*IMP ??? ??-?? */
            cerror(E_SYNT_RECOV_EXP);
            ats_errok();
            $$.u_ptr_c_type.ptr_tree = mk_i_const((C_LONG)0, (STR_PTR)NULL);
	    }			|

	    comma_exp COMMA exp
	    {
/*STD1298*/
            if ($3.u_ptr_c_type.ptr_tree->op == TOK_IDENTIFIER)	
/*STD0124*/
	       if ($3.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->defaulted)
	          {
	          LANG_ERRMSG(E_UNDE_IDEN_ASSU_EXTE_INT,
                                $3.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->cvname);
	          $3.u_ptr_c_type.ptr_tree->u_lhs.leaf_v->defaulted = FALSE;
	          }
            $$.u_ptr_c_type.ptr_tree = mk_comma_tree($1.u_ptr_c_type.ptr_tree,
                                               $3.u_ptr_c_type.ptr_tree,
                                                            $2.this_token);
	    }			;


list_exp : comma_exp
	   {
           current_tok_p = $1.this_token;
           cvt_comma_expr($1.u_ptr_c_type.ptr_tree);
	   }	     ;

%%
