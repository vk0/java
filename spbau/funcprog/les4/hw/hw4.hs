module Homework (uniform34, uniform34', mygcd, count, sumdigits, series, integral, sqrt') where

--uniform distribution
uniform' a b x = if (x >= (min a b)) && (x <= (max a b))
			then 1/(abs (b-a))
			else 0
--uniform distribution on [3, 4]
uniform34 x = uniform' 3 4 x

uniform34' x = if (x >= 3) && (x <= 4)
			then 1
			else 0
 
--greatest common divisior interface function
mygcd a b = gcd' (abs a) (abs b)
--equlid algorithm for gcd
gcd' a b = if (b /= 0)
		then gcd' b (a `rem` b)
		else a

--go threogh number by digits
bydigit' num f = fst $ until (\x -> (snd x) == 0) f (0, num)

--counts decimal digits in a number
count' num = bydigit' num (\p -> ((fst p) + 1, div (snd p) 10))
--interface for count'
count num = if (num /= 0)
		then count' (abs num)
		else 1

--summarizes digits in a number
sumdigits' num = bydigit' num (\p -> ((fst p) + (rem (snd p) 10), div (snd p) 10))
--interface for sumdigits'
sumdigits num = sumdigits' (abs num)

--utilities for 4-tuples
fst' = \(a,_,_,_) -> a
snd' = \(_,a,_,_) -> a
trd' = \(_,_,a,_) -> a
frh' = \(_,_,_,a) -> a
update' t = (snd' t, trd' t, (snd' t) + (trd' t) - 2*(fst' t), 1 + (frh' t))
--calculate recurcive series
series n = fst' $ until (\t -> frh' t >= n) update' (1, 2, 3, 0)

--integral utilities
step' a b n = (abs (b - a))/n
sumf' f b e s = fst $ until (\p -> snd p > e) (\p -> ((fst p) + f (snd p), (snd p) + s)) (0, b)
--compute integral of f from a to b with n steps
integral f a b n = h*(((f a) + (f b))/2 + (sumf' f (min (a+h) (b-h)) (max (a+h) (b-h)) h)) where h = (step' a b n)

--sqrt calculation
sqrt'' c e = until (\p -> (abs (p**2 - c)) < e) ss c where ss p = (p + c/p)/2
--sqrt calculation with default error = 0.0005
sqrt' c = sqrt'' c 0.0005
