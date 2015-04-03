#!/usr/bin/perl
use strict;
use warnings;

my ($line_count, $word_count);

my $filename = shift or die "Usage: $0 filename\n";
my $fh;
open $fh, '<', $filename or die "Can't open $filename: $!\n";
while ( my $line = <$fh> )
{
  my @words = split ' ', $line;
  $word_count += @words;
  $line_count++;
}

print "Lines = $line_count; Words = $word_count\n";
close $fh or die "Problem with closing $filename: $!\n";
