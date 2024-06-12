import org.crossplatformprogramming.*;

import java.io.FileNotFoundException;
import java.time.LocalDate;


public class Main {
    public static void main(String[] args) {

        try {
            YamlParser yamlParser= new YamlParser("C:\\university\\5-sem\\KPP\\KPP04\\src\\config.yaml");
            YamlCalendar yamlCalendar = new YamlCalendar("C:\\university\\5-sem\\KPP\\KPP04\\src\\countries.yaml");

            WorkingScheduleBuilder workingScheduleBuilder = new WorkingScheduleBuilder(yamlParser);
            System.out.println(workingScheduleBuilder);
            workingScheduleBuilder.generateWorkingSchedule();
            System.out.println(workingScheduleBuilder);
            LocalDate startDate = LocalDate.of(2023, 8, 15);
            LocalDate endDate = LocalDate.of(2023, 11, 16);

            WorkingHoursCalculator workingHoursCalculator = new WorkingHoursCalculator(startDate, endDate,
                    workingScheduleBuilder.generateWorkingSchedule(), yamlCalendar);
            //System.out.println(workingScheduleBuilder);
            workingHoursCalculator.calculateAll(yamlParser.getCountries());


            // 12 * 8 = 96 - October
            // 9 * 12 = 108 - November
            // total = 204

        } catch (FileNotFoundException exception) {
            throw new RuntimeException(exception.getMessage());
        }

    }
}