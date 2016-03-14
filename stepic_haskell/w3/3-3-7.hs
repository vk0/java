--Пусть задан тип Odd нечетных чисел следующим образом:

--data Odd = Odd Integer
--  deriving (Eq, Show)

--Сделайте этот тип представителем класса типов Enum.

--GHCi> succ $ Odd (-100000000000003)
--Odd (-100000000000001)

--Конструкции с четным аргументом, типа Odd 2, считаются недопустимыми и не тестируются.

--Примечание. Мы еще не знакомились с объявлениями пользовательских типов данных, однако, скорее всего, приведенное объявление не вызовет сложностей. Здесь объявляется тип данных Odd с конструктором Odd. Фактически это простая упаковка для типа Integer. Часть deriving (Eq, Show) указывает компилятору, чтобы он автоматически сгенерировал представителей соответствующих классов типов для нашего типа (такая возможность имеется для ряда стандартных классов типов). Значения типа Odd можно конструировать следующим образом:

--GHCi> let x = Odd 33
--GHCi> x
--Odd 33

--и использовать конструктор данных Odd в сопоставлении с образцом:

--addEven :: Odd -> Integer -> Odd
--addEven (Odd n) m | m `mod` 2 == 0 = Odd (n + m)
--                  | otherwise      = error "addEven: second parameter cannot be odd"

-- data Odd = Odd Integer deriving (Eq,Show)
-- не убирайте комментарий с предыдущей строки
-- определение Odd уже присутствует в вызывающей программе

instance Enum Odd where
  succ (Odd x) = Odd $ x + 2
  pred (Odd x) = Odd $ x - 2
  toEnum x = Odd $ toInteger x * 2 + 1
  fromEnum (Odd x) = quot (fromInteger x - 1) 2
  enumFrom = iterate succ
  enumFromThen (Odd x) (Odd y) = map Odd [x, y ..]
  enumFromTo (Odd x) (Odd y) = map Odd [x, x + 2 .. y]
  enumFromThenTo (Odd x) (Odd y) (Odd z) = map Odd [x , y .. z]