                       /* cntexp.c,  8 Nov 08 */

#include <stdlib.h>
#include <stdio.h>

#include "ngutil.h"
#include "lex.h"
#include "parser.h"
#include "dispexp.h"

#define DISPEXP_DEBUG 0

#define TOP_EXPR TOK_SPACE


BOOL do_cnt_expr;


void count_subexpr(int expr_context,
		     tree_node_ptr expr_ptr,
		     int parent_tok)
/*
 * Recurse down an expression tree counting various attributes
 * that it contains.
 */
{
if (expr_ptr == NULL)
   return;

switch (expr_ptr->tok)
   {
/*
 * A function argument or a value on an initializer list.
 */
   case TOK_ARG:
	if (expr_ptr->left_op != NULL)
	   count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
	if (expr_ptr->right_op != NULL)
	   count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
	return;

/*
 * The initializer list inside of a { ... }
 */
   case TOK_CMPD_INIT:
	count_full_expr(expr_context, expr_ptr->right_op);
	return;

   case TOK_FUNC_CALL:
        count_subexpr(expr_context, expr_ptr->right_op, TOP_EXPR);
	return;


      case TOK_COMMA:

      case TOK_QUESTION:
      case TOK_COLON:
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
		count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
			break;

      case TOK_SIZEOF:
      case TOK_OPEN_RND:
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
			break;

      case TOK_PLUS:
      case TOK_ARITH_NEG:
      case TOK_ADDR:
      case TOK_PRE_PLUS:
      case TOK_PRE_MINUS:
      case TOK_BIT_NOT:
      case TOK_LOG_NOT:
		unary_ops++;
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
			break;

      case TOK_LSHIFT:
      case TOK_RSHIFT:
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
		count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
			break;

      case TOK_ADD:
      case TOK_MINUS:
      case TOK_STAR:
      case TOK_TIMES:
      case TOK_REMAINDER:
      case TOK_DIVIDE:
		arith_ops++;
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
		count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
			break;

      case TOK_BIT_XOR:
      case TOK_BIT_AND:
      case TOK_BIT_OR:
      case TOK_LOG_AND:
      case TOK_LOG_OR:
		bit_ops++;
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
		count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
			break;

      case TOK_LESS_THAN:
      case TOK_LESS_EQUAL:
      case TOK_GR_EQUAL:
      case TOK_GREATER_THAN:
      case TOK_EQ_EQUAL:
      case TOK_EXC_EQUAL:
		equal_rel_ops++;
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
		count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
			break;

      case TOK_OPEN_SQUARE:
      case TOK_DIR_SELECT:
      case TOK_INDIR_SELECT:
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
		count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
			break;

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
		count_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
		count_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
			break;
      
      case TOK_LITERAL:
      case TOK_IDENTIFIER:
      
	break;
   }
}

void count_full_expr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Called with a full expression.
 */
{
count_subexpr(expr_context, expr_ptr, TOP_EXPR);
}


void count_expr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Top level function (called when a full expression appearing in a grammar
 * production reduces) that displays an expression tree.
 */
{
if (expr_ptr == NULL)
   return;
count_full_expr(expr_context, expr_ptr);
printf("unary %d  arith %d  bit %d  eq_rel %d\n",
			unary_ops, arith_ops, bit_ops, equal_rel_ops);
}


void init_cnt_expr(void)
{
unary_ops=0;
arith_ops=0;
bit_ops=0;
equal_rel_ops=0;
}

