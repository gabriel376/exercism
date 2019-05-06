import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

class Series {
    private final String series;

    Series(String series) {
        this.series = series;
    }

    List<String> slices(int len) {
        if (len < 1) {
            throw new IllegalArgumentException("Slice size is too small.");
        }

        if (len > series.length()) {
            throw new IllegalArgumentException("Slice size is too big.");
        }

        return IntStream.range(0, series.length() - len + 1)
            .mapToObj(i -> series.substring(i, i + len))
            .collect(Collectors.toList());
    }
}
