all:
	gcc -std=c99 -D_XOPEN_SOURCE=700 -o /home/box/posix_sem /home/box/6-3-7.c -lpthread