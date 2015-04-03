#my @wrongly_sorted = sort qw/1, 2, 4, 8, 16, 32/;
#my @wrongly_sorted = sort {$a <=> $b} qw/1, 2, 4, 8, 16, 32/;
my @wrongly_sorted = reverse sort {$a <=> $b} qw/1, 2, 4, 8, 16, 32,/;

print @wrongly_sorted;

