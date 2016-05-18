-- Consider  and  to be two points on a 2D plane where  are the respective minimum and maximum values of Northern Latitude (LAT_N) and  are the respective minimum and maximum values of Western Longitude (LONG_W) in STATION.

-- Query the Euclidean Distance between points  and  and format your answer to display  decimal digits.

select round(sqrt(power(min(lat_n)-min(long_w),2)+power(max(lat_n)-max(long_w),2)),4) from station;