--Scturtle likes strings very much. He is getting bored today, because he has already completed this week's task and doesn't have anything else to do. So he starts left-rotating a string. If the length of the string is nn, then he will rotate it nn times and note down the result of each rotation on a paper.

--For a string S=s1s2…sn, nS=s1s2…sn, n rotations are possible. Let's represent these rotations by r1,r2…rnr1,r2…rn. Rotating it once will result in string r1=s2s3…sns1r1=s2s3…sns1, rotating it again will result in string r2=s3s4…sns1s2r2=s3s4…sns1s2 and so on. Formally, ithith rotation will be equal to ri=si+1…sn−1sns1…siri=si+1…sn−1sns1…si. Note that rn=Srn=S.

--Your task is to display all nn rotations of string SS.

--For example, if SS = abc then it has 3 rotations. They are  r1 r1 = bca, r2r2 = cab and r3r3 = abc.

--Input Format
--The first line contains an integer, TT, which represents the number of test cases to follow. Then follows TT lines, which represent a test case each.
--Each test case contains a string, SS, which consists of lower case latin characters (′a′−′z′)(′a′−′z′) only.

--Output Format
--For each test case, print all the rotations, r1 r2…rnr1 r2…rn, separated by a space.

--Constraints
--1 ≤ T ≤ 101 ≤ T ≤ 10
--1 ≤ n ≤ 1021 ≤ n ≤ 102
--SS will consist of lower case latin character, [′a′…′z′][′a′…′z′] only.

--Sample Input

--5
--abc
--abcde
--abab
--aaa
--z
--Sample Output

--bca cab abc
--bcdea cdeab deabc eabcd abcde
--baba abab baba abab
--aaa aaa aaa
--z
--Explanation
--Test case #1: This case is mentioned in the problem statment.
--Test case #2: Rotations of abcde are: bcdea -> cdeab -> deabc -> eabcd -> abcde.
--Test case #3: Rotations of abab are: baba -> abab -> baba -> abab.
--Test case #4: All three rotations will result into same string.
--Test case #5: Only one rotation is possible, and that will result into original string.

import           Control.Applicative ((<$>))
import           Control.Monad       (forM_)

rotateL :: Int -> String -> String
rotateL _ [] = []
rotateL 0 xs = xs
rotateL n (x:xs) = rotateL (n-1) (xs ++ [x])

main :: IO ()
main = do
  n <- (\x -> read x :: Int) <$> getLine
  forM_ [1..n] $ \_ -> do
    s <- getLine
    putStrLn . foldl1 (\a b -> a ++ " " ++ b) $
      zipWith rotateL [1..] (replicate (length s) s)