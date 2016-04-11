--The series expansion of eexx is given by:

--1+x+x1+x+x22/2!+x/2!+x33/3!+x/3!+x44/4!/4! +.......+.......
--Evaluate eexx for given values of xx by using the above expansion for the first 1010 terms.

--Input Format

--The first line contains an integer NN, the number of test cases.
--NN lines follow. Each line contains a value of xx for which you need to output the value of eexx using the above series expansion. These input values have exactly 44 decimal places each.

--Output Format

--Output NN lines, each containing the value of eexx, computed by your program.

--Constraints

--1<=N<=501<=N<=50
--−20.00<=x<=20.00−20.00<=x<=20.00
--Var, Val in Scala and def and defn in Clojure are blocked keywords. The challenge is to accomplish this without either mutable state or direct declaration of local variables.

--Sample Input

--4
--20.0000
--5.0000
--0.5000
---0.5000
--Sample Output

--2423600.1887
--143.6895
--1.6487
--0.6065
--Explanation

--The output has the computed values of eexx corresponding to each test case. They are correct up to 44 decimal places and on separate lines.

--Scoring

--All test cases carry an equal weight in the final score. For your solution to pass a given test case, all the values of eexx computed by you must be within +/−0.1+/−0.1 of the expected answers. This tolerance level has been kept to account for slightly different answers across different languages.

solve :: Double -> Double
solve x = sum $ take 10 [x**y/product [1..y] | y <- [0..]]

main :: IO ()
main = getContents >>= mapM_ print. map solve. map (read::String->Double). tail. words