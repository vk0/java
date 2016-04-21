--You are given a string, str, of length N consisting of lowercase letters of alphabet. You have to remove all those characters from str which have already appeared in it, i.e., you have to keep only first occurance of each letter.

--Input Format
--First line of input contains a string str of length N.

--Output Format
--A string with removed characters as described in the problem.

--Constraints
--1 <= N <= 30000
--str will contain only lowercase letters ('a'-'z').

--Sample Input #00

--aabc
--Sample Output #00

--abc
--Sample Input #01

--ccbabacc
--Sample Output #01

--cba
--Explanation
--Test Case #00: Here you have to remove 'a' at index 1 (0 based indexing) because it has already appeared at index 0.
--Test Case #01: Here you have to remove 'c' from index 1, 6 and 7, because 'c' has already appeared at index 0. Similarly you have to remove 'b' from index 4 and 'a' from index 5.

import Data.List

main = do
    str <- getLine
    putStr (nub str)