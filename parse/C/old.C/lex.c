                    /* lexer.c, 27 Feb 05 */

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "../../ngutil.h"

#define NGRAM_DEBUG 0

char *cur_out_file;
unsigned char cur_ch,
              prev_ch,
	      prev_tok,
	      prev_tok_not_nl;

BOOL last_was_newline,
     last_was_whitespace,
     got_token;

int
    cur_token,
    in_c_idents,
    first_intdigit[10],
    first_fltdigit[10],
    first_hexdigit[15],
    int_suffix[13],
    exp_uses_e, exp_uses_E,
    flt_suffix[3],
    cconst_len[8],
    hex_pow_count[32],
    cur_block_nest,
    cur_line_len,
    cur_splice_cnt,
    last_keyword,
    last_tok_splice,
    last_tok_strlit,
    cur_logical_line_len,
    total_str_line_splice,
    total_oct_literals,
    total_hex_literals,
    total_dec_literals,
    total_char_escapes,
    total_str_escapes,
    total_chars,
    total_all_chars,
    total_tokens,
    total_tokens_not_nl,
    total_trigraphs,
    two_questions;

struct key_tag {
                char *key_str;
	        int tok_num,
		    occurrences;
               };
struct key_tag keywords[MAX_KEY_LEN][12] = {
   {NULL, 0, 0},
   {NULL, 0, 0},
   {"do", TOK_DO, 0, "if", TOK_IF, 0, NULL, 0, 0},
   {"for", TOK_FOR, 0, "int", TOK_INT, 0, NULL, 0, 0},
   {"auto", TOK_AUTO, 0, "else", TOK_ELSE, 0, "enum", TOK_ENUM, 0,
    "elif", TOK_ELIF, 0,
    "case", TOK_CASE, 0, "char", TOK_CHAR, 0, "goto", TOK_GOTO, 0,
    "line", TOK_LINE, 0,
    "long", TOK_LONG, 0, "void", TOK_VOID, 0, NULL, 0, 0},
   {"break", TOK_BREAK, 0, "const", TOK_CONST, 0,
    "endif", TOK_ENDIF, 0, "error", TOK_ERROR, 0,
    "float", TOK_FLOAT, 0,
    "ifdef", TOK_IFDEF, 0,
    "short", TOK_SHORT, 0,
    "undef", TOK_UNDEF, 0,
    "union", TOK_UNION, 0, "while", TOK_WHILE, 0,
    "_Bool", TOK__BOOL, 0,
    NULL, 0, 0},
   {"define", TOK_DEFINE, 0, "double", TOK_DOUBLE, 0,
    "extern", TOK_EXTERN, 0, "ifndef", TOK_IFNDEF, 0,
    "pragma", TOK_PRAGMA, 0,
    "return", TOK_RETURN, 0, "signed", TOK_SIGNED, 0,
    "sizeof", TOK_SIZEOF, 0, "static", TOK_STATIC, 0,
    "struct", TOK_STRUCT, 0, "switch", TOK_SWITCH, 0,
    NULL, 0, 0},
   {"default", TOK_DEFAULT, 0, "defined", TOK_DEFINED, 0,
    "include", TOK_INCLUDE, 0, "typedef", TOK_TYPEDEF, 0,
    NULL, 0, 0},
   {"continue", TOK_CONTINUE, 0, "register", TOK_REGISTER, 0,
    "unsigned", TOK_UNSIGNED, 0, "volatile", TOK_VOLATILE, 0,
    "_Complex", TOK__COMPLEX, 0,
   {NULL, 0, 0},
    NULL, 0, 0},
   {"_Imaginary", TOK__IMAGINARY, 0,
    NULL, 0, 0},
   };
/*
   "__LINE__",
   "__FILE__",
   "__DATE__",
   "__TIME__",
   "__STDC_VERSION__",
*/

char ident_str[IDENT_SAVE_LEN];


void output_token(unsigned char token,
		  unsigned int tok_width)
{
if ((token != TOK_NEW_LINE) &&
    (token != COMMENT) &&
    (token != COMMENT_NL) &&
    (token != CPP_COMMENT))
   got_token=TRUE;
if ((token == INTEGER_CONST) || (token == FLOAT_CONST))
   cur_token=TOK_LITERAL;
else
   cur_token=token;
}


void do_end_of_line(void)
/*
 * Called everytime the input stream reaches an end of line
 */
{
cur_line_len--; /* subtract 1 for the new-line character */

if (last_tok_splice)
   {
   cur_splice_cnt++;
   cur_logical_line_len+=(cur_line_len-1); /* and 1 for the splice */
   }
else
   {
   }
last_tok_splice=FALSE;
cur_line_len=0;
}


void next_ch(void)
{
cur_line_len++;
if (feof(stdin))
   {
   cur_ch=0;
   return;
   }

cur_ch=getchar();

if (NGRAM_DEBUG)
   printf("%c", cur_ch);
}

void do_cur_ch(void)
{
prev_ch=cur_ch;
next_ch();
}


void do_comment_ch(void)
{
next_ch();
prev_ch=cur_ch;
if (cur_ch == '\n')
   {
   do_end_of_line();
   }
}


void lex_identifier(int ident_len)
/*
 * No keyword starts with an L, so there is no need to worry
 * about the non-wide character constant case.
 */
{
int id_index;

if (ident_len == 1)
   ident_str[0]='L';
while ((cur_ch == '_') ||
       isalpha(cur_ch) ||
       isdigit(cur_ch))
   {
   if (ident_len < IDENT_SAVE_LEN)
      ident_str[ident_len]=cur_ch;
   ident_len++;
   do_cur_ch();
   }
if (in_c_idents)
   {
   if (ident_len < IDENT_SAVE_LEN-1)
      {
      ident_str[ident_len]='\0';
      }
   return;
   }
if (ident_len < MAX_KEY_LEN)
   {
   struct key_tag *key_ptr = keywords[ident_len];

   ident_str[ident_len]='\0';
   while (key_ptr->key_str != NULL)
      {
      if (strcmp(ident_str, key_ptr->key_str) == 0)
         {
	 key_ptr->occurrences++;
	 output_token(key_ptr->tok_num, ident_len);
	 return;
	 }
      key_ptr++;
      }
   }
#if PRINT_IDENTS
for (id_index=0; id_index < ident_len; id_index++)
   printf("%c", ident_str[id_index]);
printf("\n");
#endif
if (ident_len < IDENT_SAVE_LEN-1)
   {
   ident_str[ident_len]='\0';
   }
output_token(TOK_IDENTIFIER, ident_len);
}


void lex_float(int skip_period,
	       int cur_tok_len,
	       int first_nz_digit)
{
int exp_val = 0,
    exp_sign,
    start_all_char_count=total_all_chars,
    is_first_digit = TRUE,
    has_exponent = 0,
    suffix_flag = 0,
    dp_offset=cur_tok_len,
    digits_after_dp=0;

if (first_nz_digit != 0)
   {
   is_first_digit=FALSE;
   first_fltdigit[first_nz_digit]++;
   }
if (cur_ch == '.')
   do_cur_ch(); /* skip . */
else
   {
   }
while (isdigit(cur_ch))
   {
   digits_after_dp++;
   if (is_first_digit && (cur_ch != '0'))
      {
      is_first_digit=FALSE;
      first_fltdigit[cur_ch-'0']++;
      }
   do_cur_ch();
   }
if ((cur_ch == 'e') ||
    (cur_ch == 'E'))
   {
   if (cur_ch == 'e')
      exp_uses_e++;
   else
      exp_uses_E++;
   do_cur_ch();
   has_exponent=1;
   exp_sign=1;
   if ((cur_ch == '-') ||
       (cur_ch == '+'))
      {
      exp_sign = (cur_ch == '-') ? -1 : 1;
      do_cur_ch();
      }
   while (isdigit(cur_ch))
      {
      exp_val = exp_val * 10 + (cur_ch - '0');
      do_cur_ch();
      }
   }

if ((cur_ch == 'F') || (cur_ch == 'f'))
   {
   do_cur_ch();
   }
else if ((cur_ch == 'l') || (cur_ch == 'L'))
   {
   do_cur_ch();
   }
output_token(FLOAT_CONST, cur_tok_len+total_all_chars-start_all_char_count);
}

void lex_int_suffix(void)
/*
 * Handle integer suffixes.
 */
{
int suffix_flag = 0;

if ((cur_ch == 'U') || (cur_ch == 'u'))
   {
   suffix_flag=0x01;
   do_cur_ch();
   }
if ((cur_ch == 'L') || (cur_ch == 'l'))
   {
   do_cur_ch();
   if ((cur_ch == 'L') || (cur_ch == 'l'))
      {
      suffix_flag|=0x04;
      do_cur_ch();
      }
   else
      suffix_flag|=0x02;
   if ((cur_ch == 'U') || (cur_ch == 'u'))
      {
      suffix_flag|=0x08;
      do_cur_ch();
      }
   }
int_suffix[suffix_flag]++;
}

void lex_number(void)
{
int power_10,
    power_16,
    hex_valu,
    is_first_digit = TRUE,
    first_nz_digit;
LONGEST_UINT  lit_valu = 0,
	      ten_lit_valu;
int start_all_char_count=total_all_chars;

lit_valu = (cur_ch - '0');
do_cur_ch();
if ((cur_ch == 'x') ||
    (cur_ch == 'X'))
   {
   do_cur_ch();
   while (is_hex_digit(cur_ch))
      {
      if (isdigit(cur_ch))
         hex_valu = (cur_ch - '0');
      else if (is_a_f(cur_ch))
         hex_valu = (cur_ch - 'a' + 10);
      else if (is_A_F(cur_ch))
         hex_valu = (cur_ch - 'A' + 10);
      if (is_first_digit && (cur_ch != '0'))
         {
	 is_first_digit=FALSE;
	 first_hexdigit[hex_valu]++;
	 }
      lit_valu= (lit_valu << 4) + hex_valu;
      do_cur_ch();
      }
   lex_int_suffix();
   output_token(INTEGER_CONST, total_all_chars-start_all_char_count);
   total_hex_literals++;
   return;
   }

first_nz_digit=lit_valu;
total_dec_literals++; /* subtract off octal count by hand */
if (lit_valu == 0)
   {
   while (isdigit(cur_ch))
      {
      if (is_first_digit && (cur_ch != '0'))
         {
         total_oct_literals++; /* will not count a single '0' */
         is_first_digit=FALSE;
         first_nz_digit=cur_ch - '0';
         }
      lit_valu = (lit_valu << 3) + (cur_ch - '0');
      do_cur_ch();
      }
   }
else
   {
   while (isdigit(cur_ch))
      {
      lit_valu = (cur_ch - '0') + lit_valu*10;
      do_cur_ch();
      }
   }
if ((cur_ch == '.') || (cur_ch == 'E') || (cur_ch == 'e'))
   {
   lex_float(TRUE, total_all_chars-start_all_char_count, first_nz_digit);
   return;
   }
lex_int_suffix();
output_token(INTEGER, total_all_chars-start_all_char_count);
}


void do_escape(char char_str)
{
int num_octal_digits;
LONGEST_UINT escape_valu = 0;

if ((cur_ch == 'x') ||
    (cur_ch == 'X'))
   {
   do_cur_ch();
   while (is_hex_digit(cur_ch))
      {
      if (isdigit(cur_ch))
         escape_valu = (cur_ch - '0') + escape_valu*16;
      else if (is_a_f(cur_ch))
         escape_valu = (cur_ch - 'a' + 10) + escape_valu*16;
      else if (is_A_F(cur_ch))
         escape_valu = (cur_ch - 'A' + 10) + escape_valu*16;
      do_cur_ch();
      }
   }
else if ((cur_ch >= '0') &&
         (cur_ch <= '7'))
   {
   num_octal_digits=1;
   do_cur_ch();
   while ((cur_ch >= '0') &&
          (cur_ch <= '7') &&
	  (num_octal_digits != 3))
      {
      num_octal_digits++;
      escape_valu = (escape_valu * 8) + (cur_ch - '0');
      do_cur_ch();
      }
   }
else
   {
   do_cur_ch();
   return;
   }

}

void lex_char_const(char is_wide)
{
int start_all_char_count=total_all_chars,
    char_count = 0;

do_cur_ch();
while (cur_ch != '\'')
   {
   char_count++;
   if (cur_ch == '\\')
      {
      total_char_escapes++;
      do_cur_ch(); /* this will cause \' to be skipped over */
      do_escape(0);
      }
   else
      {
      do_cur_ch();
      }
   }
cconst_len[char_count]++;
do_cur_ch();
output_token(CHAR_CONST, total_all_chars-start_all_char_count);
}


void lex_str_const(char is_wide)
/*
 * TODO
 */
{
int str_len = 0;
int start_all_char_count = total_all_chars;

do_cur_ch();
if (prev_tok == TOK_INCLUDE)
   {
   while (cur_ch != '\"')
      {
      if (cur_ch == '\\')
         {
         do_cur_ch(); /* this will cause \" to be skipped over */
         if (cur_ch == '\n')
            {
	    total_str_line_splice++;
	    str_len--;
	    do_end_of_line();
	    }
         }
      else
	 do_cur_ch();
      }
   do_cur_ch();
   output_token(HEADER_NAME , total_all_chars-start_all_char_count);
   return;
   }
/*
 * TODO
if (last_tok_strlit)
   ???
*/
last_tok_strlit=TRUE;
while (cur_ch != '\"')
   {
   if (cur_ch == '\\')
      {
      do_cur_ch(); /* this will cause \" to be skipped over */
      if (cur_ch == '\n')
         {
	 total_str_line_splice++;
	 str_len--;
	 do_end_of_line();
	 }
      else
         {
         total_str_escapes++;
	 do_escape(1);
	 }
      }
   else if (cur_ch == '?')
      {
      do_cur_ch();
      if (cur_ch == '?')
         {
         str_len++;
	 do_cur_ch();
	 if ((cur_ch == '=') ||
	     (cur_ch == '[') ||
	     (cur_ch == '/') ||
	     (cur_ch == ']') ||
	     (cur_ch == '^') ||
	     (cur_ch == '{') ||
	     (cur_ch == '|') ||
	     (cur_ch == '}') ||
	     (cur_ch == '~'))
	    {
            str_len++;
	    do_cur_ch();
	    total_trigraphs++;
	    }
	 else
	    two_questions++;
	 }
      }
   else
      {
      do_cur_ch();
      }
   str_len++;
   }
do_cur_ch();
output_token(STRING_CONST, total_all_chars-start_all_char_count);
}


void do_comment(void)
{
int start_all_char_count = total_all_chars-1;

do_comment_ch();
while (TRUE)
   {
   if (cur_ch == '*')
      {
      while (cur_ch == '*')
         do_comment_ch();
      if (cur_ch == '/')
         break;
      }
   do_comment_ch();
   }
do_comment_ch();

output_token(COMMENT, total_all_chars-start_all_char_count);
}


void do_cpp_comment(void)
{
int start_all_char_count = total_all_chars-1;

do_comment_ch();
while (TRUE)
   {
   if (cur_ch == '\n')
      break;
   do_comment_ch();
   }
output_token(CPP_COMMENT, total_all_chars-start_all_char_count);
}


void end_of_file(void)
{
}


int yylex(void)
{
int ch_1,
    ch_3,
    ind,
    num_whitespace;
char seen_newline;

got_token=FALSE;
if (feof(stdin))
   {
   return 0;
   }

while (!got_token)
   {
   switch (cur_ch)
      {
      case 'A': case 'B':
      case 'C': case 'D': case 'E': case 'F':
      case 'G': case 'H': case 'I': case 'J': case 'K':
      case 'M': case 'N':
      case 'O': case 'P': case 'Q': case 'R':
      case 'S': case 'T': case 'U': case 'V': case 'W':
      case 'X': case 'Y': case 'Z':
      case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
      case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
      case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
      case 's': case 't': case 'u': case 'v': case 'w': case 'x':
      case 'y': case 'z':
      case '_':
	    lex_identifier(0);
	    break;

      /* check for start of a wide character constant/wide string literal */
      case 'L':
	    do_cur_ch();
	    if (cur_ch == '\'')	
	       lex_char_const(TRUE);
	    else if (cur_ch == '\"')	
	       lex_str_const(TRUE);
	    else
	       lex_identifier(1);
	    break;

      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
	    lex_number();
	    break;

      case '*':		/* could be * or *= */
	    do_cur_ch();
	    if (cur_ch == '=')
	       {
	       output_token(TOK_MULT_EQUAL, 2);
	       do_cur_ch();
	       }
	    else		
	       output_token(TOK_TIMES, 1);
	    break;

      case '=':		/* could be = or == */
	    do_cur_ch();
	    if (cur_ch == '=')
	       {
	       output_token(TOK_EQ_EQUAL, 2);
	       do_cur_ch();
	       }
	    else
	       output_token(TOK_EQUAL, 1);
	    break;

      case '-':              /* could be - -- -= or -> */
	    do_cur_ch();
	    if (cur_ch == '>')	
	       {
	       output_token(TOK_INDIR_SELECT, 2);
	       do_cur_ch();
	       }
	    else if (cur_ch == '-')
	       {
	       output_token(TOK_PRE_MINUS, 2);
	       do_cur_ch();
	       }
	    else if (cur_ch == '=')
	       {
	       output_token(TOK_MIN_EQUAL, 2);
	       do_cur_ch();
	       }
	    else		
	       output_token(TOK_MINUS, 1);
	    break;

      case '\"':
	    lex_str_const(FALSE);
	    break;

      case '+':		/* could be + ++ or += */
	    do_cur_ch();
	    if (cur_ch == '+')
	       {
	       output_token(TOK_PRE_PLUS, 2);
	       do_cur_ch();
	       }
	    else if (cur_ch == '=')
	       {
	       output_token(TOK_PLUS_EQUAL, 2);
	       do_cur_ch();
	       }
	    else		
	       output_token(TOK_ADD, 1);
	    break;

      case '.':              /* could be .digits (float pt) or ... */
	    do_cur_ch();
	    if (isdigit(cur_ch))	/* floating-point constant */
	       {
	       lex_float(FALSE, 0, 0);
	       }
	    else if (cur_ch == '.')	/* could be ... */
	       {
	       do_cur_ch();
	       if (cur_ch == '.')    /* it is ... */
	          {
	          output_token(TOK_ELLIPSIS, 3);
		  do_cur_ch();
	          }
	       else
	          {
	          }
	       }
	    else
	       {			
	       output_token(TOK_DIR_SELECT, 1);
	       }
	    break;

      case '<':		/* could be < << <= or <<= or the digraphs <: or <% */
	    if (prev_tok == TOK_INCLUDE)
	       {
	       int start_all_char_count = total_all_chars;
	       
	       do_cur_ch();
	       while (cur_ch != '>')
	          do_cur_ch();
	       do_cur_ch();
	       output_token(HEADER_NAME , total_all_chars-start_all_char_count);
	       break;
	       }
	    do_cur_ch();
	    if (cur_ch == '=')	
	       {
	       output_token(TOK_LESS_EQUAL, 2);
	       do_cur_ch();
	       }
	    else
	    if (cur_ch == '<')
	       {
	       do_cur_ch();
	       if (cur_ch == '=')
	          {
	          output_token(TOK_LSH_ASSIGN, 3);
	          do_cur_ch();
	          }
	       else		
	          output_token(TOK_LSHIFT, 2);
	       }
	    else if (cur_ch == ':')
	       {
	       output_token(TOK_OPEN_SQUARE, 3);
	       do_cur_ch();
	       }
	    else if (cur_ch == '%')
	       {
	       output_token(TOK_OPEN_CURL, 3);
	       do_cur_ch();
	       }
	    else
	       output_token(TOK_LESS_THAN, 1);
	    break;

      case '>':		/* could be > >> >= or >>= */
	    do_cur_ch();
	    if (cur_ch == '>')
	       {
	       do_cur_ch();
	       if (cur_ch == '=')
	          {
	          output_token(TOK_RSH_ASSIGN, 3);
	          do_cur_ch();
	          }
	       else		
	          output_token(TOK_RSHIFT, 2);
	       }
	    else
	       if (cur_ch == '=')	
	          {
	          output_token(TOK_GR_EQUAL, 2);
	          do_cur_ch();
	          }
	       else
	          output_token(TOK_GREATER_THAN, 1);
	    break;

      case '\'':
	    lex_char_const(FALSE);
	    break;

      case ':':
	    do_cur_ch();
	    if (cur_ch == '>')
	       {
	       output_token(TOK_CL_SQUARE, 2);
	       do_cur_ch();
	       }
	    else
	       output_token(TOK_COLON, 1);
	    break;

      case '|':		/* could be | || or |= */
	    do_cur_ch();
	    if (cur_ch == '|')
	       {
	       output_token(TOK_LOG_OR, 2);
	       do_cur_ch();
	       }
	    else if (cur_ch == '=')	
	       {
	       output_token(TOK_BOR_ASSIGN, 2);
	       do_cur_ch();
	       }
	    else		
	       output_token(TOK_BIT_OR, 1);
	    break;

      case '/':		/* could be / or /= */
	    do_cur_ch();
	    if (cur_ch == '*')
	       do_comment();
	    else if (cur_ch == '/')
	       do_cpp_comment();
	    else if (cur_ch == '=')
	       {
	       output_token(TOK_DIV_EQUAL, 2);
	       do_cur_ch();
	       }
	    else
	       output_token(TOK_DIVIDE, 1);
	    break;

      case '!':
	    /* could be ! or != */
	    do_cur_ch();
	    if (cur_ch == '=')
	       {
	       output_token(TOK_EXC_EQUAL, 2);
	       do_cur_ch();
	       }
	    else
	       output_token(TOK_LOG_NOT, 1);
	    break;

      case '^':
	    /* could be ^ or ^= */
	    do_cur_ch();
	    if (cur_ch == '=')
	       {
	       output_token(TOK_BXOR_ASSIGN, 2);
	       do_cur_ch();
	       }
	    else		
	       output_token(TOK_BIT_XOR, 1);
	    break;

      case '&':              /* could be & && or &= */
	    do_cur_ch();
	    if (cur_ch == '&')	
	       {
	       output_token(TOK_LOG_AND, 2);
	       do_cur_ch();
	       }
	    else if (cur_ch == '=')
	       {
	       output_token(TOK_AND_ASSIGN, 2);
	       do_cur_ch();
	       }
	    else
	       output_token(TOK_BIT_AND, 1);
	    break;

      case '%':		/* could be % or %= */
	    do_cur_ch();
	    if (cur_ch == '=')
	       {
	       output_token(TOK_REM_EQUAL, 2);
	       do_cur_ch();
	       }
	    else if (cur_ch == '>')
	       {
	       output_token(TOK_CL_CURL, 2);
	       do_cur_ch();
	       }
	    else if (cur_ch == ':')
	       {
	       do_cur_ch();
	       if (cur_ch == '%')
	          {
	          if (cur_ch == ':')
	             {
		     output_token(HASH_HASH, 4);
	             }
	          else
	             ;
	          }
	       else
	          {
		  output_token(HASH, 2);
		  }
	       }
	    else		
	       output_token(TOK_REMAINDER, 1);
	    break;

      case '?':
	       do_cur_ch();
	       if (cur_ch == '?')
	          {
	          do_cur_ch();
	          do_cur_ch();
		  total_trigraphs++;
		  }
	       else
	          output_token(TOK_QUESTION, 1);
	       break;

      case '(':		
	       output_token(TOK_OPEN_RND, 1);
	       do_cur_ch();
	       break;

      case ')':		
	       output_token(TOK_CL_RND, 1);
	       do_cur_ch();
	       break;

      case ',':		
	       output_token(TOK_COMMA, 1);
	       do_cur_ch();
	       break;

      case ';':		
	       output_token(TOK_SEMICOLON, 1);
	       do_cur_ch();
	       break;

      case '[':
	       output_token(TOK_OPEN_SQUARE, 1);
	       do_cur_ch();
	       break;

      case ']':
	       output_token(TOK_CL_SQUARE, 1);
	       do_cur_ch();
	       break;

      case '~':		/* can only be ~ */
	       output_token(TOK_BIT_NOT, 1);
	       do_cur_ch();
	       break;

      case '{':		
	       output_token(TOK_OPEN_CURL, 1);
	       cur_block_nest++;
	       do_cur_ch();
	       break;

      case '}':
	       output_token(TOK_CL_CURL, 1);
	       if (cur_block_nest > 0)
	          cur_block_nest--;
	       do_cur_ch();
	       break;

      case '@':
	    output_token(_AT_, 1);
	    do_cur_ch();
	    break;

      case '#':		/* could be # or ## */
	    do_cur_ch();
	    if (cur_ch == '#')	
	       {
	       output_token(HASH_HASH, 2);
	       do_cur_ch();
	       }
	    else		
	       output_token(HASH, 1);
	    break;

      case FILE_SEP_CHAR:
	       end_of_file();
	       do_cur_ch();
	       break;
      
      case '\\':
	       last_tok_splice=TRUE;
	       do_cur_ch();
	       break;
      
      default:               /* vertical white space and 'other' tokens */
	    seen_newline=FALSE;
	    /*
	     * Count whitespace between tokens, but not
	     * after newline, ie not indentation whitespace
	     */
	    num_whitespace=0;
	    last_was_whitespace=FALSE;
	    if (cur_ch == '\n')
	       {
	       output_token(TOK_NEW_LINE, 1);
	       seen_newline=TRUE;
	       do_end_of_line();
	       }
	    else
	       num_whitespace=(isspace(cur_ch) != 0);
	    if (num_whitespace == 1)
	       {
	       last_was_whitespace=TRUE;
	       }
	    do_cur_ch();

	    while (isspace(cur_ch) && !feof(stdin))
	       {
	       if (cur_ch == '\n')
		  {
	          output_token(TOK_NEW_LINE, 1);
	          seen_newline=TRUE;
		  last_was_whitespace=FALSE;
		  do_end_of_line();
		  }
	       else
	          {
		  num_whitespace++;
		  last_was_whitespace=TRUE;
		  }
	       do_cur_ch();
	       }
	    if (feof(stdin))
	       {
	       return 0;
	       }

	    break;
      }
   }

#if NGRAM_DEBUG
printf(":%d:", cur_token);
#endif

return 161+cur_token;
}

