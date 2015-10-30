#!/bin/bash
#
# get-logfiles-ext.sh
#
# Simple script to get all logs and optionally
# store them in a database.
# Warning: This script might take a long time to run!
# by Dr. Phil Polstra (@ppolstra) as developed for
# PentesterAcademy.com.
#
# This is an extended version of get-logfiles.sh.
# It will attempt to load current logs and archived logs.
# This could take a long time and required lots of storage.

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

olddir=$(pwd)
cd $1/var
for logfile in $(find log -type f -name '*')
do 
   if echo $logfile | egrep -q "\.gz$"  ; then
     zcat $logfile | awk "{ print \"$logfile;\" \$0 }" \
     | tee -a /tmp/logfiles.csv
   else
     awk "{ print \"$logfile;\" \$0 }" $logfile  \
     | tee -a /tmp/logfiles.csv
   fi
done
cd "$olddir"

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


