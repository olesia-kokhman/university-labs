package org.crossplatform;

import java.util.Random;

public class Client implements Runnable {
    private final Bank bank;
    private final String name;
    private final Random random = new Random();
    private volatile boolean suspended = false;

    public Client(Bank bank, String name) {
        this.bank = bank;
        this.name = name;
    }

    public String getClientName() {
        return name;
    }

    public synchronized void suspendClient() {
        suspended = true;
        System.out.println("suspended " + this.getClientName());
    }

    public synchronized void resumeClient() {
        suspended = false;
        notify();
        System.out.println("resumed " + this.getClientName());
    }

    public void getInfo() {
        Thread currectThread = Thread.currentThread();
        System.out.println("Thread name - " + currectThread.getName());
        System.out.println("Thread state - " + currectThread.getState());
        System.out.println("Thread priority - " + currectThread.getPriority());
    }

    @Override
    public void run() {
        while (true) {
            if (suspended) {
                try {
                    synchronized (this) {
                        wait();
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            int amount = random.nextInt(100) + 1;
            if (random.nextBoolean()) {
                bank.withdrawCash(amount, name);
            } else {
                bank.depositCash(amount, name);
            }

            try {
                Thread.sleep(random.nextInt(1000) + 500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}