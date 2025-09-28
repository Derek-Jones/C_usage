                       /* parsefile.h, 20 Aug 12 */

extern BOOL do_print_stmt,
     print_parse_error,
     print_prepro,
     disp_rule_reduce,
     seen_term_tok,
     have_pushed_tok,
     in_dead_code,
     in_for_struct
     ;

extern int rule_cnt[];

extern void parse_file(get_buff_func_type get_buff_func,
		       char *filename);
extern void init_parsefile(void);

