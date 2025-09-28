                            /* utils.h, 28 Apr 10 */

extern void * get_heap(size_t mem_size);
extern BOOL save_arg_info(char *arg_buf,
			  int *cur_arg_len,
			  int max_num_args,
			  char *arg_info,
			  char *err_msg);

