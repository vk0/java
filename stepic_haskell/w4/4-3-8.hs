--Определить функцию abbrFirstName, которая сокращает имя до первой буквы с точкой, т.е. если имя было "Ivan", то после применения этой функции, оно превратится в "I.". Но если имя было короче двух символов, то оно не меняется.

data Person = Person { firstName :: String, lastName :: String, age :: Int }

abbrFirstName :: Person -> Person
abbrFirstName p@(Person {firstName = fn}) = if length fn <= 2 then p else p {firstName = head fn : "."}