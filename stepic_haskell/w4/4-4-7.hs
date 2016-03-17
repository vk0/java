--Реализуйте функцию findDigitOrX, используя функцию findDigit (ее реализовывать не нужно). findDigitOrX должна находить цифру в строке, если в строке цифр нет, то она должна возвращать 'X'. Используйте конструкцию case.


import Data.Char(isDigit)

findDigit :: [Char] -> Maybe Char

findDigitOrX :: [Char] -> Char
findDigitOrX x =
    case findDigit x of
        Nothing -> 'X'
        Just a  -> a