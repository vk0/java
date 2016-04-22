--Replicate the elements of a list a given number of times.

--Example:

--* (repli '(a b c) 3)
--(A A A B B B C C C)
--Example in Haskell:

--> repli "abc" 3
--"aaabbbccc"

repli :: [a] -> Int -> [a]
repli xs n = concatMap (replicate n) xs

--or, in Pointfree style:

repli = flip $ concatMap . replicate

--alternatively, without using the replicate function:

repli :: [a] -> Int -> [a]
repli xs n = concatMap (take n . repeat) xs

--or, using the list monad:

repli :: [a] -> Int -> [a]
repli xs n = xs >>= replicate n

--or, a more verbose solution without the use of replicate:

repli :: [a] -> Int -> [a]
repli xs n = foldl (\acc e -> acc ++ repli' e n) [] xs
    where
      repli' _ 0 = []
      repli' x n = x : repli' x (n-1)

--or, a version that does not use list concatenation:

repli :: [a] -> Int -> [a]
repli [] _ = []
repli (x:xs) n = foldr (const (x:)) (repli xs n) [1..n]