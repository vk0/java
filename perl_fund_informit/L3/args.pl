#!/usr/bin/perl
use strict;
use warnings;

print "Command line arguments: @ARGV\n";

my $argument;
while ( $argument = shift @ARGV )
{
  print "Next argument = '$argument'\n";
}
