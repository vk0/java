-- Исходные данные
-- База данных магазина `store` следующей структуры: https://ucarecdn.com/c3cd7834-60ed-4dc6-b86e-ce4555aba914/

-- В таблице 'client' ограничение внешнего ключа называется 'fk_client_source1', определенное на поле 'source_id'.

-- Задание
-- Удалите из таблицы 'client' поля 'code' и 'source_id'.

-- NB! Для удаления поля поля, являющегося внешним ключом, необходимо удалить ограничение внешнего ключа оператором 'DROP FOREIGN KEY <fk_name>'. Удаление ограничения внешнего ключа и поля таблицы необходимо производить в рамках одного вызова ALTER TABLE.

-- NB! При выполнении ALTER TABLE не следует указывать название схемы.

ALTER TABLE client DROP COLUMN code, DROP COLUMN source_id, DROP FOREIGN KEY fk_client_source1;