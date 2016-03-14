--Реализуйте функцию sumOdd, которая суммирует элементы списка целых чисел, имеющие нечетные значения:

--GHCi> sumOdd [2,5,30,37]
--42

sumOdd :: [Integer] -> Integer
sumOdd = foldr (\x s -> if odd x then x + s else s) 0