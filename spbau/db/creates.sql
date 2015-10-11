create table "region" (
		id serial primary key,
		name varchar(80) not null unique
		);
		
create table "rate" (
		id serial primary key,
		name varchar(80) not null unique,
		homepay money not null,
		foreignpay money not null
		);
		
create table "tower" (
		id serial primary key,
		region_id integer references "region"(id) on delete no action
		);
		
create table "user" (
		id serial primary key,
		name varchar(255) not null,
		regionid integer references "region"(id) on delete no action,
		rateid integer references "rate"(id) on delete no action
		);

create table "towerserveuser" (
		userid integer references "user"(id) on delete cascade,
		towerid integer references "tower"(id) on delete no action,
		begintime timestamp not null,
		endtime timestamp null,
		constraint userveid
			primary key (userid, towerid, begintime),
			check (begintime < endtime)
		);

create table "usercalluser" (
			firstid integer references "user"(id) on delete no action,
			secondid integer references "user"(id) on delete no action,
			begintime timestamp not null,
			endtime timestamp null,
			constraint ucallid
				primary key (firstid, secondid, begintime),
				check (begintime < endtime),
				check (firstid <> secondid)
		);
