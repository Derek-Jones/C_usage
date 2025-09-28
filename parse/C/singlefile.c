                      /* singlefile.c, 23 Feb 12 */

/*
 * Process the numeric literals in one file.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
 
#include "global.h"
#if HAVE_FNMATCH_H
#include <fnmatch.h>
#endif
#include "errors.h"
#include "isprop.h"
#include "utils.h"
#include "arccomp.h"
#include "parsefile.h"
#include "singlefile.h"


#define MAX_FILE_BUFF_SIZE (5*1024)
#define MAX_FILE_SUFF_SIZE 200
#define MAX_FILE_SUFF_LEN 6

BOOL do_print_location = TRUE,
     have_printed_filename;
char *cur_filename;
int file_bytes_read;

static int num_file_suff;
static char file_suff_pat[MAX_FILE_SUFF_SIZE];


static char * read_file_buff(void)
{
static char file_buff[MAX_FILE_BUFF_SIZE];

file_bytes_read = fread(file_buff, 1, sizeof(file_buff), stdin);

// printf("bytes read %d\n", file_bytes_read);

return file_buff;
}


void analyse_file(get_buff_func_type get_buff_func,
		  char *filename)
{
parse_file(get_buff_func, filename);
}


void process_file(CHAR *filename)
{
if (filename == NULL)
   cur_filename="stdin";
else
   {
   cur_filename=filename;
// Martin Moene reported problems with close/fopen under WinGW
// but that the following works.
   if (freopen(filename, "r", stdin) == NULL)
      {
      print_warning("freopen failed (errno=%d)\n", errno);
      return;
      }
   }
if (is_arc_comp(cur_filename))
   handle_arc_comp(cur_filename);
else
   analyse_file(read_file_buff, cur_filename);
}


static void add_file_suffix(char *suff_str, int *cur_file_suff_len)
{
if (save_arg_info(file_suff_pat, cur_file_suff_len, MAX_FILE_SUFF_SIZE,
                suff_str, "Size of file suffixes exceeded\n"))
   num_file_suff++;
}


void init_sing_file(void)
{
int dummy_file_suff_len = 0;

add_file_suffix("asp", &dummy_file_suff_len);
add_file_suffix("aspx", &dummy_file_suff_len);
add_file_suffix("gif", &dummy_file_suff_len);
add_file_suffix("htm", &dummy_file_suff_len);
add_file_suffix("html", &dummy_file_suff_len);
add_file_suffix("jpeg", &dummy_file_suff_len);
add_file_suffix("jpg", &dummy_file_suff_len);
add_file_suffix("jsp", &dummy_file_suff_len);
add_file_suffix("mp3", &dummy_file_suff_len);
add_file_suffix("pdf", &dummy_file_suff_len);
add_file_suffix("php", &dummy_file_suff_len);
add_file_suffix("png", &dummy_file_suff_len);
add_file_suffix("shtml", &dummy_file_suff_len);
add_file_suffix("stm", &dummy_file_suff_len);
add_file_suffix("svg", &dummy_file_suff_len);
add_file_suffix("txt", &dummy_file_suff_len);
add_file_suffix("xls", &dummy_file_suff_len);
add_file_suffix("xml", &dummy_file_suff_len);
}

