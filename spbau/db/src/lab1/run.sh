#!/bin/bash

DIR=$PWD
DRIVER="$DIR/postgresql.jar"

echo "current dir: $DIR"
echo "jdbc arj: $DRIVER"
export CLASSPATH="$CLASSPATH:$DRIVER"
echo "classpath: $CLASSPATH"

echo "start speed test:"

java -Djdbc.Drivers=postgresql.Driver $1
