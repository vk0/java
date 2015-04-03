#!/usr/bin/perl
use strict;
use warnings;

my @aquatic    = qw(goldfish koi toad dolphin platypus manatee);
my @land_based = (qw(schnauzer platypus capybara toad), 'guinea pig');

my @dual;
{
  my %seen;
  for my $key (@aquatic)
  {
    $seen{$key}++;
  }
  for my $key (@land_based)
  {
    push @dual, $key if $seen{$key};
  }
}

print "Inhabit both land and water: @dual\n";
