%glr-parser
%token ID

%{
#include <ctype.h>
#include <stdio.h>

static const char *input = "(x)+(y)+z";

#define YYSTYPE char *

static void yyerror (const char *s)
{
  printf ("%s\n", s);
}

static YYSTYPE stmtMerge (YYSTYPE a, YYSTYPE b)
{
  char *s;
  asprintf (&s, "\n{ %s %s }\n", a, b);
  return s;
}

static int yylex ();
%}

%%

main: add_expr { puts ($1); };

add_expr: mult_expr              %merge <stmtMerge>
        | add_expr '+' mult_expr %merge <stmtMerge>
                                 { asprintf (&$$, "[b+ %s %s]", $1, $3); }
        | add_expr '-' mult_expr { asprintf (&$$, "[b- %s %s]", $1, $3); }
        ;

mult_expr: factor
         | mult_expr '*' factor  { asprintf (&$$, "[b* %s %s]", $1, $3); }
         | mult_expr '/' factor  { asprintf (&$$, "[b/ %s %s]", $1, $3); }
         ;

factor: '(' add_expr ')'         { asprintf (&$$, "(%s)", $2); }
      | '(' ID ')' factor        { asprintf (&$$, "<%s>%s", $2, $4); }
      | '+' factor               { asprintf (&$$, "u+%s", $2); }
      | '-' factor               { asprintf (&$$, "u-%s", $2); }
      | ID
      ;
%%

static int yylex ()
{
  char c = *input ? *input++ : 0;
  asprintf (&yylval, "%c", c);
  return isalnum (c) ? ID : c;
}

int main ()
{
  printf ("%i\n", yyparse ());
}
