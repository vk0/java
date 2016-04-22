-- This function should print a single digit number as English text, or "unknown" if it's out of the range 0-9

--Solution using Guards
englishDigit :: Int -> String
englishDigit x
    | x < 0 = "unknown"
    | x > 9 = "unknown"
    | otherwise = show x

--Solution using pattern matching
englishDigit' :: Int -> String
englishDigit' 0 = show 0
englishDigit' 1 = show 1
englishDigit' 2 = show 2
englishDigit' 3 = show 3
englishDigit' 4 = show 4
englishDigit' 5 = show 5
englishDigit' 6 = show 6
englishDigit' 7 = show 7
englishDigit' 8 = show 8
englishDigit' 9 = show 9
englishDigit' x = "Unknown"

-- given a tuple, divide fst by snd, using pattern matching.
-- it should return undefined for division by zero

--Solution using Guards
divTuple :: (Eq a, Fractional a) => (a, a) -> a
divTuple (x,y)
    | fst (x,y) == 0 = error "dividing zero by a number: Infinity"
    | snd (x,y) == 0 = error "division by zero: undefined"
    | otherwise      = (fst (x,y) / snd (x,y))

--Solution using pattern matching
divTuple' :: (Eq a, Fractional a) => (a, a) -> a
divTuple' (_, 0) = error "division by zero: undefined"
divTuple' (0, _) = error "dividing zero by a number: Infinity"
divTuple' (x,y) = (fst (x,y) / snd (x,y))

-- if the first three numbers in a list are all zero, return True

--Solution using Guards
threeZeroList :: [Int] -> Bool
threeZeroList list
    | take 3 list == [0,0,0] = True
    | otherwise = False

--Solution using pattern matching
threeZeroList' :: [Int] -> Bool
threeZeroList' [0,0,0] = True
threeZeroList' [0,0,0,_] = True
threeZeroList' list = False