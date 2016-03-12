--Напишите функцию трех аргументов getSecondFrom, полиморфную по каждому из них, которая полностью игнорирует первый и третий аргумент, а возвращает второй. Укажите ее тип.

--GHCi> getSecondFrom True 'x' "Hello"
--'x'
--GHCi> getSecondFrom 'x' 42 True
--42

getSecondFrom :: t1 -> t2 -> t3 -> t2
getSecondFrom x y z = y