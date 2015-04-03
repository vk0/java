$maximum = &max(3, 5, 10, 4, 6);
sub max {
my($max_so_far) = shift @_;
foreach (@_) {
if ($_ > $max_so_far) {
$max_so_far = $_;
}
}
print $max_so_far."\n";
}
