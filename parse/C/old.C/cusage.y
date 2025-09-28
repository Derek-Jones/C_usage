/*	$Header$

	CGRAM		LastMod	 3 Jun 00  DJ
			Created	   Jul 86  DJ

##############################################################################

	'C' Compiler grammar

	(c) 1986-2002 Knowledge Software Ltd, all rights reserved

##############################################################################
         
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

program : external_declaration 
	  {
	  }	  	       |

	  stmt		       
	  {
	  }                    |

	  function_def_start   
	  {
	  }                    ;
	  

external_declaration : top_level_data_declaration ;


top_level_data_declaration : opt_decl_specifier SEMICOLON  
			     {
			     }				  |

			     opt_decl_specifier list_init_dcltr SEMICOLON 
			     {
			     }						  ;


old_param_decl_list :				     
	   {
           $$.this_token  (TOKEN_LIST)NULL;
           $$.u_ptr_c_type.ptr_c_vlist  (VLIST_PTR)NULL;
           decl_is_empty  TRUE;	/* ready for param decls */
           tdef_valid  TRUE;
	   }					     |

	   old_param_decl_list ELLIPSIS		     
	   {
           if (!cc_extensions[GCC_Extension])
	      LANG_ERROR(E_GCC_ELLIPSIS);
	   }					     |
	   
	   old_param_decl_list parameter_declaration 
	   {
           $$.this_token  $2.this_token;
           $$.u_ptr_c_type.ptr_c_vlist  app_var_list($2.u_ptr_c_type.ptr_c_vlist,
                                                      $1.u_ptr_c_type.ptr_c_vlist);
	   }					     ;


/* Variable */
function_header : opt_decl_specifier p3_fn_dcltr old_param_decl_list 
		  {
		  }				   ;


function_def_start :	function_header OPEN_CURL 
                        {
                        }                         ;


parameter_declaration : decl_specifier SEMICOLON	    
			{
			}				    |

			decl_specifier list_dcltr SEMICOLON 
			{
			}				    ;

typename_declaration : decl_specifier abs_dcltr 
		       {
      		       pop_decl_spec();
      		       current_tok_p  $2.this_token;
      		       $$.u_ptr_c_type.ptr_c_type  build_type($2.u_ptr_c_type.ptr_c_type,
                                                  $1.u_ptr_c_type.ptr_c_type);
		       }			;

/* List of fields */
NT_0003 :			    
	  {
	  $$.u_ptr_c_type.ptr_fld_list  (FIELD_PTR)NULL;
	  }			     |

	  NT_0003 struct_declaration 
	  {
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_fld_list  append_fields($1.u_ptr_c_type.ptr_fld_list,
      	                                          $2.u_ptr_c_type.ptr_fld_list);
	  }			     ;


list_struct_declaration : NT_0003 
		{
		}		;

ptr_star : STAR 
	   {
	   tdef_valid  FALSE;
	   }	|

	   AND 
	   {
	   /* Better error recover by supporting C++ ref
	    * operator in the grammar.
	    */
	   tdef_valid  FALSE;
	   }    ;

star_type : ptr_star		     
	    {
            $$.u_ptr_c_type.ptr_c_type  mk_ptr((C_TYPE_PTR)NULL);
	    }			     |

	    ptr_star type_specifier_list 
	    {
      $$.u_ptr_c_type.ptr_c_type  build_type($2.u_ptr_c_type.ptr_c_type,
                                              mk_ptr((C_TYPE_PTR)NULL));
	    }			     ;


pointer : star_type          |

          pointer star_type  
          {
         $$.u_ptr_c_type.ptr_c_type  build_type(
                                   $2.u_ptr_c_type.ptr_c_type,
                                   $1.u_ptr_c_type.ptr_c_type);
          }                  ;


parameter_type_list : parameter_list		    |
		      parameter_list COMMA ELLIPSIS 
		      {
      $$.u_ptr_c_type.ptr_c_plist  mk_plist($1.u_ptr_c_type.ptr_c_plist,
                                                anon_ellip_var);
		      }				    |

		      ELLIPSIS 
		      {
      LANG_ERROR(E_ELLIPSIS_IS_CPP);
      $$.u_ptr_c_type.ptr_c_plist  (PARAM_LIST_PTR)NULL;
		      }				    ;


parameter_list	: formal_declaration			  
		  {
      $$.u_ptr_c_type.ptr_c_plist  mk_plist((PARAM_LIST_PTR)NULL,
      					     $1.u_ptr_c_type.ptr_c_var);
		  }					  |

/*STD1709a*/
		  parameter_list COMMA formal_declaration 
		  {
      $$.u_ptr_c_type.ptr_c_plist  mk_plist($1.u_ptr_c_type.ptr_c_plist,
                                             $3.u_ptr_c_type.ptr_c_var);
		  }					  ;


formals_declaration : parameter_type_list 
		{
		chk_void_params($$.u_ptr_c_type.ptr_c_plist);
		}			;

formal_declaration : decl_specifier p3_dcltr  
		     {
         current_tok_p  $2.this_token;
	 $2.u_ptr_c_type.ptr_c_var->vtype 
	 		build_type($2.u_ptr_c_type.ptr_c_var->vtype,
                                    rebuild_type(cur_decl_spec));
         chk_formal($2.u_ptr_c_type.ptr_c_var);
         pop_decl_spec();
         $$  $2;
         tdef_valid  TRUE;
		     }			      |

		     decl_specifier abs_dcltr 
		     {
         current_tok_p  $2.this_token;
         pop_decl_spec();
         $$.u_ptr_c_type.ptr_c_var  new_var((STR_PTR)NULL,
					      nest_scope_depth);
         $$.u_ptr_c_type.ptr_c_var->vtype  $2.u_ptr_c_type.ptr_c_type;
         chk_formal($$.u_ptr_c_type.ptr_c_var);
         tdef_valid  TRUE;
		     }			      ;


opt_decl_specifier :		    
		     {
		     $$.u_ptr_c_type.ptr_c_type  (C_TYPE_PTR)NULL;
		     push_decl_spec((C_TYPE_PTR)NULL);
		     }		    |

		     decl_specifier ;


decl_specifier : NT_0005 
		 {
                 mk_empty_set(types_seen);
                 push_decl_spec($1.u_ptr_c_type.ptr_c_type);
		 }	 ;


NT_0005 : tc_specifier	       
	  {
          mk_empty_set(types_seen);
          if ($1.optok ! TOK_AT_LOCATION)
	     combine_std_types(types_seen, $1.optok);
	  }		       |

/*STD1337c*/
	  NT_0005 tc_specifier 
	  {
          current_tok_p  $2.this_token;
          if ($2.optok ! TOK_AT_LOCATION)
             {
	     combine_std_types(types_seen, $2.optok);
             $$.u_ptr_c_type.ptr_c_type  mk_tc_spec($1.u_ptr_c_type.ptr_c_type,
                                                   $2.u_ptr_c_type.ptr_c_type);
             }
	  }		       ;


tc_specifier : std_class      |
	       type_specifier ;


std_class : AUTO     
	    {
            $$.u_ptr_c_type.ptr_c_type  mk_class(CAUTO,
					      (C_TYPE_PTR)NULL);
	    }	     |

	    STATIC   
	    {
            $$.u_ptr_c_type.ptr_c_type  mk_class(CSTATIC,
					      (C_TYPE_PTR)NULL);
	    }	     |

	    EXTERN   
	    {
            $$.u_ptr_c_type.ptr_c_type  mk_class(EXT,
					      (C_TYPE_PTR)NULL);
	    }	     |

	    REGISTER 
	    {
            $$.u_ptr_c_type.ptr_c_type  mk_class(REG,
					      (C_TYPE_PTR)NULL);
	    }	     |

	    TYPEDEF  
	    {
            $$.u_ptr_c_type.ptr_c_type  mk_class(CTYPEDEF,
					      (C_TYPE_PTR)NULL);
	    }	     |

	    INLINE   
	    {
            $$.u_ptr_c_type.ptr_c_type  mk_class(CINLINE,
					      (C_TYPE_PTR)NULL);
	    }	     ;


type_specifier_list : std_type			   
		      {
			/*
			 * The only types allowed are const
			 * and volatile
			 */
      current_tok_p  $1.this_token;
      mk_empty_set(types_seen);	
      if ($1.optok ! TOK_AT_LOCATION)
	    combine_std_types(types_seen, $1.optok);
		      }				   |

		      type_specifier_list std_type 
		      {
	 current_tok_p  $2.this_token;	
	       combine_std_types(types_seen, $2.optok);
	       $$.u_ptr_c_type.ptr_c_type  mk_tc_spec($1.u_ptr_c_type.ptr_c_type,
   	                                            $2.u_ptr_c_type.ptr_c_type);
		      }				   ;
		      

type_specifier : TYPEDEFNAME	                  
		 {
                 tdef_valid  FALSE;
		 }		                  |

		 TYPEOF OPEN_RND exp CLOSE_RND    
		 {
		 $$.u_ptr_c_type.ptr_c_type  $3.u_ptr_c_type.ptr_tree->exptype;
		 }                                |

	         TYPEOF OPEN_RND typename_declaration CLOSE_RND 
		 {
	         $$.u_ptr_c_type.ptr_c_type  $3.u_ptr_c_type.ptr_c_type;
		 }                                |

		 std_type	                  |
		 struct_enum_spec		  ;

struct_enum_spec : struct_specifier 
		   {
                   tdef_valid  FALSE;
		   }		    |

		   enum_specifier   
		   {
                   tdef_valid  FALSE;
		   }		    ;


std_type : CHAR	    
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_char;
           tdef_valid  FALSE;
	   }	    |

	   FLOAT    
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_float;
           tdef_valid  FALSE;
	   }	    |

	   DOUBLE   
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_double;
           tdef_valid  FALSE;
	   }	    |

	   INT	    
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_int;
           tdef_valid  FALSE;
	   }	    |

	   SHORT    
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_short;
           tdef_valid  FALSE;
	   }	    |

	   LONG	    
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_long;
           tdef_valid  FALSE;
	   }	    |

	   UNSIGNED 
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_uint;
           tdef_valid  FALSE;
	   }	    |

	   SIGNED   
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_sint;
           tdef_valid  FALSE;
	   }	    |

	   VOID	    
	   {
           $$.u_ptr_c_type.ptr_c_type  ct_void;
           tdef_valid  FALSE;
	   }	    |

	   PASCAL   
	   {
           $$.u_ptr_c_type.ptr_c_type  mk_class(CPASCAL,
					       (C_TYPE_PTR)NULL);
	   }	    |

	   FORTRAN  
	   {
           $$.u_ptr_c_type.ptr_c_type  mk_class(CFORTRAN,
					       (C_TYPE_PTR)NULL);
	   }	    |

	   type_qual ;


type_qual : CONST    
	    {
            $$.u_ptr_c_type.ptr_c_type  add_qualifier(CCONSTANT, (C_TYPE_PTR)NULL);
	    }	    |

	    VOLATILE 
	    {
            $$.u_ptr_c_type.ptr_c_type  add_qualifier(CVOLATILE, (C_TYPE_PTR)NULL);
	    }	    |

            AT_ADDR IDENTIFIER 
	    {
	    $$.u_ptr_c_type.ptr_c_type  add_qualifier(CEXTENSION, (C_TYPE_PTR)NULL);
	    LANG_ERROR(E_AT_IDENTIFIER);
	    }       ;


struct_or_union : STRUCT	
	{
        tdef_valid  FALSE;
	}			|

	UNION			
	{
        tdef_valid  FALSE;
	}			;


struct_tag : struct_or_union IDENTIFIER 
	     {
      if ($1.optok = TOK_STRUCT)
	 $$.u_ptr_c_type.ptr_c_var  tagged_type($2.u_ptr_c_type.ptr_ident,
                                                                      CSTRUCT);
      else
	 $$.u_ptr_c_type.ptr_c_var  tagged_type($2.u_ptr_c_type.ptr_ident,
                                                                      CUNION);
	     }		       ;


struct_def : struct_tag OPEN_CURL 
	     {
      tdef_valid  TRUE;
      decl_is_empty  FALSE;	
      if ($$.u_ptr_c_type.ptr_c_var->v_scope_level ! nest_scope_depth)	
	 $$.u_ptr_c_type.ptr_c_var  decl_tag($$.u_ptr_c_type.ptr_c_var->cvname,
                                        $$.u_ptr_c_type.ptr_c_var->vtype->base,
					struct_nesting);
      struct_nesting++;
	     }			  ;


struct_curl : struct_or_union OPEN_CURL 
	{
	struct_nesting++;
	tdef_valid  TRUE;
	}				;


struct_specifier : struct_tag					  
		   {
         $$.u_ptr_c_type.ptr_c_type  $$.u_ptr_c_type.ptr_c_var->vtype;
		   }						  |

		   struct_curl list_struct_declaration CLOSE_CURL 
		   {
      just_defined_typeTRUE;
      struct_nesting--;
      current_tok_p  $2.this_token;	
      if ($1.optok = TOK_STRUCT)
	 $$.u_ptr_c_type.ptr_c_type  mk_new_su((STR_PTR)NULL, CSTRUCT,
                                                  $2.u_ptr_c_type.ptr_fld_list,
						  struct_nesting);
      else
	 $$.u_ptr_c_type.ptr_c_type  mk_new_su((STR_PTR)NULL, CUNION,
                                                  $2.u_ptr_c_type.ptr_fld_list,
						  struct_nesting);
		   }						  |

		   struct_def list_struct_declaration CLOSE_CURL  
		   {
      just_defined_typeTRUE;
      struct_nesting--;
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_c_type  fin_su_tagged_decl($1.u_ptr_c_type.ptr_c_var,
      		                                  $2.u_ptr_c_type.ptr_fld_list);
      decl_is_empty  FALSE;
		   }						  ;


struct_declaration : decl_specifier list_struct_dcltr SEMICOLON 
		     {
		     }						;


bitfield_dcltr : p3_dcltr COLON 
		 {
		  if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
		     scope_exit(FALSE);	/* close this prototype scope */
		 }		;

struct_dcltr : p3_dcltr	       
	       {
         current_tok_p  $$.this_token;
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_fld_list  mk_field($$.u_ptr_c_type.ptr_c_var->cvname,
                                    build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                                  rebuild_type(cur_decl_spec)));
	       }	       |

	       COLON exp       
	       {
	 current_tok_p  $2.this_token;	
	 if (is_integral_const($2.u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val($2.u_ptr_c_type.ptr_tree, (INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_BITS_INT_CONST);
	    temp_long  0;
	    }
	 $$.u_ptr_c_type.ptr_fld_list  mk_field((STR_PTR)NULL,
                                            mk_bits(rebuild_type(cur_decl_spec),
                                                               temp_long, FALSE));
	       } 	          |

	       bitfield_dcltr exp 
	       {
	 current_tok_p  $2.this_token;	
	 if (is_integral_const($2.u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val($2.u_ptr_c_type.ptr_tree,
                                       bits_in_type[INT_ALIGN]);
	    }
	 else
	 {
	    LANG_ERROR(E_BITS_INT_CONST);
	    temp_long  bits_in_type[INT_ALIGN];
	 }
      $$.u_ptr_c_type.ptr_fld_list  mk_field($1.u_ptr_c_type.ptr_c_var->cvname,
                            mk_bits(build_type($1.u_ptr_c_type.ptr_c_var->vtype,
                                      rebuild_type(cur_decl_spec)),
							temp_long, TRUE));
	       }	       ;


NT_0006 : enumerator			
	  {
          $$.u_ptr_c_type.ptr_c_vlist  mk_vlist((VLIST_PTR)NULL,
	  					 $1.u_ptr_c_type.ptr_c_var);
	  }				|

	  NT_0006 enumerator		
	  {
      current_tok_p  $2.this_token;	
      LANG_ERROR(E_MISS_COMMA);
      $$.u_ptr_c_type.ptr_c_vlist  mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                     $2.u_ptr_c_type.ptr_c_var);
	  }				|

	  NT_0006 COMMA enumerator	
	  {
      $$.u_ptr_c_type.ptr_c_vlist  mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                     $3.u_ptr_c_type.ptr_c_var);
	  }				;


enumerator_list : NT_0007		
	  {
          set_num(-1, ct_int, &cur_enum_val);
          if (enum_member_count($$.u_ptr_c_type.ptr_c_vlist) > MAX_NUM_ENUMS)
	     LANG_ERROR(E_NUM_ENUM_CONSTS_EXCEEDS_CSTAN);
          if (enum_member_count($$.u_ptr_c_type.ptr_c_vlist) > max_enum_const)
	     LANG_ERROR(E_NUM_ENUM_CONSTS_EXCEEDS_LIMIT);
	  }			;


NT_0007 : NT_0006		|
	  NT_0006 COMMA		
	  {
	  LANG_ERROR(E_ENUM_TRAIL_COMMA);
	  }			;


an_enum : ENUM	
	{
        KandR_Warn($$.this_token->tok.name, KR_ENUM);
        $$.u_ptr_c_type.ptr_c_type  (C_TYPE_PTR)NULL;
        tdef_valid  FALSE;
	}	;


enum_tag : an_enum IDENTIFIER	
	{
      $$.u_ptr_c_type.ptr_c_var  tagged_type($2.u_ptr_c_type.ptr_ident, CENUM);
	}			;


enum_def : enum_tag OPEN_CURL	
	{
      decl_is_empty  FALSE;	
      if ($$.u_ptr_c_type.ptr_c_var->v_scope_level ! nest_scope_depth)
	 $$.u_ptr_c_type.ptr_c_var  decl_tag($$.u_ptr_c_type.ptr_c_var->cvname,
                                              CENUM,
					      struct_nesting);
	}			;

	
enum_specifier : enum_tag	
		{
      $$.u_ptr_c_type.ptr_c_type  $$.u_ptr_c_type.ptr_c_var->vtype;
		}		|

		 an_enum OPEN_CURL enumerator_list CLOSE_CURL	
		 {
      		 mk_enum(&($$.u_ptr_c_type.ptr_c_type), $3.u_ptr_c_type.ptr_c_vlist);
      		 just_defined_typeTRUE;
      		 decl_is_empty  FALSE;
		 }						|

		 enum_def enumerator_list CLOSE_CURL            
		 {
	 	 current_tok_p  $3.this_token;
	 	 mk_enum(&($$.u_ptr_c_type.ptr_c_var->vtype),
                                                   $2.u_ptr_c_type.ptr_c_vlist);
	 	 $$.u_ptr_c_type.ptr_c_type  $$.u_ptr_c_type.ptr_c_var->vtype;
         	 just_defined_typeTRUE;
         	 decl_is_empty  FALSE;
		 }						;


enum_set_val : IDENTIFIER ASSIGN 
	       {
	       tdef_valid  TRUE;	/* to allow casts in ensuing exp */
	       }		 ;


enumerator : IDENTIFIER		   
	     {
             current_tok_p  $1.this_token;	
             if (signed_compare(&cur_enum_val,
				&int_info->val[IS_SIGNED].max_val) = COMP_EQ)
	        LANG_ERROR(E_ENUM_CONS_TOO_LARG);
             else
                {
                if (signed_compare(&cur_enum_val,
			   &int_info->val[IS_SIGNED].max_port_val) ! COMP_LT)
	           LANG_ERROR(E_ENUM_VALU_EXCEED_MIN_VAL);
                inc_number(&cur_enum_val, IS_SIGNED);	
                }
             $$.u_ptr_c_type.ptr_c_var  mk_efield($1.u_ptr_c_type.ptr_ident,
                                                   &cur_enum_val);
	     }			   |

	     enum_set_val exp 
	     {
	 current_tok_p  $2.this_token;	
	 if (is_integral_const($2.u_ptr_c_type.ptr_tree))
	    {
	    get_folded_num(&cur_enum_val, $2.u_ptr_c_type.ptr_tree);
	    }
	 else
	    LANG_ERROR(E_ENUM_INT_CONST);
      $$.u_ptr_c_type.ptr_c_var  mk_efield($1.u_ptr_c_type.ptr_ident,
                                                  &cur_enum_val);
	     }			   ;


identifier_list : IDENTIFIER			   
		  {
                  $$.u_ptr_c_type.ptr_c_plist  mk_plist((PARAM_LIST_PTR)NULL,
                                             new_var($1.u_ptr_c_type.ptr_ident,
                                                    nest_scope_depth));
		  }				   |

		  identifier_list COMMA IDENTIFIER 
		  {
             $$.u_ptr_c_type.ptr_c_plist  mk_plist($1.u_ptr_c_type.ptr_c_plist,
                                      new_var($3.u_ptr_c_type.ptr_ident,
                                               nest_scope_depth));
		  }				   ;

p1_dcltr : IDENTIFIER		    
	   {
           $$.u_ptr_c_type.ptr_c_var  new_var($1.u_ptr_c_type.ptr_ident,
                                               nest_scope_depth);
           decl_is_empty  FALSE;
	   }			    ;


p2_fndcl : p2_dcltr OPEN_RND 
	   {
           current_tok_p  $1.this_token;
	   if (cc_extensions[CPP_Extension] &&
	       just_defined_type)
	      {
	      just_defined_typeFALSE;
	      LANG_ERROR(E_CPP_DEF_TYPE_RET);
	      }
           tdef_valid  TRUE;
           nested_params++;		
           scope_entry();	/* open prototype scope */
	   }		     ;

p2_fn_dcltr : p2_fndcl CLOSE_RND		      
	   {
      current_tok_p  $2.this_token;
      if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
         scope_exit(FALSE);	/* close this prototype scope */
      $$.u_ptr_c_type.ptr_c_var->vtype 
                                 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                            mk_func((C_TYPE_PTR)NULL,
					            OLD_FUNC_DECL,
						    (PARAM_LIST_PTR)NULL));
      tdef_valid  TRUE;
      nested_params--;
	   }					      |

	   OPEN_RND p3_dcltr CLOSE_RND                
	   {
	   $$  $2;
	   }			                      |

	   p2_fndcl identifier_list CLOSE_RND	      
	   {
	 current_tok_p  $2.this_token;
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_c_var->vtype 
				 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                             mk_func((C_TYPE_PTR)NULL,
					     	     OLD_FUNC_DECL,
                                               	     $2.u_ptr_c_type.ptr_c_plist));
         tdef_valid  TRUE;
         nested_params--;
	   }					      |

	   p2_fndcl formals_declaration CLOSE_RND     
	   {
	 current_tok_p  $2.this_token;
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_c_var->vtype 
				build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                              mk_func((C_TYPE_PTR)NULL,
					      	      PROTOTYPE_FUNC,
                                               	      $2.u_ptr_c_type.ptr_c_plist));
         tdef_valid  TRUE;
         nested_params--;
	   }					      ;

p2_dcltr : p1_dcltr				      |
	   p2_fn_dcltr				      |

	   p2_dcltr OPEN_SQUARE CLOSE_SQUARE	      
	   {
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_c_var->vtype 
				 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                          mk_array((C_TYPE_PTR)NULL,
					  	   (TYPE_SIZE_TYPE)0));
	   }					      |

	   p2_dcltr OPEN_SQUARE cond_exp CLOSE_SQUARE 
	   {
	 current_tok_p  $3.this_token;	
	 if (is_integral_const($3.u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val($3.u_ptr_c_type.ptr_tree,
						(INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long  0;
	    }
         $$.u_ptr_c_type.ptr_c_var->vtype 
				 build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                                  mk_array((C_TYPE_PTR)NULL,
						  	    temp_long));
	   }		    ;


p3_dcltr : p2_dcltr	    maybe_asm |

	   pointer p2_dcltr maybe_asm 
	   {
         $2.u_ptr_c_type.ptr_c_var->vtype 
				build_type($2.u_ptr_c_type.ptr_c_var->vtype,
                                                 $1.u_ptr_c_type.ptr_c_type);
         $$  $2;
	   }		    ;

p3_fn_dcltr : p2_fn_dcltr         |

	      pointer p2_fn_dcltr 
		{
      $2.u_ptr_c_type.ptr_c_var->vtype 
				 build_type($2.u_ptr_c_type.ptr_c_var->vtype,
                                                 $1.u_ptr_c_type.ptr_c_type);
      $$  $2;
		}			;

dcltr : p3_dcltr 
	{
      if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
         {
	 scope_exit(FALSE);	/* close prototype scope */
	 /* and transform fn params
          * add in the current decl specifier
	  */
	 strip_idents_from_formals($$.u_ptr_c_type.ptr_c_var->vtype);
         }
      
	}	 ;


i_dcltr : p3_dcltr ASSIGN 
	  {
      tdef_valid  TRUE;	/* allow casts in ensuing initializer */
      if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
         {
	 scope_exit(FALSE);	/* close prototype scope */
	 /*
	  * and transform fn params
	  */
	 strip_idents_from_formals($$.u_ptr_c_type.ptr_c_var->vtype);
         }
      current_tok_p  $1.this_token;	
      init_declare(&($$.u_ptr_c_type.ptr_c_var));
      cur_scope->has_init  TRUE;	
      start_initializer($$.u_ptr_c_type.ptr_c_var);
	  }		  ;

at_location : AT_ADDR cond_exp 
	      {
	      current_tok_p  $1.this_token;	
	      LANG_ERROR(E_AT_LOCATION);
	      }		       ;

init_dcltr : init_1_dcltr             |
	     init_1_dcltr at_location ;

init_1_dcltr : dcltr             |

	     i_dcltr init_exp  
	     {
	     }		       ;


NT_0009 : init_exp		 |

	  NT_0009 COMMA init_exp 
	  {
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
	   $$$2;
	   }				;

NT_0010 :  NT_0009		|

	   NT_0009 COMMA	
	   {
	   }			;


p1_abs_dcltr : OPEN_RND p3_abs_dcltr CLOSE_RND 
	       {
	       $$  $2;
	       }			       ;


p2_abs_fndcl : p2_abs_dcltr OPEN_RND	
	       {
               current_tok_p  $1.this_token;
               tdef_valid  TRUE;
               nested_params++;		
               scope_entry();	/* open prototype scope */
	       }			;


e_open_rnd : OPEN_RND	
	     {
             tdef_valid  TRUE;
             nested_params++;		
             scope_entry();	/* open prototype scope */
	     }		;


p2_abs_dcltr : p1_abs_dcltr				      |

	       p2_abs_fndcl CLOSE_RND			      
	       {
      current_tok_p  $2.this_token;
      scope_exit(TRUE);		/* close prototype scope */
      $$.u_ptr_c_type.ptr_c_type  build_type($1.u_ptr_c_type.ptr_c_type,
                                              mk_func((C_TYPE_PTR)NULL,
					      	      OLD_FUNC_DECL,
						      (PARAM_LIST_PTR)NULL));
      tdef_valid  TRUE;
      nested_params--;
	       }					      |

	       p2_abs_fndcl parameter_type_list CLOSE_RND     
	       {
      scope_exit(TRUE);		/* close prototype scope */
      current_tok_p  $1.this_token;	/* we do not want a
					 * variable list here! */
      $$.u_ptr_c_type.ptr_c_type  mk_func((C_TYPE_PTR)NULL, PROTOTYPE_FUNC,
                                            $2.u_ptr_c_type.ptr_c_plist);
      strip_idents_from_formals($$.u_ptr_c_type.ptr_c_type);
      $$.u_ptr_c_type.ptr_c_type  build_type($1.u_ptr_c_type.ptr_c_type,
                                                 $$.u_ptr_c_type.ptr_c_type);
      tdef_valid  TRUE;
      nested_params--;
	       }					      |

	       e_open_rnd parameter_type_list CLOSE_RND     
	       {
      scope_exit(TRUE);		/* close prototype scope */
      current_tok_p  $1.this_token;	/* we do not want a
					 * variable list here! */
      $$.u_ptr_c_type.ptr_c_type  mk_func((C_TYPE_PTR)NULL, PROTOTYPE_FUNC,
                                               $2.u_ptr_c_type.ptr_c_plist);
      strip_idents_from_formals($$.u_ptr_c_type.ptr_c_type);
      tdef_valid  TRUE;
      nested_params--;
	       }					      |

	       e_open_rnd CLOSE_RND			      
	       {
      current_tok_p  $2.this_token;
      scope_exit(TRUE);		/* close prototype scope */
      $$.u_ptr_c_type.ptr_c_type  mk_func((C_TYPE_PTR)NULL, OLD_FUNC_DECL,
      						(PARAM_LIST_PTR)NULL);
      tdef_valid  TRUE;
      nested_params--;
	       }					      |

	       p2_abs_dcltr OPEN_SQUARE CLOSE_SQUARE	      
	       {
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_c_type  build_type($1.u_ptr_c_type.ptr_c_type,
                                              mk_array((C_TYPE_PTR)NULL,
					      	       (TYPE_SIZE_TYPE)0));
	       }					      |

	       p2_abs_dcltr OPEN_SQUARE cond_exp CLOSE_SQUARE 
	       {
	 current_tok_p  $3.this_token;	
	 if (is_integral_const($3.u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val($3.u_ptr_c_type.ptr_tree, (INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long  0;
	    }
         $$.u_ptr_c_type.ptr_c_type  build_type($1.u_ptr_c_type.ptr_c_type,
                                                 mk_array((C_TYPE_PTR)NULL,
						 	  temp_long));
	       }					      |

	       e_abs_dcltr OPEN_SQUARE CLOSE_SQUARE	      
	       {
            $$.u_ptr_c_type.ptr_c_type  mk_array((C_TYPE_PTR)NULL, (TYPE_SIZE_TYPE)0);
	       }					      |

	       e_abs_dcltr OPEN_SQUARE cond_exp CLOSE_SQUARE  
	       {
	 current_tok_p  $3.this_token;	
	 if (is_integral_const($3.u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val($3.u_ptr_c_type.ptr_tree,
						(INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long  0;
	    }
         $$.u_ptr_c_type.ptr_c_type  mk_array((C_TYPE_PTR)NULL,
						      temp_long);
	       }					      ;


p3_abs_dcltr : p2_abs_dcltr	    |

	       pointer p2_abs_dcltr 
	       {
      $$.u_ptr_c_type.ptr_c_type  build_type($2.u_ptr_c_type.ptr_c_type,
                                                $1.u_ptr_c_type.ptr_c_type);
	       }		    |
	       pointer e_abs_dcltr  
	       {
      $$.u_ptr_c_type.ptr_c_type  $1.u_ptr_c_type.ptr_c_type ;
	       }		    ;


e_abs_dcltr : ;


abs_dcltr : p3_abs_dcltr 
	    {
      $$.u_ptr_c_type.ptr_c_type  build_type($$.u_ptr_c_type.ptr_c_type,
                                                rebuild_type(cur_decl_spec));
	    }		 |

	    e_abs_dcltr	 
	    {
      $$.u_ptr_c_type.ptr_c_type  rebuild_type(cur_decl_spec);
	    }		 ;


list_init_dcltr : init_dcltr			   
		  {
      $$.u_ptr_c_type.ptr_c_vlist  mk_vlist((VLIST_PTR)NULL,
      					     $1.u_ptr_c_type.ptr_c_var);
      tdef_valid  FALSE;
		  }				   |

		  list_init_dcltr COMMA init_dcltr 
		  {
			/* NOTE: we build var list back to front!!!! */
      $$.u_ptr_c_type.ptr_c_vlist  mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                   $3.u_ptr_c_type.ptr_c_var);
      tdef_valid  FALSE;
		  }				   ;


list_struct_dcltr : struct_dcltr                	 
		    {
		    tdef_valid  FALSE;
		    }					|

		    list_struct_dcltr COMMA struct_dcltr 
		    {
      current_tok_p  $3.this_token;
      $$.u_ptr_c_type.ptr_fld_list  append_fields($1.u_ptr_c_type.ptr_fld_list,
                                                 $3.u_ptr_c_type.ptr_fld_list);
      tdef_valid  FALSE;
		    }					 ;


list_dcltr : p3_dcltr		       
	     {
	 if (is_open_proto_scope($$.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 $$.u_ptr_c_type.ptr_c_var->vtype  build_type($$.u_ptr_c_type.ptr_c_var->vtype,
                                                  rebuild_type(cur_decl_spec));
	 $$.u_ptr_c_type.ptr_c_vlist  mk_vlist((VLIST_PTR)NULL,
	 					$$.u_ptr_c_type.ptr_c_var);
         tdef_valid  FALSE;
	     }			       |

	     list_dcltr COMMA p3_dcltr 
	     {
	 if (is_open_proto_scope($3.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 $3.u_ptr_c_type.ptr_c_var->vtype  build_type($3.u_ptr_c_type.ptr_c_var->vtype,
                                              rebuild_type(cur_decl_spec));
	 $$.u_ptr_c_type.ptr_c_vlist  mk_vlist($1.u_ptr_c_type.ptr_c_vlist,
                                                    $3.u_ptr_c_type.ptr_c_var);
         tdef_valid  FALSE;
	     }			       ;


maybe_asm :                                |
            ASM OPEN_RND LITERAL CLOSE_RND 
	    {
	    }                              ;

asm_stmt : asm_gnu_stmt 
	   {
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

label_list  : label		
	      {
	      not_labelledFALSE;
	      }		        |

	      label_list label	;

/*
 * null statement is parsed as a null top level declaration
 */
basic_stmt : e_stmt		       |
	     do_header		       |

	     BREAK SEMICOLON	       
	     {
	     }			       |

	     CONTINUE SEMICOLON	       
	     {
	     }			       |

	     GOTO IDENTIFIER SEMICOLON 
	     {
	     }			       |

	     return_stmt	       |
	     asm_stmt                  
	     {
	     }                         ;


stmt : bal_statement		|
       label_list bal_statement	;


bal_statement : basic_stmt	|
		while_header	|
		for_header	|
		if_header	|
		switch_header   ;


if_tok  : IF 
	  {
	  }  ;


if_header  : if_tok OPEN_RND list_exp CLOSE_RND 
	     {
	     }		  ;


e_stmt : UNDEFINED list_exp SEMICOLON 
	 {
	 }		    ;


while_tok : WHILE 
	    {
	    }     ;


while_header  : while_tok OPEN_RND list_exp CLOSE_RND 
		{
		}		;


do_header : DO 
	    {
	    }  ;



NT_0014 : SEMICOLON CLOSE_RND	       
	  {
	  }			       |

	  SEMICOLON list_exp CLOSE_RND 
	  {
	  }			       ;


for_tok : FOR 
	  {
	  }   ;


for_header     : for_tok OPEN_RND SEMICOLON NT_0014		      
		 {
		 }						      |

		 for_tok OPEN_RND SEMICOLON list_exp NT_0014	      
		 {
		 }						      |

		 for_tok OPEN_RND list_exp SEMICOLON NT_0014	      
		 {
		 }					 	      |

		 for_tok OPEN_RND list_exp SEMICOLON list_exp NT_0014 
		 {
		 }						      ;


switch_tok : SWITCH 
	     {
	     }      ;


switch_header	: switch_tok OPEN_RND list_exp CLOSE_RND 
		  {
		  }		;


return_stmt : RETURN SEMICOLON		
	      {
	      }				|

	      RETURN list_exp SEMICOLON 
	      {
	      }			  ;



label : IDENTIFIER COLON 
	{
	}		 |

	CASE exp COLON	 
	{
	}		 |

	DEFAULT COLON	 
	{
	}		;


paren_exp : OPEN_RND list_exp CLOSE_RND 
	    {
      $$.u_ptr_c_type.ptr_tree  mk_tree($2.u_ptr_c_type.ptr_tree, (TPTR_TYPE)NULL,
                                         TOK_OPEN_RND,
					 $1.this_token->tok.parent_macro);
	    }				;


primary_exp : IDENTIFIER					
	      {
              current_tok_p  $1.this_token;	
	      id_name$1.u_ptr_c_type.ptr_ident;
              $1.u_ptr_c_type.ptr_c_var  lookup_var(id_name,
					       $1.this_token->tok.parent_macro);
              $$.u_ptr_c_type.ptr_tree  mk_leaf(&($1), TOK_IDENTIFIER);
	      }						|

	      LITERAL					
	      {
		 }						|

		 paren_exp					;


postfix_exp : primary_exp					   |

	      postfix_exp OPEN_SQUARE list_exp CLOSE_SQUARE        
	      {
              array_bnd_chk($1.u_ptr_c_type.ptr_tree, $3.u_ptr_c_type.ptr_tree);
              current_tok_p  $2.this_token;
              $$.u_ptr_c_type.ptr_tree 
		        mk_tree($1.u_ptr_c_type.ptr_tree,
                                $3.u_ptr_c_type.ptr_tree,
				TOK_ARRAY_REF,
		                $2.this_token->tok.parent_macro);
	      }						   |

	      postfix_exp OPEN_RND CLOSE_RND		   
	      {
              current_tok_p  $1.this_token;
              $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
					    (TPTR_TYPE)NULL,
                                            TOK_FNC_CALL,
				            current_tok_p->tok.parent_macro);
	       }					   |

		 postfix_exp OPEN_RND comma_exp CLOSE_RND	    
		 {
      current_tok_p  $3.this_token;
      temp_tree_ptr  tilt_args($3.u_ptr_c_type.ptr_tree);
      current_tok_p  $1.this_token;
      $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         temp_tree_ptr,
					 TOK_FNC_CALL,
				         $2.this_token->tok.parent_macro);
		 }						   |

		 postfix_exp DOT IDENTIFIER			   
		 {
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         (TPTR_TYPE)$3.u_ptr_c_type.ptr_ident,
                                         TOK_DIR_SELECT,
				         $2.this_token->tok.parent_macro);
	/* note type punning of Ptr_Ident with Ptr_Tree */
		 }						     |

		 postfix_exp DEREF IDENTIFIER		   
		 {
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         (TPTR_TYPE)$3.u_ptr_c_type.ptr_ident,
                                         TOK_INDIR_SELECT,
				         $2.this_token->tok.parent_macro);
		 }						     |

	         postfix_exp postfix_op			   
	         {
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
					 (TPTR_TYPE)NULL,
                                         $2.optok,
				         $2.this_token->tok.parent_macro);
	         }						     |

		 postfix_exp DOT LITERAL		   
		 {
      /*
       * S. 9 is tokenised as IDENTIFIER DOT LITERAL
       */
      current_tok_p  $2.this_token;
      $$$1;
      LANG_ERROR(E_EXT_BIT_SELECT);
		 }						     |

		 postfix_exp     LITERAL		   
		 {
      /*
       * S.9 is tokenised as IDENTIFIER LITERAL, not
       * IDENTIFIER DOT LITERAL
       * where the literal will be a floating point value
       */
      current_tok_p  $2.this_token;
      $$$1;
		 }						     ;


postfix_op : PLUSPLUS	
	     {
	     $$.optokTOK_POST_PLUS;
	     }		|

	     MINUSMINUS 
	     {
	     $$.optokTOK_POST_MINUS;
	     }		;

unary_exp : postfix_exp	|

	    SIZEOF OPEN_RND typename_declaration CLOSE_RND 
	    {
	    current_tok_p  $3.this_token;
	    $$.u_ptr_c_type.ptr_tree  mk_sizeof($3.u_ptr_c_type.ptr_c_type,
                                                  FALSE,
				                  $3.this_token->tok.parent_macro);
            tdef_valid  TRUE;
	    }						  |

	    SIZEOF unary_exp	
	    {
	    current_tok_p  $2.this_token;
	    $$.u_ptr_c_type.ptr_tree  mk_sizeof($2.u_ptr_c_type.ptr_tree->exptype,
                                              $2.u_ptr_c_type.ptr_tree->is_l_value,
				              $2.this_token->tok.parent_macro);
	     }			|

	     ALIGNOF OPEN_RND typename_declaration CLOSE_RND 
	     {
	     }						     |

	     ALIGNOF unary_exp	  
	     {
	     }			  |

	     prefix_op unary_exp 
	     {
             current_tok_p  $2.this_token;
             $$.u_ptr_c_type.ptr_tree  mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                                $1.optok,
				                $1.this_token->tok.parent_macro);
	     }			|

	     STAR cast_exp	
	     {
             current_tok_p  $2.this_token;
             $$.u_ptr_c_type.ptr_tree  mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	TOK_CONT_OF,
				         	$1.this_token->tok.parent_macro);
	     }			|

	     AND cast_exp	
	     {
             current_tok_p  $2.this_token;
             $$.u_ptr_c_type.ptr_tree  mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	TOK_ADDR_OF,
				         	$1.this_token->tok.parent_macro);
	     }			|

	     negate_op cast_exp 
	     {
             current_tok_p  $2.this_token;
             $$.u_ptr_c_type.ptr_tree  mk_tree($2.u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	$1.optok,
				         	$1.this_token->tok.parent_macro);
	     }			|


	     ANDTEST IDENTIFIER	
	     {
             /*
	      * The NULL pointer constant, a 'safe' value
	      */
	     $$.u_ptr_c_type.ptr_tree  mk_l_const(0,
				                   $1.this_token->tok.parent_macro);
	     }		        ;

prefix_op : PLUSPLUS   
	    {
	    $$.optokTOK_PRE_PLUS;
	    }	       |

	    MINUSMINUS 
	    {
	    $$.optokTOK_PRE_MINUS;
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
	    tdef_valid  TRUE;
	    $$  $2;
	    }					    ;

cast_exp : unary_exp		|

	   type_cast cast_exp	
	   {
           current_tok_p  $$.this_token;
           $$.u_ptr_c_type.ptr_tree  mk_cast($2.u_ptr_c_type.ptr_tree,
                                                $$.u_ptr_c_type.ptr_c_type,
				         	$1.this_token->tok.parent_macro);
	   }			;



mult_oper_exp : cast_exp			     |
		
		mult_oper_exp mult_op cast_exp 
		{
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree, $2.optok,
				         $2.this_token->tok.parent_macro);
		}				     ;


mult_op : STAR	    
	  {
	  $$.optok  TOK_TIMES;
	  }	    |
	  DIVIDE    |
	  REMAINDER ;


add_oper_exp : mult_oper_exp			 |

	       add_oper_exp add_op mult_oper_exp 
	       {
      current_tok_p  $2.this_token;
      $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                        $3.u_ptr_c_type.ptr_tree, $2.optok,
				        $2.this_token->tok.parent_macro);
	       }				 ;


add_op : PLUS	
	 {
	 $$.optok  TOK_ADD;
	 }	|
	 
	 NEGATE 
	 {
	 $$.optok  TOK_MINUS;
	 }     ;


shift_oper_exp : add_oper_exp			      |

		 shift_oper_exp shift_op add_oper_exp 
		 {
                 current_tok_p  $2.this_token;
                 $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree, $2.optok,
				         $2.this_token->tok.parent_macro);
		 }				      ;


shift_op : LEFTSHIFT  |
	   RIGHTSHIFT ;


rel_oper_exp : shift_oper_exp			  |

	       rel_oper_exp rel_op shift_oper_exp 
	       {
               current_tok_p  $2.this_token;
               $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
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
               current_tok_p  $2.this_token;
               $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         $2.optok,
				         $2.this_token->tok.parent_macro);
	       }				;


equ_op : EQUAL	  |
	 NOTEQUAL ;


bitand_oper_exp : equ_oper_exp			   |

		  bitand_oper_exp AND equ_oper_exp 
		  {
                  current_tok_p  $2.this_token;
                  $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_BIT_AND,
				         $2.this_token->tok.parent_macro);
		  }				   ;


bitxor_oper_exp : bitand_oper_exp		      |

		  bitxor_oper_exp XOR bitand_oper_exp 
		  {
                  current_tok_p  $2.this_token;
                  $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_BIT_XOR,
				         $2.this_token->tok.parent_macro);
		  }				      ;


bitor_oper_exp : bitxor_oper_exp		   |

		 bitor_oper_exp OR bitxor_oper_exp 
		 {
                 current_tok_p  $2.this_token;
                 $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_BIT_OR,
				         $2.this_token->tok.parent_macro);
		 }				   ;


and_oper_exp : bitor_oper_exp			   |

	       and_oper_exp ANDTEST bitor_oper_exp 
	       {
               current_tok_p  $2.this_token;
               $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_LOG_AND,
				         $2.this_token->tok.parent_macro);
	       }				   ;


or_oper_exp : and_oper_exp		      |

	      or_oper_exp ORTEST and_oper_exp 
	      {
              current_tok_p  $2.this_token;
              $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
                                         $3.u_ptr_c_type.ptr_tree,
                                         TOK_LOG_OR,
				         $2.this_token->tok.parent_macro);
	      }						   ;


cond_exp : or_oper_exp					|

	   or_oper_exp QUESTION list_exp COLON cond_exp 
	   {
           current_tok_p  $2.this_token;
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
             if ($1.u_ptr_c_type.ptr_tree->op = TOK_CAST)
	        {
                current_tok_p  $1.this_token;
	        LANG_ERROR(E_CAST_ON_LHS_ASSIGN);
                while ($1.u_ptr_c_type.ptr_tree->op = TOK_CAST)
                   $1.u_ptr_c_type.ptr_treeRHS_EXPR($1.u_ptr_c_type.ptr_tree);
		}
/*STD1232*/
             current_tok_p  $2.this_token;
             $$.u_ptr_c_type.ptr_tree  mk_tree($1.u_ptr_c_type.ptr_tree,
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
	    }			|

	    comma_exp COMMA exp 
	    {
	    }			;


list_exp : comma_exp 
	   {
           current_tok_p  $1.this_token;
           cvt_comma_expr($1.u_ptr_c_type.ptr_tree);
	   }	     ;

%%
