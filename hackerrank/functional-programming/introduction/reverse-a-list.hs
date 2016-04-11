--You are given a list of NN elements. Reverse the list without using the reverse function. The input and output portions will be handled automatically. You need to write a function with the recommended method signature.

--Input Format

--Each element, XX, of the list is displayed on a separate line.

--Output Format

--The output is the reverse of the input list.

--Sample Input

--19
--22
--3
--28
--26
--17
--18
--4
--28
--0
--Sample Output

--0
--28
--4
--18
--17
--26
--28
--3
--22
--19
--Method Signature

--Number Of Parameters: 1
--Parameters: [list]
--Returns: List or Vector
--Constraints

--1<=N<=1001<=N<=100
--0<=X<=1000<=X<=100.

--For Hackers Using Clojure

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- (fn[lst]___________________________)
--For Hackers Using Scala

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- def f(arr:List[Int]):List[Int] = __________________
--For Hackers Using Haskell

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- rev l = __________________
--For Hackers Using other Languages

--You have to read input from standard input and write output to standard output. Please follow the input/output format mentioned above.

--NOTE: You only need to submit the code above after filling in the blanks appropriately. The input and output section will be handled by us. The focus is on writing the correct function.

rev :: [a] -> [a]
rev [] = []
rev (x:xs) = rev xs ++ [x]