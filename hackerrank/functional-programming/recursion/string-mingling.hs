--Pawel and Shaka recently became friends. They believe their friendship will last forever if they merge their favorite strings.

--The lengths of their favorite strings are the same, nn. Mingling two strings, P=p1p2…pnP=p1p2…pn and Q=q1q2…qnQ=q1q2…qn, both of length nn, will result in the creation of a new string RR of length 2×n2×n. It will have the following structure:

--R=p1q1p2q2…pnqn
--R=p1q1p2q2…pnqn
--You are given two strings PP (Pawel's favorite) and QQ (Shaka's favorite), determine the mingled string RR.

--Input Format

--The first line of input contains the string PP.
--The second line contains QQ.

--Output Format

--Print the mingled string, RR.

--Constraints

--1≤n≤1051≤n≤105
--The string only consists of lowercase English characters (a−za−z).
--length(P) = length(Q) =n=n
--Sample Input #00

--abcde
--pqrst
--Sample Output #00

--apbqcrdset
--Sample Input #01

--hacker
--ranker
--Sample Output #01

--hraacnkkeerr
--Explanation

--Sample Case #00:

--P=a   b   c   d   eP=a   b   c   d   e
--Q=p   q   r   s   tQ=p   q   r   s   t
--R=ap bq cr ds etR=ap bq cr ds et


--Sample Case #01:

--P=h   a   c   k   e   rP=h   a   c   k   e   r
--Q=r   a   n   k   e   rQ=r   a   n   k   e   r
--R=hr aa cn kk ee rr

main :: IO ()
main = do
    p <- getLine
    q <- getLine
    putStrLn $ alternate p q

alternate :: [Char] -> [Char] -> [Char]
alternate [] [] = []
alternate a  [] = a
alternate [] b  = b
alternate (a:as) (b:bs) = a : b : alternate as bs