package ru.csc.java2014.fprog;

import java.math.BigDecimal;
import java.util.Optional;
import java.util.function.Supplier;
import java.util.stream.Stream;

/**
 * @author av
 */
public class Fibonacci {

    public static void main(String[] args) {
        BigDecimal million = new BigDecimal(1_000_000);
        Optional<BigDecimal> first = Stream.generate(new FibonacciSupplier())
                .filter((d) -> d.compareTo(million) >= 0)
                .findFirst();

        System.out.println(first.get());
    }


    private static class FibonacciSupplier implements Supplier<BigDecimal> {
        private BigDecimal prev = BigDecimal.ZERO;
        private BigDecimal next = BigDecimal.ONE;

        @Override
        public BigDecimal get() {
            BigDecimal current = next;
            next = prev.add(current);
            prev = current;
            return current;
        }
    }
}
