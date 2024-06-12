package crossplatformprogramming.org;

import java.time.LocalDate;

public class Product {
    private final String name;
    private final LocalDate manufactureDate;
    private final LocalDate expirationDate;
    private double price;

    public Product(String name, LocalDate manufactureDate, LocalDate expirationDate, double price) {
        this.name = name;
        this.manufactureDate = manufactureDate;
        this.expirationDate = expirationDate;
        this.price = price;
    }

    public LocalDate getExpirationDate() {
        return this.expirationDate;
    }

    public double getPrice() {
        return this.price;
    }

    public String getName() {
        return this.name;
    }

    public LocalDate getManufactureDate() {
        return this.manufactureDate;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Product{" +
                "name=" + name  +
                ", manufactureDate=" + manufactureDate +
                ", expirationDate=" + expirationDate +
                ", price=" + price +
                '}';
    }
}
