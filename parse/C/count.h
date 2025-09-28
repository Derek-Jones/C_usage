                       /* count.h,  5 Mar 12 */

extern BOOL print_op_seq,
	    do_if_expr,
	    do_cnt_expr;

extern unsigned int
	     num_if_andand,
	     num_if_oror,
	     unary_ops,
	     arith_ops,
	     bit_ops,
	     equal_rel_ops;

extern void init_count(void);
extern void sum_expr_info(int expr_context, tree_node_ptr operand);
extern void if_expression(tree_node_ptr operand);
extern void print_op_count(void);
extern void print_op_seq_count(void);

extern void count_expr_op(int expr_context, tree_node_ptr expr_ptr);
extern void init_cnt_expr_op(void);

