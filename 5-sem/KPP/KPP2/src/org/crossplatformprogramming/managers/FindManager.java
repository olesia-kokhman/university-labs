package org.crossplatformprogramming.managers;

import org.crossplatformprogramming.securities.RiskLevel;
import org.crossplatformprogramming.securities.Security;
import org.crossplatformprogramming.securities.Trend;

import java.util.List;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class FindManager {

    public static List<Security> findByCriteria(List<Security> securities, Predicate<Security> predicate) {
        return securities.stream()
                .filter(predicate)
                .collect(Collectors.toList());
    }

    public static List<Security> findByPrice(double price, List<Security> securities) {
        Predicate<Security> priceFilter = security -> security.getPrice() == price;
        return findByCriteria(securities, priceFilter);
    }

    public static List<Security> findByRiskLevel(RiskLevel riskLevel, List<Security> securities) {
        Predicate<Security> riskLevelFilter = security -> security.getRiskLevel() == riskLevel;
        return findByCriteria(securities, riskLevelFilter);
    }

    public static List<Security> findByTrend(Trend trend, List<Security> securities) {
        Predicate<Security> trendFilter = security -> security.getTrend() == trend;
        return findByCriteria(securities, trendFilter);
    }

}

