--Реализуйте функцию seqA, находящую элементы следующей рекуррентной последовательности

--a0=1;a1=2;a2=3;ak+3=ak+2+ak+1−2ak.

--Попытайтесь найти эффективное решение.

--GHCi> seqA 301
--1276538859311178639666612897162414

seqA :: Integer -> Integer
seqA 0 = 1
seqA 1 = 2
seqA 2 = 3
seqA n = s' 3 3 2 1 n
s' :: Integer -> Integer -> Integer -> Integer -> Integer -> Integer
s' i a b c n | (i < n) = s' (i + 1) res a b n
             | (i == n) = res
             where res = a + b - 2*c