-- Query the Western Longitude for the smallest value of the Northern Latitudes greater than 38.7780 in STATION and round to 4 decimal places.

SELECT ROUND(CAST(LONG_W AS DECIMAL(10,4)),4) FROM STATION WHERE LAT_N IN (SELECT MIN(LAT_N) FROM STATION WHERE LAT_N>38.7780);