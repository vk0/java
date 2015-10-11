insert into StratfordPlayers 
SELECT   PlayerNo, Street + ' ' + HouseNo AS Address, LeagueNo
FROM     Players
WHERE    Town = 'Stratford'
ORDER BY LeagueNo;

insert into PlayersBirthYearIN
SELECT   PlayerNo, BirthYear
FROM     Players
WHERE    BirthYear IN (1962, 1963, 1970);

insert into Team1Players
SELECT   PlayerNo, Name
FROM     Players
WHERE    PlayerNo IN 
        (SELECT   PlayerNo
         FROM     Matches
         WHERE    TeamNo = 1);

insert into PlayersBirthYearANY
SELECT   PlayerNo, Name, BirthYear
FROM     Players 
WHERE    BirthYear  > ANY 
        (SELECT   BirthYear 
         FROM     Players);

insert into PlayersPenalties
SELECT   DISTINCT PlayerNo
FROM     Penalties PN
WHERE    EXISTS
        (SELECT   *
         FROM     Penalties 
         WHERE    PN.PlayerNo = PlayerNo 
         AND      PaymentNo <> PN.PaymentNo );

insert into Player57TeamMate
SELECT   PlayerNo
FROM     Players P
WHERE    NOT EXISTS
        (SELECT *
         FROM   Matches M1
         WHERE  PlayerNo = 57
         AND    NOT EXISTS
               (SELECT  *
                FROM    Matches M2
                WHERE   M1.TeamNo = M2.TeamNo
                AND     P.PlayerNo = M2.PlayerNo))
AND      PlayerNo NOT IN 
        (SELECT   PlayerNo
         FROM     Matches 
         WHERE    TeamNo IN
                 (SELECT   TeamNo
                  FROM     Teams 
                  WHERE    TeamNo NOT IN
                          (SELECT TeamNo
                           FROM   Matches 
                           WHERE  PlayerNo = 57)));