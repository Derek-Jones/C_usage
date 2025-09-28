#ifndef _STDIO_H
#define _STDIO_H

#include <stdarg.h>
#include <stddef.h>

struct _IO_FILE { };
/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE FILE;

/* End of file character.
   Some things throughout the library rely on this being -1.  */
#ifndef EOF
# define EOF (-1)
#endif


/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
#define SEEK_SET	0	/* Seek from beginning of file.  */
#define SEEK_CUR	1	/* Seek from current position.  */
#define SEEK_END	2	/* Seek from end of file.  */


/* Standard streams.  */
FILE *stdin;		/* Standard input stream.  */
FILE *stdout;		/* Standard output stream.  */
FILE *stderr;		/* Standard error output stream.  */

/* Remove file FILENAME.  */
int remove (const char *filename); 
/* Rename file OLD to NEW.  */
int rename (const char *, const char *);

FILE *tmpfile (void);
/* Generate a temporary filename.  */
char *tmpnam (char *s);

/* Close STREAM.  */
int fclose (FILE *stream);
/* Flush STREAM, or all streams if STREAM is NULL.  */
int fflush (FILE *stream);

/* Open a file and create a new stream for it.  */
FILE *fopen (const char * filename,
             const char * modes);
/* Open a file, replacing an existing stream with it. */
FILE *freopen (const char * filename,
	       const char * modes,
	      FILE * stream); 

#include <stddef.h>
using std::size_t;
/* Create a new stream that refers to a memory buffer.  */
FILE *fmemopen (void *s, size_t len, const char *modes);

/* Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose.  */
FILE *open_memstream (char **bufloc,
		      size_t *sizeloc);

/* If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ.  */
void setbuf (FILE *stream, char *buf);
/* Make STREAM use buffering mode MODE.
   If BUF is not NULL, use N bytes of it for buffering;
   else allocate an internal buffer N bytes long.  */
int setvbuf (FILE *stream, char *buf,
		    int modes, size_t n);

/* Write formatted output to STREAM.  */
int fprintf (FILE *stream,
		   const char *__format, ...);
/* Write formatted output to stdout.  */
int printf (const char *format, ...);
/* Write formatted output to S.  */
int sprintf (char *s,
	     const char *format, ...);

/* Write formatted output to S from argument list ARG.  */
int vfprintf (FILE *s, const char *format,
	      va_list _arg);
/* Write formatted output to stdout from argument list ARG.  */
int vprintf (const char *format, void* arg);
/* Write formatted output to S from argument list ARG.  */
int vsprintf (char *s, const char *format,
	      va_list arg);

/* Read formatted input from STREAM.  */
int fscanf (FILE *stream,
		   const char *format, ...);
/* Read formatted input from stdin.  */
int scanf (const char *format, ...);
/* Read formatted input from S.  */
int sscanf (const char *s,
		   const char *format, ...);

/* Read a character from STREAM.  */
int fgetc (FILE *stream);
int getc (FILE *stream);

/* Read a character from stdin.  */
int getchar (void);

/* Write a character to STREAM.  */
int fputc (int c, FILE *stream);
int putc (int c, FILE *stream);

/* Write a character to stdout.  */
int putchar (int c) ;

/* Get a newline-terminated string of finite length from STREAM.  */
char *fgets (char *s, int, FILE *stream);

/* Get a newline-terminated string from stdin, removing the newline.
   DO NOT USE THIS FUNCTION!!  There is no limit on how much it will read.  */
char *gets (char *s);

/* Write a string to STREAM.  */
int fputs (const char *s, FILE *stream);

/* Write a string, followed by a newline, to stdout.  */
int puts (const char *s);

/* Push a character back onto the input buffer of STREAM.  */
int ungetc (int c, FILE *stream);

/* Read chunks of generic data from STREAM.  */
size_t fread (void *ptr, size_t size,
		     size_t n, FILE *stream);
/* Write chunks of generic data to STREAM.  */
size_t fwrite (const void *ptr, size_t size,
		      size_t n, FILE *s);

/* Seek to a certain position on STREAM.  */
int fseek (FILE *stream, long int off, int whence);
/* Return the current position of STREAM.  */
long int ftell (FILE *stream);
/* Rewind to the beginning of STREAM.  */
void rewind (FILE *stream);

//#include "fpos.h"
//typedef std::fpos<char> fpos_t;
typedef unsigned  fpos_t;
/* Get STREAM's position.  */
int fgetpos (FILE *stream, fpos_t *pos);
/* Set STREAM's position.  */
int fsetpos (FILE *stream, const fpos_t *pos);

/* Clear the error and EOF indicators for STREAM.  */
void clearerr (FILE *stream);
/* Return the EOF indicator for STREAM.  */
int feof (FILE *stream);
/* Return the error indicator for STREAM.  */
int ferror (FILE *stream);

/* Print a message describing the meaning of the value of errno.  */
void perror (const char *s);

/* ebd3: added filno */
int fileno(FILE*);

/* ebd3: added dfopen - 27July2004 */
FILE *fdopen(int fildes, const char *mode);

using std::off_t;
int fseeko(FILE *stream, off_t offset, int whence);

off_t ftello(FILE *stream);

#endif /* !_STDIO_H */
