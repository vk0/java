-- Укажите, в каком порядке будут выполняться операции над отношениями в следующем запросе:

select number, code from sale
join client on sale.client_id=client.id
join status on status.id=status_id
where status.id in (6, 7);


explain select number, code from sale  join client on sale.client_id=client.id join status on status.id=status_id where status.id in (6, 7);
+----+-------------+--------+--------+-------------------------------------------+----------------------+---------+----------------------+------+--------------------------+
| id | select_type | table  | type   | possible_keys                             | key                  | key_len | ref                  | rows | Extra                    |
+----+-------------+--------+--------+-------------------------------------------+----------------------+---------+----------------------+------+--------------------------+
|  1 | SIMPLE      | status | index  | PRIMARY                                   | PRIMARY              | 4       | NULL                 |    7 | Using where; Using index |
|  1 | SIMPLE      | sale   | ref    | fk_order_status1_idx,fk_order_client1_idx | fk_order_status1_idx | 4       | store.status.id      |    1 |                          |
|  1 | SIMPLE      | client | eq_ref | PRIMARY                                   | PRIMARY              | 4       | store.sale.client_id |    1 |                          |
+----+-------------+--------+--------+-------------------------------------------+----------------------+---------+----------------------+------+--------------------------+

-- status
-- sale
-- client

