/* report.c -- search hash lists for common matches */

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include "shred.h"

#define min(x, y)	((x < y) ? (x) : (y)) 
#define max(x, y)	((x > y) ? (x) : (y)) 

struct match_t
{
    int            nmatches;
    struct sorthash_t *matches;
};

static int merge_ranges(struct sorthash_t *p, 
			struct sorthash_t *q,
			int nmatches)
/* merge p into q, if the ranges in the match are compatible */
{
    int	i, mc, overlap;
    
    /*
     * The general problem: you have two lists of shreds, of the same
     * lengths.  Within each list, all shreds have the same hash.
     * Within the lists, the shreds are sorted in filename order.
     * 
     * There are two possible overlap cases.  Either the start line of
     * each range in p is within the corresponding range in q or
     * vice-versa.  If we know all pairs of shreds intersect, we
     * assume they intersect in the same way because the same 
     * hash pair (the same text) is involved each time.
     */
    overlap = 0;
    mc = 0;
    for (i = 0; i < nmatches; i++)
	if (p[i].hash.start >= q[i].hash.start && p[i].hash.start <= q[i].hash.end)
	    mc++;
	else
	    break;
    if (mc == nmatches)
	overlap = 1;
    mc = 0;
    for (i = 0; i < nmatches; i++)
	if (q[i].hash.start >= p[i].hash.start && q[i].hash.start <= p[i].hash.end)
	    mc++;
	else
	    break;
    if (mc == nmatches)
	overlap = 1;
    if (!overlap)
    {
#ifdef DEBUG
	printf("Intervals don't intersect\n");
#endif /* DEBUG */
	return(0);
    }

    /* merge attempt successful */
    for (i = 0; i < nmatches; i++)
    {
	p[i].hash.start = min(p[i].hash.start, q[i].hash.start);
	p[i].hash.end   = max(p[i].hash.end, q[i].hash.end);
    }
    return(1);
}

static int sametree(const char *s, const char *t)
/* are two files from the same tree? */
{
    int sn = strchr(s, '/') - s;
    int tn = strchr(t, '/') - t;

    return (sn == tn) && !strncmp(s, t, sn); 
}

static int compare_files(const void *a, const void *b)
/* sort by files shred is included in */
{
    struct match_t *s = ((struct match_t *)a);
    struct match_t *t = ((struct match_t *)b);
    int i;

    /* two cliques of different length can never match */
    if (s->nmatches - t->nmatches)
	return(s->nmatches - t->nmatches);

    /* sort by file */
    for (i = 0; i < s->nmatches; i++)
    {
	int cmp = strcmp(s->matches[i].file->name, t->matches[i].file->name);

	if (cmp)
	    return(cmp);
    }

    return(0);
}

static int collapse_ranges(struct match_t *reduced, int nonuniques)
/* collapse together overlapping ranges in the hit list */
{ 
    struct match_t *sp, *tp;
    int spancount, removed = 0;

    /*
     * For two matches to be eligible for merger, all their filenames must
     * match pairwise.  If there are no such matches, these chunks are
     * completely irrelevant to each other.  It might be that for some
     * values of i the filenames are equal and for others not.  In
     * that case the pair of lists of ranges cannot represent the same
     * overlapping segments of text, which is the only case we are
     * interested in.
     *
     * This gives us leverage to apply the qsort trick again.  The naive
     * way to check for range overlaps would be to write a quadratic
     * double loop compairing all matches pairwise.  Instead we can
     * use this sort to partition the matches into spans such that
     * all overlaps must take place within spans.
     */
    qsort(reduced, nonuniques, sizeof(struct match_t), compare_files);

#ifdef DEBUG
    for (sp = reduced; sp < reduced + nonuniques; sp++)
    {
	 struct sorthash_t	*rp;

	 printf("Clique beginning at %d:\n", sp - reduced);
	 for (rp = sp->matches; rp < sp->matches + sp->nmatches; rp++)
	     printf("%s:%d:%d\n",  rp->file->name, rp->hash.start, rp->hash.end);
    }
#endif /* DEBUG */

    /* time to merge overlapping shreds */
    spancount = 0;
    for (sp = reduced; sp < reduced + nonuniques; sp++, spancount--)
    {
	int remaining;

	/*
	 * This optimization drastically reduces the number of compare_files
	 * calls.  The continue condition in the inner loop below would 
	 * otherwise involve one every time for O(n**2) calls; this reduces
	 * the number to O(n).
	 */
	if (spancount <= 0)
	{
	    spancount = 0;
	    for (tp = sp + 1; 
		 !compare_files(sp, tp) && tp < reduced + nonuniques; 
		 tp++)
		spancount++;
	}

	for (tp = sp + 1, remaining = spancount; remaining--; tp++)
	{
#ifdef DEBUG
	    printf("Trying merge of %d into %d\n", tp-reduced, sp-reduced);
#endif /* DEBUG */
	    /* neither must have been deleted */
	    if (!sp->nmatches || !tp->nmatches)
	    {
#ifdef DEBUG
		printf("Null match pointer: %d=%p, %d=%p\n", 
		       sp-reduced, sp->matches, tp-reduced, tp->matches);
#endif /* DEBUG */

		continue;
	    }

	    /* attempt the merge */
	    if (merge_ranges(tp->matches, sp->matches, sp->nmatches))
	    {		 
#ifdef DEBUG
		struct sorthash_t	*rp;

		printf("*** Merged %d into %d\n", tp-reduced, sp-reduced);
		for (rp=sp->matches; rp < sp->matches+sp->nmatches; rp++)
		    printf("%s:%d:%d\n",rp->file->name,rp->hash.start,rp->hash.end);
#endif /* DEBUG */
		removed++;
		sp->nmatches = 0;
	    }
	}
    }

#ifdef DEBUG
    for (sp = reduced; sp < reduced + nonuniques; sp++)
    {
	struct sorthash_t	*rp;

	printf("Clique beginning at %d (%d):\n", sp - reduced, sp->nmatches);
	for (rp = sp->matches; rp < sp->matches + sp->nmatches; rp++)
	    printf("%s:%d:%d\n",  rp->file->name, rp->hash.start, rp->hash.end);
    }
#endif /* DEBUG */

    return(nonuniques - removed);
}

struct match_t *reduce_matches(struct sorthash_t *obarray, int *hashcountp)
/* assemble list of duplicated hashes */
{
     unsigned int nonuniques, nreduced, progress, hashcount = *hashcountp;
     struct sorthash_t *mp, *np;
     struct match_t	*reduced;

     if (debug)
	 dump_array("Chunk list before reduction.\n",obarray, hashcount);

     /*
      * To reduce the size of the in-core working set, we do a a
      * pre-elimination of duplicates based on hash key alone, in
      * linear time.  This may leave in the array hashes that all
      * point to the same tree.  We'll discard those in the next
      * phase.  This costs less time than one might think; without it,
      * the clique detector in the next phase would have to do an
      * extra HASHCMP per array slot to detect clique boundaries.  Net
      * cost of this optimization is thus *one* HASHCMP per entry.
      * The benefit is that it kicks lots of shreds out, reducing the
      * total working set at the time we build match lists.  The idea
      * here is to avoid swapping, because typical data sets are so
      * large that handling them can easily kick the VM into
      * thrashing.
      *
      * The technique: first mark...
      */
     if (HASHCMP(obarray, obarray+1))
	 obarray[0].hash.start = UNIQUE_FLAG;
     for (np = obarray+1; np < obarray + hashcount-1; np++)
	 if (HASHCMP(np, np-1) && HASHCMP(np, np+1))
	     np->hash.start = UNIQUE_FLAG;
     if (HASHCMP(obarray+hashcount-2, obarray+hashcount-1))
	 obarray[hashcount-1].hash.start = UNIQUE_FLAG;
     /* ...then sweep. */
     for (mp = np = obarray; np < obarray + hashcount; np++)
	 if (np->hash.start != UNIQUE_FLAG)
	     *mp++ = *np;
     /* now we get to reduce the memory footprint */
     report_time("Compaction reduced %d shreds to %d", 
		 hashcount, mp - obarray);
     hashcount = mp - obarray;
     obarray = (struct sorthash_t *)realloc(obarray, 
			    sizeof(struct sorthash_t)* hashcount);

     if (debug)
	 dump_array("Chunk list after reduction.\n",obarray, hashcount);

     /* build list of hashes with more than one range associated */
     nonuniques = progress = 0;
     if (verbose)
	 fprintf(stderr, "%% Extracting duplicates...   ");
     nreduced = 10000;
     reduced = (struct match_t *)malloc(sizeof(struct match_t) * nreduced);
     for (np = obarray; np < obarray + hashcount; np = mp)
     {
	 int i, heterogenous, nmatches;

	 if (verbose && !debug && progress++ % 10000 == 0)
	     fprintf(stderr, "\b\b\b%02.0f%%", progress / (hashcount * 0.01));

	 /* count the number of hash matches */
	 nmatches = 1;
	 for (mp = np+1; mp < obarray + hashcount; mp++)
	     if (HASHCMP(np, mp))
		 break;
	     else
		 nmatches++;

	 /* if all these matches are within the same tree, toss them */
	 heterogenous = 0;
	 for (i = 0; i < nmatches; i++)
	     if (!sametree(np[i].file->name, np[(i+1) % nmatches].file->name))
		 heterogenous++;
	 if (!heterogenous)
	     continue;

	 if (debug)
	 {
	     printf("*** %d has %d in its clique\n", np-obarray, nmatches);
	     for (i = 0; i < nmatches; i++)
		 printf("%d: %s:%d:%d\n", 
			np-obarray+i, np[i].file->name, np[i].hash.start, np[i].hash.end);
	 }

	 /* passed all tests, keep this set of ranges */
	 if (nonuniques >= nreduced)
	 {
	     nreduced *= 2;
	     reduced = (struct match_t *)realloc(reduced,
						 sizeof(struct match_t)*nreduced);
	 }
	 /*
	  * Point into the existing hash array rather than allocating
	  * new storage.  This means our working set won't get any
	  * smaller, but it avoids the time overhead of doing a bunch
	  * of malloc and free calls.
	  */
	 reduced[nonuniques].matches = np;
	 reduced[nonuniques].nmatches = nmatches;
	 nonuniques++;
     }
     if (verbose)
	 fprintf(stderr, "\b\b\b100%% done.\n");

     *hashcountp = nonuniques;
     return reduced;
}

static int sortmatch(const void *a, const void *b)
/* sort by file and first line */
{
    struct sorthash_t *s = ((struct match_t *)a)->matches;
    struct sorthash_t *t = ((struct match_t *)b)->matches;
    int i;

    /* first sort by file */
    for (i = 0; i < ((struct match_t *)a)->nmatches; i++)
    {
	int cmp = strcmp(s[i].file->name, t[i].file->name);

	if (cmp)
	    return(cmp);
    }

    /* then sort by start line number */
    for (i = 0; i < ((struct match_t *)a)->nmatches; i++)
    {
	int cmp = s->hash.start - t->hash.start;

	if (cmp)
	    return(cmp);
    }

    return(0);
}

void emit_report(struct sorthash_t *obarray, int hashcount)
/* report our results */
{
    struct match_t *hitlist, *match, *copy;
    int mergecount;

    hitlist = reduce_matches(obarray, &hashcount);
    if (debug)
	dump_array("After removing uniques.\n", obarray, hashcount);
    report_time("%d range groups after removing unique hashes", hashcount);
    mergecount = collapse_ranges(hitlist, hashcount);
    report_time("%d range groups after merging", mergecount);

    /*
     * A little extra effort so we can generate a sirted report.
     * Compact the match list in order to cut the n log n qsort time
     */
    for (copy = match = hitlist; match < hitlist + hashcount; match++)
	if (match->nmatches && copy < match)
	    *copy++ = *match;
    qsort(hitlist, mergecount, sizeof(struct match_t), sortmatch);

    for (match = hitlist; match < hitlist + mergecount; match++)
    {
	int	i;

	for (i=0; i < match->nmatches; i++)
	{
	    struct sorthash_t	*rp = match->matches+i;

	    printf("%s:%d:%d:%d\n", 
		   rp->file->name, 
		   rp->hash.start, rp->hash.end,
		   rp->file->length
		);
	}
	printf("%%%%\n");
    }
    /* free(hitlist); */
}

/* report.c ends here */
