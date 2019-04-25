import java.util.stream.IntStream;

class CollatzCalculator {
    long computeStepCount(int num) {
        if (num <= 0) {
            throw new IllegalArgumentException("Only natural numbers are allowed");
        }

        return IntStream.iterate(num, this::hasNextStep, this::computeStep).count();
    }

    private boolean hasNextStep(int num) {
        return num > 1;
    }

    private int computeStep(int num) {
        if (isEven(num)) {
            return num / 2;
        }

        return (3 * num) + 1;
    }

    private boolean isEven(int num) {
        return num % 2 == 0;
    }
}
