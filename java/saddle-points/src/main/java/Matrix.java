import java.util.List;
import java.util.Set;
import java.util.Map;
import java.util.HashMap;
import java.util.Comparator;
import java.util.stream.Stream;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

class Matrix {
    private final List<List<Integer>> matrix;
    private final Set<MatrixCoordinate> saddlePoints;
    private Map<Integer, Integer> rowMaxValues = new HashMap();
    private Map<Integer, Integer> colMinValues = new HashMap();;

    public Matrix(List<List<Integer>> matrix) {
        this.matrix = matrix;
        this.saddlePoints = IntStream.range(0, matrix.size())
                                     .boxed()
                                     .flatMap(this::getSaddlePoints)
                                     .collect(Collectors.toSet());
    }

    private Stream<MatrixCoordinate> getSaddlePoints(Integer x) {
        return IntStream.range(0, matrix.get(x).size())
                        .filter(y -> matrix.get(x).get(y) == getRowMaxValue(x)
                                  && matrix.get(x).get(y) == getColMinValue(y))
                        .mapToObj(y -> new MatrixCoordinate(x+1, y+1));
    }

    private Integer getRowMaxValue(Integer x) {
        rowMaxValues.putIfAbsent(x, matrix.get(x)
                                          .stream()
                                          .max(Comparator.naturalOrder())
                                          .get());
        return rowMaxValues.get(x);
    }

    private Integer getColMinValue(Integer y) {
        colMinValues.putIfAbsent(y, matrix.stream()
                                          .map(row -> row.get(y))
                                          .min(Comparator.naturalOrder())
                                          .get());
        return colMinValues.get(y);
    }

    public Set<MatrixCoordinate> getSaddlePoints() {
        return saddlePoints;
    }
}
