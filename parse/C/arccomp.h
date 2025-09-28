                           /* arccomp.h, 29 Apr 10 */

#define MAX_AC_PATTERN_LEN 2000


extern BOOL started_arccomp_file;
extern char *cur_arccomp_name;

extern BOOL is_arc_comp(char *filename);
extern void handle_arc_comp(char *filename);
extern void init_arccomp(void);

