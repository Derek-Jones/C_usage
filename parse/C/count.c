                       /* count.c, 19 Aug 12 */

#include <stdlib.h>
#include <stdio.h>

#include "global.h"
#include "lex.h"
#include "parser.h"
#include "count.h"

#define COUNT_DEBUG 0

#define OP_SEQ_OPEN_RND 20
#define OP_SEQ_CL_RND   21

#define MAX_OPS_PER_EXPR 100
#define MAX_ARG_COUNT 50

#define TOP_EXPR TOK_SPACE

typedef unsigned int op_count_type[MAX_TOK];
typedef struct {
	       BYTE num_ops;
	       BYTE ops[MAX_OPS_PER_EXPR];
               } op_seq_type;

op_count_type total_op_count,
	      expr_op_count[MAX_CONTEXT];
unsigned char tok_to_op[221];
unsigned int num_expressions,
	     num_unary_ops,
	     num_idents,
	     num_if_andand,
	     num_if_oror,
	     unary_ops,
	     arith_ops,
	     bit_ops,
	     equal_rel_ops;
unsigned int total_binary_ops[MAX_OPS_PER_EXPR];

/*
 * Contexts in which an expression can occur
 */
static int cur_context;
static char * context_str[MAX_CONTEXT] = {
			"bitfield",
			"enum_init",
			"designator",
			"case_label",
			"if_cond",
			"switch_cond",
			"expr_stmt",
			"while_cond",
			"for_init",
			"for_cntrl",
			"for_inc",
			"return",
			"dir_decl",
			"dir_absdecl",
			"init_valu",
			};

#if 000
struct operand_map {
		    unsigned char usr_binary;
		   };

struct operand_map tok_to_op[MAX_TOK]= {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
#endif

char * op_seq_str[34];

BOOL 
     do_if_expr,
     do_cnt_expr;

static void count_full_expr(int expr_context, tree_node_ptr expr_ptr);

static BOOL seen_open_rnd,
	    include_open_rnd;
static int cur_arg_count; // Don't recurse too deeply into initializers

static void map_op_toks(void)
{
/*
 * Map operator tokens to a small number
 */
op_seq_str[0]="_";
tok_to_op[TOK_LSHIFT]=1;
op_seq_str[1]=tokens[TOK_LSHIFT];
tok_to_op[TOK_RSHIFT]=2;
op_seq_str[2]=tokens[TOK_RSHIFT];
tok_to_op[TOK_ADD]=3;
op_seq_str[3]=tokens[TOK_ADD];
tok_to_op[TOK_MINUS]=4;
op_seq_str[4]=tokens[TOK_MINUS];
tok_to_op[TOK_TIMES]=5;
op_seq_str[5]=tokens[TOK_TIMES];
tok_to_op[TOK_REMAINDER]=6;
op_seq_str[6]=tokens[TOK_REMAINDER];
tok_to_op[TOK_DIVIDE]=7;
op_seq_str[7]=tokens[TOK_DIVIDE];
tok_to_op[TOK_BIT_XOR]=8;
op_seq_str[8]=tokens[TOK_BIT_XOR];
tok_to_op[TOK_BIT_AND]=9;
op_seq_str[9]=tokens[TOK_BIT_AND];
tok_to_op[TOK_BIT_OR]=10;
op_seq_str[10]=tokens[TOK_BIT_OR];
tok_to_op[TOK_LESS_THAN]=11;
op_seq_str[11]=tokens[TOK_LESS_THAN];
tok_to_op[TOK_LESS_EQUAL]=12;
op_seq_str[12]=tokens[TOK_LESS_EQUAL];
tok_to_op[TOK_GR_EQUAL]=13;
op_seq_str[13]=tokens[TOK_GR_EQUAL];
tok_to_op[TOK_GREATER_THAN]=14;
op_seq_str[14]=tokens[TOK_GREATER_THAN];
tok_to_op[TOK_EQ_EQUAL]=15;
op_seq_str[15]=tokens[TOK_EQ_EQUAL];
tok_to_op[TOK_EXC_EQUAL]=16;
op_seq_str[16]=tokens[TOK_EXC_EQUAL];
tok_to_op[TOK_LOG_AND]=17;
op_seq_str[17]=tokens[TOK_LOG_AND];
tok_to_op[TOK_LOG_OR]=18;
op_seq_str[18]=tokens[TOK_LOG_OR];
tok_to_op[TOK_COMMA]=19;
op_seq_str[19]=tokens[TOK_COMMA];

tok_to_op[TOK_OPEN_RND]=OP_SEQ_OPEN_RND;
op_seq_str[OP_SEQ_OPEN_RND]=tokens[TOK_OPEN_RND];
op_seq_str[OP_SEQ_CL_RND]=tokens[TOK_CL_RND];

#if MEMBER_SELECT
tok_to_op[TOK_DIR_SELECT]=22;
op_seq_str[22]=tokens[TOK_DIR_SELECT];
tok_to_op[TOK_INDIR_SELECT]=23;
op_seq_str[23]=tokens[TOK_INDIR_SELECT];
#endif

#if UNARY_OPS
tok_to_op[TOK_PLUS]=24;
op_seq_str[24]=tokens[TOK_PLUS];
tok_to_op[TOK_ARITH_NEG]=25;
op_seq_str[25]=tokens[TOK_ARITH_NEG];
tok_to_op[TOK_STAR]=26;
op_seq_str[26]=tokens[TOK_STAR];
tok_to_op[TOK_ADDR]=27;
op_seq_str[27]=tokens[TOK_ADDR];
tok_to_op[TOK_PRE_PLUS]=28;
op_seq_str[28]=tokens[TOK_PRE_PLUS];
tok_to_op[TOK_PRE_MINUS]=29;
op_seq_str[29]=tokens[TOK_PRE_MINUS];
tok_to_op[TOK_POST_PLUS]=30;
op_seq_str[30]=tokens[TOK_POST_PLUS];
tok_to_op[TOK_POST_MINUS]=31;
op_seq_str[31]=tokens[TOK_POST_MINUS];
#endif

tok_to_op[TOK_QUESTION]=32;
op_seq_str[32]=tokens[TOK_QUESTION];
tok_to_op[TOK_COLON]=33;
op_seq_str[33]=tokens[TOK_COLON];
}


void zero_op_count(op_count_type op_count)
{
int ind;

for (ind=0; ind < MAX_TOK; ind++)
   op_count[ind]=0;
}


void add_op_seq(op_seq_type val)
{
BYTE sind;

if (val.num_ops == 0)
   return;

if (!do_cnt_expr)
   return;
if (include_open_rnd)
   printf("Os ");
else
   printf("OS ");
if (cur_context < MAX_CONTEXT)
   printf("%s", context_str[cur_context]);
for (sind=0; sind < val.num_ops; sind++)
   printf("   %2s", op_seq_str[val.ops[sind]]);
printf("\n");
}


static void get_expr_op_seqs(tree_node_ptr expr_ptr);

op_seq_type get_op_seq(tree_node_ptr expr_ptr)
/*
 * Build up a single value that represents 'all' (ie, those for
 * which tok_to_op[expr_ptr->tok] == 0) operators in an expression.
 * Called twice, the second time if an open parenthesis was encountered
 * on the first call.
 */
{
op_seq_type op_seq,
	    sub_op_seq;
BYTE sind;

if (expr_ptr == NULL)
   {
   op_seq.num_ops=0;
   return op_seq;
   }

if ((tok_to_op[expr_ptr->tok] == 0) ||
    ((expr_ptr->tok == TOK_OPEN_RND) && !include_open_rnd))
   {
   get_expr_op_seqs(expr_ptr);
   op_seq.num_ops=0;
   return op_seq;
   }

if (expr_ptr->tok == TOK_OPEN_RND)
   {
   op_seq=get_op_seq(expr_ptr->left_op);

   /*
    * Add a bracketing ( ... ) around the left expression.
    */
   if (op_seq.num_ops+2 < MAX_OPS_PER_EXPR)
      {
      op_seq.ops[op_seq.num_ops]=OP_SEQ_CL_RND;
      op_seq.num_ops++;
      for (sind=op_seq.num_ops+1; sind != 0; sind--)
         op_seq.ops[sind]=op_seq.ops[sind-1];
      op_seq.ops[0]=OP_SEQ_OPEN_RND;
      op_seq.num_ops++;
      }
   }
else
   {
   op_seq=get_op_seq(expr_ptr->left_op);

   if ((tok_to_op[expr_ptr->tok] != 0) &&
       (op_seq.num_ops != MAX_OPS_PER_EXPR))
      {
      op_seq.ops[op_seq.num_ops]=tok_to_op[expr_ptr->tok];
      op_seq.num_ops++;
      }
   }

/*
 * Now process the right subexpression.
 */
sub_op_seq=get_op_seq(expr_ptr->right_op);
if (sub_op_seq.num_ops > 0)
   {
   if (op_seq.num_ops+sub_op_seq.num_ops >= MAX_OPS_PER_EXPR)
      sub_op_seq.num_ops=MAX_OPS_PER_EXPR-op_seq.num_ops;
   for (sind=0; sind < sub_op_seq.num_ops; sind++)
      op_seq.ops[op_seq.num_ops+sind]=sub_op_seq.ops[sind];
   op_seq.num_ops+=sub_op_seq.num_ops;
   }

return op_seq;
}

void get_expr_op_seqs(tree_node_ptr expr_ptr)
/*
 * Walk an expression tree saving the 'op_seq' value for
 * various subexpressions (based, hopefully, on how developers
 * break down expressions into distinct subexpressions).
 */
{
if (expr_ptr == NULL)
   return;

#if COUNT_DEBUG
{
static int last_tok;
if (expr_ptr->tok != last_tok)
   printf("tok %d\n", expr_ptr->tok);
last_tok=expr_ptr->tok;
}
#endif

switch (expr_ptr->tok)
   {
/*
 * A function argument or a value on an initializer list.
 */
   case TOK_ARG:
	if (cur_arg_count < MAX_ARG_COUNT)
	   {
	   cur_arg_count++;
	   add_op_seq(get_op_seq(expr_ptr->left_op));
	   add_op_seq(get_op_seq(expr_ptr->right_op));
	   cur_arg_count--;
	   }
	break;

   case TOK_OPEN_RND:
	add_op_seq(get_op_seq(expr_ptr->left_op));
	seen_open_rnd=TRUE;
	break;

   case TOK_OPEN_SQUARE:
	get_expr_op_seqs(expr_ptr->left_op);
	add_op_seq(get_op_seq(expr_ptr->right_op));
	break;

   case TOK_CAST:
	get_expr_op_seqs(expr_ptr->right_op);
	break;

/*
 * The initializer list inside of a { ... }
 */
   case TOK_CMPD_INIT:
	get_expr_op_seqs(expr_ptr->right_op);
	break;

   case TOK_FUNC_CALL:
   default:
	get_expr_op_seqs(expr_ptr->left_op);
	get_expr_op_seqs(expr_ptr->right_op);
	break;
   }
return;
}

void cnt_operators(op_count_type op_count, tree_node_ptr expr_ptr)
/*
 * Count operators (well actually it counts tokens and so includes
 * leaf information).
 */
{
if (expr_ptr == NULL)
   return;

op_count[expr_ptr->tok]++;

cnt_operators(op_count, expr_ptr->left_op);
cnt_operators(op_count, expr_ptr->right_op);

return;
}


static void cnt_op_seq(tree_node_ptr expr_ptr)
{
if (expr_ptr->tok == TOK_EQUAL)
   {
   add_op_seq(get_op_seq(expr_ptr->left_op));
   add_op_seq(get_op_seq(expr_ptr->right_op));
   }
else
   add_op_seq(get_op_seq(expr_ptr));
}


static void binary_ops_in_expr(int expr_context, tree_node_ptr expr_ptr);

int binary_ops_in_subexpr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Recurse down an expression tree counting the number of
 * binary operators it contains.
 */
{
int num_ops;

if (expr_ptr == NULL)
   return 0;

switch (expr_ptr->tok)
   {
/*
 * A function argument or a value on an initializer list.
 */
   case TOK_ARG:
	if (expr_ptr->left_op != NULL)
	   binary_ops_in_expr(expr_context, expr_ptr->left_op);
	if (expr_ptr->right_op != NULL)
	   binary_ops_in_expr(expr_context, expr_ptr->right_op);
	return 0;

   case TOK_OPEN_SQUARE:
	binary_ops_in_expr(expr_context, expr_ptr->right_op);
	return 0;

/*
 * The initializer list inside of a { ... }
 */
   case TOK_CMPD_INIT:
	binary_ops_in_expr(expr_context, expr_ptr->right_op);
	return 0;

   case TOK_FUNC_CALL:
        (void)binary_ops_in_subexpr(expr_context, expr_ptr->right_op);
	return 0;

   default:
	break;
   }

num_ops=binary_ops_in_subexpr(expr_context, expr_ptr->left_op)+
        binary_ops_in_subexpr(expr_context, expr_ptr->right_op);

if (IS_USER_BIN_OP(expr_ptr->tok))
   return num_ops+1;
else
   return num_ops;
}

void binary_ops_in_expr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Called with a full expression.
 */
{
unsigned int num_binary_ops = binary_ops_in_subexpr(expr_context, expr_ptr);

if (num_binary_ops < MAX_OPS_PER_EXPR)
   total_binary_ops[num_binary_ops]++;
}


void print_op_count(void)
{
int con_ind,
    tok_ind;
unsigned int total_exprs = 0;
unsigned int *op_count_ptr;

printf("Number of expressions %d\n", num_expressions);
printf("Contextual expression operator/operand count\n");
for (con_ind=0; con_ind < MAX_CONTEXT; con_ind++)
   {
   printf("%s\n", context_str[con_ind]);
   op_count_ptr=expr_op_count[con_ind];
   for (tok_ind=0; tok_ind < MAX_TOK; tok_ind++)
      {
      total_op_count[tok_ind] += op_count_ptr[tok_ind];
      if (op_count_ptr[tok_ind] != 0)
         printf("%6d   %s\n", op_count_ptr[tok_ind], tokens[tok_ind]);
      }
   }

printf("Total operator/operand count\n");
for (tok_ind=0; tok_ind < MAX_TOK; tok_ind++)
   {
   if (total_op_count[tok_ind] != 0)
      printf("%6d   %s\n", total_op_count[tok_ind], tokens[tok_ind]);
   }

printf("Expressions containing given number of operators\n");
for (con_ind=0; con_ind < MAX_OPS_PER_EXPR; con_ind++)
   total_exprs+=total_binary_ops[con_ind];
for (con_ind=0; con_ind < MAX_OPS_PER_EXPR; con_ind++)
   if (total_binary_ops[con_ind] != 0)
      printf("%3d  %7d %5.2f\n", con_ind, total_binary_ops[con_ind],
			(100.0*total_binary_ops[con_ind])/total_exprs);
}


void print_op_seq_count(void)
{
printf("Operator sequence totals %d\n", num_expressions);

}


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
		if (expr_ptr->tok == TOK_LOG_AND)
		   num_if_andand++;
		else if (expr_ptr->tok == TOK_LOG_OR)
		   num_if_oror++;
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

static void count_full_expr(int expr_context, tree_node_ptr expr_ptr)
/*
 * Called with a full expression.
 */
{
count_subexpr(expr_context, expr_ptr, TOP_EXPR);
}


void sum_expr_info(int expr_context, tree_node_ptr expr_ptr)
/*
 * Top level function (called when a full expression appearing in a grammar
 * production reduces) that counts various quantities associated
 * with an expression.
 */
{
if (expr_ptr == NULL)
   return;
cur_context=expr_context;
num_expressions++;
num_unary_ops=0;
cnt_operators(expr_op_count[expr_context], expr_ptr);
binary_ops_in_expr(expr_context, expr_ptr);

seen_open_rnd=FALSE;
include_open_rnd=FALSE;
cnt_op_seq(expr_ptr);
if (seen_open_rnd)
   {
   include_open_rnd=TRUE;
   cnt_op_seq(expr_ptr);
   }

#if 000
count_full_expr(expr_context, expr_ptr);
printf("unary %d  arith %d  bit %d  eq_rel %d\n",
			unary_ops, arith_ops, bit_ops, equal_rel_ops);
#endif
}


void init_cnt_expr_op(void)
{
unary_ops=0;
arith_ops=0;
bit_ops=0;
equal_rel_ops=0;
cur_arg_count=0;
}

void if_expression(tree_node_ptr expr_ptr)
/*
 * Top level function called when a control expression in an
 * if statement reduces.
 */
{
if (expr_ptr == NULL)
   return;
num_if_andand=0;
num_if_oror=0;
count_subexpr(0, expr_ptr, 0);
printf("IX %4d %4d\n", num_if_andand, num_if_oror);
}


void init_count(void)
{
map_op_toks();
// zero_op_count();
init_cnt_expr_op();
}

