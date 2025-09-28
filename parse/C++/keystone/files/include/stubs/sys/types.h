
#ifndef _SYS_TYPES_H_
#define _SYS_TYPES_H_

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/sys/types.h.html
 */

typedef int blkcnt_t;
typedef int blksize_t;
typedef double clock_t;
typedef long  clockid_t;
typedef long dev_t;
typedef unsigned int fsblkcnt_t;
typedef unsigned int fsfilcnt_t;
typedef int gid_t;
typedef int id_t;
typedef unsigned int ino_t;
struct key_t;
typedef int mode_t;
typedef int nlink_t;
typedef int off_t;
typedef int pid_t;
struct pthread_attr_t;
struct pthread_barrier_t;
struct pthread_barrierattr_t;
struct pthread_cond_t;
struct pthread_condattr_t;
struct pthread_key_t;
struct pthread_mutex_t;
struct pthread_mutexattr_t;
struct pthread_once_t;
struct pthread_rwlock_t;
struct pthread_rwlockattr_t;
struct pthread_spinlock_t;
struct pthread_t;
typedef unsigned int size_t;
typedef int ssize_t;
typedef long suseconds_t;
typedef double time_t;
struct timer_t;
struct trace_attr_t;
struct trace_event_id_t;
struct trace_event_set_t;
struct trace_id_t;
typedef int uid_t;
typedef unsigned long useconds_t;

#endif
