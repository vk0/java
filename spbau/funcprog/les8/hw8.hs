module Homework8 where

import Control.Applicative
import Data.Either
import Data.Traversable

-- [(*0), (+100), (^2)] <*> [1, 2, 3] = [ f x | f <- fs, x <- xs]
-- where fs = [(*0), (+100), (^2)] and xs = [1, 2, 3], so
-- result = [0, 0, 0, 101, 102, 103, 1, 4, 9]
result1 = [(*0), (+100), (^2)] <*> [1, 2, 3]

-- (++) <$> ["ha", "heh", "hmm"] <*> ["?", "!", "..."] =
-- ( pure (++) <*> ["ha", "heh", "hmm"] ) <*> ["?", "!", "..."] =
-- [(++)] <*> ["ha", "heh", "hmm"] <*> ["?", "!", "..."] =
-- [("ha"++), ("heh"++), ("hmm"++)] <*> ["?", "!", "..."] =
-- ["ha?", "ha!", "ha...", "heh?", "heh!", "heh...", "hmm?", "hmm!", "hmm..."]
result2 = (++) <$> ["ha", "heh", "hmm"] <*> ["?", "!", "..."]

-- [(+), (*)] <*> [1, 2] <*> [3, 4] = [(1+), (2+), (1*), (2*)] <*> [3, 4] =
-- [4, 5, 5, 6, 3, 4, 6, 8]
result3 = [(+), (*)] <*> [1, 2] <*> [3, 4]

-- getZipList $ (,,) <*> ZipList "dog" <*> ZipList "cat" <*> ZipList "rat" =
-- getZipList $ ZipList [(d,,), (o,,), (g,,)] <*> ZipList "cat" <*> ZipList "rat" =
-- getZipList $ ZipList [(d, c, ), (o, a, ), (g, t, )] <*> ZipList "rat" =
-- getZipList $ ZipList [(d, c, r), (o, a, a), (g, t, t)] = [(d, c, r), (o, a, a), (g, t, t)]
result4 = getZipList $ (,,) <$> ZipList "dog" <*> ZipList "cat" <*> ZipList "rat"

-- (,,) <$> "dog" <*> "cat" <*> "rat" = [(,,)] <*> "dog" <*> "cat" <*> "rat" =
-- [(d,,), (o,,), (g,,)] <*> "cat" <*> "rat" = 
-- [(d, c,), (o, a,), (g, t,)] <*> "rat" = [(d, c, r), (o, a, a), (g, t, t)]
result5 = (,,) <$> "dog" <*> "cat" <*> "rat"

-- duplcative definition with Applicative ((->) a) (in Control.Applicative)
-- instance Applicative ((->) e) where
--   pure         =  const
--   (<*>) f g x  =  f x (g x)

-- (<*>) :: f (a -> b) -> f a -> f b = (e -> (a -> b)) -> (e -> a) -> (e -> b) =
-- (e -> a -> b) -> (e -> a) -> e -> b
-- so (<*>) takes function f1 with two arguments, function f2 with 1 argument and value x,
-- then apply f1 to x and (f2 x), so (<*>) is combinator S (connector)

-- \f g h -> f <*> g <*> h,
-- so f :: a -> b -> c -> d, g :: a -> b and h :: a -> c and result type will be
-- \f g h -> f <*> g <*> h :: (a -> b -> c -> d) -> (a -> b) -> (a -> c) -> a -> c

-- \f g h -> f <$> g <*> h,
-- so f :: b -> c -> d, g and h have same type, so result type will be
-- \f g h -> f <$> g <*> h :: (b -> c -> d) -> (a -> b) -> (a -> c) -> a -> c

-- (pure 3) "blah" = 3 //hm...
result6 = (pure 3) "blah"

-- (+) <*> (*3) $ 4 = ((+) <*> (*3)) $ 4 = (+) 4 ((*3) 4) = 4 + 12 = 16 (see above ((->) e))
result7 = (+) <*> (*3) $ 4

-- (+) <$> (+2) <*3> $ 10 = pure (+) <*> (+2) <*> (*3) $ 10 =
-- \f g x -> f x + g x <*> (+2) <*> (*3) $ 10 = \g x -> (2 + x) + g x <*> (*3) $ 10 =
-- \x -> (2 + x) + 3 * x $ 10 = 42
result8 = (+) <$> (+2) <*> (*3) $ 10

-- (\a b c -> [a, b, c]) <$> (+5) <*> (*3) <*> (/2) $ 7 =
-- pure (\a b c -> [a, b, c]) <*> (+5) <*> (*3) <*> (/2) $ 7 =
-- \a b c x -> [a x, b x, c x] <*> (+5) <*> (*3) <*> (/2) $ 7 =
-- \b c x -> [5 + x, b x, c x] <*> (*3) <*> (/2) $ 7 =
-- \c x -> [5 + x, 3 * x, c x] <*> (/2) $ 7 =
-- \x -> [5 + x, 3 * x, x / 2] $ 7 = [12, 21, 3.5]
result9 = (\a b c -> [a, b, c]) <$> (+5) <*> (*3) <*> (/2) $ 7

data MyEither a b = MyLeft a | MyRight b deriving Show
instance Functor (MyEither a) where
  fmap _ (MyLeft x)   =  MyLeft x
  fmap g (MyRight y)  =  MyRight (g y)

instance Applicative (MyEither a) where
  pure                 =  MyRight
  (<*>) (MyLeft x) _   =  MyLeft x
  (<*>) (MyRight f) r  =  fmap f r

-- (*) <$> MyRight 2 <*> MyRight 3 = MyRight (*) <*> MyRight 2 <*> MyRight 3 =
-- MyRight (2*) <*> MyRight 3 = MyRight (2 * 3) = MyRight 6
result10 = (*) <$> MyRight 2 <*> MyRight 3

-- (*) <$> MyRight 2 <*> MyLeft "Oh." = MyRight (*) <*> MyRight 2 <*> MyLeft "Oh." =
-- MyRight (2*) <*> MyLeft "Oh." = fmap (2*) MyLeft "Oh." = MyLeft "Oh."
result11 = (*) <$> MyRight 2 <*> MyLeft "Oh."

-- (*) <$> MyLeft "Ha!" <*> MyLeft "Oh." = MyRight (*) <*> MyLeft "Ha!" <*> MyLeft "Oh." =
-- (fmap (*) MyLeft "Ha!") <*> MyLeft "Oh." = MyLeft "Ha!" <*> MyLeft "Oh." = MyLeft "Ha!"
result12 = (*) <$> MyLeft "Ha!" <*> MyLeft "Oh."

data Tree a = Nil | Branch (Tree a) a (Tree a) deriving Show

instance Functor Tree where
  fmap _ Nil             =  Nil
  fmap f (Branch l d r)  =  Branch (fmap f l) (f d) (fmap f r)

-- instance Applicative Tree where
--  pure x                      =  Branch Nil x Nil
--  (<*>) _ Nil                 =  Nil
--  (<*>) (Branch Nil f Nil) r  =  fmap f r

instance Applicative Tree where
  pure x                                   =  Branch (pure x) x (pure x)
  (<*>) Nil _                              =  Nil
  (<*>) _ Nil                              =  Nil
  (<*>) (Branch l1 f r1) (Branch l2 x r2)  =  Branch (l1 <*> l2) (f x) (r1 <*> r2)

-- in comparision with lists there is one significant difference, we can wrap
-- number of function in a list, but with Tree only one function can be wrapped
-- because to difficult define Applicative for Tree consistently with the laws
-- of Applicative

-- sequenceA [Right 3, Right 4, Right 5] = traverse id [Right 3, Right 4, Right 5] =
-- foldr cons_f (pure []) [Right 3, Right 4, Right 5] = 
-- cons_f (Right 3) (foldr cons_f (pure []) [Right 4, Right 5]) =
-- cons_f (Right 3) (cons_f (Right 4) (foldr cons_f (pure []) [Right 5])) =
-- cons_f (Right 3) (cons_f (Right 4) (cons_f (Right 5) (foldr cons_f (pure []) []))) =
-- cons_f (Right 3) (cons_f (Right 4) (cons_f (Right 5) (pure []))) = 
-- Right (3:) <*> (cons_f (Right 4) (cons_f (Right 5) (pure []))) = 
-- Right (3:) <*> Right (4:) (cons_f (Right 5) (pure [])) =
-- Right (3:) <*> Right (4:) <*> Right (5:) <*> Right [] =
-- Right [3, 4, 5]
result13 = sequenceA [Right 3, Right 4, Right 5]

-- sequaneceA [Right 3, Left 4, Right 5] = traverse id [Right 3, Left 4, Right 5] =
-- foldr cons_f (pure []) [Right 3, Left 4, Right 5] =
-- cons_f (Right 3) (foldr cons_f (pure []) [Left 4, Right 5]) =
-- Right (3:) <*> (cons_f (Left 4) (foldr cons_f (pure []) [Right 5])) =
-- Right (3:) <*> ((:) <$> (Left 4) <*> (foldr cons_f (pure []) [Right 5])) =
-- Right (3:) <*> ((Right (:)) <*> (Left 4) <*> (foldr cons_f (pure []) [Right 5])) =
-- Right (3:) <*> (Left 4) = Left 4
result14 = sequenceA [Right 3, Left 4, Right 5]

-- the same thing, result Left 3
result15 = sequenceA [Left 3, Left 4, Right 5]

-- sequenceA [(+3), (+2), (+1)] 3 = (traverse id [(+3), (+2), (+1)]) 3 =
-- (foldr cons_f (pure []) [(+3), (+2), (+1)]) 3 =
-- ((:) <$> (+3) <*> (foldr cons_f (pure []) [(+2), (+1)])) 3 =
-- (pure (:) <*> (+3) <*> (foldr ...)) 3 =
-- (const (:) <*> (+3) <*> (foldr ...)) 3 =
-- ((\x -> (((+3) x) :)) <*> (foldr ...)) 3 =
-- (\x -> ((+3) x):((+2) x):((+1) x):[]) 3 = [6, 5, 4]
result16 = sequenceA [(+3), (+2), (+1)] 3

-- (getZipList . sequenceA . map ZipList) [[1, 2, 3], [4, 5, 6]] =
-- getZipList (sequenceA (map ZipList [[1, 2, 3], [4, 5, 6]])) =
-- getZipList (sequenceA (map ZipList [[1, 2, 3], [4, 5, 6]])) =
-- getZipList (sequenceA ([ZipList [1, 2, 3], ZipList [4, 5, 6]])) =
-- getZipList (traverse id [ZipList [1, 2, 3], ZipList [4, 5, 6]]) =
-- getZipList (foldr cons_f (pure []) [ZipList [1, 2, 3], ZipList [4, 5, 6]]) =
-- getZipList (pure (:) <*> ZipList [1, 2, 3] <*> (foldr cons_f (pure []) [ZipList [4, 5, 6]])) =
-- getZipList (ZipList (:) <*> ZipList [1, 2, 3] <*> (ZipList (:) <*> ZipList [4, 5, 6] <*> ZipList (repeat []))) =
-- getZipList (ZipList [(1:), (2:), (3:)] <*> ZipList [(4:), (5:), (6:)] <*> ZipList [[] ..]) =
-- getZipList (ZipList [(1:4:), (2:5:), (3:6:)] <*> ZipList [[] ..]) =
-- getZipList (ZipList [1:4:[], 2:5:[], 3:6:[]]) = [[1, 4], [2, 5], [3, 6]]
result17 = (getZipList . sequenceA . map ZipList) [[1, 2, 3], [4, 5, 6]]

(>*<) xs ys  =  getZipList $ (ZipList xs) <*> (ZipList ys)
(>$<) f  xs  =  (repeat f) >*< xs

-- MAYBE
-- Composition:

-- pure (.) = Just (.)
-- if u, v and w - Just's, then
-- Just (.) <*> Just f <*> Just g <*> Just x =
-- Just (f .) <*> Just g <*> Just x =
-- Just (f . g) <*> Just x = Just (f (g x))
-- and Just f <*> (Just g <*> Just x) =
-- Just f <*> (Just (g x) ) = Just (f (g x))
-- if u, v or w is Nothing, then
-- Just (.) <*> u <*> v <*> w = Nothing
-- and u <*> (v <*> w) is nothing too

-- Interchange:

-- if g - Just f, then
-- Just g <*> Just x = Just (g x)
-- and pure ($ x) <*> g = Just ($ x) <*> Just f = Just (($ x) f) = Just (f x)
-- if g - Nothing, then Nothing <*> _ = Nothing
-- and pure ($ x) <*> Nothing = Just ($ x) <*> Nothing = Nothing

-- LIST
-- Composition:
-- pure (.) = [(.)]
-- [(.)] <*> [f1, f2, ..., fn] <*> [g1, g2, ..., gm] <*> [x1, x2, ..., xk] =
-- [(f1 .), (f2 .), ..., (fn .)] <*> [g1, g2, ..., gm] <*> [x1, x2, ..., xk] =
-- [(f1.g1), ..., (f1.gm), (f2.g1), ..., (f2.gm), ..., (fn.g1), ..., (fn.gm)]
-- <*> [x1, x2, ..., xk] =
-- [(f1.g1)x1, ..., (f1.g1)xk, ..., (fn.gm)x1, ..., (fn.fm)xk]
-- [g1, g2, ..., gm] <*> [x1, x2, ..., xk] =
-- [g1 x1, g1 x2, ..., g1 xk, g2 x1, g2 x2, ..., x2 xk, ..., gm x1, ..., gm xk]
-- [f1, ..., fn] <*> [g1 x1, ..., gm xk] =
-- [f1 (g1 x1), ..., f1 (gm xk), ..., fn (g1 x1), ..., fn (gm xk)]

-- Interchange:
-- g = [f1, ..., fn], then
-- g <*> [x] = [f1 x, ..., fn x]
-- and pure ($ x) = [($ x)], then
-- [($ x)] <*> [f1, ..., fn] =
-- [($ x) f1, ..., ($ x) fn] = [f1 x, ..., fn x]
