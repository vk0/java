#!/usr/bin/perl
use strict;
use warnings;

my $variable = "aardvark";
my $single = 'A variable: $variable - and - \t\t - an escape sequence ';
my $double = "A variable: $variable - and - \t\t - an escape sequence ";
print "Single quotes: $single\n";
print "Double quotes: $double\n";
