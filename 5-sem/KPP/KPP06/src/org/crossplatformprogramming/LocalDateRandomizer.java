package org.crossplatformprogramming;

import java.time.LocalDate;

public class LocalDateRandomizer {

    public static LocalDate randomizeIssueDate() {
        return LocalDate.of(2023, 12, 01);
    }

    public static LocalDate randomizeRealReturnDate() {
        return LocalDate.of(2023, 12, 12);
    }
}
