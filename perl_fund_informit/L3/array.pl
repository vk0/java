#!/usr/bin/perl
use strict;
use warnings;

my @muses = qw(Calliope Clio Erato Euterpe Melpomene
               Polyhymnia Terpsichore Thalia Urania);
print "Muses = @muses\n";

my @workdays     = qw(Monday Tuesday Wednesday Thursday Friday);
my @weekend_days = qw(Saturday Sunday);
my @weekdays     = (@workdays, @weekend_days);
print "Weekdays: @weekdays\n";

my @sith_lords = ("Darth Maul", "Darth Sidious", "Darth Tyranus", "Darth Vader");

while ( @sith_lords )
{
  my $dark_one = shift @sith_lords;
  print "What is thy bidding, $dark_one?\n";
}
