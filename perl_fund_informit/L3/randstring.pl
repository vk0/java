#!/usr/bin/perl
use strict;
use warnings;

my $string = '';

my $length = 10 + rand 10;
print "Forming random string of length $length\n";

my @chars = ( 'A' .. 'Z', 'a' .. 'z' );
while ( length $string < $length )
{
  $string .= $chars[ rand @chars ];
}

print "Resulting string = $string\n";
