--Create an array of NN amount of integers, where NN is given as the input. This can be any array with NN integers. For example, when N=4N=4 you could return [1,1,1,1][1,1,1,1] or [1,2,3,4][1,2,3,4].

--Sample Input

--3
--Sample Output

--[1, 2, 3]
--Output Format

--The output only indicates the number of elements contained in the list, array or vector you created.

--Constraints

--N<=100N<=100
--The members of the List/Vector/Array returned should be integers.

--Method Signature

--Number Of Parameters: 1
--Parameters: [n]
--Returns: List or Vector
--For Hackers Using Clojure

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- (fn[n]___________________________)
--For Hackers Using Scala

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- def f(num:Int) : List[Int] = __________________
--For Hackers Using Haskell

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- fn n = __________________
--NOTE: You only need to submit the code above after filling in the blanks appropriately. The input and output section will be handled by us. The focus is on writing the correct function.

fn n = replicate n n