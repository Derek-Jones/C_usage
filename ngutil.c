                    /* ngutil.c, 25 Sep 25 */

/*
 * Various utility functions used by ngram.c
 *
 * Written by Derek Jones to obtain typical developer usage
 * information for the 'cultural' aspects of the book
 * "The New C Standard: An economic and cultural commentary".
 *
 * Copyright (c) 2001-2005 Knowledge Software Ltd
 *
 This software is licensed under the terms of the GNU
 General Public License version 2 as published by the
 Free Software Foundation.
 
 It is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this software; see the file COPYING.  If not, write to
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.
 */

/*
 * The economic requirements for the production of this software
 * were driven by the need to produce data for use in a book.  A
 * cost/benefit analysis showed that it was not worthwhile investing
 * time during production to save time later, after the book had been
 * published, on maintenance.  Enjoy.
 */

/*
   8 Apr 21 DJ Added support for print_line_info
  17 Sep 07 DJ Negative check to speed up keyword search & C++ keyword support
   2 Nov 06 DJ Fixed prev_tok bug reported by Richard O'Keefe +
               related last_opkeyword issue
   1 May 06 DJ
       Elements in first_intdigit and first_fltdigit increased to 11
*/

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NGUTIL_DEBUG 0

/*
 * Information about switch statements
 */
struct block_info {
                   int switch_number;
		   int total_cases;
                   int cases_cur_stmt;
                   int switch_block_nest;
		   long lowest_case;
		   unsigned long highest_case;
                  } block_info[MAX_BLOCK_NEST];
struct {
        int case_count;
	long lowest_case;
	unsigned long highest_case;
       } switch_info[MAX_SWITCHES];

/*
 * Information on occurrence of preprocessor directives on
 * particular source lines.
 */
struct {
	int num_files,
	    /*
	     * 0 is the count for the current file
	     * 1 is the count for all files
	     * 2 is the count for files with more than MIN_DEFINC_LINES
	     */
	    num_define[3],
	    num_include[3],
	    num_pp_if,
	    num_pp_ifdef,
	    num_pp_else,
	    num_pp_error,
	    num_pp_line,
	    num_pp_pragma;
       } src_line_info[MAX_SRC_LINES];

BYTE cur_ch,
     prev_ch,
     cur_tok,
     prev_tok,
     prev_keyword,
     prev_punct,
     prev_op,
     prev_tok_not_nl;

BOOL last_was_log_newline,
     last_tok_case,
     last_tok_splice,
     last_tok_strlit,
     last_was_whitespace,
     seen_type_spec,
     seen_question_op,
     seen_class_templ,
     prev_class_templ,
     just_seen_hash,
     in_pp_directive,
     in_h_if,
     start_hdefine,
     is_first_tok,
     is_single_line_comment,
     expr_print,
     expr_at_start,
     chk_cpp = FALSE,
     print_int_cons = FALSE,
     print_idents = FALSE,
     print_puncts = FALSE,
     print_cntrl_expr = FALSE,
     print_for_cntrl_expr = FALSE,
     print_pp_body = FALSE,
     print_pp_direct = FALSE,
     print_strlit = FALSE,
     print_enum = FALSE,
     print_declinfo = FALSE,
     print_expr_stmt = FALSE,
     print_line_info = FALSE,
     print_block = FALSE,
     verify_mode = FALSE,
     seen_enum_hdr,              /* seen enum */
     seen_esu_hdr,               /* seen enum, struct, union keyword */
     seen_cntrl_hdr,             /* seen a keyword associated with a control expression */
     seen_for_cntrl_hdr;

int letter_bigram[NCHAR_MAX+1][NCHAR_MAX+1],
    all_bigram[NCHAR_MAX+1][NCHAR_MAX+1],
    token_bigram[2][NCHAR_MAX+1][NCHAR_MAX+1], /* use CHAR_MAX for type compatibility reasons */
    tok_literal[2][MAX_TOK][MAX_OP_LIT+5],
    first_tok[MAX_TOK],
    last_tok[MAX_TOK],
    case_literal[MAX_OP_LIT+5],
    lower_x_bigram[NCHAR_MAX+1],
    upper_x_bigram[NCHAR_MAX+1],
    digit_x_bigram[NCHAR_MAX+1],
    punct_x_bigram[NCHAR_MAX+1],
    x_lower_bigram[NCHAR_MAX+1],
    x_upper_bigram[NCHAR_MAX+1],
    x_digit_bigram[NCHAR_MAX+1],
    x_punct_bigram[NCHAR_MAX+1],
    all_letters[NCHAR_MAX+1],
    noncomment_letters[NCHAR_MAX+2],
    ident_lengths[MAX_IDENT_LEN],
    idents_on_cur_line,
    idents_on_line[MAX_TOKENS_PER_LINE],
    first_intdigit[11],
    first_fltdigit[11],
    first_hexdigit[16],
    hex_num_digits[MAX_HEX_DIGITS],
    intlit_count[MAX_LIT_LEN],
    hexlit_count[MAX_LIT_LEN],
    int_suffix_cnt[13],
    total_int_16,
    total_uint_16,
    total_long_16,
    total_ulong_16,
    total_other_16,
    total_int_32,
    total_uint_32,
    total_long_32,
    total_ulong_32,
    total_other_32,
    exp_uses_e, exp_uses_E,
    flt_suffix[3],
    flt_info[6][MAX_FLT_WIDTH+1],
    chars_in_cconst[NCHAR_MAX+1],
    cconst_len[MAX_CCONST_LEN],
    token_count[MAX_TOK+1],
    token_width[MAX_TOK+1],
    tok_nest[MAX_TOK+1][MAX_TOK_BLOCK_NEST+1],
    digraphs[MAX_TOK+1],
    num_type_specs[MAX_TYPE_SPECS],
    hex_pow_count[32],
    str_len_count[MAX_STR_LEN+8],
    cur_block_nest,
    total_single_line_comment,
    escape_seqs[4][NCHAR_MAX+1],
    exponent[1001],
    paren_nesting,
    line_len_count[MAX_LINE_LEN],
    line_len_diff[3][2*MAX_VISIBLE_LINE_LEN],
    cur_line_len,
    last_line_len,
    total_pp_splices,
    total_non_pp_splices,
    splice_count[MAX_SPLICE_CNT],
    splice_line_len_count[MAX_LINE_LEN],
    cur_splice_cnt,
    cur_src_line_cnt,
    cur_src_direct_cnt,
    cur_indentation,
    prev_indentation,
    nws_chars_on_line[MAX_LINE_LEN],
    opkeyword_tok[MAX_TOK][MAX_TOK],
    last_opkeyword,
    cur_logical_line_len,
    total_str_chars,
    total_str_bec_set, /* total basic execution character set count */
    total_str_line_splice,
    total_oct_literals,
    total_hex_literals,
    total_dec_literals,
    total_char_escapes,
    total_str_escapes,
    total_letters,
    total_phys_chars,
    total_logic_chars,
    total_tokens_inc_nl,
    total_tokens,
    tokens_on_cur_line,
    tokens_on_line[MAX_TOKENS_PER_LINE],
    total_trigraphs,
    total_switches,
    total_class_templ[2],
    total_coloncolon[2],
    total_32767[2],
    total_65535[2],
    bit_widths[MAX_BIT_WIDTH+1],
    def_rel_pos[101],
    inc_rel_pos[101],
    two_questions,
    cur_pp_if_depth,
    cur_pp_line_cnt,
    cur_pp_line_cnt,
    total_cases = -1,
    cases_per_stmt[MAX_CASES_PER_STMT],
    cases_cur_stmt = 0,
    switch_number,
    switch_block_nest = -1
    ;

long lowest_case;
unsigned long highest_case;

/*
 * Visible form of tokens
 */
char *tokens[MAX_TOK+1] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0, /* 69 */
":b",  /* bitfield width */
0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
"_BOOL",
"_COMPLEX",
"_IMAGINARY",
"AUTO",
"STATIC",
"EXTERN",
"REGISTER",
"TYPEDEF",
"CHAR",
"FLOAT",
"DOUBLE",
"INT",
"SHORT",
"LONG",
"UNSIGNED",
"SIGNED",
"VOID",
"CONST",
"VOLATILE",
"STRUCT",
"UNION",
"ENUM",
"IF",
"ELSE",
"WHILE",
"FOR",
"DO",
"SWITCH",
"CASE",
"DEFAULT",
"BREAK",
"CONTINUE",
"RETURN",
"GOTO",
"SIZEOF",
"(",
")",
"<<",
">>",
"+v",
"+",
"-v",
"-",
"*v",
"*",
"%",
"/",
"^",
"&v",
"&",
"|",
"~",
"!",
"<",
"<=",
">=",
">",
"==",
"!=",
"&&",
"||",
"?",
"?:",
".",
"->",
"++v",
"--v",
"v++",
"v--",
",",
";",
"...",
"{",
"}",
"[",
"]",
"=",
"+=",
"-=",
"*=",
"<<=",
">>=",
"&=",
"/=",
"%=",
"|=",
"^=",
":",
"*p",
"LIT",
"IDENT",
"STRING_LIT",
"PASCAL",
"FORTRAN",
"PPASM",
"ATTRIBUTE",
"TYPEOF",
"ALIGNOF",
"INLINE",
"RESTRICT",
"",
"",
"",
"#IF",
"#ELSE",
"#ELIF",
"#LINE",
"#ENDIF",
"#ERROR",
"#IFDEF",
"#PRAGMA",
"DEFINED",
"#INCLUDE",
"#DEFINE",
"#IFNDEF",
"#UNDEF",
"",
"",
"EXPR_STMT",
};

struct key_tag {
                char *key_str;
	        int tok_num,
		    occurrences;
               };
/*
 * Keywords ordered by length and then alphabetically.
 */
struct key_tag keywords[MAX_KEY_LEN][12] = {
   {{NULL, 0, 0}},
   {{NULL, 0, 0}},
   {{"do", TOK_DO, 0}, {"if", TOK_IF, 0},
    {NULL, 0, 0}},
   {{"for", TOK_FOR, 0}, {"int", TOK_INT, 0},
    {NULL, 0, 0}},
   {{"auto", TOK_AUTO, 0},
    {"case", TOK_CASE, 0}, {"char", TOK_CHAR, 0},
    {"elif", TOK_ELIF, 0}, {"else", TOK_ELSE, 0}, {"enum", TOK_ENUM, 0},
    {"goto", TOK_GOTO, 0},
    {"line", TOK_LINE, 0}, {"long", TOK_LONG, 0},
    {"void", TOK_VOID, 0},
    {NULL, 0, 0}},
   {{"break", TOK_BREAK, 0}, {"const", TOK_CONST, 0},
    {"endif", TOK_ENDIF, 0}, {"error", TOK_ERROR, 0},
    {"float", TOK_FLOAT, 0},
    {"ifdef", TOK_IFDEF, 0},
    {"short", TOK_SHORT, 0},
    {"undef", TOK_UNDEF, 0}, {"union", TOK_UNION, 0},
    {"while", TOK_WHILE, 0},
    {"_Bool", TOK__BOOL, 0},
    {NULL, 0, 0}},
   {{"define", TOK_DEFINE, 0}, {"double", TOK_DOUBLE, 0},
    {"extern", TOK_EXTERN, 0}, {"ifndef", TOK_IFNDEF, 0},
    {"pragma", TOK_PRAGMA, 0},
    {"return", TOK_RETURN, 0},
    {"signed", TOK_SIGNED, 0}, {"sizeof", TOK_SIZEOF, 0},
    {"static", TOK_STATIC, 0}, {"struct", TOK_STRUCT, 0},
    {"switch", TOK_SWITCH, 0},
    {NULL, 0, 0}},
   {{"default", TOK_DEFAULT, 0},
    {"include", TOK_INCLUDE, 0}, {"typedef", TOK_TYPEDEF, 0},
    {NULL, 0, 0}},
   {{"continue", TOK_CONTINUE, 0}, {"register", TOK_REGISTER, 0},
    {"unsigned", TOK_UNSIGNED, 0}, {"volatile", TOK_VOLATILE, 0},
    {"_Complex", TOK__COMPLEX, 0},
    {NULL, 0, 0}},
   {{NULL, 0, 0}},
   {{"_Imaginary", TOK__IMAGINARY, 0},
    {NULL, 0, 0}},
   };
/*
   "__LINE__",
   "__FILE__",
   "__DATE__",
   "__TIME__",
   "__STDC_VERSION__",
*/

char ident_str[IDENT_SAVE_LEN];
char cur_filename[MAX_CUR_FILE_LEN];


void print_char(int ch)
/*
 * 'meaningful' (in a C sense) visible form of a value
 * interpreted as a character.
 */
{
if (ch == ' ')
   printf(" sp");
else if (isprint(ch))
   printf("  %c", ch);
else
   if (ch == '\n')
      printf(" \\n");
   else
   if (ch == '\t')
      printf(" \\t");
   else
   if (ch == '\r')
      printf(" \\r");
   else
   printf("%3d", ch);
}

void count_letter(void)
/*
 * Various bigram letter counts.
 */
{
total_letters++;
letter_bigram[prev_ch][cur_ch]++;
noncomment_letters[cur_ch]++;
if (islower(prev_ch))
   lower_x_bigram[cur_ch]++;
if (islower(cur_ch))
   x_lower_bigram[prev_ch]++;
if (isupper(prev_ch))
   upper_x_bigram[cur_ch]++;
if (isupper(cur_ch))
   x_upper_bigram[prev_ch]++;
if (isdigit(prev_ch))
   digit_x_bigram[cur_ch]++;
if (isdigit(cur_ch))
   x_digit_bigram[prev_ch]++;
if (ispunct(prev_ch))
   punct_x_bigram[cur_ch]++;
if (ispunct(cur_ch))
   x_punct_bigram[prev_ch]++;
}


void do_end_of_line(void)
/*
 * Called everytime the input stream reaches an end of line
 */
{
cur_pp_line_cnt++;
cur_src_line_cnt++;

if (print_line_info)
   printf("%d %d %d %d %d %d\n", cur_line_len, cur_indentation,
				 tokens_on_cur_line, idents_on_cur_line,
				 in_pp_directive, last_tok_splice);

if (cur_line_len > 0)
   cur_line_len--; /* subtract 1 for the new-line character */

if (cur_line_len < MAX_LINE_LEN)
   line_len_count[cur_line_len]++;
/*
 * Calculate the line length difference between the current
 * and the last line.  Empty lines don't count.
 */
if ((cur_line_len != 0) &&
    (abs(cur_line_len-last_line_len) < MAX_VISIBLE_LINE_LEN))
   {
   line_len_diff[0][MAX_VISIBLE_LINE_LEN+cur_line_len-last_line_len]++;
   if (last_line_len > 59)
      line_len_diff[1][MAX_VISIBLE_LINE_LEN+cur_line_len-last_line_len]++;
   if (last_line_len < 20)
      line_len_diff[2][MAX_VISIBLE_LINE_LEN+cur_line_len-last_line_len]++;
   last_line_len=cur_line_len;
   }

#if 0
{
static int line_num = 0;

line_num++;
printf("line %d, line len %d, last indent %d\n", line_num, cur_line_len, prev_indentation);
}
#endif

if (cur_line_len-cur_indentation < MAX_LINE_LEN)
   nws_chars_on_line[cur_line_len-cur_indentation]++;

if (last_tok_splice)
   {
   if (in_pp_directive)
      total_pp_splices++;
   else
      total_non_pp_splices++;
   cur_splice_cnt++;
   cur_logical_line_len+=(cur_line_len-1); /* and 1 for the splice */
   last_tok_splice=FALSE;
   }
else
   {
   last_was_log_newline=TRUE;
   if (cur_splice_cnt > 0)
      if (cur_splice_cnt < MAX_SPLICE_CNT)
         {
         splice_count[cur_splice_cnt]++;
	 cur_splice_cnt=0;
	 cur_logical_line_len+=cur_line_len;
	 if (cur_logical_line_len < MAX_LINE_LEN)
	   splice_line_len_count[cur_logical_line_len]++;
         cur_logical_line_len=0;
	 }
   }
if (idents_on_cur_line < MAX_TOKENS_PER_LINE)
   idents_on_line[idents_on_cur_line]++;
if (tokens_on_cur_line < MAX_TOKENS_PER_LINE)
   tokens_on_line[tokens_on_cur_line]++;
prev_indentation=cur_indentation;
cur_indentation=0;
idents_on_cur_line=0;
tokens_on_cur_line=0;
/*
 * prev_tok_not_nl is zero until a non-newline token is encountered.
 */
if (prev_tok_not_nl != 0)
   last_tok[prev_tok_not_nl]++;
is_first_tok=TRUE;
cur_line_len=0;
}


void next_ch(void)
/*
 * Lowest level read of character from input stream.
 * Called by do_cur_ch and do_comment_ch.
 */
{
cur_ch=getchar();
total_phys_chars++;
if (cur_ch == '\t')
   {
   total_logic_chars+=SPACES_IN_TAB;
   cur_line_len+=SPACES_IN_TAB;
   }
else
   {
   total_logic_chars++;
   cur_line_len++;
   }
all_bigram[prev_ch][cur_ch]++;
all_letters[cur_ch]++;

#if NGUTIL_DEBUG
   {
static int c_count;
   c_count++;
   printf("%c", cur_ch);
   if ((c_count % 100) == 0)
      {
      printf("\n");
      c_count=0;
      }
   }
#endif
}

void do_cur_ch(void)
{
prev_ch=cur_ch;
next_ch();
count_letter();
}


BYTE conv_tok(BYTE token)
/*
 * Attempt to deduce whether an operator token is the binary
 * or unary form, the pre/post form, or the preprocessor
 * directive form of that token (based on the immediately
 * surrounding tokens).
 */
{
if (just_seen_hash)
   {
   /*
    * These are the only identifiers that can be either
    * keywords or preprocessing directives.
    */
   if (token == TOK_IF)
      token=TOK_H_IF;
   else if (token == TOK_ELSE)
      token=TOK_H_ELSE;
   }
if ((token == TOK_PRE_PLUS) || (token == TOK_PRE_MINUS))
   switch (prev_tok_not_nl)
      {
      /*
       * The following are the only tokens than can immediately
       * preceed a postfix operator.
       */
      case TOK_CL_RND:
      case TOK_CL_SQUARE:
      case TOK_IDENTIFIER:
                if (token == TOK_PRE_PLUS)
                   token=TOK_POST_PLUS;
                if (token == TOK_PRE_MINUS)
                   token=TOK_POST_MINUS;
		break;
   
      default : 
	        break;
      }
else
   switch (prev_tok_not_nl)
      {
      /*
       * The following are the only tokens than can immediately
       * preceed a binary operator.
       */
      case TOK_CL_RND:
      case TOK_CL_SQUARE:
      case INTEGER_CONST:
      case CHAR_CONST:
      case FLOAT_CONST:
      case STRING_CONST:
      case TOK_LITERAL:
      case TOK_IDENTIFIER:
      case TOK_POST_PLUS:
      case TOK_POST_MINUS: 
		       break;
   
      case TOK_PTR: 
      case TOK_VOID: 
      case TOK_CHAR: 
      case TOK_SHORT:
      case TOK_INT: 
      case TOK_LONG: 
      case TOK_FLOAT: 
      case TOK_DOUBLE: 
      case TOK_SIGNED: 
      case TOK_UNSIGNED: 
      case TOK_CONST: 
      case TOK_VOLATILE: 
                if (token == TOK_TIMES)
                   token=TOK_PTR;
		break;
   
      default : if (token == TOK_MINUS)
                   token=TOK_ARITH_NEG;
                if (token == TOK_ADD)
                   token=TOK_PLUS;
                if (token == TOK_TIMES)
                   token=TOK_STAR;
                if (token == TOK_BIT_AND)
                   token=TOK_ADDR;
	        break;
      }
if (token == TOK_COLON)
   {
   if (seen_question_op)
      token = TOK_QCOLON;
   else if (seen_type_spec) /* don't want to catch casts */
      token = TOK_BIT_WIDTH;
   }
return token;
}

void type_specifier(BYTE token)
/*
 * If we have a type specifier add its encoded form into
 * the 'current' type specifier information.
 */
{
static int cur_type_spec = 0;

switch (token)
   {
   case TOK_VOID: cur_type_spec = (cur_type_spec << 4) | TS_VOID;
		  seen_type_spec=TRUE;
		  break;

   case TOK__BOOL: cur_type_spec = (cur_type_spec << 4) | TS_BOOL;
		  seen_type_spec=TRUE;
		  break;

   case TOK__COMPLEX: cur_type_spec = (cur_type_spec << 4) | TS_COMPLEX;
		  seen_type_spec=TRUE;
		  break;

   case TOK__IMAGINARY: cur_type_spec = (cur_type_spec << 4) | TS_IMAGINARY;
		  seen_type_spec=TRUE;
		  break;

   case TOK_CHAR: cur_type_spec = (cur_type_spec << 4) | TS_CHAR;
		  seen_type_spec=TRUE;
		  break;

   case TOK_FLOAT: cur_type_spec = (cur_type_spec << 4) | TS_FLOAT;
		  seen_type_spec=TRUE;
		  break;

   case TOK_DOUBLE: cur_type_spec = (cur_type_spec << 4) | TS_DOUBLE;
		  seen_type_spec=TRUE;
		  break;

   case TOK_INT	: cur_type_spec = (cur_type_spec << 4) | TS_INT;
		  seen_type_spec=TRUE;
		  break;

   case TOK_SHORT: cur_type_spec = (cur_type_spec << 4) | TS_SHORT;
		  seen_type_spec=TRUE;
		  break;

   case TOK_LONG: cur_type_spec = (cur_type_spec << 4) | TS_LONG;
		  seen_type_spec=TRUE;
		  break;

   case TOK_UNSIGNED: cur_type_spec = (cur_type_spec << 4) | TS_UNSIGNED;
		  seen_type_spec=TRUE;
		  break;

   case TOK_SIGNED: cur_type_spec = (cur_type_spec << 4) | TS_SIGNED;
		  seen_type_spec=TRUE;
		  break;


   case TOK_OPEN_CURL:
   case TOK_CL_CURL:
   case TOK_SEMICOLON:
		  seen_type_spec=FALSE;
		  /* FALL THROUGH */
   case TOK_DEFINE:
   case TOK_ELIF:
   case TOK_ELSE:
   case TOK_ENDIF:
   case TOK_STAR:
   case TOK_COMMA:
   case TOK_OPEN_RND:
   case TOK_OPEN_SQUARE:
   case TOK_CL_RND:  if (cur_type_spec != 0)
			num_type_specs[cur_type_spec]++;
		     cur_type_spec = 0;
		     break;

   default: break;

   }
if ((cur_type_spec << 4) > MAX_TYPE_SPECS)
   {
   if (verify_mode)
      printf("type_specifier overflow: %d\n", token);
   cur_type_spec=0;
   }
}

void output_space(void)
/*
 * Does not really output a space, but increments various
 * counts as if one had been output.
 */
{
token_count[TOK_SPACE]++;
token_bigram[0][prev_tok][TOK_SPACE]++;
token_bigram[1][prev_tok_not_nl][TOK_SPACE]++;
}

void semicolon_output(void)
/*
 * We have encountered a semi-colon.  Used to indicate
 * that we must (not) be in various state(s).
 */
{
if (cases_cur_stmt != 0)
   cases_per_stmt[cases_cur_stmt]++;
cases_cur_stmt=0;
}

void switch_output(void)
/*
 * We have encountered a switch.  Used to indicate
 * that we must (not) be in various state(s).
 */
{
semicolon_output(); /* handle case 2: switch (x) { case 4: */
block_info[cur_block_nest].switch_number=switch_number;
block_info[cur_block_nest].total_cases=total_cases;
block_info[cur_block_nest].switch_block_nest=switch_block_nest;
block_info[cur_block_nest].lowest_case=lowest_case;
block_info[cur_block_nest].highest_case=highest_case;
switch_block_nest=cur_block_nest;
total_cases=0;
highest_case=0;
lowest_case=LONG_MAX;
total_switches++;
switch_number=total_switches;
}

void close_curl_output(void)
{
/*
 * We have encountered a semi-colon.  Used to indicate
 * that we must (not) be in various state(s).
 * Have we just unnested from a switch statement?
 */
if (switch_block_nest == cur_block_nest)
   {
   if (verify_mode && (total_cases == 0))
      printf("total_cases=0\n");
   switch_info[switch_number].case_count=total_cases;
   switch_info[switch_number].lowest_case=lowest_case;
   switch_info[switch_number].highest_case=highest_case;
   switch_number=block_info[cur_block_nest].switch_number;
   total_cases=block_info[cur_block_nest].total_cases;
   switch_block_nest=block_info[cur_block_nest].switch_block_nest;
   lowest_case=block_info[cur_block_nest].lowest_case;
   highest_case=block_info[cur_block_nest].highest_case;
   }
}

void case_output(void)
/*
 * We have encountered a case.  Used to indicate
 * that we must (not) be in various state(s).
 */
{
if (verify_mode && (switch_block_nest+1 != cur_block_nest))
   printf("switch block nest=%d, cur block nest=%d\n",
                     switch_block_nest, cur_block_nest);
total_cases++;
cases_cur_stmt++;
last_tok_case=TRUE;
}

void default_output(void)
{
/*
 * with other labels???
 */
}

#if STMT_PARSING
void output_token(BYTE token,
		  unsigned int tok_width)
{
if ((token == CHAR_CONST) || (token == INTEGER_CONST) ||
    (token == FLOAT_CONST))
   cur_tok=TOK_LITERAL;
else
if (token == STRING_CONST)
   cur_tok=TOK_STRING_LIT;
else
if (token == TOK_BIT_AND)
   cur_tok=TOK_ADDR;
else
   cur_tok=token;
}

#else
void output_token(BYTE token,
		  unsigned int tok_width)
/*
 * Called for every token built.
 */
{
total_tokens_inc_nl++;
token=conv_tok(token);
cur_tok=token;
type_specifier(token);
token_count[token]++;
token_width[token]+=tok_width;
token_bigram[0][prev_tok][token]++;
if (cur_block_nest < MAX_TOK_BLOCK_NEST)
   tok_nest[token][cur_block_nest]++;
else
   tok_nest[token][MAX_TOK_BLOCK_NEST]++;

/*
 * Various cases where a visible form of token is
 * written to stdout.  Output only occurs if one of the
 * print_* variables will has been set to true.  The complicated
 * tests are an attempt to limit the output to those tokens
 * directly associated with the construct being output.
 */
if (print_puncts && (token >= FIRST_PUNCT_TOK && token <= LAST_PUNCT_TOK))
   printf("%s\n", tokens[token]);
if (print_enum && seen_enum_hdr)
   if (token == TOK_IDENTIFIER)
      printf("%s ", ident_str);
   else
      printf("%s ", tokens[token]);
if (print_expr_stmt && (cur_block_nest > 0) &&
    (!(seen_cntrl_hdr || seen_for_cntrl_hdr)) &&
    (token != TOK_NEW_LINE) &&
    !is_comment_tok(token))
   {
   if ((token == TOK_SEMICOLON) || (token == TOK_OPEN_CURL))
      {
      if (expr_print)
         printf("\n");
      expr_print=TRUE;
      expr_at_start=TRUE;
      }
   else if (((token >= TOK_BREAK) && (token <= TOK_GOTO)) ||
            (expr_at_start && ((token >= TOK__BOOL) && (token <= TOK_ENUM))) ||
	    (expr_at_start && (token >= _AT_) && (token <= HEADER_NAME)) ||
	    (token >= TOK_START_PP_DIRECT))
      expr_print=FALSE;
   else if (expr_print)
      {
      expr_at_start=FALSE;
      if ((token != TOK_CL_CURL) &&
	  ((token < TOK_IF) || (token > TOK_SWITCH)))
	 printf("%s ", tokens[token]);
      }
   }
if ((seen_esu_hdr && (token != INTEGER_CONST)) ||
    (((print_for_cntrl_expr && seen_for_cntrl_hdr) ||
      (print_cntrl_expr && seen_cntrl_hdr)) &&
     (paren_nesting > 0)))
   if ((token == TOK_IDENTIFIER) && (print_for_cntrl_expr || print_declinfo))
      printf("%s ", ident_str);
   else
      printf("%s ", tokens[token]);
if (print_block)
   {
   if (((token >= TOK__BOOL) && (token < TOK_SIZEOF)) ||
       (token == TOK_OPEN_CURL) || (token == TOK_CL_CURL) ||
       (token == TOK_OPEN_RND) || (token == TOK_CL_RND) ||
       (token == TOK_SEMICOLON) || (token == TOK_COMMA) ||
       (token == TOK_EQUAL))
      printf("%s\n", tokens[token]);
   }
if (in_pp_directive && print_pp_body)
   {
   if ((token == TOK_IDENTIFIER) && start_hdefine)
      {
      if (cur_ch == '(')
         printf("FUNC_MAC ");
      else
         printf("OBJ_MAC ");
      start_hdefine=FALSE;
      }
   else
      printf("%s ", tokens[token]);
   }

if (is_first_tok)
   {
   is_first_tok=FALSE;
   first_tok[token]++;
   }

/*
 * Certain kinds of 'token's that we don't want to affect
 * the counts made.
 */
if ((token != TOK_NEW_LINE) &&
    (token != COMMENT) &&
    (token != COMMENT_NL) &&
    (token != CPP_COMMENT))
   {
   token_bigram[1][prev_tok_not_nl][token]++;
   prev_tok_not_nl=token;
   total_tokens++;
   tokens_on_cur_line++;
   if (last_opkeyword != 0) /* Is zero at start of file */
      opkeyword_tok[last_opkeyword][token]++;
   /*
    * SIZEOF is not treated as a keyword.
    * Most of TOK_AUTO..TOK_ENUM occur in casts and are ignored.
    * Assignment (TOK_EQUAL) is treated as a keyword.
    * Including { } enables reduces the silly results, which are just
    * arguments of function calls.
    */
   if ((token >= TOK_IF) && (token <= TOK_GOTO))
      last_opkeyword=token;
   else if ((token == TOK_EQUAL) ||
	    (token == TOK_SEMICOLON) ||
	    (token == TOK_CL_CURL) ||
	    (token == TOK_OPEN_CURL))
      last_opkeyword=token;
   }
if (last_was_whitespace)
   {
   last_was_whitespace=FALSE;
   token_bigram[0][TOK_SPACE][token]++;
   token_bigram[1][TOK_SPACE][token]++;
   }
else
   {
   /*
    * The LINE_START 'token' occurs when there is no
    * whitespace at the start of a line.
    */
   if ((token == TOK_NEW_LINE) || (prev_tok == TOK_NEW_LINE))
      token_count[TOK_LINE_START]++;
   if (token == TOK_NEW_LINE)
      {
      token_bigram[0][prev_tok][TOK_LINE_START]++;
      token_bigram[1][prev_tok][TOK_LINE_START]++;
      }
   if (prev_tok == TOK_NEW_LINE)
      {
      token_bigram[0][TOK_LINE_START][token]++;
      token_bigram[1][TOK_LINE_START][token]++;
      }
   }
if (token != COMMENT_NL)
   prev_tok=token;
}
#endif


void do_comment_ch(void)
/*
 * Non-default handling of characters within a comment.
 */
{
next_ch();
prev_ch=cur_ch;
if (cur_ch == '\n')
   {
   is_single_line_comment=FALSE;
   output_token(COMMENT_NL, 0);
   do_end_of_line();
   }
}

void count_digraph(BYTE token)
/*
 * Count digraphs (added in Amendment 1 to C90).
 */
{
digraphs[token]++;
}


void lex_identifier(int ident_len)
/*
 * No keyword starts with an L, so there is no need to worry
 * about the non-wide character constant case.
 */
{
int id_index,
    cmp_id;

if (ident_len == 1)
   ident_str[0]='L';
while ((cur_ch == '_') ||
       isalpha(cur_ch) ||
       isdigit(cur_ch))
   {
   if (ident_len < IDENT_SAVE_LEN-1)
      ident_str[ident_len]=cur_ch;
   ident_len++;
   do_cur_ch();
   }
if (ident_len < IDENT_SAVE_LEN)
   ident_str[ident_len]='\0';
else
   ident_str[IDENT_SAVE_LEN-1]='\0';
idents_on_cur_line++;
/*
 * Is the identifier a keyword?
 */
if (ident_len < MAX_KEY_LEN)
   {
   struct key_tag *key_ptr = keywords[ident_len];

   while (key_ptr->key_str != NULL)
      {
      cmp_id=strcmp(ident_str, key_ptr->key_str);
      if (cmp_id < 0)
         break;
      if (cmp_id == 0)
         {
	 if ((key_ptr->tok_num < TOK_START_PP_DIRECT) ||
	     just_seen_hash)
	    {
	    key_ptr->occurrences++;
	    output_token(key_ptr->tok_num, ident_len);
	    return;
	    }
	 break;
	 }
      key_ptr++;
      }
   }
if (in_h_if && (strcmp(ident_str, "defined") == 0))
   {
   output_token(TOK_DEFINED, ident_len);
   return;
   }
if (chk_cpp &&
    ((strcmp(ident_str, "class") == 0) ||
     (strcmp(ident_str, "template") == 0)))
   {
   seen_class_templ=TRUE;
   }
/*
 * Do not rely on: ident_len < IDENT_SAVE_LEN-1
 */
if (print_idents)
   {
   for (id_index=0; id_index < ident_len; id_index++)
      printf("%c", ident_str[id_index]);
   printf("\n");
   }
output_token(TOK_IDENTIFIER, ident_len);
if (ident_len >= MAX_IDENT_LEN)
   ident_len=MAX_IDENT_LEN-1;
ident_lengths[ident_len]++;
}


void lex_float(int cur_tok_len,
	       int first_nz_digit)
/*
 * Lex a floating-point constant.
 */
{
const int start_all_char_count=total_phys_chars;
int exp_val = 0,
    exp_sign,
    is_first_digit = TRUE,
    has_exponent = 0,
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
   dp_offset--;
   if ((cur_ch == 'E') || (cur_ch == 'e'))
      dp_offset=MAX_FLT_WIDTH;
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
   if (exp_val < 500)
      exponent[500 + (exp_sign * exp_val)]++;
   else
      if (exp_sign == 1)
         exponent[1000]++;
      else
         exponent[0]++;
   }

if ((cur_ch == 'F') || (cur_ch == 'f'))
   {
   do_cur_ch();
   flt_suffix[1]++;
   }
else if ((cur_ch == 'l') || (cur_ch == 'L'))
   {
   do_cur_ch();
   flt_suffix[2]++;
   }
else
   flt_suffix[0]++;
/*
 * Some people love to type digits
 */
if (cur_tok_len+total_phys_chars-start_all_char_count < MAX_FLT_WIDTH)
   {
   flt_info[0+has_exponent*3][cur_tok_len+total_phys_chars-start_all_char_count]++;
   flt_info[1+has_exponent*3][dp_offset]++;
   flt_info[2+has_exponent*3][digits_after_dp]++;
   }
output_token(FLOAT_CONST, cur_tok_len+total_phys_chars-start_all_char_count);
}

void int_const_cnt(LONGEST_UINT lit_valu,
                   BOOL is_decimal,
		   int int_suffix)
/*
 * Figure out the type of an integer constant and
 * add one to the appropriate counts.
 */
{
long signed_lit;

/*
 * decimal constants only have an unsigned type if suffixed
 * The numeric values for the suffixes are created by
 * lex_int_suffix.
 *
 * Count occurrences for both a 16 and 32 bit implementation
 */
switch (int_suffix)
   {
   case 0: /* no suffix*/
      if (lit_valu <= INT_MAX_32)
         total_int_32++;
      else
         if ((lit_valu <= UINT_MAX_32) && !is_decimal)
            total_uint_32++;
         else
            total_other_32++;
      if (lit_valu <= INT_MAX_16)
         total_int_16++;
      else
         if ((lit_valu <= UINT_MAX_16) && !is_decimal)
            total_uint_16++;
         else
            if (lit_valu <= LONG_MAX_16)
               total_long_16++;
            else
               if (lit_valu <= ULONG_MAX_16)
                  total_ulong_16++;
               else
                  total_ulong_16++;
      break;

   case 0x01: /* u/U suffix*/
      if (lit_valu <= UINT_MAX_32)
         total_uint_32++;
      else
         total_other_32++;
      if (lit_valu <= UINT_MAX_16)
         total_uint_16++;
      else
         if (lit_valu <= ULONG_MAX_16)
            total_ulong_16++;
         else
            total_other_16++;
      break;

   case 0x02: /* l/L suffix*/
      if (lit_valu <= INT_MAX_32)
         total_long_32++;
      else
         if ((lit_valu <= UINT_MAX_32) && !is_decimal)
            total_ulong_32++;
         else
            total_other_32++;
      if (lit_valu <= LONG_MAX_16)
         total_long_16++;
      else
         if ((lit_valu <= ULONG_MAX_16) && !is_decimal)
            total_ulong_16++;
         else
            total_other_16++;
      break;

   case 0x03: /* u/U l/L suffix*/
      if (lit_valu <= UINT_MAX_32)
         total_ulong_32++;
      else
         total_other_32++;
      if (lit_valu <= ULONG_MAX_16)
         total_ulong_16++;
      else
         total_other_16++;
      break;

   default: /* all other suffixes (not many occurrences) */
      total_other_32++;
      total_other_16++;
      break;
   }

if (lit_valu <= 32767)
   total_32767[is_decimal]++;
if (lit_valu <= 65535)
   total_65535[is_decimal]++;
if (lit_valu < MAX_OP_LIT)
   tok_literal[is_decimal][prev_tok_not_nl][lit_valu]++;
else if (lit_valu < 512)
   tok_literal[is_decimal][prev_tok_not_nl][MAX_OP_LIT]++;
else if (lit_valu < 1024)
   tok_literal[is_decimal][prev_tok_not_nl][MAX_OP_LIT+1]++;
else if (lit_valu < 32767)
   tok_literal[is_decimal][prev_tok_not_nl][MAX_OP_LIT+2]++;
else
   tok_literal[is_decimal][prev_tok_not_nl][MAX_OP_LIT+3]++;
/*
 * The one situation where we bother about constants
 * being negated
 */
if (last_tok_case)
   {
   if (prev_tok_not_nl == TOK_MINUS)
      signed_lit=-lit_valu;  /* negating an unsigned quantity :-O */
   else
      signed_lit=lit_valu;

   if (lit_valu < MAX_OP_LIT)
      case_literal[lit_valu]++;
   else
      case_literal[MAX_OP_LIT]++;
   /*
    * This combination of tests is nowhere near complicated
    * enough to handle all possible combinations of values/types.
    * But it handles most.
    */
   if (highest_case < signed_lit)
      highest_case=signed_lit;
   if (lowest_case > signed_lit)
      lowest_case=signed_lit;
   last_tok_case=FALSE;
   }
}

int lex_int_suffix(void)
/*
 * Handle integer constant suffixes.
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
int_suffix_cnt[suffix_flag]++;

if ((suffix_flag & 0x08) != 0)
   suffix_flag |= 0x01 | (suffix_flag & 0x07);
return suffix_flag;
}

void output_int_cons(LONGEST_UINT int_valu,
                     BOOL is_dec)
{
if (is_dec)
   printf("%lu ", int_valu);
else
   printf("0x%lx ", int_valu);
}

void lex_number(void)
/*
 * It could be an integer or floating-point constant
 */
{
int power_10,
    power_16,
    hex_valu,
    int_suffix,
    first_nz_digit,
    num_digits = 0;
LONGEST_UINT  ten_lit_valu;
int start_all_char_count=total_phys_chars;
BOOL is_first_digit = TRUE;

lit_valu = (cur_ch - '0');
do_cur_ch();
if ((cur_ch == 'x') ||
    (cur_ch == 'X'))
   {
   do_cur_ch();
   while (is_hex_digit(cur_ch))
      {
      num_digits++;
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

   if (num_digits < MAX_HEX_DIGITS)
      hex_num_digits[num_digits]++;
   if ((prev_tok_not_nl == TOK_BIT_WIDTH) &&
       (lit_valu < MAX_BIT_WIDTH))
      bit_widths[lit_valu]++;
   if (print_int_cons)
      output_int_cons(lit_valu, FALSE);
   int_suffix=lex_int_suffix();
   int_const_cnt(lit_valu, FALSE, int_suffix);
   if (lit_valu < 1024)
      hexlit_count[lit_valu]++;
   ten_lit_valu=lit_valu;
   power_10=0;
   while (ten_lit_valu > 9)
      {
      ten_lit_valu /= 10;
      power_10++;
      }
   hexlit_count[1024 + power_10]++;
   power_16=0;
   while (lit_valu > 0)
      {
      lit_valu /= 16;
      power_16++;
      }
   hex_pow_count[power_16]++;
   output_token(INTEGER_CONST, total_phys_chars-start_all_char_count);
   total_hex_literals++;
   return;
   }

first_nz_digit=lit_valu;
total_dec_literals++; /* subtract off octal count below */
if (lit_valu == 0)
   {
   while (isdigit(cur_ch))
      {
      if (is_first_digit && (cur_ch != '0'))
         {
         total_oct_literals++; /* will not count a single '0' */
	 total_dec_literals--;
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
   lex_float(total_phys_chars-start_all_char_count, first_nz_digit);
   return;
   }
else
   first_intdigit[first_nz_digit]++;
if (print_int_cons)
   output_int_cons(lit_valu, TRUE);
if ((prev_tok_not_nl == TOK_BIT_WIDTH) &&
    (lit_valu < MAX_BIT_WIDTH))
   bit_widths[lit_valu]++;
int_suffix=lex_int_suffix();
int_const_cnt(lit_valu, TRUE, int_suffix); /* octal not that common :-| */
if (lit_valu < 1024)
   intlit_count[lit_valu]++;
power_10=0;
while (lit_valu > 9)
   {
   lit_valu /= 10;
   power_10++;
   }
intlit_count[1024 + power_10]++;
output_token(INTEGER_CONST, total_phys_chars-start_all_char_count);
}


LONGEST_UINT do_escape(char char_str)
/*
 * Process escape sequences
 */
{
int num_octal_digits;
LONGEST_UINT escape_valu = 0;

escape_seqs[char_str][cur_ch]++;

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
   num_octal_digits=0;
   while ((cur_ch >= '0') &&
          (cur_ch <= '7') &&
	  (num_octal_digits != 3))
      {
      num_octal_digits++;
      escape_valu = (escape_valu << 3) | (cur_ch - '0');
      do_cur_ch();
      }
   }
else
   {
   switch (cur_ch)
      {
      case 'a': escape_valu='\a';
		break;

      case 'b': escape_valu='\b';
		break;

      case 'e': escape_valu='\e';
		break;

      case 'f': escape_valu='\f';
		break;

      case 'n': escape_valu='\n';
		break;

      case 'r': escape_valu='\r';
		break;

      case 't': escape_valu='\t';
		break;

      case 'v': escape_valu='\v';
		break;

      case '\\': escape_valu='\\';
		break;

      case '\'': escape_valu='\'';
		break;

      case '\"': escape_valu='\"';
		break;

      default : escape_valu=cur_ch;
		break;
      }
   do_cur_ch();
   return escape_valu;
   }

if (escape_valu < NCHAR_MAX)
   escape_seqs[2+char_str][escape_valu]++;
else
   escape_seqs[2+char_str][NCHAR_MAX]++;
return escape_valu;
}

void lex_char_const(BOOL is_wide)
/*
 * Process a character constant
 */
{
const int start_all_char_count=total_phys_chars;
int char_count = 0;
LONGEST_UINT escape_valu;

do_cur_ch();
while ((cur_ch != '\'') && (cur_ch != '\n') && !feof(stdin))
   {
   char_count++;
   if (cur_ch == '\\')
      {
      total_char_escapes++;
      do_cur_ch();
      escape_valu=do_escape(0);
      if (escape_valu <= NCHAR_MAX)
         chars_in_cconst[escape_valu]++;
      }
   else if (cur_ch == '?')
      {
      do_cur_ch();
      if (cur_ch == '?')
         {
	 do_cur_ch();
         if ((cur_ch == '(') || (cur_ch == ')') ||
             (cur_ch == '<') || (cur_ch == '>') ||
             (cur_ch == '/') || (cur_ch == '!') ||
             (cur_ch == '-') || (cur_ch == '=') ||
             (cur_ch == '\''))
	    {
            chars_in_cconst[cur_ch]++; /* TODO map trigraph */
	    do_cur_ch();
	    total_trigraphs++;
	    }
	 else
	    two_questions++;
	 }
      }
   else
      {
      chars_in_cconst[cur_ch]++;
      do_cur_ch();
      }
   }
if (char_count < MAX_CCONST_LEN)
   cconst_len[char_count]++;
if (cur_ch != '\n')
   do_cur_ch();
output_token(CHAR_CONST, total_phys_chars-start_all_char_count);
}


void str_char_usage(char ch)
{
total_str_chars++;
if (in_bec_set(ch))
   total_str_bec_set++;
}


void lex_str_const(BOOL is_wide)
/*
 * Process a string constant
 */
{
int str_len = 0;
const int start_all_char_count = total_phys_chars;
int escape_ch;

do_cur_ch();
if (prev_tok == TOK_INCLUDE)
   {
   if (print_pp_direct)
      printf("\" ");
   while ((cur_ch != '\"') && (cur_ch != '\n') && !feof(stdin))
      {
      if (print_pp_direct)
         printf("%c", cur_ch);
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
      do_cur_ch();
      }
   if (cur_ch != '\n')
      do_cur_ch();
   output_token(HEADER_NAME , total_phys_chars-start_all_char_count);
   if (print_pp_direct)
      printf("\n");
   return;
   }
/*
 * TODO
if (last_tok_strlit)
   ???
*/
last_tok_strlit=TRUE;
while ((cur_ch != '\"') && (cur_ch != '\n'))
   {
   if (cur_ch == '\\')
      {
      do_cur_ch();
      if (cur_ch == '\n')
         {
	 total_str_line_splice++;
         last_tok_splice=TRUE;
	 do_end_of_line();
         do_cur_ch();
	 }
      else
         {
         if (print_strlit)
            printf("%c", cur_ch);
         total_str_escapes++;
	 escape_ch=do_escape(1);
	 str_char_usage(escape_ch);
	 str_len++;
	 }
      }
   else if (cur_ch == '?')
      {
      if (print_strlit)
         printf("%c", cur_ch);
      str_char_usage(cur_ch);
      do_cur_ch();
      if (cur_ch == '?')
         {
	 do_cur_ch();
         if ((cur_ch == '(') || (cur_ch == ')') ||
             (cur_ch == '<') || (cur_ch == '>') ||
             (cur_ch == '/') || (cur_ch == '!') ||
             (cur_ch == '-') || (cur_ch == '=') ||
             (cur_ch == '\''))
	    {
	    do_cur_ch();
	    total_trigraphs++;
	    }
	 else
	    two_questions++;
	 }
      str_len++;
      }
   else
      {
      if (print_strlit)
         printf("%c", cur_ch);
      str_char_usage(cur_ch);
      do_cur_ch();
      str_len++;
      }
   }
if (print_strlit)
   printf("\n");
if (str_len < MAX_STR_LEN)
   str_len_count[str_len]++;
else
   {
   if (str_len < 300)
      str_len_count[MAX_STR_LEN]++;
   else if (str_len < 350)
      str_len_count[MAX_STR_LEN+1]++;
   else if (str_len < 450)
      str_len_count[MAX_STR_LEN+2]++;
   else if (str_len < 750)
      str_len_count[MAX_STR_LEN+3]++;
   else if (str_len < 1500)
      str_len_count[MAX_STR_LEN+4]++;
   else if (str_len < 4095)
      str_len_count[MAX_STR_LEN+5]++;
   else if (str_len < 10000)
      str_len_count[MAX_STR_LEN+6]++;
   else
      str_len_count[MAX_STR_LEN+7]++;
   }
if (cur_ch != '\n')
   do_cur_ch();
output_token(STRING_CONST, total_phys_chars-start_all_char_count);
}


void do_comment(void)
/*
 * A C90 style comment
 */
{
const int start_all_char_count = total_phys_chars-1;

is_single_line_comment=TRUE;
do_comment_ch();
while (!feof(stdin))
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
if (is_single_line_comment)
   total_single_line_comment++;
do_cur_ch();

output_token(COMMENT, total_phys_chars-start_all_char_count);
}


void do_cpp_comment(void)
/*
 * A C++ style comment
 */
{
int start_all_char_count = total_phys_chars-1;

do_comment_ch();
while (!feof(stdin))
   {
   if (cur_ch == '\n')
      break;
   do_comment_ch();
   }
output_token(CPP_COMMENT, total_phys_chars-start_all_char_count);
}


void end_of_file(void)
/*
 * Called everytime the input stream reaches an 'end of file',
 * i.e., the value 242 (FILE_SET_CHAR) is encountered.
 */
{
int l;
const int max_lines = (cur_src_line_cnt < MAX_SRC_LINES) ?
				cur_src_line_cnt : (MAX_SRC_LINES-1);
/*
 * Generate an identifier and hope that no C source contains it
 * as an identifier
 */
if (print_idents ||
    print_cntrl_expr ||
    print_for_cntrl_expr ||
    print_pp_body ||
    print_pp_direct ||
    print_declinfo ||
    print_expr_stmt ||
    print_block ||
    print_enum ||
    print_strlit)
   printf("__E__O__F__\n");

if (verify_mode)
   printf("%s\n", cur_filename);

/*
 * Add in current file #define and #include counts
 */
for (l=1; l <= max_lines; l++)
   {
   def_rel_pos[(100*l)/cur_src_line_cnt]+=src_line_info[l].num_define[0];
   inc_rel_pos[(100*l)/cur_src_line_cnt]+=src_line_info[l].num_include[0];
   if (cur_src_line_cnt > MIN_DEFINC_LINES)
      {
      src_line_info[l].num_define[2]+=src_line_info[l].num_define[0];
      src_line_info[l].num_include[2]+=src_line_info[l].num_include[0];
      }
   src_line_info[l].num_define[1]+=src_line_info[l].num_define[0];
   src_line_info[l].num_include[1]+=src_line_info[l].num_include[0];
   src_line_info[l].num_define[0]=0;
   src_line_info[l].num_include[0]=0;
   }
// This consistency check confuses ident processing.
if ((cur_pp_if_depth!=0) && (!print_idents))
   printf("pp if depth=%d\n", cur_pp_if_depth);
cur_pp_if_depth=0;
cur_block_nest=0;
last_was_log_newline=TRUE;
last_was_whitespace=FALSE;
in_pp_directive=FALSE;
last_opkeyword=0;
cur_indentation=0;
prev_indentation=0;
is_first_tok=TRUE;
switch_block_nest=-1;
total_cases=0;
seen_type_spec=FALSE;
seen_cntrl_hdr=FALSE;
seen_for_cntrl_hdr=FALSE;
seen_esu_hdr=FALSE;
prev_keyword=0;
prev_punct=0;
prev_op=0;
idents_on_cur_line=0;
tokens_on_cur_line=0;
expr_print=FALSE;
expr_at_start=TRUE;
if (cur_src_line_cnt < MAX_SRC_LINES-1)
   src_line_info[cur_src_line_cnt].num_files++;
else
   src_line_info[MAX_SRC_LINES-1].num_files++;
cur_src_line_cnt=0;
cur_src_direct_cnt=0;
if (chk_cpp)
   {
   print_cpp();
   total_class_templ[0]=0;
   total_class_templ[1]=0;
   total_coloncolon[0]=0;
   total_coloncolon[1]=0;
   }
}


void get_cur_filename(void)
{
int cur_file_len=0;

cur_ch=getchar();
while (cur_ch !=  FILE_SEP_CHAR)
   {
   if (cur_file_len < MAX_CUR_FILE_LEN-1)
      cur_filename[cur_file_len]=cur_ch;
   cur_file_len++;
   cur_ch=getchar();
   }
if (cur_file_len < MAX_CUR_FILE_LEN)
   cur_filename[cur_file_len]='\0';
else
   cur_filename[MAX_CUR_FILE_LEN-1]='\0';
do_cur_ch();
}

