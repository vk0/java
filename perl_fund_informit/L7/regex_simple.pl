#!/usr/bin/perl
use strict;
use warnings;

for my $arg (@ARGV)
{
  print "$arg ", ($arg =~ /dog/ ? "matches" : "doesn't match"), " /dog/\n";
  if ( $arg =~ s/dog/cat/ )
  {
    print "   After substitution: $arg\n";
  }
  else
  {
    print "   Substitution failed\n";
  }
}
