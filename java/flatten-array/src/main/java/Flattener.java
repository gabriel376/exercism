import java.util.List;
import java.util.Objects;
import java.util.stream.Stream;
import java.util.stream.Collectors;

class Flattener {
    public <T> List<T> flatten(List<T> objects) {
        return objects.stream()
                      .filter(Objects::nonNull)
                      .flatMap(this::getValues)
                      .collect(Collectors.toList());
    }

    private <T> Stream<T> getValues(T object) {
        return object instanceof List
            ? flatten((List<T>) object).stream()
            : List.of(object).stream();
    }
}
