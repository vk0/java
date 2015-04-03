#!/usr/bin/perl
use strict;
use warnings;

my @continents = ("North America", "South America", "Europe", "Africa", "Asia", "Australia");
my @oceans = qw(Indian Pacific Atlantic Arctic);

print "The continents are: @continents\n";
print "The oceans are:     @oceans\n";

my $am = "America";
@continents = ("North $am", "South $am", qw(Europe Africa Asia Australia));
print "The continents are: @continents\n";
