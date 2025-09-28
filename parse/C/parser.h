                        /* parser.h, 19 Aug 12 */

#define EMPT_COLON_CE   0
#define DECL_COLON_CE   0
#define ENUM_INITIAL_CE 1
#define DESIGNATOR_CE   2
#define CASE_LAB_CE     3

#define IF_EXPR_EX      4
#define SWITCH_EXPR_EX  5
#define EXPR_STMT_EX    6
#define WHILE_EXPR_EX   7
#define FOR_INIT_EX     8
#define FOR_CNTRL_EX    9
#define FOR_INC_EX     10
#define RETURN_EX      11
#define DIR_DECL_EX    12
#define DIR_ABSDECL_EX 13
#define INIT_EX        14

#define MAX_CONTEXT 15

/*
#define YYSTYPE char const *
*/

struct tree_node {
		  BOOL lit_is_hex;
		  short tok;
		  struct tree_node *left_op,
				   *right_op;
		  union {
			 LONGEST_UINT int_valu;
			 char *ident_str;
			} lex_valu;
		  };
typedef struct tree_node * tree_node_ptr;

struct parse_node {
		   tree_node_ptr node_ptr;
		   int tok;
		  }; 
#define YYSTYPE struct parse_node

YYSTYPE stmt_decl_merge(YYSTYPE x0, YYSTYPE x1);
YYSTYPE multiplicative_merge(YYSTYPE x0, YYSTYPE x1);
YYSTYPE additive_merge(YYSTYPE x0, YYSTYPE x1);

extern BOOL build_parse_tree,
            seen_DC,
            seen_ES;
extern int total_frees,
	   total_mallocs;
extern int num_multiplicative_merge,
           num_additive_merge;

extern int yydebug;

extern void push_ident(char *id_str);
extern char *pop_ident(void);
extern void push_number(LONGEST_UINT valu);
extern void push_float(long double f_valu);
extern void push_char(char ch);
extern void push_string(char str);

extern void print_tree(tree_node_ptr tree_ptr);
extern tree_node_ptr mk_qualifier_list(tree_node_ptr left_specifier,
			               tree_node_ptr right_specifier);
extern tree_node_ptr mk_leaf_node(int tok);
extern tree_node_ptr mk_unary_node(int tok, tree_node_ptr operand);
extern tree_node_ptr mk_binary_node(int tok, tree_node_ptr left_operand, tree_node_ptr right_operand);
extern void build_tok_tree(unsigned char token);
extern tree_node_ptr pop_id_str(void);
extern void init_parse(void);
extern void finish_parse(void);

