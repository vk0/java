#!/bin/sh
rm -f ./libHello
cp hello.c hello.cpp
gcc -shared -o libHello.so hello.cpp
#x64
#gcc -shared -o libHello.so -fPIC hello.cpp

nm libHello.so

#show function real name
c++filt __Z13hello_messagePKc