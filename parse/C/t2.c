
void get_next_token(void)
{
if (seen_term_tok)
   cur_token=TOK_EOF;
else
   {
   if (have_pushed_tok)
      {
      have_pushed_tok=FALSE;
      cur_token=pushed_back_tok;
      }
   else
      {
      if (last_was_log_newline)
         while (next_token == HASH)
            do_pp_directive();
      cur_token=next_token;
      get_token();
      }
   }
if (cur_token == TOK_IDENTIFIER)
   push_ident(ident_str);
else if (cur_token == TOK_LITERAL)
   push_number(lit_valu);
else if (cur_token == TOK_STRING_LIT)
   push_string('"');
/*
else
   push_float(1.0);
*/
tok_seen_ind++;
if (tok_seen_ind == TOK_SEEN_BUF_LEN)
   tok_seen_ind=0;
token_seen_buf[tok_seen_ind]=cur_token;
}

