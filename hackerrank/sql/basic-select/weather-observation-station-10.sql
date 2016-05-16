-- Query the list of CITY names from STATION that do not end with vowels. Your result cannot contain duplicates.

-- Input Format

-- The STATION table is described as follows:

-- Station.jpg

-- where LAT_N is the northern latitude and LONG_W is the western longitude.

SELECT CITY FROM STATION WHERE RIGHT(CITY,1) NOT IN ('a','e','i','o','u') GROUP BY CITY;