--Тип LogLevel описывает различные уровни логирования.

--data LogLevel = Error | Warning | Info


--Определите функцию cmp, сравнивающую элементы типа LogLevel так, чтобы было верно, что Error > Warning > Info.

--GHCi> cmp Error Warning
--GT
--GHCI> cmp Info Warning
--LT

cmp :: LogLevel -> LogLevel -> Ordering
cmp Info Info = EQ
cmp Error Error = EQ
cmp Warning Warning = EQ
cmp Info _ = LT
cmp Error _ = GT
cmp Warning Error = LT
cmp Warning _ = GT