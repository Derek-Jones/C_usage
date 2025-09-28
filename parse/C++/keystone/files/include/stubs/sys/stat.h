
#ifndef _SYS_STAT_H_
#define _SYS_STAT_H_

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/sys/stat.h.html
 */

#include <sys/types.h>

struct stat {
   dev_t     st_dev;   //    Device ID of device containing file. 
   ino_t     st_ino;   //    File serial number. 
   mode_t    st_mode;   //   Mode of file (see below). 
   nlink_t   st_nlink;   //  Number of hard links to the file. 
   uid_t     st_uid;   //    User ID of file. 
   gid_t     st_gid;   //    Group ID of file. 

   dev_t     st_rdev;   //   Device ID (if file is character or block special). 

   off_t     st_size;   //   For regular files, the file size in bytes. 

   time_t    st_atime;   //  Time of last access. 
   time_t    st_mtime;   //  Time of last data modification. 
   time_t    st_ctime;   //  Time of last status change. 

   blksize_t st_blksize;   //A file system-specific preferred I/O block size for 
                           //this object. In some file system types, this may 
                           //vary from file to file. 
   blkcnt_t  st_blocks;   // Number of blocks allocated for this object. 
};

enum S_IFMT {
    S_IFBLK,
    S_IFCHR,
    S_IFIFO,
    S_IFREG,
    S_IFDIR,
    S_IFLNK,
    S_IFSOCK
};


enum S_IRWXU {
    S_IRUSR,
    S_IWUSR,
    S_IXUSR
};

enum S_IRWXG {
    S_IRGRP,
    S_IWGRP,
    S_IXGRP
};

enum S_IRWXO {
    S_IROTH,
    S_IWOTH,
    S_IXOTH
};

enum {
   S_ISUID,
   S_ISGID,
   S_ISVTX,
   S_IRWXU,
   S_IRWXG,
   S_IRWXO
};

int S_ISBLK(mode_t );
//    Test for a block special file.
int S_ISCHR(mode_t );
//    Test for a character special file.
int S_ISDIR(mode_t );
//    Test for a directory.
int S_ISFIFO(mode_t );
//    Test for a pipe or FIFO special file.
int S_ISREG(mode_t );
//    Test for a regular file.
int S_ISLNK(mode_t );
//    Test for a symbolic link.
int S_ISSOCK(mode_t );

int S_TYPEISMQ(struct stat *);
int S_TYPEISSEM(struct stat *);
int S_TYPEISSHM(struct stat *);
int S_TYPEISTMO(struct stat *);

int    chmod(const char *, mode_t);
int    fchmod(int, mode_t);
int    fstat(int, struct stat *);
int    lstat(const char *restrict, struct stat *restrict);
int    mkdir(const char *, mode_t);
int    mkfifo(const char *, mode_t);

int    mknod(const char *, mode_t, dev_t);

int    stat(const char *restrict, struct stat *restrict);
mode_t umask(mode_t);

#endif
