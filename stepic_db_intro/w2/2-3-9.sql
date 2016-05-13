-- Задание
-- Выведите список всех источников клиентов и суммарный объем заказов по каждому источнику. Результат должен включать также записи для источников, по которым не было заказов.
-- Ожидаемый формат результата:

-- +-------------+----------------+
-- | source_name | sale_sum       |
-- +-------------+----------------+
-- | source 1    | 111.00         |
-- | source 2    | 222.00         |
-- | source 3    | 333.00         |
-- ...


-- NB! В запросе для соединения нескольких источников данных операцию соединения можно использовать многократно. Например, для соединения таблиц A, B и C можно использовать запрос вида:

-- SELECT * FROM A
--   LEFT OUTER JOIN B
--     ON A.b_id = B.id
--   LEFT OUTER JOIN C
--     ON a.c_id = C.id
-- ;

select s.name source_name, sum(o.sale_sum) sale_sum from source as s left join client as cl on cl.source_id = s.id left join sale as o on o.client_id = cl.id group by 1;

-- Query result:
-- +---------------+----------+
-- | source_name   | sale_sum |
-- +---------------+----------+
-- | Advertisement | 89188.00 |
-- | AdWords       | 21623.00 |
-- | Banner        | None     |
-- | Campaign      | 49214.00 |
-- | Direct link   | 72362.00 |
-- | Google search | 17330.00 |
-- | SN            | 57043.00 |
-- +---------------+----------+