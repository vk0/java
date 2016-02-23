--Реализуйте функцию, находящую значение определённого интеграла от заданной функции f на заданном интервале [a,b] методом трапеций. (Используйте равномерную сетку; достаточно 1000 элементарных отрезков.)

--integration :: (Double -> Double) -> Double -> Double -> Double
--integration f a b = undefined
--GHCi> integration sin pi 0
---2.0
--Результат может отличаться от -2.0, но не более чем на 1e-4.

integration :: (Double -> Double) -> Double -> Double -> Double
integration f a b = let h = (b-a)/1000
             in h * ((f a + f b)/2 + helper 0 f a h 1)
helper s f a h n | n == 1000 = s
                 | otherwise = helper (s + f (a + n * h)) f a h (n + 1)