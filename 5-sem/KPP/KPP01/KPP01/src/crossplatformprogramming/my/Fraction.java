package crossplatformprogramming.my;

import java.math.BigInteger;

public class Fraction {
    protected BigInteger numerator;
    protected BigInteger denominator;

    Fraction() {}

    Fraction(BigInteger numerator, BigInteger denominator) {
        this.numerator = numerator;

        if(isNotZero(denominator)) {
            this.denominator = denominator;
        } else {
            throw new ArithmeticException("denominator equals 0");
        }
    }

    protected boolean isNotZero(BigInteger value) {
        return !value.equals(0);
    }

}
