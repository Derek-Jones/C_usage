                    /* stmt.c, 14 Mar 05 */

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

#define YYSTYPE char const *

#define STMT_PARSING 1

#define STMT_DEBUG 0
#define YYDEBUG 1

#define MAX_GRAM_RULES 300

char *cur_out_file;
BOOL seen_term_tok,
     in_dead_code
     ;
int prev_tok_seen,
    pushed_back_tok,
    dead_pp_if_depth,
    cur_direct_cnt,
    curl_nesting,
    paren_nesting
    ;

int rule_cnt[];

#include "ngutil.c"
#include "lexer.c"

extern int yydebug;
void do_pp_directive(void);

void cnt_rule(int rule_num)
{
rule_cnt[rule_num-1]++;
}
     
void push_tok(void)
{
pushed_back_tok=cur_tok;
cur_tok=prev_tok_seen;
}

void next_token(void)
{
if (pushed_back_tok == TOK_EOF)
   get_token();
else
   {
   cur_tok=pushed_back_tok;
   pushed_back_tok=TOK_EOF;
   }
}

YYSTYPE multiplicative_merge(YYSTYPE parse_1, YYSTYPE parse_2)
{  
printf("%s : %s\n", parse_1, parse_2);
return parse_1;
}

YYSTYPE additive_merge(YYSTYPE parse_1, YYSTYPE parse_2)
{  
printf("%s + %s\n", parse_1, parse_2);
return parse_1;
}

void yyerror (const char *s)  /* Called by yyparse on error */
{
if (seen_term_tok)
   push_tok();
else
   {
   if (!in_dead_code)
      printf ("Error : %s\n", s);
   while ((cur_tok != TOK_SEMICOLON) &&
          (cur_tok != TOK_OPEN_CURL) &&
          !feof(stdin))
      next_token();
   next_token();
   }
}

int yylex(void)
{
/*
 * get_token has been called to find the first token before
 * yyparse (which calls yylex) is called.
 */
if (seen_term_tok || (cur_tok == TOK_EOF))
   return TOK_EOF;
prev_tok_seen=cur_tok;

do
   {
   next_token();
   if (last_was_log_newline)
      while (cur_tok == HASH)
         do_pp_directive();
   }
   while ((cur_tok == COMMENT) || (cur_tok == CPP_COMMENT) ||
          (cur_tok == COMMENT_NL) || (cur_tok == TOK_NEW_LINE));

#if STMT_DEBUG
printf("%s ", tokens[prev_tok_seen]);
#endif

return prev_tok_seen+161;
}

#include "cbook.tab.c"

int rule_cnt[YYNRULES];

void parse_decl(void)
{
yyparse();
}


void parse_struct_union(void)
{
yyparse();
}


void parse_expr(void)
{
yyparse();
}


void parse_for(void)
{
yyparse();
}


void parse_isw(void)
{
yyparse();
}


void parse_stmt(void)
{
yyparse();
}


void do_pp_directive(void)
/*
 * Process the token sequences making up a preprocessing
 * directive (a # has been encountered at the start of a line).
 */
{
in_pp_directive=TRUE;
start_hdefine=FALSE;
if (!feof(stdin))
   {
   just_seen_hash=TRUE;
   next_token();
   just_seen_hash=FALSE;

   switch (cur_tok)
      {
      case TOK_INCLUDE:
		     break;

      case TOK_DEFINE:
		     start_hdefine=TRUE;
		     break;

      case TOK_UNDEF:
      case TOK_LINE:
      case TOK_ERROR:
      case TOK_PRAGMA:
		     break;

      case TOK_IF:
		     if (!in_dead_code)
		        {
			next_token();
			if ((cur_tok == TOK_LITERAL) &&
			    (lit_valu == 0))
			   {
			   in_dead_code=TRUE;
			   dead_pp_if_depth=0;
			   }
			}
		     dead_pp_if_depth++;
		     cur_pp_if_depth++;
		     break;

      case TOK_IFDEF:
      case TOK_IFNDEF:
		     dead_pp_if_depth++;
		     cur_pp_if_depth++;
		     break;

      case TOK_ELIF:
      case TOK_ELSE:
		     break;

      case TOK_ENDIF:
		     if (cur_pp_if_depth > 0)
		        cur_pp_if_depth--;
		     dead_pp_if_depth--;
		     if (dead_pp_if_depth == 0)
		        in_dead_code=FALSE;
		     break;
      }
   }
/*
 * Process to end of logical line
 */
while (!feof(stdin))
   {
   next_token();
   if (last_was_log_newline)
      break;
   }
in_pp_directive=FALSE;
}

void print_results(void)
{
int rindex;

for (rindex=0; rindex < YYNRULES; rindex++)
   printf("%6d %10d\n", rindex, rule_cnt[rindex]);
}

int main(int argc, char **argv)
{
yydebug=0;
pushed_back_tok=TOK_EOF;
in_dead_code=FALSE;

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
      printf("Supported options include: idents control for ppbody ppdirect strlit enum declinfo\n");
   print_block= (strcmp(argv[1], "block") == 0);
   }

/*
 * TODO
 * #if as first line of file
 */
get_token();
while (!feof(stdin))
   {
   if (last_was_log_newline)
      while (cur_tok == HASH)
         do_pp_directive();
   /*
    * Attempt to parse the source a statement or declaration at a time.
    */
   seen_term_tok=FALSE;
#if STMT_DEBUG
printf(">%d %s< ", cur_src_line_cnt, tokens[cur_tok]);
#endif
   switch (cur_tok)
      {
      case TOK_OPEN_CURL:
		          printf("OC\n");
			  next_token();
			  break;

      case TOK_CL_CURL: 
		        printf("CC\n");
			next_token();
			break;

      case TOK_FOR:
			parse_for();
			break;

      case TOK_SWITCH:
      case TOK_IF:
      case TOK_WHILE:
			parse_isw();
			break;

      case TOK_DO:
			/*
			   TODO
			 */
			next_token();
      			break;

      case TOK_ELSE:
		        printf("EL\n");
			next_token();
      			break;

      case TOK_STRUCT:
      case TOK_UNION:
			parse_struct_union();
		        break;

      case TOK__BOOL:
      case TOK__COMPLEX:
      case TOK__IMAGINARY:
      case TOK_INLINE:
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
      case TOK_RESTRICT:
      case TOK_ENUM:
			parse_decl();
			break;

      case TOK_CASE:
      case TOK_DEFAULT:
			next_token();
			while ((cur_tok != TOK_COLON) &&
			       !feof(stdin))
			   next_token();
			next_token();
			break;

      case TOK_BREAK:
      case TOK_CONTINUE:
      case TOK_RETURN:
      case TOK_GOTO:
      case TOK_OPEN_RND:
      case TOK_SIZEOF:
      case TOK_ADD:
      case TOK_MINUS:
      case TOK_TIMES:
      case TOK_BIT_AND:
      case TOK_PRE_PLUS:
      case TOK_PRE_MINUS:
      case TOK_IDENTIFIER:
      case TOK_SEMICOLON:
			parse_stmt();
			break;

      case TOK_NEW_LINE:
      case COMMENT:
      case CPP_COMMENT:
      case COMMENT_NL: do
			  next_token();
			  while ((cur_tok == COMMENT) ||
			         (cur_tok == CPP_COMMENT) ||
			         (cur_tok == COMMENT_NL) ||
				 (cur_tok == TOK_NEW_LINE));
		       break;

      case TOK_PASCAL:
      case TOK_FORTRAN:
      case TOK_PPASM:
      case TOK_ATTRIBUTE:
      
      default :
#if STMT_DEBUG
printf("Skipping %s\n", tokens[cur_tok]);
#endif
      		next_token();
		while ((cur_tok != TOK_SEMICOLON) &&
		       (cur_tok != TOK_OPEN_CURL) &&
		       !feof(stdin))
		   next_token();
		break;
      }

   }

/*
print_results();
*/

return 0;
}
