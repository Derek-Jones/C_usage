                      /* lexer.c, 17 Sep 07 */

/*
 * This is a hand written lexer for C.  It is #include'ed
 * by ngram, a tool for counting various C constructs.
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
 * A lexer for the C language
 *
 * 17 Sep 07 Added optional support for ::
 * 19 Jul 04 Initial release
 */

int 
    hash_indentation[MAX_INDENT_LEN],
    line_indentation[MAX_INDENT_LEN],
    line_indent_diff[2*MAX_INDENT_LEN],
    whitespace_count[MAX_WHITESPACE+1]
			    ;

void get_token(void)
{
int num_whitespace;
char seen_newline;

last_was_log_newline=FALSE;
cur_tok=TOK_EOF;

RESTART:;

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
	       lex_float(1, 0);
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
	          /*
		   * TODO
		   * anything???
		   */
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
	       int start_all_char_count = total_phys_chars;
	       
	       if (print_pp_direct)
		  printf("< ");
	       do_cur_ch();
	       while ((cur_ch != '>') && !feof(stdin))
	          {
		  if (print_pp_direct)
		     printf("%c", cur_ch);
		  do_cur_ch();
		  }
	       if (print_pp_direct)
		  printf("\n");
	       do_cur_ch();
	       output_token(HEADER_NAME , total_phys_chars-start_all_char_count);
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
	       count_digraph(TOK_OPEN_SQUARE);
	       do_cur_ch();
	       }
	    else if (cur_ch == '%')
	       {
	       output_token(TOK_OPEN_CURL, 3);
	       count_digraph(TOK_OPEN_CURL);
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
	       count_digraph(TOK_CL_SQUARE);
	       do_cur_ch();
	       }
	    else
               if (chk_cpp && (cur_ch == ':'))
	          output_token(TOK_COLONCOLON, 2);
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
	       /*
	        * bitwise & is not only more common that
		* unary &, but it is the simpler case to
		* handle in conv_tok.
	        */
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
	       count_digraph(TOK_CL_CURL);
	       do_cur_ch();
	       }
	    else if (cur_ch == ':')
	       {
	       do_cur_ch();
	       if (cur_ch == '%')
	          {
	          do_cur_ch();
	          if (cur_ch == ':')
	             {
		     output_token(HASH_HASH, 4);
	             count_digraph(HASH_HASH);
	             }
	          else
	             ;
	          }
	       else
	          {
		  output_token(HASH, 2);
	          count_digraph(HASH);
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
	          if ((cur_ch == '(') || (cur_ch == ')') ||
	              (cur_ch == '<') || (cur_ch == '>') ||
	              (cur_ch == '/') || (cur_ch == '!') ||
	              (cur_ch == '-') || (cur_ch == '=') ||
	              (cur_ch == '\''))
		     {
		     do_cur_ch();
		     total_trigraphs++;
		     }
	          /*
		   * TODO Not wholely accurate, but good enough
		   */
		  seen_question_op=TRUE;
		  output_token(TOK_QUESTION, 1);
		  }
	       else
	          {
		  seen_question_op=TRUE;
		  output_token(TOK_QUESTION, 1);
		  }
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
	       seen_question_op=FALSE;
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
	       do_cur_ch();
	       break;

   case '}':
	       output_token(TOK_CL_CURL, 1);
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
	       get_cur_filename();
	       end_of_file();
               break;
   
   case '\\':
	       last_tok_splice=TRUE;
	       do_cur_ch();
	       break;
   
   default:
	    /*
	     * We can get here because of vertical white space and
	     * 'other' tokens.  On the whole it is because of space
	     * characters.
	     */
	    seen_newline=FALSE;
	    /*
	     * Count whitespace between tokens, but not
	     * after newline, ie not indentation whitespace
	     */
	    num_whitespace=0;
	    last_was_whitespace=FALSE;
	    /*
	     * Assume \r is followed by a \n,  ie a DOS eoln marker
	     */
	    if (cur_ch == '\r')
	       do_cur_ch();
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
	       output_space();
	       }
	    do_cur_ch();
	    while (isspace(cur_ch) && !feof(stdin))
	       {
	       if (cur_ch == '\r')
	          ; /* handle carriage return line feed style of EOLN */
	       else if (cur_ch == '\n')
		  {
	          output_token(TOK_NEW_LINE, 1);
	          seen_newline=TRUE;
		  last_was_whitespace=FALSE;
		  num_whitespace=0;
		  do_end_of_line();
		  }
	       else
	          {
		  if (cur_ch == '\t')
		     num_whitespace+=SPACES_IN_TAB;
		  else
		     num_whitespace++;
		  last_was_whitespace=TRUE;
		  }
	       do_cur_ch();
	       }

	    /* Indentation only occurs after a newline :-) */
	    if (seen_newline)
	       {
	       if (num_whitespace < MAX_INDENT_LEN)
	          {
		  if (cur_ch == '#')
		     hash_indentation[num_whitespace]++;
		  line_indentation[num_whitespace]++;
		  line_indent_diff[MAX_INDENT_LEN+num_whitespace-
						     prev_indentation]++;
		  }
	       cur_indentation=num_whitespace;
	       }
	     /* Otherwise it is whitespace between tokens */
	     else if (num_whitespace < MAX_WHITESPACE)
	       {
	       whitespace_count[num_whitespace]++;
	       }
	    break;
   }
if (((cur_tok == TOK_EOF) || (cur_tok == TOK_NEW_LINE)) &&
    !feof(stdin))
   goto RESTART;
}

