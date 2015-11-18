// Задача на программирование: двоичный поиск
// В первой строке даны целое число 1≤n≤105 и массив A[1…n] из n различных натуральных чисел, не превышающих 109, в порядке возрастания, во второй — целое число 1≤k≤105 и k натуральных чисел b1,…,bk, не превышающих 109. Для каждого i от 1 до k необходимо вывести индекс 1≤j≤n, для которого A[j]=bi, или −1, если такого j нет.

// Sample Input:

// 5 1 5 8 12 13
// 5 8 1 23 1 11

// Sample Output:

// 3 1 -1 1 -1

import java.util.Scanner;

class Main {
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] toSearch = new int[n];
      for(int i = 0; i < n; i++)
          toSearch[i] = sc.nextInt();
      int k = sc.nextInt();
      for(int i = 0; i < k; i++){
          System.out.print(bsearch(toSearch, sc.nextInt()));
          System.out.print(" ");
      }
  }

  public static int bsearch(int[] toSearch, int toFind){
      int left = 0, right = toSearch.length-1;
      int mid = (right + left)/2;
      while(left <= right){
          if(toSearch[mid] == toFind)
              return mid + 1;
          if(toFind > toSearch[mid])
              left = mid + 1;
          else
              right = mid - 1;
          mid = (right + left)/2;
      }
      return -1;
  }
}