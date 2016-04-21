--Pentagonal numbers are the number of dots that can be shown in a pentagonal pattern of dots. Let's represent the nth pentagonal number by P(n). The following figure depicts pentagonal patterns for n ∈ {1, 2, 3, 4, 5}.

--Pentagonal Numebers

--Your task is to find the value of P(n) for a given n.

--Input
--The first line will contain an integer T, which represents the number of test cases. Then T lines, each representing a single test case, follow. Each test case contains an integer n.

--Output
--For each test case, print the nth pentagonal number, P(n), in separate line.

--Constraints
--1 <= T <= 105
--1 <= n <= 105

--Sample Input

--5
--1
--2
--3
--4
--5
--Sample Output

--1
--5
--12
--22
--35
--Explanation
--Above image contains the pentagonal pattern for all n's.

import           Control.Applicative (liftA)
import           Control.Monad       (forM_)
import           Control.Monad.State
import qualified Data.Map            as M
import           System.IO

pentagonal :: M.Map Int Int -> Int -> (M.Map Int Int, Int)
pentagonal d 1 = (d, 1)
pentagonal d x =
  let r = (x * (3 * x - 1)) `div` 2
  in (M.insert x r d, r)

main :: IO ()
main = do
    n <- liftA (\x -> read x :: Int) getLine
    flip evalStateT M.empty $ do
      forM_ [1..n] $ \_ -> do
        m <- liftIO $ liftA (\x -> read x :: Int) getLine
        d <- get
        case M.lookup m d of
          Nothing -> do
            let (d', v) = pentagonal d m
            put d'
            liftIO $ putStrLn (show v)
          Just v -> do
            liftIO $ putStrLn (show v)