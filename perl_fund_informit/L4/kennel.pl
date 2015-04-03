#!/usr/bin/perl
use strict;
use warnings;

my %kennel = ( 'Rex' => 'D17', 'Rover' => 'E21', 'Spot' => 'B12', 'Rin Tin Tin' => 'B6' );
$kennel{Lassie} = 'A1';

for my $dog (sort keys %kennel)
{
  print "$dog is located in $kennel{$dog}\n";
}

print "-" x 10, "\n";

my %dog = reverse %kennel;

for my $kennel (sort keys %dog)
{
  print "$kennel contains $dog{$kennel}\n";
}
