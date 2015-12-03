// Задача на программирование: рюкзак

// ﻿

// Первая строка входа содержит целые числа 1≤W≤104 и 1≤n≤300 — вместимость рюкзака и число золотых слитков. Следующая строка содержит n целых чисел 0≤w1,…,wn≤105, задающих веса слитков. Найдите максимальный вес золота, который можно унести в рюкзаке.

// Sample Input:

// 10 3
// 1 4 8

// Sample Output:

// 9

import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int knapsack_weight = sc.nextInt();
        int num_bullions = sc.nextInt();

        int[] bullions = new int[num_bullions+1];
        for(int i = 1; i < bullions.length; i++)
            bullions[i] = sc.nextInt();

        System.out.println(maxWeightFit(knapsack_weight, bullions));
    }

    public static int maxWeightFit(int capacity, int[] weights){
        int[][] dp = new int[capacity + 1][weights.length];

        for(int i = 1; i <= capacity; i++){
            for(int j = 1; j < weights.length; j++){
                 if(weights[j] <= i)
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-weights[j]][j-1] + weights[j]);
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[capacity][weights.length-1];
    }

    public static void printMatrix(int[][] mat){
        System.out.print('\n');
        for(int i = 0; i < mat.length; i++){
            for(int j = 0; j < mat[0].length; j++){
                System.out.print(mat[i][j]);
            }
            System.out.print('\n');
        }
    }
}