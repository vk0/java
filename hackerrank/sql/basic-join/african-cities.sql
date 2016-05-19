-- Given the CITY and COUNTRY tables, query the names of all cities where the CONTINENT is 'Africa'.

-- Note: CITY.CountryCode and COUNTRY.Code are matching key columns.

SELECT CI.NAME FROM CITY CI JOIN COUNTRY CO ON CI.COUNTRYCODE = CO.CODE WHERE CO.CONTINENT = 'Africa';
