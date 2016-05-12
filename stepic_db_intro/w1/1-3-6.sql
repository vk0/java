-- Исходные данные

-- База данных магазина `store_simple` состоит из одной таблицы `store` следующей структуры:

-- CREATE TABLE IF NOT EXISTS `store_simple`.`store` (
--   `product_name` VARCHAR(255) NULL,
--   `category` VARCHAR(255) NULL,
--   `price` DECIMAL(18,2) NULL,
--   `sold_num` INT NULL)
-- ENGINE = InnoDB;
-- Задание

-- Выведите 5 категорий товаров, продажи которых принесли наибольшую выручку. Под выручкой понимается сумма произведений стоимости товара на количество проданных единиц. Результат должен содержать два столбца:
-- название категории,
-- выручка от продажи товаров в данной категории.

select category, sum(sold_num*price) as rez from store group by category order by rez desc limit 5;