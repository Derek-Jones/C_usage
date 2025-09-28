                       /* cbook.y,  2 Dec 06 */

%glr-parser

%token
_BOOL _COMPLEX _IMAGINARY
AUTO STATIC EXTERN REGISTER TYPEDEF
CHAR FLOAT DOUBLE INT SHORT LONG UNSIGNED SIGNED VOID
CONST VOLATILE
STRUCT UNION ENUM
IF ELSE
WHILE FOR DO
SWITCH CASE DEFAULT
BREAK CONTINUE
RETURN
GOTO
SIZEOF
OPEN_RND CLOSE_RND
LEFTSHIFT RIGHTSHIFT
PLUS ADD
NEGATE MINUS
STAR TIMES REMAINDER
DIVIDE XOR
AND BITAND
OR BITNEGATE NOT
LT LE GE GT EQUAL NOTEQUAL ANDTEST ORTEST
QUESTION DUMMY1
DOT DEREF
PLUSPLUS MINUSMINUS POSTPLUSPLUS POSTMINUSMINUS
COMMA SEMICOLON
ELLIPSIS
OPEN_CURL CLOSE_CURL
OPEN_SQUARE CLOSE_SQUARE
ASSIGN PLUSASSIGN MINUSASSIGN TIMESASSIGN LSASSIGN RSASSIGN ANDASSIGN
DIVASSIGN REMASSIGN ORASSIGN XORASSIGN
COLON
DUMMY2
CONSTANT
IDENTIFIER
STRING_LITERAL
TYPEDEFNAME
INLINE RESTRICT

ASM
CATCH CLASS COLONCOLON CONST_CAST
DELETE DEREFSTAR DOTSTAR DYNAMIC_CAST
EXPLICIT EXPORT
FRIEND
MUTABLE
NAMESPACE NEW
OPERATOR
PRIVATE PROTECTED PUBLIC
REINTERPRET_CAST
STATIC_CAST
TEMPLATE THIS THROW TRY TYPEID TYPENAME
USING
VIRTUAL
WCHAR_T

UNDEFINED

%%

/*
typedef-name: 
	IDENTIFIER

namespace-name:
	        original-namespace-name
	        namespace-alias

original-namespace-name:
	        IDENTIFIER

namespace-alias:
	        IDENTIFIER

class-name:
	IDENTIFIER
	template-id

enum-name:
	IDENTIFIER

template-name:
	IDENTIFIER
*/

/*
   1.2 - Lexical conventions [gram.lex]

hex-quad:
	hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit

universal-character-name:
	\u         hex-quad
	\U         hex-quad hex-quad
        preprocessing-token:
	header-name
	identifier
	pp-number
	character-literal
	string-literal
	preprocessing-op-or-punc
	each non-white-space character that cannot be one of the above
        token:
	identifier
	keyword
	literal
	operator
	punctuator

header-name:
	< h-char-sequence>        
	" q-char-sequence"        

h-char-sequence:
	h-char
	h-char-sequence h-char

h-char:
	any member of the source character set except
		new-line and >        

q-char-sequence:
	q-char
	q-char-sequence q-char

q-char:
	any member of the source character set except
		new-line and "        

pp-number:
	digit
	. digit
	pp-number digit
	pp-number nondigit
	pp-number e sign
	pp-number E sign
	pp-number .

identifier:
	nondigit
	identifier nondigit
	identifier digit

nondigit: one of
	        universal-character-name
	_ a b c d e f g h i j k l m
	  n o p q r s t u v w x y z
	  A B C D E F G H I J K L M
	  N O P Q R S T U V W X Y Z

digit: one of
	0 1 2 3 4 5 6 7 8 9

preprocessing-op-or-punc: one of
	{	}	[	]	#	##	(	)
	<:	:>	<%	%>	%:	%:%:	;	:	...
	new	delete	?	::	.	.*
	+	-	*	/	%	^	&	|	~
	!	=	<	>	+=	-=	*=	/=	%=
	^=	&=	|=	<<	>>	>>=	<<=	==	!=
	<=	>=	&&	||	++	--	,	->*	->
	and	and_eq	bitand	bitor	compl	not	not_eq
	or	or_eq	xor	xor_eq

literal:
	integer-literal
	character-literal
	floating-literal
	string-literal
	boolean-literal

integer-literal:
	decimal-literal integer-suffix_opt
	octal-literal integer-suffix_opt
	hexadecimal-literal integer-suffix_opt

decimal-literal:
	nonzero-digit
	decimal-literal digit

octal-literal:
	0        
	octal-literal octal-digit

hexadecimal-literal:
	0x         hexadecimal-digit
	0X         hexadecimal-digit
	hexadecimal-literal hexadecimal-digit

nonzero-digit: one of
	1  2  3  4  5  6  7  8  9

octal-digit: one of
	0  1  2  3  4  5  6  7

hexadecimal-digit: one of
	0  1  2  3  4  5  6  7  8  9
	a  b  c  d  e  f
	A  B  C  D  E  F

integer-suffix:
	unsigned-suffix long-suffix_opt
	long-suffix unsigned-suffix_opt

unsigned-suffix: one of
	u  U

long-suffix: one of
	l  L

character-literal:
	'        c-char-sequence'
	L'        c-char-sequence'        

c-char-sequence:
	c-char
	c-char-sequence c-char

c-char:
	any member of the source character set except
		the single-quote  ', backslash  \, or new-line character
	        escape-sequence
	        universal-character-name

escape-sequence:
	simple-escape-sequence
	octal-escape-sequence
	hexadecimal-escape-sequence

simple-escape-sequence: one of
	\'  \"  \?  \\
	\a  \b  \f  \n  \r  \t  \v

octal-escape-sequence:
	\         octal-digit
	\         octal-digit         octal-digit
	\         octal-digit         octal-digit         octal-digit

hexadecimal-escape-sequence:
	\x         hexadecimal-digit
	hexadecimal-escape-sequence         hexadecimal-digit

floating-literal:
	fractional-constant exponent-part_opt floating-suffix_opt
	digit-sequence exponent-part floating-suffix_opt

fractional-constant:
	digit-sequence_opt . digit-sequence
	digit-sequence .

exponent-part:
	e sign_opt digit-sequence
	E sign_opt digit-sequence

sign: one of
	+  -

digit-sequence:
	digit
	digit-sequence digit

floating-suffix: one of
	f  l  F  L

string-literal:
	"s-char-sequence_opt"
	L"s-char-sequence_opt"

s-char-sequence:
	s-char
	s-char-sequence         s-char

s-char:
	any member of the source character set except
		the double-quote ", backslash \, or new-line character
	        escape-sequence
	        universal-character-name

boolean-literal:
	false
	true
*/

/*
   1.3 - Basic concepts [gram.basic]
*/

/*
translation_unit:
                declaration_seq ;
*/

translation_unit:
              declaration  %dprec 1
              {
#if STMT_DEBUG
              printf("declaration\n");
#endif
              seen_term_tok=TRUE;
	      cnt_rule(yyn);
              }        |
              statement    %dprec 2
              {
#if STMT_DEBUG
              printf("statement\n");
#endif
	      seen_term_tok=TRUE;
	      cnt_rule(yyn);
              }        ;
/*
   1.4 - Expressions [gram.expr]
*/
primary_expr:
	id_expression
              {
              $$=$1;
              cnt_rule(yyn);
              }                      |
              CONSTANT
              {
              $$.node_ptr=mk_leaf_node(INTEGER_CONST);
              cnt_rule(yyn);
              }                      |
              string_seq
              {
              $$=$1;
              cnt_rule(yyn);
              }                      |
	THIS
              {
              $$.node_ptr=mk_leaf_node(TOK_THIS);
              cnt_rule(yyn);
              }                      |
              OPEN_RND expression CLOSE_RND
              {
              $$.node_ptr=mk_unary_node(TOK_OPEN_RND, $2.node_ptr);
              cnt_rule(yyn);
              }                      ;

/*
   A made up rule to handle the fact that string concatenation
   is not being handled by a preprocessor (4% of syntax errors).
 */
string_seq: STRING_LITERAL
            {
            $$.node_ptr=mk_leaf_node(STRING_CONST);
            cnt_rule(yyn);
            }                  |
            string_seq STRING_LITERAL
            {
            $$.node_ptr=mk_binary_node(TOK_STRING_CONCAT, $1.node_ptr,
					mk_leaf_node(STRING_CONST));
            cnt_rule(yyn);
            }                  ;

argument_expr_list_opt:
              {
              $$.node_ptr=NULL;
	      cnt_rule(yyn);
              }          |  
              argument_expr_list
              {
              $$=$1;
              cnt_rule(yyn);
              }          ;

id_expression:
	unqualified_id |
	qualified_id   ;

/*
 * unqualified_id includes IDENTIFIER and template_id,
 * just like class_name.  Two less shift-reduce and one
 * less reduce/reduce conflict by using class_name.
 */
unqualified_id:
    type_name              |
	operator_function_id   |
	conversion_function_id |
    bitneg_type_name       ;

/*
 * Could also be unary_operator IDENTIFIER
*/
bitneg_type_name:
	BITNEGATE type_name   ;

cconns_temp_unqual_id:
	cc_opt_nested_n_spec template_opt unqualified_id ;

qualified_id:
    cconns_temp_unqual_id                            |
	COLONCOLON operator_function_id                  |
    COLONCOLON type_name                             ;
/*
 *  IDENTIFIER | template_id is the rule for class_name.
 *  COLONCOLON IDENTIFIER                            |
	COLONCOLON template_id                           ;
*/

cc_opt_nested_n_spec:
	coloncolon_opt nested_name_specifier ;

cc_opt_nested_n_specopt:
	cc_opt_nested_n_spec |
	coloncolon_opt       ;

template_opt:    |
        TEMPLATE ;

coloncolon_opt:
        COLONCOLON       ;

nested_name_specifier:
	type_name COLONCOLON           nested_name_specifier_opt |
	type_name COLONCOLON TEMPLATE  nested_name_specifier     ;

nested_name_specifier_opt:    |
        nested_name_specifier ;

/*
 *	namespace_name <- namespace_alias <- IDENTIFIER
class_or_namespace_name:
	type_name ;
*/

postfix_expr:
              primary_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                             |
              postfix_expr OPEN_SQUARE expression CLOSE_SQUARE
              {
              $$.node_ptr=mk_binary_node(TOK_OPEN_SQUARE, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                             |
              postfix_expr OPEN_RND argument_expr_list_opt CLOSE_RND
              {
              $$.node_ptr=mk_binary_node(TOK_FUNC_CALL, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                             |
/*
 * The following are both a subset of the rules:
 
  	postfix_expr DOT   template_opt id_expression                                                                 |
	postfix_expr DEREF template_opt id_expression                                                                 |

              postfix_expr DOT IDENTIFIER
              {
              $$.node_ptr=mk_binary_node(TOK_DIR_SELECT, $1.node_ptr,
					 mk_leaf_node(TOK_IDENTIFIER));
              cnt_rule(yyn);
              }                             |
              postfix_expr DEREF IDENTIFIER
              {
              $$.node_ptr=mk_binary_node(TOK_INDIR_SELECT, $1.node_ptr,
					 mk_leaf_node(TOK_IDENTIFIER));
              cnt_rule(yyn);
              }                             |
*/
              postfix_expr PLUSPLUS
              {
              $$.node_ptr=mk_unary_node(TOK_POST_PLUS, $1.node_ptr);
              cnt_rule(yyn);
              }                             |
              postfix_expr MINUSMINUS
              {
              $$.node_ptr=mk_unary_node(TOK_POST_MINUS, $1.node_ptr);
              cnt_rule(yyn);
              }                             |
              OPEN_RND type_name CLOSE_RND OPEN_CURL initializer_list CLOSE_CURL
              {
              $$.node_ptr=mk_binary_node(TOK_CMPD_INIT, $2.node_ptr, $5.node_ptr);
              cnt_rule(yyn);
              }                             |
              OPEN_RND type_name CLOSE_RND OPEN_CURL initializer_list COMMA CLOSE_CURL
              {
              $$.node_ptr=mk_binary_node(TOK_CMPD_INIT, $2.node_ptr, $5.node_ptr);
              cnt_rule(yyn);
              }                             |
	simple_type_specifier OPEN_RND argument_expr_list_opt CLOSE_RND |
/*
 * The productions making up TN_cc_nested_ID_tem are shared with
 * elaborated_type_specifier
*/
	TN_cc_nested_ID_temp OPEN_RND argument_expr_list_opt CLOSE_RND  |
    postfix_expr DOT   template_opt id_expression                   |
    postfix_expr DEREF template_opt id_expression                   |
	postfix_expr DOT   pseudo_destructor_name                       |
	postfix_expr DEREF pseudo_destructor_name                       |
	DYNAMIC_CAST LT type_id GT OPEN_RND expression CLOSE_RND        |
	STATIC_CAST LT type_id GT OPEN_RND expression CLOSE_RND         |
	REINTERPRET_CAST LT type_id GT OPEN_RND expression CLOSE_RND    |
	CONST_CAST LT type_id GT OPEN_RND expression CLOSE_RND          |
	TYPEID OPEN_RND expression CLOSE_RND                            |
	TYPEID OPEN_RND type_id CLOSE_RND                               ;

argument_expr_list:
              assignment_expr
              {
              $$.node_ptr=mk_binary_node(TOK_ARG, $1.node_ptr, NULL);
              cnt_rule(yyn);
              }                          |
              argument_expr_list COMMA assignment_expr
              {
              $$.node_ptr=mk_binary_node(TOK_ARG, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                          ;
/*
expression_list:
	assignment_expression
	expression_list COMMA assignment_expression
*/

pseudo_destructor_name:
	stp_decl_id                                  COLONCOLON bitneg_type_name |
	cc_opt_nested_n_spec    TEMPLATE template_id COLONCOLON bitneg_type_name |
	cc_opt_nested_n_specopt                                 bitneg_type_name ;

unary_expr:
              postfix_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                 |
              PLUSPLUS unary_expr
              {
              $$.node_ptr=mk_unary_node(TOK_PRE_PLUS, $2.node_ptr);
              cnt_rule(yyn);
              }                 |
              MINUSMINUS unary_expr
              {
              $$.node_ptr=mk_unary_node(TOK_PRE_MINUS, $2.node_ptr);
              cnt_rule(yyn);
              }                 |
              unary_operator cast_expr
              {
              $$.node_ptr=mk_unary_node($1.tok, $2.node_ptr);
              cnt_rule(yyn);
              }                 |
/*
   We cannot comment out the second production because it
   is needed for uses such as sizeof(enum{a, b})
 */
              SIZEOF unary_expr                   %dprec 2
              {
              $$.node_ptr=mk_unary_node(TOK_SIZEOF, $2.node_ptr);
              cnt_rule(yyn);
              }                 |
	      SIZEOF OPEN_RND type_id CLOSE_RND %dprec 1
              {
              $$.node_ptr=mk_unary_node(TOK_SIZEOF, $3.node_ptr);
              cnt_rule(yyn);
              }                 |
	new_expression          |
	delete_expression       ;

unary_operator:
              BITAND
              {
	      $$.tok=TOK_ADDR;
              cnt_rule(yyn);
              }      |
              TIMES
              {
              $$.tok=TOK_STAR;
              cnt_rule(yyn);
              }      |
              ADD
              {
              $$.tok=TOK_PLUS;
              cnt_rule(yyn);
              }      |
              MINUS
              {
              $$.tok=TOK_ARITH_NEG;
              cnt_rule(yyn);
              }      |
              BITNEGATE
              {
              $$.tok=TOK_BIT_NOT;
              cnt_rule(yyn);
              }      |
              NOT
              {
              $$.tok=TOK_LOG_NOT;
              cnt_rule(yyn);
              }      ;

new_expression:
	coloncolon_opt NEW new_placement_opt new_type_id                new_initializer_opt |
	coloncolon_opt NEW new_placement_opt OPEN_RND type_id CLOSE_RND new_initializer_opt ;

new_placement:
	OPEN_RND argument_expr_list CLOSE_RND ;

new_placement_opt:    |
        new_placement ;

new_type_id:
	type_specifier_seq new_declarator_opt ;

/*
 * 5.3.4p2
 * The new_type_id in a new_expression is the longest possible sequence
 * of new_declarators.
 * new int * i; is parsed as (new int *) i;  not (new int) * i
 * This generates a shift/reduce conflict on the new_declarator_opt
 * in new_type_id & new_declarator.
*/
new_declarator:
	ptr_operator new_declarator_opt |
	direct_new_declarator           ;

new_declarator_opt:    |
        new_declarator ;

direct_new_declarator:
	                      OPEN_SQUARE expression CLOSE_SQUARE    |
	direct_new_declarator OPEN_SQUARE constant_expr CLOSE_SQUARE ;

new_initializer:
	OPEN_RND argument_expr_list_opt CLOSE_RND ;

new_initializer_opt:    |
        new_initializer ;

delete_expression:
	coloncolon_opt DELETE                          cast_expr |
	coloncolon_opt DELETE OPEN_SQUARE CLOSE_SQUARE cast_expr ;

/*
   The token sequence (id)(expr) could be parsed as

      o cast of expr to type id
      o redundant () around the function name in a function call

   The cast is likely to be the most common case.
 */
cast_expr:
              unary_expr                             %dprec 1
              {
              $$=$1;
              cnt_rule(yyn);
              }                             |
              OPEN_RND type_id CLOSE_RND cast_expr %dprec 2
              {
              $$.node_ptr=mk_binary_node(TOK_CAST, $2.node_ptr, $4.node_ptr);
              cnt_rule(yyn);
              }                             ;

pm_expr:
	cast_expr                   |
	pm_expr DOTSTAR   cast_expr |
	pm_expr DEREFSTAR cast_expr ;

/*
   The token sequence (id)*expr can be parsed as:

      o cast of *expr to type id
      o multiplication of (id) and expr

   The cast is assumed to be the common case.
 */
multiplicative_expr:
              pm_expr                           %merge <multiplicative_merge>
              {
	      $$=$1;
              cnt_rule(yyn);
              }                         |
              multiplicative_expr TIMES pm_expr %merge <multiplicative_merge>
              {
              $$.node_ptr=mk_binary_node(TOK_TIMES, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                         |
              multiplicative_expr DIVIDE pm_expr
              {
              $$.node_ptr=mk_binary_node(TOK_DIVIDE, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                         |
              multiplicative_expr REMAINDER pm_expr
              {
              $$.node_ptr=mk_binary_node(TOK_REMAINDER, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                         ;

/*
   The token sequence (id)-expr and (id)+expr could be parsed as

      o cast of -/+expr to type id
      o subtracting/addition between id and expr

   In the case of - the unary minus interpreation is likely
   to be the common case.  Use of unary + is rare and addition
   is likely to be the common case.
 */
additive_expr:
              multiplicative_expr                     %merge <additive_merge>
              {
              $$=$1;
              cnt_rule(yyn);
              }                     |
	      additive_expr ADD multiplicative_expr   %merge <additive_merge>
              {
              $$.node_ptr=mk_binary_node(TOK_ADD, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                     |
              additive_expr MINUS multiplicative_expr %merge <additive_merge>
              {
              $$.node_ptr=mk_binary_node(TOK_MINUS, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                     ;
	
shift_expr:
              additive_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                       |
              shift_expr LEFTSHIFT additive_expr
              {
              $$.node_ptr=mk_binary_node(TOK_LSHIFT, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                       |
              shift_expr RIGHTSHIFT additive_expr
              {
              $$.node_ptr=mk_binary_node(TOK_RSHIFT, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                       ;

relational_expr:
              shift_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                    |
              relational_expr LT shift_expr
              {
              $$.node_ptr=mk_binary_node(TOK_LESS_THAN, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                    |
              relational_expr GT shift_expr
              {
              $$.node_ptr=mk_binary_node(TOK_GREATER_THAN, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                    |
              relational_expr LE shift_expr
              {
              $$.node_ptr=mk_binary_node(TOK_LESS_EQUAL, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                    |
              relational_expr GE shift_expr
              {
              $$.node_ptr=mk_binary_node(TOK_GR_EQUAL, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                    ;

equality_expr:
              relational_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                        |
              equality_expr EQUAL relational_expr
              {
              $$.node_ptr=mk_binary_node(TOK_EQ_EQUAL, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                        |
              equality_expr NOTEQUAL relational_expr
              {
              $$.node_ptr=mk_binary_node(TOK_EXC_EQUAL, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                        ;

/*
   The token sequence (id)&expr can be parsed as:

      o cast of &expr to type id
      o bitwise of (id) and expr

   The cast is assumed to be the common case.
 */
AND_expr:
              equality_expr                 %dprec 2
              {
              $$=$1;
              cnt_rule(yyn);
              }              |
              AND_expr BITAND equality_expr %dprec 1
              {
              $$.node_ptr=mk_binary_node(TOK_BIT_AND, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }              ;

exclusive_OR_expr:
              AND_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                       |
              exclusive_OR_expr XOR AND_expr
              {
              $$.node_ptr=mk_binary_node(TOK_BIT_XOR, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                       ;

inclusive_OR_expr:
              exclusive_OR_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                      |
              inclusive_OR_expr OR exclusive_OR_expr
              {
              $$.node_ptr=mk_binary_node(TOK_BIT_OR, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                      ;

logical_AND_expr:
              inclusive_OR_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                          |
              logical_AND_expr ANDTEST inclusive_OR_expr
              {
              $$.node_ptr=mk_binary_node(TOK_LOG_AND, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                          ;

logical_OR_expr:
              logical_AND_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                        |
              logical_OR_expr ORTEST logical_AND_expr
              {
              $$.node_ptr=mk_binary_node(TOK_LOG_OR, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                        ;

conditional_expr:
              logical_OR_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                                            |
              logical_OR_expr QUESTION expression COLON conditional_expr
              {
              $$.node_ptr=mk_binary_node(TOK_QUESTION, $1.node_ptr,
				mk_binary_node(TOK_COLON, $3.node_ptr, $5.node_ptr));
              cnt_rule(yyn);
              }                                            ;

assignment_expr:
              conditional_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                               |
              logical_OR_expr assignment_operator assignment_expr
              {
              $$.node_ptr=mk_binary_node($2.tok, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                               |
	throw_expression
              {
              $$=$1;
              cnt_rule(yyn);
              }                               ;

assignment_operator:
              ASSIGN
              {
              $$.tok=TOK_EQUAL;
              cnt_rule(yyn);
              }      |
	          TIMESASSIGN
              {
              $$.tok=TOK_MULT_EQUAL;
              cnt_rule(yyn);
              }      |
	          DIVASSIGN
              {
              $$.tok=TOK_DIV_EQUAL;
              cnt_rule(yyn);
              }      |
 	          REMASSIGN
              {
              $$.tok=TOK_REM_EQUAL;
              cnt_rule(yyn);
              }      |
	          PLUSASSIGN
              {
              $$.tok=TOK_PLUS_EQUAL;
              cnt_rule(yyn);
              }     |
	          MINUSASSIGN
              {
              $$.tok=TOK_MIN_EQUAL;
              cnt_rule(yyn);
              }      |
	          LSASSIGN
              {
              $$.tok=TOK_LSH_ASSIGN;
              cnt_rule(yyn);
              }      |
	          RSASSIGN
              {
              $$.tok=TOK_RSH_ASSIGN;
              cnt_rule(yyn);
              }     |
	          ANDASSIGN
              {
              $$.tok=TOK_AND_ASSIGN;
              cnt_rule(yyn);
              }      |
	          ORASSIGN
              {
              $$.tok=TOK_BOR_ASSIGN;
              cnt_rule(yyn);
              }      |
	          XORASSIGN
              {
              $$.tok=TOK_BXOR_ASSIGN;
              cnt_rule(yyn);
              }      ;

expression:
              assignment_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                  |
              expression COMMA assignment_expr
              {
              $$.node_ptr=mk_binary_node(TOK_COMMA, $1.node_ptr, $3.node_ptr);
	      cnt_rule(yyn);
              }                  ;

constant_expr:
              conditional_expr
	      {
	      $$=$1;
              cnt_rule(yyn);
	      }                ;

constant_expr_opt:    |
        constant_expr ;

/*
   1.5 - Statements [gram.stmt.stmt]
*/

statement:
              labeled_statement
              {
              cnt_rule(yyn);
              }     |
              expression_statement
              {
              cnt_rule(yyn);
              }     |
              selection_header
              {
              cnt_rule(yyn);
              }     |
              iteration_header
              {
              cnt_rule(yyn);
              }     |
/*
 * OPEN_CURL, CLOSE_CURL, and ELSE are needed because
 * we are parsing single statements and these occur in
 * 'larger' statements.
 */
              OPEN_CURL
              {
              print_stmt("OC");
              cnt_rule(yyn);
              }     |
              CLOSE_CURL
              {
              print_stmt("CC");
              cnt_rule(yyn);
              }     |
              ELSE
              {
              print_stmt("EL");
              cnt_rule(yyn);
              }     |
              jump_statement
              {
              cnt_rule(yyn);
              }     |
	declaration_statement |
	try_block             ;

labeled_statement:
              IDENTIFIER COLON statement
              {
              cnt_rule(yyn);
              }         |
              CASE constant_expr COLON statement
              {
              got_expression(CASE_LAB_CE, $2.node_ptr);
              free_tree($2.node_ptr);
              cnt_rule(yyn);
              }         |
              DEFAULT COLON statement
              {
              cnt_rule(yyn);
              }         ;

/*
 * In C ; is an empty statement, while in C++
 * we specify it is an empty simple_declaration.
 */
expression_statement:
              expression SEMICOLON
              {
              print_stmt("ES");
              got_expression(EXPR_STMT_EX, $1.node_ptr);
              free_tree($1.node_ptr);
	          cnt_rule(yyn);
              } ;

/*
compound_statement:
	{ statement_seq_opt }

statement_seq:
	statement
	statement_seq  statement

selection_statement:
	if OPEN_RND condition CLOSE_RND     statement
	if OPEN_RND condition CLOSE_RND     statement else statement
	switch OPEN_RND condition CLOSE_RND statement
*/

selection_header:
		  IF OPEN_RND condition CLOSE_RND
              {
              print_stmt("IF");
              got_expression(IF_EXPR_EX, $3.node_ptr);
              free_tree($3.node_ptr);
	      cnt_rule(yyn);
              }       |
		  SWITCH OPEN_RND condition CLOSE_RND
              {
              print_stmt("SW");
              got_expression(SWITCH_EXPR_EX, $3.node_ptr);
              free_tree($3.node_ptr);
	      cnt_rule(yyn);
              }       ;

expr_opt:
              {
              $$.node_ptr=NULL;
              cnt_rule(yyn);
              }      |
              expression
              {
	      cnt_rule(yyn);
              }      ;

condition:
	expression                                           |
	type_specifier_seq declarator ASSIGN assignment_expr ;

condition_opt:  |
    condition   ;

/*
iteration_statement:
	while OPEN_RND condition CLOSE_RND statement
	do    statement  while OPEN_RND expression CLOSE_RND SEMICOLON
	for OPEN_RND for_init_statement condition_opt SEMICOLON expression_opt CLOSE_RND statement

for_init_statement:
	expression_statement
	simple_declaration
*/

iteration_header:
              WHILE OPEN_RND condition CLOSE_RND
              {
              print_stmt("WH");
              got_expression(WHILE_EXPR_EX, $3.node_ptr);
              free_tree($3.node_ptr);
	      cnt_rule(yyn);
              }                                   |
              DO
              {
              print_stmt("DO");
              cnt_rule(yyn);
              }                                   |
/*
   The token sequence for (i ; ; ) can be parsed as

      o for (expr ;
      o for (declaration ;

   The expression form is likely to be the only semantically valid case.
 */
	      FOR OPEN_RND for_init_statement condition_opt SEMICOLON condition_opt CLOSE_RND %dprec 2
              {
              print_stmt("FO");
              got_expression(FOR_INIT_EX, $3.node_ptr);
              free_tree($3.node_ptr);
              got_expression(FOR_CNTRL_EX, $5.node_ptr);
              free_tree($4.node_ptr);
              got_expression(FOR_INC_EX, $7.node_ptr);
              free_tree($6.node_ptr);
              cnt_rule(yyn);
              }                                   ;

for_init_statement:
    expression_statement |
    simple_declaration   ;

jump_statement:
              GOTO IDENTIFIER SEMICOLON
              {
              print_stmt("GO");
              cnt_rule(yyn);
              }           |
              CONTINUE SEMICOLON
              {
              print_stmt("CO");
              cnt_rule(yyn);
              }           |
              BREAK SEMICOLON
              {
              print_stmt("BR");
              cnt_rule(yyn);
              }           |
              RETURN expr_opt SEMICOLON
              {
              print_stmt("RE");
              got_expression(RETURN_EX, $2.node_ptr);
              free_tree($2.node_ptr);
              cnt_rule(yyn);
              }           ;

declaration_statement:
	block_declaration

/*
   1.6 - Declarations [gram.dcl.dcl]
*/

/*
declaration_seq:
	declaration                 |
	declaration_seq declaration ;
*/

declaration:
	block_declaration       |
	function_header         |
	template_declaration    |
	explicit_instantiation  |
	explicit_specialization |
	linkage_specification   |
	namespace_definition    ;

block_declaration:
	simple_declaration         |
	asm_definition             |
	namespace_alias_definition |
	using_declaration          |
	using_directive            ;

simple_declaration:
	decl_specifier_seq_opt init_declarator_list_opt SEMICOLON ;

decl_specifier:
	storage_class_specifier |
	type_specifier          |
	function_specifier      |
	FRIEND                  |
	TYPEDEF                 ;

decl_specifier_seq:
	decl_specifier                    |
	decl_specifier_seq decl_specifier ;

decl_specifier_seq_opt:    |
        decl_specifier_seq ;

/*
   TYPEDEF is not a storage_class_specifier in C++
*/
storage_class_specifier:
              MUTABLE
              {
              cnt_rule(yyn);
              }     |
              EXTERN
              {
              cnt_rule(yyn);
              }     |
              STATIC
              {
              cnt_rule(yyn);
              }     |
              AUTO
              {
              cnt_rule(yyn);
              }     |
              REGISTER
              {
              cnt_rule(yyn);
              }     ;

function_specifier:
	INLINE   |
	VIRTUAL  |
	EXPLICIT ;

/*
typedef_name:
	IDENTIFIER ;
*/
	
type_specifier:
	simple_type_specifier     |
	class_specifier           |
	enum_specifier            |
	elaborated_type_specifier |
	cv_qualifier              ;

/*
 * Same rule is used for simple_type_specifier & declarator_id
 */
stp_decl_id:
	cc_opt_nested_n_specopt type_name ;

simple_type_specifier:
	stp_decl_id                               |
	cc_opt_nested_n_spec TEMPLATE template_id |
	WCHAR_T                                   |
              VOID
              {
              cnt_rule(yyn);
              }           |
              CHAR
              {
              cnt_rule(yyn);
              }           |
              SHORT
              {
              cnt_rule(yyn);
              }           |
              INT
              {
              cnt_rule(yyn);
              }           |
              LONG
              {
              cnt_rule(yyn);
              }           |
              FLOAT
              {
              cnt_rule(yyn);
              }           |
              DOUBLE
              {
              cnt_rule(yyn);
              }           |
              SIGNED
              {
              cnt_rule(yyn);
              }           |
              UNSIGNED
              {
              cnt_rule(yyn);
              }           |
              _BOOL
              {
              cnt_rule(yyn);
              }           ;

identifier_opt:
              {
              cnt_rule(yyn);
              }      |
              IDENTIFIER
              {
              cnt_rule(yyn);
              }      ;

/*
type_name:
	class_name   ;
 * The following both reduce from IDENTIFIER, just like class_name
	enum_name    |
	typedef_name ;
*/

elaborated_type_specifier:
	class_key cc_opt_nested_n_specopt IDENTIFIER                |
	class_key cc_opt_nested_n_specopt template_opt template_id  |
	ENUM      cc_opt_nested_n_specopt IDENTIFIER                |
    TN_cc_nested_ID_temp                                        ;

TN_cc_nested_ID_temp:
	TYPENAME cc_opt_nested_n_spec IDENTIFIER               |
	TYPENAME cc_opt_nested_n_spec template_opt template_id ;

/*
enum_name:
	IDENTIFIER ;
*/

enum_specifier:
	ENUM identifier_opt OPEN_CURL enumerator_list_opt CLOSE_CURL ;

enumerator_list_opt:    |
        enumerator_list ;

enumerator_list:
	enumerator_definition                       |
	enumerator_list COMMA enumerator_definition ;

enumerator_definition:
	enumerator                      |
	enumerator ASSIGN constant_expr ;

enumerator:
	IDENTIFIER ;

/*
 *	original_namespace_name |
*/
namespace_name:
        namespace_alias         ;

/*
original_namespace_name:
        IDENTIFIER ;
*/

namespace_definition:
        named_namespace_definition   |
        unnamed_namespace_definition ;

/*
 *		original_namespace_definition  |
*/
named_namespace_definition:
        extension_namespace_definition ;

/*
original_namespace_definition:
        NAMESPACE IDENTIFIER OPEN_CURL namespace_body CLOSE_CURL ;
*/

/*
        NAMESPACE original_namespace_name OPEN_CURL namespace_body CLOSE_CURL ;
*/
extension_namespace_definition:
        NAMESPACE IDENTIFIER OPEN_CURL ;

/*
        NAMESPACE OPEN_CURL namespace_body CLOSE_CURL ;
*/
unnamed_namespace_definition:
        NAMESPACE OPEN_CURL

/*
namespace_body:
        declaration_seq_opt ;
*/

namespace_alias:
        IDENTIFIER ;

namespace_alias_definition:
        NAMESPACE IDENTIFIER ASSIGN qualified_namespace_specifier SEMICOLON ;

/*
 * stp_decl_id is a superset of:
    cc_opt_nested_n_specopt namespace_name
*/
qualified_namespace_specifier:
    cc_opt_nested_n_specopt namespace_name ;

using_declaration:
        USING typename_opt cc_opt_nested_n_spec unqualified_id SEMICOLON |
        USING COLONCOLON unqualified_id SEMICOLON                        ;

typename_opt:    |
        TYPENAME ;

using_directive:
        USING NAMESPACE cc_opt_nested_n_specopt namespace_name SEMICOLON ;

asm_definition:
	ASM OPEN_RND string_seq CLOSE_RND SEMICOLON ;

/*
	EXTERN string_seq OPEN_CURL declaration_seq_opt CLOSE_CURL |
*/
linkage_specification:
	EXTERN string_seq OPEN_CURL   |
	EXTERN string_seq declaration ;

/*
   1.7 - Declarators [gram.dcl.decl]
*/

init_declarator_list_opt:    |
        init_declarator_list ;

init_declarator_list:
	init_declarator                            |
	init_declarator_list COMMA init_declarator ;

init_declarator:
	declarator initializer_opt ;

declarator:
	direct_declarator       |
	ptr_operator declarator ;

direct_declarator:
	declarator_id                                                                                                      |
	direct_declarator OPEN_RND parameter_declaration_clause CLOSE_RND cv_qualifier_seq_opt exception_specification_opt |
	direct_declarator OPEN_SQUARE constant_expr_opt CLOSE_SQUARE                                                 |
	OPEN_RND declarator CLOSE_RND                                                                                      ;

ptr_operator:
	TIMES cv_qualifier_seq_opt                      |
	BITAND                                          |
	cc_opt_nested_n_spec TIMES cv_qualifier_seq_opt ;

cv_qualifier_seq_opt:    |
        cv_qualifier_seq ;

cv_qualifier_seq:
	cv_qualifier                  |
	cv_qualifier_seq cv_qualifier ;

cv_qualifier:
	CONST    |
	VOLATILE ;

declarator_id:
	id_expression |
	stp_decl_id   ;

type_id:
	type_specifier_seq abstract_declarator_opt ;

type_specifier_seq:
	type_specifier                    |
	type_specifier_seq type_specifier ;

abstract_declarator:
	ptr_operator abstract_declarator_opt |
	direct_abstract_declarator           ;

abstract_declarator_opt:
              {
              cnt_rule(yyn);
              } |
              abstract_declarator
              {
              cnt_rule(yyn);
              } ;

direct_abstract_declarator_opt:    |
        direct_abstract_declarator ;

direct_abstract_declarator:
	direct_abstract_declarator_opt OPEN_RND parameter_declaration_clause CLOSE_RND cv_qualifier_seq_opt exception_specification_opt |
	direct_abstract_declarator_opt OPEN_SQUARE constant_expr_opt CLOSE_SQUARE                  |
	OPEN_RND abstract_declarator CLOSE_RND                                                           ;

parameter_declaration_clause:
	parameter_declaration_list_opt ellipsis_opt |
	parameter_declaration_list COMMA ELLIPSIS   ;

ellipsis_opt:    |
        ELLIPSIS ;

parameter_declaration_list_opt:    |
        parameter_declaration_list ;

parameter_declaration_list:
	parameter_declaration                                  |
	parameter_declaration_list COMMA parameter_declaration ;

parameter_declaration:
	decl_specifier_seq declarator                                     |
	decl_specifier_seq declarator ASSIGN assignment_expr              |
	decl_specifier_seq abstract_declarator_opt                        |
	decl_specifier_seq abstract_declarator_opt ASSIGN assignment_expr ;

/*
function_definition:
	decl_specifier_seq_opt declarator ctor_initializer_opt function_body |
	decl_specifier_seq_opt declarator function_try_block                 ;
*/
function_header:
	decl_specifier_seq_opt declarator ctor_initializer_opt OPEN_CURL |
	decl_specifier_seq_opt declarator function_try_header            ;

/*
function_body:
	compound_statement ;
*/

initializer:
	ASSIGN initializer_clause  |
/*
 * The syntax is the same as new_placement.
*/
	new_placement              ;

initializer_opt:    |
        initializer ;

initializer_clause:
	assignment_expr                             |
	OPEN_CURL initializer_list COMMA CLOSE_CURL |
	OPEN_CURL initializer_list       CLOSE_CURL |
	OPEN_CURL CLOSE_CURL                        ;

initializer_list:
	initializer_clause                        |
	initializer_list COMMA initializer_clause ;

/*
   1.8 - Classes [gram.class]
*/

type_name:
          IDENTIFIER
          {
          $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
          cnt_rule(yyn);
          }                      |
	template_id ;

class_specifier:
	class_head OPEN_CURL member_specification_opt CLOSE_CURL ;

class_head:
	class_key identifier_opt base_clause_opt                        |
	class_key nested_name_specifier IDENTIFIER base_clause_opt      |
	class_key nested_name_specifier_opt template_id base_clause_opt ;

class_key:
	CLASS  |
	STRUCT |
	UNION  ;

member_specification_opt:    |
        member_specification ;

/*
member_specification:
	member_declaration member_specification_opt     |
	access_specifier COLON member_specification_opt ;
*/
member_specification:
    mem_decl_or_acc_spec                      |
    member_specification mem_decl_or_acc_spec ;

mem_decl_or_acc_spec:
	member_declaration     |
    access_specifier COLON ;

member_declaration:
	decl_specifier_seq_opt member_declarator_list_opt SEMICOLON |
/* TODO
	function_definition semicolon_opt                           |
*/
	cconns_temp_unqual_id SEMICOLON                             |
	using_declaration                                           |
	template_declaration                                        ;

semicolon_opt:    |
        SEMICOLON ;

member_declarator_list:
	member_declarator                              |
	member_declarator_list COMMA member_declarator ;

member_declarator_list_opt:    |
        member_declarator_list ;

/*
    declarator pure_specifier_opt       |
*/
member_declarator:
	declarator constant_initializer_opt |
	identifier_opt COLON constant_expr  ;

/*
 * This is a subset of constant_initialiser_opt
pure_specifier_opt: |
	ASSIGN 0 ;
*/

constant_initializer_opt:    |
	ASSIGN constant_expr ;

/*
   1.9 - Derived classes [gram.class.derived]
*/

base_clause_opt:            |
	base_specifier_list ;

base_specifier_list:
	base_specifier                           |
	base_specifier_list COMMA base_specifier ;

base_specifier:
	stp_decl_id                              |
	VIRTUAL access_specifier_opt stp_decl_id |
	access_specifier virtual_opt stp_decl_id ;

access_specifier:
	PRIVATE   |
	PROTECTED |
	PUBLIC    ;

access_specifier_opt:    |
        access_specifier ;

virtual_opt:    |
        VIRTUAL ;

/*
   1.10 - Special member functions [gram.special]
*/

conversion_function_id:
	OPERATOR conversion_type_id ;

/*
 *	type_specifier_seq conversion_declarator_opt ;
*/
conversion_type_id:
	type_specifier_seq ptr_operator_list_opt ;

ptr_operator_list_opt:  |
    ptr_operator_list   ;

ptr_operator_list:
    ptr_operator                   |
    ptr_operator_list ptr_operator ;

ctor_initializer_opt:          |
	COLON mem_initializer_list ;

mem_initializer_list:
	mem_initializer                            |
    mem_initializer_list COMMA mem_initializer ;

mem_initializer:
	stp_decl_id OPEN_RND argument_expr_list_opt CLOSE_RND ;

/*
 *	IDENTIFIER can reduce through cc_opt_nested_n_specopt type_name 
	IDENTIFIER ;

 * Same syntax as stp_decl_id
mem_initializer_id:
	cc_opt_nested_n_specopt type_name ;
*/

/*
   1.11 - Overloading [gram.over]
*/

operator_function_id:
	OPERATOR operator                                  |
	OPERATOR operator LT template_argument_list_opt GT ;

operator:
        ADD    |
        MINUS  |
        TIMES  |
        DIVIDE |
        XOR    |
        AND    |
        BITAND    |
        OR     |
        BITNEGATE |
        NOT    |
        LT     |
        LE     |
        GE     |
        GT     |
        EQUAL      |
        NOTEQUAL   |
        ANDTEST    |
        ORTEST     |
        LEFTSHIFT  |
        RIGHTSHIFT ;
/*
	new  delete    new[]     delete[]
	+    -    *    /    %    ^    &    |    ~
	!    =    <    >    +=   _=   *=   /=   %=
	^=   &=   |=   <<   >>   >>=  <<=  ==   !=
	<=   >=   &&   ||   ++   --   ,    ->*  ->
	()   []
*/

/*
1.12 - Templates [gram.temp]
*/

template_declaration:
	EXPORT template_lt_gt declaration |
           template_lt_gt declaration ;

template_lt_gt:
	TEMPLATE LT template_parameter_list GT ;

template_parameter_list:
	template_parameter                               |
	template_parameter_list COMMA template_parameter ;

template_parameter:
	type_parameter        |
	parameter_declaration ;

type_parameter:
	CLASS identifier_opt                                     |
	CLASS identifier_opt ASSIGN type_id                      |
	TYPENAME identifier_opt                                  |
	TYPENAME identifier_opt ASSIGN type_id                   |
	template_lt_gt CLASS identifier_opt                      |
	template_lt_gt CLASS identifier_opt ASSIGN id_expression ;

template_id:
	IDENTIFIER LT template_argument_list_opt GT ;

/*
template_name:
	IDENTIFIER ;
*/

template_argument_list_opt:    |
        template_argument_list ;

template_argument_list:
	template_argument                              |
	template_argument_list COMMA template_argument ;

/*
 *	id_expression is included in assignment_expr
*/
template_argument:
	assignment_expr |
	type_id         ;

explicit_instantiation:
	TEMPLATE declaration ;

explicit_specialization:
	TEMPLATE LT GT declaration ;

/*
1.13 - Exception handling [gram.except]
*/

/*
try_block:
	 TRY compound_statement handler_seq ;
*/
try_block:
	 TRY OPEN_CURL          |
         CLOSE_CURL handler_seq ;

/*
function_try_block:
	 TRY ctor_initializer_opt function_body handler_seq ;
*/
function_try_header:
	 TRY ctor_initializer_opt OPEN_CURL |
         CLOSE_CURL handler_seq             ;

handler_seq:
	handler             |
	handler_seq handler ;

/*
handler:
	CATCH OPEN_RND exception_declaration CLOSE_RND compound_statement ;
*/
handler:
	CATCH OPEN_RND exception_declaration CLOSE_RND OPEN_CURL ;

exception_declaration:
	type_specifier_seq declarator          |
	type_specifier_seq abstract_declarator |
	type_specifier_seq                     |
	ELLIPSIS                               ;

throw_expression:
	THROW                 |    
	THROW assignment_expr ;

exception_specification_opt:                  |
	THROW OPEN_RND              CLOSE_RND |
	THROW OPEN_RND type_id_list CLOSE_RND ;

type_id_list:
	type_id                    |
	type_id_list COMMA type_id ;

/*
1.14 - Preprocessing directives [gram.cpp]

preprocessing_file:
	group_opt

group:
	group_part
	group group_part

group_part:
	pp_tokens_opt new_line
	if_section
	control_line

if_section:
	if_group elif_groups_opt else_group_opt endif_line

if_group:
	# if     constant_expression new_line group_opt
	# ifdef  identifier new_line group_opt
	# ifndef identifier new_line group_opt

elif_groups:
	elif_group
	elif_groups elif_group

elif_group:
	# elif   constant_expression new_line group_opt

else_group:
	# else   new_line group_opt

endif_line:
	# endif  new_line

control_line:
	# include pp_tokens new_line
	# define  identifierreplacement_list new_line
	# define  identifierlparen identifier_list_opt ) replacement_list new_line
	# undef   identifiernew_line
	# line    pp_tokens new_line
	# error   pp_tokens_opt     new_line
	# pragma  pp_tokens_opt     new_line
	# new_line

lparen:
	the left_parenthesis character without preceding white_space

replacement_list:
	pp_tokens_opt

pp_tokens:
	preprocessing_token
	pp_tokens preprocessing_token

new_line:
	the new_line character
*/

%%