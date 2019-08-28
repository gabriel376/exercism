import java.util.stream.IntStream;

class PrimeCalculator {
    int nth(int nth) {
        return IntStream.iterate(2, n -> n+1)
            .filter(this::isPrime)
            .skip(nth-1)
            .findFirst()
            .orElseThrow();
    }

    boolean isPrime(int num) {
        return IntStream.rangeClosed(2, num/2)
            .noneMatch(n -> num % n == 0);
    }
}
