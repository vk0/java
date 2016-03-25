> toList :: String -> [Integer]
> toList input = read ("[" ++ input ++ "]")
>
> main = do
>   putStrLn "Enter a list of numbers (separated by comma):"
>   input <- getLine
>   print $ sum (toList input)
