--Определите функцию updateLastName person1 person2, которая меняет фамилию person2 на фамилию person1.

data Person = Person { firstName :: String, lastName :: String, age :: Int }

updateLastName :: Person -> Person -> Person
updateLastName person1 person2 = person2 {lastName = (lastName person1)}