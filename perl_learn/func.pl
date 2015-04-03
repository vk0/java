#/usr/bin/perl
use strict;

sub myfunc {
   my($alpha, $beta) = @_;
      $alpha + $beta;
      }

      print myfunc(2, 3)."\n";
