package org.crossplatformprogramming;

import org.yaml.snakeyaml.Yaml;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class YamlCalendar {

    private Map<String, Object> holidayCalendar;

    public YamlCalendar(String filePath) throws FileNotFoundException {
        Yaml yaml = new Yaml();

        try {
            FileInputStream fileInputStream = new FileInputStream(filePath);
            holidayCalendar = yaml.load(fileInputStream);
        } catch(FileNotFoundException exception) {
            throw new FileNotFoundException(exception.getMessage());
        }

    }

    public List<LocalDate> getPublicHolidays(String country) {
        List<String> stringDates = (List<String>) holidayCalendar.get(country.toUpperCase());
        List<LocalDate> localDates = new ArrayList<>();

        for(String string: stringDates) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-dd-MM");
            localDates.add(LocalDate.parse(string, formatter));
        }

        return localDates;
    }
}

