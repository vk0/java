module Homework where


--the type of sides of the world
data WorldSide  = South | North | West | East deriving Show

--left turnning
turnLeft South  = East
turnLeft East   = North
turnLeft North  = West
turnLeft West   = South

--right turnning
turnRight South = West
turnRight West  = North
turnRight North = East
turnRight East  = South

--turn back
turnAround side = turnLeft $ turnLeft side


--split number to dec digits with division by 10
digits n = if n <= 0
             then error ("natural number expected instead " ++ (show n) )
             else digits' n []
               where digits' 0 list = list;
                     digits' n list = digits' (div n 10) ( (rem n 10) : list )


--removes repetitons from list
unique list = unique' list []
                 where  unique' [] ulist          = ulist;
		        unique' (head:tail) ulist = if elem head ulist
                                                     then unique' tail ulist
			                             else unique' tail (head:ulist)
		       

--drops elements such that f e == True 
filterList [] _          = []
filterList (head:tail) f = if f head
                         then filterList tail f
			 else (head:(filterList tail f))

dropzeros 0 = True;
dropzeros _ = False

--test that list of digits for n contains all dec digits except 0
containsAll n = if (length (filterList (unique (digits n)) dropzeros)) == 9
                  then True
                  else False

--test that n contains every digit in 1..9 only once = length list_without_repetitoins = length source_list
containsAllOnce n = containsAllOnce' (filterList (digits n) dropzeros)
                      where containsAllOnce' list = if (length list) == (length (unique list))
		                                      then True
						      else False

--list of lists
shiftCopy (head:tail) byn = if byn <= 0
                              then error ("Positive integer expected instead " ++ (show byn))
                              else ((head:(take (byn - 1) tail)):(shiftCopy tail byn))
shiftCopy [] byn          = if byn <= 0
                              then error ("Positive integer expected instead " ++ (show byn))
                              else []


--tree is empty tree (NIL) or node with left and right child and data
data BinaryTree value = NIL | CONS value (BinaryTree value) (BinaryTree value) deriving Show

--assistance
left NIL           = NIL
left (CONS _ l _)  = l
right NIL          = NIL
right (CONS _ _ r) = r
info NIL           = error "Dereference of a NIL"
info (CONS d _ _)  = d

sumElems NIL = 0
sumElems tree = (info tree) + (sumElems $ left tree) + (sumElems $ right tree)

depth NIL  = 0
depth tree = 1 + (max (depth (left tree)) (depth (right tree)) )

--width on specified depth in the tree
widthAt NIL _  = 0
widthAt _ 0    = 1
widthAt tree h = (widthAt (left tree) (h-1) ) + (widthAt (right tree) (h - 1) )

myfst2 (a,_,_) = a
--go through every tree level and find the most numerous
width NIL  = 0
width tree = maximum (myfst2 $ until (\(_,c,d) -> c >= d) ss ([], 0 , depth tree) )
                        where ss (l,c,d) = (((widthAt tree c):l), c + 1, d)
