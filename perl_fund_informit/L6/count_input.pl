#!/usr/bin/perl
use strict;
use warnings;

my ($line_count, $word_count);

while ( my $line = <> )
{
  my @words = split ' ', $line;
  $word_count += @words;
  $line_count++;
}

print "Lines = $line_count; Words = $word_count\n";
