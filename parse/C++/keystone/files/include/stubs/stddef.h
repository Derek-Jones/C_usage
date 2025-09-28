
#ifndef _CSTDDEF_H
#define _CSTDDEF_H

#define NULL 0
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

typedef unsigned int size_t;
typedef int ptrdiff_t;
typedef int off_t;

#endif
