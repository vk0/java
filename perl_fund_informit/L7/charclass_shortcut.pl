#!/usr/bin/perl
use strict;
use warnings;

my $DATA_FILE = 'data';

my $animal_type = shift or die "Usage: $0 animal_type\n";

my (%food_for, %inventory);
open my $fh, '<', $DATA_FILE or die "Can't open $DATA_FILE: $!\n";
while ( <$fh> )
{
  if ( $_ =~ /\d/ )
  {
    my ($count, $type) = split;
    $inventory{$type} = $count;
  }
  else
  {
    my ($type, $pet) = split;
    $food_for{$pet} = $type;
  }
}

$food_for{$animal_type} && $inventory{ $food_for{$animal_type} } or die "Insufficient data\n";
print "Inventory on hand for $animal_type = $inventory{ $food_for{$animal_type} }\n";
