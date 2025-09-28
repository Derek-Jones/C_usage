#ifndef	_STDLIB_H
#define	_STDLIB_H

#include <sys/types.h>
#include <stddef.h>

/* Returned by `div'.  */
typedef struct
  {
    int quot;			/* Quotient.  */
    int rem;			/* Remainder.  */
  } div_t;

/* Returned by `ldiv'.  */
typedef struct
  {
    long int quot;		/* Quotient.  */
    long int rem;		/* Remainder.  */
  } ldiv_t;


/* The largest number rand will return (same as INT_MAX).  */
#define	RAND_MAX	2147483647


/* We define these the same for all machines.
   Changes from this to the outside world should be done in `_exit'.  */
#define	EXIT_FAILURE	1	/* Failing exit status.  */
#define	EXIT_SUCCESS	0	/* Successful exit status.  */



/* Convert a string to a floating-point number.  */
double atof (const char *);
/* Convert a string to an integer.  */
int atoi (const char *);
/* Convert a string to a long integer.  */
long int atol (const char *);

/* Convert a string to a long long integer.  */
long long int atoll (const char *);

/* Convert a string to a floating-point number.  */
double strtod (const char *, char **);

/* Likewise for `float' and `long double' sizes of floating-point numbers.  */
float strtof (const char *, char **);

long double strtold (const char *, char **);

/* Convert a string to a long integer.  */
long int strtol (const char *, char **, int);

/* Convert a string to an unsigned long integer.  */
unsigned long int strtoul (const char *, char **, int );


/* The internal entry points for `strtoX' take an extra flag argument
   saying whether or not to parse locale-dependent number grouping.  */

/*
extern double __strtod_internal (__const char *__restrict __nptr,
				 char **__restrict __endptr, int __group)
     __THROW;
extern float __strtof_internal (__const char *__restrict __nptr,
				char **__restrict __endptr, int __group)
     __THROW;
extern long double __strtold_internal (__const char *__restrict __nptr,
				       char **__restrict __endptr,
				       int __group) __THROW;
#ifndef __strtol_internal_defined
extern long int __strtol_internal (__const char *__restrict __nptr,
				   char **__restrict __endptr,
				   int __base, int __group) __THROW;
# define __strtol_internal_defined	1
#endif
#ifndef __strtoul_internal_defined
extern unsigned long int __strtoul_internal (__const char *__restrict __nptr,
					     char **__restrict __endptr,
					     int __base, int __group) __THROW;
# define __strtoul_internal_defined	1
#endif
#if defined __GNUC__ || defined __USE_ISOC99
# ifndef __strtoll_internal_defined
__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
					 char **__restrict __endptr,
					 int __base, int __group) __THROW;
#  define __strtoll_internal_defined	1
# endif
# ifndef __strtoull_internal_defined
__extension__
extern unsigned long long int __strtoull_internal (__const char *
						   __restrict __nptr,
						   char **__restrict __endptr,
						   int __base, int __group)
     __THROW;
#  define __strtoull_internal_defined	1
# endif
#endif * GCC *
*/


inline double strtod (const char *, char **);
inline long int strtol (const char *, char **, int );
inline unsigned long int strtoul (const char *, char **, int );

inline float strtof (const char *, char **);
inline long double strtold (const char *, char **);

inline long long int strtoq (const char *, char **, int );
inline unsigned long long int strtouq (const char *, char **, int );

inline long long int strtoll (const char *, char **, int );
inline unsigned long long int strtoull (const char * , char **, int );

inline double atof (const char *);
inline int atoi (const char *);
inline long int atol (const char *);

inline long long int atoll (const char *);


extern char *l64a (long int );

/* Read a number from a string S in base 64 as above.  */
extern long int a64l (const char *);


/* Return a random long integer between 0 and RAND_MAX inclusive.  */
extern long int random (void);

/* Seed the random number generator with the given number.  */
extern void srandom (unsigned int );

/* Initialize the random number generator to use state buffer STATEBUF,
   of length STATELEN, and seed it with SEED.  Optimal lengths are 8, 16,
   32, 64, 128 and 256, the bigger the better; values less than 8 will
   cause an error and values greater than 256 will be rounded down.  */
extern char *initstate (unsigned int , char *, size_t );

/* Switch the random number generator to state buffer STATEBUF,
   which should have been previously initialized by `initstate'.  */
extern char *setstate (char *) ;


typedef int int32_t;

struct random_data
  {
    int32_t *fptr;		/* Front pointer.  */
    int32_t *rptr;		/* Rear pointer.  */
    int32_t *state;		/* Array of state values.  */
    int rand_type;		/* Type of random number generator.  */
    int rand_deg;		/* Degree of random number generator.  */
    int rand_sep;		/* Distance between front and rear.  */
    int32_t *end_ptr;		/* Pointer behind state table.  */
  };

extern int random_r (struct random_data *, int32_t *);

extern int srandom_r (unsigned int , struct random_data *);

extern int initstate_r (unsigned int , char *, size_t , struct random_data *);

extern int setstate_r (char *, struct random_data *);


/* Return a random integer between 0 and RAND_MAX inclusive.  */
extern int rand (void);
/* Seed the random number generator with the given number.  */
extern void srand (unsigned int );

/* Reentrant interface according to POSIX.1.  */
extern int rand_r (unsigned int *) ;


/* Allocate SIZE bytes of memory.  */
extern void *malloc (size_t );
/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
extern void *calloc (size_t , size_t ) ;

/* Re-allocate the previously allocated block
   in PTR, making the new block SIZE bytes long.  */
extern void *realloc (void *, size_t ) ;
/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
extern void free (void *) ;

/* Free a block.  An alias for `free'.	(Sun Unices).  */
extern void cfree (void *) ;

/* Abort execution and generate a core-dump.  */
extern void abort (void);


/* Register a function to be called when `exit' is called.  */
extern int atexit (void (*) (void)) ;

/* Register a function to be called with the status
   given to `exit' and the given argument.  */
extern int on_exit (void (*) (int , void *), void *) ;

/* Call all functions registered with `atexit' and `on_exit',
   in the reverse of the order in which they were registered
   perform stdio cleanup, and terminate program execution with STATUS.  */
extern void exit (int );

/* Terminate the program with STATUS without calling any of the
   functions registered with `atexit' or `on_exit'.  */
extern void _Exit (int );


/* Return the value of envariable NAME, or NULL if it doesn't exist.  */
extern char *getenv (const char *) ;

/* This function is similar to the above but returns NULL if the
   programs is running with SUID or SGID enabled.  */
extern char *__secure_getenv (const char *) ;


/* The `clearenv' was planned to be added to POSIX.1 but probably
   never made it.  Nevertheless the POSIX.9 standard (POSIX bindings
   for Fortran 77) requires this function.  */
extern int clearenv (void) ;


/* Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   Returns TEMPLATE, or a null pointer if it cannot get a unique file name.  */
extern char *mktemp (char *) ;

/* Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the filename unique.
   Returns a file descriptor open on the file for reading and writing,
   or -1 if it cannot create a uniquely-named file.  */

/* Execute the given line as a shell command.  */
extern int system (const char *) ;


/* Return a malloc'd string containing the canonical absolute name of the
   named file.  The last file name component need not exist, and may be a
   symlink to a nonexistent file.  */
extern char *canonicalize_file_name (const char *) ;

/* Return the canonical absolute name of file NAME.  The last file name
   component need not exist, and may be a symlink to a nonexistent file.
   If RESOLVED is null, the result is malloc'd; otherwise, if the canonical
   name is PATH_MAX chars or more, returns null with `errno' set to
   ENAMETOOLONG; if the name fits in fewer than PATH_MAX chars, returns the
   name in RESOLVED.  */
extern char *realpath (const char *restrict , char *) ;


/* Shorthand for type of comparison functions.  */
typedef int (*__compar_fn_t) (const void *, const void *);

typedef __compar_fn_t comparison_fn_t;

/* Do a binary search for KEY in BASE, which consists of NMEMB elements
   of SIZE bytes each, using COMPAR to perform the comparisons.  */
extern void *bsearch (const void *, const void *, size_t , size_t , __compar_fn_t );

/* Sort NMEMB elements of BASE, of SIZE bytes each,
   using COMPAR to perform the comparisons.  */
extern void qsort (void *, size_t , size_t , __compar_fn_t );


/* Return the absolute value of X.  */
extern int abs (int );
extern long int labs (long int );
extern long long int llabs (long long int );


/* Return the `div_t', `ldiv_t' or `lldiv_t' representation
   of the value of NUMER over DENOM. */
/* GCC may have built-ins for these someday.  */
extern div_t div (int , int );
extern ldiv_t ldiv (long int , long int );



/* Return the length of the multibyte character
   in S, which is no longer than N.  */
extern int mblen (const char *, size_t ) ;
/* Return the length of the given multibyte character,
   putting its `wchar_t' representation in *PWC.  */
extern int mbtowc (wchar_t *, const char *, size_t ) ;
/* Put the multibyte character represented
   by WCHAR in S, returning its length.  */
extern int wctomb (char *, wchar_t ) ;


/* Convert a multibyte string to a wide char string.  */
extern size_t mbstowcs (wchar_t *, const char *, size_t ) ;
/* Convert a wide char string to multibyte string.  */
extern size_t wcstombs (char *, const wchar_t *, size_t );



/* Store at most BUFLEN characters of the pathname of the slave pseudo
   terminal associated with the master FD is open on in BUF.
   Return 0 on success, otherwise an error number.  */
extern int ptsname_r (int , char *, size_t ) ;

/* Open a master pseudo terminal and return its file descriptor.  */
extern int getpt (void);

/* Put the 1 minute, 5 minute and 15 minute load averages into the first
   NELEM elements of LOADAVG.  Return the number written (never more than
   three, but may be less than NELEM), or -1 if an error occurred.  */
extern int getloadavg (double __loadavg[], int ) ;

#endif /* stdlib.h  */
