#!/usr/bin/perl
use strict;
use warnings;

my $result = bare_return();
print "\$result is ", (defined($result) ? "defined": "not defined"), "\n";

my @results = bare_return();
print "Number of elements in \@results is " . @results, "\n";

sub bare_return
{
  # ... stuff ...
  return;
}
