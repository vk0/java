--Определите представителя класса Functor для бинарного дерева, в каждом узле которого хранятся элементы типа Maybe:

--data Tree a = Leaf (Maybe a) | Branch (Tree a) (Maybe a) (Tree a) deriving Show


--GHCi> words <$> Leaf Nothing
--Leaf Nothing

--GHCi> words <$> Leaf (Just "a b")
--Leaf (Just ["a","b"])

instance Functor Tree where
    fmap f (Leaf Nothing) = Leaf Nothing
    fmap f (Leaf (Just a)) = Leaf $ Just $ f a  --splitOn " " a
    fmap f (Branch t1 m t2) = Branch (fmap f t1) (fmap f m) (fmap f t2)
