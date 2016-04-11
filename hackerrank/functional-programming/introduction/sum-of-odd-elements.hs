--You are given a list. Return the sum of odd elements from the given list. The input and output portions will be handled automatically. You need to write a function with the recommended method signature.

--Constraints

--The list will have 1−1001−100 elements.
--Each element will be an integer XX where −100<=X<=100−100<=X<=100.

--Sample Input

--3
--2
--4
--6
--5
--7
--8
--0
--1
--Sample Output

--16
--Explanation

--Sum of odd elements is 3+5+7+1=163+5+7+1=16
--Method Signature

--Number Of Parameters: 1
--Parameters: [list]
--Returns: Number
--For Hackers Using Clojure

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- (fn[lst]___________________________)
--For Hackers Using Scala

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- def f(arr:List[Int]):Int = __________________
--For Hackers Using Haskell

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- f arr = ______________________
--For Hackers Using other Languages

--You have to read input from standard input and write output to standard output. Please follow the input/output format mentioned above.

--NOTE: You only need to submit the code above after filling in the blanks appropriately. The input and output section will be handled by us. The focus is on writing the correct function.

f arr = sum (filter (odd) arr)

-- This part handles the Input/Output and can be used as it is. Do not change or modify it.
main = do
   inputdata <- getContents
   putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata
