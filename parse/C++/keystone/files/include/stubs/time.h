
#ifndef _TIME_H_
#define _TIME_H_

/*
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/time.h.html
 */

#include <sys/types.h>

struct tm {
   int    tm_sec;  //  Seconds [0,60]. 
   int    tm_min;  //  Minutes [0,59]. 
   int    tm_hour;  // Hour [0,23]. 
   int    tm_mday;  // Day of month [1,31]. 
   int    tm_mon;  //  Month of year [0,11]. 
   int    tm_year;  // Years since 1900. 
   int    tm_wday;  // Day of week [0,6] (Sunday =0). 
   int    tm_yday;  // Day of year [0,365]. 
   int    tm_isdst;  //Daylight Savings flag. 
};

enum {
   CLOCKS_PER_SEC,
   CLOCK_PROCESS_CPUTIME_ID,
   CLOCK_THREAD_CPUTIME_ID,
   TIMER_ABSTIME,
   CLOCK_MONOTONIC
};

struct timespec {
   time_t  tv_sec; //    Seconds. 
   long    tv_nsec; //   Nanoseconds.
};

struct itimerspec {
   struct timespec  it_interval;  //  Timer period. 
   struct timespec  it_value;  //     Timer expiration.
};

char      *asctime(const struct tm *);
char      *asctime_r(const struct tm *restrict, char *restrict);
clock_t    clock(void);
int        clock_getcpuclockid(pid_t, clockid_t *);
int        clock_getres(clockid_t, struct timespec *);
int        clock_gettime(clockid_t, struct timespec *);
int        clock_nanosleep(clockid_t, int, const struct timespec *,
               struct timespec *);
int        clock_settime(clockid_t, const struct timespec *);
char      *ctime(const time_t *);
char      *ctime_r(const time_t *, char *);
double     difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *gmtime_r(const time_t *restrict, struct tm *restrict);
struct tm *localtime(const time_t *);
struct tm *localtime_r(const time_t *restrict, struct tm *restrict);
time_t     mktime(struct tm *);
int        nanosleep(const struct timespec *, struct timespec *);
size_t     strftime(char *restrict, size_t, const char *restrict,
           const struct tm *restrict);
char      *strptime(const char *restrict, const char *restrict,
               struct tm *restrict);
time_t     time(time_t *);
int        timer_create(clockid_t, struct sigevent *restrict,
               timer_t *restrict);
int        timer_delete(timer_t);
int        timer_gettime(timer_t, struct itimerspec *);
int        timer_getoverrun(timer_t);
int        timer_settime(timer_t, int, const struct itimerspec *restrict,
               struct itimerspec *restrict);
void       tzset(void);


extern int    daylight;
extern long   timezone;
extern char  *tzname[];

#endif
