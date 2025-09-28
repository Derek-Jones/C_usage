#ifndef _WCHAR_H
#define _WCHAR_H

#include <stddef.h>
//using std::size_t;

#include <wctype.h>

#ifndef WEOF
# define WEOF (0xffffffffu)
#endif

/* This incomplete type is defined in <time.h> but needed here because
   of `wcsftime'.  */
struct tm;


/* Copy SRC to DEST.  */
wchar_t *wcscpy (wchar_t *dest,
			const wchar_t *src);
/* Copy no more than N wide-characters of SRC to DEST.  */
wchar_t *wcsncpy (wchar_t *dest,
			 const wchar_t *src, size_t n);
 
/* Append SRC onto DEST.  */
wchar_t *wcscat (wchar_t *dest,
			const wchar_t *src);
/* Append no more than N wide-characters of SRC onto DEST.  */
wchar_t *wcsncat (wchar_t *dest,
			 const wchar_t *src, size_t n);


/* Compare S1 and S2.  */
int wcscmp (const wchar_t *s1, const wchar_t *s2);
   
/* Compare N wide-characters of S1 and S2.  */
int wcsncmp (const wchar_t *s1, const wchar_t *s2, size_t n);
 

/* Compare S1 and S2, both interpreted as appropriate to the
   LC_COLLATE category of the current locale.  */
int wcscoll (const wchar_t *s1, const wchar_t *s2);
/* Transform S2 into array pointed to by S1 such that if wcscmp is
   applied to two transformed strings the result is the as applying
   `wcscoll' to the original strings.  */
size_t wcsxfrm (wchar_t *s1,
		       const wchar_t *s2, size_t n);

/* Find the first occurrence of WC in WCS.  */
wchar_t *wcschr (const wchar_t *wcs, wchar_t wc);
/* Find the last occurrence of WC in WCS.  */
wchar_t *wcsrchr (const wchar_t *wcs, wchar_t wc);

/* Return the length of the initial segmet of WCS which
   consists entirely of wide characters not in REJECT.  */
size_t wcscspn (const wchar_t *wcs, const wchar_t *reject);
/* Return the length of the initial segmet of WCS which
   consists entirely of wide characters in  ACCEPT.  */
size_t wcsspn (const wchar_t *wcs, const wchar_t *accept);
/* Find the first occurrence in WCS of any character in ACCEPT.  */
wchar_t *wcspbrk (const wchar_t *wcs, const wchar_t *accept);
/* Find the first occurrence of NEEDLE in HAYSTACK.  */
wchar_t *wcsstr (const wchar_t *haystack, const wchar_t *needle);

/* Divide WCS into tokens separated by characters in DELIM.  */
wchar_t *wcstok (wchar_t *s,
			const wchar_t *delim,
			wchar_t **ptr);

/* Return the number of wide characters in S.  */
size_t wcslen (const wchar_t *s);

/* Search N wide characters of S for C.  */
wchar_t *wmemchr (const wchar_t *s, wchar_t c, size_t n);

/* Compare N wide characters of S1 and S2.  */
int wmemcmp (const wchar_t *s1,
		    const wchar_t *s2, size_t n);

/* Copy N wide characters of SRC to DEST.  */
wchar_t *wmemcpy (wchar_t *s1,
			 const wchar_t *s2, size_t n);

/* Copy N wide characters of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
wchar_t *wmemmove (wchar_t *s1, const wchar_t *s2, size_t n);

/* Set N wide characters of S to C.  */
wchar_t *wmemset (wchar_t *s, wchar_t c, size_t n);

/* Determine whether C constitutes a valid (one-byte) multibyte
   character.  */
wint_t btowc (int c);

/* Determine whether C corresponds to a member of the extended
   character set whose multibyte representation is a single byte.  */
int wctob (wint_t c);

#include "mbstate.h"
/* Determine whether PS points to an object representing the initial
   state.  */
int mbsinit (const mbstate_t *ps);

/* Write wide character representation of multibyte character pointed
   to by S to PWC.  */
size_t mbrtowc (wchar_t *pwc,
		       const char *s, size_t n,
		       mbstate_t *p);

/* Write multibyte representation of wide character WC to S.  */
size_t wcrtomb (char *s, wchar_t wc,
		       mbstate_t *ps);

/* Return number of bytes in multibyte character pointed to by S.  */
size_t mbrlen (const char *s, size_t n,
		      mbstate_t *ps);

/* Write wide character representation of multibyte character string
   SRC to DST.  */
size_t mbsrtowcs (wchar_t *dst,
			 const char **src, size_t len,
			 mbstate_t *ps);

/* Write multibyte character representation of wide character string
   SRC to DST.  */
size_t wcsrtombs (char *dst,
			 const wchar_t **src, size_t len,
			 mbstate_t *ps);


/* Convert initial portion of the wide string NPTR to `double'
   representation.  */
double wcstod (const wchar_t *nptr,
		      wchar_t **endptr);

/* Convert initial portion of wide string NPTR to `long int'
   representation.  */
long int wcstol (const wchar_t *nptr,
			wchar_t **endptr, int base);

/* Convert initial portion of wide string NPTR to `unsigned long int'
   representation.  */
unsigned long int wcstoul (const wchar_t *nptr,
				  wchar_t **endptr, int base);


#include <stdio.h>
/* Select orientation for stream.  */
int fwide (FILE *fp, int mode);


/* Write formatted output to STREAM.  */
int fwprintf (FILE *__stream,
		    const wchar_t *format, ...);
 
/* Write formatted output to stdout.  */
int wprintf (const wchar_t *format, ...);
/* Write formatted output of at most N characters to S.  */
int swprintf (wchar_t *s, size_t n,
		     const wchar_t *format, ...);

/* Write formatted output to S from argument list ARG.  */
int vfwprintf (FILE *s,
		      const wchar_t *format,
		      void* arg);
/* Write formatted output to stdout from argument list ARG.  */
int vwprintf (const wchar_t *format,
		     void* arg);
/* Write formatted output of at most N character to S from argument
   list ARG.  */
int vswprintf (wchar_t *s, size_t n,
		      const wchar_t *format,
		      void* arg);


/* Read formatted input from STREAM.  */
int fwscanf (FILE *stream,
		    const wchar_t *format, ...);
/* Read formatted input from stdin.  */
int wscanf (const wchar_t *format, ...);
/* Read formatted input from S.  */
extern int swscanf (const wchar_t *s,
		    const wchar_t *format, ...);

/* Read a character from STREAM.  */
wint_t fgetwc (FILE *stream);
wint_t getwc (FILE *stream);

/* Read a character from stdin.  */
wint_t getwchar (void);


/* Write a character to STREAM.  */
wint_t fputwc (wchar_t wc, FILE *stream);
wint_t putwc (wchar_t wc, FILE *stream);

/* Write a character to stdout.  */
wint_t putwchar (wchar_t wc);


/* Get a newline-terminated wide character string of finite length
   from STREAM.  */
wchar_t *fgetws (wchar_t *ws, int n,
			FILE *stream);

/* Write a string to STREAM.  */
int fputws (const wchar_t *ws,
		   FILE *stream);


/* Push a character back onto the input buffer of STREAM.  */
wint_t ungetwc (wint_t wc, FILE *stream);


/* Format TP into S according to FORMAT.
   Write no more than MAXSIZE wide characters and return the number
   of wide characters written, or 0 if it would exceed MAXSIZE.  */
size_t wcsftime (wchar_t *s, size_t maxsize,
			const wchar_t *format,
			const struct tm *tp);

/* The X/Open standard demands that most of the functions defined in
   the <wctype.h> header must also appear here.  This is probably
   because some X/Open members wrote their implementation before the
   ISO C standard was published and introduced the better solution.
   We have to provide these definitions for compliance reasons but we
   do this nonsense only if really necessary.  */

#endif /* wchar.h  */
