module Homework10 where

import Control.Monad.State
import Control.Monad.Writer
import Data.IORef
import System.Random
import System.IO

-- sequence [Just 1, Just 2, Just 3] =
-- foldr k (return []) [Just 1, Just 2, Just 3] =
-- k (Just 1) (foldr k (return []) [Just 2, Just 3]) = ...
-- Just (1:2:3[]) = Just [1, 2, 3]
result1 = sequence [Just 1, Just 2, Just 3]

-- sequence [Just 1, Just 2, Nothing, Just 4] = Nothing
result2 = sequence [Just 1, Just 2, Nothing, Just 4]

-- sequence [[1, 2, 3], [10, 20]] = 
-- k [1, 2, 3] (foldr k (return []) [[10, 20]]) = ..
-- [[1, 10], [1, 20], [2, 10], [2, 20], [3, 10], [3, 20]]
result3 = sequence [[1, 2, 3], [10, 20]]

-- mapM (\x -> [x+1,x*2]) [10, 20] = 
-- sequence [[11, 20], [21, 40]] = [[11, 21], [11, 40], [20, 21], [20, 40]]
result4 = mapM (\x -> [x+1,x*2]) [10, 20]

-- sequence_ [[1, 2, 3], [10, 20]] = [(), (), (), (), ()]
result5 = sequence_ [[1, 2, 3], [10, 20]]

-- mapM_ (\x -> [x+1,x*2]) [10, 20] = [(), (), (), ()]
result6 = mapM_ (\x -> [x+1,x*2]) [10, 20]

-- just "second"
result7 = let x = print "first" in print "second"

-- "first"\n"second"
result8 = let x = print "first" in x >> print "second"

-- "first"
result9 = (\x -> print "first") (print "second")

-- just "second", see `seq`
result10 = print "first" `seq` print "second"

prod  =  do (n,p) <- get
            put (n + 1, p * n)
fact n  =  snd $ execState (replicateM n prod) (1, 1)

fsum  =  do (f1, f0) <- get
            put (f1 + f0, f1)
fibb n  =  snd $ execState (replicateM n fsum) (1, 0)

while var fun s = do
                     n <- readIORef var
                     if (fun n)
                        then do s
                                while var fun s
                        else return ()

factorial n  =  do
                   r <- newIORef 1
                   i <- newIORef 1
                   while i (<= n) ( do
                                       ival <- readIORef i
                                       modifyIORef r (* ival)
                                       modifyIORef i (+ 1)
                                  )
                   readIORef r

recursiveSum []      =  do
                            tell $ "0"
                            return 0

recursiveSum (x:xs)  =  do
                            tell $ "(" ++ (show x)  ++ " + "
                            tail <- recursiveSum xs
                            tell $ ")"
                            return (x + tail)

sum' l = runWriter (recursiveSum l)

-- emulate 1000 flips and count diviation
difference  =  do
                   l <- replicateM 1000 $ randomRIO (0, 1) :: IO [Int]
                   return (500 - (sum l))

-- count diviations in 1000 emulations
differences  =  replicateM 1000 $ difference

-- count avarage absolute value of diviation
averagediff  =  do
                    l <- differences
                    return ((fromIntegral (sum (map abs l))) / 1000)

-- utilities
instances _ [] = 0
instances e (x:xs) | e == x    = (1 + (instances e xs))
                   | otherwise = (instances e xs)
indent v l = take l ((show v) ++ (replicate l ' '))

-- build histogram of frequences of elements in l
histogram mn mx l  =  fst $ until (\(a, b) -> b < mn) pp ([], mx)
                                  where pp (xs, v)  =  ((( (indent v 4) ++ (replicate (instances v l) '*')):xs), v - 1)

printresults = do
                  putStrLn "Enter file name"
                  filename <- getLine
                  handle <- openFile filename WriteMode
                  l <- differences
                  mapM_ (\s -> hPutStrLn handle s) (histogram (minimum l) (maximum l) l)
                  hClose handle
