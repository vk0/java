#!/usr/bin/perl
use strict;
use warnings;

sub remove_duplicates
{
  my @results;
  my %seen;
  for my $elem (@_)
  {
    push @results, $elem unless $seen{$elem}++;
  }
  return @results;
}

my @pets = qw(dog cat parrot rabbit cat bird dog aardvark);

print "Before: @pets\n";
@pets = remove_duplicates( @pets );
print "After:  @pets\n";
