--Реализуйте функцию nTimes, которая возвращает список, состоящий из повторяющихся значений ее первого аргумента. Количество повторов определяется значением второго аргумента этой функции.

--GHCi> nTimes 42 3
--[42,42,42]
--GHCi> nTimes 'z' 5
--"zzzzz"

nTimes:: a -> Int -> [a]
nTimes x n = nTimes' x n []
nTimes' :: a -> Int -> [a] -> [a]
nTimes' x n acc | n == 0 = acc
                | otherwise = nTimes' x (n-1) (x : acc)