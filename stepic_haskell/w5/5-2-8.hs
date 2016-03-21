--Реализованные ранее returnLog и bindLog позволяют определить тип Log представителем класса Monad:

--instance Monad Log where
--    return = returnLog
--    (>>=) = bindLog

--Используя return и >>=, определите функцию execLoggersList

--execLoggersList :: a -> [a -> Log a] -> Log a

--которая принимает некоторый элемент, список функций с логированием и возвращает результат последовательного применения всех функций в списке к переданному элементу вместе со списком сообщений, которые возвращались данными функциями:

--GHCi> execLoggersList 3 [add1Log, mult2Log, \x -> Log ["multiplied by 100"] (x * 100)]
--Log ["added one","multiplied by 2","multiplied by 100"] 800

execLoggersList :: a -> [a -> Log a] -> Log a
execLoggersList x = foldl (>>=) (return x)