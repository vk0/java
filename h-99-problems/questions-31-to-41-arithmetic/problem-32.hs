--Determine the greatest common divisor of two positive integer numbers. Use Euclid's algorithm.

--Example:

--* (gcd 36 63)
--9
--Example in Haskell:

--[myGCD 36 63, myGCD (-3) (-6), myGCD (-3) 6]
--[9,3,3]


gcd' 0 y = y
gcd' x y = gcd' (y `mod` x) x
myGCD x y | x < 0     = myGCD (-x) y
          | y < 0     = myGCD x (-y)
          | y < x     = gcd' y x
          | otherwise = gcd' x y

--The Prelude includes a gcd function, so we have to choose another name for ours. The function gcd' is a straightforward implementation of Euler's algorithm, and myGCD is just a wrapper that makes sure the arguments are positive and in increasing order.

--A more concise implementation is:

myGCD :: Integer -> Integer -> Integer
myGCD a b
      | b == 0     = abs a
      | otherwise  = myGCD b (a `mod` b)