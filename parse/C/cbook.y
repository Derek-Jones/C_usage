                       /* cbook.y, 21 May 08 */

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
UNDEFINED

%%

/*
                        Annex A
                     (informative)


                Language syntax summary

NOTE  The notation is described in 6.1.

A.1  Lexical grammar

A.1.1  Lexical elements

(6.4) token:
              keyword
              identifier
              constant
              string-literal
              punctuator
(6.4) preprocessing-token:
              header-name
              identifier
              pp-number
              character-constant
              string-literal
              punctuator
              each non-white-space character that cannot be one of the above

A.1.2  Keywords

(6.4.1) keyword: one of
        auto        enum        restrict    unsigned
        break       extern      return      void
        case        float       short       volatile
        char        for         signed      while
        const       goto        sizeof      _Bool
        continue    if          static      _Complex
        default     inline      struct      _Imaginary
        do          int         switch
        double      long        typedef
        else        register    union

A.1.3  Identifiers

(6.4.2.1) identifier:
              identifier-nondigit
              identifier identifier-nondigit
              identifier digit
(6.4.2.1) identifier-nondigit:
              nondigit
              universal-character-name
              other implementation-defined characters
(6.4.2.1) nondigit: one of
              _  a  b  c  d  e  f  g  h  i  j  k  l  m
                 n  o  p  q  r  s  t  u  v  w  x  y  z
                 A  B  C  D  E  F  G  H  I  J  K  L  M
                 N  O  P  Q  R  S  T  U  V  W  X  Y  Z
(6.4.2.1) digit: one of
              0  1  2  3  4  5  6  7  8  9

A.1.4  Universal character names

(6.4.3) universal-character-name:
              \u hex-quad
              \U hex-quad hex-quad
(6.4.3) hex-quad:
              hexadecimal-digit hexadecimal-digit
                              hexadecimal-digit hexadecimal-digit

A.1.5  Constants

(6.4.4) constant:
              integer-constant
              floating-constant
              enumeration-constant
              character-constant
(6.4.4.1) integer-constant:
              decimal-constant integer-suffix-opt
              octal-constant integer-suffix-opt
              hexadecimal-constant integer-suffix-opt
(6.4.4.1) decimal-constant:
              nonzero-digit
              decimal-constant digit
(6.4.4.1) octal-constant:
              0
              octal-constant octal-digit
(6.4.4.1) hexadecimal-constant:
              hexadecimal-prefix hexadecimal-digit
              hexadecimal-constant hexadecimal-digit
(6.4.4.1) hexadecimal-prefix: one of
              0x  0X
(6.4.4.1) nonzero-digit: one of
              1  2  3  4  5  6  7  8  9
(6.4.4.1) octal-digit: one of
              0  1  2  3  4  5  6  7
(6.4.4.1) hexadecimal-digit: one of
              0  1  2  3  4  5  6  7  8  9
              a  b  c  d  e  f
              A  B  C  D  E  F
(6.4.4.1) integer-suffix:
              unsigned-suffix long-suffix-opt
              unsigned-suffix long-long-suffix
              long-suffix unsigned-suffix-opt
              long-long-suffix unsigned-suffix-opt
(6.4.4.1) unsigned-suffix: one of
              u  U
(6.4.4.1) long-suffix: one of
              l  L
(6.4.4.1) long-long-suffix: one of
              ll  LL
(6.4.4.2) floating-constant:
              decimal-floating-constant
              hexadecimal-floating-constant
(6.4.4.2) decimal-floating-constant:
              fractional-constant exponent-part-opt floating-suffix-opt
              digit-sequence exponent-part floating-suffix-opt
(6.4.4.2) hexadecimal-floating-constant:
              hexadecimal-prefix hexadecimal-fractional-constant
                              binary-exponent-part floating-suffix-opt
              hexadecimal-prefix hexadecimal-digit-sequence
                              binary-exponent-part floating-suffix-opt
(6.4.4.2) fractional-constant:
              digit-sequence-opt . digit-sequence
              digit-sequence .
(6.4.4.2) exponent-part:
              e sign-opt digit-sequence
              E sign-opt digit-sequence
(6.4.4.2) sign: one of
              +  -
(6.4.4.2) digit-sequence:
              digit
              digit-sequence digit
(6.4.4.2) hexadecimal-fractional-constant:
              hexadecimal-digit-sequence-opt .
                              hexadecimal-digit-sequence
              hexadecimal-digit-sequence .
(6.4.4.2) binary-exponent-part:
              p sign-opt digit-sequence
              P sign-opt digit-sequence
(6.4.4.2) hexadecimal-digit-sequence:
              hexadecimal-digit
              hexadecimal-digit-sequence hexadecimal-digit
(6.4.4.2) floating-suffix: one of
              f  l  F  L
(6.4.4.3) enumeration-constant:
              identifier
(6.4.4.4) character-constant:
              ' c-char-sequence '
              L' c-char-sequence '
(6.4.4.4) c-char-sequence:
              c-char
              c-char-sequence c-char
(6.4.4.4) c-char:
              any member of the source character set except
                              the single-quote ', backslash \, or new-line character
              escape-sequence
(6.4.4.4) escape-sequence:
              simple-escape-sequence
              octal-escape-sequence
              hexadecimal-escape-sequence
              universal-character-name
(6.4.4.4) simple-escape-sequence: one of
              \'  \"  \?  \\
              \a  \b  \f  \n  \r  \t  \v
(6.4.4.4) octal-escape-sequence:
              \ octal-digit
              \ octal-digit octal-digit
              \ octal-digit octal-digit octal-digit
(6.4.4.4) hexadecimal-escape-sequence:
              \x hexadecimal-digit
              hexadecimal-escape-sequence hexadecimal-digit

A.1.6  String literals

(6.4.5) string-literal:
              " s-char-sequence-opt "
              L" s-char-sequence-opt "
(6.4.5) s-char-sequence:
              s-char
              s-char-sequence s-char
(6.4.5) s-char:
              any member of the source character set except
                              the double-quote ", backslash \, or new-line character
              escape-sequence

A.1.7  Punctuators

(6.4.6) punctuator: one of
              [  ]  (  )  {  }  .  ->
              ++  --  &  *  +  -  ~  !
              /  %  <<  >>  <  >  <=  >=  ==  !=  ^  |  &&  ||
              ?  :  ;  ...
              =  *=  /=  %=  +=  -=  <<=  >>=  &=  ^=  |=
              ,  #  ##
              <:  :>  <%  %>  %:  %:%:

A.1.8  Header names

(6.4.7) header-name:
              < h-char-sequence >
              " q-char-sequence "
(6.4.7) h-char-sequence:
              h-char
              h-char-sequence h-char
(6.4.7) h-char:
              any member of the source character set except
                              the new-line character and >
(6.4.7) q-char-sequence:
              q-char
              q-char-sequence q-char

(6.4.7) q-char:
              any member of the source character set except
                              the new-line character and "

A.1.9  Preprocessing numbers

(6.4.8) pp-number:
              digit
              . digit
              pp-number digit
              pp-number identifier-nondigit
              pp-number e sign
              pp-number E sign
              pp-number p sign
              pp-number P sign
              pp-number .
*/

/* A.2  Phrase structure grammar */

/* (6.9) */
TU:
	translation_unit
	{
        if (seen_ES)
	   {
	   TRACE_LOG("ES");
	   }
        else if (seen_DC)
	   {
	   TRACE_LOG("DC");
	   }
	}                   ;
/*
   An attempt is made to parse the token sequence:

      static foo bar;
      static int foo (lose);

   as two declarations (i.e., the second static does not cause the
   first line to reduce through declaration) unless this production
   is commented out

	TU translation_unit ;
 */

translation_unit:
              external_declaration  %merge <stmt_decl_merge>
              {
#if STMT_DEBUG
              printf("declaration\n");
#endif
              seen_term_tok=TRUE;
	      cnt_rule(yyn);
              }        |
              statement             %merge <stmt_decl_merge>
              {
#if STMT_DEBUG
              printf("statement\n");
#endif
	      seen_term_tok=TRUE;
	      cnt_rule(yyn);
              }        ;

/* A.2.1  Expressions */

/* (6.5.1) */
primary_expr:
              IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
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
            }                  |
/*
   Extension.  The following handle the case where a macro expands
   to a string that is then expected to be concatenated with
   an adjacent string.
 */
            string_seq IDENTIFIER
            {
            $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
            $$=$1;
            cnt_rule(yyn);
            }                  |
            string_seq IDENTIFIER OPEN_RND constant_expr CLOSE_RND
            {
            $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
            $$=$1;
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
/* (6.5.2) */
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
              }                             ;

/* (6.5.2) */
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

/* (6.5.3) */
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
	      SIZEOF OPEN_RND type_name CLOSE_RND %dprec 1
              {
              $$.node_ptr=mk_unary_node(TOK_SIZEOF, $3.node_ptr);
              cnt_rule(yyn);
              }                 ;

/* (6.5.3) */
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

/* (6.5.4) */
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
              OPEN_RND type_name CLOSE_RND cast_expr %dprec 2
              {
              $$.node_ptr=mk_binary_node(TOK_CAST, $2.node_ptr, $4.node_ptr);
              cnt_rule(yyn);
              }                             ;

/* (6.5.5) */
/*
   The token sequence (id)*expr can be parsed as:

      o cast of *expr to type id
      o multiplication of (id) and expr

   The cast is assumed to be the common case.
 */
multiplicative_expr:
              cast_expr                           %merge <multiplicative_merge>
              {
	      $$=$1;
              cnt_rule(yyn);
              }                         |
              multiplicative_expr TIMES cast_expr %merge <multiplicative_merge>
              {
              $$.node_ptr=mk_binary_node(TOK_TIMES, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                         |
              multiplicative_expr DIVIDE cast_expr
              {
              $$.node_ptr=mk_binary_node(TOK_DIVIDE, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                         |
              multiplicative_expr REMAINDER cast_expr
              {
              $$.node_ptr=mk_binary_node(TOK_REMAINDER, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                         ;
/*
   See discussion for additive_expr
              cast_expr                           %dprec 2
                                       |
              cast_expr TIMES multiplicative_expr %dprec 1
                                       |
              cast_expr DIVIDE multiplicative_expr
                                       |
              cast_expr REMAINDER multiplicative_expr
                                       ;
 */

/* (6.5.6) */
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
	      
/*
   The token sequencwe x + (y) + z can be parsed as

                +
	      /   \
	     x  (cast)
	         /  \
		y    z

   or as

               +
	     /   \
	    +     z
	  /   \
	 x    (y)

   The functionality provided by %dprec does not help here (it
   essentially requires the tagged productions to consume the
   same token sequence.
   In this case the only solution is to rewrite the productions
   to be right recursive :-(

              multiplicative_expr                     %dprec 2
                                   |
	      multiplicative_expr ADD additive_expr   %dprec 3
                                   |
              multiplicative_expr MINUS additive_expr %dprec 1
                                   ;
*/

/* (6.5.7) */
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

/* (6.5.8) */
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

/* (6.5.9) */
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

/* (6.5.10) */
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
/*
   See discussion for additive_expr
              equality_expr              %dprec 2
                            |
              equality_expr AND AND_expr %dprec 1
                            ;
 */

/* (6.5.11) */
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

/* (6.5.12) */
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

/* (6.5.13) */
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

/* (6.5.14) */
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

/* (6.5.15) */
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

/* (6.5.16) */
assignment_expr:
              conditional_expr
              {
              $$=$1;
              cnt_rule(yyn);
              }                               |
              unary_expr assignment_operator assignment_expr
              {
              $$.node_ptr=mk_binary_node($2.tok, $1.node_ptr, $3.node_ptr);
              cnt_rule(yyn);
              }                               ;

/* (6.5.16) */
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

/* (6.5.17) */
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

/* (6.6) */
constant_expr:
              conditional_expr
	      {
	      $$=$1;
              cnt_rule(yyn);
	      }                ;

/* A.2.2  Declarations */

/*

Causes a reduction ambiguity with declaration_specifiers_opt

init_declarator_list_opt:
              {
              cnt_rule(yyn);
              }          |    
              init_declarator_list
              {
              cnt_rule(yyn);
              }          ;
*/

/* (6.7) */
/*
   In the declaration int i; the identifier i can reduce via:
   
      o type-specifier to give a list of declaration specifiers
      o identifier to give an init-declarator-list

   We prefer the second option.
*/
declaration:
              declaration_specifiers                      SEMICOLON %dprec 1
              {
              cnt_rule(yyn);
              }                                           |
              declaration_specifiers init_declarator_list SEMICOLON %dprec 2
              {
              cnt_rule(yyn);
              }                                           ;

/* (6.7) */
/*
   The C Standard production is right recursive.  Change to left recursive.
 */
decl_specifier:
              storage_class_specifier
              {
              cnt_rule(yyn);
              }            |
              type_specifier
              {
              cnt_rule(yyn);
              }            |
              type_qualifier
              {
              cnt_rule(yyn);
              }            |
              function_specifier
              {
              cnt_rule(yyn);
              }            ;

declaration_specifiers:
              decl_specifier
              {
              cnt_rule(yyn);
              }            |
              declaration_specifiers decl_specifier
              {
              cnt_rule(yyn);
              }            ;

/* (6.7) */
init_declarator_list:
              init_declarator
              {
              cnt_rule(yyn);
              }                            |
              init_declarator_list COMMA init_declarator
              {
              cnt_rule(yyn);
              }                            ;

/* (6.7) */
init_declarator:
              declarator
              {
              cnt_rule(yyn);
              }                    |
              declarator ASSIGN initializer
              {
              got_expression(INIT_EX, $3.node_ptr);
              cnt_rule(yyn);
              }                    ;

/* (6.7.1) */
storage_class_specifier:
              TYPEDEF
              {
              $$.node_ptr=mk_leaf_node(TOK_TYPEDEF);
              cnt_rule(yyn);
              }     |
              EXTERN
              {
              $$.node_ptr=mk_leaf_node(TOK_EXTERN);
              cnt_rule(yyn);
              }     |
              STATIC
              {
              $$.node_ptr=mk_leaf_node(TOK_STATIC);
              cnt_rule(yyn);
              }     |
              AUTO
              {
              $$.node_ptr=mk_leaf_node(TOK_AUTO);
              cnt_rule(yyn);
              }     |
              REGISTER
              {
              $$.node_ptr=mk_leaf_node(TOK_REGISTER);
              cnt_rule(yyn);
              }     ;

/* (6.7.2) */
type_specifier:
              VOID
              {
              $$.node_ptr=mk_leaf_node(TOK_VOID);
              cnt_rule(yyn);
              }           |
              CHAR
              {
              $$.node_ptr=mk_leaf_node(TOK_CHAR);
              cnt_rule(yyn);
              }           |
              SHORT
              {
              $$.node_ptr=mk_leaf_node(TOK_SHORT);
              cnt_rule(yyn);
              }           |
              INT
              {
              $$.node_ptr=mk_leaf_node(TOK_INT);
              cnt_rule(yyn);
              }           |
              LONG
              {
              $$.node_ptr=mk_leaf_node(TOK_LONG);
              cnt_rule(yyn);
              }           |
              FLOAT
              {
              $$.node_ptr=mk_leaf_node(TOK_FLOAT);
              cnt_rule(yyn);
              }           |
              DOUBLE
              {
              $$.node_ptr=mk_leaf_node(TOK_DOUBLE);
              cnt_rule(yyn);
              }           |
              SIGNED
              {
              $$.node_ptr=mk_leaf_node(TOK_SIGNED);
              cnt_rule(yyn);
              }           |
              UNSIGNED
              {
              $$.node_ptr=mk_leaf_node(TOK_UNSIGNED);
              cnt_rule(yyn);
              }           |
              _BOOL
              {
              $$.node_ptr=mk_leaf_node(TOK__BOOL);
              cnt_rule(yyn);
              }           |
              _COMPLEX
              {
              $$.node_ptr=mk_leaf_node(TOK__COMPLEX);
              cnt_rule(yyn);
              }           |
              _IMAGINARY
              {
              $$.node_ptr=mk_leaf_node(TOK__IMAGINARY);
              cnt_rule(yyn);
              }           |
              struct_or_union_specifier
              {
              cnt_rule(yyn);
              }           |
              enum_specifier
              {
              cnt_rule(yyn);
              }           |
              typedef_name
              {
              cnt_rule(yyn);
              }           ;

identifier_opt:
              {
              cnt_rule(yyn);
              }      |
              IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              }      ;

/* (6.7.2.1) */
struct_or_union_specifier:
              struct_or_union identifier_opt OPEN_CURL struct_declaration_list CLOSE_CURL
              {
              $$=$2;
	      cnt_rule(yyn);
              }   |
              struct_or_union IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              }   ;

/* (6.7.2.1) */
struct_or_union:
              STRUCT
              {
              cnt_rule(yyn);
              }  |
              UNION
              {
              cnt_rule(yyn);
              }  ;

/* (6.7.2.1) */
struct_declaration_list:
              struct_declaration
              {
              cnt_rule(yyn);
              }                         |
              struct_declaration_list struct_declaration
              {
              cnt_rule(yyn);
              }                         ;

/* (6.7.2.1) */
struct_declaration:
              specifier_qualifier_list struct_declarator_list SEMICOLON
              {
              cnt_rule(yyn);
              }                         ;

/* (6.7.2.1) */
spec_qual:
              type_specifier
              {
              cnt_rule(yyn);
              }           |
              type_qualifier
              {
              cnt_rule(yyn);
              }           ;

/*
   The C Standard production is right recursive.  Change to left recursive.
 */
specifier_qualifier_list:
              spec_qual
              {
              cnt_rule(yyn);
              }                        |
              specifier_qualifier_list spec_qual
              {
              $$.node_ptr=mk_qualifier_list($1.node_ptr, $2.node_ptr);
              cnt_rule(yyn);
              }                        ;

/* (6.7.2.1) */
struct_declarator_list:
              struct_declarator
              {
              cnt_rule(yyn);
              }                        |
              struct_declarator_list COMMA struct_declarator
              {
              cnt_rule(yyn);
              }                        ;

/*
declarator_opt:
              {
              cnt_rule(yyn);
              }      |
              declarator
              {
              cnt_rule(yyn);
              }      ;
*/

/* (6.7.2.1) */
struct_declarator:
              declarator
              {
              cnt_rule(yyn);
              }                         |
                         COLON constant_expr
              {
              got_expression(EMPT_COLON_CE, $2.node_ptr);
	      cnt_rule(yyn);
              }                         ;
/*
   In struct { int i : 3; } i could reduce through

      o type-specifier and then through specifier_qualifier_list
      o identifier and then through declarator

  this ambiguity is very fiddly to resolve using dprec.  Always
  taking the type-specifier route may not be the common case,
  but it requires the minimal number of changes to the grammar.

              declarator COLON constant_expr
              {
              } ;
*/

/* (6.7.2.2) */
enum_specifier:
              ENUM identifier_opt OPEN_CURL enumerator_list CLOSE_CURL
              {
              $$.node_ptr=mk_leaf_node(TOK_ENUM);
              cnt_rule(yyn);
              }            |
              ENUM identifier_opt OPEN_CURL enumerator_list COMMA CLOSE_CURL
              {
              $$.node_ptr=mk_leaf_node(TOK_ENUM);
              cnt_rule(yyn);
              }            |
              ENUM IDENTIFIER
              {
	      /*
	       * All instances of IDENTIFIER in the grammar need a mk_leaf_node
	       * so that previously pushed identifiers get popped in the
	       * correct order.
	       */
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              $$.node_ptr=mk_leaf_node(TOK_ENUM);
              cnt_rule(yyn);
              }            ;

/* (6.7.2.2) */
enumerator_list:
              enumerator
              {
              cnt_rule(yyn);
              }                       |
              enumerator_list COMMA enumerator
              {
              cnt_rule(yyn);
              }                       ;

/* (6.7.2.2) */
enumerator:
              IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              }                   |
              IDENTIFIER ASSIGN constant_expr
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              got_expression(ENUM_INITIAL_CE, $3.node_ptr);
              cnt_rule(yyn);
              }                   ;

/* (6.7.3) */
type_qualifier:
              CONST
              {
              $$.node_ptr=mk_leaf_node(TOK_CONST);
              cnt_rule(yyn);
              }    |
              RESTRICT
              {
              $$.node_ptr=mk_leaf_node(TOK_RESTRICT);
              cnt_rule(yyn);
              } |
              VOLATILE
              {
              $$.node_ptr=mk_leaf_node(TOK_VOLATILE);
              cnt_rule(yyn);
              } ;

/* (6.7.4) */
function_specifier:
              INLINE
              {
              cnt_rule(yyn);
              } ;

pointer_opt:
              {
              cnt_rule(yyn);
              }          |
              pointer
              {
              cnt_rule(yyn);
              } ;
/* (6.7.5) */
declarator:
              pointer_opt direct_declarator
              {
              cnt_rule(yyn);
              } ;
fndef_declarator:
              pointer_opt fndef_direct_declarator
              {
              cnt_rule(yyn);
              } ;
type_qualifier_list_opt:
              {
              cnt_rule(yyn);
              }          |
              type_qualifier_list
              {
              cnt_rule(yyn);
              } ;
assignment_expr_opt:
              {
              cnt_rule(yyn);
              }          |
              assignment_expr
              {
              cnt_rule(yyn);
              } ;
/*
identifier_list_opt:
              {
              cnt_rule(yyn);
              }          |
              identifier_list
              {
              cnt_rule(yyn);
              } ;
*/
/* (6.7.5) */
/*
   The sequence unsigned f(i); could be a

      o declaration of f to return unsigned and take a single argument
      o declaration of i to have type unsigned f

   The likely common case is a function definition.
   The problem is that %dprec cannot be used to distinguish between
     OPEN_RND declarator CLOSE_RND and (fndef_direct_declarator or
     direct_declarator OPEN_RND parameter_type_list CLOSE_RND)
 */
direct_declarator:
              IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              }                |
              OPEN_RND declarator CLOSE_RND
              {
/*
   printf("( declarator )\n");
*/
              cnt_rule(yyn);
              }                |
              direct_declarator OPEN_SQUARE STATIC type_qualifier_list_opt assignment_expr CLOSE_SQUARE
              {
              got_expression(DIR_DECL_EX, $5.node_ptr);
              cnt_rule(yyn);
              }                |
              direct_declarator OPEN_SQUARE type_qualifier_list STATIC assignment_expr CLOSE_SQUARE
              {
              got_expression(DIR_DECL_EX, $5.node_ptr);
              cnt_rule(yyn);
              }                |
              direct_declarator OPEN_SQUARE type_qualifier_list_opt TIMES CLOSE_SQUARE
              {
              cnt_rule(yyn);
              }                |
	      fndef_direct_declarator
              {
              cnt_rule(yyn);
              }                ;

fndef_direct_declarator:
              direct_declarator OPEN_SQUARE type_qualifier_list_opt assignment_expr_opt CLOSE_SQUARE
              {
              got_expression(DIR_DECL_EX, $4.node_ptr);
              cnt_rule(yyn);
              }                |
              direct_declarator OPEN_RND parameter_type_list CLOSE_RND
              {
/*
	      printf("direct_decl ( param type list )\n");
*/
              cnt_rule(yyn);
              }                |
/*
   Code written to support translators written before prototypes were
   generally available often uses a macro based technique for switching
   prototypes on/off.  Such usage usually involves extra matching ( and ),
   and requires preprocessing before it is syntactically correct.
   The following rule adds support for this syntax.
   A rule having the form
   
      direct_declarator IDENTIFIER OPEN_RND OPEN_RND ...

   might be thought to closer reflect reality and improve performance.
   However, ambiguities increase from 16 to 19 (on the book's benchmarks)
   and there is one more reduce/reduce conflict in the grammar.
 */
              direct_declarator OPEN_RND OPEN_RND parameter_type_list CLOSE_RND CLOSE_RND
              {
              cnt_rule(yyn);
              }                |
              direct_declarator OPEN_RND CLOSE_RND
              {
              cnt_rule(yyn);
              }                ;
/*
   No point using dprec to disambiguate what is essentially (from a syntax point
   of view) a rule that is almost a pure subset of that rule.

              direct_declarator OPEN_RND parameter_type_list CLOSE_RND %dprec 2
              direct_declarator OPEN_RND identifier_list_opt CLOSE_RND %dprec 1
              {
              cnt_rule(yyn);
              }                ;
*/

/* (6.7.5) */
pointer:
              TIMES type_qualifier_list_opt
              {
              cnt_rule(yyn);
              }         |
              TIMES type_qualifier_list_opt pointer
              {
              cnt_rule(yyn);
              } ;

/* (6.7.5) */
type_qualifier_list:
              type_qualifier
              {
              cnt_rule(yyn);
              }                     |
              type_qualifier_list type_qualifier
              {
              cnt_rule(yyn);
              } ;

/* (6.7.5) */
parameter_type_list:
              parameter_list
              {
              cnt_rule(yyn);
              }                |
              parameter_list COMMA ELLIPSIS
              {
              cnt_rule(yyn);
              } ;

/* (6.7.5) */
parameter_list:
              parameter_declaration
              {
              cnt_rule(yyn);
              }                      |
              parameter_list COMMA parameter_declaration
              {
              cnt_rule(yyn);
              } ;

abstract_declarator_opt:
              {
              cnt_rule(yyn);
              }          |
              abstract_declarator
              {
              cnt_rule(yyn);
              } ;
/* (6.7.5) */
/*
   There is an ambiguity in void f(int p) in that it is possible for
   p to reduce as 
   
      o a typedef via declarations specifiers
      o an identifier via declarator
   
   The likely common case is given preference.

   There is an ambiguity in x ( y ( z (a))) in that it is possible for
   z (a) to reduce as

      o an abstract declarator (with a being a typedef-name)
      o a declarator (with a being an direct-declarator)
  
   In this context a is likely to be a typedef-name .
 */
parameter_declaration:
              declaration_specifiers declarator          %dprec 2
              {
              cnt_rule(yyn);
              }              |
              declaration_specifiers                     %dprec 1
              {
              cnt_rule(yyn);
              }              |
              declaration_specifiers abstract_declarator %dprec 3
              {
              cnt_rule(yyn);
              }              ;

/* (6.7.5) */
/*
identifier_list:
              IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              }                       |
              identifier_list COMMA IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              } ;
*/

/* (6.7.6) */
type_name:
              specifier_qualifier_list abstract_declarator_opt
              {
              $$.node_ptr=mk_leaf_node(TOK_TYPEOF);
              cnt_rule(yyn);
              } ;

/* (6.7.6) */
abstract_declarator:
              pointer
              {
              cnt_rule(yyn);
              }          |
              pointer_opt direct_abstract_declarator
              {
              cnt_rule(yyn);
              }          ;

direct_abstract_declarator_opt:
              {
              cnt_rule(yyn);
              }          |
              direct_abstract_declarator
              {
              cnt_rule(yyn);
              }          ;
parameter_type_list_opt:
              {
              cnt_rule(yyn);
              }          |
              parameter_type_list
              {
              cnt_rule(yyn);
              }          ;
/* (6.7.6) + DR #289 update */
direct_abstract_declarator:
              OPEN_RND abstract_declarator CLOSE_RND
              {
              cnt_rule(yyn);
              }   |
              direct_abstract_declarator_opt OPEN_SQUARE type_qualifier_list_opt assignment_expr_opt CLOSE_SQUARE
              {
              print_filename();
	      got_expression(DIR_ABSDECL_EX, $4.node_ptr);
              cnt_rule(yyn);
              }   |
              direct_abstract_declarator_opt OPEN_SQUARE STATIC type_qualifier_list_opt assignment_expr CLOSE_SQUARE
              {
              print_filename();
              got_expression(DIR_ABSDECL_EX, $5.node_ptr);
              cnt_rule(yyn);
              }   |
              direct_abstract_declarator_opt OPEN_SQUARE type_qualifier_list STATIC assignment_expr CLOSE_SQUARE
              {
              print_filename();
              got_expression(DIR_ABSDECL_EX, $5.node_ptr);
              cnt_rule(yyn);
              }   |
              direct_abstract_declarator_opt OPEN_SQUARE TIMES CLOSE_SQUARE
              {
              print_filename();
              cnt_rule(yyn);
              }   |
              direct_abstract_declarator_opt OPEN_RND parameter_type_list_opt CLOSE_RND
              {
              cnt_rule(yyn);
              } ;

/* (6.7.7) */
/*
   See discussion for direct_declarator.
 */
typedef_name:
              IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              } ;

/* (6.7.8) */
initializer:
              assignment_expr
              {
              $$=$1;
              }                             |
              OPEN_CURL initializer_list CLOSE_CURL
              {
              $$.node_ptr=mk_unary_node(TOK_OPEN_CURL, $2.node_ptr);
              }       |
              OPEN_CURL initializer_list COMMA CLOSE_CURL
              {
              $$.node_ptr=mk_unary_node(TOK_OPEN_CURL, $2.node_ptr);
              } ;

designation_opt:
              {
              cnt_rule(yyn);
              }          |
              designation
              {
              cnt_rule(yyn);
              } ;
/* (6.7.8) */
initializer_list:
              designation_opt initializer
              {
              $$.node_ptr=mk_binary_node(TOK_ARG, $2.node_ptr, NULL);
              }                        |
              initializer_list COMMA designation_opt initializer
              {
              $$.node_ptr=mk_binary_node(TOK_ARG, $1.node_ptr, $4.node_ptr);
              }                        |
              /* empty
                 Extension to support an empty list so that declarations
		 that use a #include'd initializer list don't generate
		 a syntax error.
	      */
              {
              $$.node_ptr=NULL;
              }                        ;

/* (6.7.8) */
designation:
              designator_list ASSIGN
              {
              cnt_rule(yyn);
              } ;

/* (6.7.8) */
designator_list:
              designator
              {
              cnt_rule(yyn);
              }                 |
              designator_list designator
              {
              cnt_rule(yyn);
              }                 ;

/* (6.7.8) */
designator:
              OPEN_SQUARE constant_expr CLOSE_SQUARE
              {
              got_expression(DESIGNATOR_CE, $2.node_ptr);
              cnt_rule(yyn);
              }                         |
              DOT IDENTIFIER
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              }                         ;

/* A.2.3  Statements */

/* (6.8) */
/*
 *			  compound_statement
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
              TRACE_LOG("{_");
              cnt_rule(yyn);
              }     |
              CLOSE_CURL
              {
              TRACE_LOG("}_");
              cnt_rule(yyn);
              }     |
              ELSE
              {
              TRACE_LOG("EL");
              cnt_rule(yyn);
              }     |
              jump_statement
              {
              cnt_rule(yyn);
              }     ;

/* (6.8.1) */
labeled_statement:
              IDENTIFIER COLON statement
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              }         |
              CASE constant_expr COLON {TRACE_LOG("CA");} statement
              {
              got_expression(CASE_LAB_CE, $2.node_ptr);
              cnt_rule(yyn);
              }         |
              DEFAULT COLON {TRACE_LOG("DE");} statement
              {
              cnt_rule(yyn);
              }         ;

/*
block_item_list_opt:          |
              block_item_list ;
   (6.8.2)
compound_statement:
              OPEN_CURL block_item_list_opt CLOSE_CURL ;
							  
   (6.8.2)
block_item_list:
              block_item  |
              block_item_list block_item ;

   (6.8.2)   
block_item:
              declaration |
              statement   ;
*/

/* (6.8.3) */
expression_statement:
              expr_opt SEMICOLON
              {
              seen_ES=TRUE;
              got_expression(EXPR_STMT_EX, $1.node_ptr);
	      cnt_rule(yyn);
              } ;

/* (6.8.4)
selection_statement:
		  IF OPEN_RND expression CLOSE_RND statement                  |
		  IF OPEN_RND expression CLOSE_RND statement ELSE statement   |
    		  SWITCH OPEN_RND expression CLOSE_RND statement              ;
*/

selection_header:
		  IF OPEN_RND expression CLOSE_RND
              {
	      TRACE_LOG("IF");
              got_expression(IF_EXPR_EX, $3.node_ptr);
	      cnt_rule(yyn);
              }       |
		  SWITCH OPEN_RND expression CLOSE_RND
              {
              TRACE_LOG("SW");
              got_expression(SWITCH_EXPR_EX, $3.node_ptr);
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

/* (6.8.5)
iteration_statement:
              WHILE OPEN_RND expression CLOSE_RND statement               |
              DO statement WHILE OPEN_RND expression CLOSE_RND SEMICOLON  |
              FOR OPEN_RND expr_opt SEMICOLON expr_opt SEMICOLON expr_opt CLOSE_RND statement  |
              FOR OPEN_RND declaration expr_opt SEMICOLON expr_opt CLOSE_RND statement ;
*/
iteration_header:
              WHILE OPEN_RND expression CLOSE_RND
              {
              TRACE_LOG("WH");
              got_expression(WHILE_EXPR_EX, $3.node_ptr);
	      cnt_rule(yyn);
              }                                   |
              DO
              {
              TRACE_LOG("DO");
              cnt_rule(yyn);
              }                                   |
/*
   The token sequence for (i ; ; ) can be parsed as

      o for (expr ;
      o for (declaration ;

   The expression form is likely to be the only semantically valid case.
 */
	      FOR OPEN_RND expr_opt SEMICOLON expr_opt SEMICOLON expr_opt CLOSE_RND %dprec 2
              {
              TRACE_LOG("FO");
              got_expression(FOR_INIT_EX, $3.node_ptr);
              got_expression(FOR_CNTRL_EX, $5.node_ptr);
              got_expression(FOR_INC_EX, $7.node_ptr);
              cnt_rule(yyn);
              }                                   |
              FOR OPEN_RND declaration expr_opt SEMICOLON expr_opt CLOSE_RND %dprec 1
              {
              TRACE_LOG("FO");
              got_expression(FOR_CNTRL_EX, $4.node_ptr);
              got_expression(FOR_INC_EX, $6.node_ptr);
              cnt_rule(yyn);
              }                                   ;

/* (6.8.6) */
jump_statement:
              GOTO IDENTIFIER SEMICOLON
              {
              $$.node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              TRACE_LOG("GO");
              cnt_rule(yyn);
              }           |
              CONTINUE SEMICOLON
              {
              TRACE_LOG("CO");
              cnt_rule(yyn);
              }           |
              BREAK SEMICOLON
              {
              TRACE_LOG("BR");
              cnt_rule(yyn);
              }           |
              RETURN expr_opt SEMICOLON
              {
              TRACE_LOG("RE");
              got_expression(RETURN_EX, $2.node_ptr);
              cnt_rule(yyn);
              }           ;

/* A.2.4  External definitions

/* (6.9) */
external_declaration:
              function_header
              {
              cnt_rule(yyn);
              }     |
              declaration
              {
              seen_DC=TRUE;
              cnt_rule(yyn);
              }     ;

declaration_list_opt:
              {
              cnt_rule(yyn);
              }          |
              declaration_list
              {
              cnt_rule(yyn);
              }          ;
/* (6.9.1)
function_definition:
              declaration_specifiers declarator declaration_list_opt compound_statement ;

   In the following:

      usr_type_1 x;
      usr_type_2 y = foo;
      if ( z )

   the first two declarations are sometimes parsed as if they were part of
   a declaration_list_opt in a function header.  Changing declarator to
   fndef_declarator requires that some ( ) appear in one of the declarations
   (which can happen if the variable being declared is bracketed by redundant
   parenthesis).
*/

function_header:
              declaration_specifiers fndef_declarator declaration_list_opt OPEN_CURL
              {
	      TRACE_LOG("FD");
              cnt_rule(yyn);
              }                    |
/*
   The following production is not in C99, but was in C90.
 */
                                     fndef_declarator declaration_list_opt OPEN_CURL
              {
	      TRACE_LOG("FD");
              cnt_rule(yyn);
              }                    ;

/* (6.9.1) */
declaration_list:
              declaration
              {
              cnt_rule(yyn);
              }                  |
              declaration_list declaration
              {
              cnt_rule(yyn);
              }                  ;

/*
A.3  Preprocessing directives

(6.10) preprocessing-file:
              group-opt
(6.10) group:
              group-part
              group group-part
(6.10) group-part:
              if-section
              control-line
              text-line
              # non-directive
(6.10) if-section:
              if-group elif-groups-opt else-group-opt endif-line
(6.10) if-group:
              # if     constant-expr new-line group-opt
              # ifdef  identifier new-line group-opt
              # ifndef identifier new-line group-opt
(6.10) elif-groups:
              elif-group
              elif-groups elif-group
(6.10) elif-group:
              # elif   constant-expr new-line group-opt
(6.10) else-group:
              # else   new-line group-opt
(6.10) endif-line:
              # endif  new-line
(6.10) control-line:
              # include pp-tokens new-line
              # define  identifier replacement-list new-line
              # define  identifier lparen identifier-list-opt )
                                                      replacement-list new-line
              # define  identifier lparen ... ) replacement-list new-line
              # define  identifier lparen identifier-list , ... )
                                                      replacement-list new-line
              # undef   identifier new-line
              # line    pp-tokens new-line
              # error   pp-tokens-opt new-line
              # pragma  pp-tokens-opt new-line
              #         new-line
(6.10) text-line:
              pp-tokens-opt new-line
(6.10) non-directive:
              pp-tokens new-line
(6.10) lparen:
              a ( character not immediately preceded by white-space
(6.10) replacement-list:
              pp-tokens-opt
(6.10) pp-tokens:
              preprocessing-token
              pp-tokens preprocessing-token
(6.10) new-line:
              the new-line character
*/

%%

