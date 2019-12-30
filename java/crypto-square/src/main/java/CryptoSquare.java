import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class CryptoSquare {

    private final List<Character> chars;
    private final int nrows, ncols;

    public CryptoSquare(final String text) {
        this.chars = text.chars()
                         .filter(Character::isLetterOrDigit)
                         .mapToObj(c -> (char)c)
                         .collect(Collectors.toList());

        nrows = (int) Math.ceil(Math.sqrt(chars.size()));
        ncols = nrows == 0 ? 0 : (chars.size() + nrows - 1) / nrows;
    }

    public String getCiphertext() {
        return IntStream.range(0, nrows)
                        .mapToObj(this::getRow)
                        .collect(Collectors.joining(" "))
                        .toString();
    }

    private String getRow(int row) {
        return IntStream.range(0, ncols)
                        .mapToObj(col -> getCol(col * nrows + row))
                        .map(String::valueOf)
                        .collect(Collectors.joining());
    }

    private Character getCol(int index) {
        if (index >= chars.size()) {
            return ' ';
        }
        return Character.toLowerCase(chars.get(index));
    }
}
