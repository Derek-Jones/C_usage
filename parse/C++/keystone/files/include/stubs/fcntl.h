
#ifndef _FCNTL_H_
#define _FCNTL_H_

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/fcntl.h.html
 */

#include <unistd.h>
#include <sys/types.h>

enum {
   F_DUPFD,
   F_GETFD,
   F_SETFD,
   F_GETFL,
   F_SETFL,
   F_GETLK,
   F_SETLK,
   F_SETLKW,
   F_GETOWN,
   F_SETOWN,


   FD_CLOEXEC,

   F_RDLCK,
   F_UNLCK,
   F_WRLCK,


   O_CREAT,
   O_EXCL,
   O_NOCTTY,
   O_TRUNC,


   O_APPEND,
   O_DSYNC,
   O_NONBLOCK,
   O_RSYNC,
   O_SYNC,

   O_ACCMODE,

   O_RDONLY,
   O_RDWR,
   O_WRONLY,

   POSIX_FADV_NORMAL,
   POSIX_FADV_SEQUENTIAL,
   POSIX_FADV_RANDOM,
   POSIX_FADV_WILLNEED,
   POSIX_FADV_DONTNEED,
   POSIX_FADV_NOREUSE,
};

struct flock {
   short  l_type; //   Type of lock; F_RDLCK, F_WRLCK, F_UNLCK. 
   short  l_whence; // Flag for starting offset. 
   off_t  l_start; //  Relative offset in bytes. 
   off_t  l_len; //    Size; if 0 then until EOF. 
   pid_t  l_pid; //    Process ID of the process holding the lock; returned with F_GETLK. 
};

int  creat(const char *, mode_t);
int  fcntl(int, int, ...);
int  open(const char *, int, ...);

int  posix_fadvise(int, off_t, off_t, int);
int  posix_fallocate(int, off_t, off_t);

#endif
