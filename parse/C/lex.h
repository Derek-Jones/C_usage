                         /* lex.h, 20 Aug 12 */

#define MAX_TOK_LEN 15

extern BOOL last_was_newline,
     last_was_log_newline,
     last_was_whitespace,
     in_pp_directive,
     got_token,
     in_h_if,
     just_seen_hash,
     lit_is_hex,
     print_block;

extern int
    next_token,
    first_intdigit[11],
    first_fltdigit[11],
    first_hexdigit[16],
    int_suffix[13],
    exp_uses_e, exp_uses_E,
    flt_suffix[3],
    cconst_len[MAX_CCONST_LEN],
    hex_pow_count[32],
    cur_block_nest,
    cur_line_len,
    cur_src_line_cnt,
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

extern LONGEST_UINT lit_valu;

extern char ident_str[IDENT_SAVE_LEN];
extern char *tokens[MAX_TOK+1];

extern void print_input_buf(void);

extern void next_ch(void);
extern int get_token(void);
extern void init_lex_new_file(get_buff_func_type get_buff_func);
extern void init_lexer(void);

