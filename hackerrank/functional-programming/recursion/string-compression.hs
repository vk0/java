--Joseph and Jane are making a contest for apes. During the process, they have to communicate frequently with each other. Since they are not completely human, they cannot speak properly. They have to transfer messages using postcards of small sizes.
--To save space on the small postcards, they devise a string compression algorithm:

--If a character, chch, occurs n(>1)n(>1) times in a row, then it will be represented by {ch}{n}{ch}{n}, where {x}{x} is the value of xx. For example, if the substring is a sequence of 44 'a' ("aaaa"), it will be represented as "a4".

--If a character, chch, occurs exactly one time in a row, then it will be simply represented as {ch}{ch}. For example, if the substring is "a", then it will be represented as "a".

--Help Joseph to compress a message, msg.

--Input

--The only line of input contains a string, msg.

--Output

--Print the string msg as a compressed message.

--Constraints

--1≤length(msg)≤1051≤length(msg)≤105
--msg consists of lowercase English characters (a−za−z) only.
--Sample Input #00

--abcaaabbb
--Sample Output #00

--abca3b3
--Sample Input #01

--abcd
--Sample Output #01

--abcd
--Sample Input #02

--aaabaaaaccaaaaba
--Sample Output #02

--a3ba4c2a4ba
--Explanation
--Sample Case #00: msg = "abcaaabbbabcaaabbb". Here, the first 33 characters occur exactly once, and the rest of them occur 33 times in a sequence.

--Sample Case #01: msg = "abcdabcd". As there is no multiple consecutive occurrence of any character, the compressed message will be same as original one.

--Sample Case #02: msg = "aaabaaaaccaaaabaaaabaaaaccaaaaba". In the first 3 occurrences, 'a' is repeated 44 times, while in the last occurrence, there is only one 'a'. Also,'c' occurs two times, and 'b' occurs one time in both occurrences.


import Data.List (group)

compress :: String -> String
compress = concatMap f . group where
  f [] = []
  f xs = let len = length xs
         in if (len == 1)
              then xs
              else head xs : show len

main :: IO ()
main = do
  s <- getLine
  putStrLn $ compress s