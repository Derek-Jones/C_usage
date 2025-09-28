
#ifndef _DIRENT_H
#define _DIRENT_H

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/dirent.h.html
 */

#include <sys/types.h>

struct __DIR { };
typedef __DIR DIR;

struct dirent {
   ino_t  d_ino;   //    File serial number. 
   char   d_name[];
};



int            closedir(DIR *);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);

int            readdir_r(DIR *restrict, struct dirent *restrict,
                   struct dirent **restrict);

void           rewinddir(DIR *);

void           seekdir(DIR *, long);
long           telldir(DIR *);

#endif
