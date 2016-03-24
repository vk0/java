-- Версия 8
--  evenSum [1,2,3,4]
--⇒ foldl' (+) 0 (filter even [1,2,3,4])
--⇒ foldl' (+) 0 [2,4]
--⇒ foldl' (+) (0+2) [4]
--⇒ foldl' (+) 2 [4]
--⇒ foldl' (+) (2+4) []
--⇒ foldl' (+) 6 []
--⇒ 6

import Data.List (foldl')
evenSum :: Integral a => [a] -> a
evenSum l = foldl' (+) 0 (filter even l)