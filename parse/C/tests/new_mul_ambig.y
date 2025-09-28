%glr-parser
%token ID NEW VOID

%{
#include <ctype.h>
#include <stdio.h>

/*
static const char *input = "N V * * * z";
*/
static const char *input = "N V * * * z";

#define YYSTYPE char *

static void yyerror (const char *s)
{
  printf ("%s\n", s);
}

static YYSTYPE stmtMerge (YYSTYPE a, YYSTYPE b)
{
  char *s;
  asprintf (&s, "\n{ %s %s }\n\t", a, b);
  return s;
}

static int yylex ();
%}

%%

main: add_expr { puts ($1); };

new_expression:
   NEW new_type_id
                       { asprintf (&$$, "[NEW %s]", $2); }
   ;

new_type_id:
   type_specifier new_declarator_opt
                       { asprintf (&$$, "[new_type_id %s %s]", $1, $2); }
   ;

new_declarator:
   ptr_operator new_declarator_opt
		   { asprintf (&$$, "[ptr_op new_decl_opt %s %s]", $1, $2); }
   | direct_new_declarator
   ;

new_declarator_opt:  |
   new_declarator    ;

direct_new_declarator:
					     '[' add_expr ']' ;

type_specifier:
    VOID
            { asprintf (&$$, "[VOID]"); }
	;

ptr_operator:
	'*' |
	'&' ;

add_expr: mult_expr
        | add_expr '+' mult_expr
                                 { asprintf (&$$, "[b+ %s %s]", $1, $3); }
        | add_expr '-' mult_expr
                                 { asprintf (&$$, "[b- %s %s]", $1, $3); }
        ;

mult_expr: primary
         | mult_expr '*' primary
								 { asprintf (&$$, "[b* %s %s]", $1, $3); }
         | mult_expr '/' primary
                                 { asprintf (&$$, "[b/ %s %s]", $1, $3); }
         ;

primary : new_expression |
          factor         ;

factor: '(' add_expr ')'         { asprintf (&$$, "<%s>", $2); }
        | '(' ID ')' factor        { asprintf (&$$, "(%s)%s", $2, $4); }
/*      | '+' factor               { asprintf (&$$, "u+|%s|", $2); }
      | '-' factor               { asprintf (&$$, "u-|%s|", $2); }
*/      | ID
             { asprintf (&$$, "[ID]"); }
      ;
%%

static int yylex ()
{
  char c = *input++;
  while (isspace(c))
      c = *input++;
  int tok = (c == 'N') ? NEW :
		     ((c == 'V') ? VOID :
		      ((isalpha(c)) ? ID :
			   c));
  printf("%d %d\n", c, tok);
  asprintf (&yylval, "%c", tok);
  return tok;
}

int main ()
{
  printf("%s\n", input);
  printf ("%i\n", yyparse ());
}
