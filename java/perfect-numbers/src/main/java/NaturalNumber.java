import java.util.stream.IntStream;

class NaturalNumber {

  private int number;

  NaturalNumber(int input) {
    if (input <= 0) {
      throw new IllegalArgumentException("You must supply a natural number (positive integer)");
    }

    this.number = input;
  }

  private IntStream getFactors() {
    return IntStream.rangeClosed(1, number / 2).filter(this::isFactor);
  }

  private boolean isFactor(int input) {
    return number % input == 0;
  }

  public Classification getClassification() {
    int sum = getFactors().sum();
    return sum < number
        ? Classification.DEFICIENT
        : sum > number ? Classification.ABUNDANT : Classification.PERFECT;
  }
}
