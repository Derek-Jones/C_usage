#!/usr/bin/perl -w

#
# Authors: Tanton Gibbs
#          Nick Kraft
#
# Last Modified: 5 July 2004
#
# Usage: key-wc (directory)+
#
# Purpose: count the number of source lines in the given directories
#

use strict;
use File::Find;

my $loc = 0;

sub countLines
{
  # if the filename ends in .cpp .treecc .btyacc .flex
  # then continue
  # else return
  return unless -f $_ and $_ =~ /\.cpp$|\.h$|\.y$|\.l$|\.tc$/;

  open FILE, $_ or die "Could not open $_: $!\n";

  while( <FILE> )
  {
    chomp;
    # increment $loc unless the current line is:
    #   blank
    #   a // comment
    #   a preprocessor statement beginning with '#i', '#e', or '#l' where
    #     there may be unlimited spaces before and after the '#'
    #
    ++$loc unless /^$|^\s*\/\/.*$|^\s*\#\s*i.*$|^\s*\#\s*e.*$|^\s*\#\s*l.*$/;
  }
}

#
# find( \&mysubroutine, 'dir1', 'dir2'...);
#
# foreach directory with root dir1, dir2, ...
#   call mysubroutine ($_ in mysubroutine will be the file name)
#
find( \&countLines, @ARGV );

print "LOC: ", $loc, "\n";
