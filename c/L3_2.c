#include<stdio.h>

//перевод 10 числа в двоичное
main ()
{
    int i,n;
    unsigned int testNumber=1;

    printf("Input interger: ");
    scanf("%d",  &n);

    for(i=0;i<sizeof(int)*8;i++)
    {
        printf("%1d",(n&testNumber)?1:0);
        testNumber=testNumber<<1;
    }

}

/**********************
main ()
{
    int i,a,b;
    printf("Input a b(0-255) :");
    scanf("%d %d",  &a,  &b);

    //проверка
    if(a>b)     a=0;
    if(b>255)   b=255;
    if(a<0)     a=0;

    for (i=a; i<=b; i++)
    {
        printf("%3d-%c  ",  i,  i);
        if (i%5==0) printf("\n");
    }
}
***************************/
