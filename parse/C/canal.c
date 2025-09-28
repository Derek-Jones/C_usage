                      /* canal.c, 17 Feb 12 */

/*
 * Count constructs in the visible form of C source code.
 *
 * Written by Derek Jones to obtain typical developer usage
 * information for the 'cultural' aspects of the book
 * "The New C Standard: An economic and cultural commentary".
 *
 * Copyright (c) 2001-2012 Knowledge Software Ltd
 *
 */

/*
   17 Sep 07 DJ Support C++ keywords and ::
    2 Nov 06 DJ TOK_T_DEF_NAME not needed as a token
   12 Mar 05 DJ Minor updates
   26 Aug 03 DJ Initial release
 */

/*
 * The economic requirements for the production of this software
 * were driven by the need to produce data for use in a book.  A
 * cost/benefit analysis showed that it was not worthwhile investing
 * time during production to save time later, after the book had been
 * published, on maintenance.  Enjoy.
 */

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "options.h"
#include "singlefile.h"
#include "chkfiles.h"


int main(int argc, char **argv)
{
init(argc, argv);
process_arg_files();

print_usage();

return 0;
}

