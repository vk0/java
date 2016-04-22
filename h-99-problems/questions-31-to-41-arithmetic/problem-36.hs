--Determine the prime factors of a given positive integer.

--Construct a list containing the prime factors and their multiplicity.

--Example:

--* (prime-factors-mult 315)
--((3 2) (5 1) (7 1))
--Example in Haskell:

--*Main> prime_factors_mult 315
--[(3,2),(5,1),(7,1)]

prime_factors_mult n = map swap $ encode $ primeFactors n
  where swap (x,y) = (y,x)

--using primeFactors from problem 35 to generate the list of prime factors in ascending order, and encode from problem 10 to compress this list to a list of numbers paired with their multiplicity.

--Without relying on encode from problem 10, but using group from Data.List:

prime_factors_mult = map encode . group . primeFactors
    where encode xs = (head xs, length xs)