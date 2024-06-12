package crossplatformprogramming.my;

import java.math.BigInteger;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("Enter n value:");

        Scanner scanner = new Scanner(System.in);

        HarmonicSeries harmonicSeries = new HarmonicSeries(BigInteger.valueOf(scanner.nextInt()));

        System.out.println(harmonicSeries.count());
    }
}
