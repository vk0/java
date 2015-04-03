#!/usr/bin/perl
# newfeat.pl by Bill Weinman <http://bw.org/contact/>
# Copyright (c) 2010 The BearHeart Group, LLC
#
use strict;
use warnings;
use feature ":5.10";

main(@ARGV);

sub main
{
    say "This is the Perl 5.10 new features exercise file.";
}

sub error
{
    my $e = shift || 'unkown error';
    my $me = ( split(/[\\\/]/, $0 ) )[-1];
    print("$me: $e\n");
    exit 0;
}

