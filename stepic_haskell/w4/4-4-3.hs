--Реализуйте функции distance, считающую расстояние между двумя точками с вещественными координатами, и manhDistance, считающую манхэттенское расстояние между двумя точками с целочисленными координатами.

data Coord a = Coord a a

distance :: Coord Double -> Coord Double -> Double
distance (Coord x y) (Coord x1 y1) = sqrt((x - x1)^2 + (y - y1)^2)

manhDistance :: Coord Int -> Coord Int -> Int
manhDistance (Coord x y) (Coord x1 y1) = abs (x - x1) + abs (y - y1)