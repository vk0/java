--We call an integer p>1p>1 a prime number (or simply a prime) if its only positive divisors are 11 and pp.

--Fundamental theorem of arithmetic states: Every positive integer nn can be uniquely expressed as a product of power of primes, i.e.,

--N=pn11×pn22×pn33×…N=p1n1×p2n2×p3n3×…
--where,

--pipi is the ithith prime, i.e., p1=2,p2=3,p3=5,…p1=2,p2=3,p3=5,…
--∀i.ni≥0∀i.ni≥0
--Greatest common divisor of two positive integers

--For two positive integers, AA and BB, whose prime factorization is represented as

--A=pa11×pa22×pa33×…A=p1a1×p2a2×p3a3×…

--B=pb11×pb22×pb33×…B=p1b1×p2b2×p3b3×…

--We calculate the greatest common divisor, gcd(A,B)gcd(A,B), as

--gcd(A,B)=pmin(a1,b1)1×pmin(a2,b2)2×pmin(a3,b3)3×…gcd(A,B)=p1min(a1,b1)×p2min(a2,b2)×p3min(a3,b3)×…

--Greater common divisor of a list of numbers

--Greatest common factor of a list of positive integers, lst={l1,l2,…lq}lst={l1,l2,…lq}, is represented as

--gcd(lst)=gcd(l1,gcd(l2,gcd(l3,…,(gcd(lq−1,lq))…)))gcd(lst)=gcd(l1,gcd(l2,gcd(l3,…,(gcd(lq−1,lq))…)))

--Finite representation of prime factorization

--Since primes are infinite, it is not possible to store factors in the form provided above. To that end, we will only consider those prime factors (pipi) whose power is greater than zero (ni>0ni>0). That is:

--N=pni1i1×pni2i2×pni3i3×…N=pi1ni1×pi2ni2×pi3ni3×…

--, where

--pij<pij+1pij<pij+1
--0<nij,  j∈[1,2,…]0<nij,  j∈[1,2,…]; for rest ni=0ni=0
--And we will represent them as following:

--N=pi1 ni1 pi2 ni2 pi3 ni3 …N=pi1 ni1 pi2 ni2 pi3 ni3 …

--For example:

--49=72=7 249=72=7 2
--28=22×71=2 2 7 128=22×71=2 2 7 1
--Challenge

--You are given the elements of list, lstlst, in the representation provided above. Find its greatest common divisor, i.e., gcd(lst)gcd(lst).

--Input Format

--First line contains an integer, qq, which is the size of list, lstlst.
--Then follows qq lines, where ithith line represents the factors of ithith element of lstlst, lili

--Output Format

--Print one line representing the greatest common divisor of lstlst (gcd(lst)gcd(lst)) in the above representation.

--Constraints

--2≤q≤10002≤q≤1000
--All other integers lie in [1,105][1,105]
--1≤1≤ Total number of prime factors of an element ≤100≤100
--Notes

--Test cases are designed such that gcd(lst)gcd(lst) will always be greater than 11.
--Sample Input #00

--2
--7 2
--2 2 7 1
--Sample Output #00

--7 1
--Sample Input #01

--4
--2 2 3 2 5 3
--3 2 5 3 11 1
--2 2 3 3 5 4 7 6 19 18
--3 10 5 15
--Sample Output #01

--3 2 5 3
--Explanation

--Test case #00: lst={72,22×71}lst={72,22×71}. Therefore gcd(lst)=71gcd(lst)=71.
--Test case #01: lst={22×32×53, 32×53×111, 22×33×54×76×1918,310×515}lst={22×32×53, 32×53×111, 22×33×54×76×1918,310×515}. gcd(lst)=32×53

import           Control.Applicative ((<$>))
import           Control.Monad       (forM)
import           Data.Maybe

newtype Power = Power (Int, Int)
  deriving Show

readNumbers :: String -> [Power]
readNumbers s = go [] (map (\x -> read x :: Int) $ words s) where
  go ps [] = ps
  go ps (x:y:ys) = go (Power (x,y) : ps) ys

listGcd :: [[Power]] -> [Power]
listGcd = foldr1 reduce

reduce :: [Power] -> [Power] -> [Power]
reduce = reduce' [] where
  reduce' rs _ [] = rs
  reduce' rs [] _ = rs
  reduce' rs (x:xs) ys = reduce' (f x ys ++ rs) xs ys where
    f x [] = []
    f x (y:ys) = case reducePower x y of
                   Nothing -> f x ys
                   Just v -> [v]

reducePower :: Power -> Power -> Maybe Power
reducePower (Power (x,y)) (Power (x',y'))
  | x == x' && y > y' = Just (Power (x, y'))
  | x == x' && y < y' = Just (Power (x, y))
  | x == x' && y == y' = Just (Power (x, y))
  | otherwise = Nothing

showGcd :: [Power] -> String
sjowGcd [] = []
showGcd [Power (a, b)] = show a ++ " " ++ show b
showGcd ((Power (a, b)):gs) = show a ++ " " ++ show b ++ " " ++ showGcd gs

main :: IO ()
main = do
  n <- (\x -> read x :: Int) <$> getLine
  ns <- forM [1..n] $ \_ -> do
    getLine
  putStrLn . showGcd . listGcd $ map readNumbers ns