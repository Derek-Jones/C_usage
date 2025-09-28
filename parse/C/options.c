                        /* options.c, 19 Aug 12 */

#include <ctype.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "errors.h"
#include "utils.h"
#include "arccomp.h"
#include "singlefile.h"
#include "chkfiles.h"
#include "parser.h"
#include "stgrep.h"
#include "print.h"
#include "count.h"
#include "lex.h"
#include "dispexp.h"
#include "parsefile.h"
#include "options.h"


#define TRACE_FSPLIT    FALSE
#define TRACE_GETPATH   FALSE	/* very useful at start of a port! */

char minus_plus[2] = {'-', '+'};

#if defined(FULL_POSIX) || defined(SUN_UNIX)
struct stat ISexec;
#endif


/*	Given a relative path, search the PATH environment
 *      variable to find the absolute path
 *	NOTE: if the host sets argv[0] to the absolute path, then either:
 *		that host is MS-DOS and we check relpath first
 *		or that host is NOT unix so you probably need
 *              to modify this routine anyway!
 */
char	*getpath(char * relpath)
{
char	*pathlist;
char	*copy_of_paths;
char	*fullpath;
size_t	curpath = 0,
	nextpath;
FILE	*fp;
unsigned long	copy_path_len;

#if	TRACE_GETPATH
printf("getpath(%s)\n", relpath);
#endif

#ifdef  MS_DOS
/* MS-DOS searches current directory first */
if ((fp = fopen(relpath, "r")) != NULL)
   {
   fclose(fp);
   if (ISEXECUTABLE(relpath))
      {
#if     TRACE_GETPATH
printf("%s...exists...isexec\n", relpath);
#endif
      return relpath;
      }
   }
#endif

/* If the path which is passed contains a directory separator
 * character then the path name is either absolute, or
 * relative to the current directory
 */
if (strstr(relpath, directory_separator) != NULL)
   {
   if ((fp = fopen(relpath, "r")) != NULL)
      {
      fclose(fp);
      if (ISEXECUTABLE(relpath))
	 {
#if     TRACE_GETPATH
   printf("%s...exists...isexec\n", relpath);
#endif
         return relpath;
         }
      }
   return (char *)NULL;		/* ?? Can this be executed ?? */
   }

pathlist = GETVAR(PATHVAR);
if (pathlist == NULL)
   pathlist = "";		/* NOTEXEC under unix - cannot unset PATH */

#if	TRACE_GETPATH
printf("pathlist=\"%s\"\n", pathlist);
#endif

fullpath = (char *)get_heap(MAX_FILENAME_LEN+1);

/* we can't modify the environment string! */
copy_path_len = strlen(pathlist) + strlen(path_separator) + 1;
copy_of_paths = (char*)get_heap(copy_path_len);

strcpy(copy_of_paths, pathlist);
strcat(copy_of_paths, path_separator);

while (copy_of_paths[curpath]) /* while more paths to search... */
   {
   for (nextpath = curpath; copy_of_paths[nextpath]; ++nextpath)
     /* look for next path separator... */
      if (strncmp(&copy_of_paths[nextpath], path_separator,
                                              strlen(path_separator)) == 0)
         {
         copy_of_paths[nextpath] = '\0';
         /* having chopped string at that point, break out */
         break;
         }
   /* construct full pathname to test */
   strcpy(fullpath, &copy_of_paths[curpath]);
   strcat(fullpath, directory_separator);
   strcat(fullpath, relpath);
#if	TRACE_GETPATH
printf("trying %s...", fullpath);
#endif
   /* attempt to open file: */
   if ((fp = fopen(fullpath, "r")) != NULL)
      {
      /* success: close the file and check it is executable: */
      fclose(fp);
#if	TRACE_GETPATH
printf("exists...");
#endif
      if (ISEXECUTABLE(fullpath))
         {
         /* success: return the path found */
#if	TRACE_GETPATH
printf("exec\n");
#endif
         return fullpath;
         }
      }
#if	TRACE_GETPATH
printf("\n");
#endif
   /* keep searching paths... */
   curpath = nextpath + strlen(path_separator);
   }
#if     TRACE_GETPATH
printf("can't find %s\n", relpath);
#endif
/* no path matches: return NULL to indicate failure */
return (char *)NULL;
}


static char * get_exe_path(char * argv_0)
/*
 * Find the path that the program was run from
 */
{
int path_len;
char * full_exe_path;
#if defined(MS_DOS) || defined(CYGWIN)
char *exe_name;
#endif

if (argv_0 == (char *)NULL)
   return NULL;            /* NOT Really EXEC */

full_exe_path = getpath(argv_0);
 
#if defined(MS_DOS) || defined(CYGWIN)
if (full_exe_path == NULL)
   {
   exe_name=get_heap(strlen(argv_0)+1+4);
   strcpy(exe_name, argv_0);
#if defined(MS_DOS)
   strcat(exe_name, ".EXE");
#else
   strcat(exe_name, ".exe");
#endif
   full_exe_path=getpath(exe_name);
   }
#endif

if (full_exe_path == NULL)
   return NULL;

path_len=strlen(full_exe_path);
while (path_len > 0)
   {
   if (strncmp(full_exe_path+path_len-DSEP_LEN,
                                     directory_separator, DSEP_LEN) == 0)
      {
      full_exe_path[path_len]=NULL_CHAR;
      break;
      }
   else
      path_len--;
   }

// The POSIX standard requires that an array of appropriate size
// be passed.  It is making use of a common extension to pass NULL
// and expect the system to allocate the storage.
if (path_len == 0)
   full_exe_path=getcwd(NULL, 0);

return full_exe_path;
}


long get_arg_val(char *arg_str, int max_arg_val)
{
unsigned long arg_val;
char *end_ptr;

errno=0;
arg_val = strtoul(arg_str, &end_ptr, 0);
if ((errno != 0) || ((arg_val == 0) && (end_ptr == arg_str)))
   {
   print_warning("Argument %s cannot be converted to an integer value\n",
							arg_str);
   arg_val=max_arg_val;
   }

if (arg_val > (unsigned long)max_arg_val)
   {
   print_warning("Argument value (%lu) exceeds maximum allowed (%d)\n",
							arg_val, max_arg_val);
   arg_val=max_arg_val;
   }

return arg_val;
}


BOOL arg_is_plus(char *arg_str)
{
return arg_str[strlen(arg_str)-1] != '-';
}


void trace_options(int argc, char *argv[])
{
int cur_arg;

for (cur_arg=1; cur_arg < argc; cur_arg++)
   {
   if (strncmp(argv[cur_arg], "-trace", 4) == 0)
      {
      cur_arg++;
      if (cur_arg == argc)
	 break;
      if (strncmp(argv[cur_arg], "input", 3) == 0)
	 do_trace_input=arg_is_plus(argv[cur_arg]);
      else if (strncmp(argv[cur_arg], "progress", 3) == 0)
	 do_trace_progress=arg_is_plus(argv[cur_arg]);
      else
	 print_warning("Unknown option %s\n", argv[cur_arg]);
      }
   }
}


void list_options(int argc, char *argv[])
{
int cur_arg;

for (cur_arg=1; cur_arg < argc; cur_arg++)
   {
   if ((strcmp(argv[cur_arg], "-?") == 0) ||
       (strcmp(argv[cur_arg], "-help") == 0) ||
       (strcmp(argv[cur_arg], "-v") == 0) ||
       (strcmp(argv[cur_arg], "-V") == 0))
      {
      printf("Canal version 0.1.0\n");
      printf("Options, first four characters significant (default values in parenthesis):\n");
      printf("    <file name>\n");
      printf("    <directory name>\n");
      printf("    -error%c\n",
					minus_plus[print_parse_error]);
      printf("    -help print version and options\n");
      printf("    -opcnt%c\n",
					minus_plus[do_cnt_expr]);
      printf("    -rulecount%c\n",
					minus_plus[disp_rule_count]);
      printf("    -rulereduce%c\n",
					minus_plus[disp_rule_reduce]);
      printf("    -trace input%c | progress%c\n",
					minus_plus[do_trace_input],
					minus_plus[do_trace_progress]);
      printf("    -v, -V print version and options\n");
      printf("    -wildcard <shell-wildcard>\n");
      exit(0);
      }
   }
}


void handle_options(int argc, char *argv[])
{
int cur_arg;
int cur_arg_file_len = 0;
int cur_arg_pattern_len = 0;

for (cur_arg=1; cur_arg < argc; cur_arg++)
   {
   if ((strcmp(argv[cur_arg], "?") == 0) ||
       (strcmp(argv[cur_arg], "-help") == 0) ||
       (strcmp(argv[cur_arg], "-v") == 0) ||
       (strcmp(argv[cur_arg], "-V") == 0))
      {
      // handled elsewhere
      }

   if (strncmp(argv[cur_arg], "-yydebug", 4) == 0)
      yydebug=1;
   else if (strncmp(argv[cur_arg], "-grep", 4) == 0)
      {
      do_grep=1;
      get_grep_pat(argv[cur_arg+1]);
      cur_arg++;
      }
   else if (strncmp(argv[cur_arg], "-block", 4) == 0)
      print_block=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "-dispexpr", 4) == 0)
      init_disp_expr();
   else if (strncmp(argv[cur_arg], "-error", 4) == 0)
      print_parse_error=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "-opcnt", 4) == 0)
      {
      do_cnt_expr=TRUE;
      build_parse_tree=TRUE;
      }
   else if (strncmp(argv[cur_arg], "-ifexpr", 4) == 0)
      do_if_expr=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "-stmt", 4) == 0)
      do_print_stmt=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "prepro", 4) == 0)
      print_prepro=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "-results", 4) == 0)
      disp_results=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "-rulecount", 5) == 0)
      disp_rule_count=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "-rulereduce", 5) == 0)
      disp_rule_reduce=arg_is_plus(argv[cur_arg]);
   else if (strncmp(argv[cur_arg], "-trace", 4) == 0) // Handled in earlier loop
      {
      cur_arg++;
      }
   else if (strncmp(argv[cur_arg], "-wildcard", 4) == 0)
      {
      cur_arg++;
      if (cur_arg == argc)
	 break;
      if (save_arg_info(arg_patterns, &cur_arg_pattern_len, MAX_ARG_PATTERN_LEN,
			argv[cur_arg], "Size of file wildcard arguments exceeded at %s\n"))
	 num_arg_patterns++;
      }
   else
      {
      // treat as probably a file or directory name
      if (save_arg_info(arg_files, &cur_arg_file_len, MAX_ARG_FILE_LEN,
				argv[cur_arg], "Size of file arguments exceeded at %s\n"))
	 num_arg_files++;
      }
   } 
}


void init(int argc, char *argv[])
{
trace_options(argc, argv);
init_sing_file();
handle_options(argc, argv);
list_options(argc, argv);
init_arccomp();
init_count();
init_lexer();
init_parsefile();
}

