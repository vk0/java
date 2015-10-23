#include <stdio.h>

int main(void)
{
	int a=25;
	double f=9.3e+03;
	char c='g';
	char* s = "Hello, world";
	printf("%d %5d %.5d %-5d\n", a, a, a, a);
	printf("%lf %9.3lf %-9.3lf\n", f, f, f, f);
	printf("%c %5c %-5c\n", c, c, c);
	printf("%s %20s %.5s %-20s\n", s, s, s, s);
	printf("Enter a:");
	scanf("a=%d",&a);
	printf("a=%d\n",a);
	return 0;
}