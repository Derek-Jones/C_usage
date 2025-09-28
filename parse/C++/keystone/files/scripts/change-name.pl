#!/usr/bin/perl -w

use strict;
use warnings;

use Cwd;
use File::Find;

#---------------------------------------
# Globals
#---------------------------------------
my $count = 0;

#---------------------------------------
# Procedures
#---------------------------------------
sub pushIfSrc
{
  if ( /^(Actions|Ast)/ )
  {
    ++$count;

    my $filename = $File::Find::name;
    open SRC, $filename or die "Could not open $filename: $!\n";
    my @src = <SRC>;
    close SRC;

    open SRC, ">$filename" or die "Could not open $filename: $!\n";
    foreach ( @src )
    {
      s/$ARGV[0]/$ARGV[1]/g;
      print SRC;
    }
    close SRC;
  }
}

#---------------------------------------
# Main
#---------------------------------------
if ( scalar @ARGV != 2 )
{
  print "Usage: $0 FROM TO\n";
  exit 1;
}

find \&pushIfSrc, cwd;

#print "Number of files: $count\n";

