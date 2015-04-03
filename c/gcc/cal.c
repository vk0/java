#include <stdio.h>

int main(void)

{

 float num1;
 float num2;
 char op;

printf("Первое число: ");
 scanf("%f",&num1);
 printf("Второе число: ");
 scanf("%f",&num2);
printf("Оператор ( + - * / ): ");
while ((op = getchar()) != EOF)
 {
 if (op == '+')
 {
 printf("%6.2f\n",num1 + num2);
 break;
 }
 else if(op == '-')
 {
 printf("%6.2f\n",num1 - num2);
 break;
 }
 else if(op == '*')
 {
 printf("%6.2f\n",num1 * num2);
 break;
 }
 else if(op == '/')
 {
 if(num2 == 0)
 {
 printf("Ошибка: деление на ноль!\n");
break;
 }
 else
 {
 printf("%6.2f\n",num1 / num2);
 break;
 }
 }
 }
 return 0;
}
