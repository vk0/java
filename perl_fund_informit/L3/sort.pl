#!/usr/bin/perl
use strict;
use warnings;

my @sorted_strings = sort @ARGV;

my @sorted_numbers = sort { $a <=> $b } @ARGV;

my @reversed_sorted_numbers = sort { $b <=> $a } @ARGV;

print "Sorted strings  : @sorted_strings\n";
print "Sorted numbers  : @sorted_numbers\n";
print "Reversed numbers: @reversed_sorted_numbers\n";
