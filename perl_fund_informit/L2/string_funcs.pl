#!/usr/bin/perl
use strict;
use warnings;

print "There is a ";
my $beast = "Rhinocrocidae";

if ( length $beast > 20 )
{
  print substr $beast, 0, 20;
}
else
{
  print substr "$beast                  ", 0, 20;
}
print " in cage 6\nThere is a ";
$beast = "Lama pacos";
if ( length $beast > 20 )
{
  print substr $beast, 0, 20;
}
else
{
  print substr "$beast                  ", 0, 20;
}
print " in cage 7\n";
