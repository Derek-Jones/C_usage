#!/usr/bin/perl -w

use strict;
use warnings;

use File::Find;

my $classes = 0;

sub countClasses
{
  return unless -f $_ and $_ =~ /\.cpp$|\.h$/;

  open FILE, $_ or die "Could not open $_: $!\n";

  while( <FILE> )
  {
    chomp;
    ++$classes if /^class[ a-zA-Z:]*[^;]$/;
  }
}

find( \&countClasses, @ARGV );

print "CLASSES: ", $classes, "\n";

