-- Версия 5
evenSum :: Integral a => [a] -> a

evenSum l = mysum 0 (filter even l)
    where
      mysum n [] = n
      mysum n (x:xs) = mysum (n+x) xs