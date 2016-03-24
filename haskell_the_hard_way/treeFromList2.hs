data BinTree a = Empty
                 | Node a (BinTree a) (BinTree a)
                  deriving (Eq,Ord)

-- говорим что  BinTree будет экземпляром Show
instance (Show a) => Show (BinTree a) where
  -- перед корнем будет отображаться '<'
  -- и напишем : в начале строки
  show t = "< " ++ replace '\n' "\n: " (treeshow "" t)
    where
    -- treeshow pref Tree
    --   отображает дерево и начинает каждую строку с  pref
    -- Мы не будем отображать пустое дерево
    treeshow pref Empty = ""
    -- Leaf
    treeshow pref (Node x Empty Empty) =
                  (pshow pref x)

    -- Правая ветка пустая
    treeshow pref (Node x left Empty) =
                  (pshow pref x) ++ "\n" ++
                  (showSon pref "`--" "   " left)

    -- Левая ветка пустая
    treeshow pref (Node x Empty right) =
                  (pshow pref x) ++ "\n" ++
                  (showSon pref "`--" "   " right)

    -- Дерево с непустыми правой и левой ветками
    treeshow pref (Node x left right) =
                  (pshow pref x) ++ "\n" ++
                  (showSon pref "|--" "|  " left) ++ "\n" ++
                  (showSon pref "`--" "   " right)

    -- отображение дерева с  красивыми префиксами
    showSon pref before next t =
                  pref ++ before ++ treeshow (pref ++ next) t

    -- pshow заменяет "\n" на "\n"++pref
    pshow pref x = replace '\n' ("\n"++pref) (show x)

    -- заменяет символ строкой
    replace c new string =
      concatMap (change c new) string
      where
          change c new x
              | x == c = new
              | otherwise = x:[] -- "x"

treeFromList :: (Ord a) => [a] -> BinTree a
treeFromList [] = Empty
treeFromList (x:xs) = Node x (treeFromList (filter (<x) xs))
                             (treeFromList (filter (>x) xs))

--putStrLn "Int binary tree:"
--print $ treeFromList [7,2,4,8,1,3,6,21,12,23]
--< 7
--: |--2
--: |  |--1
--: |  `--4
--: |     |--3
--: |     `--6
--: `--8
--:    `--21
--:       |--12
--:       `--23

--λ> print $ treeFromList ["foo","bar","baz","gor","yog"]
--< "foo"
--: |--"bar"
--: |  `--"baz"
--: `--"gor"
--:    `--"yog"

--λ> print ( treeFromList (map treeFromList ["baz","zara","bar"]))
--< < 'b'
--: : |--'a'
--: : `--'z'
--: |--< 'b'
--: |  : |--'a'
--: |  : `--'r'
--: `--< 'z'
--:    : `--'a'
--:    :    `--'r'

--λ> print $ (treeFromList . map (treeFromList . map treeFromList)) [ ["YO","DAWG"], ["I","HEARD"], ["I","HEARD"], ["YOU","LIKE","TREES"] ]
--< < < 'Y'
--: : : `--'O'
--: : `--< 'D'
--: :    : |--'A'
--: :    : `--'W'
--: :    :    `--'G'
--: |--< < 'I'
--: |  : `--< 'H'
--: |  :    : |--'E'
--: |  :    : |  `--'A'
--: |  :    : |     `--'D'
--: |  :    : `--'R'
--: `--< < 'Y'
--:    : : `--'O'
--:    : :    `--'U'
--:    : `--< 'L'
--:    :    : `--'I'
--:    :    :    |--'E'
--:    :    :    `--'K'
--:    :    `--< 'T'
--:    :       : `--'R'
--:    :       :    |--'E'
--:    :       :    `--'S'
