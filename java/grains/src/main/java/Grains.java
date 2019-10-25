import java.math.BigInteger;

class Grains {
    static final int MIN = 1;
    static final int MAX = 64;
    static final String error = String.format(
            "square must be between %d and %d", MIN, MAX);

    BigInteger computeNumberOfGrainsOnSquare(final int square) {
        if (square < MIN || square > MAX) {
            throw new IllegalArgumentException(error);
        }
        return BigInteger.ONE.shiftLeft(square-1);
    }

    BigInteger computeTotalNumberOfGrainsOnBoard() {
        return BigInteger.ONE.shiftLeft(MAX).subtract(BigInteger.ONE);
    }
}
