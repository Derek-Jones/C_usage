
#ifndef _SIGNAL_H_
#define _SIGNAL_H_

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html
 */

#include <sys/types.h>

typedef void (*sighandler_t)(int);

typedef void(*SIG_DFL)(int);
typedef void(*SIG_ERR)(int);
typedef void(*SIG_HOLD)(int);
sighandler_t SIG_IGN;
/*typedef void(*SIG_IGN)(int);*/

typedef int sig_atomic_t;
typedef int sigset_t;

union sigval {
   int    sival_int;  //    Integer signal value. 
   void  *sival_ptr;  //    Pointer signal value.
};

struct sigevent {
   int                    sigev_notify; //            Notification type. 
   int                    sigev_signo; //             Signal number. 
   union sigval           sigev_value; //             Signal value. 
   void(*sigev_notify_function)(union sigval)  ; //   Notification function. 
   pthread_attr_t *sigev_notify_attributes; // Notification attributes. 
};

enum {
   SIGEV_NONE,
   SIGEV_SIGNAL,
   SIGEV_THREAD
};

enum {
   SIGABRT,
   SIGALRM,
   SIGBUS,
   SIGCHLD,
   SIGCONT,
   SIGFPE,
   SIGHUP,
   SIGILL,
   SIGINT,
   SIGKILL,
   SIGPIPE,
   SIGQUIT,
   SIGSEGV,
   SIGSTOP,
   SIGTERM,
   SIGTSTP,
   SIGTTIN,
   SIGTTOU,
   SIGUSR1,
   SIGUSR2,
   SIGPROF,
   SIGSYS,
   SIGTRAP,
   SIGURG,
   SIGXCPU,
   SIGXFSZ
};

sighandler_t signal(int signum, sighandler_t handler);

#endif
