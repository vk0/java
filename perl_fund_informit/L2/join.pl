#!/usr/bin/perl
use strict;
use warnings;

my $area_code  = "212";
my $exchange   = "867";
my $subscriber = "5309";

print join( '-', $area_code, $exchange, $subscriber ), "\n";
