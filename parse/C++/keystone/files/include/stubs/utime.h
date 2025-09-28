
#ifndef _UTIME_H
#define _UTIME_H

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/utime.h.html
 */

#include <sys/types.h>

struct utimbuf {
   time_t    actime;  // Access time. 
   time_t    modtime;  //Modification time. 
};

int utime(const char *, const struct utimbuf *);

#endif
