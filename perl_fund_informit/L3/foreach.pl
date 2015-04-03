#!/usr/bin/perl
use strict;
use warnings;

my @inventory = qw(Cavy Wallaby Millipede);
push @inventory, "African Grey Parrot";

print "We have on hand:\n";
for my $pet ( @inventory )
{
  print "\t$pet\n";
}

my @costs = (250, 900, 1.23, 1200);

for (my $index = 0; $index <= $#inventory; $index++)
{
  print "Cost of $inventory[$index] is \$$costs[$index]\n";
}
