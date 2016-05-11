all: exe lib

exe:	hello.h main.c lib
	# gcc main.c -L. -lHello -o hello
	# gcc main.c -fPIC -L. -lHello -o hello
	gcc 1-3-2-main.c -fPIC -ldl -o hello

lib: 	hello.h hello.c
	# gcc -shared hello.c -o libHello.so
	gcc -shared hello.c -fPIC -o libHello.so

clean:
	-rm -f hello hello.exe libHello.so 2>/dev/null