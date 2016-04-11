--(*) Find the last element of a list.

--(Note that the Lisp transcription of this problem is incorrect.)

--Example in Haskell:

--Prelude> myLast [1,2,3,4]
--4
--Prelude> myLast ['x','y','z']
--'z'

myLast :: [a] -> a
myLast [] = error "No end for empty lists!"
myLast [x] = x
myLast (_:xs) = myLast xs

myLast' = foldr1 (const id)

myLast'' = foldr1 (flip const)

myLast''' = head . reverse

myLast'''' = foldl1 (curry snd)

myLast''''' [] = error "No end for empty lists!"
myLast''''' x = x !! (length x -1)