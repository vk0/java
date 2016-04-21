--You are given a sequence of NN balls in 4 colors: red, green, yellow and blue. The sequence is full of colors if and only if all of the following conditions are true:

--There are as many red balls as green balls.
--There are as many yellow balls as blue balls.
--Difference between the number of red balls and green balls in every prefix of the sequence is at most 1.
--Difference between the number of yellow balls and blue balls in every prefix of the sequence is at most 1.
--Your task is to write a program, which for a given sequence prints True if it is full of colors, otherwise it prints False.

--Input
--In the first line there is one number TT denoting the number of tests cases.
--TT lines follow. In each of them there is a sequence of letters {R,G,Y,B}{R,G,Y,B} denoting the input sequence (RR - red, GG - green, YY - yellow, BB - blue).

--Output
--For each test case, print True if this is a sequence full of colors, otherwise print False.

--Constraints
--1≤T≤101≤T≤10
--Sequence will only consists of letters {R,G,Y,B}{R,G,Y,B}.
--Sum of length of all sequences will not exceed 106106.

--Notes
--A prefix of a string T=t1…tnT=t1…tn is a string Tˆ=t1…tmT^=t1…tm, where 0≤m≤n0≤m≤n.

--Sample Input

--4
--RGGR
--RYBG
--RYRB
--YGYGRBRB
--Sample Output

--True
--True
--False
--False
--Explanation
--In the first two test cases, all four conditions are satisfied.
--In the third test case, condition #1 fails as there are more red balls than green balls and condition #3 also fails for prefix "RYR" as the difference between the number of red and green balls is more than 1. In the fourth test, for a prefix "YGYG" condition 4th fails.

import           Control.Applicative ((<$>))
import           Control.Monad       (forM_)

check :: String -> Bool
check = go 0 0 0 0 where
  go r g y b []     = r == g && y == b
  go r g y b (x:xs)
    | x == 'R' = abs (r + 1 - g) <= 1 && go (r+1) g y b xs
    | x == 'G' = abs (g + 1 - r) <= 1 && go r (g+1) y b xs
    | x == 'Y' = abs (y + 1 - b) <= 1 && go r g (y+1) b xs
    | x == 'B' = abs (b + 1 - y) <= 1 && go r g y (b+1) xs

main :: IO ()
main = do
  n <- (\x -> read x :: Int) <$> getLine
  forM_ [1..n] $ \_ -> do
    s <- getLine
    if not (check s)
      then putStrLn "False"
      else putStrLn "True"