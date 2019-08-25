import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class DiamondPrinter {

    public List<String> printToList(char chr) {
        int mid = chr - 'A';
        int len = 2 * mid + 1;

        return IntStream.range(0, len)
            .map(n -> n <= mid ? n : len - n - 1)
            .mapToObj(n -> {
                char c = (char)('A' + n);
                StringBuilder row = new StringBuilder();
                row.append(" ".repeat(len));
                row.setCharAt(mid - n, c);
                row.setCharAt(mid + n, c);
                return row.toString();
            }).collect(Collectors.toList());
    }
}
