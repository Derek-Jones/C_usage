                        /* parser.c, 18 Aug 12 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "lex.h"
#include "parser.h"

#define STORE_BUF_SIZE 10000
#define MAX_TOK_STACK 350

#define CHK_TOP_TOK_STACK if (top_tok_stack == MAX_TOK_STACK)             \
                           {printf(">>>Error: top_tok_stack overflow\n"); \
			    print_input_buf();                            \
			    return;}

BOOL build_parse_tree, /* MUST be set if a parse tree is being built */
     seen_DC,
     seen_ES;

int num_multiplicative_merge,
    num_additive_merge,
    num_stmt_decl_merge;

/*
 * Linked list of buffers used to manage a simple mark/release
 * storage allocator.
 */
struct base_stor_rec {
   void *buff;
   size_t free_offset;
   struct base_stor_rec *next;
   };
struct base_stor_rec *base_stor_ptr = NULL,
                     *cur_stor_ptr;
union {
      char *id_str;
      char c_const;
      char str;
      long double f_val;
      } tok_stack[MAX_TOK_STACK];
static int top_tok_stack;

static void * get_mem(size_t amount);


/*
 * GLR parsing may make use of multiple parse stacks.  This means
 * that grammar reductions may get delayed and the current lexical
 * token may not correspond to the token occurring at the start of
 * the production.  So we keep various stacks of tokens as they are
 * lexed and the code for the reduction pops the appropriate item.
 */
void push_ident(char *id_str)
{
size_t id_len=strlen(id_str);

// printf("push %s\n", id_str);

if (!build_parse_tree)
   return;

CHK_TOP_TOK_STACK;

tok_stack[top_tok_stack].id_str=(char *)get_mem(id_len+1);
strcpy(tok_stack[top_tok_stack].id_str, id_str);
top_tok_stack++;
}

char *pop_ident(void)
/*
 * Actually this is not a pop since we need to return the oldest
 * token pushed.
 */
{
char *next_id;
int ind;

if (top_tok_stack == 0)
   return "-";

next_id=tok_stack[0].id_str;

/*
 * Suffle down the other tokens.
 */
for (ind=1; ind <top_tok_stack; ind++)
   tok_stack[ind-1].id_str=tok_stack[ind].id_str;

top_tok_stack--;

// printf("pop %s\n", next_id);

return next_id;
}

void push_number(LONGEST_UINT valu)
{
if (!build_parse_tree)
   return;
}

void push_float(long double f_valu)
{
if (!build_parse_tree)
   return;
}

void push_char(char ch)
{
if (!build_parse_tree)
   return;
}

void push_string(char str)
{
if (!build_parse_tree)
   return;
}

void print_tree(tree_node_ptr tree_ptr)
/*
 * Print an expression tree (in non-friendly form)
 */
{
if (tree_ptr == NULL)
   return;

printf("%s\n", tokens[tree_ptr->tok]);
print_tree(tree_ptr->left_op);
print_tree(tree_ptr->right_op);
}

static tree_node_ptr mk_node(int tok)
{
tree_node_ptr node = (tree_node_ptr)get_mem(sizeof(struct tree_node));

node->tok=tok;

return node;
}


tree_node_ptr mk_qualifier_list(tree_node_ptr left_specifier,
			        tree_node_ptr right_specifier)
/*
 * Build a list of declaration specifiers.  In the bison grammar right_specifier
 * is the next specifier encountered, so the final list is backwards to
 * what appears in the source.
 */
{
if (!build_parse_tree)
   return NULL;

if (right_specifier != NULL)
   right_specifier->left_op=left_specifier;

return right_specifier;
}


tree_node_ptr mk_leaf_node(int tok)
{
int ident_len;
tree_node_ptr node;
char *next_ident;

if (!build_parse_tree)
   return NULL;

node = mk_node(tok);
node->left_op=NULL;
node->right_op=NULL;
switch (tok)
   {
   case TOK_IDENTIFIER: next_ident=pop_ident();
			ident_len=strlen(next_ident);
			node->lex_valu.ident_str=(char *)get_mem(ident_len+1);
			strcpy(node->lex_valu.ident_str, next_ident);
			break;

   case INTEGER_CONST: node->lex_valu.int_valu=lit_valu;
		       node->lit_is_hex=lit_is_hex;
		       break;

   case CHAR_CONST:
		       strcpy(node->lex_valu.ident_str, "'a'");
		       break;

   case FLOAT_CONST:
		       strcpy(node->lex_valu.ident_str, "1.0");
		       break;

   case STRING_CONST:
		       break;

   default: /* declaration specifiers, etc */
		       break;
   }

return node;
}

tree_node_ptr mk_unary_node(int tok, tree_node_ptr operand)
{
tree_node_ptr node = mk_node(tok);

/*
printf("mku %d\n", tok);
*/

node->left_op=operand;
node->right_op=NULL;

return node;
}


tree_node_ptr mk_binary_node(int tok, tree_node_ptr left_operand, tree_node_ptr right_operand)
{
tree_node_ptr node = mk_node(tok);

/*
printf("mkb %d\n", tok);
*/

node->left_op=left_operand;
node->right_op=right_operand;

return node;
}

static YYSTYPE stmt_or_decl(YYSTYPE x0, YYSTYPE x1)
{
if (x0.node_ptr->tok == TOK_TIMES)
   {
   seen_ES=FALSE;
   return x1;
   }
if (x0.node_ptr->tok == TOK_FUNC_CALL)
   {
   return x0;
   }

return x0;
}

YYSTYPE stmt_decl_merge(YYSTYPE x0, YYSTYPE x1)
{
num_stmt_decl_merge++;
/*
 * f(x);  could be a function call or a declaration of x to have type f
 * x * y; could be an expression statement or a declaration of y as pointer to x
 */
if (x0.node_ptr != NULL)
   return stmt_or_decl(x0, x1);
if (x1.node_ptr != NULL)
   return stmt_or_decl(x1, x0);

return x0;
}

YYSTYPE multiplicative_merge(YYSTYPE x0, YYSTYPE x1)
{
num_multiplicative_merge++;
/*
 * If possible assume it's a binary operator.
 */
if (x0.node_ptr->tok == TOK_TIMES)
   {
   return x0;
   }

return x1;
}

YYSTYPE additive_merge(YYSTYPE x0, YYSTYPE x1)
{
num_additive_merge++;
/*
 * If possible assume it's a binary operator.
 */
if ((x0.node_ptr->tok == TOK_ADD) || (x0.node_ptr->tok == TOK_MINUS))
   {
   return x0;
   }

return x1;
}


static void get_new_block(void)
/*
 * Try to use a previously allocated block, otherwise
 * allocated a new block of storage.
 */
{
struct base_stor_rec *new_block_ptr;

if (cur_stor_ptr->next)
   {
   cur_stor_ptr=cur_stor_ptr->next;
   cur_stor_ptr->free_offset=0;
   }
else
   {
   new_block_ptr=malloc(sizeof(struct base_stor_rec));
   new_block_ptr->buff=malloc(STORE_BUF_SIZE);
   new_block_ptr->free_offset=0;
   new_block_ptr->next=NULL;
   cur_stor_ptr->next=new_block_ptr;
   cur_stor_ptr=new_block_ptr;
   }
}

void init_parse(void)
{
seen_DC=FALSE;
seen_ES=FALSE;
top_tok_stack=0;
if (base_stor_ptr == NULL)
   {
   base_stor_ptr=malloc(sizeof(struct base_stor_rec));
   base_stor_ptr->buff=malloc(STORE_BUF_SIZE);
   base_stor_ptr->free_offset=0;
   base_stor_ptr->next=NULL;
   }
cur_stor_ptr=base_stor_ptr;
}

static void * get_mem(size_t amount)
{
void *ret_ptr;

if (cur_stor_ptr->free_offset+amount > STORE_BUF_SIZE)
   get_new_block();
ret_ptr=cur_stor_ptr->buff+cur_stor_ptr->free_offset;
cur_stor_ptr->free_offset+=amount;

return ret_ptr;
}


void finish_parse(void)
{
}

