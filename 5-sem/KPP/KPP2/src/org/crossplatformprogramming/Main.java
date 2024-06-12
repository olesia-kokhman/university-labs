package org.crossplatformprogramming;

import org.crossplatformprogramming.managers.FindManager;
import org.crossplatformprogramming.managers.SecuritySortManager;
import org.crossplatformprogramming.securities.*;


import java.time.LocalDate;
import java.util.*;

public class Main {
    public static void main(String[] args) {

        List<Security> securities = new ArrayList<>();

        securities.add(new Stock("Apple", 180, Trend.INCREASING, RiskLevel.MEDIUM, 0.5));
        securities.add(new Stock("Tesla", 250, Trend.INCREASING, RiskLevel.LOW, 0.75));
        securities.add(new Bond("Military", 1000, Trend.DECREASING, RiskLevel.HIGH, 10.5, LocalDate.of(2030, 10, 10)));
        securities.add(new Bond("Private", 50, Trend.DECREASING, RiskLevel.CRITICAL, 5.5, LocalDate.of(2030, 10, 10)));

        System.out.println("\nInitial list:\n" + securities);

        System.out.println("\nSort securities by price ascending:\n" + SecuritySortManager.sortByPriceAscending(securities));
        System.out.println("\nSort securities by risk level ascending:\n" + SecuritySortManager.sortByRiskLevelAscending(securities));
        System.out.println("\nSort securities by name ascending:\n" + SecuritySortManager.sortByNameAscending(securities));

        System.out.println("\nSort securities by price descending:\n" + SecuritySortManager.sortByPriceDescending(securities));
        System.out.println("\nSort securities by risk level descending:\n" + SecuritySortManager.sortByRiskLevelDescending(securities));
        System.out.println("\nSort securities by name descending:\n" + SecuritySortManager.sortByNameDescending(securities));

        System.out.println("\nshould find 250 price - " + FindManager.findByPrice(250, securities));

        List<Bond> bonds = new ArrayList<>();
        bonds.add(new Bond("Private", 50, Trend.DECREASING, RiskLevel.HIGH, 5.5, LocalDate.of(2030, 9, 10)));
        bonds.add(new Bond("Corporate", 75, Trend.DECREASING, RiskLevel.MEDIUM, 4.2, LocalDate.of(2025, 3, 20)));
        bonds.add(new Bond("Government", 100, Trend.INCREASING, RiskLevel.LOW, 3.0, LocalDate.of(2028, 2, 15)));
        bonds.add(new Bond("Municipal", 60, Trend.DECREASING, RiskLevel.MEDIUM, 4.8, LocalDate.of(2040, 7, 5)));
        bonds.add(new Bond("Convertible", 90, Trend.INCREASING, RiskLevel.HIGH, 6.2, LocalDate.of(2050, 5, 25)));

        System.out.println("\nInitial bonds:\n" + bonds);


        System.out.println("\nSort bonds by maturity date descending:\n" + SecuritySortManager.sortByMaturityDateAscending(bonds));

        System.out.println("\nSort securities by maturity date descending:\n" + SecuritySortManager.sortByMaturityDateDescending(bonds));


    }
}
