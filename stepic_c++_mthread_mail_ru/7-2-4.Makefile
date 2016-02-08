all:
	gcc -D_XOPEN_SOURCE=700 -o /home/box/posix_mutex /home/box/7-2-4.c -lrt