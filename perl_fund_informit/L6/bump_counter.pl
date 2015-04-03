#!/usr/bin/perl
use strict;
use warnings;

my $COUNTER_FILE = 'counter';

my $count;
if ( open my $fh, '<', $COUNTER_FILE )
{
  $count = <$fh>;
  chomp $count;
  $count++;
  print "Count now $count\n";
  # $fh closed automatically here
}
else
{
  $count = 0;
}

open my $fh, '>', $COUNTER_FILE or die "Couldn't open $COUNTER_FILE: $!\n";
print {$fh} "$count\n";
