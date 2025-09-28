                      /* analyse.c, 19 Aug 12 */

#include "global.h"
#include "parser.h"
#include "count.h"
#include "dispexp.h"
#include "stgrep.h"
#include "analyse.h"

void got_expression(int expr_context, tree_node_ptr expr_ptr)
{
if (do_if_expr && (expr_context == IF_EXPR_EX))
   if_expression(expr_ptr);
if (do_cnt_expr)
   sum_expr_info(expr_context, expr_ptr);
if (do_disp_expr)
   display_expr(expr_context, expr_ptr);
if (do_grep)
   grep_expr(expr_context, expr_ptr);
}
