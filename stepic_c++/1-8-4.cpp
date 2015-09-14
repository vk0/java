#include <cstdio>
#include <math.h>
using namespace std;
#define sqr(x) x * x
int power(int x, unsigned p) {
    int answer;
    answer = pow(x,p);
    /* считаем answer */
    return answer;
}

int  main () {
// power(5,5);
printf ("%g",power(3,5));
printf ("%g",sqr(3 + 0));
}

http://www.programmersforum.ru/showthread.php?t=123333
http://www.cyberforum.ru/cpp-beginners/thread300222.html

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (r)=(a) : (r)=(b))

#define MAX(x, y, r) (((x) > (y)) ? (r)=(x) : (r)=(y))

int a = 10;
int b = 20;
int c = 0;
max(a, b, c);