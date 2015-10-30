# send-sha256sum.sh
#
# Simple script to calculate sha1 sum as part of
# initial live incident response.
# Warning: This script might take a long time to run!
# by Dr. Phil Polstra (@ppolstra) as developed for
# PentesterAcademy.com.

usage () {
	echo "usage: $0 <starting directory>"
	echo "Simple script to send SHA1 hash to a log listener"
	exit 1
}

if [ $# -lt 1 ] ; then
   usage
fi

# find only files, don't descend to other filesystems, 
# execute command sha1sum -b <filename> for all files found 
send-log.sh find $1 -type f -xdev -exec sha1sum -b {} \;
