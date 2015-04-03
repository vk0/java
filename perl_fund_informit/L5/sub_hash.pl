#!/usr/bin/perl
use strict;
use warnings;

my @keys = qw(Ford Carter Reagan Bush Clinton Bush Obama);
my @values = (38 .. 44);

my %ordinal;

@ordinal{@keys} = @values;

for my $key (keys %ordinal)
{
  printf "%-8s -> %s\n", $key, $ordinal{$key};
}

