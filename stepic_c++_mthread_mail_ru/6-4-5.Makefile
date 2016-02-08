all:
	gcc -std=c99 -D_XOPEN_SOURCE=700 -o /home/box/sysv_shm /home/box/6-4-5.c -lpthread