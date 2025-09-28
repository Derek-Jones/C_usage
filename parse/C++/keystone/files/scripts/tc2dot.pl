#!/usr/bin/perl -w
#
# Convert class hierarchy defined in treecc file to dot format
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
  if ( $arg !~ /.tc$/ )
  {
    print "Unrecognized file type: $arg\n";
    exit 1;
  }

  my ( $dot ) = $arg =~ m/(.*)\.tc$/;
  $dot .= ".dot";

  open TC, "$arg" or die "Open $arg failed: $!\n";
  open DOT, "> $dot" or die "Open $dot failed: $!\n";

  my @tc = <TC>;

  my @nodes;
  foreach my $line ( @tc )
  {
    if ( $line =~ /\%node/ )
    {
      chomp $line;
      push @nodes, $line;
    }
  }

  print DOT "digraph\n{\n";
  print DOT "  rankdir = \"LR\"\n";
  foreach my $node ( @nodes )
  {
    $node =~ s/^\s*\%node\s*//;
    $node =~ s/\%abstract//;
    $node =~ s/\%typedef//;

    $node =~ m/([a-zA-Z]\w*)?\s+([a-zA-Z]\w*)?/;
    my $class     = $1;
    my $baseClass = ( defined $2 ? $2 : "" );

    print DOT "  \"$class\"[ shape = \"rectangle\" ];\n";
    if ( length $baseClass )
    {
      print DOT "  \"$baseClass\" -> \"$class\" [ dir = back, arrowtail = onormal ];\n";
    }
  }
  print DOT "}";
  close DOT;

  print "Number of nodes: " . scalar @nodes . "\n";
}

