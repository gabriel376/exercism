import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.Comparator;

class DiceResult {
    private List<Integer> values = new ArrayList();

    void add(int value) {
        values.add(value);
    }

    DiceResult top(int limit) {
        values = values.stream()
            .sorted(Comparator.reverseOrder())
            .limit(limit)
            .collect(Collectors.toList());

        return this;
    }

    int sum() {
        return values.stream().mapToInt(x -> x).sum();
    }
}
