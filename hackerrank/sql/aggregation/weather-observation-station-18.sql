-- Consider  and  to be two points on a 2D plane where  are the respective minimum and maximum values of Northern Latitude (LAT_N) and  are the respective minimum and maximum values of Western Longitude (LONG_W) in STATION.

-- Query the Manhattan Distance between points p1  and p2 and round it to 4 decimal digits.

SELECT ROUND(ABS((MAX(LONG_W) - MAX(LAT_N)))+ABS((MIN(LAT_N)-MIN(LONG_W))),4) FROM STATION;