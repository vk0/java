#!/usr/bin/perl
use strict;
use warnings;

my %cost = (Cavy => 250, Wallaby => 900, Millipede => 1.23, 'African Grey Parrot' => 1200);

for my $pet ( keys %cost )
{
  print "Cost of $pet is \$$cost{$pet}\n";
}
