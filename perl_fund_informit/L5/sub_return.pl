#!/usr/bin/perl
use strict;
use warnings;

my %daily_feedings       = ( cat    => 2        );
my %feeding_weight       = ( cat    => 0.4      );
my %food_type            = ( cat    => 'kibble' );
my %cost_per_unit_weight = ( kibble => 0.90     );

for my $pet ( pets_in_shelter() )
{
  print "Daily food cost for a $pet is \$", food_cost( $pet ), "\n";
}

sub food_cost
{
  my $pet = shift;

  exists $daily_feedings{$pet} or die "No such animal $pet";
  return $daily_feedings{$pet} * $feeding_weight{$pet}
       * $cost_per_unit_weight{ $food_type{$pet} };
}

sub pets_in_shelter
{
  return ( 'cat', 'ostrich' );
}
