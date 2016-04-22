{-
 - Lets implement the UNIX echo command
 - The program arguments are simply printed to the standard output.
 - If the first argument is -n, this argument is not printed, and no trailing newline is printed
 -}

import System.Random
import System.Environment
--cabal install random
--haskell-compiler 9-input-and-output.hs

main = do
    args <- getArgs
    print1 args


print1 all@(arg:args)
    | arg == "-n" = putStr $ init $ foldl (\acc arg->acc++arg++" " ) [] args
    | otherwise = putStrLn $ init $ foldl (\acc arg->acc++arg++" " ) [] all

{- Write a lottery number picker
 - This function should take a StdGen instance, and produce a list of six unique numbers between 1 and 49, in numerical order
 -}
lottery :: StdGen -> [Int]
lottery gen = take 6 (randomRs (1,49) gen)
