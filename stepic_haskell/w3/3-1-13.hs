--Напишите функцию groupElems которая группирует одинаковые элементы в списке (если они идут подряд) и возвращает список таких групп.

--GHCi> groupElems []
--[]
--GHCi> groupElems [1,2]
--[[1],[2]]
--GHCi> groupElems [1,2,2,2,4]
--[[1],[2,2,2],[4]]
--GHCi> groupElems [1,2,3,2,4]
--[[1],[2],[3],[2],[4]]

--Разрешается использовать только функции, доступные из библиотеки Prelude.


groupElems :: Eq a => [a] -> [[a]]
groupElems [] = []
groupElems a  =  gr a []
  where gr [] as = reverse as
        gr (x : xs) [] = gr xs ((x : []) : [])
        gr (x : xs) ys = if (x == headOfHead ys) then gr xs ((x : (head ys)) : (tail ys))
                         else gr xs ((x : []) : ys)
headOfHead = head . head