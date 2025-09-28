#ifndef	_CTYPE_H
#define	_CTYPE_H	1

/* Return the lowercase version of C.  */
int tolower (int c); 

/* Return the uppercase version of C.  */
int toupper (int c); 

int isascii (int c);
int toascii (int c);
int isalnum (int c);
int isalpha (int c);
int iscntrl (int c);
int isdigit (int c);
int islower (int c);
int isgraph (int c);
int isprint (int c);
int ispunct (int c);
int isspace (int c);
int isupper (int c);
int isxdigit(int c);
int isblank (int c);
int toupper (int c);
int tolower (int c);

#endif /* ctype.h  */
