#!/usr/bin/perl -w
#
# Input: File listing an inheritance hierarchy in a simple, flexible format
# Output: File listing the inheritance hierarchy in dot format
#
# Notes: No error checking (e.g. multiple definitions, def before use)
#

use strict;
use warnings;

my $argc = scalar @ARGV;
if ( ! $argc )
{
  print "USAGE: $0 FILE\n";
}

foreach my $arg ( @ARGV )
{
  if ( $arg !~ /.ih$/ )
  {
    print "Unrecognized file type: $arg\n";
    exit 1;
  }

  my ( $dot ) = $arg =~ m/(.*)\.ih$/;
  $dot .= ".dot";

  open IH, "$arg" or die "Open $arg failed: $!\n";
  open DOT, "> $dot" or die "Open $dot failed: $!\n";

  print DOT "digraph\n{\n";
  print DOT "  rankdir = \"LR\"\n";

  my $nodes = 0;
  foreach my $line ( <IH> )
  {
    chomp $line;
    next if $line =~ m/^$|^#.*$/;

    # Find class name
    $line =~ s/^([a-zA-Z]\w*)//;
    my $class = $1;

    $nodes++;

    # Find names of base classes
    my @baseClasses;
    while ( $line =~ m/([a-zA-Z]\w*)/g )
    {
      push @baseClasses, $1;
    }

    print DOT "  \"$class\"[ shape = \"rectangle\" ];\n";
    foreach my $baseClass ( @baseClasses )
    {
      # Print in reverse (assumes hierarchy is defined top-down)
      print DOT "  \"$baseClass\" -> \"$class\" [ dir = back, arrowtail = onormal ];\n";
    }
  }
  print DOT "}";
  close DOT;

  print "Number of nodes: $nodes\n";
}

