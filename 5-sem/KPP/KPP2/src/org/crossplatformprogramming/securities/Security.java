package org.crossplatformprogramming.securities;

import java.util.Comparator;

public abstract class Security {

    protected double price;

    @Override
    public String toString() {
        return "\nSecurity{" +
                "price=" + price +
                ", name='" + name + '\'' +
                ", riskLevel=" + riskLevel +
                ", trend=" + trend +
                "}";
    }

    protected String name;
    protected RiskLevel riskLevel;
    protected Trend trend;

    Security() {}

    Security(String name, double price, Trend trend, RiskLevel riskLevel) {
        this.name = name;
        this.price = price;
        this.trend = trend; // how to copy objects ???
        this.riskLevel = riskLevel;
    }

    public String getName() {
        return this.name;
    }

    public RiskLevel getRiskLevel() {
        return this.riskLevel;
    }

    public double getPrice() {
        return this.price;
    }

    public Trend getTrend() {
        return this.trend;
    }

    public static class PriceComparator implements Comparator<Security> {

        @Override
        public int compare(Security security1, Security security2) {
            return Double.compare(security1.price, security2.price);
        }
    }

}
