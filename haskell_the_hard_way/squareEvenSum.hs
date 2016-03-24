-- Версия 1
-- squareEvenSum  [1..4]
import Data.List (foldl')
sum' :: (Num a) => [a] -> a
sum' = foldl' (+) 0
squareEvenSum :: Integral a => [a] -> a
squareEvenSum = sum' . (map (^2)) . (filter even)