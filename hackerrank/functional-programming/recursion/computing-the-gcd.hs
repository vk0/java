--Objective
--In this challenge, we learn how to compute GCD using the Euclidean algorithm.

--Resources
--Here's a helpful video on the topic:

--Given two integers, xx and yy, a recursive technique to find their GCD is the Euclidean Algorithm.

--The algorithm states that, for computing the GCD of two positive integers xx and yy, if xx and yy are equal, GCD(x,y)=xGCD(x,y)=x. Otherwise GCD(x,y)=GCD(x−y,y)GCD(x,y)=GCD(x−y,y) if x>yx>y. There are a few optimizations that can be made to the above logic to arrive at a more efficient implementation.

--Task
--Given the starter code, you need to complete a function body that returns the GCD of two given integers xx and yy.
--The task of reading in input and printing the output will be handled by us.

--Input Format

--One line of input containing 22 space separated integers.

--Output Format

--Output one integer, the GCD of the two given numbers.

--Sample Input

--1 5
--Sample Output

--1
--Constraints

--1<=a,b<=101<=a,b<=1066

--Programming Language Support
--At this point of time, we have a template for Scala. This means that we provide the code required to accept the input and display the output.

--Sample Return Values:

--GCD(1,5) = 1
--GCD(10,100) = 10
--GCD(22,131) = 1

module Main where


gcd' :: Integral a => a -> a -> a
gcd' n 0 = n
gcd' n m = gcd' m (mod n m)


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
  input <- getLine
  print . uncurry gcd' . listToTuple . convertToInt . words $ input
 where
  listToTuple (x:xs:_) = (x,xs)
  convertToInt = map (read :: String -> Int)