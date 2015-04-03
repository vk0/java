#!/usr/bin/perl
# RandomQuote.pl by Bill Weinman <http://bw.org/contact/>
# Copyright (c) 2010 The BearHeart Group, LLC
#
# command line version. 
# usage: RandomQuote.pl
#           will display one random quote from quotes.txt
#        RandomQuote.pl filename
#           will display one random quote from (filename)
#        RandomQuote.pl filename number
#           will display (number) random quotes from (filename)
#

use strict;
use warnings;
use IO::File;

my $quotes = [];    # container for quotes

main(@ARGV);

sub main
{
    my ($filename, $dispQuan) = @_;
    $filename = "quotes.txt" unless $filename;
    $dispQuan = 1 unless $dispQuan;

    readQuotes($filename);
    while($dispQuan--) {
        displayQuote(getQuote());
    }
}

sub readQuotes
{
    my $filename = shift or error("readQuotes: missing filename");
    my $fh = IO::File->new($filename, 'r') or error("Cannot open $filename ($!)");

    my $token = '';
    my $quote = {};
    while( my $line = $fh->getline() ) {
        if ( my $newtok = getToken($line) ) {
            $token = $newtok;
            if ($token eq 'quote') {
                $quote = newQuote();
            }
        } elsif($token) {
            chomp $line;
            if( $quote->{$token} ) {
                $quote->{$token} = join("\n", $quote->{$token}, $line); # join with a newline
            } else {
                $quote->{$token} = $line;
            }
        } else {
            error("widowed line (no token) in $filename: $line");
        }
    }
}

sub getQuote
{
    my $count = @$quotes;
    message("No quotes.") unless $count;

    my $qn = int(rand($count));
    return splice(@$quotes, $qn, 1);
}

sub displayQuote
{
    my $quote = shift or return;
    return unless $quote->{quote};

    message(qq{$quote->{quote}});
    message(qq{--$quote->{byline}}) if $quote->{byline};
}

sub getToken
{
    my $line = shift or return undef;
    if( $line =~ /^\$(.*)\$$/m ) {
        return $1;
    } else {
        return undef;
    } 
}

sub newQuote
{
    push( @$quotes, {} );   # empty hash for new new quote
    return $quotes->[-1];   # use this entry for our current quote 
    
}

sub message
{
    my $m = shift or return;
    print("$m\n");
}

sub error
{
    my $e = shift || 'unkown error';
    my $me = $0;
    $me = ( split( m|[\\\/]|, $me ) )[-1];
    print STDERR ("$me: $e\n");
    exit 0;
}
