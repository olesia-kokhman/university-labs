package org.crossplatformprogramming.managers;

import org.crossplatformprogramming.securities.Bond;
import org.crossplatformprogramming.securities.Security;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class SecuritySortManager {

    public static List<Security> sortByPriceAscending(List<Security> securities) {
        //Collections.sort(securities, new Security.PriceComparator());

        securities.sort(new Security.PriceComparator());
        return securities;
    }

    public static List<Security> sortByPriceDescending(List<Security> securities) {

        Collections.reverse(SecuritySortManager.sortByPriceAscending(securities));
        return securities;
    }


   public static List<Bond> sortByMaturityDateAscending(List<Bond> bonds) {

        bonds.sort(new Bond().new MaturityDateComparator());
        return bonds;
   }

    public static List<Bond> sortByMaturityDateDescending(List<Bond> bonds) {
        Collections.reverse(SecuritySortManager.sortByMaturityDateAscending(bonds));
        return bonds;
    }

   public static List<Security> sortByNameAscending(List<Security> securities) {

       securities.sort(new Comparator<>() {
           @Override
           public int compare(Security security1, Security security2) {
               return security1.getName().compareTo(security2.getName());
           }
       });

       return securities;
   }

    public static List<Security> sortByNameDescending(List<Security> securities) {
        Collections.reverse(SecuritySortManager.sortByNameAscending(securities));
        return securities;
    }

   public static List<Security> sortByRiskLevelAscending(List<Security> securities) {

       securities.sort(Comparator.comparingInt(security -> security.getRiskLevel().ordinal()));

//       securities.sort((security1, security2) ->
//               Integer.compare(security1.getRiskLevel().ordinal(), security2.getRiskLevel().ordinal()) // return
//       );

        return securities;
   }

    public static List<Security> sortByRiskLevelDescending(List<Security> securities) {
        Collections.reverse(SecuritySortManager.sortByRiskLevelAscending(securities));
        return securities;
    }

}
