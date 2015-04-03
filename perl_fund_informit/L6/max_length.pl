#!/usr/bin/perl
use strict;
use warnings;

my $max_length = 0;
while ( my $line = <> )
{
  chomp $line;
  $max_length = length($line) if length($line) > $max_length;
}

print "Longest line was $max_length characters long\n";
