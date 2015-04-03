#!/usr/bin/perl
use strict;
use warnings;

while ( <> )
{
  chomp;
  if ( /\A([^,]+),\s?([^,]+),\s*([^,]+),?\s+([A-Z][A-Z])\s+(\d{5})(-\d{4})?\Z/ )
  {
    my ($name, $address, $city, $state, $zip, $zip_plus_4) = ($1, $2, $3, $4, $5, $6);
    print "Name: $name\n";
    print "Address: $address\n";
    print "City: $city\n";
    print "State: $state\n";
    print "Zip Code: $zip";
    print $zip_plus_4 if $zip_plus_4;
    print "\n", "-" x 10, "\n";
  }
}
