import crossplatformprogramming.org.Product;
import crossplatformprogramming.org.ProductList;

import java.io.File;
import java.io.PrintStream;

public class Main {
    public static void main(String[] args) {

       System.out.println("Initial product list:\n");
//        ProductList productList = new ProductList();
//        productList.print();

        File file1 = new File("products.txt");
        File file2 = new File("products 2.txt");

        ProductList productList = new ProductList(file1, file2);
        productList.print();

        System.out.println("\n\nProduct list after discount:\n");
        productList.applyDiscount();
        productList.print();

        System.out.println("\n\nProduct list after deleting Cheese");
        productList.deleteProductsWithName("Cheese");
        productList.print();

        System.out.println("\n\nProduct list after deleting previous years:\n");
        productList.deletePreviousYearProducts();
        productList.print();
    }
}