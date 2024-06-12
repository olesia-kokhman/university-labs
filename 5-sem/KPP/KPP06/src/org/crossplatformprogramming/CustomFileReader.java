package org.crossplatformprogramming;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class CustomFileReader<T> {

    private List<String> objectStrings;

    public CustomFileReader(String filePath) {
        objectStrings = new ArrayList<>();
        scanFile(filePath);
    }

    private void scanFile(String filePath) {
        try {
            FileReader fileReader = new FileReader(filePath);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line;
            try {
                while ((line = bufferedReader.readLine()) != null) {
                    objectStrings.add(line);
                }
            } catch (IOException exception) {
                throw new RuntimeException(exception.getMessage());
            }
        } catch (FileNotFoundException exception) {
            throw new RuntimeException(exception.getMessage());
        }
    }

    public List<T> getObjects(IConverter<T> converter) {
        return objectStrings.stream().map(converter::convertTo).collect(Collectors.toList());
    }


}
