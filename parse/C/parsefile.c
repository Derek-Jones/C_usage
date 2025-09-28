                    /* parsefile.c, 20 Aug 12 */

/*
 * Count constructs in the visible form of C source code.
 *
 * Written by Derek Jones to obtain typical developer usage
 * information for the 'cultural' aspects of the book
 * "The New C Standard: An economic and cultural commentary".
 *
 * Copyright (c) 2001-2005 Knowledge Software Ltd
 *
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

#define STMT_PARSING 1

#define STMT_DEBUG 0
#define YYDEBUG 1

#define MAX_GRAM_RULES 300
#define TOK_SEEN_BUF_LEN 20

#include "global.h"
#include "singlefile.h"
#include "lex.h"
#include "parser.h"
#include "count.h"
#include "print.h"
#include "dispexp.h"
#include "stgrep.h"
#include "analyse.h"
#include "parsefile.h"

#define TRACE_LOG(str) if (print_block) \
			  printf(str "\n")

char *cur_out_file;
BOOL do_print_stmt,
     print_parse_error = FALSE,
     print_prepro,
     disp_rule_reduce,
     seen_term_tok,
     have_pushed_tok,
     in_dead_code,
     in_for_struct
     ;
int prev_tok_seen,
    cur_token,
    last_token,
    tok_seen_ind,
    pushed_back_tok,
    cur_pp_if_depth,
    dead_pp_if_depth,
    cur_direct_cnt,
    curl_nesting,
    paren_nesting
    ;
int token_seen_buf[TOK_SEEN_BUF_LEN];

int rule_cnt[];
char *local_filename;


static void get_next_token(void);


void print_filename(void)
{
printf("%s %d\n", local_filename, cur_src_line_cnt);
}


void cnt_rule(int rule_num)
{
if (disp_rule_reduce)
   printf("cnt_rule %d\n", rule_num-1);
rule_cnt[rule_num-1]++;
}


void do_pp_directive(void)
/*
 * Process the token sequences making up a preprocessing
 * directive (a # has been encountered at the start of a line).
 */
{
if (print_prepro)
   TRACE_LOG("PP");
in_pp_directive=TRUE;
last_was_log_newline=FALSE;

if (file_bytes_read != 0)
   {
   just_seen_hash=TRUE;
   get_next_token();
   just_seen_hash=FALSE;

   switch (cur_token)
      {
      case TOK_INCLUDE:
		     break;

      case TOK_DEFINE:
		     break;

      case TOK_UNDEF:
      case TOK_LINE:
      case TOK_ERROR:
      case TOK_PRAGMA:
		     break;

      case TOK_IF:
		     in_h_if=TRUE;
		     if (!in_dead_code)
		        {
			get_next_token();
			if ((cur_token == TOK_LITERAL) &&
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
		     in_h_if=TRUE;
		     break;

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
while (file_bytes_read != 0)
   {
   get_next_token();
   if (last_was_log_newline)
      break;
   }
in_pp_directive=FALSE;
in_h_if=FALSE;
}


void push_cur_token(void)
{
have_pushed_tok=TRUE;
pushed_back_tok=cur_token;
cur_token=TOK_EOF;
token_seen_buf[tok_seen_ind]=TOK_EOF;
}


void get_next_token(void)
{
if (seen_term_tok)
   cur_token=TOK_EOF;
else
   {
   if (have_pushed_tok)
      {
      have_pushed_tok=FALSE;
      cur_token=pushed_back_tok;
      }
   else
      {
      if (last_was_log_newline)
         while (next_token == HASH)
            do_pp_directive();
      cur_token=next_token;
      get_token();
      }
   }
if (cur_token == TOK_IDENTIFIER)
   push_ident(ident_str);
else if (cur_token == TOK_LITERAL)
   push_number(lit_valu);
else if (cur_token == TOK_STRING_LIT)
   push_string('"');
/*
else
   push_float(1.0);
*/
tok_seen_ind++;
if (tok_seen_ind == TOK_SEEN_BUF_LEN)
   tok_seen_ind=0;
token_seen_buf[tok_seen_ind]=cur_token;
}


int yylex(void)
{
/*
 * Simulate an end-of-input because this causes the parser to behave
 * differently than if the token that happened to follow the semicolon
 * was returned.  Returning the token following the semicolon often
 * results in the parser behaving as expected, but sometimes strange
 * syntax errors occur or the default behavior is to pick (often the
 * wrong one) one of the multiple parse stacks without using any of the
 * %dprec or %merge options.
 */
/*
if ((last_token == TOK_SEMICOLON) && !in_for_struct)
   {
   last_token=TOK_EOF;
   get_next_token();
   return TOK_EOF;
   }
*/
get_next_token();
last_token=cur_token;
in_for_struct |= (cur_token == TOK_FOR) ||
                 (cur_token == TOK_STRUCT ) ||
                 (cur_token == TOK_UNION );
if (cur_token == TOK_EOF)
   return TOK_EOF;
else
   return 161+cur_token;
}


void print_tok_buf(void)
{
int tok_ind;

printf("> ");
for (tok_ind=tok_seen_ind+1; tok_ind < TOK_SEEN_BUF_LEN; tok_ind++)
   if (token_seen_buf[tok_ind] == TOK_EOF)
      printf("\n> ");
   else
      printf(" %s", tokens[token_seen_buf[tok_ind]]);
for (tok_ind=0; tok_ind <= tok_seen_ind; tok_ind++)
   if (token_seen_buf[tok_ind] == TOK_EOF)
      printf("\n> ");
   else
      printf(" %s", tokens[token_seen_buf[tok_ind]]);
printf("\n");
}


void yyerror (const char *s)  /* Called by yyparse on error */
{
if (seen_term_tok)
   push_cur_token();
else
   {
   if (print_parse_error)
      {
      if (!in_dead_code)
         printf ("Error : %s\n", s);
      print_tok_buf();
#if 1
      print_input_buf();
#endif
      }
   while ((cur_token != TOK_SEMICOLON) &&
          (cur_token != TOK_CL_CURL) &&
          (file_bytes_read != 0))
      {
   // printf("%d ", cur_token);
      get_next_token();
      }
   get_next_token();
   }
}

void print_stmt(char *stmt)
{
if (do_print_stmt)
   printf("%s\n", stmt);
}


#include "cbook.tab.c"

int rule_cnt[YYNRULES];

void print_rules_reduced(void)
{
int rindex;

for (rindex=0; rindex < YYNRULES; rindex++)
   printf("%6d %10d\n", rindex, rule_cnt[rindex]);
}


void parse_file(get_buff_func_type get_buff_func,
		  char *filename)
{
next_token=TOK_EOF;
in_dead_code=FALSE;
have_pushed_tok=FALSE;
cur_token=TOK_EOF;
local_filename=filename;

init_lex_new_file(get_buff_func);

/*
 * TODO
 * #if as first line of file
 */
init_parse();
get_next_token();
while (file_bytes_read != 0)
   {
   seen_term_tok=FALSE;

#if STMT_DEBUG
printf(">%d %s< ", cur_src_line_cnt, tokens[cur_token]);
#endif
   /*
    * Attempt to parse the source a statement or declaration at a time.
    */
   if (do_cnt_expr)
      init_cnt_expr_op();
   yyparse();
   init_parse();
   in_for_struct=FALSE;
   last_token=TOK_EOF;

   /*
    * An ambiguous parse may result in one more token being read
    * than is needed.  This token will be part of the next
    * statement/declaration and needs to be pushed back so that
    * it is available again.  Because seen_term_tok won't have
    * been set in time cur_token won't be set to TOK_EOF.
    */
   if (cur_token != TOK_EOF)
      push_cur_token();
   }

// print_usage(TRUE);
}


void init_parsefile(void)
{
yydebug=0;

}

