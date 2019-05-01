import java.util.List;
import java.util.stream.Stream;
import java.util.stream.Collectors;

class KindergartenGarden {
    private String garden;

    KindergartenGarden(String garden) {
        this.garden = garden;
    }

    List<Plant> getPlantsOfStudent(String student) {
        long start = Student.getStart(student);
        long cups = Student.getCups();

        return Stream.of(garden.split("\n"))
            .flatMap(row -> row.chars()
                .skip(start)
                .limit(cups)
                .mapToObj(Plant::getPlant))
            .collect(Collectors.toList());
    }
}
