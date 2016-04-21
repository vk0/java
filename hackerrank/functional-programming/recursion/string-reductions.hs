--Given a string, str=s1,s2…snstr=s1,s2…sn, consisting of nn lowercase English characters (a−za−z), remove all of the characters that occurred previously in the string. Formally, remove all characters, sisi, for:

--∃j,sj=si∃j,sj=si and j<ij<i
--Input Format

--A single line of input containing a string strstr of length nn.

--Constraints

--1≤n≤1051≤n≤105
--si∈{a, b,…, z},where 1≤i≤nsi∈{a, b,…, z},where 1≤i≤n
--Output Format

--Print the string after removing all the characters that occurred previously.

--Sample Input #00

--accabb
--Sample Output #00

--acb
--Sample Input #01

--abc
--Sample Output #01

--abc
--Sample Input #02

--pprrqq
--Sample Output #02

--prq
--Explanation

--Test case #00: For str= ′′accabb′′str= ″accabb″, characters at indexes 3,4,63,4,6 are removed as they have already occurred.
--Test case #01: As each character occurs only once, nothing is removed.
--Test case #02: For str= ′′pprrqq′′str= ″pprrqq″, each character occurs twice. The second of these characters is removed. Characters at positions 2,42,4 and 66 are removed.

deDup :: Eq a => [a] -> [a]
deDup [] = []
deDup (x:xs) = x : deDup (filter (/= x) xs)

main :: IO ()
main = do
  s <- getLine
  putStr $ deDup s