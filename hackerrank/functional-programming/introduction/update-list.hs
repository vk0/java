--Update the values of a list with their absolute values. The input and output portions will be handled automatically during grading. You only need to write a function with the recommended method signature.

--Input Format

--There are NN integers, each on a separate line. These are the NN elements of the input array.

--Output Format

--Output the absolute value of NN integers, each on a separate line in the same input order.

--Sample Input

--2
---4
--3
---1
--23
---4
---54
--Sample Output

--2
--4
--3
--1
--23
--4
--54
--Constraints

--The list will have no more than 100100 integers.
--Each integer, XX, in the list: −100<=X<=100−100<=X<=100.

--Recommended Method Signature

--Number Of Parameters: 1
--Parameters: [list]
--Returns: List or Vector
--For Hackers Using Clojure

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- (fn[lst]___________________________)
--For Hackers Using Scala

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- def f(arr:List[Int]):List[Int] = __________________
--For Hackers Using Haskell

--This will be the outline of your function body (fill in the blank portion marked by underscores):

--f arr = ___________________
--For Hackers Using other Languages

--You have to read input from standard input and write output to standard output. Please follow the input/output format mentioned above.

--NOTE: You only need to submit the code above after filling in the blanks appropriately. The input and output section will be handled by us. The focus is on writing the correct function.

-- Enter your code here. Read input from STDIN. Print output to STDOUT

f arr = map abs arr

-- This section handles the Input/Output and can be used as it is. Do not modify it.
main = do
   inputdata <- getContents
   mapM_ putStrLn $ map show $ f $ map (read :: String -> Int) $ lines inputdata
