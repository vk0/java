--You are incharge of data transfer between two data-centres. Each set of data is represented by a pair of strings. Over a period of time you have observed a trend: most of the times both strings share some prefix. You want to utilize this observation to design a data compression algorithm which will be used to reduce amount of data to be transferred.

--You are given two strings, xx and yy, representing the data, you need to find the longest common prefix (pp) of the two strings. Then you will send substring pp, x′x′ and y′y′, where x′x′ and y′y′ are the substring left after stripping pp from them.

--For example, if x=‘‘abcdefpr"x=‘‘abcdefpr" and y=‘‘abcpqr"y=‘‘abcpqr", then p=‘‘abc",x′=‘‘defpr",y′=‘‘pqr"p=‘‘abc",x′=‘‘defpr",y′=‘‘pqr".

--Input Format
--Input will contain two lines. First line will contain string xx and second line string yy.

--Output Format
--In first line, print the length of substring pp, followed by prefix pp. In second line, print the length of substring x′x′, followed by substring x′x′. Similary in third line, print the length of substring y′y′, followed by substring y′y′.

--Constraints

--xx and yy will contain only lowercase Latin characters ('a'-'z').
--1≤length(x),length(y)≤1051≤length(x),length(y)≤105
--Sample Input #00

--abcdefpr
--abcpqr
--Sample Output #00

--3 abc
--5 defpr
--3 pqr
--Explanation #00
--Already explained above in the problem statement.

--Sample Input #01

--kitkat
--kit
--Sample Output #01

--3 kit
--3 kat
--0
--Explanation
--Here pp is ‘‘kit"‘‘kit" which is also yy. So x′x′ will be ‘‘kat"‘‘kat", while y′y′ will be an empty string.

--Sample Input #02

--puppy
--puppy
--Sample Output #02

--5 puppy
--0
--0
--Explanation
--Since both strings are same, prefix will cover both the strings, and hence x′x′ and y′y′ will be empty strings.

longestPrefix :: String -> String -> String
longestPrefix = f [] where
  f acc [] _ = reverse acc
  f acc _ [] = reverse acc
  f acc (x:xs) (y:ys)
    | x == y    = f (x:acc) xs ys
    | otherwise = reverse acc

subString :: String -> String -> (Int, String)
subString xs prefix = let s = drop (length prefix) xs
                      in  (length s, s)

main :: IO ()
main = do
  a <- getLine
  b <- getLine
  let p = longestPrefix a b
  putStrLn $ show (length p) ++ " " ++ p
  putStrLn $ show (fst (subString a p)) ++ " " ++ snd (subString a p)
  putStrLn $ show (fst (subString b p)) ++ " " ++ snd (subString b p)