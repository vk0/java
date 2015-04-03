#!/usr/bin/perl
use YAML;

my %total_bytes;
while (<>) {
my ($source, $destination, $bytes) = split;
$total_bytes{$source}{$destination} += $bytes;
}
print Dump(\%total_bytes);
