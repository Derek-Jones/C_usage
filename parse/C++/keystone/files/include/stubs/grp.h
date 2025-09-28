
#ifndef _GRP_H_
#define _GRP_H_

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/grp.h.html
 */

#include <sys/types.h>

struct group {
   char   *gr_name; // The name of the group. 
   gid_t   gr_gid; //  Numerical group ID. 
   char  **gr_mem; //  Pointer to a null-terminated array of character pointers to member names. 
};



struct group  *getgrgid(gid_t);
struct group  *getgrnam(const char *);

int            getgrgid_r(gid_t, struct group *, char *,
                   size_t, struct group **);
int            getgrnam_r(const char *, struct group *, char *,
                   size_t , struct group **);

struct group  *getgrent(void);
void           endgrent(void);
void           setgrent(void);

#endif
