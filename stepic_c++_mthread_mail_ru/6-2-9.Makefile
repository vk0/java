all:
	gcc -std=c99 -Wall -D_XOPEN_SOURCE=700 -o /home/box/msgq_posix /home/box/6-2-9.c -lrt