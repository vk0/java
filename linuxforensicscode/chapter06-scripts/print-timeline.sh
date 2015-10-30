#!/bin/bash
#
# print-timeline.sh
#
# Simple shell script to print a timeline.
#
# Developed for PentesterAcademy by
# Dr. Phil Polstra (@ppolstra)

usage () {
	echo "usage: $0 <database> <starting date>"
	echo "Simple script to get timeline from the database"
	exit 1
}

if [ $# -lt 2 ] ; then
   usage
fi


cat << EOF | mysql $1 -u root -p 
select Operation, timeline.date, timeline.time,
   filename, permissions, userid, groupid
   from files, timeline
   where timeline.date >= str_to_date("$2", "%m/%d/%Y") and
   files.recno = timeline.recno 
   order by timeline.date desc, timeline.time desc;
EOF
