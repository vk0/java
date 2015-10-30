#!/bin/bash
#
# close-case.sh
#
# Simple script to start shut down listeners. 
# Intended to be used as part of initial live response.
# by Dr. Phil Polstra (@ppolstra) as developed for
# PentesterAcademy.com.

echo "Shutting down listeners at $(date) at user request" | nc localhost 4444
killall start-case.sh
killall start-file-listener.sh
killall nc

