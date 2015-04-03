#!/usr/bin/perl
use strict;
use warnings;

print_cost( 'emu', 425 );

print_cost( llama => 700 );

my $pet = 'orangutan'; my $value = 12000;
print_cost( $pet, $value );

my %single_pet_cost = ( mole => 35 );
print_cost( %single_pet_cost );

my @single_pet_cost = ( gnat => 0.00001 );
print_cost( @single_pet_cost );


sub print_cost
{
  my ($pet, $cost) = @_;
  printf "One unit of a/an %s costs \$%.2f\n", $pet, $cost;
}

print "\$pet = $pet\n";
