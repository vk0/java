use File::Find;
my $total_size = 0;
find(sub { $total_size += -s if -f }, '.');
print "Total Size $total_size", "\n";
