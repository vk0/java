--Goldbach's conjecture.

--Goldbach's conjecture says that every positive even number greater than 2 is the sum of two prime numbers. Example: 28 = 5 + 23. It is one of the most famous facts in number theory that has not been proved to be correct in the general case. It has been numerically confirmed up to very large numbers (much larger than we can go with our Prolog system). Write a predicate to find the two prime numbers that sum up to a given even integer.

--Example:

--* (goldbach 28)
--(5 23)
--Example in Haskell:

--*goldbach 28
--(5, 23)

--Solution 1:

goldbach a = head $
                     filter (\(x,y) -> isPrime x && isPrime y) $
                     map (\e -> (e, a - e)) [1,3..a `div` 2]
 where
 factors a = filter (isFactor a) [2..a-1]
 isFactor a b = a `mod` b == 0
 isPrime a = null $ factors a

--Woohoo! I've solved the goldbach conjecture! Where do I collect my prize? This does the obvious thing. It makes a list of odd numbers and then uses it to make up pairs of odd numbers that sum to n. Then it looks for a pair of odd numbers where both are prime and returns it as a tuple.

--Solution 2:

-- using the previous problem...

goldbach n = head [(x,y) | x <- pr, y <- pr, x+y==n]
    where pr = primesR 2 (n-2)

--Solution 3:

goldbach n = head [(x,y) | x <- primesR 2 (n-2),
                           let y = n-x, isPrime y]