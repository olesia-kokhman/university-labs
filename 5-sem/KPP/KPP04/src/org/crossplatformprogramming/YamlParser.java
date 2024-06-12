package org.crossplatformprogramming;

import org.yaml.snakeyaml.Yaml;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import java.time.DayOfWeek;
import java.time.Duration;
import java.time.LocalTime;
import java.time.Month;
import java.time.format.DateTimeFormatter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class YamlParser {
    private final Map<String, Object> configData;

    public YamlParser(String filePath) throws FileNotFoundException {
        Yaml yaml = new Yaml();

        try {
            FileInputStream fileInputStream = new FileInputStream(filePath);
            configData = yaml.load(fileInputStream);
        } catch (FileNotFoundException exception) {
            throw new FileNotFoundException(exception.getMessage());
        }
    }

    public List<String> getCountries() {
        return (List<String>) configData.get("working_countries");
    }

    public Map<Integer, List<DayOfWeek>> getMonthlyWorkingDaysOfWeek() {
        Map<Integer, List<DayOfWeek>> monthlyWorkingDaysOfWeek = new HashMap<>();

        int counter = 0;

        for(String stringMonthlyWorkingDaysOfWeek: (List<String>) configData.get("working_days")) {
            String[] workingDays = stringMonthlyWorkingDaysOfWeek.split(", ");
            List<DayOfWeek> daysOfWeek = new ArrayList<>();

            for(String day: workingDays) {
                try {
                    DayOfWeek dayOfWeek = DayOfWeek.valueOf(day.toUpperCase());
                    daysOfWeek.add(dayOfWeek);
                } catch (IllegalArgumentException exception) {
                    System.err.println("Invalid weekday name " + day);
                }
            }
            monthlyWorkingDaysOfWeek.put(counter, daysOfWeek);
            counter++;
        }

        return monthlyWorkingDaysOfWeek;
    }

    public List<Integer> getMonthlyWorkingHoursPerDay() {

        List<Integer> monthlyWorkingHourPerDay = new ArrayList<>();

        for(String stringWorkingHoursPerDay:  (List<String>) configData.get("working_hours")) {
            String[] startEnd = stringWorkingHoursPerDay.split(" - ");
            DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("HH:mm");

            LocalTime start = LocalTime.parse(startEnd[0], dateTimeFormatter);
            LocalTime end = LocalTime.parse(startEnd[1], dateTimeFormatter);

            int hoursPerDay = (int) Duration.between(start, end).toHours();
            monthlyWorkingHourPerDay.add(hoursPerDay);
        }

        return monthlyWorkingHourPerDay;
    }

    public Map<Integer, Month> getMonths() {

        Map<Integer, Month> months = new HashMap<>();

        int counter = 0;

        for (String stringMonth : (List<String>) configData.get("working_months")) {
            try {
                months.put(counter, Month.valueOf(stringMonth.toUpperCase()));
            } catch (IllegalArgumentException exception) {
                System.err.println("Invalid month name " + stringMonth);
            }

            counter++;
        }
        return months;
    }

}
