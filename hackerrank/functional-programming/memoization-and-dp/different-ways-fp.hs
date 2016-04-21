--Arsenal have been on a losing streak for years now. Their critic have gone to the extent of saying that they can't even defeat a team of lemurs. So Arsenal decided to show them how wrong they are. But they have done a grave mistake. You are in charge of lemur team and are confident of the abilities of a lemur. Given N lemurs, you have to select K out of them who will be facing off Arsenal in a soccer match.

--You have to count total number of different teams you can form by selecting K out of N lemurs. A team is different from other team if there's exist atleast one lemur who is in one team but not in other. As this number can be large print answer modulo (10^8+7).

--Let's say count(N, K) represent how many different team can be formed by selecting K out of N lemurs. Then any of the following condition may occur:

--K = 0, that is you have to select no one. There only one way of doing that, ie, selecting no one.
--K = N, you have to select all of them. Here, also, is only way of doing that, ie, selecting all.
--0 < K < N, let's number N lemurs from [1, N]. Then there are two option
--Select first lemur, and then select (K-1) lemurs from remaining (N-1) lemurs.
--Don't select first lemur, so you have to select K lemurs from remaining (N-1) lemurs.
--Mathematically, we can represent this situation as following

--              1                                   , K = 0
--count(N, K) = 1                                   , K = N
--              count(N-1, K-1) + count(N-1, K),    , 0 < K < N
--Note: Haskell users can use Data.Vector library.

--Input
--First line of input will contain a integer, T, representing the number of test cases. Then T lines follow, each representing a test case. In each test case, there are two space separated integers, N K, total number of lemurs available and number of lemurs to be selected.

--Output
--For each test case, print total number of different teams that can be formed. As this number be large, print answer modulo (10^8+7).

--Constraints
--1 <= T <= 1000
--1 <= N <= 1000
--0 <= K <= N

--Sample Input

--5
--2 1
--5 1
--5 2
--5 3
--10 5
--Sample Output

--2
--5
--10
--10
--252
--Explanation
--Test case #1: You have to select one of two lemur {a, b}. Any of them can be selected, {{a}, {b}}.
--Test case #2: Similarly you have to select any one out of five lemurs {a, b, c, d, e}. There are 5 ways of doing that, {{a}, {b}, {c}, {d}, {e}}.
--Test case #3: You have to select two lemurs out of five {a, b, c, d, e}. These are the possible teams: {{a, b}, {a, c}, {a, d}, {a, e}, {b, c}, {b, d}, {b, e}, {c, d}, {c, e}, {d, e}}.
--Test case #4: Selecting three out of five lemurs is equivalent rejecting two of them. So it will be equal to number of ways of selecting two of five lemurs.
--Test case #5: There can be 252 different teams formed by selecting 5 out of 10 lemurs.

import           Control.Applicative (liftA)
import           Control.Monad       (forM_)

ways :: [[Integer]]
ways = [[count k n | k <- [0..1000]] | n <- [0..]] where
  count k n
    | k > n || n < 1 = 0
    | k == 0    = 1
    | k == n    = 1
    | otherwise = ways !! (n-1) !! (k-1) + ways !! (n-1) !! k

solve :: Int -> Int -> Int
solve n k = fromIntegral (ways !! n !! k `mod` (10^8+7))

main :: IO ()
main = do
  t <- readLn
  forM_ [1..t] $ \_ -> do
    [n, k] <- liftA (map (\x -> read x :: Int) . words) getLine
    print $ solve n k