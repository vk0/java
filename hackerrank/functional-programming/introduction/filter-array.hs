--Filter a given array of integers and output only those values that are less than a specified value XX. The output integers should be in the same sequence as they were in the input. You need to write a function with the recommended method signature for the languages mentioned below. For the rest of the languages, you have to write a complete code.

--Input Format

--The first line contains the delimiter XX.
--The next BB lines each contain an integer, which represents the elements of the list/array. You have to read the input to the End-Of-File.

--Output Format

--Print all the integers from the array that are less than the given upper limit XX in value on separate lines. The sequence should be the same as it was in the original array.

--Constraints

--1<=B<=1001<=B<=100
--For any element, YY in the array, −100<=Y<=100−100<=Y<=100
--−100<=X<=100−100<=X<=100

--Note

--The purpose of this challenge is to learn how to write your own implementation of a filter function. We recommend not using the inbuilt library function.

--Sample Input

--3
--10
--9
--8
--2
--7
--5
--1
--3
--0
--Sample Output

--2
--1
--0
--Explanation

--2,1,2,1, and 00 are the list elements that are less than the XX delimiter, 33. They are displayed in the same order as they were in the original list.

--Recommended Method Signature

--Number Of Parameters: 2
--Parameters: [upper-limit(X) list]
--Returns: List or Vector
--For Hackers Using Clojure

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- (fn[delim lst]___________________________)
--For Hackers Using Scala

--This will be the outline of your function body (fill in the blank portion marked by underscores):

-- def f(delim:Int,arr:List[Int]):List[Int] = __________________
--For Hackers Using Haskell

--This will be the outline of your function body (fill in the blank portion marked by underscores):

--f n arr = _____________________
--For Hackers Using other Languages

--You have to read input from standard input and write output to standard output. Please follow the input/output format mentioned above.

--NOTE: You only need to submit the code above after filling in the blanks appropriately. The input and output section will be handled by us. The focus is on writing the correct function.

f :: Int -> [Int] -> [Int]
f n arr = filter (< n) arr

-- The Input/Output section. You do not need to change or modify this part
main = do
    n <- readLn :: IO Int
    inputdata <- getContents
    let
        numbers = map read (lines inputdata) :: [Int]
    putStrLn . unlines $ (map show . f n) numbers
