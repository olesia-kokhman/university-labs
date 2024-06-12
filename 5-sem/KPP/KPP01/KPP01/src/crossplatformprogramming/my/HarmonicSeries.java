package crossplatformprogramming.my;

import java.math.BigInteger;
import java.math.BigDecimal;
import java.math.MathContext;

public class HarmonicSeries {
    private BigInteger n;
    private static final BigInteger k = BigInteger.ONE;

    HarmonicSeries() {}

    HarmonicSeries(BigInteger n) {
        this.n = n;
    }

    public BigDecimal count() {
        Fraction sumFraction = new HarmonicSeriesFraction(k);

        for(BigInteger value = k.add(BigInteger.ONE); value.compareTo(n) <= 0; value = value.add(BigInteger.ONE)) {

            HarmonicSeriesFraction fraction = new HarmonicSeriesFraction(value);
            sumFraction = FractionMath.add(sumFraction, fraction);

        }

        return new BigDecimal(sumFraction.numerator).divide(new BigDecimal(sumFraction.denominator), MathContext.DECIMAL128);
    }

}
