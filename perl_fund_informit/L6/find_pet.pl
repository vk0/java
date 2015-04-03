#!/usr/bin/perl
use strict;
use warnings;

my $DATA_FILE = 'kennel_report';

@ARGV or die "Usage: $0 pet ...\n";
open my $fh, '<', $DATA_FILE or die "Couldn't open $DATA_FILE: $!\n";

my %location;
while ( my $line = <$fh> )
{
  chomp $line;
  my ($kennel, $pet) = split ' ', $line;
  $location{$pet} = $kennel;
}
while ( my $pet = shift )
{
  if ( my $kennel = $location{$pet} )
  {
    print "$pet -> $kennel\n";
  }
  else
  {
    print "No location found for $pet\n";
  }
}
