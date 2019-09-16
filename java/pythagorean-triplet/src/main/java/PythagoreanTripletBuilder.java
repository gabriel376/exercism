import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class PythagoreanTripletBuilder {

    private int MIN = 3;
    private int sum;
    private int factor;

    public PythagoreanTripletBuilder withFactorsLessThanOrEqualTo(int factor) {
        this.factor = factor;
        return this;
    }

    public PythagoreanTripletBuilder thatSumTo(int sum) {
        this.sum = sum;
        return this;
    }

    public List<PythagoreanTriplet> build() {
        return IntStream.range(MIN, factor)
            .mapToObj(this::buildTriplets)
            .flatMap(List::stream)
            .filter(PythagoreanTriplet::isPythagorean)
            .filter(this::matchSum)
            .collect(Collectors.toList());
    }

    private List<PythagoreanTriplet> buildTriplets(int a) {
        return IntStream.range(a+1, factor)
            .mapToObj(b -> this.buildTriplet(a, b))
            .collect(Collectors.toList());
    }

    private PythagoreanTriplet buildTriplet(int a, int b) {
        int c = (int) Math.sqrt(a*a + b*b);
        return new PythagoreanTriplet(a, b, c);
    }

    private boolean matchSum(PythagoreanTriplet triplet) {
        return triplet.sum() == sum;
    }

}
