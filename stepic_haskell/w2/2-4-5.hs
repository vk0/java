--Имея функцию ip = show a ++ show b ++ show c ++ show d определите значения a, b, c, d так, чтобы добиться следующего поведения:

--GHCi> ip
--"127.224.120.12"

data MyIp = MyIp Int
instance Show MyIp where
  show (MyIp a) = show a ++ "."
a = MyIp 127
b = MyIp 224
c = MyIp 120
d = 12