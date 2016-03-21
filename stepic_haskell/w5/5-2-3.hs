--Введём следующий тип:

--data Log a = Log [String] a

--Реализуйте вычисление с логированием, используя Log. Для начала определите функцию toLogger

--toLogger :: (a -> b) -> String -> (a -> Log b)

--которая превращает обычную функцию, в функцию с логированием:

--GHCi> let add1Log = toLogger (+1) "added one"
--GHCi> add1Log 3
--Log ["added one"] 4

--GHCi> let mult2Log = toLogger (* 2) "multiplied by 2"
--GHCi> mult2Log 3
--Log ["multiplied by 2"] 6

--Далее, определите функцию execLoggers

--execLoggers :: a -> (a -> Log b) -> (b -> Log c) -> Log c


--Которая принимает некоторый элемент и две функции с логированием. execLoggers возвращает результат последовательного применения функций к элементу и список сообщений, которые были выданы при применении каждой из функций:

--GHCi> execLoggers 3 add1Log mult2Log
--Log ["added one","multiplicated by 2"] 8


toLogger :: (a -> b) -> String -> (a -> Log b)
toLogger f msg = \ x -> Log [msg] $ f x

execLoggers :: a -> (a -> Log b) -> (b -> Log c) -> Log c
execLoggers x f g = case f x of
    Log m1 y -> case g y of
        Log m2 z -> Log (m1 ++ m2) z