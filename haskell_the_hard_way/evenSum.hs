--Функция evenSum возвращает сумму всех четных чисел в списке:
-- Версия 1
-- evenSum  [1..5]
--*Main> evenSum [1..5]
--accumSum 0 [1,2,3,4,5]
--1 is odd
--accumSum 0 [2,3,4,5]
--2 is even
--accumSum (0+2) [3,4,5]
--3 is odd
--accumSum (0+2) [4,5]
--4 is even
--accumSum (0+2+4) [5]
--5 is odd
--accumSum (0+2+4) []
--l == []
--0+2+4
--0+6
--6

evenSum :: [Integer] -> Integer
evenSum l = accumSum 0 l
accumSum n l = if l == []
                  then n
                  else let x = head l
                           xs = tail l
                       in if even x
                              then accumSum (n+x) xs
                              else accumSum n xs