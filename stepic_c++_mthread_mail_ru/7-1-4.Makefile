all:
	gcc -D_XOPEN_SOURCE=700 -o /home/box/posix_threads /home/box/7-1-4.c -lrt