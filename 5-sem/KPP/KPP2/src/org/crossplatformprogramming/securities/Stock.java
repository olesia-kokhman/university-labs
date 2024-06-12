package org.crossplatformprogramming.securities;

public class Stock extends Security{
    private double dividend;

    public Stock() {
        super();
    }

    public Stock(String name, double price, Trend trend, RiskLevel riskLevel, double dividend) {
        super(name, price, trend, riskLevel);
        this.dividend = dividend;
    }

    public double countDividendPerMonth() {
        return price * dividend;
    }

}
