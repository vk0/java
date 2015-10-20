package ru.csc.java2014.multithreading2.demo6;

import java.util.Arrays;
import java.util.concurrent.atomic.DoubleAdder;

public class ParallelStreamBroken {

    public static void main(String[] args) {
        int[] array = Commons.prepareArray();


        long startTime = System.currentTimeMillis();

        double[] sum = new double[1];
        Arrays.stream(array)
                .parallel()
                .mapToDouble(Commons::function)
                .forEach(x -> sum[0] += x);

        long endTime = System.currentTimeMillis();

        System.out.println("sum = " + sum[0]);
        System.out.println("time = " + (endTime - startTime) + "ms");
    }
}
