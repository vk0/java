package ru.csc.java2014.multithreading2.demo6;

public class Sequential {

    public static void main(String[] args) {
        int[] array = Commons.prepareArray();

        long startTime = System.currentTimeMillis();

        double sum = Commons.calculate(array);

        long endTime = System.currentTimeMillis();

        System.out.println("sum = " + sum);
        System.out.println("time = " + (endTime - startTime) + "ms");
    }
}
