module Homework where
import Data.Monoid

newtype  MyEndo a = MyEndo {
  appMyEndo :: a -> a
}

instance Monoid (MyEndo a) where
  mempty                       =  MyEndo id
  MyEndo f `mappend` MyEndo g  =  MyEndo $ f . g

-- let fn = mconcat $ map MyEndo [(+5), (*3), (`subtract` 2)]
-- fn is function on x : (x - 2) * 3 + 5, so
-- appMyEndo fn 2 = (2 - 2) * 3 + 5 = 5

-- i know 2 ways: Nothing - neutral element of Monoid anyway
-- but `mappend` can be defined two different ways
data MyMaybe1 a = Nothing1 | Just1 a
instance Monoid (MyMaybe1 a) where
  mempty                       =  Nothing1
  Nothing1 `mappend` right     =  right
  left     `mappend` Nothing1  =  left
  left     `mappend` _         =  left

data MyMaybe2 a = Nothing2 | Just2 a
instance Monoid (MyMaybe2 a) where
  mempty                       =  Nothing2
  Nothing2 `mappend` right     =  right
  left     `mappend` Nothing2  =  left
  _        `mappend` right     =  right

-- foldl (/) 480 [3, 2, 5, 2] ->
--   foldl (480 / 3) [2, 5, 2] -> foldl ((480 / 3) / 2) [5, 2] ->
--   foldl (((480 / 3) / 2) / 5) [2] -> ((((480 / 3) / 2) / 5) / 2) [] =
--   = ((160 / 2) / 5) / 2 = (80 / 5) / 2 = 16 / 2 = 8

-- foldr (/) 2 [8, 12, 24, 4] ->
--   8 / (foldr (/) 2 [12, 24, 4]) -> 8 / (12 / (foldr (/) 2 [24, 4])) ->
--   8 / (12 / (24 / (foldr (/) 2 [4]))) ->
--   8 / (12 / (24 / (4 / (foldr (/) 2 [])))) = 8 / (12 / (24 / (4 / 2))) = 8


length' l      =  foldl myinc 0 l
                    where myinc n _  =  n + 1

or' l          =  foldr (||) False l

head' l        =  foldr myfst (error "empty list has no head") l
                    where myfst f _  =  f

last' l        =  foldl mysnd (error "empty list has no last") l
                    where mysnd _ s  =  s

maximum' l     =  foldr mymax (error "empty list has no maximum") l
                    where mymax l r | l > r      =  l
                                    | otherwise  =  r

map' f         =  foldr myop []
                    where myop e l  =  ((f e):l)

filter' p      =  foldr myop []
                    where myop e l | (p e)       =  (e:l)
                                   | otherwise   =  l

reverse'       =  foldl invcons []
                    where invcons l e = (e:l)
reverse''      =  foldr invconc []
                    where invconc e l = l ++ [e]

join           =  foldr myconc []
                    where myconc ll [] = ll;
                          myconc ll lr = ll ++ (',':lr)

foldl' op ini  =  (foldr invop ini) . reverse''
                    where invop l r  =  op r l

data Tree a = Nil | Branch (Tree a) a (Tree a) deriving (Eq, Show)

foldTree _ ini Nil              =  ini
foldTree op ini (Branch l e r)  =  op e (foldTree op ini l) (foldTree op ini r)

flattenTree1                    =  foldTree myop []
                                     where myop e l1 l2  =  (e:l1) ++ l2
flattenTree2                    =  foldTree myop []
                                     where myop e l1 l2  =  (e:l2) ++ l1
flattenTree3                    =  foldTree myop []
                                     where myop e l1 l2  =  l2 ++ (e:l1)
flattenTree4                    =  foldTree myop []
                                     where myop e l1 l2  =  l1 ++ (e:l2)
flattenTree5                    =  foldTree myop []
                                     where myop e l1 l2  =  l1 ++ l2 ++ [e]
flattenTree6                    =  foldTree myop []
                                     where myop e l1 l2  =  l2 ++ l1 ++ [e]
