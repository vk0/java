-- Samantha was tasked with calculating the average monthly salaries for all employees in the EMPLOYEES table, but did not realize her keyboard's  key was broken until after completing the calculation. She wants your help finding the difference between her miscalculation (using salaries with any zeroes removed), and the actual average salary.

-- Write a query calculating the amount of error (i.e.:  average monthly salaries), and round it up to the next integer.

-- Input Format

-- The EMPLOYEES table is described as follows:



-- Note: Salary is measured in dollars per month and its value is .

-- Sample Input



-- Sample Output

-- 2061
-- Explanation

-- The table below shows the salaries without zeroes as they were entered by Samantha:



-- Samantha computes an average salary of . The actual average salary is .

-- The resulting error between the two calculations is  which, when rounded to the next integer, is .

SELECT CEIL(AVG(SALARY)- AVG(REPLACE(SALARY,'0',''))) FROM EMPLOYEES;
