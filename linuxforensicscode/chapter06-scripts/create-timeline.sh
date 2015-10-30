#!/bin/bash
#
# create-timeline.sh
#
# Simple shell script to create a timeline in the database.
#
# Developed for PentesterAcademy by
# Dr. Phil Polstra (@ppolstra)

usage () {
	echo "usage: $0 <database>"
	echo "Simple script to create a timeline in the database"
	exit 1
}

if [ $# -lt 1 ] ; then
   usage
fi

cat << EOF | mysql $1 -u root -p 
create table timeline (
   Operation char(1), 
   Date date not null,
   Time time not null,
   recno bigint not null
);


insert into timeline (Operation, Date, Time, recno)
   select "A", accessdate, accesstime, recno from files;
insert into timeline (Operation, Date, Time, recno)
   select "M", modifydate, modifytime, recno from files;
insert into timeline (Operation, Date, Time, recno)
   select "C", createdate, createtime, recno from files;

EOF
