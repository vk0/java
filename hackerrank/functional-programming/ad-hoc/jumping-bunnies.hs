--Bunnies are very cute animals who likes to jump a lot. Every bunny has his own range of jump. Lets say there are NN bunnies and ithith (i∈[1,N])(i∈[1,N]) bunny jumps jiji units. Consider a 1-D plane, where initially bunnies are at 00. All of them starts jumping in forward direction.

--For example, consider the case of kthkth bunny. Initially he is at 00. After first jump, he will be at point jkjk. After second, he will be at 2×jk2×jk and so on. After mthmth jump, he will be at point m×jkm×jk.

--Two bunnies can only meet each other when they are on the ground. When on the ground, a bunny can wait any amount of time. Being a social animal, all of them decide to meet at the next point where all of them will be on the ground. You have to find the nearest point where all the bunnies can meet.

--For example, if there are N=3N=3 bunnies where j1=2j1=2, j2=3j2=3, j3=4j3=4. Nearest point where all bunnies can meet again is at 1212. First bunny has to jump six times, for second it is 44 times and for third it is 33 times.

--Help bunnies to find the nearest point where they can meet again.

--Input Format
--First line will contain an integer, NN, represeting the number of bunnies. Second line will contain NN space separated integer, j1,j2,⋯,jNj1,j2,⋯,jN, representing the jumping distance of them.

--Output Format
--Print the nearest location where all bunnies can meet again.

--Constraints
--2≤N≤102≤N≤10
--1≤ji≤1061≤ji≤106
--For each test case it is guaranteed that solution will not exceed 2×10182×1018.

--Sample Input #00

--3
--2 3 4
--Sample Output #00

--12
--Sample Input #01

--2
--1 3
--Sample Output #01

--3
--Explanation
--Sample Case #00: This is the same example mentioned in the statement above.
--Sample Case #01: First bunny has to jump 33 times to point 33, whereas second bunny has to jump only one time to go at point 33. Point 33 will serve as their meeting point.

main :: IO ()
main = do
    n <- readLn :: IO Int
    input <- getContents
    let numbers = map read (words input) :: [Int]
    print $ lcm' numbers

-- Least common divisor for array of numbers.
lcm' :: Integral a => [a] -> a
lcm' = foldl1 lcm