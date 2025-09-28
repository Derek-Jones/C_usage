                   /* singlefile.h, 23 Feb 12 */


extern int file_bytes_read;
extern char *cur_filename;

extern void print_progress(void);
extern void analyse_file(get_buff_func_type get_buff_func,
			 char *filename);
extern void process_file(char *filename);
extern void init_sing_file(void);

