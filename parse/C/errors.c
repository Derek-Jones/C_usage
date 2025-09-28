                          /* errors.c, 20 Jan 10 */

#include <stdarg.h>
#include <stdio.h>

#include "global.h"


void print_warning(char *msg, ...)
{
va_list ap;

va_start(ap, msg);
printf("Warning: ");
vprintf(msg, ap);

va_end(ap);
}


void print_error(char *msg, ...)
{
va_list ap;

va_start(ap, msg);
printf("Error: ");
vprintf(msg, ap);

va_end(ap);
}

