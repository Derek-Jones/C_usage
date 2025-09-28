                    /* sgrep.c, 27 May 06 */

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SGREP_DEBUG 1

#define TOK_SEEN_BUF_LEN 20

#include "ngutil.h"
#include "lex.h"

char *cur_out_file;
BOOL do_print_stmt,
     disp_results,
     disp_rule_reduce,
     seen_term_tok,
     have_pushed_tok,
     in_dead_code
     ;
int prev_tok_seen,
    cur_token,
    tok_seen_ind,
    pushed_back_tok,
    cur_pp_if_depth,
    dead_pp_if_depth,
    cur_direct_cnt,
    curl_nesting,
    paren_nesting
    ;
int token_seen_buf[TOK_SEEN_BUF_LEN];


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


BOOL match_object(void)
{
save_point();

while (TRUE)
   {
   get_next_token();
   switch (cur_token)
      {
      TOK_IDENTIFIER:
      TOK_DIR_SELECT:
      TOK_INDIR_SELECT:
			break;

      TOK_OPEN_SQUARE: open_square++;
		       break;

      TOK_CL_SQUARE: open_square--;
		     break;

      default:
      }
   }

return_lab:
restore_point();
}


BOOL match_expr(void)
{
save_point();
if (!feof(stdin))
   {
   get_next_token();
   switch (cur_token)
      {
      TOK_SEMI: goto return_lab;

      TOK_OPEN_RND: open_rnd++;
		    break;

      TOK_CL_RND: open_rnd--;
		  break;

      TOK_OPEN_SQUARE: open_square++;
		       break;

      TOK_CL_SQUARE: open_square--;
		     break;

      TOK_OPEN_CURL: open_curl++;
		     break;

      TOK_CL_CURL: open_curl--;
		   break;

      TOK_COMMA: 
		 break;

      }
   }

return_lab:
restore_point();
}

void do_pp_directive(void)
/*
 * Process the token sequences making up a preprocessing
 * directive (a # has been encountered at the start of a line).
 */
{
in_pp_directive=TRUE;
last_was_log_newline=FALSE;

if (!feof(stdin))
   {
   get_next_token();

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
   get_next_token();
   if (last_was_log_newline)
      break;
   }
in_pp_directive=FALSE;
}


void stmt_decl_grep(void)
{
}


int main(int argc, char *argv[])
{
end_of_file();
next_ch();
get_next_token();
}

