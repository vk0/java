#!/usr/bin/perl
use strict;
# создаем файловый дескриптор
open FID, "work1"
   or die "Failed to open work1: $!\n";
   my $i = 0;
   while(<FID>) {
   print "line ".++$i.": $_";
   }
   close FID; # закрываем файловый дескриптор
