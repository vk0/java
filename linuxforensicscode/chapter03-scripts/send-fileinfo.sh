# send-fileinfo.sh
#
# Simple script to collect file information as part of
# initial live incident response.
# Warning: This script might take a long time to run!
# by Dr. Phil Polstra (@ppolstra) as developed for
# PentesterAcademy.com.

usage () {
	echo "usage: $0 <starting directory>"
	echo "Simple script to send file information to a log listener"
	exit 1
}

if [ $# -lt 1 ] ; then
   usage
fi

# semicolon delimited file which makes import to spreadsheet easier
# printf is access date, access time, modify date, modify time,
#           create date, create time, permissions, user id, user name,
#           group id, group name, file size, filename and then line feed
# if you want nice column labels in your spreadsheet, paste the following
# line (minus #) at start of your CSV file
#Access Date;Access Time;Modify Date;Modify Time;Create Date;Create Time;Permissions;UID;Username;GID;Groupname;Size;File
send-log.sh find $1 -printf "%Ax;%AT;%Tx;%TT;%Cx;%CT;%m;%U;%u;%G;%g;%s;%p\n"
