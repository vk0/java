#!/usr/bin/perl
use strict;
use warnings;

while ( my $line = <> )
{
  chomp $line;
  if ( $line =~ /\d\.\d+[eE]\d+/ )
  {
    print "'$line' contains a number in scientific notation\n";
  }
  elsif ( $line =~ /\d+\.\d*/ )
  {
    print "'$line' contains a floating point number\n";
  }
  elsif ( $line =~ /\w+,\s+[A-Z][A-Z]\s+\d{5}/ )
  {
    print "'$line' looks like part of an address\n";
  }
  elsif ( $line =~ /\d+/ )
  {
    print "'$line' contains an integer\n";
  }
  else
  {
    print "'$line' contains something else\n";
  }
}
