                     /* chkfiles.h, 28 Apr 10 */


#define MAX_ARG_FILE_LEN 5000
#define MAX_ARG_PATTERN_LEN 5000

extern BOOL mk_ndb_all;
extern CHAR *dir_ptr;
extern CHAR *file_pattern;
extern char *cur_filename;
extern int num_arg_files;
extern int num_arg_patterns;
extern char arg_files[MAX_ARG_FILE_LEN];
extern char arg_patterns[MAX_ARG_PATTERN_LEN];

extern BOOL match_file_pattern(const char *filename);
extern void process_arg_files(void);

