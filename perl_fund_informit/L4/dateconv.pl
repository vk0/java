#!/usr/bin/perl
use strict;
use warnings;

my %number_of_month = ( Jan => 1, Feb => 2, Mar => 3, Apr =>  4, May =>  5, Jun =>  6,
	                Jul => 7, Aug => 8, Sep => 9, Oct => 10, Nov => 11, Dec => 12 );

my $date = shift or die "Usage: $0 date\n";   # Example: 03-Mar-2009

my $day   = substr $date, 0, 2;
my $month = substr $date, 3, 3;
my $year  = substr $date, 7;

my $monthnum = $number_of_month{$month} or die "Unrecognized month $month\n";

print "$date -> $monthnum/$day/$year\n";

