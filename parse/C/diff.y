1c1
<                        /* cbook.y, 21 Apr 08 */
---
>                        /* cbook.y,  2 Mar 05 */
44d43
< 
282,300c281
<         if (seen_ES)
< 	   {
< 	   TRACE_LOG("ES");
< 	   }
<         else if (seen_DC)
< 	   {
< 	   TRACE_LOG("DC");
< 	   }
< 	}                   ;
< /*
<    An attempt is made to parse the token sequence:
< 
<       static foo bar;
<       static int foo (lose);
< 
<    as two declarations (i.e., the second static does not cause the
<    first line to reduce through declaration) unless this production
<    is commented out
< 
---
> 	}                   |
302d282
<  */
305c285
<               external_declaration  %merge <stmt_decl_merge>
---
>               external_declaration  %dprec 1
307d286
< #if STMT_DEBUG
309,311c288,289
< #endif
<               seen_term_tok=TRUE;
< 	      cnt_rule(yyn);
---
> 	      seen_term_tok=TRUE;
>               cnt_rule();
313c291
<               statement             %merge <stmt_decl_merge>
---
>               statement             %dprec 2
315d292
< #if STMT_DEBUG
317d293
< #endif
319c295
< 	      cnt_rule(yyn);
---
> 	      cnt_rule();
328,329c304
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
333,334c308
<               $$.node_ptr=mk_leaf_node(INTEGER_CONST);
<               cnt_rule(yyn);
---
>               cnt_rule();
336c310
<               string_seq
---
>               STRING_LITERAL
338,339c312
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
343,344c316
<               $$.node_ptr=mk_unary_node(TOK_OPEN_RND, $2.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
346,379c318
< 
< /*
<    A made up rule to handle the fact that string concatenation
<    is not being handled by a preprocessor (4% of syntax errors).
<  */
< string_seq: STRING_LITERAL
<             {
<             $$.node_ptr=mk_leaf_node(STRING_CONST);
<             cnt_rule(yyn);
<             }                  |
<             string_seq STRING_LITERAL
<             {
<             $$.node_ptr=mk_binary_node(TOK_STRING_CONCAT, $1.node_ptr,
< 					mk_leaf_node(STRING_CONST));
<             cnt_rule(yyn);
<             }                  |
< /*
<    Extension.  The following handle the case where a macro expands
<    to a string that is then expected to be concatenated with
<    an adjacent string.
<  */
<             string_seq IDENTIFIER
<             {
<             $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<             $$=$1;
<             cnt_rule(yyn);
<             }                  |
<             string_seq IDENTIFIER OPEN_RND constant_expr CLOSE_RND
<             {
<             $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<             $$=$1;
<             cnt_rule(yyn);
<             }                  ;
< 
---
>               
382,383c321
<               $$.node_ptr=NULL;
< 	      cnt_rule(yyn);
---
>               cnt_rule();
387,388c325
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
394,395c331
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
399,400c335
<               $$.node_ptr=mk_binary_node(TOK_OPEN_SQUARE, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
404,405c339
<               $$.node_ptr=mk_binary_node(TOK_FUNC_CALL, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
409,411c343
<               $$.node_ptr=mk_binary_node(TOK_DIR_SELECT, $1.node_ptr,
< 					         mk_leaf_node(TOK_IDENTIFIER));
<               cnt_rule(yyn);
---
>               cnt_rule();
415,417c347
<               $$.node_ptr=mk_binary_node(TOK_INDIR_SELECT, $1.node_ptr,
< 					         mk_leaf_node(TOK_IDENTIFIER));
<               cnt_rule(yyn);
---
>               cnt_rule();
421,422c351
<               $$.node_ptr=mk_unary_node(TOK_POST_PLUS, $1.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
426,427c355
<               $$.node_ptr=mk_unary_node(TOK_POST_MINUS, $1.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
431,432c359
<               $$.node_ptr=mk_binary_node(TOK_CMPD_INIT, $2.node_ptr, $5.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
436,437c363
<               $$.node_ptr=mk_binary_node(TOK_CMPD_INIT, $2.node_ptr, $5.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
444,445c370
<               $$.node_ptr=mk_binary_node(TOK_ARG, $1.node_ptr, NULL);
<               cnt_rule(yyn);
---
>               cnt_rule();
449,450c374
<               $$.node_ptr=mk_binary_node(TOK_ARG, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
457,458c381
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
462,463c385
<               $$.node_ptr=mk_unary_node(TOK_PRE_PLUS, $2.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
467,468c389
<               $$.node_ptr=mk_unary_node(TOK_PRE_MINUS, $2.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
472,473c393
<               $$.node_ptr=mk_unary_node($1.tok, $2.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
481,482c401
<               $$.node_ptr=mk_unary_node(TOK_SIZEOF, $2.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
486,487c405
<               $$.node_ptr=mk_unary_node(TOK_SIZEOF, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
492c410
<               BITAND
---
>               AND
494,495c412
< 	      $$.tok=TOK_ADDR;
<               cnt_rule(yyn);
---
>               cnt_rule();
499,500c416
<               $$.tok=TOK_STAR;
<               cnt_rule(yyn);
---
>               cnt_rule();
504,505c420
<               $$.tok=TOK_PLUS;
<               cnt_rule(yyn);
---
>               cnt_rule();
509,510c424
<               $$.tok=TOK_ARITH_NEG;
<               cnt_rule(yyn);
---
>               cnt_rule();
514,515c428
<               $$.tok=TOK_BIT_NOT;
<               cnt_rule(yyn);
---
>               cnt_rule();
519,520c432
<               $$.tok=TOK_LOG_NOT;
<               cnt_rule(yyn);
---
>               cnt_rule();
535,536c447
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
540,541c451
<               $$.node_ptr=mk_binary_node(TOK_CAST, $2.node_ptr, $4.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
554c464
<               cast_expr                           %merge <multiplicative_merge>
---
>               cast_expr                           %dprec 2
556,557c466
< 	      $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
559c468,474
<               multiplicative_expr TIMES cast_expr %merge <multiplicative_merge>
---
>               cast_expr TIMES multiplicative_expr  %dprec 1
>               {
>               cnt_rule();
>               }                         |
> /*
>    See discussion for additive_expr
>               multiplicative_expr TIMES cast_expr %dprec 1
561,562c476
<               $$.node_ptr=mk_binary_node(TOK_TIMES, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
563a478
>  */
566,567c481
<               $$.node_ptr=mk_binary_node(TOK_DIVIDE, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
571,572c485
<               $$.node_ptr=mk_binary_node(TOK_REMAINDER, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
574,584d486
< /*
<    See discussion for additive_expr
<               cast_expr                           %dprec 2
<                                        |
<               cast_expr TIMES multiplicative_expr %dprec 1
<                                        |
<               cast_expr DIVIDE multiplicative_expr
<                                        |
<               cast_expr REMAINDER multiplicative_expr
<                                        ;
<  */
598c500
<               multiplicative_expr                     %merge <additive_merge>
---
>               multiplicative_expr                     %dprec 2
600,601c502
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
603c504
< 	      additive_expr ADD multiplicative_expr   %merge <additive_merge>
---
> 	      multiplicative_expr ADD additive_expr   %dprec 3
605,606c506
<               $$.node_ptr=mk_binary_node(TOK_ADD, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
608c508
<               additive_expr MINUS multiplicative_expr %merge <additive_merge>
---
>               multiplicative_expr MINUS additive_expr %dprec 1
610,611c510
<               $$.node_ptr=mk_binary_node(TOK_MINUS, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
613d511
< 	      
637,642c535,542
<               multiplicative_expr                     %dprec 2
<                                    |
< 	      multiplicative_expr ADD additive_expr   %dprec 3
<                                    |
<               multiplicative_expr MINUS additive_expr %dprec 1
<                                    ;
---
> 	      additive_expr ADD multiplicative_expr   %dprec 3
>               {
>               cnt_rule();
>               }                     |
>               additive_expr MINUS multiplicative_expr %dprec 1
>               {
>               cnt_rule();
>               }                     ;
649,650c549
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
654,655c553
<               $$.node_ptr=mk_binary_node(TOK_LSHIFT, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
659,660c557
<               $$.node_ptr=mk_binary_node(TOK_RSHIFT, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
667,668c564
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
672,673c568
<               $$.node_ptr=mk_binary_node(TOK_LESS_THAN, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
677,678c572
<               $$.node_ptr=mk_binary_node(TOK_GREATER_THAN, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
682,683c576
<               $$.node_ptr=mk_binary_node(TOK_LESS_EQUAL, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
687,688c580
<               $$.node_ptr=mk_binary_node(TOK_GR_EQUAL, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
695,696c587
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
700,701c591
<               $$.node_ptr=mk_binary_node(TOK_EQ_EQUAL, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
705,706c595
<               $$.node_ptr=mk_binary_node(TOK_EXC_EQUAL, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
719c608
<               equality_expr                 %dprec 2
---
>               equality_expr              %dprec 2
721,722c610
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
724c612
<               AND_expr BITAND equality_expr %dprec 1
---
>               equality_expr AND AND_expr %dprec 1
726,727c614
<               $$.node_ptr=mk_binary_node(TOK_BIT_AND, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
731,734c618,621
<               equality_expr              %dprec 2
<                             |
<               equality_expr AND AND_expr %dprec 1
<                             ;
---
>               AND_expr AND equality_expr %dprec 1
>               {
>               cnt_rule();
>               }              ;
741,742c628
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
746,747c632
<               $$.node_ptr=mk_binary_node(TOK_BIT_XOR, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
754,755c639
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
759,760c643
<               $$.node_ptr=mk_binary_node(TOK_BIT_OR, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
767,768c650
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
772,773c654
<               $$.node_ptr=mk_binary_node(TOK_LOG_AND, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
780,781c661
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
785,786c665
<               $$.node_ptr=mk_binary_node(TOK_LOG_OR, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
793,794c672
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
798,800c676
<               $$.node_ptr=mk_binary_node(TOK_QUESTION, $1.node_ptr,
< 				mk_binary_node(TOK_COLON, $3.node_ptr, $5.node_ptr));
<               cnt_rule(yyn);
---
>               cnt_rule();
807,808c683
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
812,813c687
<               $$.node_ptr=mk_binary_node($2.tok, $1.node_ptr, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
820,821c694
<               $$.tok=TOK_EQUAL;
<               cnt_rule(yyn);
---
>               cnt_rule();
825,826c698
<               $$.tok=TOK_MULT_EQUAL;
<               cnt_rule(yyn);
---
>               cnt_rule();
830,831c702
<               $$.tok=TOK_DIV_EQUAL;
<               cnt_rule(yyn);
---
>               cnt_rule();
835,836c706
<               $$.tok=TOK_REM_EQUAL;
<               cnt_rule(yyn);
---
>               cnt_rule();
840,841c710
<               $$.tok=TOK_PLUS_EQUAL;
<               cnt_rule(yyn);
---
>               cnt_rule();
845,846c714
<               $$.tok=TOK_MIN_EQUAL;
<               cnt_rule(yyn);
---
>               cnt_rule();
850,851c718
<               $$.tok=TOK_LSH_ASSIGN;
<               cnt_rule(yyn);
---
>               cnt_rule();
855,856c722
<               $$.tok=TOK_RSH_ASSIGN;
<               cnt_rule(yyn);
---
>               cnt_rule();
860,861c726
<               $$.tok=TOK_AND_ASSIGN;
<               cnt_rule(yyn);
---
>               cnt_rule();
865,866c730
<               $$.tok=TOK_BOR_ASSIGN;
<               cnt_rule(yyn);
---
>               cnt_rule();
870,871c734
<               $$.tok=TOK_BXOR_ASSIGN;
<               cnt_rule(yyn);
---
>               cnt_rule();
878,879c741
<               $$=$1;
<               cnt_rule(yyn);
---
>               cnt_rule();
883,884c745
<               $$.node_ptr=mk_binary_node(TOK_COMMA, $1.node_ptr, $3.node_ptr);
< 	      cnt_rule(yyn);
---
>               cnt_rule();
889,893c750
<               conditional_expr
< 	      {
< 	      $$=$1;
<               cnt_rule(yyn);
< 	      }                ;
---
>               conditional_expr ;
903c760
<               cnt_rule(yyn);
---
>               cnt_rule();
907c764
<               cnt_rule(yyn);
---
>               cnt_rule();
913c770
<    In the declaration int i; the identifier i can reduce via:
---
>    In the declaration int i; can the identifier i can reduce via
915c772
<       o type-specifier to give a list of declaration specifiers
---
>       o type-specifier to give a list of declaration specifiers.
923c780
<               cnt_rule(yyn);
---
>               cnt_rule();
927c784
<               cnt_rule(yyn);
---
>               cnt_rule();
937c794
<               cnt_rule(yyn);
---
>               cnt_rule();
941c798
<               cnt_rule(yyn);
---
>               cnt_rule();
945c802
<               cnt_rule(yyn);
---
>               cnt_rule();
949c806
<               cnt_rule(yyn);
---
>               cnt_rule();
955c812
<               cnt_rule(yyn);
---
>               cnt_rule();
959c816
<               cnt_rule(yyn);
---
>               cnt_rule();
966c823
<               cnt_rule(yyn);
---
>               cnt_rule();
970c827
<               cnt_rule(yyn);
---
>               cnt_rule();
977c834
<               cnt_rule(yyn);
---
>               cnt_rule();
981,982c838
<               got_expression(INIT_EX, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
989c845
<               cnt_rule(yyn);
---
>               cnt_rule();
993c849
<               cnt_rule(yyn);
---
>               cnt_rule();
997c853
<               cnt_rule(yyn);
---
>               cnt_rule();
1001c857
<               cnt_rule(yyn);
---
>               cnt_rule();
1005c861
<               cnt_rule(yyn);
---
>               cnt_rule();
1012c868
<               cnt_rule(yyn);
---
>               cnt_rule();
1016c872
<               cnt_rule(yyn);
---
>               cnt_rule();
1020c876
<               cnt_rule(yyn);
---
>               cnt_rule();
1024c880
<               cnt_rule(yyn);
---
>               cnt_rule();
1028c884
<               cnt_rule(yyn);
---
>               cnt_rule();
1032c888
<               cnt_rule(yyn);
---
>               cnt_rule();
1036c892
<               cnt_rule(yyn);
---
>               cnt_rule();
1040c896
<               cnt_rule(yyn);
---
>               cnt_rule();
1044c900
<               cnt_rule(yyn);
---
>               cnt_rule();
1048c904
<               cnt_rule(yyn);
---
>               cnt_rule();
1052c908
<               cnt_rule(yyn);
---
>               cnt_rule();
1056c912
<               cnt_rule(yyn);
---
>               cnt_rule();
1060c916
<               cnt_rule(yyn);
---
>               cnt_rule();
1064c920
<               cnt_rule(yyn);
---
>               cnt_rule();
1068c924
<               cnt_rule(yyn);
---
>               cnt_rule();
1073c929
<               cnt_rule(yyn);
---
>               cnt_rule();
1077,1078c933
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1085c940
<               cnt_rule(yyn);
---
>               cnt_rule();
1089,1090c944
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1097c951
<               cnt_rule(yyn);
---
>               cnt_rule();
1101c955
<               cnt_rule(yyn);
---
>               cnt_rule();
1108c962
<               cnt_rule(yyn);
---
>               cnt_rule();
1112c966
<               cnt_rule(yyn);
---
>               cnt_rule();
1126c980
<               cnt_rule(yyn);
---
>               cnt_rule();
1130c984
<               cnt_rule(yyn);
---
>               cnt_rule();
1136c990
<               cnt_rule(yyn);
---
>               cnt_rule();
1140c994
<               cnt_rule(yyn);
---
>               cnt_rule();
1147c1001
<               cnt_rule(yyn);
---
>               cnt_rule();
1151c1005
<               cnt_rule(yyn);
---
>               cnt_rule();
1157c1011
<               cnt_rule(yyn);
---
>               cnt_rule();
1161c1015
<               cnt_rule(yyn);
---
>               cnt_rule();
1169c1023
<               cnt_rule(yyn);
---
>               cnt_rule();
1173,1174c1027
<               got_expression(EMPT_COLON_CE, $2.node_ptr);
< 	      cnt_rule(yyn);
---
>               cnt_rule();
1187a1041
>               cnt_rule();
1195c1049
<               cnt_rule(yyn);
---
>               cnt_rule();
1199c1053
<               cnt_rule(yyn);
---
>               cnt_rule();
1203,1204c1057
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1211c1064
<               cnt_rule(yyn);
---
>               cnt_rule();
1215c1068
<               cnt_rule(yyn);
---
>               cnt_rule();
1222,1223c1075
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1227,1229c1079
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               got_expression(ENUM_INITIAL_CE, $3.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
1236c1086
<               cnt_rule(yyn);
---
>               cnt_rule();
1240c1090
<               cnt_rule(yyn);
---
>               cnt_rule();
1244c1094
<               cnt_rule(yyn);
---
>               cnt_rule();
1251c1101
<               cnt_rule(yyn);
---
>               cnt_rule();
1256c1106
<               cnt_rule(yyn);
---
>               cnt_rule();
1260c1110
<               cnt_rule(yyn);
---
>               cnt_rule();
1266c1116
<               cnt_rule(yyn);
---
>               cnt_rule();
1267a1118
> 
1271c1122
<               cnt_rule(yyn);
---
>               cnt_rule();
1272a1124
> 
1275c1127
<               cnt_rule(yyn);
---
>               cnt_rule();
1279c1131
<               cnt_rule(yyn);
---
>               cnt_rule();
1283c1135
<               cnt_rule(yyn);
---
>               cnt_rule();
1287c1139
<               cnt_rule(yyn);
---
>               cnt_rule();
1289d1140
< /*
1292c1143
<               cnt_rule(yyn);
---
>               cnt_rule();
1296c1147
<               cnt_rule(yyn);
---
>               cnt_rule();
1298d1148
< */
1313,1314c1163
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1316c1165
<               OPEN_RND declarator CLOSE_RND  %dprec 1
---
>               OPEN_RND declarator CLOSE_RND
1318,1321c1167,1171
< /*
<    printf("( declarator )\n");
< */
<               cnt_rule(yyn);
---
>               cnt_rule();
>               }                |
>               direct_declarator OPEN_SQUARE type_qualifier_list_opt assignment_expr_opt CLOSE_SQUARE
>               {
>               cnt_rule();
1325,1326c1175
<               got_expression(DIR_DECL_EX, $5.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
1330,1331c1179
<               got_expression(DIR_DECL_EX, $5.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
1333c1181
<               direct_declarator OPEN_SQUARE type_qualifier_list_opt TIMES CLOSE_SQUARE  %dprec 2
---
>               direct_declarator OPEN_SQUARE type_qualifier_list_opt TIMES CLOSE_SQUARE
1335c1183
<               cnt_rule(yyn);
---
>               cnt_rule();
1339c1187
<               cnt_rule(yyn);
---
>               cnt_rule();
1343,1369c1191
<               direct_declarator OPEN_SQUARE type_qualifier_list_opt assignment_expr_opt CLOSE_SQUARE
<               {
<               got_expression(DIR_DECL_EX, $4.node_ptr);
<               cnt_rule(yyn);
<               }                |
<               direct_declarator OPEN_RND parameter_type_list CLOSE_RND
<               {
< /*
< 	      printf("direct_decl ( param type list )\n");
< */
<               cnt_rule(yyn);
<               }                |
< /*
<    Code written to support translators written before prototypes were
<    generally available often uses a macro based technique for switching
<    prototypes on/off.  Such usage usually involves extra matching ( and ),
<    and requires preprocessing before it is syntactically correct.
<    The following rule adds support for this syntax.
<    A rule having the form
<    
<       direct_declarator IDENTIFIER OPEN_RND OPEN_RND ...
< 
<    might be thought to closer reflect reality and improve performance.
<    However, ambiguities increase from 16 to 19 (on the book's benchmarks)
<    and there is one more reduce/reduce conflict in the grammar.
<  */
<               direct_declarator OPEN_RND OPEN_RND parameter_type_list CLOSE_RND CLOSE_RND
---
>               direct_declarator OPEN_RND parameter_type_list CLOSE_RND %dprec 2
1371c1193
<               cnt_rule(yyn);
---
>               cnt_rule();
1373,1381d1194
<               direct_declarator OPEN_RND CLOSE_RND
<               {
<               cnt_rule(yyn);
<               }                ;
< /*
<    No point using dprec to disambiguate what is essentially (from a syntax point
<    of view a rule almost a pure subset of that rule.
< 
<               direct_declarator OPEN_RND parameter_type_list CLOSE_RND %dprec 2
1384c1197
<               cnt_rule(yyn);
---
>               cnt_rule();
1386d1198
< */
1392c1204
<               cnt_rule(yyn);
---
>               cnt_rule();
1396c1208
<               cnt_rule(yyn);
---
>               cnt_rule();
1403c1215
<               cnt_rule(yyn);
---
>               cnt_rule();
1407c1219
<               cnt_rule(yyn);
---
>               cnt_rule();
1414c1226
<               cnt_rule(yyn);
---
>               cnt_rule();
1418c1230
<               cnt_rule(yyn);
---
>               cnt_rule();
1425c1237
<               cnt_rule(yyn);
---
>               cnt_rule();
1429c1241
<               cnt_rule(yyn);
---
>               cnt_rule();
1434c1246
<               cnt_rule(yyn);
---
>               cnt_rule();
1438c1250
<               cnt_rule(yyn);
---
>               cnt_rule();
1461c1273
<               cnt_rule(yyn);
---
>               cnt_rule();
1465c1277
<               cnt_rule(yyn);
---
>               cnt_rule();
1469c1281
<               cnt_rule(yyn);
---
>               cnt_rule();
1473d1284
< /*
1477,1478c1288
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1482,1483c1292
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1485d1293
< */
1491,1492c1299
<               $$.node_ptr=mk_leaf_node(TOK_TYPEOF);
<               cnt_rule(yyn);
---
>               cnt_rule();
1499,1500c1306,1307
<               cnt_rule(yyn);
<               }          |
---
>               cnt_rule();
>               }                                |
1503,1504c1310,1311
<               cnt_rule(yyn);
<               }          ;
---
>               cnt_rule();
>               } ;
1508c1315
<               cnt_rule(yyn);
---
>               cnt_rule();
1512,1513c1319,1320
<               cnt_rule(yyn);
<               }          ;
---
>               cnt_rule();
>               } ;
1516c1323
<               cnt_rule(yyn);
---
>               cnt_rule();
1520,1522c1327,1329
<               cnt_rule(yyn);
<               }          ;
< /* (6.7.6) + DR #289 update */
---
>               cnt_rule();
>               } ;
> /* (6.7.6) */
1526c1333
<               cnt_rule(yyn);
---
>               cnt_rule();
1528c1335
<               direct_abstract_declarator_opt OPEN_SQUARE type_qualifier_list_opt assignment_expr_opt CLOSE_SQUARE
---
>               direct_abstract_declarator_opt OPEN_SQUARE assignment_expr_opt CLOSE_SQUARE
1530,1541c1337
<               got_expression(DIR_ABSDECL_EX, $4.node_ptr);
<               cnt_rule(yyn);
<               }   |
<               direct_abstract_declarator_opt OPEN_SQUARE STATIC type_qualifier_list_opt assignment_expr CLOSE_SQUARE
<               {
<               got_expression(DIR_ABSDECL_EX, $5.node_ptr);
<               cnt_rule(yyn);
<               }   |
<               direct_abstract_declarator_opt OPEN_SQUARE type_qualifier_list STATIC assignment_expr CLOSE_SQUARE
<               {
<               got_expression(DIR_ABSDECL_EX, $5.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
1545c1341
<               cnt_rule(yyn);
---
>               cnt_rule();
1549c1345
<               cnt_rule(yyn);
---
>               cnt_rule();
1559,1560c1355
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1567c1362
<               $$=$1;
---
>               cnt_rule();
1571c1366
<               $$.node_ptr=mk_unary_node(TOK_OPEN_CURL, $2.node_ptr);
---
>               cnt_rule();
1575c1370
<               $$.node_ptr=mk_unary_node(TOK_OPEN_CURL, $2.node_ptr);
---
>               cnt_rule();
1580c1375
<               cnt_rule(yyn);
---
>               cnt_rule();
1584c1379
<               cnt_rule(yyn);
---
>               cnt_rule();
1590c1385
<               $$.node_ptr=mk_binary_node(TOK_ARG, $2.node_ptr, NULL);
---
>               cnt_rule();
1594,1601c1389,1390
<               $$.node_ptr=mk_binary_node(TOK_ARG, $1.node_ptr, $4.node_ptr);
<               } |
<               /* empty
<                  Extension to support an empty list so that declarations
< 		 that use a #include'd initializer list don't generate
< 		 a syntax error.
< 	      */
<                 ;
---
>               cnt_rule();
>               } ;
1607c1396
<               cnt_rule(yyn);
---
>               cnt_rule();
1614c1403
<               cnt_rule(yyn);
---
>               cnt_rule();
1618,1619c1407,1408
<               cnt_rule(yyn);
<               }                 ;
---
>               cnt_rule();
>               } ;
1625,1627c1414,1415
<               got_expression(DESIGNATOR_CE, $2.node_ptr);
<               cnt_rule(yyn);
<               }                         |
---
>               cnt_rule();
>               } |
1630,1631c1418
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1643c1430
<               cnt_rule(yyn);
---
>               cnt_rule();
1647c1434
<               cnt_rule(yyn);
---
>               cnt_rule();
1651c1438
<               cnt_rule(yyn);
---
>               cnt_rule();
1655,1675c1442
<               cnt_rule(yyn);
<               }     |
< /*
<  * OPEN_CURL, CLOSE_CURL, and ELSE are needed because
<  * we are parsing single statements and these occur in
<  * 'larger' statements.
<  */
<               OPEN_CURL
<               {
<               TRACE_LOG("{_");
<               cnt_rule(yyn);
<               }     |
<               CLOSE_CURL
<               {
<               TRACE_LOG("}_");
<               cnt_rule(yyn);
<               }     |
<               ELSE
<               {
<               TRACE_LOG("EL");
<               cnt_rule(yyn);
---
>               cnt_rule();
1679c1446
<               cnt_rule(yyn);
---
>               cnt_rule();
1686,1687c1453
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               cnt_rule(yyn);
---
>               cnt_rule();
1689c1455
<               CASE constant_expr COLON {TRACE_LOG("CA");} statement
---
>               CASE constant_expr COLON statement
1691,1694c1457,1459
<               got_expression(CASE_LAB_CE, $2.node_ptr);
<               cnt_rule(yyn);
<               }         |
<               DEFAULT COLON {TRACE_LOG("DE");} statement
---
>               cnt_rule();
>               } |
>               DEFAULT COLON statement
1696,1697c1461,1462
<               cnt_rule(yyn);
<               }         ;
---
>               cnt_rule();
>               }            ;
1721,1723c1486
<               seen_ES=TRUE;
<               got_expression(EXPR_STMT_EX, $1.node_ptr);
< 	      cnt_rule(yyn);
---
>               cnt_rule();
1736,1738c1499
< 	      TRACE_LOG("IF");
<               got_expression(IF_EXPR_EX, $3.node_ptr);
< 	      cnt_rule(yyn);
---
>               cnt_rule();
1742,1744c1503
<               TRACE_LOG("SW");
<               got_expression(SWITCH_EXPR_EX, $3.node_ptr);
< 	      cnt_rule(yyn);
---
>               cnt_rule();
1749,1750c1508
<               $$.node_ptr=NULL;
<               cnt_rule(yyn);
---
>               cnt_rule();
1754c1512
< 	      cnt_rule(yyn);
---
>               cnt_rule();
1767,1769c1525
<               TRACE_LOG("WH");
<               got_expression(WHILE_EXPR_EX, $3.node_ptr);
< 	      cnt_rule(yyn);
---
>               cnt_rule();
1773,1774c1529
<               TRACE_LOG("DO");
<               cnt_rule(yyn);
---
>               cnt_rule();
1776,1784c1531
< /*
<    The token sequence for (i ; ; ) can be parsed as
< 
<       o for (expr ;
<       o for (declaration ;
< 
<    The expression form is likely to be the only semantically valid case.
<  */
< 	      FOR OPEN_RND expr_opt SEMICOLON expr_opt SEMICOLON expr_opt CLOSE_RND %dprec 2
---
>               FOR OPEN_RND expr_opt SEMICOLON expr_opt SEMICOLON expr_opt CLOSE_RND
1786,1790c1533
<               TRACE_LOG("FO");
<               got_expression(FOR_INIT_EX, $3.node_ptr);
<               got_expression(FOR_CNTRL_EX, $5.node_ptr);
<               got_expression(FOR_INC_EX, $7.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
1792c1535
<               FOR OPEN_RND declaration expr_opt SEMICOLON expr_opt CLOSE_RND %dprec 1
---
>               FOR OPEN_RND declaration expr_opt SEMICOLON expr_opt CLOSE_RND
1794,1797c1537
<               TRACE_LOG("FO");
<               got_expression(FOR_CNTRL_EX, $4.node_ptr);
<               got_expression(FOR_INC_EX, $6.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
1804,1806c1544
<               $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
<               TRACE_LOG("GO");
<               cnt_rule(yyn);
---
>               cnt_rule();
1810,1811c1548
<               TRACE_LOG("CO");
<               cnt_rule(yyn);
---
>               cnt_rule();
1815,1816c1552
<               TRACE_LOG("BR");
<               cnt_rule(yyn);
---
>               cnt_rule();
1820,1822c1556
<               TRACE_LOG("RE");
<               got_expression(RETURN_EX, $2.node_ptr);
<               cnt_rule(yyn);
---
>               cnt_rule();
1831c1565
<               cnt_rule(yyn);
---
>               cnt_rule();
1835,1836c1569
<               seen_DC=TRUE;
<               cnt_rule(yyn);
---
>               cnt_rule();
1841c1574
<               cnt_rule(yyn);
---
>               cnt_rule();
1845c1578
<               cnt_rule(yyn);
---
>               cnt_rule();
1850,1861d1582
< 
<    In the following:
< 
<       usr_type_1 x;
<       usr_type_2 y = foo;
<       if ( z )
< 
<    the first two declarations are sometimes parsed as if they were part of
<    a declaration_list_opt in a function header.  Changing declarator to
<    fndef_declarator requires that some ( ) appear in one of the declarations
<    (which can happen if the variable being declared is bracketed by redundant
<    parenthesis).
1867,1877c1588,1589
< 	      TRACE_LOG("FD");
<               cnt_rule(yyn);
<               }                    |
< /*
<    The following production is not in C99, but was in C90.
<  */
<                                      fndef_declarator declaration_list_opt OPEN_CURL
<               {
< 	      TRACE_LOG("FD");
<               cnt_rule(yyn);
<               }                    ;
---
>               cnt_rule();
>               } ;
1883c1595
<               cnt_rule(yyn);
---
>               cnt_rule();
1887c1599
<               cnt_rule(yyn);
---
>               cnt_rule();
