#!/usr/bin/perl
use strict;
use warnings;

my $OUTPUT_FILE = 'kennel_assignments';

my %available_location;
for my $kennel ( qw(A1 B52 C17 K9) )
{
  $available_location{$kennel} = $kennel;
}
my %assigned_location;
while ( keys %available_location )
{
  print "Please input a pet name or return to end: ";
  my $name = <STDIN>;
  chomp $name;
  last unless length $name;     # Exits OUTER while
  prompt_locations();

  while ( my $kennel = <STDIN> )
  {
    chomp $kennel;
    if ( my $location = $available_location{$kennel} )
    {
      $assigned_location{$name} = delete $available_location{$kennel};
      last;                     # Exits INNER while
    }
    else
    {
      print "No such location, try again\n";
      prompt_locations();
    }
  }
}

open my $fh, '>', $OUTPUT_FILE or die "Couldn't open $OUTPUT_FILE: $!\n";
for my $name ( keys %assigned_location )
{
  print {$fh} "$name $assigned_location{$name}\n";
}

sub prompt_locations
{
  print "Choose a location from: ";
  print join(' ', sort keys %available_location), "\n";
}
