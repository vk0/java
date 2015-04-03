#!/usr/bin/perl
use strict;
use warnings;

my $INPUT_FILE = 'lines';
open my $fh, '<', $INPUT_FILE or die "Unable to open $INPUT_FILE: $!\n";

while ( <$fh> )
{
  chomp;
  my @words = split ' ';
  for ( @words )
  {
    print;
    print " ";
  }
}
print "\n";
