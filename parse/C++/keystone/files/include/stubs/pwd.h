
#ifndef _PWD_H_
#define _PWD_H_

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/pwd.h.html
 */

#include <sys/types.h>

struct passwd {
   char    *pw_name;  //   User's login name. 
   uid_t    pw_uid;  //    Numerical user ID. 
   gid_t    pw_gid;  //    Numerical group ID. 
   char    *pw_dir;  //    Initial working directory. 
   char    *pw_shell;  //  Program to use as shell. 
};

struct passwd *getpwnam(const char *);
struct passwd *getpwuid(uid_t);

int            getpwnam_r(const char *, struct passwd *, char *,
                   size_t, struct passwd **);
int            getpwuid_r(uid_t, struct passwd *, char *,
                   size_t, struct passwd **);


void           endpwent(void);
struct passwd *getpwent(void);
void           setpwent(void);

#endif
