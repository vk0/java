#!/usr/bin/perl
use strict;

while(<STDIN>) { # результат чтения сохраняется в переменной $_
   chomp; # отсекаем символ \n в переменной $_
   last if($_ eq "exit");
   printf "Вы ввели '%s'. Для выхода из цикла введите 'exit'\n", $_;
}
