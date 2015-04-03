#!/usr/bin/perl
use strict;
use warnings;

my $USAGE = "Usage: $0 input_file\n";

my $input_file = init();

# ...
# ...
# ...

sub init
{
  @ARGV or die $USAGE;
  my $filename = shift @ARGV;
  -f $filename or die "$filename doesn't exist or is not a regular file\n";
  return $filename;
}
