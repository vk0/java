--For a given integer KK, print the first KK rows of Pascal's Triangle. Print each row with each value separated by a single space. The value at the nnthth row and rrthth column of the triangle is equal to n!/(r!∗(n−r)!)n!/(r!∗(n−r)!) where indexing starts from 00. These values are the binomial coefficients.

--The Pascal Triangle

--1
--1 1
--1 2 1
--1 3 3 1
--1 4 6 4 1
--....
--Input Format

--A single line of input, integer KK.

--Constraints

--2<=K<=102<=K<=10

--Output Format

--Output the first KK rows of Pascal's triangle.

--Sample Input

--4
--Sample Output

--1
--1 1
--1 2 1
--1 3 3 1

import Data.List(intercalate)

main :: IO ()
main = do
    input <- getLine
    let n = read input :: Int
    mapM_ (putStrLn . makeReadable) $ take n pascalTriangle

makeReadable :: [Int] -> String
makeReadable = intercalate " " . map show

pascalTriangle :: [[Int]]
pascalTriangle = map row [0..]

row :: Int -> [Int]
row rowNumber = map calc [0..rowNumber]
    where calc e = (factorial rowNumber) `div` ((factorial e) * factorial (rowNumber-e))

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)