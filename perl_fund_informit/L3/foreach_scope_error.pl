#!/usr/bin/perl
use strict;
use warnings;

my $rodent = "muskrat";

print "***    Before: $rodent\n";

for my $rodent ( qw(vole beaver gerbil capybara) )
{
  print "Rodent: $rodent\n";
}

print "***    After:  $rodent\n";
