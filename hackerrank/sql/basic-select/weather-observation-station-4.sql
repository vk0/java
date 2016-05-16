-- Let NUM be the number of CITY entries in STATION, and  be the number of unique cities. Query the value of  from STATION.

-- In other words, query the number of non-unique CITY names in STATION by subtracting the number of unique CITY entries in the table from the total number of CITY entries in the table.

-- Input Format

-- The STATION table is described as follows:

-- Station.jpg

-- where LAT_N is the northern latitude and LONG_W is the western longitude.

SELECT (COUNT(CITY) - COUNT(DISTINCT CITY)) FROM STATION;
