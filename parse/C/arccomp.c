                         /* arccomp.c, 12 Feb 12 */

#include "global.h"

#if HAVE_ARCHIVE_H
#include <archive.h>
#include <archive_entry.h>
#endif
#include <stdio.h>
#include <string.h>
 
#if HAVE_FNMATCH_H
#include <fnmatch.h>
#endif
#include "errors.h"
#include "isprop.h"
#include "utils.h"
#include "singlefile.h"
#include "chkfiles.h"
#include "arccomp.h"


char *cur_arccomp_name;
BOOL started_arccomp_file;

#if HAVE_FNMATCH_H && HAVE_ARCHIVE_H
#define MAX_AC_BUFF_SIZE (10*1024)

int num_ac_patterns;
char ac_patterns[MAX_AC_PATTERN_LEN];
char *cur_arccomp_name;

static struct archive *ina;
#endif


BOOL is_arc_comp(char *filename)
{
#if HAVE_FNMATCH_H && HAVE_ARCHIVE_H
int pnum;
char *cur_ac_pattern = ac_patterns;

for (pnum=0; pnum < num_ac_patterns; pnum++)
   {
   if (pnum != 0)
      cur_ac_pattern+=1+strlen(cur_ac_pattern);
// printf("%s %d\n", filename, fnmatch(cur_ac_pattern, filename, 0));
   if (fnmatch(cur_ac_pattern, filename, 0) == 0)
      return TRUE;
   }
return FALSE;

#else
return FALSE;
#endif
}


#if HAVE_ARCHIVE_H
static void arc_warning(char *warn_str, ...)
{
print_warning(warn_str);
}


static char * read_arccomp_buff(void)
{
static char file_buff[MAX_AC_BUFF_SIZE];

file_bytes_read = archive_read_data(ina, file_buff, sizeof(file_buff));

// printf("bytes read %d\n", file_bytes_read);

if (file_bytes_read < 0)
   {
   print_warning(archive_error_string(ina));
   print_warning("\n");
   file_bytes_read=0;
   }

return file_buff;
}
#endif


void try_just_compressed(char *filename)
{
#if HAVE_ARCHIVE_H
struct archive_entry *arc_entry = NULL; // dummy variable

ina = archive_read_new();
if (ina == NULL)
   arc_warning("Could not create archive reader\n", filename);
if (archive_read_support_compression_all(ina) != ARCHIVE_OK)
   {
   arc_warning("Could not enable decompression\n");
   return;
   }
if (archive_read_support_format_raw(ina) != ARCHIVE_OK)
   {
   arc_warning("Could not enable archive raw format\n");
   return;
   }
if (archive_read_open_filename(ina, filename, MAX_AC_BUFF_SIZE) != ARCHIVE_OK)
   {
   arc_warning("Could not open %s(archive_read_open_filename)\n", filename);
   return;
   }
if (archive_read_next_header(ina, &arc_entry) != ARCHIVE_OK)
   {
   arc_warning("Failed uncompress init %s(archive_read_next_header)\n", filename);
   return;
   }
started_arccomp_file=TRUE;
cur_arccomp_name=filename;
analyse_file(read_arccomp_buff, filename);
started_arccomp_file=FALSE;

if (archive_read_finish(ina) != ARCHIVE_OK)
   arc_warning("Error closing compressed file: %s\n", filename);

#endif
}


static void analyse_arc_entry(char *filename)
{
if (is_arc_comp(filename))
   {
   arc_warning("Nested archived files are not handled: %s\n", filename);
   }
else
   analyse_file(read_arccomp_buff, filename);
}


void handle_arc_comp(char *filename)
{
#if HAVE_ARCHIVE_H
int read_open_status;
struct archive_entry *arc_entry;

started_arccomp_file=TRUE;
cur_arccomp_name=filename;

ina = archive_read_new();
if (ina == NULL)
   arc_warning("Could not create archive reader\n", filename);
if (archive_read_support_compression_all(ina) != ARCHIVE_OK)
   {
   arc_warning("Could not enable decompression\n");
   return;
   }
if (archive_read_support_format_all(ina) != ARCHIVE_OK)
   {
   arc_warning("Could not enable archive read formats\n");
   return;
   }
// File descriptor 0 is stdin
read_open_status=archive_read_open_fd(ina, 0, MAX_AC_BUFF_SIZE);
if ((read_open_status != ARCHIVE_OK) &&
    (archive_errno(ina) != ARCHIVE_FATAL))
// if (archive_errno(ina) == ARCHIVE_ERRNO_FILE_FORMAT)
   {
   try_just_compressed(filename);
   return;
   }
// printf("%s:%d\n", archive_error_string(ina), archive_errno(ina));
if (read_open_status != ARCHIVE_OK)
   {
   arc_warning("Could not open archive (%s)\n", filename);
   return;
   }
while (archive_read_next_header(ina, &arc_entry) == ARCHIVE_OK)
   {
// printf("%s: ", archive_entry_pathname(arc_entry));
   // Only process regular files having non-zero size
   if (S_ISREG(archive_entry_mode(arc_entry)) &&
       (archive_entry_size(arc_entry) > 0))
      {
      if ((num_arg_patterns == 0) ||
	  match_file_pattern(archive_entry_pathname(arc_entry)))
         analyse_arc_entry(archive_entry_pathname(arc_entry));
      }
   }
started_arccomp_file=FALSE;

/* Close the archives.  */
if (archive_read_finish(ina) != ARCHIVE_OK)
   arc_warning("Error closing archive\n", filename);

#endif
}


#if HAVE_ARCHIVE_H
static void add_ac_suffix(char *ac_str, int *cur_ac_pattern_len)
{
if (save_arg_info(ac_patterns, cur_ac_pattern_len, MAX_AC_PATTERN_LEN,
		ac_str, "Size of file archive/compression suffixes exceeded at %s\n"))
   num_ac_patterns++;
}
#endif


void init_arccomp(void)
{
#if HAVE_FNMATCH_H && HAVE_ARCHIVE_H
int cur_ac_pattern_len = 0;

add_ac_suffix("*.bz2", &cur_ac_pattern_len);
add_ac_suffix("*.cab", &cur_ac_pattern_len);
add_ac_suffix("*.cpio", &cur_ac_pattern_len);
add_ac_suffix("*.cpgz", &cur_ac_pattern_len);
add_ac_suffix("*.gz", &cur_ac_pattern_len);
add_ac_suffix("*.iso", &cur_ac_pattern_len);
add_ac_suffix("*.lha", &cur_ac_pattern_len);
add_ac_suffix("*.lzh", &cur_ac_pattern_len);
add_ac_suffix("*.rar", &cur_ac_pattern_len);
add_ac_suffix("*.rpm", &cur_ac_pattern_len);
add_ac_suffix("*.tar", &cur_ac_pattern_len);
add_ac_suffix("*.tbz2", &cur_ac_pattern_len);
add_ac_suffix("*.tgz", &cur_ac_pattern_len);
add_ac_suffix("*.xar", &cur_ac_pattern_len);
add_ac_suffix("*.xz", &cur_ac_pattern_len);
add_ac_suffix("*.z", &cur_ac_pattern_len);
add_ac_suffix("*.Z", &cur_ac_pattern_len);
add_ac_suffix("*.zip", &cur_ac_pattern_len);
#endif
}

