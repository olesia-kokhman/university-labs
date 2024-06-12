package crossplatformprogramming.my;

import java.math.BigInteger;

public class EuclideanAlgorithm {
//    public static int GCD(BigInteger firstNumber, BigInteger secondNumber) {
//        while(!firstNumber.equals(secondNumber)) {
//            if (firstNumber.compareTo(secondNumber) == 1) {
//                firstNumber = firstNumber.(-secondNumber);
//            } else {
//                secondNumber -= firstNumber;
//            }
//        }
//
//        return firstNumber;
//    }

    public static BigInteger LCD(BigInteger firstNumber, BigInteger secondNumber) {
        return firstNumber.multiply(secondNumber).divide((firstNumber.gcd(secondNumber)));
    }
}
