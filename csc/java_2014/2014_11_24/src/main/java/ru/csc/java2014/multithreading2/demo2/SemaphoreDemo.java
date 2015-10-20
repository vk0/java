package ru.csc.java2014.multithreading2.demo2;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;

public class SemaphoreDemo {


    public static void main(String[] args) throws Exception {
        Semaphore semaphore = new Semaphore(2);

        List<Thread> threads = new ArrayList<Thread>();
        for (int i = 0; i < 10; ++i) {
            DemoThread thread = new DemoThread(semaphore);
            threads.add(thread);
            thread.start();
        }

        Thread.sleep(20000);

        for (Thread thread : threads) {
            thread.interrupt();
        }
    }


    private static class DemoThread extends Thread {

        private final Semaphore semaphore;

        private DemoThread(Semaphore semaphore) {
            this.semaphore = semaphore;
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
            for (;;) {
                semaphore.acquire();
                try {
                    System.out.println(getName() + " acquired semaphore");
                    Thread.sleep(5000L);
                } finally {
                    System.out.println(getName() + " releasing semaphore");
                    semaphore.release();
                }
            }
        }
    }
}
