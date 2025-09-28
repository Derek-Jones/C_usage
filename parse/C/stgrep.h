                       /* stgrep.h, 28 May 06 */


extern BOOL do_grep;
extern BYTE match_pattern[];
extern BYTE mpattern_len;

extern void grep_expr(int expr_context, tree_node_ptr expr_ptr);
extern void get_grep_pat(char *g_pat);

