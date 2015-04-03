#!/usr/bin/perl
use strict;
use warnings;

for my $arg ( @ARGV )
{
  print "$arg ", ($arg =~ /p[aeiou]t/ ? "matches" : "doesn't match"), " /p[aeiou]t/\n";

  if ( $arg =~ s/p[aeiou]t/*match*/ )
  {
    print "   Substitution result for /p[aeiou]t/: $arg\n";
  }
  elsif ( $arg =~ s/[^aeiou]at/*match*/ )
  {
    print "   Substitution result for /[^aeiou]at/: $arg\n";
  }
}
