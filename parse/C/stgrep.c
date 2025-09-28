                       /* stgrep.c, 19 Aug 12 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "global.h"
#include "lex.h"
#include "parser.h"
#include "stgrep.h"

#define STGREP_DEBUG 0

#define OP_SEQ_OPEN_RND 20
#define OP_SEQ_CL_RND   21

#define MAX_TOK_SEEN 10
#define MAX_PATTERN_LEN 20

struct expr_tok_seq {
		    BYTE tok_seen[MAX_TOK_SEEN];
		    int rep_tok_offset;
		    };

BOOL do_grep;

unsigned char tok_to_op[221];

BYTE match_pattern[MAX_PATTERN_LEN];
BYTE mpattern_len;

struct expr_tok_seq *cur_tok_seq;


void print_grep_match(void)
{
print_input_buf();
}


void report_tok(int tok)
{
BYTE mind,
     start_offset;

if (!(IS_USER_BIN_OP(tok) ||
      (tok == TOK_OPEN_RND) || (tok == TOK_CL_RND)))
   return;

#if STGREP_DEBUG
printf("r> %d\n", tok);
#endif

cur_tok_seq->tok_seen[cur_tok_seq->rep_tok_offset]=tok;
cur_tok_seq->rep_tok_offset=(cur_tok_seq->rep_tok_offset+1) % mpattern_len;

for (mind=cur_tok_seq->rep_tok_offset; mind < mpattern_len; mind++)
   if (match_pattern[mind-cur_tok_seq->rep_tok_offset] != cur_tok_seq->tok_seen[mind])
      return;

start_offset=mpattern_len-cur_tok_seq->rep_tok_offset;

for (mind=0; mind < cur_tok_seq->rep_tok_offset; mind++)
   if (match_pattern[mind+start_offset] != cur_tok_seq->tok_seen[mind])
      return;

print_grep_match();
}


void grep_subexpr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Walk an expression tree saving the 'op_seq' value for
 * various subexpressions (based, hopefully, on how developers
 * break down expressions into distinct subexpressions).
 */
{
if (expr_ptr == NULL)
   return;

#if STGREP_DEBUG
printf("g> %d\n", expr_ptr->tok);
#endif

switch (expr_ptr->tok)
   {
   case TOK_FUNC_CALL:
/*
 * A function argument or a value on an initializer list.
 */
   case TOK_ARG:
	grep_expr(expr_context, expr_ptr->left_op);
	grep_expr(expr_context, expr_ptr->right_op);
	break;

   case TOK_OPEN_RND:
	grep_expr(expr_context, expr_ptr->left_op);
	break;

   case TOK_OPEN_SQUARE:
	grep_expr(expr_context, expr_ptr->left_op);
	grep_expr(expr_context, expr_ptr->right_op);
	break;

   case TOK_CAST:
	grep_expr(expr_context, expr_ptr->right_op);
	break;

/*
 * The initializer list inside a { ... }
 */
   case TOK_CMPD_INIT:
	grep_expr(expr_context, expr_ptr->right_op);
	break;

   default:
	grep_subexpr(expr_context, expr_ptr->left_op);
	report_tok(expr_ptr->tok);
	grep_subexpr(expr_context, expr_ptr->right_op);
	break;
   }
return;
}

void grep_expr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Top level function (called when a full expression appearing in a grammar
 * production reduces) that attampts to match the specified pattern against
 * the current expression tree.
 */
{
struct expr_tok_seq loc_tok_seq;
struct expr_tok_seq * const prev_tok_seq = cur_tok_seq;

if (expr_ptr == NULL)
   return;

loc_tok_seq.rep_tok_offset=0;
cur_tok_seq=&loc_tok_seq;
grep_subexpr(expr_context, expr_ptr);
cur_tok_seq=prev_tok_seq;
}


void get_grep_pat(char *g_pat)
/*
 * Map the space delimited token sequenc given on the command line to
 * internal form (currently a list of tokens with no wildcard support).
 */
{
char *pat_ptr = g_pat;
char tok_buf[MAX_TOK_LEN];
int cur_tok_len,
    tind;

while (*pat_ptr != 0)
   {
   cur_tok_len=0;
   while (TRUE)
      if (*pat_ptr && !isspace(*pat_ptr))
         {
         tok_buf[cur_tok_len]=*pat_ptr;
         pat_ptr++;
         cur_tok_len++;
         }
      else
	 {
         while (isspace(*pat_ptr))
	    pat_ptr++;
         break;
	 }
   tok_buf[cur_tok_len]=0;

   for (tind=0; tind < MAX_TOK; tind++)
      if (tokens[tind] && (strcmp(tokens[tind], tok_buf) == 0))
         {
         match_pattern[mpattern_len]=tind;
         mpattern_len++;
         }
   }
}

