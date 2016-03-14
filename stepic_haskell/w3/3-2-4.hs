--Реализуйте функцию filterDisj, принимающую два унарных предиката и список, и возвращающую список элементов, удовлетворяющих хотя бы одному из предикатов.

--GHCi> filterDisj (< 10) odd [7,8,10,11,12]
--[7,8,11]

filterDisj :: (a -> Bool) -> (a -> Bool) -> [a] -> [a]
filterDisj _ _ [] = []
filterDisj p1 p2 (x : xs) = if (p1 x || p2 x) then x : filterDisj p1 p2 xs
                            else filterDisj p1 p2 xs