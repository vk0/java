#!/usr/bin/perl
use strict;
use warnings;

use CGI qw(header param);

print header;
if ( my @fields = param )
{
  print "<pre>\n";
  for my $field ( @fields )
  {
    print "$field -> ", param( $field ), "\n";
  }
  print "</pre>\n";
}
else
{
  print <DATA>;
}

__END__
<html><head><title>Sample Form</title></head>
<body><h1>Sample CGI Form</h1>
<form>Input fields: <input type="text" name="first"> <input type="text" name="second"> <input type="submit">
</form></body></html>
