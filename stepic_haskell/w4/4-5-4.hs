--Рассмотрим еще один пример рекурсивного типа данных:

--data Nat = Zero | Suc Nat

--Элементы этого типа имеют следующий вид: Zero, Suc Zero, Suc (Suc Zero), Suc (Suc (Suc Zero)), и так далее. Таким образом мы можем считать, что элементы этого типа - это натуральные числа в унарной системе счисления.

--Мы можем написать функцию, которая преобразует Nat в Integer следующим образом:

--fromNat :: Nat -> Integer
--fromNat Zero = 0
--fromNat (Suc n) = fromNat n + 1

--Реализуйте функции сложения и умножения этих чисел, а также функцию, вычисляющую факториал.

data Nat = Zero | Suc Nat deriving Show

fromNat :: Nat -> Integer
fromNat Zero = 0
fromNat (Suc n) = fromNat n + 1

toNat :: Integer -> Nat
toNat 0 = Zero
toNat n = Suc (toNat (n - 1))

add :: Nat -> Nat -> Nat
add Zero Zero       = Zero
add Zero x          = x
add x    Zero       = x
add x (Suc y)       = add (Suc x) y

mul :: Nat -> Nat -> Nat
mul Zero _    = Zero
mul _    Zero = Zero
mul x    y    = toNat((fromNat x) * (fromNat y))

fac :: Nat -> Nat
fac x = toNat (factorial (fromNat x))

factorial :: Integer -> Integer
factorial n = product [1..n]