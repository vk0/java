#!/usr/bin/perl
@lines = `perldoc -u -f perldoc`;
foreach (@lines) {
s/\w<([^>]+)>/\U$1/g;
print;
}

