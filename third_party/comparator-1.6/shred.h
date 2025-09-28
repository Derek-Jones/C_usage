/* shred.h -- types for shred similarity tools */

#include <sys/types.h>
#include <netinet/in.h>

#ifndef LARGEFILES
/*
 * 65,536 lines should be enough, but make it possible to compile with 32 bits.
 * The point of making it a short is that the data sets can get quite large,
 * so we want the hash_t and sorthash_t structures to be small.
 */
typedef u_int16_t	linenum_t;
#define TONET		htons
#define FROMNET		ntohs
#else
typedef u_int32_t	linenum_t;
#define TONET		htonl
#define FROMNET		ntohl
#endif
#define MAX_LINENUM	(linenum_t)-1	/* 2s-complement assumption */
#define UNIQUE_FLAG	MAX_LINENUM	/* 2s-complement assumption */

/* use this to hold total line count of the entire source tree set */
typedef u_int32_t	linecount_t;

#define HASHSIZE	16
struct hash_t
{
    linenum_t   	start, end;
    unsigned char	hash[HASHSIZE];
};
#define HASHCMP(s, t)	memcmp((s)->hash.hash, (t)->hash.hash, HASHSIZE)

struct filehdr_t
{
    char	*name;
    linenum_t	length;
    struct filehdr_t *next;
};

struct sorthash_t
{
    struct hash_t	hash;
    struct filehdr_t	*file;
};

/* control bits, meant to be set at startup */
extern int remove_braces;
extern int remove_whitespace;
extern int remove_comments;
extern int verbose, debug;
extern int shredsize;

/* main.c functions */
extern void report_time(char *legend, ...);
struct filehdr_t *register_file(const char *file, linenum_t length);
extern void corehook(struct hash_t hash, struct filehdr_t *file);
extern void extend_current_chunk(void);
extern void dump_array(const char *legend,
		       struct sorthash_t *obarray, int hashcount);

/* shredtree.c functions */
extern char **sorted_file_list(const char *, int *);
extern int shredfile(struct filehdr_t *, 
		     void (*hook)(struct hash_t, struct filehdr_t *));
extern void sort_hashes(struct sorthash_t *hashlist, int hashcount);

/* shredcompare.c functions */
extern void emit_report(struct sorthash_t *obarray, int hashcount);

/* shred.h ends here */
