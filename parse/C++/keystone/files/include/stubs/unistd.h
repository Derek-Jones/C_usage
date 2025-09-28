
#ifndef _UNITSTD_H_
#define _UNITSTD_H_

#include <stdlib.h>

/* Add what belongs as needed..I can't make out the specification
 * for this header file
 */

int isatty(int desc);
int access(const char *pathname, int mode);
char *getcwd(char *buf, size_t size);
char *get_current_dir_name(void);
char *getwd(char *buf);
int rmdir(const char *pathname);

char *getpass( const char * prompt );
int chown(const char *path, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);
int lchown(const char *path, uid_t owner, gid_t group);

#endif
