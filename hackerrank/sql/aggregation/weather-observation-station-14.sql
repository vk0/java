-- Query the greatest value of the Northern Latitudes from STATION that are under 137.2345 and truncated to 4 decimal places

select round(max(LAT_N),4) from station where LAT_N < '137.2345';
