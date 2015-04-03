#!/usr/bin/perl
use strict;
use warnings;

printf "%-10s %-10s %-7s\n", "Date", "Species", "Price";
my ($day, $month, $year, $species, $price);
my $format = "%d-%02d-%02d %-10.10s %7.2f\n";

$day = 3; $month = 8; $year = 2008; $species = "Cavy"; $price = 250;
printf $format, $year, $month, $day, $species, $price;

$day = 12; $month = 8; $year = 2008; $species = "Wallaby"; $price = 900;
printf $format, $year, $month, $day, $species, $price;

$day = 8; $month = 10; $year = 2008; $species = "Millipede"; $price = 1.23;
printf $format, $year, $month, $day, $species, $price;

$day = 12; $month = 11; $year = 2008; $species = "African Grey Parrot"; $price = 1200;
printf $format, $year, $month, $day, $species, $price;

