#!/usr/bin/perl
use strict;
use warnings;

my $date = "21-11-2008";

my @months = qw(Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec);

my $day       = substr $date, 0, 2;
my $month_num = substr $date, 3, 2;
my $year      = substr $date, 6;

print "Date is $months[$month_num - 1] $day, $year\n";
