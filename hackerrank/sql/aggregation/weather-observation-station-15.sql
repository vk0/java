-- Query the Western Longitude for the largest Northern Latitude under 137.2345, rounded to 4 decimal places.

Select ROUND(LONG_W,4) from STATION WHERE LAT_N = (SELECT MAX(LAT_N) FROM STATION WHERE LAT_N<137.2345);