import java.util.List;
import java.util.stream.Stream;
import java.util.stream.Collectors;

class Allergies {
    int score;

    Allergies(int score) {
        this.score = score;
    }

    boolean isAllergicTo(Allergen allergen) {
        return (score & allergen.getScore()) > 0;
    }

    List<Allergen> getList() {
        return Stream.of(Allergen.values())
            .filter(this::isAllergicTo)
            .collect(Collectors.toList());
    }
}
