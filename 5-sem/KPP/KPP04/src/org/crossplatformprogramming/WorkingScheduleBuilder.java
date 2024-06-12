package org.crossplatformprogramming;

import java.time.Month;

import java.util.HashMap;
import java.util.Map;

public class WorkingScheduleBuilder {

    private Map<Month, MonthWorkingSchedule> workingSchedule;
    private final YamlParser yamlParser;

    public WorkingScheduleBuilder(YamlParser yamlParser) {
        this.yamlParser = yamlParser;
        workingSchedule = new HashMap<>();
    }

    public Map<Month, MonthWorkingSchedule> generateWorkingSchedule() {
        Map<Integer, Month> months = yamlParser.getMonths();

        for(int i = 0; i < months.size(); i++) {
            MonthWorkingSchedule monthWorkingSchedule = new MonthWorkingSchedule(
                    yamlParser.getMonthlyWorkingHoursPerDay().get(i),
                    yamlParser.getMonthlyWorkingDaysOfWeek().get(i));
            workingSchedule.put(months.get(i), monthWorkingSchedule);
        }
        return workingSchedule;
    }

    @Override
    public String toString() {
        return "WorkingScheduleBuilder{" +
                "workingSchedule=" + workingSchedule +
                ", yamlParser=" + yamlParser +
                '}';
    }
}
