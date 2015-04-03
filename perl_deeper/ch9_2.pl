use Data::Dumper;
print Dumper(data_for_path('../'));
#print data_for_path('.');
sub data_for_path {
my $path = shift;
if (-f $path or -l $path) { # файлы или символические ссылки
return undef;
}
if (-d $path) {
my %directory;
opendir PATH, $path or die "Невозможно открыть $path: $!";
my @names = readdir PATH;
closedir PATH;
for my $name (@names) {
next if $name eq '.' or $name eq '..';
$directory{$name} = data_for_path("$path/$name");
}
return \%directory;
}
warn "Имя $path не является ни файлом, ни каталогом\n";
return undef;
}
