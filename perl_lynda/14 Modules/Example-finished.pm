# Example.pm
#   Example perl module
#

package Example;
use strict;
use warnings;
use IO::File;

our $VERSION = "0.1";

sub new
{
    my $class = shift;
    my $self = {};
    bless($self, $class);
    return $self;
}

sub copyfile
{
    my ( $self, $origfile, $newfile ) = @_;
    my $bufsize = 1024 * 1024;

    my $origfh = IO::File->new($origfile, 'r') or die("cannot open $origfile ($!)");
    my $newfh = IO::File->new($newfile, 'w') or die("cannot open $newfile ($!)");

    $origfh->binmode(":raw");
    $newfh->binmode(":raw");

    my $buf = '';
    while( $origfh->read( $buf, $bufsize ) ) {
        $newfh->print( $buf ); 
    }
    return 1;
}

1;
