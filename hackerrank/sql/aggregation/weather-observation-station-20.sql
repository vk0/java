-- A median is defined as a number separating the higher half of a data set from the lower half. Query the median of the Northern Latitudes (LAT_N) from STATION and round your answer to  decimal places.

-- Note: Oracle solutions are not permitted for this challenge.

SELECT round( x.LAT_N, 4 ) from STATION x, STATION y GROUP BY x.LAT_N HAVING SUM( SIGN( 1-SIGN( y.LAT_N -x.LAT_N ) ) )/COUNT(*) > .5 LIMIT 1;