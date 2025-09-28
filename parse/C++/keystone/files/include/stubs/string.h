#ifndef	_STRING_H
#define	_STRING_H	1

#include <stddef.h>
//using std::size_t;

/* Copy N bytes of SRC to DEST.  */
void *memcpy (void *dest,
              const void *src, size_t n);
/* Copy N bytes of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
void *memmove (void *dest, const void *src, size_t n);

/* Set N bytes of S to C.  */
void *memset (void *s, int c, size_t n);

/* Compare N bytes of S1 and S2.  */
int memcmp (const void *s1, const void *s2, size_t n);

/* Search N bytes of S for C.  */
extern void *memchr (const void *s, int c, size_t n);

/* Copy SRC to DEST.  */
char *strcpy (char *dest, const char *src);

/* Copy no more than N characters of SRC to DEST.  */
char *strncpy (char *dest,
		      const char *src, size_t n);

/* Append SRC onto DEST.  */
char *strcat (char *dest, const char *src);

/* Append no more than N characters from SRC onto DEST.  */
char *strncat (char *dest, const char * src,
		      size_t n);

/* Compare S1 and S2.  */
int strcmp (const char *s1, const char *s2);
/* Compare N characters of S1 and S2.  */
int strncmp (const char *s1, const char *s2, size_t n);

/* Compare the collated forms of S1 and S2.  */
int strcoll (const char *s1, const char *s2);

/* Put a transformation of SRC into no more than N bytes of DEST.  */
size_t strxfrm (char *dest,
		       const char *src, size_t n);

/* Find the first occurrence of C in S.  */
char *strchr (const char *s, int c);
/* Find the last occurrence of C in S.  */
char *strrchr (const char *s, int c);

/* Return the length of the initial segment of S which
   consists entirely of characters not in REJECT.  */
size_t strcspn (const char *s, const char *reject);
/* Return the length of the initial segment of S which
   consists entirely of characters in ACCEPT.  */
size_t strspn (const char *s, const char *accept);
/* Find the first occurrence in S of any character in ACCEPT.  */
char *strpbrk (const char *s, const char *accept);
/* Find the first occurrence of NEEDLE in HAYSTACK.  */
char *strstr (const char *haystack, const char *needle);

/* Divide S into tokens separated by characters in DELIM.  */
char *strtok (char *s, const char *delim);

/* Return the length of S.  */
size_t strlen (const char *s); 

/* Return a string describing the meaning of the `errno' code in ERRNUM.  */
char *strerror (int errnum);

#endif /* string.h  */
