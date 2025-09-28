                               /* utils.c, 28 Apr 10 */

#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "errors.h"
#include "utils.h"


void * get_heap(size_t mem_size)
{
void * mem_ptr = malloc(mem_size);

if (mem_ptr == NULL)
   print_error("Unable to allocate %d bytes of storage\n", mem_size);

return mem_ptr;
}


BOOL save_arg_info(char *arg_buf,
		   int *cur_arg_len,
		   int max_num_args,
		   char *arg_info,
		   char *err_msg)
{
size_t arg_info_len = strlen(arg_info);

if(*cur_arg_len+1+arg_info_len < max_num_args)
   {
   memcpy(arg_buf+*cur_arg_len, arg_info, 1+arg_info_len);
   *cur_arg_len+=1+arg_info_len;
   return TRUE;
   }
print_warning(err_msg, arg_info);
return FALSE;
}

