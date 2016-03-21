--Давайте убедимся, что с помощью монады State можно эмулировать монаду Reader.

--Напишите функцию readerToState, «поднимающую» вычисление из монады Reader в монаду State:

--GHCi> evalState (readerToState $ asks (+2)) 4
--6
--GHCi> runState (readerToState $ asks (+2)) 4
--(6,4)

readerToState :: Reader r a -> State r a
readerToState m = state $ \s -> (runReader m s,s)