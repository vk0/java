-- Задание
-- Выведите список всех категорий продуктов и количество продаж товаров, относящихся к данной категории. Под количеством продаж товаров подразумевается суммарное количество единиц товара данной категории, фигурирующих в заказах с любым статусом.
-- Ожидаемый формат результата:

-- +---------------------+----------+
-- | name                | sale_num |
-- +---------------------+----------+
-- | category 1          |       11 |
-- | category 2          |       25 |
-- | category 3        |       13 |
-- ...


-- NB! В запросе для соединения нескольких источников данных операцию соединения можно использовать многократно. Например, для соединения таблиц A, B и C можно использовать запрос вида:

-- SELECT * FROM A
--   LEFT OUTER JOIN B
--     ON A.b_id = B.id
--   LEFT OUTER JOIN C
--     ON a.c_id = C.id
-- ;

select c.name, count(shg.sale_id) from category as c left join category_has_good as chg on chg.category_id = c.id left join good as g on g.id = chg.good_id left join sale_has_good as shg on shg.good_id = g.id left join sale as s on s.id = shg.sale_id group by 1;

-- Query result:
-- +---------------------+--------------------+
-- | name                | count(shg.sale_id) |
-- +---------------------+--------------------+
-- | Air Fresheners      | 25                 |
-- | Bath Products       | 45                 |
-- | Cakes               | 38                 |
-- | Candy               | 39                 |
-- | Dental Care         | 39                 |
-- | Fruits & Vegetables | 0                  |
-- | Health & Medicine   | 49                 |
-- | Juices              | 39                 |
-- | Pasta & Noodles     | 0                  |
-- | Seasonings & Spices | 0                  |
-- | Snacks              | 31                 |
-- | Tea & Coffee        | 54                 |
-- | Water               | 50                 |
-- +---------------------+--------------------+