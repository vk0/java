--Будем задавать точки на плоскости парами типа (Double, Double). Реализуйте функцию dist, которая возвращает расстояние между двумя точками, передаваемыми ей в качестве аргументов.

--dist :: (Double, Double) -> (Double, Double) -> Double
--dist x y = ???

dist :: (Double, Double) -> (Double, Double) -> Double
dist x y = sqrt $ (fst y - fst x) ^ 2 + (snd y - snd x) ^ 2