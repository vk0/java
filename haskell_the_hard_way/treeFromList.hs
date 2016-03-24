--Давайте напишем функцию, которая преобразует список в упорядоченное двоичное дерево.
--описание:
--пустой список превращается в пустое дерево.
--список (x:xs) станет деревом, в котором:
--корнем будет x
--левое поддерево будет создано из элементов списка xs строго меньших x а
--правое поддерево будет создано из элементов списка xs строго больших x.
--main = print $ treeFromList [7,2,4,8]
--Должно получиться что-то вроде:
--Node 7 (Node 2 Empty (Node 4 Empty Empty)) (Node 8 Empty Empty)

import Data.List

data BinTree a = Empty
                 | Node a (BinTree a) (BinTree a)
                              deriving (Show)

treeFromList :: (Ord a) => [a] -> BinTree a
treeFromList [] = Empty
treeFromList (x:xs) = Node x (treeFromList (filter (<x) xs))
                             (treeFromList (filter (>x) xs))