module Les5 where

import Data.List

counteven (head:tail) = if ((rem head 2) == 0)
                         then (1 + (counteven tail))
                         else (counteven tail)
counteven [] = 0

consodd (head:tail) = if ((rem head 2) /= 0)
                         then (head:(consodd tail))
                         else (consodd tail)
consodd [] = []

swap (a:b:tail) = (b:a:(swap tail))
swap a = a

zipsum (head1:tail1) (head2:tail2) = ((head1 + head2):(zipsum tail1 tail2))
zipsum _ [] = []
zipsum [] _ = []

reverse' list = reverse'' list [] where reverse'' (head:tail) list = reverse'' tail (head:list)
                                        reverse'' [] list = list

firstn list 0 = []
firstn (head:tail) n = (head:(firstn tail (n-1)))
firstn [] _ = []

twice list = map (*2) list

eventwice list = map condtwice list where condtwice e = if (even e)
                                                         then e*2
                                                         else e

oddzero list = map condzero list where condzero e = if (odd e)
                                                     then 0
                                                     else e

pairslist list = snd $ mapAccumL (\x y -> ((x+1),(y,x))) 0 list

oddposzero list = snd $ mapAccumL (\x y -> ((x+1), (if (odd x) then 0 else y))) 0 list

filtermore list num = filter (\x -> x <= num) list

apply fun num list = map (fun num) list
