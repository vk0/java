-- Создайте B-tree индекс на поле с названием товара в отношении good.

select
  name,
    ifnull((select category.name from category
    join category_has_good on category.id=category_has_good.category_id
        where category_has_good.good_id=good.id
        order by category.name limit 1)
  , 0) as first_category
from good where name like 'F%';

-- Сколько теперь кортежей будет обработано из таблицы good?

create index good_name_index on good(name);
explain select
  name,
    ifnull((select category.name from category
    join category_has_good on category.id=category_has_good.category_id
        where category_has_good.good_id=good.id
        order by category.name limit 1)
  , 0) as first_category
from good where name like 'F%';
+----+--------------------+-------------------+--------+--------------------------------------------------------------------------+--------------------------------+---------+-------------------------------------+------+----------------------------------------------+
| id | select_type        | table             | type   | possible_keys                                                            | key                            | key_len | ref                                 | rows | Extra                                        |
+----+--------------------+-------------------+--------+--------------------------------------------------------------------------+--------------------------------+---------+-------------------------------------+------+----------------------------------------------+
|  1 | PRIMARY            | good              | range  | good_name_index                                                          | good_name_index                | 768     | NULL                                |   20 | Using where; Using index                     |
|  2 | DEPENDENT SUBQUERY | category_has_good | ref    | PRIMARY,fk_category_has_good_good1_idx,fk_category_has_good_category_idx | fk_category_has_good_good1_idx | 4       | store.good.id                       |    1 | Using index; Using temporary; Using filesort |
|  2 | DEPENDENT SUBQUERY | category          | eq_ref | PRIMARY                                                                  | PRIMARY                        | 4       | store.category_has_good.category_id |    1 |                                              |
+----+--------------------+-------------------+--------+--------------------------------------------------------------------------+--------------------------------+---------+-------------------------------------+------+----------------------------------------------+

drop index good_name_index on good;