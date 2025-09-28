                         /* chkfiles.c, 17 Feb 12 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
 
#include "global.h"
#if HAVE_FNMATCH_H
#include <fnmatch.h>
#endif
#include "errors.h"
#include "isprop.h"
#include "arccomp.h"
#include "singlefile.h"
#include "chkfiles.h"


int num_arg_files = 0;
int num_arg_patterns = 0;
int other_toks;
char arg_files[MAX_ARG_FILE_LEN];
char arg_patterns[MAX_ARG_PATTERN_LEN];



BOOL match_file_pattern(const char *filename)
{
#if HAVE_FNMATCH_H
int pnum;
char *cur_arg_patterns = arg_patterns;

if (num_arg_patterns == 0)
   return TRUE;

for (pnum=0; pnum < num_arg_patterns; pnum++)
   {
   if (pnum != 0)
      cur_arg_patterns+=1+strlen(cur_arg_patterns);
// printf("%s %d\n", filename, fnmatch(cur_arg_patterns, filename, 0));
   if (fnmatch(cur_arg_patterns, filename, 0) == 0)
      return TRUE;
   }
return FALSE;
#else
return TRUE;
#endif
}


void walk_dir(const char *dir)
{
struct dirent *entry;
DIR *cur_dir_ptr;
struct stat fs;
char abs_path[MAX_FILENAME_LEN];

if (!(cur_dir_ptr = opendir(dir)))
   return;
while ((entry = readdir(cur_dir_ptr)))
   {
// printf("entry %s\n", entry->d_name);
   if ((strcmp(".", entry->d_name) == 0) ||
       (strcmp("..", entry->d_name) == 0))
       continue;
   if (stat(entry->d_name, &fs) < 0)
       continue;
   if (S_ISDIR(fs.st_mode))
      {
      if (getcwd(abs_path, MAX_FILENAME_LEN) == NULL)
	 continue;
      if (do_trace_progress)
	 printf("%s/%s\n", abs_path, entry->d_name);
      if (chdir(entry->d_name) < 0)
	 return;
      walk_dir(".");
      if (do_trace_progress)
	 printf("%s\n", abs_path);
      if (chdir(abs_path) < 0)
	 return;
      }
    else
      {
      if (is_arc_comp(entry->d_name) ||
	  match_file_pattern(entry->d_name))
         process_file(entry->d_name);
      }
    }
closedir(cur_dir_ptr);
}


void chk_number(const char *num_str)
{
}


void process_arg_files(void)
{
struct stat fs;
char *dir_name;
int anum;

if (num_arg_files == 0)
   process_file(NULL); // Input assumed to come from stdin
else
   {
   // Loop over names given as options
   dir_name=arg_files;
   for (anum=0; anum < num_arg_files; anum++)
      {
      if (anum != 0)
         dir_name+=1+strlen(dir_name);
      if (stat(dir_name, &fs) < 0)
         {
         if (is_number(dir_name))
	    chk_number(dir_name);
         else
	    print_warning("Cannot stat %s\n", dir_name);
         return;
         }
      if (S_ISDIR(fs.st_mode))
         {
         if (chdir(dir_name) < 0)
	    print_warning("Unable to change directory to %s\n", dir_name);
         else
	    walk_dir(".");
         }
      else
         process_file(dir_name);
      }
   }
}

