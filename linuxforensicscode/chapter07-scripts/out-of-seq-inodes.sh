#!/bin/bash
#
# out-of-seq-inodes.sh
#
# Simple script to list out of
# sequence inodes.
# Intended to be used as part of
# a forensics investigation.
# As developed for PentesterAcademy.com 
# by Dr. Phil Polstra (@ppolstra)

usage () {
    echo "Usage: $0 <path>"
    echo "Simple script to list a directory and print a warning if"
    echo "the inodes are out of sequence as will happen if system"
    echo "binaries are overwritten."
    exit 1
}

if [ $# -lt 1 ] ; then
  usage
fi

# output a listing sorted by inode number to a temp file
templs='/tmp/temp-ls.txt'
ls -ali $1 | sort -n > $templs

# this is for discarding first couple lines in output
foundfirstinode=false 
declare -i startinode

while read line
do
   # there is usually a line or two of non-file stuff at start of output
   # the if statement helps us get past that
   if [ "$foundfirstinode" = false ] \
   && [ "`echo $line | wc -w`" -gt 6 ] ; then
      startinode=`expr $(echo $line | awk '{print $1}')`
      echo "Start inode = $startinode"
      foundfirstinode=true
   fi
   q=$(echo $line | awk '{print $1}')
   if [[ $q =~ ^-?[0-9]+$ ]] && \
     [ $((startinode)) -lt "$q" ] ; 
   then
      if [ $((startinode + 2)) -lt $q ] ; then
          echo -e "\e[31m****Out of Sequence inode detected**** \
expect $startinode got $q\e[0m"
      else
          echo -e "\e[33m****Out of Sequence inode detected**** \
expect $startinode got $q\e[0m"
      fi
      # reset the startinode to point to this value for next entry
      startinode=`expr $(echo $line | awk '{print $1}')`
   fi
   echo "$line"
   startinode=$((startinode+1))
done < $templs

rm $templs
