#!/usr/bin/perl -w
chomp($line = <STDIN>);
#$line = <STDIN>;
if ($line eq "\n") {
print "That was just a blank line!\n";
} else {
print "That line of input was: $line";
}

