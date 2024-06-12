package org.crossplatform;

public class Bank {
    private int totalCash;

    public Bank(int initialCash) {
        this.totalCash = initialCash;
    }

    public synchronized void withdrawCash(int amount, String clientName) {
        if (totalCash >= amount) {
            totalCash -= amount;
            System.out.println(clientName + " withdrew $" + amount + ". Remaining cash: $" + totalCash);
        } else {
            System.out.println(clientName + " tried to withdraw $" + amount + ", but there is not enough cash.");
        }
    }

    public synchronized void depositCash(int amount, String clientName) {
        totalCash += amount;
        System.out.println(clientName + " deposited $" + amount + ". Total cash: $" + totalCash);
    }
}


