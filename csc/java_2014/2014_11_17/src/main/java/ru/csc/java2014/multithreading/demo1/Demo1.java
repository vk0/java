package ru.csc.java2014.multithreading.demo1;

public class Demo1 {

    public static void main(String[] args) {
        for (int i = 0; i < 10; ++i) {
            new HelloThread().start();
        }

        System.out.println("Hello from main thread");
    }


    private static class HelloThread extends Thread {

        @Override
        public void run() {
            System.out.println("Hello from " + getName());
        }
    }

//    private static class HelloRunnable implements Runnable {
//
//        @Override
//        public void run() {
//            System.out.println("Hello from " + Thread.currentThread().getName());
//        }
//    }
}
