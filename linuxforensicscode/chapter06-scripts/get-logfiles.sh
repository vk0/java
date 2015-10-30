#!/bin/bash
#
# get-logfiles.sh
#
# Simple script to get all logs and optionally
# store them in a database.
# Warning: This script might take a long time to run!
# by Dr. Phil Polstra (@ppolstra) as developed for
# PentesterAcademy.com.

usage () {
	echo "usage: $0 <mount point of root> [database name]"
	echo "Simple script to get log files and" 
        echo "optionally store them to a database."
	exit 1
}

if [ $# -lt 1 ] ; then
   usage
fi

# remove old file if it exists
if [ -f /tmp/logfiles.csv ] ; then
  rm /tmp/logfiles.csv
fi

# find only files, exclude files with numbers as they are old logs 
# execute echo, cat, and echo for all files found 
olddir=$(pwd)
cd $1/var
find log -type f -regextype posix-extended \
   -regex 'log/[a-zA-Z\.]+(/[a-zA-Z\.]+)*' \
   -exec awk '{ print "{};" $0}' {} \; \
   | tee -a /tmp/logfiles.csv
cd $olddir

if [ $# -gt 1 ] ; then
chown mysql:mysql /tmp/logfiles.csv
clear
echo "Let's put that in the database"
cat << EOF | mysql $2 -u root -p 
create table if not exists logs (
   logFilename varchar(2048) not null,
   logentry varchar(2048) not null,
   recno bigint not null auto_increment,
   primary key(recno)
);

load data infile "/tmp/logfiles.csv"
   into table logs
   fields terminated by ';'
   enclosed by '"' 
   lines terminated by '\n'; 
EOF
fi


