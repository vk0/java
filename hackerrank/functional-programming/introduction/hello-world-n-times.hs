--Print "Hello World" NN amount of times. The input portion will be handled automatically. You need to write a function with the recommended method signature.

--Input Format

--A single line of input containing integer NN, the number of times to print "Hello World".

--Output Format

--Output NN lines, each containing "Hello World".

--Constraints

--0<=N<=500<=N<=50

--Sample Input

--4
--Sample Output

--Hello World
--Hello World
--Hello World
--Hello World
--Recommended Method Signature

--Number Of Parameters: 1
--Parameters: [n]
--Returns: nil
--For Hackers Using Clojure

--This will be the outline of your function body (fill up the blank portion marked by underscores):

-- (fn[n]___________________________)
--For Hackers Using Scala

--This will be the outline of your function body (fill up the blank portion marked by underscores):

-- def f(n: Int) = ______________________
--For Hackers Using Haskell

--This will be the outline of your function body (fill up the blank portion marked by underscores):

-- hello_worlds n = ______________________
--For Hackers Using other Languages

--You have to read input from standard input and write output to standard output. Please follow the input/output format mentioned above.

--NOTE: You only need to submit the code above, after filling in the blanks appropriately. The input and output section will be handled by us. The focus is on writing the correct function.

hello_worlds 0 = return ()
hello_worlds x = do putStrLn "Hello World"
                    hello_worlds (x-1)

-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
   n <- readLn :: IO Int
   hello_worlds n