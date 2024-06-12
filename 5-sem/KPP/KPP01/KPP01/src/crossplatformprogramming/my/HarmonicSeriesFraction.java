package crossplatformprogramming.my;

import java.math.BigInteger;

public class HarmonicSeriesFraction extends Fraction {
    private static final BigInteger NUMERATOR = BigInteger.ONE;

    HarmonicSeriesFraction() {}

    HarmonicSeriesFraction(BigInteger denominator) {
        super(NUMERATOR, denominator);
    }
}
