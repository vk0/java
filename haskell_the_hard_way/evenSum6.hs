-- Версия 6
-- foldl' не доступна по умолчанию
-- мы должны импортировать ее из модуля Data.List

import Data.List
evenSum l = foldl' mysum 0 (filter even l)
  where mysum acc value = acc + value