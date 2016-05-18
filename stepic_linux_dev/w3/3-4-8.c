// Вы запустили следующую программу. Определите какое суммарное количество системных вызовов  read,write будет сделано в результате выполнения программы из консоли.

#include <stdio.h>

int main()
{
  char name[100];
  printf("What is your name? __");
  gets(name);
  // fgets(name, sizeof(name), stdin);
  return printf("Hello %s\n",name);
}

// 4

// with gets = 4
strace -e read,write ./a.out
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\34\2\0\0\0\0\0"..., 832) = 832
write(1, "What is your name? __", 21What is your name? __)   = 21
read(0, asd
"asd\n", 1024)                  = 4
write(1, "Hello asd\n", 10Hello asd
)             = 10
+++ exited with 10 +++


// with fgets = 5
strace -e read,write ./a.out
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\34\2\0\0\0\0\0"..., 832) = 832
write(1, "What is your name? __", 21What is your name? __)   = 21
read(0, asd
"asd\n", 1024)                  = 4
write(1, "Hello asd\n", 10Hello asd
)             = 10
write(1, "\n", 1
)                       = 1
+++ exited with 11 +++
