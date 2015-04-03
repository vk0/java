#!/usr/bin/perl
#
# bw-contact by Bill Weinman ( http://bw.org/ )
#
# Copyright (c) 1995-2009 The BearHeart Group LLC
# All rights reserved worldwide. 
#
# This program is free software; you can redistribute it and/or modify it
# under the same terms as Perl itself. You must retain this copyright 
# notice, and if you redistribute a modified version you must insert a 
# prominent notice in each changed file stating how and when you changed 
# that file, and make your changes freely available according to the 
# terms of the "Artistic License" distributed with Perl. 
#
# #####
#
# This program provides a form for sending email to the owner of 
# a web site. It uses external HTML files to provide a look
# consistent the rest of the web site. 
#
# version 2.0  -- 2009-11-28 -- bw
#   normalized to use BW::* modules
#   for use with lynda.com course: CGIEssT
#
# version 1.02 -- 2003-08-05 -- bw
#   added code to make sure name part of return address is in quotes
#
# version 1.01 -- 2003-06-26 -- bw
#   bugfix: some servers don't pass REQUEST_URI so this version
#     uses either REQUEST_URI or SCRIPT_NAME
#   feature: now allows use of sendmail if smtp is not available
#     to use sendmail, put path to sendmail in "sendmial" option 
#     in config, and comment out the "smtp" option. 
#

##### ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
#
# if necessary ... 
# Enter the path to your config file 
#
my $config_path = 'bw-contact.conf';


# if necessary ... 
# uncomment the following and enter the path to your BW::* libraries 
# 
# use lib qw( ./lib ../lib );

#
# Nothing below this line should need to be changed. 
#
##### ----- ----- ----- ----- ----- ----- ----- ----- ----- -----

use strict;
use warnings;

use BW::CGI;
use BW::Include;
use BW::Email;
use BW::Config;
use BW::Constants;
use BW::Common;

use subs qw( error );

# global variables
my $g = {

    # configuration file
    config_file => $config_path,

    # sign on values
    progname  => "bw-contact",
    version   => "2.0",
    byline    => "Bill Weinman",
    url       => "http://bw.org/",
    copyright => "&copy; 1995-2009 William E. Weinman",
    stub      => undef

};

my $cgi = new BW::CGI;
my $qv  = $cgi->vars;
my $p   = new BW::Include;
$p->quiet(TRUE);    # supress "Undefined Variable" messages

# normalize the message
$qv->{Emessage} = BW::Common::normalize_newlines( $qv->{Emessage} ) if $qv->{Emessage};

# create the callback URI
$p->var( 'SELF', $cgi->linkback );

read_config();

# jump table
if ( my $cmd = $qv->{cmd} ) {
    firstpage()    if $cmd eq 'firstpage';
    confirm()      if $cmd eq 'confirm';
    send_message() if $cmd eq 'send';
    firstpage();    # default
}

# fall through
firstpage();

exit;

###

sub read_config
{
    my $config = new BW::Config( filename => $g->{config_file} );
    my $cfv      = $config->values;
    my $cfe    = $config->error;
    error "$cfe\n" if $cfe;

    $g->{CONFIG}     = $config;
    $g->{CV}         = $cfv;
    $g->{ERROR_PAGE} = $g->{CV}{htmlerror};
}

sub firstpage
{
    my $referer = $qv->{Referer} || $ENV{HTTP_REFERER} || '(none)';
    if ( my $firstpage = $g->{CV}{htmlfirst} ) {
        $p->var( 'Efromname',  $cgi->html_encode( $qv->{Efromname} ) )  if $qv->{Efromname};
        $p->var( 'Efromemail', $cgi->html_encode( $qv->{Efromemail} ) ) if $qv->{Efromemail};
        $p->var( 'Esubject',   $cgi->html_encode( $qv->{Esubject} ) )   if $qv->{Esubject};
        $p->var( 'Emessage',   $cgi->html_encode( $qv->{Emessage} ) )   if $qv->{Emessage};
        $p->var( 'HIDDENS', hiddens( { Referer => $referer, cmd => 'confirm' } ) );
        send_header();
        $p->pf($firstpage);
    } else {
        error "htmlfirst must be defined in $g->{config_file}";
    }
    exit;
}

sub confirm
{
    error_confirm("The email address you entered ($qv->{Efromemail}) is not valid.")
      unless BW::Email::validate_email( $qv->{Efromemail} );
    error_confirm("You must enter both your name and your email address.") unless $qv->{Efromname} =~ /\S/;
    error_confirm("You must supply a subject for your message.")           unless $qv->{Esubject}  =~ /\S/;
    error_confirm("The message is empty. Please enter your message.")      unless $qv->{Emessage}  =~ /\S/;

    firstpage() if error_confirm();

    my $dispMessage = dispLineBreaks( $qv->{Emessage} ) if $qv->{Emessage};

    if ( my $confpage = $g->{CV}{htmlconfirm} ) {

        # wrap Efromname in quotes, if necessary
        $qv->{qEfromname} = ( $qv->{Efromname} =~ /"/ ) ? $qv->{Efromname} : q|"| . $qv->{Efromname} . q|"|
          if $qv->{Efromname};

        $p->var( 'Efromname',  $cgi->html_encode( $qv->{qEfromname} ) ) if $qv->{Efromname};
        $p->var( 'Efromemail', $cgi->html_encode( $qv->{Efromemail} ) ) if $qv->{Efromemail};
        $p->var( 'Esubject',   $cgi->html_encode( $qv->{Esubject} ) )   if $qv->{Esubject};
        $p->var( 'Emessage',   $dispMessage )                           if $dispMessage;
        $p->var(
            'HIDDENS',
            hiddens( {
                    Efromname  => $qv->{Efromname},
                    Efromemail => $qv->{Efromemail},
                    Esubject   => $qv->{Esubject},
                    Emessage   => $qv->{Emessage},
                    Referer    => $qv->{Referer} } ) );
        send_header();
        $p->pf($confpage);
    } else {
        error "htmlconfirm must be defined in $g->{config_file}";
    }
    exit;
}

sub dispLineBreaks
{
    my $s = shift or return undef;
    $s = $cgi->html_encode( $s );
    $s =~ s/&#10;/<br\/>\n/gsm;
    return $s;
}


sub error_confirm
{
    my $pverr = $p->var('CONFIRM_ERROR');
    if (@_) {
        my $err = shift;
        $pverr .= "<br>\n" if $pverr;
        $err   = qq{<span style="color: red; font-weight: bold">$err</span>};
        $err   = $pverr . $err if $pverr;
        $pverr = $p->var( 'CONFIRM_ERROR', $err );
    }
    return $pverr;
}

sub send_message
{
    error "sendmail or smtp_host must be defined in $g->{config_file}"
      unless ( $g->{CV}{smtp_host} || $g->{CV}{sendmail} );
    if ( my $completepage = $g->{CV}{htmlcomplete} ) {

        # wrap Efromname in quotes, if necessary
        $qv->{Efromname} = ( $qv->{Efromname} =~ /"/ ) ? $qv->{Efromname} : q|"| . $qv->{Efromname} . q|"|
          if $qv->{Efromname};

        my $em = new BW::Email;
        $em->header( 'X-Mailer',     "$g->{progname}/$g->{version} (by $g->{byline} <$g->{url}>)" );
        $em->header( 'X-User-Agent', $ENV{HTTP_USER_AGENT} );
        $em->header( 'X-Referer',    $qv->{Referer} );
        $em->email_from( $qv->{Efromemail} );
        $em->email_from_name( $qv->{Efromname} );
        $em->email_to( $g->{CV}{toemail} );
        $em->email_to_name( $g->{CV}{toname} );
        $em->email_subject( $qv->{Esubject} );
        $em->email_body( $qv->{Emessage} );

        if ( $g->{CV}{smtp_host} ) {
            $em->smtp_host( $g->{CV}{smtp_host} );
            $em->send;
            my $emerr = $em->error;
            error "$emerr\n" if $emerr;
        } else {
            my $sendmail = $g->{CV}{sendmail};
            my $message  = $em->message;

            open( SENDMAIL, "|$sendmail -t -f $qv->{Efromemail}" ) or error "cannot open $sendmail\n";
            print SENDMAIL $message;
        }

        my $dispMessage = dispLineBreaks( $qv->{Emessage} ) if $qv->{Emessage};
        $p->var( 'Efromname',  $cgi->html_encode( $qv->{Efromname} ) )  if $qv->{Efromname};
        $p->var( 'Efromemail', $cgi->html_encode( $qv->{Efromemail} ) ) if $qv->{Efromemail};
        $p->var( 'Esubject',   $cgi->html_encode( $qv->{Esubject} ) )   if $qv->{Esubject};
        $p->var( 'Emessage',   $dispMessage )                           if $qv->{Emessage};

        send_header();
        $p->pf($completepage);
    } else {
        error "htmlcomplete must be defined in $g->{config_file}";
    }
    exit;
}

sub hiddens
{
    my $h = shift || return FALSE;
    my $s = '';
    foreach my $k ( sort keys %$h ) {
        my $v = $h->{$k} || '';
        $v = $cgi->html_encode($v);
        $s .= qq{<input type=hidden name="$k" value="$v">\n};
    }
    return $s;
}

sub send_header
{
    return if $g->{SENT_HEADER};
    $g->{SENT_HEADER} = TRUE;
    print "Robots: noindex,nofollow\n";
    print "Content-type: text/html\n\n";
}

sub error
{
    my $e = shift or return;
    send_header();
    if ( $g->{ERROR_PAGE} ) {
        $p->var( 'errormessage', $e );
        $p->pf( $g->{ERROR_PAGE} );
    } else {
        print qq{<p><span style="color: red; font-weight: bold; background-color: #ffc">$e</span></p>\n};
    }
    exit;
}

