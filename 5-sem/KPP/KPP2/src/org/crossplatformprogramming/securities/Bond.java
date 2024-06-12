package org.crossplatformprogramming.securities;

import java.time.LocalDate;
import java.util.Comparator;


public class Bond extends Security{
    private LocalDate maturityDate;
    private double annualInterestRate;

    public Bond() {
        super();
    }

    public Bond(String name, double price, Trend trend, RiskLevel riskLevel, double annualInterestRate, LocalDate maturityDate) {
        super(name, price, trend, riskLevel);
        this.annualInterestRate = annualInterestRate;
        this.maturityDate = maturityDate;
    }

    public double countFaceValue() {
        return (price * annualInterestRate) + price;
    }

    public class MaturityDateComparator implements Comparator<Bond> {

        @Override
        public int compare(Bond bond1, Bond bond2) {
            return bond1.maturityDate.compareTo(bond2.maturityDate);
        }

    }

    @Override
    public String toString() {
        return super.toString() +
                "{ maturityDate=" + maturityDate +
                ", annualInterestRate=" + annualInterestRate +
                "} ";
    }
}
