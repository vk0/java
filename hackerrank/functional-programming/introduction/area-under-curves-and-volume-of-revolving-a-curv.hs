--Definite Integrals via Numerical Methods

--This relates to definite integration via numerical methods.

--Consider the algebraic expression given by:

--(a(a11)x)xbb11 ++ (a(a22)x)xbb22 ++ (a(a33)x)xbb33 ......(a......(ann)x)xbbnn

--For the purpose of numerical computation, the area under the curve y=f(x)y=f(x) between the limits aa and bb can be computed by the Limit Definition of a Definite Integral.

--Here is some background about areas and volume computation.

--Using equal subintervals of length =0.001=0.001, you need to:

--Evaluate the area bounded by a given polynomial function of the kind described above, between the given limits of LL and RR.

--Evaluate the volume of the solid obtained by revolving this polynomial curve around the xx-axis.

--An absolute error margin of 0.020.02 will be tolerated.

--Input Format

--The first line contains NN integers separated by spaces, which are the values of aa11,a,a22...a...aNN.
--The second line contains NN integers separated by spaces, which are the values of bb11,b,b22...b...bNN.
--The third line contains two space separated integers, LL and RR, the lower and upper range limits in which the integration needs to be performed, respectively.

--Constraints

--−1000<=a<=1000−1000<=a<=1000
--−20<=b<=20−20<=b<=20
--1<=L<R<=201<=L<R<=20

--Output Format

--The first line should contain the area between the curve and the xx-axis, bound between the specified limits.
--The second line should contain the volume of the solid obtained by rotating the curve around the xx-axis, between the specified limits.

--Sample Input

--1 2 3 4 5
--6 7 8 9 10
--1 4
--Explanation

--The algebraic expression represented by:

--(1)x(1)x66+(2)x+(2)x77+(3)x+(3)x88+(4)x+(4)x99+(5)x+(5)x1010

--We need to find the area of the curve enclosed under this curve, between the limits x=1x=1 and 44. We also need to find the volume of the solid formed by revolving this curve around the xx-axis between the limits x=1x=1 and 44.

--Sample Output

--2435300.3
--26172951168940.8
--Scoring

--All test cases are weighted equally. You need to clear all the tests in a test case.

import Text.Printf (printf)

-- This function should return a list [area, volume].
solve :: Int -> Int -> [Int] -> [Int] -> [Double]
solve l r a b = [area, volume]
    where results = map (polynomial a b) (inputRange l r 0.001)
          area = sum $ map (areaRectangle 0.001) results
          volume = sum $ map (volumeCilinder 0.001) results

inputRange :: Int -> Int -> Double -> [Double]
inputRange start end step = [first,second..last]
    where first  = fromIntegral start
          second = first + step
          last   = fromIntegral end

polynomial :: [Int] -> [Int] -> Double -> Double
polynomial coefficients degrees x = sum $ map (\(c,d) -> c * x**d) (zip coef degr)
    where coef = map fromIntegral coefficients
          degr = map fromIntegral degrees

areaRectangle :: Double -> Double -> Double
areaRectangle width height = width * height

volumeCilinder :: Double -> Double -> Double
volumeCilinder height radius = (pi * radius**2) * height

--Input/Output.
main :: IO ()
main = getContents >>= mapM_ (printf "%.1f\n"). (\[a, b, [l, r]] -> solve l r a b). map (map read. words). lines