--Реализуйте фукцию bindLog

--bindLog :: Log a -> (a -> Log b) -> Log b

--которая работает подобно оператору >>= для контекста Log.

--GHCi> Log ["nothing done yet"] 0 `bindLog` add1Log
--Log ["nothing done yet","added one"] 1

--GHCi> Log ["nothing done yet"] 3 `bindLog` add1Log `bindLog` mult2Log
--Log ["nothing done yet","added one","multiplied by 2"] 8

bindLog :: Log a -> (a -> Log b) -> Log b
bindLog (Log msg1 x) f = let Log msg2 y = f x in Log (msg1 ++ msg2) y