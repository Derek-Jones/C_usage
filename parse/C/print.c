                         /* print.c, 19 Aug 12 */

#include <stdio.h>

#include "global.h"
#include "parser.h"
#include "count.h"
#include "print.h"

BOOL
     disp_results,
     disp_rule_count;


void print_results(void)
{
print_op_count();
print_op_seq_count();

printf("Total multiplicative_merge %d  Total additive_merge %d\n",
                           num_multiplicative_merge, num_additive_merge);
}

void print_usage(BOOL is_global)
{
if (disp_results)
   print_results();
if (disp_rule_count)
   print_rules_reduced();
}



