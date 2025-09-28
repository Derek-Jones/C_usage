%glr-parser

%token ID
CONST
INT
%{
#include <ctype.h>
#include <stdio.h>

static const char *input = "\
j j \
I j[0] = \
    {    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
	 0,0,0,0,0,0,0,0,0,0,             \
	 };";

#define YYSTYPE char *
#define YYDEBUG 1

static void yyerror (const char *s)
{
  printf ("%s\n", s);
}

static int yylex ();
%}

%%

TU:
	translation_unit
	{
	}                   ;

translation_unit:
              declaration  %dprec 1
              {
              }        |
              statement             %dprec 2
              {
              }        ;

primary_expr:
              ID
              {
              }                      |
              CONST
              {
              }                      ;

postfix_expr:
              primary_expr
              {
              }                             |
              postfix_expr '[' expression ']'
              {
              }                             ;

argument_expr_list:
              assignment_expr
              {
              }                          |
              argument_expr_list ',' assignment_expr
              {
              }                          ;

unary_expr:
              postfix_expr
              {
              }                 ;

assignment_expr:
              unary_expr
              {
              }                               ;

expression:
              assignment_expr
              {
              }                  |
              expression ',' assignment_expr
              {
              }                  ;

expr_opt:
		{ } |
		expression
		{ } ;

declaration:
              declaration_specifiers                      ';' %dprec 1
              {
              }                                           |
              declaration_specifiers init_declarator_list ';' %dprec 2
              {
              }                                           ;

decl_specifier:
              type_specifier
              {
              }            ;

declaration_specifiers:
              decl_specifier
              {
              }            |
              declaration_specifiers decl_specifier
              {
              }            ;

init_declarator_list:
              init_declarator
              {
              }                            |
              init_declarator_list ',' init_declarator
              {
              }                            ;

init_declarator:
              declarator
              {
              }                    |
              declarator '=' initializer
              {
              }                    ;

type_specifier:
              INT
              {
              }           |
	      typedef_name
	      {
	      }           ;

pointer_opt:
              {
              }          |
              pointer
              {
              } ;
declarator:
              pointer_opt direct_declarator
              {
              } ;
assignment_expr_opt:
              {
              }          |
              assignment_expr
              {
              } ;

direct_declarator:
              ID       %dprec 2
              {
              }                |
              '(' declarator ')'
              {
              }                |
	      direct_declarator '[' expr_opt ']'
	      {
	      }                ;

pointer:
              '*' 
              {
              }         |
              '*' pointer
              {
              } ;

typedef_name:
              ID  %dprec 1
              {
              } ;

initializer:
              assignment_expr
              {
              }                             |
              '{' initializer_list '}'
              {
              }       |
              '{' initializer_list ',' '}'
              {
              } ;

initializer_list:
              initializer
              {
              }                        |
              initializer_list ',' initializer
              {
              } ;

statement:
              expression_statement
              {
              }     ;

expression_statement:
              expr_opt ';'
              {
              } ;

declaration_list:
              declaration
              {
              }                  |
              declaration_list declaration
              {
              }                  ;

%%



static int yylex ()
{
char c;
  
c = (*input ? *input++ : 0);
  
while (isspace(c))
   c = *input++;

asprintf (&yylval, "%c", c);
printf("> %c\n",  c);

return (c == 'I') ? INT : (isalnum (c) ? ID : (isdigit(c) ? CONST : c));
}

int main ()
{
yydebug=1;
printf ("%i\n", yyparse ());
}
