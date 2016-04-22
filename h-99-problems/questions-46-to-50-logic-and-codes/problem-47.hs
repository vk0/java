--Truth tables for logical expressions (2).

--Continue problem P46 by defining and/2, or/2, etc as being operators. This allows to write the logical expression in the more natural way, as in the example: A and (A or not B). Define operator precedence as usual; i.e. as in Java.

--Example:

--* (table A B (A and (A or not B)))
--true true true
--true fail true
--fail true fail
--fail fail fail
--Example in Haskell:

--> table2 (\a b -> a `and'` (a `or'` not b))
--True True True
--True False True
--False True False
--False False False

-- functions as in solution 46

infixl 4 `or'`
infixl 6 `and'`

-- "not" has fixity 9 by default
--Java operator precedence (descending) as far as I could fathom it:

--logical not
--equality
--and
--xor
--or
--Using "not" as a non-operator is a little evil, but then again these problems were designed for languages other than haskell :)