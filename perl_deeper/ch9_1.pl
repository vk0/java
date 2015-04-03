my @input = qw/Джиллиган Шкипер Профессор Джинджер Мэри_Энн/;
my @sorted_positions = sort { $input[$a] cmp $input[$b] } 0..$#input;
print @sorted_positions;
#print "@sorted_positions\n";
