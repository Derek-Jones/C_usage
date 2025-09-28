/*
%glr-parser
*/

%token
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
QUESTION COLON
DOT DEREF PLUSPLUS MINUSMINUS
COMMA SEMICOLON
ELLIPSIS
OPEN_CURL CLOSE_CURL
OPEN_SQUARE CLOSE_SQUARE
ASSIGN PLUSASSIGN MINUSASSIGN TIMESASSIGN LSASSIGN RSASSIGN ANDASSIGN
DIVASSIGN REMASSIGN ORASSIGN NOTASSIGN
CONSTANT
IDENTIFIER
STRING_LITERAL
PASCAL FORTRAN
ASM ATTRIBUTE TYPEOF ALIGNOF
INLINE RESTRICT _BOOL _COMPLEX _IMAGINARY
AT_ADDR
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
translation_unit:
              external_declaration                    |
              translation_unit external_declaration   ;

/* A.2.1  Expressions */

/* (6.5.1) */
primary_expr:
              IDENTIFIER                    |
              CONSTANT                      |
              STRING_LITERAL                |
              OPEN_RND expression CLOSE_RND ;
              
argument_expr_list_opt:          |  
              argument_expr_list ;
/* (6.5.2) */
postfix_expr:
              primary_expr                                             |
              postfix_expr OPEN_SQUARE expression CLOSE_SQUARE         |
              postfix_expr OPEN_RND argument_expr_list_opt CLOSE_RND   |
              postfix_expr DOT IDENTIFIER                              |
              postfix_expr DEREF IDENTIFIER                            |
              postfix_expr PLUSPLUS                                    |
              postfix_expr MINUSMINUS                                  |
              OPEN_RND type_name CLOSE_RND OPEN_CURL initializer_list CLOSE_CURL   |
              OPEN_RND type_name CLOSE_RND OPEN_CURL initializer_list COMMA CLOSE_CURL   ;

/* (6.5.2) */
argument_expr_list:
              assignment_expr                          |
              argument_expr_list COMMA assignment_expr ;

/* (6.5.3) */
unary_expr:
              postfix_expr                        |
              PLUSPLUS unary_expr                 |
              MINUSMINUS unary_expr               |
              unary_operator cast_expr            |
              SIZEOF unary_expr                   |
              SIZEOF OPEN_RND type_name CLOSE_RND ;

/* (6.5.3) */
unary_operator:
              AND       |
              STAR      |
              PLUS      |
              MINUS     |
              BITNEGATE |
              NOT       ;

/* (6.5.4) */
cast_expr:
              unary_expr                             |
              OPEN_RND type_name CLOSE_RND cast_expr ;

/* (6.5.5) */
multiplicative_expr:
              cast_expr                               |
              multiplicative_expr STAR cast_expr      |
              multiplicative_expr DIVIDE cast_expr    |
              multiplicative_expr REMAINDER cast_expr ;

/* (6.5.6) */
additive_expr:
              multiplicative_expr                     |
              additive_expr PLUS multiplicative_expr  |
              additive_expr MINUS multiplicative_expr ;

/* (6.5.7) */
shift_expr:
              additive_expr                       |
              shift_expr LEFTSHIFT additive_expr  |
              shift_expr RIGHTSHIFT additive_expr ;

/* (6.5.8) */
relational_expr:
              shift_expr                     |
              relational_expr LT  shift_expr |
              relational_expr GT  shift_expr |
              relational_expr LE shift_expr  |
              relational_expr GE shift_expr  ;

/* (6.5.9) */
equality_expr:
              relational_expr                        |
              equality_expr EQUAL relational_expr    |
              equality_expr NOTEQUAL relational_expr ;

/* (6.5.10) */
AND_expr:
              equality_expr              |
              AND_expr AND equality_expr ;

/* (6.5.11) */
exclusive_OR_expr:
              AND_expr                       |
              exclusive_OR_expr XOR AND_expr ;

/* (6.5.12) */
inclusive_OR_expr:
              exclusive_OR_expr                      |
              inclusive_OR_expr OR exclusive_OR_expr ;

/* (6.5.13) */
logical_AND_expr:
              inclusive_OR_expr                          |
              logical_AND_expr ANDTEST inclusive_OR_expr ;

/* (6.5.14) */
logical_OR_expr:
              logical_AND_expr                        |
              logical_OR_expr ORTEST logical_AND_expr ;

/* (6.5.15) */
conditional_expr:
              logical_OR_expr                                            |
              logical_OR_expr QUESTION expression COLON conditional_expr ;

/* (6.5.16) */
assignment_expr:
              conditional_expr                               |
              unary_expr assignment_operator assignment_expr ;

/* (6.5.16) */
assignment_operator:
          ASSIGN      |
	      TIMESASSIGN |
	      DIVASSIGN   |
	      REMASSIGN   |
	      PLUSASSIGN  |
	      MINUSASSIGN |
	      LSASSIGN    |
	      RSASSIGN    |
	      ANDASSIGN   |
	      ORASSIGN    |
	      NOTASSIGN   ;

/* (6.5.17) */
expression:
              assignment_expr                  |
              expression COMMA assignment_expr ;

/* (6.6) */
constant_expr:
              conditional_expr ;

/* A.2.2  Declarations */

init_declarator_list_opt:          |    
              init_declarator_list ;
/* (6.7) */
declaration:
              declaration_specifiers init_declarator_list_opt SEMICOLON ;

declaration_specifiers_opt:          |
              declaration_specifiers ;
/* (6.7) */
declaration_specifiers:
              storage_class_specifier declaration_specifiers_opt   |
              type_specifier declaration_specifiers_opt            |
              type_qualifier declaration_specifiers_opt            |
              function_specifier declaration_specifiers_opt        ;

/* (6.7) */
init_declarator_list:
              init_declarator                            |
              init_declarator_list COMMA init_declarator ;

/* (6.7) */
init_declarator:
              declarator                    |
              declarator ASSIGN initializer ;

/* (6.7.1) */
storage_class_specifier:
              TYPEDEF  |
              EXTERN   |
              STATIC   |
              AUTO     |
              REGISTER ;

/* (6.7.2) */
type_specifier:
              VOID                      |
              CHAR                      |
              SHORT                     |
              INT                       |
              LONG                      |
              FLOAT                     |
              DOUBLE                    |
              SIGNED                    |
              UNSIGNED                  |
              _BOOL                     |
              _COMPLEX                  |
              _IMAGINARY                |
              struct_or_union_specifier |
              enum_specifier            |
              typedef_name              ;

identifier_opt:           |
               IDENTIFIER ;

/* (6.7.2.1) */
struct_or_union_specifier:
              struct_or_union identifier_opt OPEN_CURL struct_declaration_list CLOSE_CURL   |
              struct_or_union IDENTIFIER ;

/* (6.7.2.1) */
struct_or_union:
              STRUCT |
              UNION  ;

/* (6.7.2.1) */
struct_declaration_list:
              struct_declaration                         |
              struct_declaration_list struct_declaration ;

/* (6.7.2.1) */
struct_declaration:
              specifier_qualifier_list struct_declarator_list SEMICOLON ;

specifier_qualifier_list_opt:          |
              specifier_qualifier_list ;
/* (6.7.2.1) */
specifier_qualifier_list:
              type_specifier specifier_qualifier_list_opt |
              type_qualifier specifier_qualifier_list_opt ;

/* (6.7.2.1) */
struct_declarator_list:
              struct_declarator                              |
              struct_declarator_list COMMA struct_declarator ;

declarator_opt:          |
              declarator ;
/* (6.7.2.1) */
struct_declarator:
              declarator                         |
              declarator_opt COLON constant_expr ;

/* (6.7.2.2) */
enum_specifier:
              ENUM identifier_opt OPEN_CURL enumerator_list CLOSE_CURL   |
              ENUM identifier_opt OPEN_CURL enumerator_list COMMA CLOSE_CURL   |
              ENUM IDENTIFIER ;

/* (6.7.2.2) */
enumerator_list:
              enumerator                       |
              enumerator_list COMMA enumerator ;

/* (6.7.2.2) */
enumerator:
              IDENTIFIER                      |
              IDENTIFIER ASSIGN constant_expr ;

/* (6.7.3) */
type_qualifier:
              CONST    |
              RESTRICT |
              VOLATILE ;

/* (6.7.4) */
function_specifier:
              INLINE ;

pointer_opt:          |
              pointer ;
/* (6.7.5) */
declarator:
              pointer_opt direct_declarator ;

type_qualifier_list_opt:          |
              type_qualifier_list ;
assignment_expr_opt:          |
              assignment_expr ;
identifier_list_opt:          |
              identifier_list ;
/* (6.7.5) */
direct_declarator:
              IDENTIFIER                      |
              OPEN_RND declarator CLOSE_RND   |
              direct_declarator OPEN_SQUARE type_qualifier_list_opt assignment_expr_opt CLOSE_SQUARE   |
              direct_declarator OPEN_SQUARE STATIC type_qualifier_list_opt assignment_expr CLOSE_SQUARE   |
              direct_declarator OPEN_SQUARE type_qualifier_list STATIC assignment_expr CLOSE_SQUARE   |
              direct_declarator OPEN_SQUARE type_qualifier_list_opt STAR CLOSE_SQUARE   |
              direct_declarator OPEN_RND parameter_type_list CLOSE_RND |
              direct_declarator OPEN_RND identifier_list_opt CLOSE_RND ;

/* (6.7.5) */
pointer:
              STAR type_qualifier_list_opt         |
              STAR type_qualifier_list_opt pointer ;

/* (6.7.5) */
type_qualifier_list:
              type_qualifier                     |
              type_qualifier_list type_qualifier ;

/* (6.7.5) */
parameter_type_list:
              parameter_list                |
              parameter_list COMMA ELLIPSIS ;

/* (6.7.5) */
parameter_list:
              parameter_declaration                      |
              parameter_list COMMA parameter_declaration ;

abstract_declarator_opt:          |
              abstract_declarator ;
/* (6.7.5) */
parameter_declaration:
              declaration_specifiers declarator              |
              declaration_specifiers abstract_declarator_opt ;

/* (6.7.5) */
identifier_list:
              IDENTIFIER                       |
              identifier_list COMMA IDENTIFIER ;

/* (6.7.6) */
type_name:
              specifier_qualifier_list abstract_declarator_opt ;

/* (6.7.6) */
abstract_declarator:
              pointer                                |
              pointer_opt direct_abstract_declarator ;

direct_abstract_declarator_opt:          |
              direct_abstract_declarator ;
parameter_type_list_opt:          |
              parameter_type_list ;
/* (6.7.6) */
direct_abstract_declarator:
              OPEN_RND abstract_declarator CLOSE_RND   |
              direct_abstract_declarator_opt OPEN_SQUARE assignment_expr_opt CLOSE_SQUARE   |
              direct_abstract_declarator_opt OPEN_SQUARE STAR CLOSE_SQUARE   |
              direct_abstract_declarator_opt OPEN_RND parameter_type_list_opt CLOSE_RND ;

/* (6.7.7) */
typedef_name:
              IDENTIFIER ;

/* (6.7.8) */
initializer:
              assignment_expr                             |
              OPEN_CURL initializer_list CLOSE_CURL       |
              OPEN_CURL initializer_list COMMA CLOSE_CURL ;

designation_opt:          |
              designation ;
/* (6.7.8) */
initializer_list:
              designation_opt initializer                        |
              initializer_list COMMA designation_opt initializer ;

/* (6.7.8) */
designation:
              designator_list ASSIGN ;

/* (6.7.8) */
designator_list:
              designator                 |
              designator_list designator ;

/* (6.7.8) */
designator:
              OPEN_SQUARE constant_expr CLOSE_SQUARE |
              DOT IDENTIFIER                         ;

/* A.2.3  Statements */

/* (6.8) */
statement:
              labeled_statement    |
              compound_statement   |
              expression_statement |
              selection_statement  |
              iteration_statement  |
              jump_statement       ;

/* (6.8.1) */
labeled_statement:
              IDENTIFIER COLON statement         |
              CASE constant_expr COLON statement |
              DEFAULT COLON statement            ;

block_item_list_opt:          |
              block_item_list ;
/* (6.8.2) */
compound_statement:
              OPEN_CURL block_item_list_opt CLOSE_CURL ;

/* (6.8.2) */
block_item_list:
              block_item                 |
              block_item_list block_item ;

/* (6.8.2) */
block_item:
              declaration |
              statement   ;

/* (6.8.3) */
expression_statement:
              expr_opt SEMICOLON ;

/* (6.8.4) */
selection_statement:
              IF OPEN_RND expression CLOSE_RND statement                |
              IF OPEN_RND expression CLOSE_RND statement ELSE statement |
              SWITCH OPEN_RND expression CLOSE_RND statement            ;

expr_opt:                |
              expression ;

/* (6.8.5) */
iteration_statement:
              WHILE OPEN_RND expression CLOSE_RND statement                |
              DO statement WHILE OPEN_RND expression CLOSE_RND SEMICOLON   |
              FOR OPEN_RND expr_opt SEMICOLON expr_opt SEMICOLON expr_opt CLOSE_RND statement   |
              FOR OPEN_RND declaration expr_opt SEMICOLON expr_opt CLOSE_RND statement ;

/* (6.8.6) */
jump_statement:
              GOTO IDENTIFIER SEMICOLON |
              CONTINUE SEMICOLON        |
              BREAK SEMICOLON           |
              RETURN expr_opt SEMICOLON ;

/* A.2.4  External definitions

/* (6.9) */
external_declaration:
              function_definition |
              declaration         ;

declaration_list_opt:          |
              declaration_list ;
/* (6.9.1) */
function_definition:
              declaration_specifiers declarator declaration_list_opt compound_statement ;

/* (6.9.1) */
declaration_list:
              declaration                  |
              declaration_list declaration ;

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

