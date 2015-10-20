package ru.csc.java2014.multithreading2.demo4;

public class LockDemo {

    public static void main(String[] args) throws Exception {
        Account account = new Account(0);

        new DepositThread(account).start();

        account.waitAndWithdraw(50000000);

        System.out.println("waitAndWithdraw finished, end balance = " + account.getBalance());
    }


    private static class DepositThread extends Thread {

        private final Account account;

        private DepositThread(Account account) {
            this.account = account;
        }

        @Override
        public void run() {
            for (int i = 0; i < 60000000; ++i) {
                account.deposit(1);
            }
        }
    }

}
