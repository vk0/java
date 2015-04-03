#!/usr/bin/perl
use strict;
use warnings;

my $DEAD = 0;
my $LIVE = 1;

my $cell = $LIVE;
my $neighbors = 4;

if ( $cell == $LIVE )
{
  if ( $neighbors >  3 || $neighbors < 2 )
  {
    print "Cell dies\n";
  }
  else
  {
    print "Cell survives\n";
  }
}
elsif ( $neighbors == 3 )
{
  print "Cell is born\n";
}

