import java.util.stream.IntStream;

public class PascalsTriangleGenerator {
    public int[][] generateTriangle(int num) {
        return IntStream.range(0, num)
            .mapToObj(this::generateRow)
            .toArray(int[][]::new);
    }

    private int[] generateRow(int num) {
        return IntStream.rangeClosed(0, num)
            .map(k -> getBinomialCoefficient(num, k))
            .toArray();
    }

    private int getBinomialCoefficient(int n, int k) {
        return getFactorial(n) / (getFactorial(k) * getFactorial(n - k));
    }

    private int getFactorial(int num) {
        return IntStream.rangeClosed(1, num)
            .reduce(1, Math::multiplyExact);
    }
}
