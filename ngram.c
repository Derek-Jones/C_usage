                    /* ngram.c,  8 Apr 21 */

/*
 * Count constructs in the visible form of C source code.
 *
 * Written by Derek Jones to obtain typical developer usage
 * information for the 'cultural' aspects of the book
 * "The New C Standard: An economic and cultural commentary".
 *
 * Copyright (c) 2001-2005 Knowledge Software Ltd
 *
 This software is licensed under the terms of the GNU
 General Public License version 2 as published by the
 Free Software Foundation.
 
 It is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this software; see the file COPYING.  If not, write to
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.
 */

/*
    8 Apr 21 DJ Added support for print_line_info
   17 Sep 07 DJ Support C++ keywords and ::
    2 Nov 06 DJ TOK_T_DEF_NAME not needed as a token
   12 Mar 05 DJ Minor updates
   26 Aug 03 DJ Initial release
 */

/*
 * The economic requirements for the production of this software
 * were driven by the need to produce data for use in a book.  A
 * cost/benefit analysis showed that it was not worthwhile investing
 * time during production to save time later, after the book had been
 * published, on maintenance.  Enjoy.
 */

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ngutil.h"
#include "nprint.h"

#define NGRAM_DEBUG 0

void get_token(void);

char *cur_out_file;
int cur_direct_cnt,
    square_nesting,
    keyword_bigram[MAX_TOK+1][MAX_TOK+1],
    pp_if_depth[MAX_PP_IF_DEPTH],
    pp_if_line_cnt[MAX_PP_IF_LINES],
    pp_direct_cnt[MAX_PP_DIRECT_CNT],
    paren_info[MAX_PAREN_NESTING],
    square_info[MAX_SQUARE_NESTING],
    cases_per_switch[MAX_CASES_PER_SWITCH],
    block_nest[MAX_BLOCK_NEST],
    sp_tok_sp[6][MAX_TOK_KINDS]
    ;

#include "ngutil.c"
#include "lexer.c"
#include "nprint.c"


void do_pp_directive(void)
/*
 * Process the token sequences making up a preprocessing
 * directive (a # has been encountered at the start of a line).
 */
{
BOOL print_token = FALSE;

cur_direct_cnt++;
cur_src_direct_cnt++;
in_pp_directive=TRUE;
start_hdefine=FALSE;
if (!feof(stdin))
   {
   just_seen_hash=TRUE;
   get_token();
   just_seen_hash=FALSE;

   switch (cur_tok)
      {
      case TOK_INCLUDE:
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_include[0]++;
		     break;

      case TOK_DEFINE:
		     if (print_pp_direct)
		        {
			printf("%s ", tokens[cur_tok]);
			print_token=TRUE;
			}
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_define[0]++;
		     start_hdefine=TRUE;
		     break;

      case TOK_UNDEF:
		     if (print_pp_direct)
		        {
			printf("%s ", tokens[cur_tok]);
			print_token=TRUE;
			}
		     break;

      case TOK_LINE:
		     if (print_pp_direct)
		        {
			printf("%s ", tokens[cur_tok]);
			print_token=TRUE;
			}
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_pp_line++;
		     break;

      case TOK_ERROR:
		     if (print_pp_direct)
		        {
			printf("%s ", tokens[cur_tok]);
			print_token=TRUE;
			}
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_pp_error++;
		     break;

      case TOK_PRAGMA:
		     if (print_pp_direct)
		        {
			printf("%s ", tokens[cur_tok]);
			print_token=TRUE;
			}
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_pp_pragma++;
		     break;

      case TOK_H_IF:
/*
printf("%d #if\n", cur_pp_if_depth);
*/
		     in_h_if=TRUE;
		     if (print_pp_direct)
		        {
			printf("%s\n", tokens[cur_tok]);
			}
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_pp_if++;
		     if (cur_pp_if_depth == 0)
		        {
			cur_pp_line_cnt=0;
			cur_direct_cnt=0;
			}
		     cur_pp_if_depth++;
		     if (cur_pp_if_depth < MAX_PP_IF_DEPTH)
		        pp_if_depth[cur_pp_if_depth]++;
		     if (cur_pp_if_depth > 8)
		        printf("pp if depth=%d\n", cur_pp_if_depth);
		     break;

      case TOK_IFDEF:
      case TOK_IFNDEF:
		     /*
		     printf("%d #ifdef\n", cur_pp_if_depth);
		     */
		     if (print_pp_direct)
		        {
			printf("%s ", tokens[cur_tok]);
			print_token=TRUE;
			}
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_pp_ifdef++;
		     if (cur_pp_if_depth == 0)
		        {
			cur_pp_line_cnt=0;
			cur_direct_cnt=0;
			}
		     cur_pp_if_depth++;
		     if (cur_pp_if_depth < MAX_PP_IF_DEPTH)
		        pp_if_depth[cur_pp_if_depth]++;
		     break;

      case TOK_ELIF:
		     in_h_if=TRUE;
		     if (print_pp_direct)
		        {
			printf("%s\n", tokens[cur_tok]);
			}
		     break;

      case TOK_H_ELSE:
		     if (print_pp_direct)
		        {
			printf("%s\n", tokens[cur_tok]);
			}
		     if (cur_src_line_cnt < MAX_SRC_LINES)
		        src_line_info[cur_src_line_cnt].num_pp_else++;
		     break;

      case TOK_ENDIF:
		     /*
		     printf("%d #endif\n", cur_pp_if_depth);
		     */
		     if (print_pp_direct)
		        {
			printf("%s\n", tokens[cur_tok]);
			}
		     if (cur_pp_if_depth > 0)
		        cur_pp_if_depth--;
		     if (cur_pp_if_depth == 0)
		        {
			/*
			 * Subtract off outermost #if/#endif lines
			 */
			cur_pp_line_cnt--;
			if (cur_pp_line_cnt < MAX_PP_IF_LINES-1)
			   pp_if_line_cnt[cur_pp_line_cnt]++;
			else
			   pp_if_line_cnt[MAX_PP_IF_LINES-1]++;
			cur_direct_cnt--;
			if (cur_direct_cnt < MAX_PP_DIRECT_CNT-1)
			   pp_direct_cnt[cur_direct_cnt]++;
			else
			   pp_direct_cnt[MAX_PP_DIRECT_CNT-1]++;
			}
		     break;
      }
   }
/*
 * Process to end of logical line
 */
while (!feof(stdin))
   {
   prev_class_templ=seen_class_templ;
   seen_class_templ=FALSE;
   get_token();
   if (print_token)
      {
      print_token=FALSE;
      printf("%s\n", ident_str);
      }
   if (last_was_log_newline)
      break;
   if (prev_class_templ && chk_cpp &&
       ((cur_tok == TOK_IDENTIFIER) || (cur_tok == TOK_OPEN_CURL)))
      total_class_templ[cur_pp_if_depth != 0]++;
   }
if (print_pp_body)
   printf("\n");
in_pp_directive=FALSE;
in_h_if=FALSE;
prev_class_templ=FALSE;
seen_class_templ=FALSE;
}


int main(int argc, char **argv)
{
/*
 * Various command line arguments
 */
if (argc > 1)
   {
   if ((strcmp(argv[1], "?") == 0) ||
       (strcmp(argv[1], "help") == 0) ||
       (strcmp(argv[1], "-help") == 0) ||
       (strcmp(argv[1], "-v") == 0) ||
       (strcmp(argv[1], "-V") == 0))
      {
      printf("Options: block cpp control declinfo enum exprstmt idents for lineinfo ppdirect ppbody punct strlit verify\n");
      exit(0);
      }
   print_line_info= (strcmp(argv[1], "lineinfo") == 0);
   print_block= (strcmp(argv[1], "block") == 0);
   chk_cpp= (strcmp(argv[1], "cpp") == 0);
   print_cntrl_expr= (strcmp(argv[1], "control") == 0);
   print_declinfo= (strcmp(argv[1], "declinfo") == 0);
   print_enum= (strcmp(argv[1], "enum") == 0);
   print_expr_stmt= (strcmp(argv[1], "exprstmt") == 0);
   print_idents= (strcmp(argv[1], "idents") == 0);
   print_puncts= (strcmp(argv[1], "punct") == 0);
   print_for_cntrl_expr= (strcmp(argv[1], "for") == 0);
   print_pp_direct= (strcmp(argv[1], "ppdirect") == 0);
   print_pp_body= (strcmp(argv[1], "ppbody") == 0);
   print_strlit= (strcmp(argv[1], "strlit") == 0);
   verify_mode= (strcmp(argv[1], "verify") == 0);
   }

tokens[_AT_] = "_AT_";
tokens[TOK_SPACE] = "SPACE";
tokens[TOK_NEW_LINE] = "NEW_LINE";
tokens[TOK_LINE_START] = "LINE_START";
tokens[CHAR_CONST] = "CHAR_CONST";
tokens[COMMENT] = "COMMENT";
tokens[INTEGER_CONST] = "INT_CONST";
tokens[FLOAT_CONST] = "FLOAT_CONST";
tokens[HASH_HASH] = "##";
tokens[HASH] = "#";
tokens[COMMENT_NL] = "COMMENT_NL";
tokens[CPP_COMMENT] = "CPP_COMMENT";
tokens[STRING_CONST] = "STRING";
tokens[HEADER_NAME] = "HEADER";

end_of_file();
next_ch();

if (print_line_info)
   {
   start_file("lineinfo.d");
   printf("characters indentation tokens idents in_pp_directive last_tok_splice\n");
   }

/*
 * TODO
 * #if as first line of file
 */
while (!feof(stdin))
   {
   prev_class_templ=seen_class_templ;
   seen_class_templ=FALSE;
   get_token();
   if (last_was_log_newline)
      while (cur_tok == HASH)
         do_pp_directive();
   keyword_bigram[prev_keyword][cur_tok]++;
   /*
    * Various tokens that affect how what is
    * counted, or the state (i.e., the C syntactic construct)
    * ngram thinks it is in.
    */
   switch (cur_tok)
      {
      case TOK_IDENTIFIER:
                          if (prev_class_templ && chk_cpp)
                             total_class_templ[cur_pp_if_depth != 0]++;
			  break;

      case TOK_OPEN_CURL: cur_block_nest++;
		          if (cur_block_nest < MAX_BLOCK_NEST)
			     block_nest[cur_block_nest]++;
			  /* simple error recovery */
			  seen_cntrl_hdr=FALSE;
			  seen_for_cntrl_hdr=FALSE;
			  paren_nesting=0;
			  square_nesting=0;
                          if (prev_class_templ && chk_cpp)
                             total_class_templ[cur_pp_if_depth != 0]++;
			  break;

      case TOK_CL_CURL: 
			if (cur_block_nest > 0)
			   cur_block_nest--;
			close_curl_output();
			/* simple error recovery */
			seen_cntrl_hdr=FALSE;
			seen_for_cntrl_hdr=FALSE;
			paren_nesting=0;
		        square_nesting=0;
			if (seen_enum_hdr)
			   {
			   seen_enum_hdr=FALSE;
			   print_int_cons=FALSE;
			   printf("\n");
			   }
			if (seen_esu_hdr && (cur_block_nest == 0))
			   {
			   seen_esu_hdr=FALSE;
			   print_int_cons=FALSE;
			   printf("\n");
			   }
			break;

      case TOK_SEMICOLON:
			semicolon_output();
		        square_nesting=0;
			/* simple error recovery */
			if (!seen_for_cntrl_hdr)
			   paren_nesting=0;
			if (seen_enum_hdr)
			   {
			   seen_enum_hdr=FALSE;
			   print_int_cons=FALSE;
			   printf("\n");
			   }
			if (seen_esu_hdr)
			   {
			   seen_esu_hdr=FALSE;
			   print_int_cons=FALSE;
			   printf("\n");
			   }
		        break;

      case TOK_SWITCH:
			switch_output();
			paren_nesting=0;
			seen_cntrl_hdr=TRUE;
			if (print_cntrl_expr)
			   printf("%s ( ", tokens[cur_tok]);
		        break;

      case TOK_CASE:
			case_output();
		        break;

      case TOK_COLON:
			last_tok_case=FALSE;
		        break;

      case TOK_DEFAULT:
			default_output();
		        break;

      case TOK_OPEN_RND:
		        paren_nesting++;
			if (paren_nesting < MAX_PAREN_NESTING)
			   paren_info[paren_nesting]++;
			break;

      case TOK_CL_RND:
		        if (paren_nesting > 0)
			   paren_nesting--;
			if (paren_nesting == 0)
			   {
			   if ((print_for_cntrl_expr && seen_for_cntrl_hdr) ||
			       (print_cntrl_expr && seen_cntrl_hdr))
			      printf("\n");
			   seen_cntrl_hdr=FALSE;
			   seen_for_cntrl_hdr=FALSE;
			   }
			break;

      case TOK_OPEN_SQUARE: 
			square_nesting++;
			if (square_nesting < MAX_SQUARE_NESTING)
			   square_info[square_nesting]++;
			break;

      case TOK_CL_SQUARE: 
			if (square_nesting > 0)
			   square_nesting--;
			break;

      case TOK_FOR:
			seen_for_cntrl_hdr=TRUE;
			seen_cntrl_hdr=TRUE;
			paren_nesting=0;
			if (print_for_cntrl_expr || print_cntrl_expr)
			   printf("%s ( ", tokens[cur_tok]);
			break;

      case TOK_IF:
      case TOK_WHILE:
			seen_cntrl_hdr=TRUE;
			paren_nesting=0;
			if (print_cntrl_expr)
			   printf("%s ( ", tokens[cur_tok]);
		        break;

      case TOK_STRUCT:
      case TOK_UNION:
			if (print_declinfo)
			   {
			   seen_esu_hdr=TRUE;
			   printf("%s ", tokens[cur_tok]);
			   }
		        break;

      case TOK_ENUM:
			if (print_enum)
			   {
			   seen_enum_hdr=TRUE;
			   printf("%s ", tokens[cur_tok]);
			   }
			if (print_declinfo)
			   {
			   print_int_cons=TRUE;
			   seen_esu_hdr=TRUE;
			   printf("%s ", tokens[cur_tok]);
			   }
		        break;

      case TOK_COLONCOLON:
                        total_coloncolon[cur_pp_if_depth != 0]++;
                        break;
      }

   switch (cur_tok)
      {
      case TOK__BOOL:
      case TOK__COMPLEX:
      case TOK__IMAGINARY:
      case TOK_AUTO:
      case TOK_STATIC:
      case TOK_EXTERN:
      case TOK_REGISTER:
      case TOK_TYPEDEF:
      case TOK_CHAR:
      case TOK_FLOAT:
      case TOK_DOUBLE:
      case TOK_INT:
      case TOK_SHORT:
      case TOK_LONG:
      case TOK_UNSIGNED:
      case TOK_SIGNED:
      case TOK_VOID:
      case TOK_CONST:
      case TOK_VOLATILE:
      case TOK_STRUCT:
      case TOK_UNION:
      case TOK_ENUM:
      case TOK_IF:
      case TOK_ELSE:
      case TOK_WHILE:
      case TOK_FOR:
      case TOK_DO:
      case TOK_SWITCH:
      case TOK_CASE:
      case TOK_DEFAULT:
      case TOK_BREAK:
      case TOK_CONTINUE:
      case TOK_RETURN:
      case TOK_GOTO:
      case TOK_INLINE:
      case TOK_RESTRICT:
      
      case TOK_PASCAL:
      case TOK_FORTRAN:
      case TOK_PPASM  :
      case TOK_ATTRIBUTE:
      case TOK_TYPEOF:
      case TOK_ALIGNOF:

			  prev_keyword=cur_tok;
			  break;

      case TOK_OPEN_CURL:
      case TOK_CL_CURL:
			  prev_keyword=cur_tok;
			  prev_punct=cur_tok;
			  break;

      case TOK_SEMICOLON:
			prev_punct=cur_tok;
			if ((prev_keyword == TOK_IF) ||
			    (prev_keyword == TOK_ELSE) ||
			    (prev_keyword == TOK_WHILE) ||
			    (prev_keyword == TOK_FOR) ||
			    (prev_keyword == TOK_DO) ||
			    (prev_keyword == TOK_SWITCH) ||
			    (prev_keyword == TOK_OPEN_CURL) ||
			    (prev_keyword == TOK_CASE) ||
			    (prev_keyword == TOK_DEFAULT))
			  prev_keyword=TOK_EXPR_STMT;

			break;

      case TOK_OPEN_RND:
      case TOK_CL_RND:
      case TOK_ELLIPSIS:
			prev_punct=cur_tok;
			break;

      case TOK_COMMA:
      case TOK_COLON:
			prev_op=cur_tok;
			prev_punct=cur_tok;
			break;

      case TOK_SIZEOF:
      case TOK_LSHIFT:
      case TOK_RSHIFT:
      case TOK_PLUS:
      case TOK_ADD:
      case TOK_ARITH_NEG:
      case TOK_MINUS:
      case TOK_STAR:
      case TOK_TIMES:
      case TOK_REMAINDER:
      case TOK_DIVIDE:
      case TOK_BIT_XOR:
      case TOK_ADDR:
      case TOK_BIT_AND:
      case TOK_BIT_OR:
      case TOK_BIT_NOT:
      case TOK_LOG_NOT:
      case TOK_LESS_THAN:
      case TOK_LESS_EQUAL:
      case TOK_GR_EQUAL:
      case TOK_GREATER_THAN:
      case TOK_EQ_EQUAL:
      case TOK_EXC_EQUAL:
      case TOK_LOG_AND:
      case TOK_LOG_OR:
      case TOK_QUESTION:
      case TOK_DIR_SELECT:
      case TOK_INDIR_SELECT:
      case TOK_PRE_PLUS:
      case TOK_PRE_MINUS:
      case TOK_OPEN_SQUARE:
      case TOK_CL_SQUARE:
      case TOK_EQUAL:
      case TOK_PLUS_EQUAL:
      case TOK_MIN_EQUAL:
      case TOK_MULT_EQUAL:
      case TOK_LSH_ASSIGN:
      case TOK_RSH_ASSIGN:
      case TOK_AND_ASSIGN:
      case TOK_DIV_EQUAL:
      case TOK_REM_EQUAL:
      case TOK_BOR_ASSIGN:
      case TOK_BXOR_ASSIGN:
			prev_op=cur_tok;
			break;
      
      case TOK_LITERAL:
      case TOK_IDENTIFIER:
      
      case TOK_H_IF:
      case TOK_H_ELSE:
      case TOK_ELIF:
      case TOK_LINE:
      case TOK_ENDIF:
      case TOK_ERROR:
      case TOK_IFDEF:
      case TOK_PRAGMA:
      case TOK_DEFINED:
      case TOK_INCLUDE:
      case TOK_DEFINE:
      case TOK_IFNDEF:
      case TOK_UNDEF:
			break;
      }
   }

if (print_line_info)
   {
   end_file("lineinfo.d");
   }

if (chk_cpp)
   print_cpp();

if (!(print_idents ||
      print_puncts ||
      print_cntrl_expr ||
      print_for_cntrl_expr ||
      print_pp_body ||
      print_pp_direct ||
      print_enum ||
      print_declinfo ||
      print_expr_stmt ||
      print_block ||
      print_strlit))
   print_results();

return 0;
}
