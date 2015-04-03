#!/usr/bin/perl
use strict;
use warnings;

my $string = '';

my $length = 10 + rand 10;
print "Forming random string of length $length\n";

my @chars = ( 'A' .. 'Z', 'a' .. 'z' );
while ( length $string < $length )
{
  my $array_length = @chars;
  my $index = rand $array_length;
  my $letter = $chars[ $index ];
  $string = $string . $letter;
}

print "Resulting string = $string\n";
