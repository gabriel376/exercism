import java.util.List;
import java.util.ArrayList;

public class PrimeFactorsCalculator {

    public List<Long> calculatePrimeFactorsOf(Long number) {
        List<Long> factors = new ArrayList<>();
        Long factor = 2L;

        while (number > 1) {
            if (number % factor == 0) {
                number /= factor;
                factors.add(factor);

            } else {
                factor++;
            }
        }

        return factors;
    }
}
