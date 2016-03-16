--Реализуйте функцию distance, возвращающую расстояние между двумя точками.

data Point = Point Double Double

origin :: Point
origin = Point 0.0 0.0

distanceToOrigin :: Point -> Double
distanceToOrigin (Point x y) = sqrt (x ^ 2 + y ^ 2)

distance :: Point -> Point -> Double
distance (Point x y) (Point x1 y1) = sqrt ((x - x1) ^ 2 + (y - y1) ^ 2)