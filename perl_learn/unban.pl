#!/usr/bin/perl
#use strict;

my @ban = `cat /tmp/list`;
my @unb = `cat /tmp/list2`;
my %lookup;
my @result;

@lookup{@unb} = ();
foreach my $elem (@ban) {
  push(@result, $elem) unless exists $lookup{$elem};
  }

  print "@result\n";

