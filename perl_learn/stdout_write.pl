#!/usr/bin/perl
use strict;
# пример 1
open FID, ">output1.txt" # один знак "больше"
   or die "Failed to open output1.txt: $!\n";
print FID "111\n"; # обратите внимание - запятой нет
close FID;

# пример 2
open FID, ">>output1.txt" # два знака "больше"
   or die "Failed to open output2.txt: $!\n";
print FID "222\n";
close FID;
