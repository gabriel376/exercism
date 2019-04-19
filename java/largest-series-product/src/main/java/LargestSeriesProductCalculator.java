import java.util.stream.IntStream;

class LargestSeriesProductCalculator {
    private final String input;

    LargestSeriesProductCalculator(String input) {
        if (input.length() > 0 && !input.matches("[0-9]+")) {
            throw new IllegalArgumentException(
                "String to search may only contain digits."
            );
        }

        this.input = input;
    }

    long calculateLargestProductForSeriesLength(int len) {
        if (len < 0) {
            throw new IllegalArgumentException(
                "Series length must be non-negative."
            );
        }

        if (len > input.length()) {
            throw new IllegalArgumentException(
                "Series length must be less than or equal"
                + " to the length of the string to search."
            );
        }

        return IntStream.rangeClosed(0, input.length() - len)
            .mapToObj(i -> input.substring(i, i + len))
            .mapToLong(this::getDigitsProduct)
            .max()
            .getAsLong();
    }

    private long getDigitsProduct(String str) {
        return str.chars()
            .mapToLong(Character::getNumericValue)
            .reduce(Math::multiplyExact)
            .orElse(1);
    }
}
