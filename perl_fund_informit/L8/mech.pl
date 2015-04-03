#!/usr/local/bin/perl
use strict;
use warnings;

use WWW::Mechanize;

my $IMAGE_FILE = 'andy.jpg';

my $mech = WWW::Mechanize->new;
$mech->get( 'http://www.perl.org' )                        or die "Couldn't load site";                print "Fetched home page\n";
$mech->follow_link( text => 'Search' )                     or die "Couldn't find Search link";         print "Followed link\n";
$mech->set_visible( 'mechanize' );
$mech->submit;                                                                                         print "Submitted form\n";
$mech->follow_link( text => 'WWW::Mechanize' )             or die "Couldn't find Mechanize page link"; print "Followed link\n";
my $image = $mech->find_image( url_regex => qr/gravatar/ ) or die "Couldn't find image";               print "Found image\n";
$mech->get( $image->url, ':content_file' => $IMAGE_FILE )  or die "Couldn't get image source";         print "Got image\n";
system "display -resize 200x200 $IMAGE_FILE"              and die "Can't run display command";
unlink $IMAGE_FILE                                         or die "Couldn't delete $IMAGE_FILE";
