package crossplatformprogramming.org;

import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class ProductList {
    private Map<LocalDate, List<Product>> products;

    public ProductList() {
        products = new HashMap<>();

        addProductToMap(new Product("Milk", LocalDate.of(2023, 10, 10), LocalDate.of(2023, 11, 11), 10.0));
        addProductToMap(new Product("Bread", LocalDate.of(2023, 10, 12), LocalDate.of(2023, 12, 28), 15.0));
        addProductToMap(new Product("Yogurt", LocalDate.of(2023, 10, 10), LocalDate.of(2024, 11, 5), 20.0));
        addProductToMap(new Product("Chicken", LocalDate.of(2023, 10, 5), LocalDate.of(2023, 12, 28), 25.5));
        addProductToMap(new Product("Cheese", LocalDate.of(2023, 10, 20), LocalDate.of(2023, 11, 11), 30.0));
    }

    public ProductList(File file1, File file2) {
        products = new HashMap<>();

        addProductsFromFile(file1);
        addProductsFromFile(file2);

    }

    private void addProductsFromFile(File file) {
        try {
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line;
            while ((line = bufferedReader.readLine()) != null) {

                Product product = convertLineToProduct(line);
                if(!isPresent(product)) {
                    addProductToMap(product);
                }
            }

        } catch (IOException exception) {
            throw new RuntimeException(exception);
        }
    }

    private Product convertLineToProduct(String line) {
        String[] parts = line.split(", ");

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");

        return new Product(
                parts[0],
                LocalDate.parse(parts[1], formatter),
                LocalDate.parse(parts[2], formatter),
                Double.parseDouble(parts[3])
        );
    }

    private void addProductToMap(Product product) {
        if(!products.containsKey(product.getExpirationDate())) {
            products.put(product.getExpirationDate(), new ArrayList<>());
        }
        products.get(product.getExpirationDate()).add(product);
    }

    private boolean isPresent(Product product) {

        return products.values().stream()
                .anyMatch(productList -> productList.stream()
                        .anyMatch(p -> p.getName().equals(product.getName())));
    }

    public void applyDiscount() {

        LocalDate discountExpirationDate = LocalDate.now().plusDays(3);

        if(products.containsKey(discountExpirationDate)) {
            products.get(discountExpirationDate).forEach((product) -> {
                product.setPrice(product.getPrice() * 0.9);
            });
        }
    }

    public void deleteProductsWithName(String name) {
        products.forEach((date, productList) -> {
            productList.removeIf(product -> product.getName().equals(name));
        });

        products.entrySet().removeIf(productList -> productList.getValue().isEmpty());
    }

    public void deletePreviousYearProducts() {
        int currentYear = LocalDate.now().getYear();

        products.forEach((key, productList) -> {
            productList.removeIf(product -> product.getManufactureDate().getYear() < currentYear);
        });

        products.entrySet().removeIf(productList -> productList.getValue().isEmpty());
    }

    public void print() {
        products.forEach((key, value) -> {
            System.out.print("\n|-----------|-----------------------------------------------------------------------------------------");
            System.out.print("\n|" + key + " | ");

            List<Product> productList = products.get(key);
            productList.forEach((product) -> {
                if(productList.indexOf(product) == productList.size() - 1) {
                    if(productList.size() == 1) {
                        System.out.print(product);
                    } else {
                        System.out.print("|           | " + product);
                    }
                } else {
                    System.out.print(product + "\n");
                }
            });

        });
        System.out.print("\n|-----------|-----------------------------------------------------------------------------------------");
    }

}
