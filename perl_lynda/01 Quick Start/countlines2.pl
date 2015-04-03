#!/usr/bin/perl
# countlines2.pl by Bill Weinman <http://bw.org/contact/>
# Copyright (c) 2010 The BearHeart Group, LLC
#
use strict;
use warnings;
use IO::File;

my $filename = "linesfile.txt"; # the name of the file

# open the file - with simple error reporting
my $fh = IO::File->new( $filename, "r" );
if(! $fh) {
    print("Cannot open $filename ($!)\n");
    exit;
}

# count the lines
my $count = 0;
while( $fh->getline ) {
    $count++;
}

# close and print
$fh->close;
print("There are $count lines in $filename\n");

