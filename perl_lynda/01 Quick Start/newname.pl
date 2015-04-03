#!/usr/bin/perl
# countlines.pl by Bill Weinman <http://bw.org/contact/>
# Copyright (c) 2010 The BearHeart Group, LLC
#
use strict;
use warnings;

my $filename = "linesfile.txt"; # the name of the file

open(FH, $filename);    # open the file
my @lines = <FH>;       # read the file
close(FH);              # close the file

my $count = scalar @lines;  # the number of lines in the file
print("There are $count lines in $filename\n");

