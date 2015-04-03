#!/usr/bin/perl
use File::Find;
my @starting_directories = qw(.);
find(
    sub {
        print "Найден файл или каталог $File::Find::name\n"; 
        }, @starting_directories,
);
