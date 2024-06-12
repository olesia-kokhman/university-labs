package org.crossplatformprogramming;

import java.time.LocalDate;

public class Admin {

    public static void noteIssueDate(Membership membership) {
        LocalDate issueDate = LocalDateRandomizer.randomizeIssueDate();
        membership.setIssueDate(issueDate);
        membership.setReturnDate(issueDate.plusDays(14));
    }

    public static void noteRealReturnDate(Membership membership) {
        membership.setRealReturnDate(LocalDateRandomizer.randomizeRealReturnDate());
    }
}
