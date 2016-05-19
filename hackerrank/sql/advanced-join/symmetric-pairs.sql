-- You are given a table, Functions, containing two columns: X and Y. Y is the value of some function F at X -- i.e. Y = F(X).



-- Two pairs (X1, Y1) and (X2, Y2) are said to be symmetric pairs if X1 = Y2 and X2 = Y1.

-- Write a query to output all such symmetric pairs in ascending order by the value of X.

-- Sample Input



-- Sample Output

-- 20 20
-- 20 21
-- 22 23

select x, y from functions f1
    where exists(select * from functions f2 where f2.y=f1.x
    and f2.x=f1.y and f2.x>f1.x) and (x!=y)
union
select x, y from functions f1 where x=y and
    ((select count(*) from functions where x=f1.x and y=f1.x)>1)
        order by x;