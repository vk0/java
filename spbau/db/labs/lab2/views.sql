create view StratfordPlayerAddress AS
SELECT   PlayerNo, Street + ' ' + HouseNo AS Address
FROM     Players
WHERE    Town = 'Stratford';

create view StratfordPlayerLeague AS
SELECT   PlayerNo, LeagueNo
FROM     Players
WHERE    Town = 'Stratford';

create view PlayerBirth AS
SELECT   PlayerNo, BirthYear
FROM     Players
WHERE    BirthYear IN (1962, 1963, 1970);

create view Team1Matches AS
SELECT   PlayerNo
         FROM     Matches
         WHERE    TeamNo = 1;
