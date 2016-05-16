-- Write a query identifying the type of each record in the TRIANGLES table using its three side lengths. Output one of the following statements for each record in the table:

-- Not A Triangle: The given values of A, B, and C don't form a triangle.
-- Equilateral: It's a triangle with  sides of equal length.
-- Isosceles: It's a triangle with  sides of equal length.
-- Scalene: It's a triangle with  sides of differing lengths.
-- Input Format

-- The TRIANGLES table is described as follows:



-- Each row in the table denotes the lengths of each of a triangle's three sides.

-- Sample Input



-- Sample Output

-- Isosceles
-- Equilateral
-- Scalene
-- Not A Triangle
-- Explanation

-- Values in the tuple  form an Isosceles triangle, because .
-- Values in the tuple  form an Equilateral triangle, because . Values in the tuple form a Scalene triangle, because .
-- Values in the tuple  cannot form a triangle, because sides .

SELECT CASE WHEN (A + B <= C) OR (B+C <= A) OR (A+C <= B) THEN "Not A Triangle" WHEN (A=B) AND (B=C) THEN "Equilateral" WHEN (A=B) OR (C=A) OR (B=C) THEN "Isosceles" ELSE "Scalene" END FROM TRIANGLES