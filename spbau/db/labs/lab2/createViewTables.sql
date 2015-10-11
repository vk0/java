CREATE TABLE Player57TeamMate (
  PlayerNo INTEGER NOT NULL,
  PRIMARY KEY (PlayerNo)
);

CREATE TABLE PlayersBirthYearANY (
  PlayerNo INTEGER NOT NULL,
  Name VARCHAR(45) NOT NULL,
  BirthYear INTEGER NOT NULL,
  PRIMARY KEY (PlayerNo)
);

CREATE TABLE PlayersBirthYearIN (
  PlayerNo INTEGER NOT NULL,
  BirthYear INTEGER NOT NULL,
  PRIMARY KEY (PlayerNo)
);

CREATE TABLE PlayersPenalties (
  PlayerNo INTEGER NOT NULL,
  PRIMARY KEY (PlayerNo)
);

CREATE TABLE StratfordPlayers (
  PlayerNo INTEGER NOT NULL,
  Address VARCHAR(70) NOT NULL,
  LeagueNo VARCHAR(4)                 ,
  PRIMARY KEY (PlayerNo)
);

CREATE TABLE Team1Players (
  PlayerNo INTEGER NOT NULL,
  Name VARCHAR(45) NOT NULL,
  PRIMARY KEY (PlayerNo)
);
