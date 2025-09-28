                  /* nprint.c, 18 Sep 07 */

/*
 * This prints out the information counted by by ngram.
 * It is #include'ed by ngram.
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
   18 Sep 07 DJ Added print_cpp
    2 Nov 06 DJ TOK_T_DEF_NAME not needed as a token
   27 Feb 05 DJ Minor updates
   14 Jul 03 DJ Initial release
 */

/*
 * The economic requirements for the production of this software
 * were driven by the need to produce data for use in a book.  A
 * cost/benefit analysis showed that it was not worthwhile investing
 * time during production to save time later, after the book had been
 * published, on maintenance.  Enjoy.
 */

/*
 * Now print out the information we have accumulated.
 * On the whole the format is:
 * File: some_name.d
 * data
 * End File
 * Various awk scripts canb search for some_name.d to locate
 * the numbers they need.
 * The data is space separated (rather than comma separated)
 * to simplify the awk scripts.
 * These File:/End pairs may have other 'useful' numbers or
 * 'helpful' comments between them.
 */

char *TS_str[] = {
		  "",
		  "VOID",
		  "CHAR",
		  "FLOAT",
		  "DOUBLE",
		  "INT",
		  "SHORT",
		  "LONG",
		  "UNSIGNED",
		  "SIGNED",
		  "BOOL",
		  "COMPLEX",
		  "IMAGINARY",
		 };

int total_bigram_tokens,
    total_bigram_width;
unsigned int top_bigrams[3][MAX_TOP_BIGRAMS];

void get_top_bigrams(int upper_bound, int (*bigrams)[NCHAR_MAX+1])
/*
 * Return the top MAX_MAX_BIGRAMS, from the array bigrams,
 * in the array top_bigrams.
 */
{
int ch_1,
    ch_2,
    ch_3,
    top_index;

for (ch_1=0; ch_1 < MAX_TOP_BIGRAMS; ch_1++)
       top_bigrams[0][ch_1]=0;
top_bigrams[0][0]=UINT_MAX; /* no count bigger than this */

/*
 * Loop over the input array of bigrams
 */
for (ch_1=0; ch_1 <= upper_bound; ch_1++)
   {
   for (ch_2=0; ch_2 <= upper_bound; ch_2++)
      /*
       * Is this count larger than the smallest count we have
       * seen so far?  If so, figure out where to insert this
       * entry in the numerically sorted output array.  Shuffle
       * up the existing entries to make room and insert it.
       */
      if (bigrams[ch_1][ch_2] > top_bigrams[0][MAX_TOP_BIGRAMS-1])
         {
	 top_index=MAX_TOP_BIGRAMS-1;
         while (bigrams[ch_1][ch_2] > top_bigrams[0][top_index])
	    top_index--;
	 for (ch_3=MAX_TOP_BIGRAMS-1; ch_3 > top_index+1; ch_3--)
	    {
	    top_bigrams[0][ch_3]=top_bigrams[0][ch_3-1];
	    top_bigrams[1][ch_3]=top_bigrams[1][ch_3-1];
	    top_bigrams[2][ch_3]=top_bigrams[2][ch_3-1];
	    }
	 top_bigrams[0][top_index+1]=bigrams[ch_1][ch_2];
	 top_bigrams[1][top_index+1]=ch_1;
	 top_bigrams[2][top_index+1]=ch_2;
	 }
   }
}


void sp_tok_sp_bigrams(int upper_bound, int (*bigrams)[NCHAR_MAX+1])
/*
 * Return counts for the bigrams 'space' 'token' and 'token' 'space'
 * Where 'token' is one of the classes of pp-token or token,
 * 'space' can be any whitespace.
 */
{
int ch_1;

for (ch_1=0; ch_1 <= upper_bound; ch_1++)
   {
   switch (ch_1)
      {
      case _AT_:
      case TOK_SPACE:
      case TOK_NEW_LINE:
      case TOK_LINE_START:
      case COMMENT_NL:
      			  break;
      
      case COMMENT:
      case CPP_COMMENT:
			  sp_tok_sp[0][TK_COMMENT] += token_count[ch_1];
			  sp_tok_sp[1][TK_COMMENT] += token_width[ch_1];
			  sp_tok_sp[2][TK_COMMENT] += bigrams[TOK_SPACE][ch_1];
			  sp_tok_sp[3][TK_COMMENT] += bigrams[TOK_LINE_START][ch_1];
			  sp_tok_sp[4][TK_COMMENT] += bigrams[ch_1][TOK_SPACE];
			  sp_tok_sp[5][TK_COMMENT] += bigrams[ch_1][TOK_LINE_START];
      			  break;
      
      case TOK_LITERAL:
      case CHAR_CONST:
      case INTEGER_CONST:
      case FLOAT_CONST:
			  sp_tok_sp[0][TK_CONSTANT] += token_count[ch_1];
			  sp_tok_sp[1][TK_CONSTANT] += token_width[ch_1];
			  sp_tok_sp[2][TK_CONSTANT] += bigrams[TOK_SPACE][ch_1];
			  sp_tok_sp[3][TK_CONSTANT] += bigrams[TOK_LINE_START][ch_1];
			  sp_tok_sp[4][TK_CONSTANT] += bigrams[ch_1][TOK_SPACE];
			  sp_tok_sp[5][TK_CONSTANT] += bigrams[ch_1][TOK_LINE_START];
      			  break;

      case STRING_CONST:
			  sp_tok_sp[0][TK_STRING_LIT] += token_count[ch_1];
			  sp_tok_sp[1][TK_STRING_LIT] += token_width[ch_1];
			  sp_tok_sp[2][TK_STRING_LIT] += bigrams[TOK_SPACE][ch_1];
			  sp_tok_sp[3][TK_STRING_LIT] += bigrams[TOK_LINE_START][ch_1];
			  sp_tok_sp[4][TK_STRING_LIT] += bigrams[ch_1][TOK_SPACE];
			  sp_tok_sp[5][TK_STRING_LIT] += bigrams[ch_1][TOK_LINE_START];
      			  break;


      case TOK_AUTO:
      case TOK_STATIC:
      case TOK_EXTERN:
      case TOK_REGISTER:
      case TOK_TYPEDEF:
      case TOK_CHAR:
      case TOK_FLOAT:
      case TOK_DOUBLE:
      case TOK_INT:
      case TOK_SHORT:
      case TOK_LONG:
      case TOK_UNSIGNED:
      case TOK_SIGNED:
      case TOK_VOID:
      case TOK_CONST:
      case TOK_VOLATILE:
      case TOK_STRUCT:
      case TOK_UNION:
      case TOK_ENUM:
      case TOK_IF:
      case TOK_ELSE:
      case TOK_WHILE:
      case TOK_FOR:
      case TOK_DO:
      case TOK_SWITCH:
      case TOK_CASE:
      case TOK_DEFAULT:
      case TOK_BREAK:
      case TOK_CONTINUE:
      case TOK_RETURN:
      case TOK_GOTO:
      case TOK_SIZEOF:
      
      case TOK_PASCAL:
      case TOK_FORTRAN:
      case TOK_PPASM:
      case TOK_ATTRIBUTE:
      case TOK_TYPEOF:
      case TOK_ALIGNOF:

      /*
       * New in C99
       */
	  case TOK_INLINE:
	  case TOK_RESTRICT:
	  case TOK__BOOL:
	  case TOK__COMPLEX:
	  case TOK__IMAGINARY:
		  sp_tok_sp[0][TK_KEYWORD] += token_count[ch_1];
		  sp_tok_sp[1][TK_KEYWORD] += token_width[ch_1];
		  sp_tok_sp[2][TK_KEYWORD] += bigrams[TOK_SPACE][ch_1];
		  sp_tok_sp[3][TK_KEYWORD] += bigrams[TOK_LINE_START][ch_1];
		  sp_tok_sp[4][TK_KEYWORD] += bigrams[ch_1][TOK_SPACE];
		  sp_tok_sp[5][TK_KEYWORD] += bigrams[ch_1][TOK_LINE_START];
		  break;

	  case TOK_ELIF:
	  case TOK_LINE:
	  case TOK_ENDIF:
	  case TOK_ERROR:
	  case TOK_IFDEF:
	  case TOK_PRAGMA:
	  case TOK_DEFINED:
	  case TOK_INCLUDE:
	  case TOK_DEFINE:
	  case TOK_IFNDEF:
	  case TOK_UNDEF:
		  sp_tok_sp[0][TK_PP_DIRECT] += token_count[ch_1];
		  sp_tok_sp[1][TK_PP_DIRECT] += token_width[ch_1];
		  sp_tok_sp[2][TK_PP_DIRECT] += bigrams[TOK_SPACE][ch_1];
		  sp_tok_sp[3][TK_PP_DIRECT] += bigrams[TOK_LINE_START][ch_1];
		  sp_tok_sp[4][TK_PP_DIRECT] += bigrams[ch_1][TOK_SPACE];
		  sp_tok_sp[5][TK_PP_DIRECT] += bigrams[ch_1][TOK_LINE_START];
		  break;

      case HASH_HASH:
      case HASH:
      case TOK_OPEN_RND:
      case TOK_LSHIFT:
      case TOK_RSHIFT:
      case TOK_PLUS:
      case TOK_ADD:
      case TOK_ARITH_NEG:
      case TOK_MINUS:
      case TOK_STAR:
      case TOK_TIMES:
      case TOK_REMAINDER:
      case TOK_DIVIDE:
      case TOK_BIT_XOR:
      case TOK_ADDR:
      case TOK_BIT_AND:
      case TOK_BIT_OR:
      case TOK_BIT_NOT:
      case TOK_LOG_NOT:
      case TOK_LESS_THAN:
      case TOK_LESS_EQUAL:
      case TOK_GR_EQUAL:
      case TOK_GREATER_THAN:
      case TOK_EQ_EQUAL:
      case TOK_EXC_EQUAL:
      case TOK_LOG_AND:
      case TOK_LOG_OR:
      case TOK_QUESTION:
      case TOK_COLON:
      case TOK_CL_RND:
      case TOK_DIR_SELECT:
      case TOK_INDIR_SELECT:
      case TOK_PRE_PLUS:
      case TOK_PRE_MINUS:
      case TOK_COMMA:
      case TOK_SEMICOLON:
      case TOK_ELLIPSIS:
      case TOK_OPEN_CURL:
      case TOK_CL_CURL:
      case TOK_OPEN_SQUARE:
      case TOK_CL_SQUARE:
      case TOK_EQUAL:
      case TOK_PLUS_EQUAL:
      case TOK_MIN_EQUAL:
      case TOK_MULT_EQUAL:
      case TOK_LSH_ASSIGN:
      case TOK_RSH_ASSIGN:
      case TOK_AND_ASSIGN:
      case TOK_DIV_EQUAL:
      case TOK_REM_EQUAL:
      case TOK_BOR_ASSIGN:
      case TOK_BXOR_ASSIGN:
			  sp_tok_sp[0][TK_PUNCTUATOR] += token_count[ch_1];
			  sp_tok_sp[1][TK_PUNCTUATOR] += token_width[ch_1];
			  sp_tok_sp[2][TK_PUNCTUATOR] += bigrams[TOK_SPACE][ch_1];
			  sp_tok_sp[3][TK_PUNCTUATOR] += bigrams[TOK_LINE_START][ch_1];
			  sp_tok_sp[4][TK_PUNCTUATOR] += bigrams[ch_1][TOK_SPACE];
			  sp_tok_sp[5][TK_PUNCTUATOR] += bigrams[ch_1][TOK_LINE_START];
      			  break;


      case TOK_IDENTIFIER:
			  sp_tok_sp[0][TK_IDENTIFIER] += token_count[ch_1];
			  sp_tok_sp[1][TK_IDENTIFIER] += token_width[ch_1];
			  sp_tok_sp[2][TK_IDENTIFIER] += bigrams[TOK_SPACE][ch_1];
			  sp_tok_sp[3][TK_IDENTIFIER] += bigrams[TOK_LINE_START][ch_1];
			  sp_tok_sp[4][TK_IDENTIFIER] += bigrams[ch_1][TOK_SPACE];
			  sp_tok_sp[5][TK_IDENTIFIER] += bigrams[ch_1][TOK_LINE_START];

      			  break;

      default:
			  break;
      }
   }
}

void print_sptoksp(char *format, int sp_kind)
{
/*
 * Add 1 to prevent divide by zero errors.
 */
printf(format,
	  100.0*(sp_tok_sp[0][sp_kind]/(double)total_bigram_tokens),
	  100.0*(sp_tok_sp[1][sp_kind]/(double)total_bigram_width),
	  100.0*(sp_tok_sp[2][sp_kind]/(double)(1+sp_tok_sp[0][sp_kind])),
	  100.0*(sp_tok_sp[3][sp_kind]/(double)(1+sp_tok_sp[0][sp_kind])),
	  100.0*(sp_tok_sp[4][sp_kind]/(double)(1+sp_tok_sp[0][sp_kind])),
	  100.0*(sp_tok_sp[5][sp_kind]/(double)(1+sp_tok_sp[0][sp_kind]))
		  );
}


void print_array(int *p_info, char *description)
{   
int ch_1;

printf("%s\n", description); 
       
for (ch_1=0; ch_1 <= NCHAR_MAX; ch_1++)
   {
   print_char(ch_1);
   printf(", %7d\n", p_info[ch_1]);
   }
}   
		        

void start_file(char *file_str)
{
if (cur_out_file != NULL)
   printf(">>>>>>>>>>>>> called start_file before matching end_file: %s\n",
			cur_out_file);
printf("File: %s\n", file_str);
cur_out_file=file_str;
}


void end_file(char *file_str)
{
if (strcmp(file_str, cur_out_file) != 0)
   printf(">>>>>>>>>>>>> Output file mismatch: %s : %s\n",
			cur_out_file, file_str);
cur_out_file=NULL;
printf("End File\n");
}


void print_op_lit(int tok_op, char *d_str)
{
int ch_1,
    total_dec = 0,
    total_hex = 0;

printf("Occurrences of an operator followed by constant (dec hex) of a given value\n");
start_file(d_str);
for (ch_1=0; ch_1 < MAX_OP_LIT; ch_1++)
   if ((tok_literal[0][tok_op][ch_1] != 0) ||
       (tok_literal[1][tok_op][ch_1] != 0))
      {
      printf("%3d %7d %7d\n", ch_1, tok_literal[0][tok_op][ch_1],
                                    tok_literal[1][tok_op][ch_1]);
      total_hex+=tok_literal[0][tok_op][ch_1];
      total_dec+=tok_literal[1][tok_op][ch_1];
      }
end_file(d_str);
printf("Occurrences of constant (dec hex) less than the given value\n");
printf("512 %7d %7d\n", tok_literal[0][tok_op][MAX_OP_LIT]+0,
                        tok_literal[1][tok_op][MAX_OP_LIT]+0);
printf("1024 %7d %7d\n", tok_literal[0][tok_op][MAX_OP_LIT]+1,
                         tok_literal[1][tok_op][MAX_OP_LIT]+1);
printf("32767 %7d %7d\n", tok_literal[0][tok_op][MAX_OP_LIT]+2,
                          tok_literal[1][tok_op][MAX_OP_LIT]+2);
printf("MAX_ULONG %7d %7d\n", tok_literal[0][tok_op][MAX_OP_LIT]+3,
                              tok_literal[1][tok_op][MAX_OP_LIT]+3);
printf("Total hex %7d\n", total_hex+
			tok_literal[0][tok_op][MAX_OP_LIT+0]+
			tok_literal[0][tok_op][MAX_OP_LIT+1]+
			tok_literal[0][tok_op][MAX_OP_LIT+2]+
			tok_literal[0][tok_op][MAX_OP_LIT+3]);
printf("Total dec %7d\n", total_dec+
			tok_literal[1][tok_op][MAX_OP_LIT+0]+
			tok_literal[1][tok_op][MAX_OP_LIT+1]+
			tok_literal[1][tok_op][MAX_OP_LIT+2]+
			tok_literal[1][tok_op][MAX_OP_LIT+3]);
}

void print_opkeyword_tok(int tok_op, char *d_str)
{
int ch_1;

start_file(d_str);
for (ch_1=0; ch_1 < MAX_TOK; ch_1++)
   if (opkeyword_tok[ch_1][tok_op] != 0)
      {
      printf("%s  %7d\n", tokens[ch_1], opkeyword_tok[ch_1][tok_op]);
      }
end_file(d_str);
}


void print_results(void)
{
int ch_1,
    ch_2,
    ch_3,
    ind,
    total_punct_toks,
    est_switch_bounds,
    total_flt_constant,
    total_int_constant;
struct key_tag *key_ptr;
int case_density[101] = {0};

printf("Total physical characters = %d, total logical characters = %d, total (non-comment) letters = %d\n",
			total_phys_chars, total_logic_chars, total_letters);
printf("Total trigraphs = %d, two ?'s only = %d\n",
			total_trigraphs, two_questions);

/*
for (ch_1=0; ch_1 <= NCHAR_MAX; ch_1++)
   {
   printf("%.3d", ch_1);
   for (ch_2=0; ch_2 <= NCHAR_MAX; ch_2++)
      printf(", %7d", letter_bigram[ch_1][ch_2]);
   printf("\n");
   }
*/

get_top_bigrams(NCHAR_MAX, letter_bigram);
printf("Top %d (noncomment) letter digraphs\n", MAX_TOP_BIGRAMS-1);
printf(" ch   ch    occurrences  percentage of chars  ???   ???\n");
for (ch_3=1; ch_3 < MAX_TOP_BIGRAMS; ch_3++)
   {
   if (top_bigrams[0][ch_3] == 0)
      break;
   print_char(top_bigrams[1][ch_3]);
   printf("  ");
   print_char(top_bigrams[2][ch_3]);
   printf("  %7d  %.2f  %7d  %.2f\n",
			top_bigrams[0][ch_3],
			100.0*(top_bigrams[0][ch_3] / (double)total_letters),
		all_bigram[top_bigrams[1][ch_3]][top_bigrams[2][ch_3]],
		100.0*(all_bigram[top_bigrams[1][ch_3]][top_bigrams[2][ch_3]] /
			 (double)total_phys_chars));
   }

get_top_bigrams(NCHAR_MAX, all_bigram);
printf("Top %d (comment) letter digraphs\n", MAX_TOP_BIGRAMS-1);
for (ch_3=1; ch_3 < MAX_TOP_BIGRAMS; ch_3++)
   {
   if (top_bigrams[0][ch_3] == 0)
      break;
   print_char(top_bigrams[1][ch_3]);
   printf("  ");
   print_char(top_bigrams[2][ch_3]);
   printf("  %7d  %.2f  %7d  %.2f\n",
			top_bigrams[0][ch_3],
			100.0*(top_bigrams[0][ch_3] / (double)total_phys_chars),
		letter_bigram[top_bigrams[1][ch_3]][top_bigrams[2][ch_3]],
		100.0*(letter_bigram[top_bigrams[1][ch_3]][top_bigrams[2][ch_3]] /
			 (double)total_letters));
   }

#if 000
print_array(lower_x_bigram, "lower case/x bigrams");
print_array(x_lower_bigram, "x/lower case bigrams");
print_array(upper_x_bigram, "upper case/x bigrams");
print_array(x_upper_bigram, "x/upper case bigrams");
print_array(digit_x_bigram, "digit/x bigrams");
print_array(x_digit_bigram, "x/digit bigrams");
print_array(punct_x_bigram, "punctuation/x bigrams");
print_array(x_punct_bigram, "x/punctuation bigrams");
#endif

printf("character   all_letters   non_comment_letters\n");
start_file("charfreq.d");
for (ch_1=0; ch_1 <= NCHAR_MAX; ch_1++)
   {
   print_char(ch_1);
   printf("  %9d  %.3f  %9d  %.3f\n",
		all_letters[ch_1],
		100.0*(all_letters[ch_1]/(double)total_phys_chars),
		noncomment_letters[ch_1],
		100.0*(noncomment_letters[ch_1]/(double)total_letters));
   }
end_file("charfreq.d");

start_file("identlen.d");
for (ind=1; ind < MAX_IDENT_LEN; ind++)
   printf("%2d %7d\n", ind, ident_lengths[ind]);
end_file("identlen.d");

start_file("hex_ndigit.d");
for (ch_1=0; ch_1 < MAX_HEX_DIGITS; ch_1++)
   {
   if (hex_num_digits[ch_1] != 0)
      printf(" %3d %7.3f %7d\n", ch_1, 
		100.0*(hex_num_digits[ch_1]/(double)total_hex_literals),
		hex_num_digits[ch_1]);
   }
end_file("hex_ndigit.d");

start_file("int_cons_kind.d");
total_int_constant=total_oct_literals + total_hex_literals + total_dec_literals;
printf("decimal-constant %2.1f\n", 100*(total_dec_literals/(double)total_int_constant));
printf("hexadecimal-constant %2.1f\n", 100*(total_hex_literals/(double)total_int_constant));
printf("octal-constant %2.1f\n", 100*(total_oct_literals/(double)total_int_constant));
end_file("int_cons_kind.d");

start_file("int_cons_type.d");
total_int_constant=total_int_16+total_uint_16+total_long_16+total_ulong_16+total_other_16;
printf("int ,, %2.3f ,, %2.3f\n",
		100*(total_int_16/(double)total_int_constant),
		100*(total_int_32/(double)total_int_constant));
printf("unsigned int ,, %2.3f ,, %2.3f\n",
		100*(total_uint_16/(double)total_int_constant),
		100*(total_uint_32/(double)total_int_constant));
printf("long ,, %2.3f ,, %2.3f\n",
		100*(total_long_16/(double)total_int_constant),
		100*(total_long_32/(double)total_int_constant));
printf("unsigned long ,, %2.3f ,, %2.3f\n",
		100*(total_ulong_16/(double)total_int_constant),
		100*(total_ulong_32/(double)total_int_constant));
printf("other-types ,, %2.3f ,, %2.3f\n",
		100*(total_other_16/(double)total_int_constant),
		100*(total_other_32/(double)total_int_constant));
end_file("int_cons_type.d");

printf("Suffix ordering (i.e., U or L first) is encoded in the counts\n");
start_file("intsuffix.d");
printf("none  %2.4f\n", 100*(int_suffix_cnt[0x00]/(double)total_int_constant));
printf("U/u  %2.4f\n", 100*(int_suffix_cnt[0x01]/(double)total_int_constant));
printf("L/l  %2.4f\n", 100*(int_suffix_cnt[0x02]/(double)total_int_constant));
printf("U/uL/ul  %2.4f\n", 100*(int_suffix_cnt[0x03]/(double)total_int_constant));
printf("Lu/lU  %2.4f\n", 100*(int_suffix_cnt[0x0a]/(double)total_int_constant));
printf("LL/lL/ll  %2.4f\n", 100*(int_suffix_cnt[0x04]/(double)total_int_constant));
printf("ULL/uLl/ulL/Ull  %2.4f\n", 100*(int_suffix_cnt[0x05]/(double)total_int_constant));
printf("LLU/lLu/LlU/llu  %2.4f\n", 100*(int_suffix_cnt[0x0c]/(double)total_int_constant));
end_file("intsuffix.d");
total_flt_constant= flt_suffix[0]+flt_suffix[1]+flt_suffix[2];
start_file("fltsuffix.d");
printf("none  %2.4f\n", 100*(flt_suffix[0]/(double)total_flt_constant));
printf("F/f  %2.4f\n", 100*(flt_suffix[1]/(double)total_flt_constant));
printf("L/l  %2.4f\n", 100*(flt_suffix[2]/(double)total_flt_constant));
end_file("fltsuffix.d");

printf("Literals <= 32767 hex %.2f, dec %.2f\n",
                           100*total_32767[0]/(double)total_hex_literals,
                           100*total_32767[1]/(double)total_dec_literals);
printf("Literals <= 65535 hex %.2f, dec %.2f\n",
                           100*total_65535[0]/(double)total_hex_literals,
                           100*total_65535[1]/(double)total_dec_literals);
printf("Literal values, octal literals=%d\n", total_oct_literals);
start_file("intlitvals.d");
for (ind=0; ind < 1024; ind++)
   printf("%3d %7d\n", ind, intlit_count[ind]);
end_file("intlitvals.d");
printf("Powers of 10\n");
for (ind=1024; ind < MAX_LIT_LEN; ind++)
   printf("%2d %7d\n", ind-1024, intlit_count[ind]);

start_file("benfordint.d");
for (ind=0; ind < 10; ind++)
   printf("%d %7d\n", ind, first_intdigit[ind]);
end_file("benfordint.d");

start_file("benfordhex.d");
for (ind=0; ind < 16; ind++)
   printf("%d %7d\n", ind, first_hexdigit[ind]);
end_file("benfordhex.d");

start_file("benfordflt.d");
for (ind=0; ind < 10; ind++)
   printf("%d %7d\n", ind, first_fltdigit[ind]);
end_file("benfordflt.d");

printf("Hex literals  %d\n", total_hex_literals);
start_file("hexlitvals.d");
for (ind=0; ind < 1024; ind++)
   printf("%3d %7d\n", ind, hexlit_count[ind]);
end_file("hexlitvals.d");

printf("Powers of 10\n");
for (ind=1024; ind < MAX_LIT_LEN; ind++)
   printf("%2d %7d\n", ind-1024, hexlit_count[ind]);
printf("Powers of 16\n");
for (ind=0; ind < 10; ind++)
   printf("%2d %7d\n", ind, hex_pow_count[ind]);

printf("Uses e = %d, uses E = %d\n", exp_uses_e, exp_uses_E);
printf("no dp: %d %d %d  %d %d %d\n",
		flt_info[0][MAX_FLT_WIDTH], flt_info[1][MAX_FLT_WIDTH],
		flt_info[2][MAX_FLT_WIDTH],
		flt_info[3][MAX_FLT_WIDTH], flt_info[4][MAX_FLT_WIDTH],
		flt_info[5][MAX_FLT_WIDTH]);
printf("chars in float-constant  digits before dp  digits after dp\n");
printf("              with exponent                       without exponent\n");
start_file("fltconst.d");
for (ind=0; ind < MAX_FLT_WIDTH; ind++)
   {
   printf("%3d  %7d  %7d  %7d  %7d  %7d  %7d\n",
		ind, flt_info[3][ind], flt_info[4][ind], flt_info[5][ind],
		  flt_info[0][ind], flt_info[1][ind], flt_info[2][ind]);
   }
end_file("fltconst.d");

printf("The following 'keywords' include all identifiers in preprocessor directives\n");
start_file("keywordall.d");
for (ind=2; ind < 9; ind++)
   {
   key_ptr=keywords[ind];
   while (key_ptr->key_str)
      {
      printf("%s %7d\n", key_ptr->key_str, key_ptr->occurrences);
      key_ptr++;
      }
   }
end_file("keywordall.d");

#if 0
printf("Token digrams\n");
for (ch_1=0; ch_1 <= MAX_TOK; ch_1++)
   {
   printf("%.3d", ch_1);
   for (ch_2=0; ch_2 <= MAX_TOK; ch_2++)
      printf("  %7d", token_digram[1][ch_1][ch_2]);
   printf("\n");
   }
#endif
/********
for (ch_1=0; ch_1 <= MAX_TOK; ch_1++)
   {
   printf("CHAR_CONST %12s  %7d\n", tokens[ch_1], token_digram[1][CHAR_CONST][ch_1]);
   printf("%12s CHAR_CONST  %7d\n", tokens[ch_1], token_digram[1][ch_1][CHAR_CONST]);
   }
********/

printf("Preprocessing directives separated out, keyword count is accurate\n");
printf("Total_tokens %d inc_newline %d single_line_comment %d\n",
	  total_tokens, total_tokens_inc_nl, total_single_line_comment);
printf("token     as %% of tokens  [as %% of punctuation tokens] occurrences\n");
start_file("tokcnt.d");
total_punct_toks=0;
for (ch_1=TOK_OPEN_RND; ch_1 <= LAST_PUNCT_TOK; ch_1++)
   total_punct_toks += token_count[ch_1];
for (ch_1=0; ch_1 <= MAX_TOK; ch_1++)
   if (token_count[ch_1] != 0)
      {
      if ((ch_1 < TOK_OPEN_RND) || (ch_1 > LAST_PUNCT_TOK))
         printf("%-12s  %2.2f  %7d\n",
		   tokens[ch_1],
		   100.0*(token_count[ch_1]/(double)total_tokens),
		   token_count[ch_1]);
      else
         printf("%-12s  %2.2f  %2.2f  %7d\n",
		   tokens[ch_1],
		   100.0*(token_count[ch_1]/(double)total_tokens),
		   100.0*(token_count[ch_1]/(double)total_punct_toks),
		   token_count[ch_1]);
      }
end_file("tokcnt.d");

start_file("tokblkcnt.d");
for (ch_1=0; ch_1 <= MAX_TOK; ch_1++)
   {
   if (tokens[ch_1] != NULL)
      {
      printf("%-12s  ", tokens[ch_1]);
      for (ch_2=0; ch_2 <= MAX_TOK_BLOCK_NEST; ch_2++)
         printf("  %7d", tok_nest[ch_1][ch_2]);
      printf("\n");
      }
   }
end_file("tokblkcnt.d");

printf("Digraph counts\n");
start_file("digraph.d");
for (ch_1=0; ch_1 <= MAX_TOK; ch_1++)
   if (digraphs[ch_1] != 0)
      printf("%12s  %7d\n", tokens[ch_1], digraphs[ch_1]);
end_file("digraph.d");

get_top_bigrams(MAX_TOK, token_bigram[0]);
printf("Top %d token bigrams\n", MAX_TOP_BIGRAMS-1);
printf("    tok      tok   occurrences   %% all tokens   %% 1st token  %% 2nd token\n");
start_file("tokbigramnl.d");
for (ch_3=1; ch_3 < MAX_TOP_BIGRAMS; ch_3++)
   {
   if (top_bigrams[0][ch_3] == 0)
      break;
   if ((tokens[top_bigrams[1][ch_3]] == 0) ||
       (tokens[top_bigrams[1][ch_3]] == 0))
      {
      /*
      printf("bigram=%d\n", top_bigrams[1][ch_3]);
      */
      continue;
      }
   printf("%13s %13s %7d %9f %.1f %.1f\n",
			tokens[top_bigrams[1][ch_3]],
			tokens[top_bigrams[2][ch_3]],
			top_bigrams[0][ch_3],
			top_bigrams[0][ch_3] / (double)total_tokens_inc_nl,
			100.0*(top_bigrams[0][ch_3] /
				(double)token_count[top_bigrams[1][ch_3]]),
			100.0*(top_bigrams[0][ch_3] /
				(double)token_count[top_bigrams[2][ch_3]]));
   }
end_file("tokbigramnl.d");

get_top_bigrams(MAX_TOK, token_bigram[1]);
printf("Top %d token, not newline, bigrams\n", MAX_TOP_BIGRAMS-1);
printf("    tok      tok   occurrences   %% all tokens   %% 1st token  %% 2nd token\n");
start_file("tokbigram.d");
for (ch_3=1; ch_3 < MAX_TOP_BIGRAMS; ch_3++)
   {
   if (top_bigrams[0][ch_3] == 0)
      break;
   if ((tokens[top_bigrams[1][ch_3]] == 0) ||
       (tokens[top_bigrams[1][ch_3]] == 0))
      {
      /*
      printf("bigram=%d\n", top_bigrams[1][ch_3]);
      */
      continue;
      }
   printf("%13s %13s %7d %9f %.1f %.1f\n",
			tokens[top_bigrams[1][ch_3]],
			tokens[top_bigrams[2][ch_3]],
			top_bigrams[0][ch_3],
			top_bigrams[0][ch_3] / (double)total_tokens,
			100.0*(top_bigrams[0][ch_3] /
				(double)token_count[top_bigrams[1][ch_3]]),
			100.0*(top_bigrams[0][ch_3] /
				(double)token_count[top_bigrams[2][ch_3]]));
   }
end_file("tokbigram.d");

start_file("parennest.d");
for (ch_1=1; ch_1 < MAX_PAREN_NESTING; ch_1++)
   if (paren_info[ch_1] == 0)
      break;
   else
      printf("%2d %7d\n", ch_1, paren_info[ch_1]);
end_file("parennest.d");

start_file("squarenest.d");
for (ch_1=1; ch_1 < MAX_SQUARE_NESTING; ch_1++)
   if (square_info[ch_1] == 0)
      break;
   else
      printf("%2d %7d\n", ch_1, square_info[ch_1]);
end_file("squarenest.d");

printf("total characters = %d, characters in basic execution character set = %d\n", total_str_chars, total_str_bec_set);
printf("Strings line spliced=%d\n", total_str_line_splice);
start_file("strlen.d");
for (ch_1=0; ch_1 < MAX_STR_LEN+8; ch_1++)
   printf("%3d %7d\n", ch_1, str_len_count[ch_1]);
end_file("strlen.d");

{
long total_cchars=0,
     total_src_cchars=0;

for (ch_1=0; ch_1 < NCHAR_MAX; ch_1++)
   {
   total_cchars+= chars_in_cconst[ch_1];
   if (in_bec_set(ch_1))
      total_src_cchars+= chars_in_cconst[ch_1];
   }

printf("total characters = %ld, characters in basic execution character set = %ld\n", total_cchars, total_src_cchars);
}

start_file("ccharc.d");
for (ch_1=0; ch_1 < NCHAR_MAX; ch_1++)
   {
   print_char(ch_1);
   printf(" %3d %7d\n", ch_1, chars_in_cconst[ch_1]);
   }
end_file("ccharc.d");

start_file("ccharlen.d");
for (ch_1=0; ch_1 < 8; ch_1++)
   {
   printf("%3d  %7d\n", ch_1, cconst_len[ch_1]);
   }
end_file("ccharlen.d");

printf("char-esc %d  string-esc %d : char-cons %d  str-lit %d\n",
		total_char_escapes, total_str_escapes,
		token_count[CHAR_CONST], token_count[STRING_CONST]);
printf("first char   char-escape   str-escape\n");
start_file("escseq.d");
for (ch_1=0; ch_1 < NCHAR_MAX; ch_1++)
   {
   if ((escape_seqs[0][ch_1] != 0) ||
       (escape_seqs[1][ch_1] != 0))
      {
      print_char(ch_1);
      printf("   %7d  %.2f  %7d  %.2f\n",
      		escape_seqs[0][ch_1],
		100.0*(escape_seqs[0][ch_1] / (double)total_char_escapes),
      		escape_seqs[1][ch_1],
		100.0*(escape_seqs[1][ch_1] / (double)total_str_escapes));
      }
   }
end_file("escseq.d");

start_file("charsimesc.d");
for (ch_1=0; ch_1 < NCHAR_MAX; ch_1++)
   if (escape_seqs[2][ch_1] != 0)
      {
      print_char(ch_1);
      printf("  %7d   %.2f\n", escape_seqs[2][ch_1],
		100.0*(escape_seqs[2][ch_1] / (double)total_char_escapes));
      }
end_file("charsimesc.d");

printf("Numeric escape values\n");
start_file("numesc.d");
for (ch_1=0; ch_1 < 256; ch_1++)
   if (escape_seqs[2][ch_1] != 0)
      {
      print_char(ch_1);
      printf("  %7d\n", escape_seqs[2][ch_1]);
      }
end_file("numesc.d");

start_file("exprng.d");
for (ch_1=0; ch_1 < 1000; ch_1++)
   if (exponent[ch_1] != 0)
      {
      printf("%4d %7d\n", ch_1-500, exponent[ch_1]);
      }
end_file("exprng.d");

start_file("whitespace.d");
for (ch_1=0; ch_1 < MAX_WHITESPACE+1; ch_1++)
   if (whitespace_count[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, whitespace_count[ch_1]);
      }
end_file("whitespace.d");

start_file("blocknest.d");
for (ch_1=0; ch_1 < MAX_BLOCK_NEST; ch_1++)
   if (block_nest[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, block_nest[ch_1]);
      }
end_file("blocknest.d");

start_file("physlinelen.d");
for (ch_1=0; ch_1 < MAX_LINE_LEN; ch_1++)
   if (line_len_count[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, line_len_count[ch_1]);
      }
end_file("physlinelen.d");

start_file("numnonwhitesp.d");
for (ch_1=0; ch_1 < MAX_LINE_LEN; ch_1++)
   if (nws_chars_on_line[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, nws_chars_on_line[ch_1]);
      }
end_file("numnonwhitesp.d");

printf("pp splices %d, non-pp splices %d\n", total_pp_splices,
						total_non_pp_splices);
start_file("splice.d");
for (ch_1=0; ch_1 < MAX_SPLICE_CNT; ch_1++)
   if (splice_count[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, splice_count[ch_1]);
      }
end_file("splice.d");

start_file("splicellen.d");
for (ch_1=0; ch_1 < MAX_LINE_LEN; ch_1++)
   if (splice_line_len_count[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, splice_line_len_count[ch_1]);
      }
end_file("splicellen.d");

start_file("stmtlendiff.d");
for (ch_1=0; ch_1 < 2*MAX_VISIBLE_LINE_LEN; ch_1++)
   {
   printf("%3d %7d\n", ch_1, line_len_diff[0][ch_1]);
   }
end_file("stmtlendiff.d");

start_file("lstmtlendiff.d");
for (ch_1=0; ch_1 < 2*MAX_VISIBLE_LINE_LEN; ch_1++)
   {
   printf("%3d %7d\n", ch_1, line_len_diff[1][ch_1]);
   }
end_file("lstmtlendiff.d");

start_file("sstmtlendiff.d");
for (ch_1=0; ch_1 < 2*MAX_VISIBLE_LINE_LEN; ch_1++)
   {
   printf("%3d %7d\n", ch_1, line_len_diff[2][ch_1]);
   }
end_file("sstmtlendiff.d");

start_file("indentdiff.d");
for (ch_1=0; ch_1 < 2*MAX_INDENT_LEN; ch_1++)
   {
   printf("%3d %7d\n", ch_1, line_indent_diff[ch_1]);
   }
end_file("indentdiff.d");

start_file("lineindentation.d");
for (ch_1=0; ch_1 < MAX_INDENT_LEN; ch_1++)
   {
   printf("%3d %7d\n", ch_1, line_indentation[ch_1]);
   }
end_file("lineindentation.d");

start_file("hashinden.d");
for (ch_1=0; ch_1 < MAX_INDENT_LEN; ch_1++)
   {
   printf("%3d %7d\n", ch_1, hash_indentation[ch_1]);
   }
end_file("hashinden.d");

start_file("firsttok.d");
for (ch_1=0; ch_1 < MAX_TOK; ch_1++)
   {
   if (first_tok[ch_1] != 0)
      {
      printf("%.9s  %7d\n", tokens[ch_1], first_tok[ch_1]);
      }
   }
end_file("firsttok.d");

start_file("lasttok.d");
for (ch_1=0; ch_1 < MAX_TOK; ch_1++)
   {
   if (last_tok[ch_1] != 0)
      {
      printf("%.9s  %7d\n", tokens[ch_1], last_tok[ch_1]);
      }
   }
end_file("lasttok.d");

print_op_lit(TOK_LOG_NOT, "toklnot.d");
print_op_lit(TOK_BIT_NOT, "bnotcons.d");
print_op_lit(TOK_ADD, "addcons.d");
print_op_lit(TOK_PLUS, "tokplus.d");
print_op_lit(TOK_MINUS, "minuscons.d");
print_op_lit(TOK_ARITH_NEG, "uminuscons.d");
print_op_lit(TOK_TIMES, "multcons.d");
print_op_lit(TOK_DIVIDE, "divcons.d");
print_op_lit(TOK_REMAINDER, "tokrem.d");
print_op_lit(TOK_EQUAL, "tokassign.d");
print_op_lit(TOK_EQ_EQUAL, "eqeqcons.d");
print_op_lit(TOK_EXC_EQUAL, "neqcons.d");
print_op_lit(TOK_LESS_THAN, "ltcons.d");
print_op_lit(TOK_LESS_EQUAL, "lecons.d");
print_op_lit(TOK_GR_EQUAL, "gecons.d");
print_op_lit(TOK_GREATER_THAN, "gtcons.d");
print_op_lit(TOK_LSHIFT, "lshiftcons.d");
print_op_lit(TOK_RSHIFT, "rshiftcons.d");
print_op_lit(TOK_BIT_AND, "bandcons.d");
print_op_lit(TOK_BIT_OR, "borcons.d");
print_op_lit(TOK_BIT_XOR, "tokbitxor.d");
print_op_lit(TOK_COMMA, "tokcomma.d");
print_op_lit(TOK_OPEN_RND, "tokopenrnd.d");
print_op_lit(TOK_OPEN_SQUARE, "tokopensqr.d");
print_op_lit(TOK_RETURN, "tokreturn.d");
print_op_lit(TOK_CASE, "tokcase.d");
print_op_lit(TOK_COLON, "tokcolon.d");

/*
 * Token and the most recent preceeding keyword.
 */
print_opkeyword_tok(TOK_LOG_NOT, "keylnot.d");
print_opkeyword_tok(TOK_BIT_NOT, "keybnot.d");
print_opkeyword_tok(TOK_ADD, "keyadd.d");
print_opkeyword_tok(TOK_PLUS, "keyplus.d");
print_opkeyword_tok(TOK_MINUS, "keyminus.d");
print_opkeyword_tok(TOK_ARITH_NEG, "keyaneg.d");
print_opkeyword_tok(TOK_TIMES, "keytimes.d");
print_opkeyword_tok(TOK_DIVIDE, "keydivide.d");
print_opkeyword_tok(TOK_REMAINDER, "keyrem.d");
print_opkeyword_tok(TOK_EQUAL, "keyassign.d");
print_opkeyword_tok(TOK_EQ_EQUAL, "keyequal.d");
print_opkeyword_tok(TOK_EXC_EQUAL, "keynequal.d");
print_opkeyword_tok(TOK_LESS_THAN, "keylt.d");
print_opkeyword_tok(TOK_LESS_EQUAL, "keyle.d");
print_opkeyword_tok(TOK_GR_EQUAL, "keyge.d");
print_opkeyword_tok(TOK_GREATER_THAN, "keygt.d");
print_opkeyword_tok(TOK_LSHIFT, "keylshift.d");
print_opkeyword_tok(TOK_RSHIFT, "keyrshift.d");
print_opkeyword_tok(TOK_BIT_AND, "keybitand.d");
print_opkeyword_tok(TOK_BIT_OR, "keybitor.d");
print_opkeyword_tok(TOK_BIT_XOR, "keybitxor.d");
print_opkeyword_tok(TOK_OPEN_RND, "keyopenrnd.d");
print_opkeyword_tok(TOK_OPEN_SQUARE, "keyopensqr.d");
print_opkeyword_tok(TOK_LOG_AND, "keylogand.d");
print_opkeyword_tok(TOK_LOG_OR, "keylogor.d");
print_opkeyword_tok(TOK_OPEN_CURL, "keyopencur.d");

start_file("idonline.d");
for (ch_1=0; ch_1 < MAX_TOKENS_PER_LINE; ch_1++)
   {
   printf("%3d  %7d\n", ch_1, idents_on_line[ch_1]);
   }
end_file("idonline.d");

start_file("tokonline.d");
for (ch_1=0; ch_1 < MAX_TOKENS_PER_LINE; ch_1++)
   {
   printf("%3d  %7d\n", ch_1, tokens_on_line[ch_1]);
   }
end_file("tokonline.d");

printf("Token sp/nl bigrams\n");
sp_tok_sp_bigrams(MAX_TOK, token_bigram[0]);
total_bigram_tokens=sp_tok_sp[0][TK_KEYWORD]+
                    sp_tok_sp[0][TK_IDENTIFIER]+
                    sp_tok_sp[0][TK_CONSTANT]+
                    sp_tok_sp[0][TK_STRING_LIT]+
                    sp_tok_sp[0][TK_PUNCTUATOR]+
                    sp_tok_sp[0][TK_HEADER_NAME]+
                    sp_tok_sp[0][TK_COMMENT];
total_bigram_width=sp_tok_sp[1][TK_KEYWORD]+
                   sp_tok_sp[1][TK_IDENTIFIER]+
                   sp_tok_sp[1][TK_CONSTANT]+
                   sp_tok_sp[1][TK_STRING_LIT]+
                   sp_tok_sp[1][TK_PUNCTUATOR]+
                   sp_tok_sp[1][TK_HEADER_NAME]+
                   sp_tok_sp[1][TK_COMMENT];
printf("token_type  %% of token kind   %% of all characters  space token   new-line token  token space   token new-line\n");
start_file("sptoksp.d");
print_sptoksp("punctuator occur %2.1f  width %2.1f  sp pun %2.1f  nl pun %2.1f  pun sp %2.1f  pun nl %2.1f\n", TK_PUNCTUATOR);
print_sptoksp("identifier occur %2.1f  width %2.1f  sp id %2.1f  nl id %2.1f  id sp %2.1f  id nl %2.1f\n", TK_IDENTIFIER);
print_sptoksp("constant occur %2.1f  width %2.1f  sp con %2.1f  nl con %2.1f  con sp %2.1f  con nl %2.1f\n", TK_CONSTANT);
print_sptoksp("keyword occur %2.1f  width %2.1f  sp kw %2.1f  nl kw %2.1f  kw sp %2.1f  kw nl %2.1f\n", TK_KEYWORD);
print_sptoksp("comment occur %2.1f  width %2.1f  sp com %2.1f  nl com %2.1f  com sp %2.1f  com nl %2.1f\n", TK_COMMENT);
print_sptoksp("string-literal occur %2.1f  width %2.1f  sp str %2.1f  nl str %2.1f  str sp %2.1f  str nl %2.1f\n", TK_STRING_LIT);
print_sptoksp("pp-directive occur %2.1f  width %2.1f  sp com %2.1f  nl com %2.1f  com sp %2.1f  com nl %2.1f\n", TK_PP_DIRECT);
print_sptoksp("header-name occur %2.1f  width %2.1f  sp hdr %2.1f  nl hdr %2.1f  hdr sp %2.1f  hdr nl %2.1f\n", TK_HEADER_NAME);
end_file("sptoksp.d");
#if 000
printf("kw %d  iw %d  cw %d  sw %d  pw %d  hw %d  cw %d\n",
	   sp_tok_sp[0][TK_KEYWORD], sp_tok_sp[0][TK_IDENTIFIER],
           sp_tok_sp[0][TK_CONSTANT], sp_tok_sp[0][TK_STRING_LIT],
           sp_tok_sp[0][TK_PUNCTUATOR], sp_tok_sp[0][TK_HEADER_NAME],
           sp_tok_sp[0][TK_COMMENT]);
printf("kw %d  iw %d  cw %d  sw %d  pw %d  hw %d  cw %d\n",
	   sp_tok_sp[2][TK_KEYWORD], sp_tok_sp[2][TK_IDENTIFIER],
           sp_tok_sp[2][TK_CONSTANT], sp_tok_sp[2][TK_STRING_LIT],
           sp_tok_sp[2][TK_PUNCTUATOR], sp_tok_sp[2][TK_HEADER_NAME],
           sp_tok_sp[2][TK_COMMENT]);
printf("kw %d  iw %d  cw %d  sw %d  pw %d  hw %d  cw %d\n",
	   sp_tok_sp[3][TK_KEYWORD], sp_tok_sp[3][TK_IDENTIFIER],
           sp_tok_sp[3][TK_CONSTANT], sp_tok_sp[3][TK_STRING_LIT],
           sp_tok_sp[3][TK_PUNCTUATOR], sp_tok_sp[3][TK_HEADER_NAME],
           sp_tok_sp[3][TK_COMMENT]);
#endif

/*
 * Counts of type specifier sequences (which will have been
 * shifted-in in the order they were encountered, so the read
 * out needs to start with the most significant bits).
 */
start_file("num_type_specs.d");
for (ch_1=0; ch_1 < MAX_TYPE_SPECS; ch_1++)
   if (num_type_specs[ch_1] != 0)
      {
      ch_3=ch_1;
      ch_2=sizeof(ch_1)*CHAR_BIT;
      while (ch_2 != 0)
         {
	 printf("%s ", TS_str[(ch_3 >> (ch_2-4)) & 0x0f]);
	 ch_2-=4;
	 }
      printf("%7d\n", num_type_specs[ch_1]);
      }
end_file("num_type_specs.d");
start_file("h_ifdepth.d");
for (ch_1=0; ch_1 < MAX_PP_IF_DEPTH; ch_1++)
   if (pp_if_depth[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, pp_if_depth[ch_1]);
      }
end_file("h_ifdepth.d");

start_file("h_if_line_cnt.d");
for (ch_1=0; ch_1 < MAX_PP_IF_LINES; ch_1++)
   if (pp_if_line_cnt[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, pp_if_line_cnt[ch_1]);
      }
end_file("h_if_line_cnt.d");

start_file("h_direct_cnt.d");
for (ch_1=0; ch_1 < MAX_PP_DIRECT_CNT; ch_1++)
   if (pp_direct_cnt[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, pp_direct_cnt[ch_1]);
      }
end_file("h_direct_cnt.d");

start_file("caseswitch.d");
for (ch_1=1; ch_1 <= total_switches; ch_1++)
   cases_per_switch[switch_info[ch_1].case_count]++;
for (ch_1=0; ch_1 < MAX_CASES_PER_SWITCH; ch_1++)
   if (cases_per_switch[ch_1] != 0)
      {
      printf("%4d %7d\n", ch_1, cases_per_switch[ch_1]);
      }
end_file("caseswitch.d");

start_file("casestmt.d");
for (ch_1=0; ch_1 < MAX_CASES_PER_STMT; ch_1++)
   if (cases_per_stmt[ch_1] != 0)
      {
      printf("%4d %7d\n", ch_1, cases_per_stmt[ch_1]);
      }
end_file("casestmt.d");

est_switch_bounds=0;
start_file("case_density.d");
for (ch_1=1; ch_1 <= total_switches; ch_1++)
   if ((switch_info[ch_1].case_count != 0) &&
       (switch_info[ch_1].lowest_case != LONG_MAX) &&
       (switch_info[ch_1].case_count <=
          (1+switch_info[ch_1].highest_case-switch_info[ch_1].lowest_case)))
      {
      est_switch_bounds++;
      case_density[100*switch_info[ch_1].case_count /
            (1+switch_info[ch_1].highest_case-switch_info[ch_1].lowest_case)]++;
      }
for (ch_1=0; ch_1 < 101; ch_1++)
   printf("%4d %3d\n", ch_1, case_density[ch_1]);
end_file("case_density.d");

printf("total switches=%d, estimates bounds=%d\n",
                                 total_switches, est_switch_bounds);

start_file("case_prev_tok.d");
for (ch_1=0; ch_1 <= MAX_TOK; ch_1++)
   {
   if (keyword_bigram[ch_1][TOK_CASE] != 0)
      printf("%12s  %7d  %.2f  %.2f\n",
		tokens[ch_1], keyword_bigram[ch_1][TOK_CASE],
		100.0*(keyword_bigram[ch_1][TOK_CASE]/(double)token_count[TOK_CASE]),
		100.0*(keyword_bigram[ch_1][TOK_CASE]/(double)token_count[ch_1]));
   }
end_file("case_prev_tok.d");

start_file("cl_curl_prev_tok.d");
for (ch_1=0; ch_1 <= MAX_TOK; ch_1++)
   {
   if (keyword_bigram[ch_1][TOK_CL_CURL] != 0)
      printf("%12s  %7d  %.2f  %.2f\n",
		tokens[ch_1], keyword_bigram[ch_1][TOK_CL_CURL],
		100.0*(keyword_bigram[ch_1][TOK_CL_CURL]/(double)token_count[TOK_CL_CURL]),
		100.0*(keyword_bigram[ch_1][TOK_CL_CURL]/(double)token_count[ch_1]));
   }
end_file("cl_curl_prev_tok.d");

start_file("src_lines.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_files != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_files);
      }
end_file("src_lines.d");

start_file("rellineinclude.d");
for (ch_1=0; ch_1 <= 100; ch_1++)
   if (inc_rel_pos[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, inc_rel_pos[ch_1]);
      }
end_file("rellineinclude.d");
start_file("rellinedefine.d");
for (ch_1=0; ch_1 <= 100; ch_1++)
   if (def_rel_pos[ch_1] != 0)
      {
      printf("%3d %7d\n", ch_1, def_rel_pos[ch_1]);
      }
end_file("rellinedefine.d");
start_file("lineinclude.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_include[2] != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_include[2]);
      }
end_file("lineinclude.d");

start_file("linedefine.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_define[2] != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_define[2]);
      }
end_file("linedefine.d");

start_file("line_pp_if.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_pp_if != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_pp_if);
      }
end_file("line_pp_if.d");

start_file("line_pp_ifdef.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_pp_ifdef != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_pp_ifdef);
      }
end_file("line_pp_ifdef.d");

start_file("line_pp_else.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_pp_else != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_pp_else);
      }
end_file("line_pp_else.d");

start_file("line_pp_line.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_pp_line != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_pp_line);
      }
end_file("line_pp_line.d");

start_file("line_pp_error.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_pp_error != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_pp_error);
      }
end_file("line_pp_error.d");

start_file("line_pp_pragma.d");
for (ch_1=0; ch_1 < MAX_SRC_LINES; ch_1++)
   if (src_line_info[ch_1].num_pp_pragma != 0)
      {
      printf("%3d %7d\n", ch_1, src_line_info[ch_1].num_pp_pragma);
      }
end_file("line_pp_pragma.d");

start_file("bitfieldwidth.d");
for (ch_1=0; ch_1 < MAX_BIT_WIDTH; ch_1++)
   if (bit_widths[ch_1]!= 0)
      {
      printf("%3d %7d\n", ch_1, bit_widths[ch_1]);
      }
end_file("bitfieldwidth.d");
}

void print_cpp(void)
{
if ((total_class_templ[0] != 0) || (total_class_templ[1] != 0) ||
    (total_coloncolon[0] != 0) || (total_coloncolon[1] != 0))
   {
   printf("> %s %d %d %d %d\n", cur_filename,
                                total_class_templ[0], total_class_templ[1],
                                total_coloncolon[0], total_coloncolon[1]);
   }
}

