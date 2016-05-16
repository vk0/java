-- Query all columns for all American cities in CITY with populations larger than 100,000. The CountryCode for America is USA.

-- Input Format

-- The CITY table is described as follows: CITY.jpg

select * from CITY Where CountryCode = 'USA' and POPULATION > 100000