#!/bin/bash
#
# get-logins.sh
#
# Simple script to get all successful and unsuccessful 
# login attempts and optionally store them in a database.
# 
# by Dr. Phil Polstra (@ppolstra) as developed for
# PentesterAcademy.com.

usage () {
	echo "usage: $0 <mount point of root> [database name]"
	echo "Simple script to get logs of successful "
  echo "and unsucessful logins."
  echo "Results may be optionally stored in a database"
	exit 1
}

if [[ $# -lt 1 ]] ; then
   usage
fi

# use the last and lastb commands to display information
# use awk to create ; separated fields
# use sed to strip white space
echo "who-what;terminal-event;start;stop;elapsedTime;ip" \
   | tee /tmp/logins.csv
for logfile in $1/var/log/wtmp*
do
  last -aiFwx -f $logfile | \
    awk '{print substr($0, 1, 8) ";" substr($0, 10, 13) ";" \
       substr($0, 23, 24) ";" substr($0, 50, 24) ";" substr($0, 75, 12) \
       ";" substr($0, 88, 15)}' \
    | sed 's/[[:space:]]*;/;/g' | sed 's/[[:space:]]+\n/\n/' \
    | tee -a /tmp/logins.csv 
done

echo "who-what;terminal-event;start;stop;elapsedTime;ip" \
   | tee /tmp/login-fails.csv
for logfile in $1/var/log/btmp*
do
  lastb -aiFwx -f $logfile | \
    awk '{print substr($0, 1, 8) ";" substr($0, 10, 13) ";" \
       substr($0, 23, 24) ";" substr($0, 50, 24) ";" substr($0, 75, 12) \
       ";" substr($0, 88, 15)}' \
    | sed 's/[[:space:]]*;/;/g' | sed 's/[[:space:]]+\n/\n/' \
    | tee -a /tmp/login-fails.csv 
done

if [ $# -gt 1 ] ; then
chown mysql:mysql /tmp/logins.csv
chown mysql:mysql /tmp/login-fails.csv
cat << EOF | mysql $2 -u root -p 
create table logins (
   who_what varchar(8),
   terminal_event varchar(13),
   start datetime,
   stop datetime,
   elapsed varchar(12),
   ip varchar(15),
   recno bigint not null auto_increment,
   primary key(recno)
);

load data infile "/tmp/logins.csv"
   into table logins
   fields terminated by ';'
   enclosed by '"' 
   lines terminated by '\n'
   ignore 1 rows
   (who_what, terminal_event, @start, @stop, elapsed, ip)
   set start=str_to_date(@start, "%a %b %e %H:%i:%s %Y"),
       stop=str_to_date(@stop, "%a %b %e %H:%i:%s %Y"); 

create table login_fails (
   who_what varchar(8),
   terminal_event varchar(13),
   start datetime,
   stop datetime,
   elapsed varchar(12),
   ip varchar(15),
   recno bigint not null auto_increment,
   primary key(recno)
);

load data infile "/tmp/login-fails.csv"
   into table login_fails
   fields terminated by ';'
   enclosed by '"' 
   lines terminated by '\n'
   ignore 1 rows
   (who_what, terminal_event, @start, @stop, elapsed, ip)
   set start=str_to_date(@start, "%a %b %e %H:%i:%s %Y"),
       stop=str_to_date(@stop, "%a %b %e %H:%i:%s %Y"); 
EOF

fi


