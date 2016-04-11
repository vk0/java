--Kazama gave Shaun a string of even length, and asked him to swap the characters at the even positions with the next character. Indexing starts at 00.

--Formally, given a string str of length LL where LL is even, Shaun has to swap the characters at position ii and i+1i+1, where i∈i∈{0,2,..,L−20,2,..,L−2}.

--For example, if str = "abcdpqrs", L=8L=8. We have to swap the characters at positions:
--{(0,1),(2,3),(4,5),(6,7)(0,1),(2,3),(4,5),(6,7)}

--So, answer will be "badcqpsr".

--Input Format

--The first line contains an integer, TT, the number of test cases.
--TT lines follow, each containing some string str.

--Output Format

--For each test case, print the new string as explained in the problem statement.

--Constraints

--1≤T≤101≤T≤10
--1<L≤101<L≤1055
--LL is even
--str consists of lowercase English characters, {a−za−z}.

--Sample Input

--2
--abcdpqrs
--az
--Sample Output

--badcqpsr
--za
--Explanation

--Test case #00: This is the same example as mentioned in the problem statement.
--Test case #01: Here LL is 22, so we have to swap the characters at position (0,1)(0,1) only.

main :: IO ()
main = do
    n <- getLine
    input <- getContents
    mapM_ putStrLn $ map swap $ words input

swap :: String -> String
swap []              = []
swap (odd:even:rest) = even : odd : swap rest