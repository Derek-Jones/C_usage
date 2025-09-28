#ifndef _WCTYPE_H
#define _WCTYPE_H

typedef unsigned int wint_t;

# ifndef WEOF
#  define WEOF (0xffffffffu)
# endif

/* Scalar type that can hold values which represent locale-specific
   character classifications.  */
typedef unsigned long int wctype_t;

/*
 * Wide-character classification functions: 7.15.2.1.
 */

/* Test for any wide character for which `iswalpha' or `iswdigit' is
   true.  */
int iswalnum (wint_t wc);

/* Test for any wide character for which `iswupper' or 'iswlower' is
   true, or any wide character that is one of a locale-specific set of
   wide-characters for which none of `iswcntrl', `iswdigit',
   `iswpunct', or `iswspace' is true.  */
int iswalpha (wint_t wc);

/* Test for any control wide character.  */
int iswcntrl (wint_t wc);

/* Test for any wide character that corresponds to a decimal-digit
   character.  */
int iswdigit (wint_t wc);

/* Test for any wide character for which `iswprint' is true and
   `iswspace' is false.  */
int iswgraph (wint_t wc);

/* Test for any wide character that corresponds to a lowercase letter
   or is one of a locale-specific set of wide characters for which
   none of `iswcntrl', `iswdigit', `iswpunct', or `iswspace' is true.  */
int iswlower (wint_t wc);

/* Test for any printing wide character.  */
int iswprint (wint_t wc);

/* Test for any printing wide character that is one of a
   locale-specific et of wide characters for which neither `iswspace'
   nor `iswalnum' is true.  */
int iswpunct (wint_t wc);

/* Test for any wide character that corresponds to a locale-specific
   set of wide characters for which none of `iswalnum', `iswgraph', or
   `iswpunct' is true.  */
int iswspace (wint_t wc);

/* Test for any wide character that corresponds to an uppercase letter
   or is one of a locale-specific set of wide character for which none
   of `iswcntrl', `iswdigit', `iswpunct', or `iswspace' is true.  */
int iswupper (wint_t wc);

/* Test for any wide character that corresponds to a hexadecimal-digit
   character equivalent to that performed be the functions described
   in the previous subclause.  */
int iswxdigit (wint_t wc);

/*
 * Extensible wide-character classification functions: 7.15.2.2.
 */

/* Construct value that describes a class of wide characters identified
   by the string argument PROPERTY.  */
wctype_t wctype (const char *property);

/* Determine whether the wide-character WC has the property described by
   DESC.  */
int iswctype (wint_t wc, wctype_t desc);

/*
 * Wide-character case-mapping functions: 7.15.3.1.
 */

/* Scalar type that can hold values which represent locale-specific
   character mappings.  */
typedef const long *wctrans_t;

/* Converts an uppercase letter to the corresponding lowercase letter.  */
wint_t towlower (wint_t wc);

/* Converts an lowercase letter to the corresponding uppercase letter.  */
wint_t towupper (wint_t wc);

/* Construct value that describes a mapping between wide characters
   identified by the string argument PROPERTY.  */
wctrans_t wctrans (const char *property);

/* Map the wide character WC using the mapping described by DESC.  */
wint_t towctrans (wint_t wc, wctrans_t desc);

#endif /* wctype.h  */
