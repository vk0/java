use IO::File;

my $log_fh = IO::File->new( 'castaways.log', "w" );

print {$log_fh} "Сегодня у нас нет бананов!\n";

log_message( $log_fh, 'Меня зовут мистер Эд' );

sub log_message {
    my $fh = shift;
    print $fh @_, "\n";
}
