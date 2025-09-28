                       /* dispexp.c, 19 Aug 12 */

#include <stdlib.h>
#include <stdio.h>

#include "global.h"
#include "lex.h"
#include "parser.h"
#include "dispexp.h"

#define DISPEXP_DEBUG 0

#define TOP_EXPR TOK_SPACE


BOOL do_disp_expr;


void display_leaf(tree_node_ptr expr_ptr)
{
if (expr_ptr == NULL)
   return;

if (expr_ptr->tok == TOK_IDENTIFIER)
   printf("%s", expr_ptr->lex_valu.ident_str);
else if (expr_ptr->tok == INTEGER_CONST)
   {
   if (expr_ptr->lit_is_hex)
      printf("0x%llx", expr_ptr->lex_valu.int_valu);
   else
      printf("%llu", expr_ptr->lex_valu.int_valu);
   }
else
   printf("%s ", tokens[expr_ptr->tok]);
}


static void display_full_expr(int expr_context,
			      tree_node_ptr expr_ptr);

static tree_node_ptr get_postfix_ident(tree_node_ptr expr_ptr)
{
while ((expr_ptr->tok == TOK_DIR_SELECT) ||
       (expr_ptr->tok == TOK_INDIR_SELECT) ||
       (expr_ptr->tok == TOK_OPEN_SQUARE) ||
       (expr_ptr->tok == TOK_FUNC_CALL))
   if ((expr_ptr->tok == TOK_OPEN_SQUARE) ||
       (expr_ptr->tok == TOK_FUNC_CALL))
      expr_ptr=expr_ptr->left_op;
   else
      expr_ptr=expr_ptr->right_op;

return expr_ptr;
}


void display_subexpr(int expr_context,
		     tree_node_ptr expr_ptr,
		     int parent_tok)
/*
 * Recurse down an expression tree displaying the binary operators
 * it contains.
 */
{
tree_node_ptr left_tree_ptr,
	      right_tree_ptr;

if (expr_ptr == NULL)
   return;

switch (expr_ptr->tok)
   {
/*
 * A function argument or a value on an initializer list.
 */
   case TOK_ARG:
	if (expr_ptr->left_op != NULL)
	   display_full_expr(expr_context, expr_ptr->left_op);
	if (expr_ptr->right_op != NULL)
	   display_full_expr(expr_context, expr_ptr->right_op);
	return;

   case TOK_OPEN_SQUARE:
	display_full_expr(expr_context, expr_ptr->right_op);
	return;

/*
 * The initializer list inside of a { ... }
 */
   case TOK_CMPD_INIT:
	display_full_expr(expr_context, expr_ptr->right_op);
	return;

   case TOK_FUNC_CALL:
        display_subexpr(expr_context, expr_ptr->right_op, TOP_EXPR);
	return;

   default:
	break;
   }

if (IS_USER_BIN_OP(expr_ptr->tok) &&
    (!IS_USER_BIN_OP(parent_tok)))
   {
   if ((expr_ptr->left_op == NULL) ||
       (expr_ptr->right_op == NULL))
      return;
   left_tree_ptr=get_postfix_ident(expr_ptr->left_op);
   right_tree_ptr=get_postfix_ident(expr_ptr->right_op);
   if (((left_tree_ptr->tok == TOK_IDENTIFIER) ||
        (left_tree_ptr->tok == INTEGER_CONST)) &&
       ((right_tree_ptr->tok == TOK_IDENTIFIER) ||
        (right_tree_ptr->tok == INTEGER_CONST)))
      {
      printf("%s ", tokens[expr_ptr->tok]);
      display_leaf(left_tree_ptr);
      printf(" ");
      display_leaf(right_tree_ptr);
      printf("\n");
      }
   }
display_subexpr(expr_context, expr_ptr->left_op, expr_ptr->tok);
display_subexpr(expr_context, expr_ptr->right_op, expr_ptr->tok);
}

void display_full_expr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Called with a full expression.
 */
{
display_subexpr(expr_context, expr_ptr, TOP_EXPR);
}


void display_expr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Top level function (called when a full expression appearing in a grammar
 * production reduces) that displays an expression tree.
 */
{
if (expr_ptr == NULL)
   return;
display_full_expr(expr_context, expr_ptr);
}


void init_disp_expr(void)
{
do_disp_expr=TRUE;
build_parse_tree=TRUE;
}

