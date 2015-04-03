open my $log_fh, '>', 'castaways.log'
or die "Невозможно открыть файл castaways.log: $!"; 

print {$log_fh} "Сегодня у нас нет бананов!\n";

log_message( $log_fh, 'Меня зовут мистер Эд' );

sub log_message {
    my $fh = shift;
    print $fh @_, "\n";
}
