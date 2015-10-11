create Index PlayersTown on Players (Town, LeagueNo ASC);
create index PlayersBirthYear on Players (BirthYear);
create index TeamMatches on Matches (TeamNo, PlayerNo);
create index PlayerPenalties on Penalties (PlayerNo);

