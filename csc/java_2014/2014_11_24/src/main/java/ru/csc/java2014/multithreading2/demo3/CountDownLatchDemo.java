package ru.csc.java2014.multithreading2.demo3;

import java.util.concurrent.CountDownLatch;

public class CountDownLatchDemo {

    public static void main(String[] args) throws InterruptedException {
        CountDownLatch latch = new CountDownLatch(10);

        for (int i = 0; i < 10; ++i) {
            new DemoThread(latch).start();
        }
    }


    private static class DemoThread extends Thread {

        private final CountDownLatch latch;

        private DemoThread(CountDownLatch latch) {
            this.latch = latch;
        }

        @Override
        public void run() {
            try {
                runUnsafe();
            } catch (InterruptedException e) {
                System.out.println(getName() + " interrupted");
            }
        }

        private void runUnsafe() throws InterruptedException {
            // initialization phase
            Thread.sleep((long) (Math.random() * 10000L));

            System.out.println(getName() + " finished initialization");

            latch.countDown();
            latch.await();

            System.out.println(getName() + " entered main phase");

            // main phase
            Thread.sleep((long) (Math.random() * 10000L));
        }
    }
}
