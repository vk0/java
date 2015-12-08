# Выведите разложение натурального числа n > 1 на простые множители. Простые множители должны быть упорядочены по возрастанию и разделены пробелами.

# Sample Input:

# 75

# Sample Output:

# 3 5 5

# import java.util.Scanner;

# class Main {
#     public static void main(String[] args) {
#         int n = 0;
#         Scanner sc = new Scanner(System.in);
#         if (sc.hasNextInt())
#             n = sc.nextInt();
#         for (int i = 2; i <= n; i++)
#             if (test(i))
#             if (n % i == 0) {
#                 n = n / i;
#                 System.out.print(i + " ");
#                 i = 2;} }


#     public static boolean test(long n) {
#         for (long i = 2;i <= Math.sqrt(n);i++)
#         if (n % i == 0)
#             return false;
#         return true;
#     }
# }


n = 75
# n = int(input())
a = []
while n > 1:
    i = 2
    while 1:
        if n%i==0:
            a.append(i)
            n = n // i
            break
        else:
            i += 1
for i in a:
    print(i,end=' ')
print()