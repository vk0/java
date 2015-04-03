#!/usr/bin/perl
use strict;
opendir DIR, "/tmp" or die $!;
while(my $fname = readdir DIR) {
   print "$fname\n";
   }
   closedir DIR;
