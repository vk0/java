# Template.pm
# 
# Description goes here
# by Your Name
#

package Template;
use strict;
use warnings;

our $VERSION = "0.1";

sub new
{
    my $class = shift;
    my $self  = {};

    bless( $self, $class );
    return $self;
}

sub method 
{
    my ($self, $this, $that ) = @_;
    return 1;
}

1;

__END__

=head1 NAME

Template - Description goes here

=head1 SYNOPSIS

    use Template
    my $o = Template->new;

=head1 METHODS

=over 4

=item B<new>

Constructs a new Template object. 

Returns a blessed Template object reference.

=item B<method>

Describe the method here 

=back

=head1 AUTHOR

Written by Your Name

=head1 HISTORY

    Version history here. 

=cut

