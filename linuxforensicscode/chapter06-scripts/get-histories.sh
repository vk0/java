#!/bin/bash
#
# get-histories.sh
#
# Simple script to get all user bash history files and .
# by Dr. Phil Polstra (@ppolstra) as developed for
# PentesterAcademy.com.

usage () {
	echo "usage: $0 <mount point of root> [database name]"
	echo "Simple script to get user histories and \
              optionally store them in the database"
	exit 1
}

if [ $# -lt 1 ] ; then
   usage
fi

# find only files, filename is .bash_history 
# execute echo, cat, and echo for all files found 
olddir=$(pwd)
cd $1
find home -type f -regextype posix-extended \
   -regex "home/[a-zA-Z\.]+(/\.bash_history)" \
   -exec awk '{ print "{};" $0}' {} \; \
   | tee /tmp/histories.csv
# repeat for the admin user
find root -type f -regextype posix-extended \
   -regex "root(/\.bash_history)" \
   -exec awk '{ print "{};" $0}' {} \; \
   | tee -a /tmp/histories.csv
cd "$olddir"

if [ $# -gt 1 ] ; then
chown mysql:mysql /tmp/histories.csv
cat << EOF | mysql $2 -u root -p 
create table if not exists histories (
   historyFilename varchar(2048) not null,
   historyCommand varchar(2048) not null,
   recno bigint not null auto_increment,
   primary key(recno)
);

load data infile "/tmp/histories.csv"
   into table histories
   fields terminated by ';'
   enclosed by '"' 
   lines terminated by '\n'; 
EOF
fi


