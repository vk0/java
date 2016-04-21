--Contributed by Abhiranjan Kumar

--Convex Hull of a set of points, in 2D plane, is a convex polygon with minimum area such that each point lies either on the boundary of polygon or inside it.

--Let's consider a 2D plane, where we plug pegs at the points mentioned. We enclose all the pegs with a elastic band and then release it to take its shape. The closed structure formed by elastic band is similar to that of convex hull.

--Convex Hull
--In the above figure, convex hull of the points, represented as dots, is the polygon formed by blue line.

--Tasks
--Given a set of N points, Find the perimeter of the convex hull for the points.

--Input Format
--First line of input will contain a integer, N, number of points. Then follow N lines where each line contains the coordinate, xi yi, of ith point.

--Output Format
--Print the perimeter of convex hull for the given set of points. An error margin of +/- 0.2 is acceptable.

--Constraints
--3 <= N <= 104
--0 <= xi, yi <= 104
--There exists, at least, three points which are non-colinear.

--Sample Input

--6
--1 1
--2 5
--3 3
--5 3
--3 2
--2 2
--Sample Output

--12.2
--Explanation
--For the given set of points in sample input, the convex hull is formed by the triangle whose vertices are given by (1, 1), (2, 5), (5, 3). Here perimeter of the hull is 12.200792856.

import           Control.Applicative (liftA, (<$>))
import           Control.Monad       (forM)
import           Data.List           (minimumBy, sortBy)
import           Text.Printf

data Direction = LeftTurn | RightTurn | Straight
  deriving (Eq, Show)

data Point = Point {
  xa :: Double,
  ya :: Double
}  deriving (Eq, Show)

point :: [Int] -> Point
point [x, y] = Point (fromIntegral x) (fromIntegral y)

-- https://en.wikipedia.org/wiki/Graham_scan
angle :: Point -> Point -> Point -> Direction
angle p1 p2 p3
  | turn > 0  = LeftTurn
  | turn < 0  = RightTurn
  | turn == 0 = Straight
  where turn = (xa p2 - xa p1) * (ya p3 - ya p1) - (xa p3 - xa p1) * (ya p2 - ya p1)

perimeter :: [Point] -> Double
perimeter ps = go (ps ++ [head ps]) where
    go (x:y:zs) = line x y + go (y:zs)
    go _ = 0
    line (Point x y) (Point x' y') = sqrt ((y'-y) ** 2 + (x'-x) ** 2)

lowestY :: [Point] -> Point
lowestY [] = error "Error: no input"
lowestY xs = minimumBy comp xs where
  comp p1 p2
    | ya p1 > ya p2 = GT
    | ya p1 == ya p2 && xa p1 > xa p2 = GT
    | ya p1 == ya p2 && xa p1 == xa p2 = EQ
    | otherwise = LT

angleFromX :: Point -> Point -> Double
angleFromX p1 p2
  | ag >= 0 = ag
  | ag < 0  = ag + 2*pi
    where ag = atan2 (ya p2 - ya p1) (xa p2 - xa p1)

grahamScan :: [Point] -> [Point]
grahamScan ps
  | length ps >= 3 = go [p] (tail sorted) where
      sorted = sortBy (comparing' (angleFromX p)) ps
      p = lowestY ps
      comparing' f p1 p2
        | f p1 < f p2 = LT
        | f p1 == f p2 && ya p1 < ya p2 = LT
        | otherwise = GT
      go (x:xs) (y:z:zs)
        | angle x y z == LeftTurn  = go (y:x:xs) (z:zs)
        | angle x y z == RightTurn = go xs (x:z:zs)
        | angle x y z == Straight  = go (x:xs) (z:zs)
      go xs [z] = z : xs

main :: IO ()
main = do
  n <- readLn
  ps <- forM [1..n] $ \_ ->
    (point . map (\x -> read x :: Int)) <$> liftA words getLine
  printf "%.1f\n" . perimeter $ grahamScan ps