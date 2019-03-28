import java.util.stream.IntStream;

class SumOfMultiples {
    private int max;
    private int[] divisors;

    SumOfMultiples(int max, int[] divisors) {
        this.max = max;
        this.divisors = divisors;
    }

    int getSum() {
        return IntStream
            .of(divisors)
            .filter(x -> x > 0)
            .flatMap(this::getMultiples)
            .distinct()
            .sum();
    }

    private IntStream getMultiples(int factor) {
        return IntStream
            .iterate(factor, x -> x + factor)
            .limit((max - 1) / factor);
    }
}
