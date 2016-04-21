--Task
--Find the number of ways that a given integer, XX, can be expressed as the sum of the NNthth power of unique, natural numbers.

--Input Format

--The first line contains an integer XX.
--The second line contains an integer NN.

--Constraints

--1<=X<=10001<=X<=1000
--2<=N<=102<=N<=10
--Output Format

--Output a single integer, the answer to the problem explained above.

--Sample Input 1

--10
--2
--Sample Output 1

--1
--Sample Input 2

--100
--3
--Sample Output 2

--1
--Sample Input 3

--100
--2
--Sample Output 3

--3
--Explanation

--Sample 1
--If X=10X=10 and N=2N=2, we need to find the number of ways that 1010 can be represented as the sum of squares of unique numbers.

--10=110=122+3+322

--This is the only way in which 1010 can be expressed as the sum of unique squares.

--Sample 2
--100100 can be expressed as the sum of the cubes of 1,2,3,41,2,3,4.
--(1+8+27+64=100)(1+8+27+64=100). There is no other way to express 100100 as the sum of cubes.

--Sample 3
--100=10100=1022=6=622+8+822=1=122+3+322+4+422+5+522+7+72

import           Control.Applicative (liftA)

searchPowers :: Int -> [Int] -> Int
searchPowers = go where
  go 0 _      = 1
  go _ []     = 0
  go t (x:xs) = if x > t
                  then go t xs
                  else go (t-x) xs + go t xs

powers :: Int -> Int -> Int
powers m n = searchPowers m cs where
    cs = reverse . takeWhile (<= m) . map (^n) $ [1..]

main :: IO ()
main = do
  m <- liftA (\x -> read x :: Int) getLine
  n <- liftA (\x -> read x :: Int) getLine
  print $ powers m n