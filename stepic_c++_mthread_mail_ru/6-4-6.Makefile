all:
	gcc -D_XOPEN_SOURCE=700 -o /home/box/posix_shm /home/box/6-4-6.c -lrt