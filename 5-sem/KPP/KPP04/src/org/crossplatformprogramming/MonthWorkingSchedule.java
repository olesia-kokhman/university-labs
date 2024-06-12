package org.crossplatformprogramming;

import java.time.DayOfWeek;
import java.time.Month;

import java.util.ArrayList;
import java.util.List;

public class MonthWorkingSchedule {

    private final int workingHoursPerDay;
    private final List<DayOfWeek> workingDays;

    public MonthWorkingSchedule(int workingHoursPerDay, List<DayOfWeek> workingDays) {
        this.workingHoursPerDay = workingHoursPerDay;
        this.workingDays = new ArrayList<>(workingDays);
    }

    public List<DayOfWeek> getWorkingDays() {
        return this.workingDays;
    }

    public int getWorkingHoursPerDay() {
        return this.workingHoursPerDay;
    }
}
