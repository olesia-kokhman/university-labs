package crossplatformprogramming.my;

import java.math.BigInteger;

public class FractionMath {
    public static Fraction add(Fraction firstFraction, Fraction secondFraction) {
        BigInteger denominator = EuclideanAlgorithm.LCD(firstFraction.denominator, secondFraction.denominator);
        BigInteger numerator = firstFraction.numerator.multiply(denominator.divide(firstFraction.denominator)).add(secondFraction.numerator.multiply(denominator.divide(secondFraction.denominator)));

        return FractionMath.reduce(new Fraction(numerator, denominator));
    }

    public static Fraction reduce(Fraction fraction) {
        BigInteger GCD = fraction.numerator.gcd(fraction.denominator);

        return new Fraction(fraction.numerator.divide(GCD), fraction.denominator.divide(GCD));
    }

    // other math operations

}
