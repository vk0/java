-- P(R) represents a pattern drawn by Julia in R rows. The following pattern represents P(5):

-- * * * * *
-- * * * *
-- * * *
-- * *
-- *
-- Write a query to print the pattern P(20).

SELECT REPEAT('* ', @NUMBER := @NUMBER + 1) FROM information_schema.tables, (SELECT @NUMBER:=0) t LIMIT 20;