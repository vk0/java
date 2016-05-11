#!/bin/sh
gcc -o libHello.so -shared hello.c

# for x64
# gcc -o libHello.so -shared -fPIC hello.c

nm ./libHello.so

#gcc main.c -L./ -lHello -o hello
#export LD_LIBRARY_PATH=.