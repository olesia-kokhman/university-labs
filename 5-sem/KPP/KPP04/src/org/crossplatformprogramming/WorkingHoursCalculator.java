package org.crossplatformprogramming;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Month;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class WorkingHoursCalculator {

    private final Map<Month, MonthWorkingSchedule> workingSchedule;
    private final LocalDate startDate;
    private final LocalDate endDate;
    private final YamlCalendar yamlCalendar;

    public WorkingHoursCalculator(LocalDate startDate, LocalDate endDate, Map<Month, MonthWorkingSchedule> workingSchedule,
                                  YamlCalendar yamlCalendar) {
        this.startDate = startDate;
        this.endDate = endDate;
        this.workingSchedule = workingSchedule;
        this.yamlCalendar = yamlCalendar;
    }

    public int calculate(String country) {
        int sum = 0;
        LocalDate currentDate = startDate;

        List<LocalDate> holidays = yamlCalendar.getPublicHolidays(country);

        while(!currentDate.isAfter(endDate)) {

            DayOfWeek currentDay = currentDate.getDayOfWeek(); // sunday
            Month month = currentDate.getMonth();
            System.out.println(month);
            try {
                MonthWorkingSchedule monthWorkingSchedule = workingSchedule.get(month);
                System.out.println(monthWorkingSchedule);
                if (monthWorkingSchedule.getWorkingDays().contains(currentDay)) {
                    if(holidays.contains(currentDay)) {
                        continue;
                    } else {
                        sum += monthWorkingSchedule.getWorkingHoursPerDay();
                    }
                }
                currentDate = currentDate.plusDays(1);
            } catch (NullPointerException exception) {
                throw new NullPointerException(exception.getMessage());
            }

        }

        return sum;
    }

    public void calculateAll(List<String> countries) {
        for(String country: countries) {
            System.out.println(calculate(country));
        }
    } // for all the countries

}
